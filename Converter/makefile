converter: main.o binaryToText.o textToBinary.o
	gcc main.o binaryToText.o textToBinary.o -o converter
main.o: main.c
	gcc -c main.c
binaryToText.o: binaryToText.c
	gcc -c binaryToText.c
textToBinary.o: textToBinary.c
	gcc -c textToBinary.c
clean:
	rm -f *.o core converter
warning:
	gcc -Wall *.c
