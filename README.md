# linux-char-driver-tutorial

Implementation of a SCULL driver (Simple Character Utility for Loading Localities) example of Linux kernel development.

## Description

SCULL is an region is memory that the kernel treats as if it was device or memory in device. It is used for learning to write device drivers and is also used for testing simple drivers.

### Datatypes

- `dev_t` type (defined in <linux/types.h>) is used to hold device numbers - both the major and minor parts.
