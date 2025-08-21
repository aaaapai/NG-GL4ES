#ifndef _GL4ES_STRING_UTILS_H_
#define _GL4ES_STRING_UTILS_H_

#define FindString gl4es_find_string
#define FindStringNC gl4es_find_string_nc
#define CountString gl4es_count_string
#define ResizeIfNeeded gl4es_resize_if_needed
#define InplaceReplace gl4es_inplace_replace
#define Append gl4es_append
#define InplaceInsert gl4es_inplace_insert
#define GetLine gl4es_getline
#define CountLine gl4es_countline
#define GetLineFor gl4es_getline_for
#define StrNext gl4es_str_next
#define NextStr gl4es_next_str
#define PrevStr gl4es_prev_str
#define NextBlank gl4es_next_blank
#define NextLine gl4es_next_line
#define GetNextStr gl4es_get_next_str
#define CountStringSimple gl4es_countstring_simple
#define InplaceReplaceSimple gl4es_inplace_replace_simple

extern const char* AllSeparators;

const char* gl4es_find_string(const char* pBuffer, const char* S);
char* gl4es_find_string_nc(char* pBuffer, const char* S);
int gl4es_count_string(const char* pBuffer, const char* S);
char* gl4es_resize_if_needed(char* pBuffer, int *size, int addsize);
char* gl4es_inplace_replace(char* pBuffer, int* size, const char* S, const char* D);
char* gl4es_append(char* pBuffer, int* size, const char* S);
char* gl4es_inplace_insert(char* pBuffer, const char* S, char* master, int* size);
char* gl4es_getline(char* pBuffer, int num);
int gl4es_countline(const char* pBuffer);
int gl4es_getline_for(const char* pBuffer, const char* S); // get the line number for 1st occurent of S in pBuffer
char* gl4es_str_next(char *pBuffer, const char* S); // mostly as strstr, but go after the substring if found
//"blank" (space, tab, cr, lf,":", ",", ";", ".", "/")
char* gl4es_next_str(char* pBuffer);   // go to next non "blank"
char* gl4es_prev_str(char* Str, char* pBuffer);    // go to previous non "blank"
char* gl4es_next_blank(char* pBuffer);   // go to next "blank"
char* gl4es_next_line(char* pBuffer);   // go to next new line (crlf not included)


const char* gl4es_get_next_str(char* pBuffer); // get a (static) copy of next str (until next separator), can be a simple number or separator also

// those function don't try to be smart with separators...
int gl4es_countstring_simple(char* pBuffer, const char* S);
char* gl4es_inplace_replace_simple(char* pBuffer, int* size, const char* S, const char* D);

int isDigit(char value);
int isValidFunctionName(char value);
void AppendToEnd(char **str, const char *suffix);
void InsertAtBeginning(char **str, const char *prefix);

char * InplaceReplaceByIndex(char* pBuffer, int* size, int startIndex, int endIndex, const char* replacement);
char * InplaceInsertByIndex(char * source, int *sourceLength, int insertPoint, const char *insertedString);


#endif // _GL4ES_STRING_UTILS_H_
