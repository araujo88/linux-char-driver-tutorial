#include "scull.h"

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

static int __init scull_init(void)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);

	// register char dev
	register_chrdev(240, "scull", &scull_fops);

	cdev_init(&scull_cdev, &scull_fops);

	return 0;
}

static void __exit scull_exit(void)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	
	cdev_del(&scull_cdev);
	
	unregister_chrdev(240, "scull");
}

module_init(scull_init);
module_exit(scull_exit);
