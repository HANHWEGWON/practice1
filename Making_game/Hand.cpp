#include "Hand.h"

Hand::Hand() {
	this->set_attack_count(100);
	this->set_attack_power(1);
}

int Hand::attack_other() {
	if (this->get_attack_count() == 0) {
		cout << "���� �������� 0�Դϴ�.\n";
		return 0;
	}
	this->set_attack_count(this->get_attack_count() - 1);
	cout << "�ָ԰���!\n";
	return 1;
}

void Hand::print_weapon() {
	cout << "�ָ�";
}