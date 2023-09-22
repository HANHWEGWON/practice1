#pragma once
#include "Weapon.h"
class scratch :public Weapon
{
public:
	scratch();
	int attack_other();
	void print_weapon();
};