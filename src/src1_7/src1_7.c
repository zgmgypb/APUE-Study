#include "../apue.h"

int log_to_stderr = 0;

int main(void)
{
	printf("uid = %d, gid = %d\n", getuid(), getgid());
	exit(0);
}
