CC = g++
flags-std = c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

mocha: peleador.o arena.o objeto.o main.o
	$(CC) $(flags) -o mocha main.o peleador.o arena.o objeto.o

peleador.o: peleador.cpp peleador.h
	$(CC) $(flags) -c -o  peleador.o peleador.cpp

arena.o: arena.cpp arena.h
	$(CC) $(flags) -c -o  arena.o arena.cpp

objeto.o: objeto.cpp objeto.h
	$(CC) $(flags) -c -o  objeto.o objeto.cpp

main.o: main.cpp peleador.h arena.h objeto.h
	$(CC) $(flags) -c -o main.o main.cpp



run: mocha
	./mocha

clean:
	rm mocha *.o