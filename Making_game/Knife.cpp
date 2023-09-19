#include "Knife.h"

Knife::Knife() {
	this->set_attack_count(5);
	this->set_attack_power(5);
}

int Knife::attack_other() {
	if (this->get_attack_count() == 0) {
		cout << "무기 내구도가 0입니다.\n";
		return 0;
	}
	this->set_attack_count(this->get_attack_count() - 1);
	cout << "찌르기\n";
	return 1;
}

void Knife::print_weapon() {
	cout << "칼";
}