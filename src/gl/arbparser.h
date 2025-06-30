#ifndef _GL4ES_ARBPARSER_H_
#define _GL4ES_ARBPARSER_H_

#include <stddef.h>

#include "arbhelper.h"

#ifdef __cplusplus
extern "C" {
#endif

struct sSpecialCases {
	int hasFogFragCoord;
	int isDepthReplacing;
};

eToken readNextToken(sCurStatus* curStatus);
void parseToken(sCurStatus *curStatus, int vertex, char **error_msg, struct sSpecialCases *hasFogFragCoord);

#ifdef __cplusplus
}
#endif

#endif // _GL4ES_ARBPARSER_H_
