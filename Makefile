
ifneq ($(KERNELRELEASE),)
obj-m +=  hello1.o
obj-m +=  hello2.o
ccflags-y += -I$(obj)/inc
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build
default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif


