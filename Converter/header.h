//The prototypes for every function is here.

#include <stdio.h>
#include "struct-def.h"

void textToBinary(FILE *in, FILE *out);
void binaryToText(FILE *in, FILE *out, char *flag);
void insertNullTerminator(char *str, int len);
void cpStudent(Student *student1, Student *student2);