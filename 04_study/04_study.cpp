

#include <iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    /*vector<int> v;
    int a, b=0;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        v.push_back(a);
    }
    cout << "벡터사이즈:" << v.size() << '\n';
    cout << "벡터값: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
        if (b < v[i]) b = v[i];
    }
    cout << '\n';
    cout <<"가장 큰 값: " << b << '\n';
    cout << "벡터 원소x2 :";
    for (int i = 0; i < v.size(); i++) {
         cout << v[i] * 2 << ' ';
    }
    cout << '\n';
    int index;
    while (true) {
        cout << "인덱스를 입력받아 해당 인덱스에 있는 원소 제거(-1[종료]):";
        cin >> index;
        cout << '\n';
        if (index == -1) {
            cout << "인덱스 제거 종료------\n\n";
            break;
        }
        else if (index >= v.size()) {
            cout << "인덱스 범위를 벗어났습니다\n";
            continue;
        }

        cout << index << "번째 원소 제거\n";
        v.erase(v.begin() + index);
        cout << "printV:";
        for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        cout << '\n';
    }

    while (true) {
        cout << "인덱스를 입력받아 해당 인덱스에 있는 새로운 원소 삽입(-1[종료]):";
        cin >> index;
        cout << '\n';
        if (index == -1) {
            cout << "인덱스 삽입 종료------\n\n";
            break;
        }
        else if (index >= v.size()) {
            cout << "현재 인덱스 범위를 넘었습니다.\n";
            continue;
        }
        cout << "데이터 입력: ";
        int data; cin >> data;
        cout << index << "번째에 삽입\n";

        v.insert(v.begin() + index, data);
        cout << "printV:";
        for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        cout << '\n';
    }*/

    /*cout << "행과 열의 수를 입력하세요: ";
    int row, col, data;
    cin >> row >> col;
    vector<vector<int> > v(row);
    cout << "행렬 원소를 입력하세요: \n";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }

    cout << "각행의 합:\n";
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += v[i][j];
        }
        cout << "행" << i + 1 << ": " << sum << '\n';
    }

    cout << "각 열의 합:\n";
    for (int j = 0; j < col; j++) {
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += v[i][j];
        }
        cout << "열 " << j + 1 << ": " << sum << '\n';
    }*/

    /*int a;
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        v.push_back(a);
    }
    for (int k = 0; k < v.size(); k++) {
        if (v[k] % 2 != 0) {
            v.erase(v.begin() + k); k--;
        }
    }
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    */

    //list<int> myList = { 5, 4, 3, 4, 2, 1, 1 };
    //cout << "4는 몇개?  ";
    //int cnt = 0;
    //for (auto element : myList) {
    //    if (element == 4) cnt++;
    //}
    //cout << cnt << '\n';
    //
    //myList.sort();
    //
    //cout << "3번->";
    //for (auto element : myList) {
    //    cout << element << ' ';
    //}
    //cout << "\n4번->";
    //myList.unique();
    //for (auto element : myList) {
    //    cout << element << ' ';
    //}
    //cout << "\n5번->";
    //list<int> myList2 = { 6, 7 };
    //list<int> myList3 = { 0 };
    //myList.splice(myList.end(), myList2);
    //
    //for (auto element : myList) {
    //    cout << element << ' ';
    //}
    //cout << "\n6번->";
    //myList.merge(myList3);
    //for (auto element : myList) {
    //    cout << element << ' ';
    //}

    /*int a[5] = { 1, 2, 3, 4, 5 };
    for (int i = 4; i >= 1; i--)  a[i] = a[i - 1];
    a[0] = 0;
    for (int i = 0; i < 5; i++) cout << a[i] << ' ';*/
}


