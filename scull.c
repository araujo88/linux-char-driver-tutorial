#include "scull.h"

void print_buffer(const char *buffer, size_t length)
{
	size_t i;
	char *bytes;
	
	bytes = (char *)kmalloc((length+1)*sizeof(char), GFP_KERNEL);
	
	if (bytes == NULL) {
		printk(KERN_ERR "Failed to allocate memory\n");
		return;
	}
	
	for (i = 0; i < length; i++) {
		bytes[i] = buffer[i];
	}
	bytes[length] = '\0';	
	
	printk(KERN_INFO "Buffer contents: %s", bytes);
	
	kfree(bytes);
}


int scull_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	return 0;
}


ssize_t scull_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	
	print_buffer(buffer, length);
	
	return 0;
}


ssize_t scull_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO "%s called\n", __FUNCTION__);
	
	print_buffer(buffer, length);
	
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
