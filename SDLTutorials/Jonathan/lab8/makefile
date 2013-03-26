OBJECTS = main.o Timer.o Enemy.o
OUTPUT = main
SDLLINKS = -lSDL -lSDL_image
($OUTPUT): $(OBJECTS)
	g++ $(OBJECTS) -o $(OUTPUT) $(SDLLINKS)
main.o: main.cpp Enemy.h
	g++ -c main.cpp
Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp
Timer.o: Timer.cpp Timer.h
	g++ -c Timer.cpp
clean:
	rm -rf core* *.o $(PROJ)
