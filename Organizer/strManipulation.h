#include "constants.h"

/*Prototypes for strManipulation.c*/

/*
(hasExtension) checks if a file has an extension
(getExtension) returns the extension of a file
(getTokenizedFileName) returns a list of tokens of the file name when splitted by "-"
(getNumberOfTokens) return the number of posible tokens
*/
int hasExtension(char* fileName);
char* getExtension(char* fileName);
char** getTokenizedFileName(char* fileName, int numberOfTokens);
int getNumberOfTokens(char* fileName);