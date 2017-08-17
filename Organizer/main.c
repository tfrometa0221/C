#include "constants.h"

int organize(char* path);

/*(main) Checks for wrong number of command line arguments and calls necesary functions to
organize the target directory.
Parameters:
	argc is the number of arguments passed from the command line.
	argv is the list of all the arguments passed from the command line.
Return:
	an integer.
*/
int main(int argc, char* argv[]) {
	char* cwd = malloc(DIRECTORY_PATH_SIZE_LIMIT);

	if (argc > 2) {
		fprintf(stderr, wrongArgumentNumber); fflush(stderr);
		exit(1);
	}
	else if (argc == 2){
		if (organize(argv[1])) {
			printf(organizeSucceed);
		}
		else {
			printf(organizeFailed);
		}
	}
	else {
		getcwd(cwd, 255);
		if (organize(cwd)) {
			printf(organizeSucceed);
		}
		else {
			printf(organizeFailed);
		}
	}

	return 1;
}