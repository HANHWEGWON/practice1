#include "Draw.h"


enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void Draw::DrawMainScreen() {
	setColor(RED);
	cout << "                                                 \n\n";
	cout << "			#####    #####     ####                   \n";
	cout << "			#    #   #    #   #                       \n";
	cout << "			#####    #####    #  ###                  \n";
	cout << "			#    #   #        #   #                   \n";
	cout << "			#    #   #         ####                   \n";
	cout << "						                          \n";
	cout << "		   *시작하려면 아무키나눌러주세요.*            \n";
}

void Draw::DrawStageLevel_01() {
	setColor(YELLOW);
	cout << "																	\n\n";
	cout << "       ###  #######      #       ####    ######     ##			\n";
	cout << "      #        #        # #     #        #         ### 	\n";
	cout << "      ####     #       #   #    #  ###   ######     ##			\n";
	cout << "         #     #       #####    #   #    #          ##	         \n";
	cout << "      ###      #      #     #    ####    ######    #### 		\n";
	cout << "																	\n";
	Sleep(2000);
	system("cls");
}

void Draw::DrawStageLevel_02() {
	setColor(VIOLET);
	cout << "																	\n\n";
	cout << "       ###  #######      #       ####    ######      #####			\n";
	cout << "      #        #        # #     #        #          ##   ##			\n";
	cout << "      ####     #       #   #    #  ###   ######        ##			\n";
	cout << "         #     #       #####    #   #    #           ##			\n";
	cout << "      ###      #      #     #    ####    ######     ########        \n";
	cout << "																	\n";
	Sleep(2000);
	system("cls");
}

void Draw::DrawStageLevel_03() {
	setColor(RED);
	cout << "																	\n\n";
	cout << "       ###  #######      #       ####    ######      #####			\n";
	cout << "      #        #        # #     #        #          ##   ##			\n";
	cout << "      ####     #       #   #    #  ###   ######       ####			\n";
	cout << "         #     #       #####    #   #    #               ##			\n";
	cout << "      ###      #      #     #    ####    ######      #####          \n";
	cout << "																	\n";
	Sleep(2000);
	system("cls");
}


void Draw::DrawFinish() {
	int n = 100;
	
	while (n!=0) {
		setColor(rand() % 15);
		Sleep(500); n--;
		cout << "																	                                          \n";
		cout << "   ###	 ###    #   #   ####    ####       #    #######  #     #   #         #      #######  ######    \n";
		cout << "  #   # #   #   ##  #  #        #   #     # #      #     #     #   #        # #        #     #          \n";
		cout << "  #     #   #   # # #  #  ###   ####     #   #     #     #     #   #       #   #       #     ######    \n";
		cout << "  #   # #   #   #  ##  #   #    #   #    #####     #     #     #   #       #####       #     #             \n";
		cout << "   ###   ###    #   #   ####    #   #   #     #    #      #####    #####  #     #      #     ######    \n";
		cout << "																 	\n";
	}
	/*cout << "																	                                          \n";
	cout << "   ###	 ###    #   #   ####    ####       #    #######  #     #   #         #      #######  ######    \n";
	cout << "  #   # #   #   ##  #  #        #   #     # #      #     #     #   #        # #        #     #          \n";
	cout << "  #     #   #   # # #  #  ###   ####     #   #     #     #     #   #       #   #       #     ######    \n";
	cout << "  #   # #   #   #  ##  #   #    #   #    #####     #     #     #   #       #####       #     #             \n";
	cout << "   ###   ###    #   #   ####    #   #   #     #    #      #####    #####  #     #      #     ######    \n"; 
	cout << "																 	\n";*/
	Sleep(5000);
}

int dx[4] = { 0, 0, +2, -2 };
int dy[4] = { +2, -2, 0, 0 };

void shuffleArray(int size)
{
	int i, r;
	int temp1, temp2;

	for (i = 0; i < (size - 1); ++i)
	{
		r = i + (rand() % (size - i));
		temp1 = dx[i];
		temp2 = dy[i];

		dx[i] = dx[r];
		dy[i] = dy[r];

		dx[r] = temp1;
		dy[r] = temp2;
	}
}

void dfs(int r, int c, int(*map)[51], int(*check)[51], int row_size, int col_size) {


	shuffleArray(4);
	
	for (int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		
		if (nr > row_size-2 || nr < 1 || nc>col_size-2 || nc < 1) continue;
		if (check[nr][nc] == 1) continue;
		check[nr][nc] = 1;
		if (map[nr][nc] == 1) {
			if (nr != r)
				map[(nr + r) / 2][c] = 0;
			// 가로 축 이동인 경우
			else
				map[r][(c + nc) / 2] = 0;
			map[nr][nc] = 0;
		}
		dfs(nr, nc, map, check, row_size, col_size);
	}
}

void Draw::DrawMap(int (*map)[51], int (*check)[51], int row_size, int col_size) {
	
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			map[i][j] = 1;
			check[i][j] = 0;
		}
	}
	int x = rand() % col_size;
	int y = rand() % row_size;
	if (x % 2 == 0) x--;
	if (y % 2 == 0) y--;
	check[y][x] = 1;
	dfs(y, x, map, check, row_size, col_size);

}
