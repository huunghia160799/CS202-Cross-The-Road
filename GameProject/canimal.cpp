#include "canimal.h"
//Vehicle

int CANIMAL::n = 3;
int CANIMAL::m = 4;

CANIMAL::CANIMAL(int x, int y)
	:mX(x), mY(y), prevX(0), prevY(0) {};

void CANIMAL::Move(int x, int y)
{
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
};

void CANIMAL::Draw() {
	for (int i = 0; i < n; ++i) {
		GotoXY(prevX, prevY + i);
		for (int j = 0; j < m; ++j) {
			cout << ' ';
		}
	}
};

void CANIMAL::Erase() {
	for (int i = 0; i < n; ++i) {
		GotoXY(mX, mY + i);
		for (int j = 0; j < m; ++j) {
			cout << ' ';
		}
	}
};