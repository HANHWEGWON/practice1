#pragma once
#include "Weapon.h"
#include <vector>
class Character
{
private:
	int hp, level;
	vector<Weapon*> w;
public:

	Character(int hp, int level);
	int getHp() { return this->hp; }
	int getLevel() { return this->level; }
	void setHp(int hp) { this->hp = hp; }
	void setLevel(int level) { this->level = level; }
	vector<Weapon*> getWeapon() { return this->w; }
	void changeWeapon(Weapon* wp, int num);
	void setWeapon(Weapon* wp);
	void attack_character(Character& other, const vector<Weapon*> w, int num); //상대 캐릭터, 나의 무기, 무기종류(2)
};

