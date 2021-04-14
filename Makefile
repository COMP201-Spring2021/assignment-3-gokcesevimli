all: clean install
	./program

install: program

clean:
	rm -rf *.o program

program: main.o
	gcc -o program main.o

main.o:
	gcc -c main.c
