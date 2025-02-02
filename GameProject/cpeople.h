#pragma once

class CVEHICLE;
class CANIMAL;
class CGAME;

#include "canimal.h"
#include "cvehicle.h"
#include "header.h"
class CPEOPLE {
    int mX, mY; // position
    bool mState; // status
    int score;
    short level;
    int tempX, tempY;

public:
	friend class CGAME;
    CPEOPLE()
    {
        mX = (MAXWIDTH / 2) - 1;
        mY = 21;
        level = 1;
        score = 0;
        mState = true;
        tempX = (MAXWIDTH / 2) - 1;
        tempY = 21;
    };
    void Up(int);
    void Left(int);
    void Right(int);
    void Down(int);
	inline void setAlive() {
		mState = true;
	}
    bool isImpact1(CVEHICLE* const& vehicle); // true = impact, false = not impact
    bool isImpact2(CANIMAL* const& animal);
    bool isFinish();
    bool isDead();
    int getScore();
    short& getLevel();
    void DrawPLayer();
    void increaseLevel();
	inline int& getX() { 
		return mX; };
	inline int& getY() { 
		return mY; };
	inline void resetPosition() { 
		mY = 21; };
	void eraseOldPlayer();
	void dieEffect();
	inline void setDead() {
		mState = false;
	};
};
