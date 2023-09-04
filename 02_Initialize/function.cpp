#include<iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	int ret = a > b ? a - b : b - a;
	return ret;
}

int mul(int a, int b) {
	return a * b;
}

double divide(int a, int b) {
	double ret = (double)a / (double)b;
	return ret;
}

void isRight(int v) {
	v % 2 == 0 ? cout << "짝수" : cout << "홀수";
	return;
}

int get_large_size(int a, int b, int c) {
	int num = a > b ? a : b;
	num = num > c ? num : c;
	return num;
}

int get_small_size(int a, int b, int c, int d) {
	int temp1 = a < b ? a : b;
	int temp2 = c < d ? c : d;
	return temp1 < temp2 ? temp1 : temp2;
}

int main() {
	/*int op1, op2;
	cout << "두 정수를 입력해주세요.\n";
	cin >> op1 >> op2;
	cout << "add: " << add(op1, op2) << '\n';
	cout << "sub: " << sub(op1, op2) << '\n';
	cout << "mul: " << mul(op1, op2) << '\n';
	cout << "divide: " << divide(op1, op2) << '\n'*/

	/*int data;
	for (int i = 0; i < 2; i++) {
		cin >> data;
		isRight(data);
	}*/

	/*int a, b, c, d;
	cin >> a >> b >> c>>d;
	cout<<get_small_size(a, b, c, d);*/

	/*string city[5] = { "한국", "일본", "중국", "베트남", "호주" };
	for (int i = 0; i < 5; i++) cout << city[i] << '\n';*/
	
	/*int grade[5];
	for (int i = 0; i < 5; i++) {
		cout << i+1 << "번 학생의 성적을 입력하세요: ";
		cin >> grade[i];
	}
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += grade[i];
	}

	cout << (double)sum / 5;*/
	double sum = 0;
	int a, b;
	cin >> a >> b;
	sum = a + b;
	
	
}