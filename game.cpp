#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void print_maze();
void print_Player();
void erase_Player();
void print_Enemy();
void erase_Enemy();
void print_enemy2();
void erase_enemy2();
void print_enemy3();
void erase_enemy3();
void move_playerLeft();
void move_playerRight();
void move_playerdown();
void move_playerUp();
void move_enemy();
void move_enemy2();
void move_enemy3();
void swapDirection_Enemy();

int pX=50,pY=28;
float eX=2,eY=1, EX=60, EY=2, EX3=118,EY3=2;

main()
{
    system("cls");
    print_maze();
    print_Enemy();
    print_Player();
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            move_playerLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            move_playerRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            move_playerUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            move_playerdown();
        }
        move_enemy();
        move_enemy2();
        move_enemy3();
        Sleep(100);
    }
}

void gotoxy(int x, int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void print_maze()
{
    std::cout<<"************************************************************************************************************************************************************"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"**                                                                                                                                                        **"<<endl;
    std::cout<<"************************************************************************************************************************************************************"<<endl;

}

char getCharAtxy(short int x, short int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    DWORD charsRead;
    char ch;
    ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), & ch, 1, coord, &charsRead);
    return ch;
}

void print_Player()
{
    gotoxy(pX,pY);
    cout<<"                    ___                      "<<endl;
    gotoxy(pX,pY+1);
    cout<<"                   /   \\                    "<<endl;
    gotoxy(pX,pY+2);
    cout<<"      ____________|     |____________        "<<endl;
    gotoxy(pX,pY+3);
    cout<<"     /            |     |            \\      "<<endl;
    gotoxy(pX,pY+4);
    cout<<"     \\____________|     |____________/      "<<endl;
    gotoxy(pX,pY+5);
    cout<<"                   \\   /                    "<<endl;
    gotoxy(pX,pY+6);
    cout<<"                    \\ /                     "<<endl;
    gotoxy(pX,pY+7);
    cout<<"                    | |                      "<<endl;
    gotoxy(pX,pY+8);
    cout<<"                   /   \\                    "<<endl; 
    gotoxy(pX,pY+9);
    cout<<"                  /_| |_\\                   "<<endl; 
}

void erase_Player()
{
    gotoxy(pX,pY);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+1);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+2);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+3);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+4);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+5);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+6);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+7);
    cout<<"                                             "<<endl;
    gotoxy(pX,pY+8);
    cout<<"                                             "<<endl; 
    gotoxy(pX,pY+9);
    cout<<"                                             "<<endl;     
}

void print_Enemy()
{  
    gotoxy(eX,eY);
    cout<<"                   \\_/           "<<endl;
    gotoxy(eX,eY+1);
    cout<<"                   / \\          "<<endl;
    gotoxy(eX,eY+2);
    cout<<"              ____|   |____      "<<endl;
    gotoxy(eX,eY+3);
    cout<<"            /_____|   |_____\\   "<<endl;
    gotoxy(eX,eY+4);
    cout<<"                   \\_/          "<<endl;   
}

void erase_Enemy()
{
    gotoxy(eX,eY);
    cout<<"                                   "<<endl;
    gotoxy(eX,eY+1);
    cout<<"                                   "<<endl;
    gotoxy(eX,eY+2);
    cout<<"                                   "<<endl;
    gotoxy(eX,eY+3);
    cout<<"                                   "<<endl;
    gotoxy(eX,eY+4);
    cout<<"                                   "<<endl;
}

void print_enemy2()
{
    gotoxy(EX,EY);
    cout<<"        __|__      "<<endl;
    gotoxy(EX,EY+1);
    cout<<"     --o--o--o--   "<<endl;
    gotoxy(EX,EY+2);
    cout<<"         \\  \\    "<<endl;
    gotoxy(EX,EY+3);
    cout<<"          \\__\\    "<<endl;
}

void erase_enemy2()
{
    gotoxy(EX,EY);
    cout<<"                   "<<endl;
    gotoxy(EX,EY+1);
    cout<<"                   "<<endl;
    gotoxy(EX,EY+2);
    cout<<"                   "<<endl;
    gotoxy(EX,EY+3);
    cout<<"                   "<<endl;
}

void print_enemy3()
{
    gotoxy(EX3,EY3);
    cout<<"   ______ "<<endl;
    gotoxy(EX3,EY3+1);
    cout<<"  |  __  |"<<endl;
    gotoxy(EX3,EY3+2);
    cout<<"  | |__| |"<<endl;
    gotoxy(EX3,EY3+3);
    cout<<"    |  |  "<<endl;
    gotoxy(EX3,EY3+4);
    cout<<"    /--\\ "<<endl;
}

void erase_enemy3()
{
    gotoxy(EX3,EY3);
    cout<<"          "<<endl;
    gotoxy(EX3,EY3+1);
    cout<<"          "<<endl;
    gotoxy(EX3,EY3+2);
    cout<<"          "<<endl;
    gotoxy(EX3,EY3+3);
    cout<<"          "<<endl;
    gotoxy(EX3,EY3+4);
    cout<<"          "<<endl;
}

void move_playerLeft()
{
    if (getCharAtxy(pX-1,pY)==' ')
    {
        erase_Player();
        pX=pX-1;
        print_Player();
    }
  
}

void move_playerRight()
{
   if (pX + 24 < 130 && getCharAtxy(pX+24,pY)==' ')
   {
     erase_Player();
     pX=pX+1;
     print_Player();
   }
}

void move_playerUp()
{
    if (pY>=2 && getCharAtxy(pX,pY)==' ')
    {
        erase_Player();
        pY=pY-1;
        print_Player();
    }
}

void move_playerdown()
{
    if(pY<=26 && getCharAtxy(pX,pY+9)==' ')
    {
        erase_Player();
        pY=pY+1;
        print_Player();
    }
}

void move_enemy()
{
    erase_Enemy();
    eX=eX+1;
    if(eX>=119)
    {
        eX=2;
    }
    print_Enemy();
}

void move_enemy2()
{
    erase_enemy2();
    EY=EY+0.7;
    if(EY>=20)
    {
        EY=2;
        EX=60;
    }
    print_enemy2();
}

void move_enemy3()
{
    erase_enemy3();
    EX3 -= 1.5;  
    EY3 += 0.7;  
    if (EX3 <= 3)
    {
        EX3 = 119;
    }

    if (EY3 >= 23)
    {
        EY3 = 2; 
    }
    print_enemy3();
}

