#include "../apue.h"

int log_to_stderr = 0;

int main(void)
{
	off_t offset;

	if ((offset = lseek(STDIN_FILENO, 0, SEEK_END)) == -1)
		printf("cannot seek\n");
	else
		printf("file len: %d\n", offset);

	exit(0);
}
