#ifndef _GL4ES_ARBCONVERTER_H_
#define _GL4ES_ARBCONVERTER_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

char* gl4es_convertARB(const char* const code, int vertex, char **error_msg, int *error_ptr);

#ifdef __cplusplus
}
#endif


#endif // _GL4ES_ARBCONVERTER_H_
