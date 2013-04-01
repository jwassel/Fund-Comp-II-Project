OBJECTS = main.o Timer.o Enemy.o Squirtle.o Sprite.o Background.o
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
Squirtle.o: Squirtle.cpp Squirtle.h
	g++ -c Squirtle.cpp
Sprite.o: Sprite.cpp Sprite.h
	g++ -c Sprite.cpp
Background.o: Background.cpp Background.h
	g++ -c Background.cpp
clean:
	rm -rf core* *.o $(PROJ)
