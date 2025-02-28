obj-m := hooker.o
hooker-objs = entry.o hooks.o kprobe_hooking.o
CC = gcc -Wall -std=c99
KERNEL_HEADERS := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) clean
