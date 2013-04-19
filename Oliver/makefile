OBJECTS = main.o Timer.o Enemy.o Squirtle.o Sprite.o Background.o Poliwhirl.o Rpidgey.o Dome.o Item.o Health.o Weapon.o Pistol.o Gatling.o Lmg.o Smg.o PlasmaCannon.o Text.o Crosshairs.o Bomb.o Voltorb.o Electrode.o
OUTPUT = main
SDLLINKS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
($OUTPUT): $(OBJECTS)
	g++ $(OBJECTS) -o $(OUTPUT) $(SDLLINKS)
main.o: main.cpp Enemy.h Squirtle.h Timer.h Background.h Poliwhirl.h Rpidgey.h Weapon.h Pistol.h Gatling.h Lmg.h Smg.h PlasmaCannon.h Text.h Crosshairs.h Voltorb.h Bomb.h Electrode.h Item.h Health.h
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
Poliwhirl.o: Poliwhirl.cpp Poliwhirl.h
	g++ -c Poliwhirl.cpp
Rpidgey.o: Rpidgey.cpp Rpidgey.h
	g++ -c Rpidgey.cpp
Dome.o: Dome.cpp Dome.h
	g++ -c Dome.cpp
Text.o: Text.cpp Text.h
	g++ -c Text.cpp
Crosshairs.o: Crosshairs.cpp Crosshairs.h
	g++ -c Crosshairs.cpp
Item.o:	Item.cpp Item.h
	g++ -c Item.cpp
Health.o: Health.cpp Health.h
	g++ -c Health.cpp
Bomb.o: Bomb.cpp Bomb.h
	g++ -c Bomb.cpp
Voltorb.o: Voltorb.cpp Voltorb.h
	g++ -c Voltorb.cpp
Electrode.o: Electrode.cpp Electrode.h
	g++ -c Electrode.cpp
Weapon.o: Weapon.cpp Weapon.h Enemy.h
	g++ -c Weapon.cpp
Pistol.o: Pistol.cpp Pistol.h
	g++ -c Pistol.cpp
Gatling.o: Gatling.cpp Gatling.h
	g++ -c Gatling.cpp
Lmg.o: Lmg.cpp Lmg.h
	g++ -c Lmg.cpp
Smg.o: Smg.cpp Smg.h
	g++ -c Smg.cpp
PlasmaCannon.o: PlasmaCannon.cpp PlasmaCannon.h
	g++ -c PlasmaCannon.cpp
clean:
	rm -rf core* *.o $(PROJ)
