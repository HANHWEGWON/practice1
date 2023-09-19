#pragma once
#include"Weapon.h"
class Knife:public Weapon
{
public:
	Knife();
	int attack_other();
	void print_weapon();
};

