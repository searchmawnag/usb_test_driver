#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x1bfd809d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x19fdf3e6, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x57bd8937, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0xf0aabcd5, __VMLINUX_SYMBOL_STR(param_ops_ushort) },
	{ 0x9d7116c5, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xc6860442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x44b1d426, __VMLINUX_SYMBOL_STR(__dynamic_pr_debug) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0xbb678d7c, __VMLINUX_SYMBOL_STR(usb_get_descriptor) },
	{ 0x5e515be6, __VMLINUX_SYMBOL_STR(ktime_get_ts64) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0x6b20632, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0x4925ac87, __VMLINUX_SYMBOL_STR(usb_clear_halt) },
	{ 0xd0d25a77, __VMLINUX_SYMBOL_STR(usb_get_status) },
	{ 0x7cf9099, __VMLINUX_SYMBOL_STR(wait_for_completion_timeout) },
	{ 0xff178f6, __VMLINUX_SYMBOL_STR(__aeabi_idivmod) },
	{ 0xa2916025, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x44dd3d8d, __VMLINUX_SYMBOL_STR(completion_done) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x1a1431fd, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irq) },
	{ 0x3507a132, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0xe707d823, __VMLINUX_SYMBOL_STR(__aeabi_uidiv) },
	{ 0x6cb7bd7, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x1fab5905, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x275ef902, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x5f754e5a, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x8d422bed, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x8fc8dfef, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0x9c6dfb63, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xb022996b, __VMLINUX_SYMBOL_STR(usb_unlink_urb) },
	{ 0x5fc56a46, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xd4669fad, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x3920d3fe, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xccbf4dac, __VMLINUX_SYMBOL_STR(mem_map) },
	{ 0xf88c3301, __VMLINUX_SYMBOL_STR(sg_init_table) },
	{ 0xb7033fb2, __VMLINUX_SYMBOL_STR(page_address) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x3f5c6471, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0x14ee1a52, __VMLINUX_SYMBOL_STR(usb_sg_wait) },
	{ 0xfa5bcf35, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x1ac43b42, __VMLINUX_SYMBOL_STR(usb_sg_init) },
	{ 0x8fdf772a, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x8b1e6972, __VMLINUX_SYMBOL_STR(usb_sg_cancel) },
	{ 0xcdf45f65, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xb0d3f90f, __VMLINUX_SYMBOL_STR(usb_find_interface) },
	{ 0x286ff7f1, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xfbeee43f, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x5d85bc21, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xde8e92ff, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xb960247c, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x63824026, __VMLINUX_SYMBOL_STR(usb_register_dev) },
	{ 0x77ae495d, __VMLINUX_SYMBOL_STR(usb_speed_string) },
	{ 0xe3f1d6a2, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0x207830c4, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x14d44f8c, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x99331da9, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x890edfac, __VMLINUX_SYMBOL_STR(__dynamic_dev_dbg) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xf7802486, __VMLINUX_SYMBOL_STR(__aeabi_uidivmod) },
	{ 0xf3a6552d, __VMLINUX_SYMBOL_STR(usb_set_interface) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0547p2235d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0547p0080d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04B4p8613d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:vFFF0pFFF0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0525pA4A0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0525pA4A4d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0525pA4A3d*dc*dsc*dp*ic*isc*ip*in*");
