#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    cout << "야구 게임\n";
    srand(time(NULL));
    vector<int> c;
    int n, cnt=0;
    

    for (;;) {
        int r = rand() % 9 + 1;
        c.push_back(r);
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        if (c.size() == 3) break;
    }

    while (true) {
        cout << "1~9 사이의 숫자 3개를 입력 하시오 (이외의 숫자: 종료)\n";
        int memo[10] = { 0 };
        vector<int> p;
        
        while (true) {
            cin >> n;
            if (memo[n] == 1) {
                cout << "숫자가 중복되었습니다. 다시 입력해주세요.\n";
                continue;
            }
            if (n < 1 || n>9) {
                cout << "범위를 넘어섰습니다. 다시 입력해주세요.\n";
                continue;
            }
            p.push_back(n);
            memo[n] = 1;
            if (p.size() == 3) break;
        }

        for (int i : p) cout << i << ' ';
        
        int strike = 0, ball = 0;
        for (int i = 0; i < 3; i++) {
            if (memo[c[i]] == 1 && p[i] == c[i]) strike++;
            else if (memo[c[i]] == 1 && p[i] != c[i]) ball++;
        }
        cnt++;
        if (strike == 3) break;
        cout << "\nStrike : " << strike << "\tBall : " << ball << '\n';
    }

    cout << cnt << "번 만에 맞혔습니다.";

}

