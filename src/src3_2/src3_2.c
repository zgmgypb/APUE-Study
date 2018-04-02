#include "../apue.h"
#include <fcntl.h>
#include <string.h>

char *buf1 = "abcdefghij";
char *buf2 = "ABCDEFGHIJ";

int log_to_stderr = 0;
int main(void)
{
	int fd;
	int i;

	if ((fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0)
		err_sys("creat error");

	if (write(fd, buf1, strlen(buf1)) != strlen(buf1))
		err_sys("write error");
	/* offset now = strlen(buf1) */

	if (lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error");
	/* offset now = 16384 */

	if (write(fd, buf2, strlen(buf2)) != strlen(buf2))
		err_sys("write error");
	/* offset now = strlen(buf2) + 16384 */

	close(fd);
	if ((fd = creat("file.nohole", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)) < 0)
		err_sys("creat error");
	for (i = 0; i < strlen(buf2) + 16384; i++)
		write(fd, buf1, 1);

	exit(0);
}

