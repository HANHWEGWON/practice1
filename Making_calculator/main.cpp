#include "Division.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include<string>

Calculator* choice_op(Calculator *cptr, char op) {
    
    
        switch (op) {
        case '/':
            cptr = new Division();
            break;
        case '*':
            cptr = new Multiplication();
            break;
        case '+':
            cptr = new Addition();
            break;
        case '-':
            cptr = new Subtraction();
            break;
        default:
            cout << "연산자가 아닙니다. 다시입력해주세요.\n";
        }
       
        return cptr;
}






int main()
{
    Calculator* cptr=0;

    float a, b;
    char op;
    int flag = 0;
    while (true) {

        if (flag == 0) {
            cout << "숫자를 입력해주세요 : ";
            cin >> a;
        }

        cout << "연산자를 입력해주세요 : ";
        cin >> op;
        cout << "숫자를 입력해주세요 : ";
        cin >> b;

        cptr=choice_op(cptr, op);

        if (flag == 0) cptr->arithmetic(a, b);
        else cptr->arithmetic(cptr->result_num, b);
        cout << "------------------------------------------------\n";
        cout << "결과 : " << cptr->getOp() << '\n';
        cout << "------------------------------------------------\n";
        
        while (true) {
            cout << "연산을 계속 진행하시겠습니까? (Y: 계속, AC: 초기화, EXIT: 종료) ";
            string choice; cin >> choice;
            if (choice.compare("Y") == 0) {
                flag = 1; cptr->result_num = cptr->getOp();  break;
            }
            else if (choice.compare("AC") == 0) {
                flag = 0; cptr->result_num = 0;  break;
            }
            else if (choice.compare("EXIT") == 0) {
                return 0;
            }
            else {
                cout << "그런 명령어는 없습니다. 다시입력해주세요.\n";
                continue;
            }
        }
        




    }

}
