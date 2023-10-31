#include <iostream>
#include "Character.h"
#include "Knife.h"
#include "Gun.h"
#include "Hand.h"
#include<windows.h>
#include "Draw.h"
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<string>
#include "scratch.h"
#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

int monster_flag = 0, monster_hp_plus = 30, monster_level_plus = 5;
int map[31][51], check[31][51];
int attack_plus = 0;
int count_plus = 0;
int end_point = 0;
Draw* dr = new Draw();

void start_game(Character&);


void gotoxy(int y, int x)
{
    COORD Pos;        //x, y를 가지고 있는 구조체
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void find_monster(Character &player) {
    int check;
    //player.getWeapon().clear();
    cout << "상대를 만났습니다!\n";
    cout << "무기를 두가지 선택해주세요 \n0:주먹 1:칼 2:총\n";
    if (player.getWeapon().size() != 0) {
        for (int i = 1; i <= 2; i++) {
            cin >> check;
            if (check == 0) {
                player.changeWeapon(new Hand(), i - 1);
            }
            else if (check == 1) {
                player.changeWeapon(new Knife(), i - 1);
            }
            else if (check == 2) {
                player.changeWeapon(new Gun(), i - 1);
            }
            player.getWeapon()[i - 1]->set_attack_power(player.getWeapon()[i - 1]->get_attack_power() + attack_plus);
            player.getWeapon()[i - 1]->set_attack_count(player.getWeapon()[i - 1]->get_attack_count() + count_plus);
        }
    }
    else {
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
    }

    system("cls");
}


void monster_event(Character &player) {
    int choice;
    PlaySound(L"Lite-Saturation-War.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
   
    int hp, level;
    if (monster_flag == 0) { hp = 30; level = 1; }
    else if (monster_flag == 1) { hp = 65; level = 5; }
    else {hp = 100; level = 10;}

    Character monster(hp, level);
    monster.setWeapon(new scratch());
    monster.setWeapon(new Hand());

    find_monster(player);

    while (true) {
        cout << "\n---------------------------현재정보-------------------------------\n";
        cout << "몬스터 hp: " << monster.getHp() << "  lv: " << monster.getLevel() << "\n";
        cout << "플레이어 hp: " << player.getHp() << "  lv: " << player.getLevel() << "\n";
        cout << "\n---------------------------무기정보-------------------------------\n";
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
            player.setLevel(player.getLevel() + 1);
            player.setHp(player.getHp() + 10);
            attack_plus += 3;
            count_plus += 1;
            break;
        }
        int r = rand() % 2;
        cout << "몬스터의 공격->"; monster.attack_character(player, monster.getWeapon(), r);

        if (player.getHp() < 1) {
            system("cls");
            cout << "       **********************************\n";
            cout << "       **********************************\n";
            cout << "       *********당신은 죽었습니다********\n";
            cout << "       **********************************\n";
            cout << "       **********************************\n";
            end_point = 1;
            Sleep(2000);
            break;
        }
     

        Sleep(1500);
        system("cls");

    }
}


void printMap(int row_size, int col_size, Character& player) {
    
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (map[i][j] == 1) cout << "■";
            else if (map[i][j] == 2) {
                cout << "★"; map[i][j] = 0;
            }
            else if (map[i][j] == 3) {
                cout << "♠";
            }
            else if (map[i][j] == 4) {
                cout << "◎";
            }else
                cout << "  ";

        }cout << '\n';
    }
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
    cout << "\n                현재 나의 HP->" << player.getHp() << " LV->" << player.getLevel() << '\n';
    cout << "         ***조작법: 방향키[←, →, ↑, ↓]*** \n";
    cout << "       벽:■    사용자:★     몬스터:♠     포탈:◎";

}
int r, c;

void insert_map_event(int monster_cnt, int row_size, int col_size) {
    
    int cnt = 0;
    while (true) {
        r = rand() % row_size;
        c = rand() % col_size;
        if (map[r][c] == 1) continue;
        map[r][c] = 2; break;
    }

    while (true) {
        int enemy_y = rand() % row_size;
        int enemy_x = rand() % col_size;

        if (map[enemy_y][enemy_x] == 1 || map[enemy_y][enemy_x] == 2) continue;
        map[enemy_y][enemy_x] = 3;
        cnt++;
        if (cnt == monster_cnt) break;
    }

    while (true) {
        int potal_y = rand() % row_size;
        int potal_x = rand() % col_size;

        if (map[potal_y][potal_x] != 0) continue;
        map[potal_y][potal_x] = 4; break;
    }
}

void start_game(Character& player) {
    char ch;
    int row_size = 11, col_size = 31, monster_size = 3;

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
                    if (map[r][c + 1] == 1) break;
                    c++;
                    break;
                case UP:
                    if (map[r - 1][c] == 1) break;
                    r--;
                    break;
                case DOWN:
                    if (map[r + 1][c] == 1) break;
                    r++;
                    break;
                }

                if (map[r][c] == 3) { //몬스터 발견
                    system("cls");
                    monster_event(player);
                    if (end_point == 1) return;

                    system("cls");
                    map[r][c] = 0;
                    PlaySound(L"file_example_WAV_1MG.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    printMap(row_size, col_size, player);
                }
                else if (map[r][c] == 4) { //다음 라운드
                    system("cls");
                    monster_flag += 1;
                    if (row_size == 31 && col_size == 51) {

                        dr->DrawFinish();
                        break;
                    }
                    row_size += 10; col_size += 10, monster_size += 3; //맵크기 변환, 몬스터 갯수 증가
                    if (monster_flag == 1) { dr->DrawStageLevel_02(); }
                    else if (monster_flag == 2) { dr->DrawStageLevel_03(); }

                    dr->DrawMap(map, check, row_size, col_size);
                    insert_map_event(monster_size, row_size, col_size);
                    printMap(row_size, col_size, player);
                }

                cout << "  ";
                gotoxy(r, c);
                cout << "★";
                gotoxy(r, c);
            }
        }
    }
}

int main()
{
    PlaySound(L"file_example_WAV_1MG.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
    //_getch();
    system("mode con:cols=110 lines=35");
    srand(time(NULL));
    dr->DrawMainScreen();
    string input; cin >> input;
    system("cls");
    
    dr->DrawStageLevel_01();
    Sleep(2000);
    system("cls");
    Character player(20, 1);
    int row_size = 11, col_size = 31, monster_size = 3;
    
    dr->DrawMap(map, check, row_size, col_size); //맵 크기 조절하는구간
    
    
    insert_map_event(monster_size, row_size, col_size);
    
    printMap(row_size, col_size, player);
    

    gotoxy(r, c);

    start_game(player);


}
