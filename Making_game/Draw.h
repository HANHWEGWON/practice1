#pragma once
#include <iostream>
#include <vector>
#include<string>
#include<ctime>
#include<windows.h>
#include<cstdlib>

using namespace std;

class Draw
{
public:
	void DrawMainScreen();
	void DrawStageLevel_01();
	void DrawStageLevel_02();
	void DrawStageLevel_03();
	void DrawFinish();
	void DrawMap(int(*map)[51], int (*check)[51], int row_size, int col_size);
};

