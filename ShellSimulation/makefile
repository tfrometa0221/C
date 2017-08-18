all: clean shell402 create list

shell402: shell402.o shellFunctions.o input.o
	gcc shell402.o shellFunctions.o input.o -o shell402
list: list.o listFunctions.o
	gcc list.o listFunctions.o -o list
create: create.o createFunctions.o
	gcc create.o createFunctions.o -o create

shell402.o: shell402.c
	gcc -c shell402.c
shellFunctions.o: shellFunctions.c shellFunctions.h
	gcc -c shellFunctions.c
input.o: input.c input.h
	gcc -c input.c
list.o: list.c
	gcc -c list.c
listFinctions.o: listFunctions.c listFunctions.h
	gcc -c listFunctions.c
create.o: create.c
	gcc -c create.c
createFunctions.o: createFunctions.c createFunctions.h
	gcc -c createFunctions.c
clean:
	rm -f core shell402 list create *.o a.out test.txt
warning:
	gcc -Wall *.c
