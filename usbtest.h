#ifndef __USBTEST_H_
#define __USBTEST_H_



#define SIMPLE_IO_TIMEOUT	10000	/* in milliseconds */

/* IOCTL interface to the driver. */
#define USBTEST_REQUEST_32    _IOWR('U', 100, struct usbtest_param_32)
/* COMPAT IOCTL interface to the driver. */
#define USBTEST_REQUEST_64    _IOWR('U', 101, struct usbtest_param_64)




/*-------------------------------------------------------------------------*/

#define	GENERIC		/* let probe() bind using module params */

/* Some devices that can be used for testing will have "real" drivers.
 * Entries for those need to be enabled here by hand, after disabling
 * that "real" driver.
 */
//#define	IBOT2		/* grab iBOT2 webcams */
//#define	KEYSPAN_19Qi	/* grab un-renumerated serial adapter */

/* set up all urbs so they can be used with either bulk or interrupt */
#define	INTERRUPT_RATE		1	/* msec/transfer */

#define ERROR(tdev, fmt, args...) \
	dev_err(&(tdev)->intf->dev , fmt , ## args)
#define WARNING(tdev, fmt, args...) \
	dev_warn(&(tdev)->intf->dev , fmt , ## args)

#define GUARD_BYTE	0xA5
#define MAX_SGLEN	128











/*-------------------------------------------------------------------------*/
/* FIXME make these public somewhere; usbdevfs.h? */

/* Parameter for usbtest driver. */
struct usbtest_param_32 {
	/* inputs */
	__u32		test_num;	/* 0..(TEST_CASES-1) */
	__u32		iterations;
	__u32		length;
	__u32		vary;
	__u32		sglen;

	/* outputs */
	__s32		duration_sec;
	__s32		duration_usec;
};

/*
 * Compat parameter to the usbtest driver.
 * This supports older user space binaries compiled with 64 bit compiler.
 */
struct usbtest_param_64 {
	/* inputs */
	__u32		test_num;	/* 0..(TEST_CASES-1) */
	__u32		iterations;
	__u32		length;
	__u32		vary;
	__u32		sglen;

	/* outputs */
	__s64		duration_sec;
	__s64		duration_usec;
};


/*-------------------------------------------------------------------------*/
struct usbtest_info {
	const char		*name;
	u8			ep_in;		/* bulk/intr source */
	u8			ep_out;		/* bulk/intr sink */
	unsigned		autoconf:1;
	unsigned		ctrl_out:1;
	unsigned		iso:1;		/* try iso in/out */
	unsigned		intr:1;		/* try interrupt in/out */
	int			alt;
};

/* this is accessed only through usbfs ioctl calls.
 * one ioctl to issue a test ... one lock per device.
 * tests create other threads if they need them.
 * urbs and buffers are allocated dynamically,
 * and data generated deterministically.
 */
struct usbtest_dev {
	//struct usb_host_interface	*intf;
	struct usb_interface	*intf;
	struct usbtest_dev	*udev;
	struct usbtest_info	*info;
	int			in_pipe;
	int			out_pipe;
	int			in_iso_pipe;
	int			out_iso_pipe;
	int			in_int_pipe;
	int			out_int_pipe;
	struct usb_endpoint_descriptor	*iso_in, *iso_out;
	struct usb_endpoint_descriptor	*int_in, *int_out;
	struct mutex		lock;
#define TBUF_SIZE	256
	u8			*buf;
};


/*-------------------------------------------------------------------------*/
/* use ch9 requests to test whether:
 *   (a) queues work for control, keeping N subtests queued and
 *       active (auto-resubmit) for M loops through the queue.
 *   (b) protocol stalls (control-only) will autorecover.
 *       it's not like bulk/intr; no halt clearing.
 *   (c) short control reads are reported and handled.
 *   (d) queues are always processed in-order
 */

struct ctrl_ctx {
	spinlock_t		lock;
	struct usbtest_dev	*dev;
	struct completion	complete;
	unsigned		count;
	unsigned		pending;
	int			status;
	struct urb		**urb;
	struct usbtest_param_32	*param;
	int			last;
};

#define NUM_SUBCASES	16		/* how many test subcases here? */

struct subcase {
	struct usb_ctrlrequest	setup;
	int			number;
	int			expected;
};


struct queued_ctx {
	struct completion	complete;
	atomic_t		pending;
	unsigned		num;
	int			status;
	struct urb		**urbs;
};


struct transfer_context {
	unsigned		count;
	unsigned		pending;
	spinlock_t		lock;
	struct completion	done;
	int			submit_error;
	unsigned long		errors;
	unsigned long		packet_count;
	struct usbtest_dev	*dev;
	bool			is_iso;
};



#endif

