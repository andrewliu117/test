
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
	FILE* fptr = fopen("t.txt", "w");
	char buf[11] = "aaaaaaaaaa";
	fwrite(buf,1,10,fptr);
	fclose(fptr);

	int fd = open("t.txt", O_RDWR); 
	char* addr = (char*)mmap(NULL, 10, PROT_WRITE , MAP_SHARED, fd, 0);
	printf("addr is [%s] \n", addr);
	strcpy(addr, "bbb");
	munmap(addr, 10);

	printf("eof is [%d]", EOF);
}
