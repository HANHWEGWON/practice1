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
	void DrawMap(int(*map)[51], int (*check)[51]);
};

