#ifndef BSD_GAMES_COMPAT_H
#define BSD_GAMES_COMPAT_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

#ifndef __unused
#if defined(__GNUC__) || defined(__clang__)
#define __unused __attribute__((__unused__))
#else
#define __unused
#endif
#endif

#ifndef __printflike
#if defined(__GNUC__) || defined(__clang__)
#define __printflike(fmtarg, firstvararg) \
	__attribute__((__format__(__printf__, fmtarg, firstvararg)))
#else
#define __printflike(fmtarg, firstvararg)
#endif
#endif

#ifndef __has_warning
#define __has_warning(x) 0
#endif

#ifndef __RCSID
#define __RCSID(s)
#endif

#ifndef __COPYRIGHT
#define __COPYRIGHT(s)
#endif

#ifndef __FBSDID
#define __FBSDID(s)
#endif

#ifndef __SCCSID
#define __SCCSID(s)
#endif

#ifndef OXTABS
#ifdef XTABS
#define OXTABS XTABS
#else
#define OXTABS 0
#endif
#endif

#ifndef __DECONST
#define __DECONST(type, var)	((type)(uintptr_t)(const void *)(var))
#endif

#ifndef SIGEMT
#define SIGEMT SIGILL
#endif

#ifndef MAXBSIZE
#define MAXBSIZE (64 * 1024)
#endif

static inline unsigned long
bsd_games_compat_seed(void)
{
	unsigned long seed = 0;
	int fd = open("/dev/urandom", O_RDONLY);

	if (fd >= 0) {
		ssize_t n = read(fd, &seed, sizeof(seed));
		close(fd);
		if (n == (ssize_t)sizeof(seed) && seed != 0)
			return seed;
	}

	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (unsigned long)tv.tv_sec ^ (unsigned long)tv.tv_usec ^
	    (unsigned long)getpid();
}

static inline void
bsd_games_compat_srandomdev(void)
{
	srandom(bsd_games_compat_seed());
}

#ifndef HAVE_SRANDOMDEV
#define srandomdev() bsd_games_compat_srandomdev()
#endif

#ifndef HAVE_FGETLN
static inline char *
bsd_games_compat_fgetln(FILE *fp, size_t *lenp)
{
	static char *line;
	static size_t cap;
	ssize_t nread = getline(&line, &cap, fp);

	if (nread < 0)
		return NULL;
	if (lenp != NULL)
		*lenp = (size_t)nread;
	return line;
}
#define fgetln(fp, lenp) bsd_games_compat_fgetln((fp), (lenp))
#endif

#ifndef HAVE_FPURGE
static inline void
bsd_games_compat_fpurge(FILE *fp)
{
	if (fp != NULL)
		fflush(fp);
}
#define fpurge(fp) bsd_games_compat_fpurge((fp))
#endif

#endif /* BSD_GAMES_COMPAT_H */
