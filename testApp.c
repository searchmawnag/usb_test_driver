#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "testApp.h"
#include<sys/types.h>
#include<sys/stat.h>


static void memdump(char *buf, int size)
{
#define LINE_SZ	16
	int len, i;
	while (size) {
		len = (size > LINE_SZ) ? LINE_SZ : size;
		for (i = 0; i < len; i++)
			fprintf(stdout, " %02x", (unsigned char)buf[i]);
			
		for (; i < LINE_SZ; i++)
			fprintf(stdout, "   ");
		
		fprintf(stdout, " : ");
		for (i = 0; i < len; i++) {
			if ((buf[i] >= '0') && (buf[i] <= 'z'))
				fprintf(stdout, "%c", buf[i]);
			else
				fprintf(stdout, ".");
		}
		fprintf(stdout, "\n");
		size -= len;
		buf  += len;
	}
}

#define DEVICE	"/dev/usbtest"
#define LOG_FILE "./log.txt"
#define BLK_SZ	5120
#define CBW_SZ  500
#define CSW_SZ	13

/* CBW with SCSI READ(10), read 1 block from block 0 */
static char cbw_read10[CBW_SZ] = {
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
	0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e,
	0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
	0x47, 0x79, 0x75, 0x6c, 0x69, 0x61, 0x6e, 0x67
};



int main(int argc, char* argv[])
{
	char buf[BLK_SZ], *pbuf;
	char rbuf[CBW_SZ] ={0};
	struct usbtest_param_64  usbParam;
	int fd, ret, done = 0, i=0;
	long loop = 1000000;
	FILE* flog;
	
	//fd = open(DEVICE, O_RDWR | O_NONBLOCK);
	fd = open(DEVICE, O_RDWR);
	flog = fopen(LOG_FILE, "w+");
	if(flog ==NULL)
		printf("Failed to open '%s'\n", LOG_FILE);

	if (fd < 0) {
		fprintf(stderr, "Failed to open '%s': %s\n", DEVICE, strerror(errno));
		return -1;
	}
	fprintf(stdout, "%s opened\n", DEVICE);

BEGIN:
	i = 10;//for(i =0; i<= 28; i++) // 28种测试
	{
		/*  command */
		memset(&usbParam, 0,  sizeof(struct usbtest_param_64));
		usbParam.test_num = i;  // 每一种测试10遍
		usbParam.iterations = 10;
		usbParam.length = 100;
		usbParam.vary = 10;
		usbParam.sglen = 10;
		if(ioctl(fd, USBTEST_REQUEST_64, &usbParam) != 0) {
			fprintf(stderr, "Failed to ioctl: %s\n", strerror(errno));
			close(fd);
		}else{
			printf("ioctl cmd succ, test mode:%d\n", usbParam.test_num);
		}
		usleep(500*1000);
	}
	
	printf("start to read....\n");
	/*  Read data */
	ret = read(fd, rbuf, CBW_SZ);
	if (ret <= 0) {
		fprintf(stderr, "Failed to read block 0 (done %d): %s\n", i, strerror(errno));
		close(fd);
		return -1;
	}


EXIT:
	close(fd);
	return 0;

}

