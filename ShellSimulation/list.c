/*
Tommy Frometa
tfrometa@albany.edu
*/
/*
This file has the main functionalities of the list command. It handles many errors
call funstions to print information about files.
*/

#include "listFunctions.h"

void main(int argc, char* argv[]) {
	//Checking for wrong number of arguments
	if (argc > 3 || argc == 0) {
		fprintf(stderr, wrongArgumentNumberError, argv[0]); fflush(stderr);
		exit(1);
	}

	char* wd = malloc(256);

	//printing certain information about files.
	if (argc > 1) {
		if (strncmp(argv[1], "-", 1) == 0) {
			//checking for wrong flag
			if (strcmp(argv[1], "-i") == 0 && strcmp(argv[1], "-h") == 0) {
				fprintf(stderr, wrongFlagError, argv[0]); fflush(stderr);
				exit(1);
			}
			if (argc == 3) {
				if (strcmp(argv[1], "-i") == 0) {
					printInfo(argv[2], 1, 1);
				}
				else if (strcmp(argv[1], "-h") == 0) {
					printInfo(argv[2], 1, 0);
				}
			}
			else {
				if (strcmp(argv[1], "-i") == 0) {
					printInfo(getcwd(wd, 257), 1, 1);
				}
				if (strcmp(argv[1], "-h") == 0) {
					printInfo(getcwd(wd, 257), 1, 0);
				}
			}
		}
		else {
			printInfo(argv[1], 0, 0);
		}
	}
	else {
		printInfo(getcwd(wd, 257), 0, 0);
	}
	exit(0);
}