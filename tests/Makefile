
.PHONY: all



tests: main.o unity.o buffer.o
	gcc -o test buffer.o main.o unity.o

main.o: main.c
	gcc -c -o main.o -I./unity -I./../src main.c

unity.o: ./unity/unity.c
	gcc -c -o unity.o -I./unity ./unity/unity.c



buffer.o: ../src/buffer.c ../src/buffer.h
	gcc -c -o buffer.o ../src/buffer.c



all: tests

