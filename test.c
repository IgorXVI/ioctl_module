#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "ioctl_module.h"

int main() {
	int answer;

	struct mystruct test = {
		.name = "Igor",
		.repeat = 10
	};

	int dev = open("/dev/mydevice", O_RDONLY);
	if(dev == -1) {
		printf("Opening was not possible!\n");
		return -1;
	}

	ioctl(dev, RD_VALUE, &answer);
	printf("the answer is %d\n", answer);

	answer = 123;
	ioctl(dev, WR_VALUE, &answer);

	ioctl(dev, RD_VALUE, &answer);
	printf("the new answer is %d\n", answer);

	ioctl(dev, GREETER, &test);

	printf("Opening was successfull!\n");
	close(dev);
	
	return 0;
}