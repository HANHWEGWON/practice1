#include<iostream>
using namespace std;

namespace seoul {
	int local_num;
	string randmark;
	
	void print() {
		cout << local_num << ' ' << randmark << '\n';
	}
}

namespace busan {
	int local_num;
	string randmark;

	void print() {
		cout << local_num << ' ' << randmark << '\n';
	}
}

using namespace busan;

int main() {
	seoul::local_num = 10;
	seoul::randmark = "����Ÿ��";
	local_num = 20;
	randmark = "����";

	seoul::print();
	::print();


}