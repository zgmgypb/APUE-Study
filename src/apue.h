/*
* Our own header, to be included before all standard system headers.
*/

#ifndef _APUE_H
#define _APUE_H

#define _POSIX_C_SOURCE 200809L

#if defined(SOLARIS) /* Solaris 10 */
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 700
#endif

#include <sys/types.h> /* some systems still require this */
#include <sys/stat.h> 
#include <sys/termios.h> /* for winsize */

#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h> /* for convenience */
#include <stdlib.h> /* for convenience */
#include <stddef.h> /* for offsetof */
#include <string.h> /* for convenience */
#include <unistd.h> /* for convenience */
#include <signal.h> /* for SIG_ERR */

#define MAXLINE 4096 /* max line length */

/*
 * Default file access permissions for new files
 * */
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Default permissions for new directories
 * */
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(inc); /* for signal handlers */

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/*
 * Prototype for our own functions.
 * */
char *path_alloc(size_t *);
long open_max(void);

int set_cloexec(int);
void clr_fl(int, int);
void set_fl(int, int);

void pr_exit(int);

void pr_mask(const char *);
Sigfunc *signal_intr(int, Sigfunc *);

void daemonize(const char *);

void sleep_us(unsigned int);
ssize_t readn(int, void *, size_t);
ssize_t writen(int, const void *, size_t);

int fd_pipe(int *);
int recv_fd(int, ssize_t (*func)(int, const void *, size_t));
int send_fd(int, int);
int send_err(int, int, const char *);
int serv_listen(const char *);
int serv_accept(int, uid_t *);
int cli_conn(const char *);
int buf_args(char *, int(*func)(int, char **));

int tty_cbreak(int);
int tty_raw(int);
int tty_reset(int);
void tty_atexit(void);
struct termios *tty_termios(void);

int ptym_open(char *, int);
int ptys_open(char *);

#endif /* _APUE_H */
