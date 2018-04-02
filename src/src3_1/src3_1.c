#include "../apue.h"

int log_to_stderr = 0;

int main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");

	exit(0);
}
