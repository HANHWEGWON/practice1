#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <conio.h>
#include <vector>

// 오토믹 사용 안하면 스레드에서 사용불가?
// 스레드는 언제 실행되는지?
// 선언 하면 바로 실행?
// join 종료대기? 
int seconds = 0, flag=0;

std::atomic<bool> isRunning(true); // 스레드 종료 조건
using namespace std;

vector<string> all_str;
// 스레드 함수: 사용자 입력 받기
void userInputThread() {
    std::string input;
    char ch = ' ';
    
    while (isRunning) {
        input = "";
        std::cout << "다음 단어를 입력하세요 -";
        while (true) {
            if (!isRunning) break;
            ch = _getch();

            if (ch == 13) {
                all_str.push_back(input);
                if (all_str.size() > 1) {
                    if (all_str[all_str.size() - 2][all_str[all_str.size() - 2].size() - 1] != all_str[all_str.size() - 1][0])
                        flag = 1;
                    else flag = 0;
                }
                if (flag == 1) { all_str.pop_back(); break; }
                
                seconds = 0;
                break; // Enter 키를 누르면 종료
            }
            input += ch;
        }
        if (!isRunning) break;
        std::cout << input << std::endl;
    }
}

int main() {
    std::thread inputThread(userInputThread);
    
    // 메인 스레드에서 초를 세기
    while (isRunning) {
        //std::cout << "\n경과 시간 (초): " << seconds << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds++;
        
        if (all_str.size() > 0) {
            for (int i = 0; i < all_str.size() - 1; i++) {
                cout << all_str[i] << "->";
            }
            cout << all_str[all_str.size() - 1];
        }
        
        
        if (seconds >= 30) {
            isRunning = false;
            inputThread.join(); // 스레드 종료 대기
            cout << "\n시간초과하셨습니다! 끝!";
            break;
        }
        else if (flag == 1) {
            cout << "\n앞 문자열과 연결되지 않았습니다! 다시!";
        }
    }

    

    return 0;
}
