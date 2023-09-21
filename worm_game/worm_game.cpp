#include<Windows.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include<queue>

// 보드 크기 N*N 정사각형
#define MAX_N 10 

#define RIGHT 77
#define DOWN 80
#define LEFT 75
#define UP 72

using namespace std;

struct WORM {
	// 좌표
	int x, y;
	// 움직이는 방향
	int next_way;
	// 먹었나 안먹었나
	bool eat;
};

// 지렁이 움직이기
bool wriggle(int(*board)[MAX_N], queue<WORM>& del_tail, WORM& bfw);
// 초기설정
void init(int(*board)[MAX_N], queue<WORM>& del_tail, WORM& bfw);
// 먹이 랜덤 생성
void food(int(*board)[MAX_N]);
// 게임 화면
void draw(int board[][MAX_N]);
// 입력
int input(int way);
// 메인게임
void game();

int main() {
	game();
	system("cls");
	printf("\n\n\ngame over\n\n\n\n");
	return 0;
}

void game() {
	// 보드 생성
	int board[MAX_N][MAX_N] = { 0 };
	// 종료 조건
	bool flag = true;
	// 지렁이 속도
	int speed = 300;

	// 꼬리를 담당하는 큐
	queue<WORM> del_tail;
	// 머리 부분 좌표
	WORM bfw;

	init(board, del_tail, bfw);

	draw(board);

	while (flag) {
		bfw.next_way = input(bfw.next_way);
		flag = wriggle(board, del_tail, bfw);
		draw(board);

		// 딜레이
		Sleep(speed);
		// 딜레이 감소
		speed = speed - 1 > 100 ? speed - 1 : speed;
	}

}

void init(int(*board)[MAX_N], queue<WORM>& del_tail, WORM& bfw) {
	// 상,우,하,좌 (시계방향)
	int way[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

	bfw.x = 0, bfw.y = 0, bfw.next_way = 1, bfw.eat = false;

	board[bfw.y][bfw.x] = 1;
	del_tail.push(bfw);

	// 길이 4짜리 지렁이
	for (int i = 0; i < 4; i++) {
		bfw.x += way[bfw.next_way][1], bfw.y += way[bfw.next_way][0];
		board[bfw.y][bfw.x] = 1;
		del_tail.push(bfw);
	}

	food(board);
}


int input(int way) {
	int next_way = way;

	// 키보드가 눌리면
	if (_kbhit()) {
		int key = _getch();
		if (key == 0xE0 || key == 0) {
			key = _getch();

			switch (key) {
			case UP:
				// 마주보는 방향으로는 갈수없음
				if (way != 2)
					next_way = 0;
				break;
			case RIGHT:
				if (way != 3)
					next_way = 1;
				break;
			case DOWN:
				if (way != 0)
					next_way = 2;
				break;
			case LEFT:
				if (way != 1)
					next_way = 3;
				break;
			default:
				break;
			}
		}
	}
	return next_way;
}

bool wriggle(int(*board)[MAX_N], queue<WORM>& del_tail, WORM& bfw) {

	// 방향 시계방향순 map[y][x] 
	int way[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };

	// 움직임
	bfw.y += way[bfw.next_way][0], bfw.x += way[bfw.next_way][1];

	if (bfw.y < 0 || bfw.y >= MAX_N || bfw.x < 0 || bfw.x >= MAX_N // 벽에 닿거나
		|| board[bfw.y][bfw.x] == 1)	// 지렁이몸에 닿으면
		return false;  //게임오버

	// 먹이을 먹음
	if (board[bfw.y][bfw.x] == 2)
		bfw.eat = true, food(board);

	board[bfw.y][bfw.x] = 1;
	del_tail.push(bfw);

	if (!bfw.eat) {
		WORM cur = del_tail.front();
		del_tail.pop();
		board[cur.y][cur.x] = 0;
	}

	bfw.eat = false;
	return 1;
}

void food(int(*board)[MAX_N]) {

	// 빈칸 세는 변수 , 랜덤값 저장변수
	int cnt = 0, ra;
	// 빈칸을 저장하는 포인터배열
	int* p[MAX_N * MAX_N];

	for (int i = 0; i < MAX_N; i++)
		for (int j = 0; j < MAX_N; j++)
			if (board[i][j] == 0)
				p[cnt++] = &board[i][j];

	srand(time(NULL));
	ra = rand() % cnt;
	*p[ra] = 2;
}

void draw(int board[][MAX_N]) {

	system("cls");

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++)

			switch (board[i][j]) {
				// 지렁이 몸
			case 1:
				printf("@ ");
				break;
				//먹이
			case 2:
				printf("* ");
				break;
				//빈곳
			default:
				printf(". ");
				break;
			}

		printf("\n");
	}
}
