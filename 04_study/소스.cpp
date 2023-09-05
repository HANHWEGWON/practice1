#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void gotoxy(int x, int y);

int main() {
	char szChoice=0;
	int x = 0, y = 0;
	while (true) {
		gotoxy(x, y);
		printf("¡Ú");
		if (_kbhit()) {
			szChoice=_getch();
			switch (szChoice) {
			case 'w':
				y--;
				break;
			case 'a':
				x--;
				break;
			case 's':
				y++;
				break;
			case 'd':
				x++;
				break;
			}
		}
		Sleep(10);
		system("cls");
	}
	

	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = {x*2, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}