#include <stdlib.h>
#include <string.h>
#include "header.h"

//This function takes student information from a text file and writes that information to a binary file.
void textToBinary(FILE *in, FILE *out) {
	Student *student = (Student *)malloc(sizeof(Student));
	while ((fscanf(in, "%s %s %u %f", student->firstName, student->lastName, &student->id, &student->gpa)) != EOF) {

		student->firstLen = strlen(student->firstName);
		student->lastLen = strlen(student->lastName);

		fwrite(&student->firstLen, sizeof(char), 1, out);
		fwrite(student->firstName, sizeof(char), strlen(student->firstName), out);
		fwrite(&student->lastLen, sizeof(char), 1, out);
		fwrite(student->lastName, sizeof(char), strlen(student->lastName), out);
		fwrite(&student->id, sizeof(int), 1, out);
		fwrite(&student->gpa, sizeof(float), 1, out);
	}
}