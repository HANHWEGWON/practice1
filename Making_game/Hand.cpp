#include "Hand.h"

Hand::Hand() {
	this->set_attack_count(100);
	this->set_attack_power(1);
}

int Hand::attack_other() {
	if (this->get_attack_count() == 0) {
		cout << "무기 내구도가 0입니다.\n";
		return 0;
	}
	this->set_attack_count(this->get_attack_count() - 1);
	cout << "주먹가격!\n";
	return 1;
}

void Hand::print_weapon() {
	cout << "주먹";
}