#include <linux/vmalloc.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include "ramd.h"

MODULE_LICENSE("GPL");

static unsigned char *ramdisk;
static struct proc_dir_entry *proc_entry;
static int ramdisk_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg);
static struct file_operations proc_operations;

static int __init init_routine(void) {
	printk("<1> Loading RAMDISK Module\n");

	proc_operations.ioctl = ramdisk_ioctl;

	// Create /proc entry first. 666 for Read/Write
	proc_entry = create_proc_entry("ramdisk", 0666, NULL);
	if (!proc_entry) {
		printk("<1> Error creating /proc entry.\n");
		return 1;
	}
	// Working version
	proc_entry->proc_fops = &proc_operations;

// Trying read write
//	proc_entry->read_proc = read_proc;
//	proc_entry->write_proc = write_proc;

	// vmalloc for 2MB
	// ramdisk = (char *)vmalloc(2097150);

	return 0;
}

static void __exit exit_routine(void) {
	printk("<1> Exiting RAMDISK Module\n");
	// Free ramdisk
	vfree(ramdisk);

	// Remove /proc entry
	remove_proc_entry("ramdisk", NULL);
	return;
}

/** 
* Ramdisk entry point
*/

static int ramdisk_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg) {
	// int i;
	// int size;

	/* 
	 * Switch according to the ioctl called 
	 */
	switch (cmd) {
	case RD_MALLOC:

		// size = (int)arg;
		// 
		// get_user(ch, temp);
		// for (i = 0; ch && i < BUF_LEN; i++, temp++)
		// 	get_user(ch, temp);
		// 
		// device_write(file, (char *)ioctl_param, i, 0);
		// vmalloc for 2MB
		ramdisk = (unsigned char *)vmalloc(2097150);
		printk("<1>I finished vmalloc!\n");
		break;
	}

	return 0;
}

module_init(init_routine);
module_exit(exit_routine);
