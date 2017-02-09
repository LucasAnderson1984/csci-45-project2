project: main.o
	gcc main.o -lwiringPi -o project.o

main.o: main.cpp
	gcc -c main.cpp -lwiringPi
