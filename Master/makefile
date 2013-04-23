OBJECTS = main.o Timer.o Enemy.o Squirtle.o Sprite.o Background.o Poliwhirl.o Rpidgey.o Dome.o Item.o Health.o Weapon.o Pistol.o Gatling.o Lmg.o Smg.o PlasmaCannon.o Text.o Crosshairs.o Bomb.o Voltorb.o Electrode.o Articuno.o Rarticuno.o Charmander.o Rcharmander.o Machamp.o Rmarowak.o Marowak.o Pidgey.o Zapdos.o Rzapdos.o Ammo.o Rmachamp.o Rsquirtle.o Rpoliwhirl.o
OUTPUT = main
SDLLINKS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
($OUTPUT): $(OBJECTS)
	g++ $(OBJECTS) -o $(OUTPUT) $(SDLLINKS)
main.o: main.cpp Enemy.h Squirtle.h Timer.h Background.h Poliwhirl.h Rpidgey.h Weapon.h Pistol.h Gatling.h Lmg.h Smg.h PlasmaCannon.h Text.h Crosshairs.h Voltorb.h Bomb.h Electrode.h Item.h Health.h Articuno.h Rarticuno.h Charmander.h Rcharmander.h Machamp.h Rmarowak.h Marowak.h Pidgey.h Zapdos.h Rzapdos.h Ammo.h Constants.h Rmachamp.h Rsquirtle.h Rpoliwhirl.h
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
Pidgey.o: Pidgey.cpp Pidgey.h
	g++ -c Pidgey.cpp
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
Ammo.o: Ammo.cpp Ammo.h
	g++ -c Ammo.cpp
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
Articuno.o: Articuno.cpp Articuno.h
	g++ -c Articuno.cpp
Rarticuno.o: Rarticuno.cpp Rarticuno.h
	g++ -c Rarticuno.cpp
Charmander.o: Charmander.cpp Charmander.h
	g++ -c Charmander.cpp
Rcharmander.o: Rcharmander.cpp Rcharmander.h
	g++ -c Rcharmander.cpp
Zapdos.o: Zapdos.cpp Zapdos.h
	g++ -c Zapdos.cpp
Rzapdos.o: Rzapdos.cpp Rzapdos.h
	g++ -c Rzapdos.cpp
Marowak.o: Marowak.cpp Marowak.h
	g++ -c Marowak.cpp
Rmarowak.o: Rmarowak.cpp Rmarowak.h
	g++ -c Rmarowak.cpp
Machamp.o: Machamp.cpp Machamp.h
	g++ -c Machamp.cpp
Rsquirtle.o: Rsquirtle.cpp Rsquirtle.h
	g++ -c Rsquirtle.cpp
Rpoliwhirl.o: Rpoliwhirl.cpp Rpoliwhirl.h
	g++ -c Rpoliwhirl.cpp
clean:
	rm -rf core* *.o $(PROJ) $(OUTPUT) 
