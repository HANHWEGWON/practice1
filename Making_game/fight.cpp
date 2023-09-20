#include <iostream>
#include "Character.h"
#include "Knife.h"
#include "Gun.h"
#include "Hand.h"
#include<windows.h>
#include "Draw.h"
#include <mmsystem.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")

int main()
{
    PlaySound(L"file_example_WAV_1MG.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
    //_getch();
    system("mode con:cols=75 lines=15");
    Draw* dr = new Draw();
    dr->DrawMainScreen();
    int input; cin >> input;
    system("cls");
    
   

    Character player(20, 1);
    Character monster(30, 1);
    monster.setWeapon(new Hand());
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
        cin >> check;
        if (check == 1) {
            cout << "player의 공격->"; player.attack_character(monster, player.getWeapon(), 0);
        }
        else if (check == 2) {
            cout << "player의 공격->"; player.attack_character(monster, player.getWeapon(), 1);
        }

        if (player.getWeapon()[0]->get_attack_count() == 0) {
            player.changeWeapon(new Hand(), 0);
        }
        if(player.getWeapon()[1]->get_attack_count() == 0){
            player.changeWeapon(new Hand(), 1);
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
