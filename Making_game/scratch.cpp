#include "scratch.h"

scratch::scratch() {
	this->set_attack_count(5);
	this->set_attack_power(5);
}

int scratch::attack_other() {
	if (this->get_attack_count() == 0) {
		cout << "���� �������� 0�Դϴ�.\n";
		return 0;
	}
	this->set_attack_count(this->get_attack_count() - 1);
	cout << "������\n";
	return 1;
}

void scratch::print_weapon() {
	cout << "��";
}