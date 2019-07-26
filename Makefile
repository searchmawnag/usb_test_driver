CCTOOLS=arm-linux-gnueabihf-
#CCTOOLS=
SURARCH=arm

CC:= $(CCTOOLS)gcc
LD:= $(CCTOOLS)ld
obj-m := usbtest.o 

###### kernel source directory , currently for Zynq7020  #######
KERNELDIR=/home/seeing-zynq/tools/kernel/
#KERNELDIR=/home/seeing-zynq/ingenic/ingenic-linux-kernel3.10.14-x1000-v8.1/kernel/  
PWD := $(shell pwd) 

modules: 
	$(MAKE) -C $(KERNELDIR)  CROSS_COMPILE=$(CCTOOLS)  ARCH=$(SURARCH)  M=$(PWD) modules 

modules_install: 
	$(MAKE) -C $(KERNELDIR)  CROSS_COMPILE=$(CCTOOLS)  ARCH=$(SURARCH)  M=$(PWD) modules_install 

app:
	$(CCTOOLS)gcc -I$(KERNELDIR) -o testApp testApp.c  testApp.h

clean:
	rm -f *.o
	rm -f *.ko
	rm -f *.mod.c
