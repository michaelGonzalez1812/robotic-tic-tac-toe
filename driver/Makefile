# SPDX-License-Identifier: GPL-2.0
#
# Makefile for USB Class drivers
# (one step up from the misc category)
#

#all: obj-m
#	make -C /usr/src/linux-headers-$(uname -r) M=$(pwd modules)
#	sudo insmod cdc-acm-ard.ko

obj-m		+= cdc-acm-ard.o
#obj-$(CONFIG_USB_PRINTER)	+= usblp.o
#obj-$(CONFIG_USB_WDM)		+= cdc-wdm.o
#obj-$(CONFIG_USB_TMC)		+= usbtmc.o


Phony: .clean
clean :  
	rm *.ko *.o *.mod.c *.cmd *.d *back.c *.symvers *.order .*
	rm -r .tmp_versions/