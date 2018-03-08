#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

void nss_debug_log(const char *fmt, ...)
{
	char buf[BUFSIZ], cmdline[PATH_MAX];
	va_list args;
	pid_t pid;
	FILE *f;

	cmdline[0] = 0;
	cmdline[sizeof(cmdline)-1] = 0;
	buf[sizeof(buf)-1] = 0;

	/* Get process's cmdline */
	pid = getpid();
	snprintf(buf, sizeof(buf)-1, "/proc/%i/cmdline", pid);
	if ((f = fopen(buf, "r")) != NULL) {
		fgets(cmdline, sizeof(cmdline)-1, f);
		fclose(f);
	}

	va_start(args, fmt);
	vsnprintf(buf, sizeof(buf)-1, fmt, args);
	va_end(args);

	fprintf(stderr, "[pid: %i cmd: %s] %s\n", pid,
		cmdline[0] != 0 ? cmdline : "(null)", buf);
}
