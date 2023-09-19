#include "Weapon.h"

void Weapon::set_attack_count(int cnt) {
	this->attack_count = cnt;
}

void Weapon::set_attack_power(int power) {
	this->power = power;
}


int Weapon::get_attack_count() {
	return this->attack_count;
}

int Weapon::get_attack_power() {
	return this->power;
}
