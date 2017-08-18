/*
This file has functions that are used in the shell program such as printing
current working directory, changing working directory, and quiting the program.
*/

#include "shellFunctions.h"

/*
(wd) Prints the current working directory.
*/
void wd() {
	char* wd = malloc(256);
	printf("%s\n", getcwd(wd, 257));
	free(wd);
}

/*
(chwd) Changes the working directory.
*/
int chwd(char* pathname) {
	if (chdir(pathname) != 0) {
		fprintf(stderr, changeDirectoryError, pathname); fflush(stderr);
		return -1;
	}
	return 0;
}

/*
(quit) Quits the program.
*/
int quit() {
	printf("GoodBye!\n");
	exit(0);
}