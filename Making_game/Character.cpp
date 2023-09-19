#include "Character.h"

Character::Character(int hp, int level){
	this->hp = hp;
	this->level = level;
}

void Character::setWeapon(Weapon* wp) { 
	this->w.push_back(wp);
}

void Character::changeWeapon(Weapon* wp, int num) {
	this->w[num] = wp;
}

void Character::attack_character(Character& c, const vector<Weapon*> w, int num) {
	if (this->w[num]->attack_other()==1) {
		c.hp -= this->w[num]->get_attack_power();
	}
}