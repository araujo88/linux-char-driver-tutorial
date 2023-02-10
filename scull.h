#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("SCULL - Simple Character Utility for Loading Localities");

struct cdev scull_cdev;

void print_buffer(const char *buffer, size_t length);

int scull_open (struct inode *pinode, struct file *pfile);
ssize_t scull_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset);
ssize_t scull_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset);
int scull_close(struct inode *pinode, struct file *pfile);

static const struct file_operations scull_fops = {
	.owner = THIS_MODULE,
	.open = scull_open,
	.read = scull_read,
	.write = scull_write,
	.release = scull_close
};
