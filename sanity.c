#include <stddef.h>
#include "types.h"
#include "user.h" 
#include "fcntl.h"

/* Sanity test for task 1*/
void
t1Test(void){
	printf(1,"running sanity test for task1\n");

	int fd;
	char buf[1024];
	int numBytes = 0;	//just to check the length
	// fills the data array with 7s
	memset(buf, 7, 1024);

	fd = open("t1Sanity", O_CREATE | O_RDWR);
	for(int i = 1; i <= 1024; i++){
		numBytes += write(fd, buf, sizeof(buf));
        printf(1, "numbytes in loop is: %d\n", numBytes);
		if (i == 6)//direct links
			printf(1,"Finished writing 6KB-->finished using the direct links\n");
		if (i == 70)// single indirect
			printf(1,"Finished writing 70KB -->finished using the single indirect links)\n");
	}
    printf(1, "numbytes is: %d\n", numBytes);
    printf(1, "fd is: %d\n", fd);
	
	// checking the we indeed wrote 1MB data
	// NOTE: using ls after the test we can see the file
	//		 and its size in the file system of QEMU
	if(numBytes == 1024*1024)
		printf(1,"Finished writing 1MB\ntest finished successfuly\n");
	else
		printf(1,"test FAILED!!\n");
}

int main(int argc, char* argv[]){
	printf(1,"*Sanity Tests*\n");
	t1Test();
	exit();
}