// 01_Initialize.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char op;
	cout << "연산할 정수 두 개를 입력해 주세요.\n";
	while (1) {
		cin >> a >> b;
		cout << "연산자를 입력해주세요 (+ - * /)";
		cin >> op;
		cout << "\n**** 연산결과 ---->";
		if (op == '+') {
			cout << "몫:" << a + b << "입니다.";
		}
		else if (op == '-') {
			cout << "몫:" << a - b << "입니다.";
		}
		else if (op == '*') {
			cout << "몫:" << a * b << "입니다.";
		}
		else if (op == '/') {
			cout << "몫:" << a / b << "나머지는" << a % b << "입니다.";
		}
	}
	


}
