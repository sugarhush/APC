a.out: add.o validate.o main.o
	gcc *.o
add.o: src/add.c
	gcc -c src/add.c
validate.o: src/validate.c
	gcc -c src/validate.c
main.o: src/main.c
	gcc -c src/main.c
clean:
	rm a.out *.o
