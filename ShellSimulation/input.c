/*
This file has functions that facilitates input processing such as getting
a line from a file and parsing a line.
*/

#include "libraries.h"
#include "input.h"

/*
(getLine) Takes in a file and a integer flag. Reads a line from the file
given and returns it. The flag just makes sure that the null terminating
character is inserted at the right position.
*/
char* getLine(FILE* stream, int argc) {
	int lineLength = 530;
	char *line = malloc(lineLength);

	int i = 0;
	char ch = getc(stream);

	while ((ch != '\n') && (ch != EOF)) {
		if (i == lineLength) {

		}
		line[i] = ch;
		i++;

		ch = getc(stream);
	}

	if (argc == 1) {
		line[i] = '\0';
	}
	else {
		line[i - 1] = '\0';
	}

	return line;
}

/*
(parseLine) Takes in a line and separates it into tokens separated by spaces.
Returns the list of tokens.
*/
char** parseLine(char* line) {
	char** tokenizedString;
	int numberOfTokens = 0;
	char* stringCopy = malloc(strlen(line));
	char delim[2] = " ";
	char* token;
	int i = 0;

	strcpy(stringCopy, line);
	token = strtok(stringCopy, delim);
	while (token != NULL) {
		token = strtok(NULL, delim);
		numberOfTokens++;
	}

	tokenizedString = malloc(numberOfTokens);
	strcpy(stringCopy, line);
	token = strtok(stringCopy, delim);

	i = 0;
	while (i < 5) {
		if (token == NULL) {
			tokenizedString[i] = NULL;
		}
		else {
			tokenizedString[i] = malloc(256);
			strcpy(tokenizedString[i], token);
		}
		token = strtok(NULL, delim);
		i++;
	}
	return tokenizedString;
}