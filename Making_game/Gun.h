#pragma once
#include "Weapon.h"
class Gun :public Weapon
{
public:
	Gun();
	int attack_other();
	void print_weapon();
};

