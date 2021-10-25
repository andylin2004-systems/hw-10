all: main.o hw-10.o
	gcc -o hw-10 main.o hw-10.o

run:
	./hw-10

main.o: main.c hw-10.c
	gcc -c main.c

hw-10.o: hw-10.c hw-10.h
	gcc -c hw-10.c