obj-m += char_drv.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) CROSS_COMPILE= CC=gcc modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
