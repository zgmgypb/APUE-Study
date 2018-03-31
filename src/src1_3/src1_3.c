#include "../apue.h"

int log_to_stderr = 0;
int main(void)
{
	int c;

	while ((c = fgetc(stdin)) != EOF)
			if (fputc(c, stdout) == EOF)
					err_sys("fputc error");

	if (ferror(stdin))
			err_sys("input error");

	exit(0);
}
