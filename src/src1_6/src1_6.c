#include "../apue.h"
#include <errno.h>

int log_to_stderr = 0;

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCESS: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	exit(0);
}
