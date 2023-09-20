#include <iostream>
#include "Character.h"
#include "Knife.h"
#include "Gun.h"
#include "Hand.h"
#include<windows.h>
#include "Draw.h"
#include <mmsystem.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<string>
#pragma comment(lib,"winmm.lib")
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77



void gotoxy(int y, int x)
{
    COORD Pos;        //x, y를 가지고 있는 구조체
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void find_monster(Character &player) {
    int check;
    cout << "상대를 만났습니다!\n";
    cout << "무기를 두가지 선택해주세요 \n0:주먹 1:칼 2:총\n";

    for (int i = 1; i <= 2; i++) {
        cin >> check;
        if (check == 0) {
            player.setWeapon(new Hand());
        }
        else if (check == 1) {
            player.setWeapon(new Knife());
        }
        else if (check == 2) {
            player.setWeapon(new Gun());
        }
    }
    system("cls");
}

void monster_event(Character &player) {
    int choice;

    Character monster(30, 1);
    
    monster.setWeapon(new Hand());

    find_monster(player);

    while (true) {
        cout << "---------------------------현재정보-------------------------------\n";
        cout << "몬스터 hp: " << monster.getHp() << "  lv: " << monster.getLevel() << "\n";
        cout << "플레이어 hp: " << player.getHp() << "  lv: " << player.getLevel() << "\n";
        cout << "------------------------------------------------------------------\n";
        cout << "1번째 무기: "; player.getWeapon()[0]->print_weapon();   cout << "  2번째 무기: "; player.getWeapon()[1]->print_weapon(); cout << '\n';
        cout << "무기 공격력: " << player.getWeapon()[0]->get_attack_power(); cout << "  무기 공격력: " << player.getWeapon()[1]->get_attack_power() << '\n';
        cout << "무기 내구도: " << player.getWeapon()[0]->get_attack_count();    cout << "  무기 내구도: " << player.getWeapon()[1]->get_attack_count() << '\n';
        cout << "------------------------------------------------------------------\n";



        cout << "사용할 무기의 번호를 입력하세요.\n";
        cin >> choice;
        if (choice == 1) {
            cout << "player의 공격->"; player.attack_character(monster, player.getWeapon(), 0);
        }
        else if (choice == 2) {
            cout << "player의 공격->"; player.attack_character(monster, player.getWeapon(), 1);
        }


        for (int i = 0; i < player.getWeapon().size(); i++) {
            if (player.getWeapon()[i]->get_attack_count() == 0) {
                player.changeWeapon(new Hand(), i);
            }
        }


        if (monster.getHp() < 1) {
            cout << "******몬스터를 처치했습니다!!*******";

            break;
        }

        cout << "몬스터의 공격->"; monster.attack_character(player, monster.getWeapon(), 0);

        Sleep(3000);
        system("cls");

    }
}

int main()
{
    PlaySound(L"file_example_WAV_1MG.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
    //_getch();
    system("mode con:cols=110 lines=33");
    srand(time(NULL));
    Draw* dr = new Draw();
    dr->DrawMainScreen();
    int input; cin >> input;
    system("cls");
    
    vector<pair<int, int> > loc;
    Character player(20, 1);
    
    
    int r, c;
    int map[31][51], check[31][51];
    dr->DrawMap(map, check);
    char ch;

    int cnt = 0;
    
    while (true) {
        r = rand() % 31;
        c = rand() % 51;
        if (map[r][c] == 1) continue;
        map[r][c] = 2; break;
    }

    while (true) {
        int enemy_y = rand() % 31;
        int enemy_x = rand() % 51;
        
        if (map[enemy_y][enemy_x] == 1 || map[enemy_y][enemy_x]==2) continue;
        map[enemy_y][enemy_x] = 3;
        cnt++;
        if (cnt == 3) break;
    }
    
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 51; j++) {
            if (map[i][j] == 1) cout << "■";
            else if (map[i][j] == 2) {
                cout << "★";
            }
            else if (map[i][j] == 3) {
                cout << "♠";
            }
            else cout << "□";

        }cout << '\n';
    }


    gotoxy(r, c);


    while (true) {
        
        if (_kbhit()) {
            ch = _getch();
            if (ch == -32) {
                ch = _getch();
                switch (ch) {
                case LEFT:
                    if (map[r][c - 1] == 1) break;
                    
                    c--;
                    break;
                case RIGHT:
                    if (map[r][c+1] == 1) break;
                    
                    c++;
                    break;
                case UP:
                    if (map[r-1][c] == 1) break;
                    
                    r--;
                    break;
                case DOWN:
                    if (map[r+1][c] == 1) break;
                    
                    r++;
                    break;
                }
                if (map[r][c] == 3) {
                    system("cls");
                    monster_event(player);
                    system("cls");
                    map[r][c] = 0;
                    for (int i = 0; i < 31; i++) {
                        for (int j = 0; j < 51; j++) {
                            if (map[i][j] == 1) cout << "■";
                            else if (map[i][j] == 2) {
                                cout << "★";
                            }
                            else if (map[i][j] == 3) {
                                cout << "♠";
                            }
                            else cout << "□";

                        }cout << '\n';
                    }
                }
                cout << "□";
                gotoxy(r, c);
                cout << "★";
                gotoxy(r, c);
                
            }
            
        }
    }


    /*int choice;

    Character player(20, 1);
    Character monster(30, 1);
    monster.setWeapon(new Hand());
    
    find_monster(player);
    
    while (true) {
        cout << "---------------------------현재정보-------------------------------\n";
        cout << "몬스터 hp: " << monster.getHp() << "  lv: " << monster.getLevel() << "\n";
        cout << "플레이어 hp: " << player.getHp() << "  lv: " << player.getLevel() << "\n";
        cout << "------------------------------------------------------------------\n";
        cout << "1번째 무기: "; player.getWeapon()[0]->print_weapon();   cout << "  2번째 무기: "; player.getWeapon()[1]->print_weapon(); cout << '\n';
        cout << "무기 공격력: " << player.getWeapon()[0]->get_attack_power(); cout << "  무기 공격력: " << player.getWeapon()[1]->get_attack_power() << '\n';
        cout << "무기 내구도: " << player.getWeapon()[0]->get_attack_count();    cout << "  무기 내구도: " << player.getWeapon()[1]->get_attack_count() << '\n';
        cout << "------------------------------------------------------------------\n";
        
        

        cout << "사용할 무기의 번호를 입력하세요.\n";
        cin >> choice;
        if (choice == 1) {
            cout << "player의 공격->"; player.attack_character(monster, player.getWeapon(), 0);
        }
        else if (choice == 2) {
            cout << "player의 공격->"; player.attack_character(monster, player.getWeapon(), 1);
        }


        for (int i = 0; i < player.getWeapon().size(); i++) {
            if (player.getWeapon()[i]->get_attack_count() == 0) {
                player.changeWeapon(new Hand(), i);
            }
        }
        
        
        if (monster.getHp() < 1) {
            cout << "******몬스터를 처치했습니다!!*******";

            break;
        }

        cout << "몬스터의 공격->"; monster.attack_character(player, monster.getWeapon(), 0);

        Sleep(3000);
        system("cls");

    }*/


}
