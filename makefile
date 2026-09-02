a.out: main.o
	gcc main.o
main.o: src/main.c
	gcc -c src/main.c
clean:
	rm a.out *.o
