#include "../apue.h"
#include <sys/wait.h>
#include <errno.h>

int log_to_stderr = 0;

static void sig_int(int); /* our signal-catching function */

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
			err_sys("signal error");

	if (signal(SIGQUIT, sig_int) == SIG_ERR)
			err_sys("signal error");

	printf("%% "); /* print prompt (printf requires %% to print %) */
cont:
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
				buf[strlen(buf) - 1] = '\0'; /* replace newline with null */

		if ((pid = fork()) < 0)
			err_sys("fork error");
		else if(pid == 0) { /* child */
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)
				err_sys("waitpid error");
		printf("%% ");
	}
	
	if (errno == EINTR)
		goto cont;

	exit(0);
}

void sig_int(int signo)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
			err_sys("signal error");
	printf("interrupt\n%% ");
}
