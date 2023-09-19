#pragma once
#include<iostream>
using namespace std;

class Weapon
{
private:
	int power, attack_count;
public:
	void set_attack_count(int cnt);
	void set_attack_power(int power);
	int get_attack_count();
	int get_attack_power();
	virtual void print_weapon() = 0;
	virtual int attack_other()=0;
};

