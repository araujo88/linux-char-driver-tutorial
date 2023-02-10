# linux-char-driver-tutorial

Implementation of a SCULL driver (Simple Character Utility for Loading Localities) example of Linux kernel development.

## Linux Kernel version

5.10.0-21-amd64

## Description

SCULL is an region is memory that the kernel treats as if it was device or memory in device. It is used for learning to write device drivers and is also used for testing simple drivers.

### Datatypes

- `dev_t` (defined in <linux/types.h>) is used to hold device numbers - both the major and minor parts
- `const struct file_operations` (defined in <linux/fs.h>) hold the file operations performed on this device

### Commands

 - `cat /proc/devices` <br>
 - `sudo tail -f /var/log/syslog` <br>
 - `sudo mknod -m 666 /dev/scull c <MAJOR_NUMBER> <MINOR_NUMBER>` <br>
