#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int boundery = 31;
    int cnt = 0;
    int p_num, c_num;
    srand(time(NULL));


    while (true) {
        cout << "개수를 입력하세요: ";
        cin >> p_num;
        if (p_num < 1 || p_num>3) {
            cout << "1~3 사이의 수를 입력하세요.\n";
            continue;
        }
        cout << "사용자가 부른 숫자!\n";
        for (int i = 0; i < p_num; i++) {
            cout << ++cnt << '\n';
            if (cnt == boundery) {
                cout << "게임 종료! 컴퓨터의 승리입니다.";
                return 0;
            }

        }
            
        cout << "\n컴퓨터가 부른 숫자!\n";
        c_num = rand() % 3 + 1;
        for (int i = 0; i < c_num; i++) {
            cout << ++cnt << '\n';
            if (cnt == boundery) {
                cout << "게임 종료! 사용자의 승리입니다.";
                return 0;
            }
        }
    }
}

