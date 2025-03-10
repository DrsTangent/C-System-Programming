CC = g++
CFLAGS = -Wall -Wextra

all: hello
	./hello
	make clean
hello: hello.o
	$(CC) -o hello hello.o

hello.o: hello.cpp
	$(CC) -c hello.cpp

clean:
	rm -f hello.o hello
