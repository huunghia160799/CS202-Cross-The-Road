#include "header.h"

int StartMenu()
{
	printTitle();
	int pointer = 0;
	string Menu[4] = { "1.New game", "2.Load game", "3.Settings", "4.Exit" };
	while (1)
	{
		EraseMenu();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 4; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				GotoXY(95, 21 + i);
				cout << Menu[i];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				GotoXY(95, 21 + i);
				cout << Menu[i];
			}
		}
		while (GetAsyncKeyState(VK_RETURN) != 0) {}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				//Sleep(500);
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
				break;
			}
			else if ((GetAsyncKeyState(VK_DOWN) != 0))
			{
				//Sleep(500);
				pointer++;
				if (pointer == 4)
					pointer = 0;
				break;
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0))
			{
				switch (pointer)
				{
				case 0:
				{
					menu = 0;
					//cout << menu << endl;
					return menu;
					break;
				}
				case 1:
				{
					menu = 1;
					//cout << menu << endl;
					return menu;
					break;
				}
				case 2:
				{
					menu = 2;
					//cout << menu << endl;
					return menu;
					break;
				}
				case 3:
				{
					menu = 3;
					return menu;
					break;
				}
				break;
				}
			}
		}
	}
}
void ChangeSound()
{
	int temp = ' ';
	string Sound = "    ";
	if (sound)
		Sound = "ON ";
	else if (!sound)
		Sound = "OFF";
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	GotoXY(95, 20);
	cout << "SOUND";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	GotoXY(95, 21);
	cout << Sound;
	while (true)
	{
		Sleep(100);
		if ((GetAsyncKeyState(VK_RETURN) != 0))
		{
			switch (sound)
			{
			case true:
			{
				sound = false;
				Sound = "OFF";
				GotoXY(95, 21);
				cout << Sound;
				break;
			}
			case false:
			{
				sound = true;
				Sound = "ON ";
				GotoXY(95, 21);
				cout << Sound;
				break;
			}
			}
		}
		else
		{
			temp = _getch();
			if (temp == 27) {
				temp = ' ';
				break;
			}
		}
	}
}
void EraseMenu()
{
	for (int i = 0; i < 5; i++)
	{
		GotoXY(95, 20 + i);
		for (int j = 0; j < 40; j++)
			cout << ' ';
	}
}
void DifficultyByLevel(int level)
{
	int temp = ' ';
	int pointer = 0;
	bool back = false;
	string Menu[3] = { "1.Easy          ", "2.Medium           ", "3.Nightmare           " };
	string MenuCheck[3] = { "1.Easy (checked)" , "2.Medium (checked)" , "3.Nightmare (checked)" };
	while (1)
	{
		if (!back)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			GotoXY(95, 20);
			cout << "DIFFICULTY";
			for (int i = 0; i < 3; i++)
			{
				if (i == pointer)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					GotoXY(95, 21 + i);
					if (difficulty == i + 1)
						cout << MenuCheck[i];
					else
						cout << Menu[i];
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					GotoXY(95, 21 + i);
					if (difficulty == i + 1)
						cout << MenuCheck[i];
					else
						cout << Menu[i];
				}
			}
			while (true)
			{
				if (GetAsyncKeyState(VK_UP) != 0)
				{
					pointer -= 1;
					if (pointer == -1)
						pointer = 2;
					break;
				}
				else if ((GetAsyncKeyState(VK_DOWN) != 0))
				{
					pointer++;
					if (pointer == 3)
						pointer = 0;
					break;
				}
				else if ((GetAsyncKeyState(VK_RETURN) != 0))
				{
					switch (pointer)
					{
					case 0:
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						GotoXY(95, 21 + difficulty - 1);
						cout << Menu[difficulty - 1];
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						GotoXY(95, 21);
						cout << MenuCheck[0];
						difficulty = 1;
						break;
					}
					case 1:
					{

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						GotoXY(95, 21 + difficulty - 1);
						cout << Menu[difficulty - 1];
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						GotoXY(95, 22);
						cout << MenuCheck[1];
						difficulty = 2;
						break;
					}
					case 2:
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						GotoXY(95, 21 + difficulty - 1);
						cout << Menu[difficulty - 1];
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						GotoXY(95, 23);
						cout << MenuCheck[2];
						difficulty = 3;
						break;
					}
					break;
					}
				}
				else
				{
					temp = _getch();
					if (temp == 27) {
						temp = ' ';
						back = true;
						break;
					}
				}
			}
		}
		else if (back)
			break;
	}


}

void Credit()
{
	int temp = ' ';
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		GotoXY(95, 20);
		cout << "GROUP 7";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		GotoXY(95, 21);
		cout << "NGUYEN HO HUU NGHIA";
		GotoXY(95, 22);
		cout << "LE QUOC HUY";
		GotoXY(95, 23);
		cout << "TRAN NGUYEN HIEN";
		GotoXY(95, 24);
		cout << "LE HOANG DAT";
		temp = _getch();
		if (temp == 27)
		{
			temp = ' ';
			break;
		}
	}
}
int Settings()
{
	int temp = ' ';
	int pointer = 0;
	string Menu[3] = { "1.Sound", "2.Difficulty", "3.Credit" };
	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		GotoXY(95, 20);
		cout << "SETTINGS";
		for (int i = 0; i < 3; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				GotoXY(95, 21 + i);
				cout << Menu[i];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				GotoXY(95, 21 + i);
				cout << Menu[i];
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
					pointer = 2;
				break;
			}
			else if ((GetAsyncKeyState(VK_DOWN) != 0))
			{
				pointer++;
				if (pointer == 3)
					pointer = 0;
				break;
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0))
			{
				switch (pointer)
				{
				case 0:
				{
					settings = 0;
					return settings;
					break;
				}
				case 1:
				{
					settings = 1;
					return settings;
					break;
				}
				case 2:
				{
					settings = 2;
					return settings;
					break;
				}
				break;
				}
			}
			else
			{
				temp = _getch();
				if (temp == 27) {
					settings = 3;
					return settings;
				}
			}
		}
	}
}

int IngameMenu()
{
	int pointer = 0;
	string Menu[4] = { "1.Resume game", "2.Save game", "3.Load game", "4.Settings" };
	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		GotoXY(95, 20);
		cout << "PAUSE";
		for (int i = 0; i < 4; i++)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				GotoXY(95, 21 + i);
				cout << Menu[i];
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				GotoXY(95, 21 + i);
				cout << Menu[i];
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
				break;
			}
			else if ((GetAsyncKeyState(VK_DOWN) != 0))
			{
				pointer++;
				if (pointer == 4)
					pointer = 0;
				break;
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0))
			{
				switch (pointer)
				{
				case 0:
				{
					menuInGame = 0;
					//cout << menu << endl;
					return menuInGame;
					break;
				}
				case 1:
				{
					menuInGame = 1;
					//cout << menu << endl;
					return menuInGame;
					break;
				}
				case 2:
				{
					menuInGame = 2;
					//cout << menu << endl;
					return menuInGame;
					break;
				}
				case 3:
				{
					menuInGame = 3;
					return menuInGame;
					break;
				}
				break;
				}
			}
		}
	}
}

void printTitle() {
	int startX = 40, startY = 0;
	string buffer;
	ifstream fin("title.txt");
	for (int i = 0; i < 20; ++i) {
		GotoXY(startX, startY + i);
		getline(fin, buffer);
		cout << buffer;
	}
}