#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

void fatal_error(const char *message);

int error(const char *message);

int warning(const char *message);

int debug(const char *tag, const char *message);

#ifdef __cplusplus
}
#endif
#endif
