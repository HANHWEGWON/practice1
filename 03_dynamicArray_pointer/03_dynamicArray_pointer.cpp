
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
    int *p가 가장 쓰기 편하다.
    ex) int* p, q <- q는 포인터가 아닌 정수형 q이기 때문에 int *p, *q 처럼 배치한다.
 */
int main()
{
    //int n2;
    //cin >> n2;
    //int* arr = new int[n2]; //동적 배열 선언 및 할당.

    //for (int i = 0; i < n2; i++) {
    //    arr[i] = i + 1;
    //} //배열공간안에 값 넣기

    //delete[] arr; //동적 배열 해제(반납) 동적 메모리는 사용 후 꼭 해제

    /*int x, y;
    cout << "x와 y를 입력하세요\n";
    cin >> x >> y;
    while (x <= 0 || y <= 0) {
        cout << "x와 y 모두 양수를 입력해주세요.\n";
        cin >> x >> y;
    }

    int** arr = new int *[x];
    for (int i = 0; i < x; i++) {
        arr[i] = new int [y];
    }

    int cnt = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = cnt++;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }

    for (int i = 0; i < x; i++) {
        delete[] arr[i];
    }
    delete[] arr;*/

    //----------------------------------------------------

    /*int score, range, i=0;
    cout << "학생수를 입력하세요:";
    cin >> range;
    cout << '\n';
    int* arr = new int[range];
    while (i<range) {
        cout <<i+1<< "번 학생의 성적을 입력하세요: ";
        cin >> score;
        cout << "\n\n";
        arr[i++] = score;
    }

    double avg = 0;
    for (int i = 0; i < range; i++) {
        avg += arr[i];
    }
    cout << "성적 평균: " << avg/range;
    delete[] arr;
    */

    //--------------------------------------------------

    /*int x, y;
    cout << "x와 y를 입력하세요\n";
    cin >> x >> y;
    while (x <= 0 || y <= 0) {
        cout << "x와 y 모두 양수를 입력해주세요.\n";
        cin >> x >> y;
    }

    vector<vector<int> > arr(x);
    int cnt = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i].push_back(cnt++);
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << arr[i][j] << ' ';
        }cout << '\n';
    }*/

    //----------------------------------------------

    /*vector<int> myVector = { 10, 20, 30, 20, 40, 10, 50 };
    sort(myVector.begin(), myVector.end());
    cout << myVector[0] << ' ';
    for (int i = 1; i < myVector.size(); i++) {
        if (myVector[i - 1] == myVector[i]) continue;
        cout << myVector[i] << ' ';
    }*/


}

