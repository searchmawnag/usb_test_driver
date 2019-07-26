#ifndef __USBTEST_H_
#define __USBTEST_H_

#include <stdint.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/ioctl.h>




#define SIMPLE_IO_TIMEOUT	10000	/* in milliseconds */

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
	uint32_t		test_num;	/* 0..(TEST_CASES-1) */
	uint32_t		iterations;
	uint32_t		length;
	uint32_t		vary;
	uint32_t		sglen;

	/* outputs */
	int32_t		duration_sec;
	int32_t		duration_usec;
};

/*
 * Compat parameter to the usbtest driver.
 * This supports older user space binaries compiled with 64 bit compiler.
 */
struct usbtest_param_64 {
	/* inputs */
	uint32_t		test_num;	/* 0..(TEST_CASES-1) */
	uint32_t		iterations;
	uint32_t		length;
	uint32_t		vary;
	uint32_t		sglen;

	/* outputs */
	int64_t		duration_sec;
	int64_t		duration_usec;
};


/* IOCTL interface to the driver. */
#define USBTEST_REQUEST_32    _IOWR('U', 100, struct usbtest_param_32)
/* COMPAT IOCTL interface to the driver. */
#define USBTEST_REQUEST_64    _IOWR('U', 101, struct usbtest_param_64)




#endif

