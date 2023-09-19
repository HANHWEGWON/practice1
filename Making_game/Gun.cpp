#include "Gun.h"

Gun::Gun() {
	this->set_attack_count(2);
	this->set_attack_power(10);
}

int Gun::attack_other() {
	if (this->get_attack_count() == 0) {
		cout << "¹«±â ³»±¸µµ°¡ 0ÀÔ´Ï´Ù.\n";
		return 0;
	}
	this->set_attack_count(this->get_attack_count() - 1);
	cout << "ÃÑ½î±â\n";
	return 1;
}

void Gun::print_weapon() {
	cout << "ÃÑ";
}