#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>
#define FIFO_FILE  "MYFIFO"

int main(void)
{
	FILE *fp;
	char readbuff[80];

	/* Create the FIFO if it does not exist */
	umask(0);
	mknod(FIFO_FILE, S_IFIFO|0666, 0);

	while(1)
	{
		fp = fopen(FIFO_FILE, "r");
		fgets(readbuff, 80, fp);
		char string[100]="kill `pidof";
		strcat(string," ");
		strcat(string,readbuff);
		strcat(string,"`");
		printf("Received string: %s\n", string);
		system(string);
		fclose(fp);
	}

	return(0);
}
