#pragma once
#include "Weapon.h"
class Hand :public Weapon
{
public:
	Hand();
	int attack_other();
	void print_weapon();
};

