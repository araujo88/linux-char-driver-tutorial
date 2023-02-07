#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define SCULL_MAJOR 0
#define SCULL_MINOR 0
#define SCULL_NR_DEVS 4
#define SCULL_QUANTUM 4000
#define SCULL_QSET 1000

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("SCULL - Simple Character Utility for Loading Localities");

dev_t *dev;

static int __init scull_init(void)
{
	int result;

	printk(KERN_INFO "Scull init\n");

	dev = (dev_t*)kmalloc(sizeof(dev_t), GFP_KERNEL);

	//dev = MKDEV(SCULL_MAJOR, SCULL_MINOR); // device numbers

	// register_chr_dev_region obtaines one or more device numbers
	// to work with.
	// result = register_chrdev_region(*dev, SCULL_NR_DEVS, "scull");

	// allocate a major number
	result = alloc_chrdev_region(dev, SCULL_MINOR, SCULL_NR_DEVS, "scull");

	printk(KERN_INFO "alloc_chrdev_region: %d\n", result);
	printk(KERN_INFO "dev: %u\n", dev);
	printk(KERN_INFO "Major number: %d | Minor number: %d\n", MAJOR(*dev), MINOR(*dev));

	if (result < 0)
		return result;

	return 0;
}

static void __exit scull_exit(void)
{
	printk(KERN_INFO "Scull exit\n");

	unregister_chrdev_region(MKDEV(SCULL_MAJOR, SCULL_MINOR), SCULL_NR_DEVS);

	kfree(dev);
}

module_init(scull_init);
module_exit(scull_exit);
