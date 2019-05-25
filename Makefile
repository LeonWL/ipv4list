obj-m	:= ipv4_list.o 
KDIR	:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
ccflags-y:= -Wno-declaration-after-statement -Wno-unused-value

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
install:
	insmod ipv4_list.ko
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
