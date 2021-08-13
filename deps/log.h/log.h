#ifndef __LOG_h__
#define __LOG_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>


FILE *CRY_FD = stderr;

#ifndef LOGLEVEL
#define LOGLEVEL 4
#endif

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#if LOGLEVEL < 3
#define NDEBUG 1
#endif

#ifdef NDEBUG
/* compile with all debug messages removed */
#define log_debug(M, ...)
#else
#ifdef LOG_NOCOLORS
  #define log_debug(M, ...) fprintf(CRY_FD, "DEBUG " M " at %s (%s:%d) \n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
#else
  #define log_debug(M, ...) fprintf(CRY_FD, "\33[34mDEBUG\33[39m " M "  \33[90m at %s (%s:%d) \33[39m\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__)
#endif /* NOCOLORS */
#endif /* NDEBUG */

/* safe readable version of errno */
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#ifdef LOG_NOCOLORS
  #define log_error(M, ...) fprintf(CRY_FD,  "ERR   " M " at %s (%s:%d) errno:%s\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__, clean_errno())
  #define log_warn(M, ...) fprintf(CRY_FD, "WARN  " M " at %s (%s:%d) errno:%s\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__, clean_errno())
  #define log_info(M, ...) fprintf(CRY_FD, "INFO  " M " at %s (%s:%d)\n", ##__VA_ARGS__, __func__, __FILENAME__, __LINE__)
#else
  #define log_error(M, ...) fprintf(CRY_FD,  "\33[31mERR\33[39m   " M "  \33[90m at %s (%s:%d) \33[94merrno: %s\33[39m\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__, clean_errno())
  #define log_warn(M, ...) fprintf(CRY_FD, "\33[91mWARN\33[39m  " M "  \33[90m at %s (%s:%d) \33[94merrno: %s\33[39m\n", ##__VA_ARGS__, __func__, __FILE__, __LINE__, clean_errno())
  #define log_info(M, ...) fprintf(CRY_FD, "\33[32mINFO\33[39m  " M "  \33[90m at %s (%s:%d) \33[39m\n", ##__VA_ARGS__, __func__, __FILENAME__, __LINE__)
#endif /* NOCOLORS */

#if LOGLEVEL < 4
#undef log_info
#define log_info(M, ...)
#endif

#if LOGLEVEL < 2
#undef log_warn
#define log_warn(M, ...)
#endif

#if LOGLEVEL < 1
#undef log_error
#define log_error(M, ...)
#endif

#endif
