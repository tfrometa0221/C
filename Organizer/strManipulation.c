#include "strManipulation.h"

int hasExtension(char* fileName) {
	int i;

	for (i = 0; i < strlen(fileName); i++) {
		if (fileName[i] == '.') {
			return 1;
		}
	}
	return 0;
}

char* getExtension(char* fileName) {
	char* extension = strrchr(fileName, '.');
	return extension;
}

char** getTokenizedFileName(char* fileName, int numberOfTokens) {
	char** tokenizedFileName;
	char* fileNameCopy = malloc(FILENAME_SIZE_LIMIT);
	char delim[2] = "-";
	char* token;
	int i = 0;
	
	if (numberOfTokens == 4) {
		tokenizedFileName = malloc(numberOfTokens - 1);
		strcpy(fileNameCopy, fileName);
		token = strtok(fileNameCopy, delim);

		for (i = 0; i < numberOfTokens - 1; i++) {
			tokenizedFileName[i] = malloc(FILENAME_SIZE_LIMIT);
		}
	}
	else {
		tokenizedFileName = malloc(numberOfTokens);
		strcpy(fileNameCopy, fileName);
		token = strtok(fileNameCopy, delim);

		for (i = 0; i < numberOfTokens; i++) {
			tokenizedFileName[i] = malloc(FILENAME_SIZE_LIMIT);
		}
	}

	i = 0;
	while (token != NULL) {
		if (numberOfTokens == 4) {
			if (i == 3) {
				strcat(tokenizedFileName[i - 1], "-");
				strcat(tokenizedFileName[i - 1], token);
			}
			else {
				strcpy(tokenizedFileName[i], token);
			}
		}
		else {
			strcpy(tokenizedFileName[i], token);
		}
		token = strtok(NULL, delim);
		i++;
	}
	return tokenizedFileName;
}

int getNumberOfTokens(char* fileName) {
	int numberOfTokens = 0;
	char* fileNameCopy = malloc(FILENAME_SIZE_LIMIT);
	char delim[2] = "-";
	char* token;

	strcpy(fileNameCopy, fileName);
	token = strtok(fileNameCopy, delim);

	while (token != NULL) {
		token = strtok(NULL, delim);
		numberOfTokens++;
	}

	return numberOfTokens;
}