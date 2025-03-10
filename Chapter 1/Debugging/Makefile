CC = g++
all: program
program: program.o
	${CC} -o program program.o
program.o: program.cpp
	${CC} -c -g program.cpp
clean:
	rm -f program.o program