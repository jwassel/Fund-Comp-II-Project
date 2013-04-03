all: main

main: main.o Wartortle.o
	g++ main.o Wartortle.o -o main -lSDL -lSDL_image -lSDL_ttf

main.o: main.cpp Wartortle.h
	g++ -c main.cpp

Wartortle.o: Wartortle.cpp Wartortle.h
	g++ -c Wartortle.cpp

clean:
	rm -f *.o main
