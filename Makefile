project: main.o
	gcc main.o -lwiringPi -o project.o

main.o: main.c
	gcc -c main.c -lwiringPi
