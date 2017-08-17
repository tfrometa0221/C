organizer: clean main.o organize.o dirManagement.o strManipulation.o constants.h
	gcc main.o organize.o dirManagement.o strManipulation.o -o organizer
main.o: main.c
	gcc -c main.c
organize.o: organize.c
	gcc -c organize.c
dirManagement.o: dirManagement.c dirManagement.h
	gcc -c dirManagement.c
strManipulation.o: strManipulation.c
	gcc -c strManipulation.c
clean:
	rm -f core *.o organizer a.out
warning:
	gcc -Wall *.c
deleteTest:
	rm -r test
restoreTest: deleteTest
	cp -r before1 test
