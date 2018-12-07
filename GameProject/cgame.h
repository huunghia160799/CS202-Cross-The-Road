#pragma once

class CVEHICLE;
class CANIMAL;
class CCAR;
class CTRUCK;
class CDINOSAUR;
class CBIRD;
class CPEOPLE;

#include <thread>
#include "cbird.h"
#include "ccar.h"
#include "cdinosaur.h"
#include "cpeople.h"
#include "ctruck.h"
#include "header.h"

class CGAME {
    CVEHICLE** vehicles = nullptr;
    CANIMAL** animals = nullptr;
    CTRUCK* trucks = nullptr;
    CCAR* cars = nullptr;
    CDINOSAUR* dinosaurs = nullptr;
    CBIRD* birds = nullptr;
    CPEOPLE player;
    int MAX_LEVEL = 10;
    int MAX_BIRD = 10;
    int NUMBER_LANE = 10;
    int HEIGHT = 10;
    int WIDTH = 10;

public:
	//init game
    CGAME(); 
    void drawBackground();
    void drawGame();
    ~CGAME();
	//get info player
    CPEOPLE& getPlayer(); 
	//get vehicle list
    CVEHICLE** getVehicle(); 
	//get animal list
    CANIMAL** getAnimal(); 
    void resetGame();
	void exitGame(thread*, bool&);
	void startGame();
	/*void loadGame(istream);
	void saveGame(istream);*/
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	//control moving player
    void updatePosPlayer(char);
	//moving vehicle
    void updatePosVehicle(); 
	//moving animal
    void updatePosAnimal(); 
    void increaseTrafficAndFlock();
	bool isFinish();
	void makeSound();
	void updateLevel();
	void updateObstacle();
	void eraseOldObstacle();
};
