#ifndef LOG_PRINT_H_
#define LOG_PRINT_H_

#define _GLOG_INFO  0
#define _GLOG_WARN  1
#define _GLOG_ERROR 2
#define _GLOG_FATAL 3

#ifdef __cplusplus
extern "C" {
#endif

void log_init(const char *program);
void log_quit();
int log_printf(const char *file, const char *func, int line, const int level, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif
