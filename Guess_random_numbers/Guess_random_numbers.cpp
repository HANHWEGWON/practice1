#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    srand(time(NULL));
    vector<int> c;
    vector<int> p;

    for (;;) {
        int r = rand() % 25 + 1;
        c.push_back(r);
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        if (c.size() == 6) break;
    }
    int memo[26] = { 0 };
    int input, cnt=0;
    cout << "1~25사이 수를 입력하세요.\n";
    for (;;) {
        cin >> input;
        cout << ++cnt << "번째 번호를 입력하세요: " << input << '\n';
        if (memo[input] == 1) {
            cout << "이미 입력된 숫자입니다.\n";
            cnt--;
            continue;
        }
        if (input < 1 || input>25) {
            cout << "잘못된 숫자입니다. 다시 입력해주세요.\n";
            cnt--;
            continue;
        }
        memo[input] = 1;
        p.push_back(input);
        if (p.size() == 6) break;
    }

    cout << "당첨번호 공개!\n";
    int answer = 0;
    for (int i = 0; i < 6; i++) {
        cout << c[i] << ' ';
        if (memo[c[i]] == 1) answer++;
    }
    cout << "\n1~7등까지 결과가 나올 수 있습니다.\n";
    cout << "결과 : ";
    cout << 7 - answer << "등입니다!";
    
    
}

