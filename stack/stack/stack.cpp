#include <iostream>
#include <string>
using namespace std;

class stack {
private:
    int data[101];
    int stackLen = -1;
    int SIZE;
public:
    stack() {
        cout << "choice stack size ※(1 <= size <= 100)\n->";
        cin >> SIZE;
        while (SIZE > 100 || SIZE < 1) {
            cout << "out of bounds\nYou have to respecify the scope again \n->";
            cin.clear();
            cin >> SIZE;
        }
    }
    ~stack() {}

    void push(int x) {
        if (stackLen == SIZE-1) cout << "stack is full\n";
        else {
            data[++stackLen] = x;
        }
        return;
    }
    void pop() {
        if (stackLen == -1) cout << "stack is empty!\n";
        else {
            data[stackLen] = NULL;
            stackLen--;
        }
        return;
    }

    void top() {
        if (stackLen == -1 || stackLen == 5) cout << "out of range\n";
        else {
            cout << "stack[" << stackLen << "]: " << data[stackLen] <<'\n';
        }
        return;
    }

    void printAll() {
        if (stackLen == -1) {
            cout << "stack is empty\n";
            return;
        }

        cout << "stack_data -> [";
        for (int i = 0; i < stackLen; i++) {
            cout << data[i] << ", ";
        }
        cout << data[stackLen] << "]";
        cout << "\n";
    }
};


int main()
{
    stack *st = new stack();
    string choice, element;
    int flag;

    while (true) {
        cout << "↓Please enter the same command that you want to choose from this menu↓\n";
        cout << "push || pop || top || printAll || end\n->";
        cin >> choice;
        if (choice == "push") {
            cout << "Please enter an integer.\n->";
            while (true) {
                flag = 0;
                cin >> element;
                for (int i = 0; i < element.size(); i++) {
                    if (isdigit(element[i]) == 0) {
                        cout << "It's not an integer. Please enter it again.\n->";
                        flag = 1; break;
                    }
                }

                if (flag == 0) {
                    st->push(stoi(element));
                    break;
                }
            }

        }
        else if (choice == "pop") {
            st->pop();
        }
        else if (choice == "top") {
            st->top();
        }
        else if (choice == "printAll") {
            st->printAll();
        }
        else if (choice == "end") {
            break;
        }
        else {
            cout << "It's not an command\n";
        }
        cin.clear();
    }

    cout << "end of stack";
    st->~stack();
    return 0;

}