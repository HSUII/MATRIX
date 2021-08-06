all:main

main: main.o matrix.o
        gcc -o main main.o matrix.o

main.o: main.c
        gcc -c main.c

matrix.o: matrix.c
        gcc -c matrix.c

clean:
        rm -r *.o main
