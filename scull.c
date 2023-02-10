#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define SCULL_NR_DEVS 4

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("SCULL - Simple Character Utility for Loading Localities");

int scull_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	return 0;
}


ssize_t scull_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	return 0;
}


ssize_t scull_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	return length;
}


int scull_close(struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	return 0;
}


static const struct file_operations scull_fops = {
	.owner = THIS_MODULE,
	.open = scull_open,
	.read = scull_read,
	.write = scull_write,
	.release = scull_close
};

struct cdev scull_cdev;

dev_t *dev;


static int __init scull_init(void)
{
	int result;

	printk(KERN_INFO "%s called\n", __FUNCTION__);

	// allocate kernel memory
	dev = (dev_t*)kmalloc(sizeof(dev_t), GFP_KERNEL);

	if (dev == NULL) {
		return 1;
	}

	// allocate a major number
	result = alloc_chrdev_region(dev, 0, SCULL_NR_DEVS, "scull");
	
	if (result < 0)
		return result;

	// register char dev
	register_chrdev(MAJOR(*dev), "scull", &scull_fops);

	cdev_init(&scull_cdev, &scull_fops);

	return 0;
}

static void __exit scull_exit(void)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	
	cdev_del(&scull_cdev);

	unregister_chrdev_region(MKDEV(MAJOR(*dev), 0), SCULL_NR_DEVS);
	
	unregister_chrdev(MAJOR(*dev), "scull");

	kfree(dev);
}

module_init(scull_init);
module_exit(scull_exit);
