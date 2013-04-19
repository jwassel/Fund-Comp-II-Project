 squirtle =new Squirtle ("squirtlej.png", rand()%600+900, 0, SQUIRTLE_HEIGHT, SQUIRTLE_WIDTH, -(rand()%10+5),Y_VELOCITY_DESCENT, SQUIRTLE_POWER, SQUIRTLE_HEALTH);
enemies.push_back (squirtle);
//Charmander
charmander =new Charmander ("charmander.png", rand()%600+900, 0, CHARMANDER_HEIGHT,CHARMANDER_WIDTH, -(rand()%10+5), Y_VELOCITY_DESCENT, CHARMANDER_POWER, CHARMANDER_HEALTH);
enemies.push_back (charmander);
//Rcharmander
rcharmander =new Rcharmander ("Rcharmander.png", rand()%300-600, 0, CHARMANDER_HEIGHT, CHARMANDER_WIDTH, (rand()%10+5), Y_VELOCITY_DESCENT, CHARMANDER_POWER, CHARMANDER_HEALTH);
enemies.push_back (rcharmander);
//Pidgey
pidgey =new Pidgey ("pidgey.png", rand()%600+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, PIDGEY_HEIGHT, PIDGEY_WIDTH, -(rand()%10+5), 0,PIDGEY_POWER, PIDGEY_HEALTH);
enemies.push_back (pidgey);
//Rpidgey
rpidgey =new Rpidgey ("Rpidgey.png", rand()%300-600, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, PIDGEY_HEIGHT, PIDGEY_WIDTH, (rand()%10+5), Y_VELOCITY_DESCENT, PIDGEY_POWER, PIDGEY_HEALTH);
enemies.push_back (rpidgey);
//Articuno
articuno =new Articuno ("articuno.png", rand()%600+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH,-(rand()%20+5), 0, ARTICUNO_POWER, ARTICUNO_HEALTH);
enemies.push_back (articuno);
//Rarticuno
rarticuno =new Rarticuno ("Rarticuno.png",rand()%300-600, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ARTICUNO_HEIGHT, ARTICUNO_WIDTH, (rand()%20+5),0, ARTICUNO_POWER, ARTICUNO_HEALTH);
enemies.push_back (rarticuno);
//Marowak
marowak =new Marowak ("marowak.png", rand()%600+900, 0, MAROWAK_HEIGHT, MAROWAK_WIDTH, -(rand()%15+5), Y_VELOCITY_DESCENT,MAROWAK_POWER, MAROWAK_HEALTH);
enemies.push_back(marowak);
//Rmarowak
rmarowak =new Rmarowak ("Rmarowak.png", rand()%300-600, 0, MAROWAK_HEIGHT, MAROWAK_WIDTH, (rand()%15+5), Y_VELOCITY_DESCENT,MAROWAK_POWER, MAROWAK_HEALTH);
enemies.push_back(rmarowak);
//Zapdos
zapdos =new Zapdos ("zapdos.png", rand()%600+900, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ZAPDOS_HEIGHT, ZAPDOS_WIDTH, -(rand()%20+5), 0,ZAPDOS_POWER, ZAPDOS_HEALTH);
enemies.push_back (zapdos);
//Rzapdos
rzapdos = new Rzapdos ("Rzapdos.png", rand()%300-600, rand()%(MIDDLE_DOME-DOME_TOP)+DOME_TOP, ZAPDOS_HEIGHT, ZAPDOS_WIDTH, (rand()%20+5), 0,ZAPDOS_POWER, ZAPDOS_HEALTH);
enemies.push_back (rzapdos);
//Poliwhirl
poliwhirl =new Poliwhirl ("poliwhirl.png", rand()%600+900, 0, POLIWHIRL_HEIGHT, POLIWHIRL_WIDTH,-(rand()%15+5), Y_VELOCITY_DESCENT, POLIWHIRL_POWER, POLIWHIRL_HEALTH);
enemies.push_back (poliwhirl);
//Machamp
machamp =new Machamp ("machamp.png", rand()%600+900, 0, MACHAMP_HEIGHT, MACHAMP_WIDTH, -(rand()%15+5), Y_VELOCITY_DESCENT,MACHAMP_POWER, MACHAMP_HEALTH);
enemies.push_back(machamp);
