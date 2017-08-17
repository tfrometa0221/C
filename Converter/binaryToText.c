#include <stdlib.h>
#include <string.h>
#include "header.h"

/*This function have two purposes. If the flag is -b, ittakes student information from a binary file and
writes that information to a text file. If the flag is -s, it calculates some information from a binary file and
prints that information to the standard output.*/
void binaryToText(FILE *in, FILE *out, char *flag) {

	Student *student1 = (Student *)malloc(sizeof(Student));
	Student *student2;
	Student *longestFullName;
	Student *shortestFullName;
	int highestID;
	int lowestID;
	float highestGPA;
	float lowestGPA;

	unsigned char len1, len2;

	while (fread(&len1, 1, 1, in) != NULL) {

		student1->firstLen = len1;
		fread(student1->firstName, 1, len1, in);
		insertNullTerminator(student1->firstName, len1);
		fread(&len2, 1, 1, in);
		student1->lastLen = len2;
		fread(student1->lastName, 1, len2, in);
		insertNullTerminator(student1->lastName, len2);
		fread(&student1->id, 4, 1, in);
		fread(&student1->gpa, 4, 1, in);

		if (strcmp("-b", flag) == 0) {
			fprintf(out, "%s %s %u %.1f\n", student1->firstName, student1->lastName, student1->id, student1->gpa);
		}
		else {
			if (student2 == NULL) {
				student2 = (Student *)malloc(sizeof(Student));
				cpStudent(student2, student1);

				longestFullName = (Student *)malloc(sizeof(Student));
				shortestFullName = (Student *)malloc(sizeof(Student));
				cpStudent(longestFullName, student1);
				cpStudent(shortestFullName, student1);
				highestID = student2->id;
				lowestID = student2->id;
				highestGPA = student2->gpa;
				lowestGPA = student2->gpa;
			}
			else {
				if (student1->firstLen + student1->lastLen > longestFullName->firstLen + longestFullName->lastLen) {
					cpStudent(longestFullName, student1);
				}
				if (student1->firstLen + student1->lastLen < shortestFullName->firstLen + shortestFullName->lastLen) {
					cpStudent(shortestFullName, student1);
				}
				if (student1->id > highestID) {
					highestID = student1->id;
				}
				if (student1->id < lowestID) {
					lowestID = student1->id;
				}
				if (student1->gpa > highestGPA) {
					highestGPA = student1->gpa;
				}
				if (student1->gpa < lowestGPA) {
					lowestGPA = student1->gpa;
				}
			}
		}
	}
	if (strcmp("-b", flag) == 0) {
		return;
	}
	else {
		printf("Longest full name: %s %s\nShortest full name: %s %s\nHighest ID: %u\nLowest ID: %u\nHighest GPA: %.1f\nLowest GPA: %.1f\n", longestFullName->firstName, longestFullName->lastName, shortestFullName->firstName, shortestFullName->lastName, highestID, lowestID, highestGPA, lowestGPA); fflush(stdout);
	}
}

//Inserts the null terminator at the end of the string str, which is specified by len.
void insertNullTerminator(char *str, int len) {
	int i;
	for (i = 0; i < len; i++);
	str[i] = '\0';
}

//Copies the inforamtion of student2 to student1.
void cpStudent(Student *student1, Student *student2) {
	student1->firstLen = student2->firstLen;
	strcpy(student1->firstName, student2->firstName);
	student1->lastLen = student2->lastLen;
	strcpy(student1->lastName, student2->lastName);
	student1->id = student2->id;
	student1->gpa = student2->gpa;
}