#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
//functions
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void setColor(int textColor, int bgColor);
void hideCursor();
//header function & main menu
void header();
int menu();
void instructions();  //instructions
void print_maze();  //maze
void scoreboard(); //scoreboard
//player movements
void print_Player();
void erase_Player();
void move_playerLeft();
void move_playerRight();
//player shooting
void moveBulletPlayer() ;
void shootBullet();
//enemies movements
void print_Enemy();  //enemy 1
void erase_Enemy();
void move_enemy();
void print_enemy2();  //enemy 2
void erase_enemy2();
void move_enemy2();
void print_enemy3();  //enemy 3
void erase_enemy3();
void move_enemy3();
// Bonus pills
void movePill();
void printPill();
void erasePill();
//Enemies life check
bool CheckEnemyLife1();
bool CheckEnemyLife2();
bool CheckEnemyLife3();
// enemies shooting
void enemy1_Shoot();  //enemy 1
void moveEnemy1_Bullets();
void enemy2_Shoot();  //enemy 2
void moveEnemy2_Bullets();
void enemy3_Shoot();  //enemy 3
void moveEnemy3_Bullets();
// game results
void lose();
void win();
//variables
int score=0; //score
float pX=45 ,pY=28; //player coordinates
float eX=30,eY=4, EX=10, EY=10, EX3=95, EY3=10;  // enemies coordinates
bool direct1=true , direct2=true , direct3=true ;  // enemies direction variables
// player shooting variables
float bulletX[1000];  
float bulletY[1000];  
bool isBulletActive[1000];  
//health of characters
float Playerh=900;  //player health
int Enemy1h=90, Enemy2h=90, Enemy3h=90;  // enemies health
//bonus pills
int pillX = 2 + rand() % 114;  
int pillY= 4;
//enemies shooting 
const int max_bullets=30;
float enemy1_BulletX[max_bullets],enemy1_BulletY[max_bullets];  // enemy 1
bool enemy1_BulletActive[max_bullets];
float enemy2_BulletX[max_bullets],enemy2_BulletY[max_bullets];  //enemy 2
bool enemy2_BulletActive[max_bullets];
float enemy3_BulletX[max_bullets],enemy3_BulletY[max_bullets];  //enemy 3
bool enemy3_BulletActive[max_bullets];
main()
{
    system("cls");
    header();
    int x=menu();
    if(x==1)
    {
        hideCursor();
        system("cls");
        print_maze();
        print_Enemy();
        print_Player();
        for (int i = 0; i < max_bullets; i++) 
        {
            enemy1_BulletActive[i] = false;
            enemy2_BulletActive[i] = false;
            enemy3_BulletActive[i] = false;
        }
        while (true)
        {
            if(Enemy1h>0)   // enemy shoot
            {
                if(rand() % 12 == 0 )
                {
                    enemy1_Shoot();
                }
                moveEnemy1_Bullets();
            }
            if(Enemy2h>0)
            {
                if(rand() % 7 == 0 )
                {
                    enemy2_Shoot();
                }
                moveEnemy2_Bullets();
            }
            if(Enemy3h>0)
            {
                if(rand() % 8 == 0 )
                {
                    enemy3_Shoot();
                }
                moveEnemy3_Bullets();
            }
            if (GetAsyncKeyState(VK_LEFT))  // player movements
            {
                move_playerLeft();
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                move_playerRight();
            }
            if(GetAsyncKeyState(VK_SPACE))   // player bulletsss
            {
                shootBullet();
            }
            moveBulletPlayer();
            if(CheckEnemyLife1())  //enemies movement
            {
                move_enemy();
            }
            else
            {
                erase_Enemy();
            }
            if(CheckEnemyLife2())
            {
                move_enemy2();
            }
            else
            {
                erase_enemy2();
            }
            if(CheckEnemyLife3())
            {

                move_enemy3();
            }
            else
            {
                erase_enemy3();
            }
            movePill();  //bonusa pills            
            if(Enemy1h==0 && Enemy2h==0 && Enemy3h==0)
            {
                win();
                break;
            }
            if(Playerh==0)
            {
                lose();
                break;
            }
            Sleep(50);
            scoreboard();
        }
    }
    if(x==2)
    {
        system("cls");
        instructions();
        gotoxy(35,22);
        setColor(8,0);
        cout<<"press any key to continue";
        getch();
        main();
    }
    if (x==3)
    {
        return 0;
    }
}
//functions
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100; // Cursor size
    info.bVisible = FALSE; // Hide cursor
    SetConsoleCursorInfo(consoleHandle, &info);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void setColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
//header function & main menu
int menu()
{
    setColor(6,0);
    gotoxy(60,25);
    cout<<"1. play game"<<endl;
    gotoxy(60,26);
    cout<<"2. view instructions"<<endl;
    gotoxy(60,27);
    cout<<"3. exit game"<<endl;
    int choice;
    gotoxy(60,28);
    cout<<"enter your option..";
    cin>>choice;
    return choice;
    setColor(15,0);
}
void header()
{
    setColor(2,0);
    gotoxy(20,6);
    cout<<"  /                                       ###                    /        ###                                  "<<endl;
    gotoxy(20,7);
    cout<<"#/                                         ###                 #/          ###      #                          "<<endl;
    gotoxy(20,8);
    cout<<"##                        #         #       ##                 ##           ##     ###        #                "<<endl;
    gotoxy(20,9);
    cout<<"##                       ##        ##       ##                 ##           ##      #        ##                "<<endl;
    gotoxy(20,10);
    cout<<"##                       ##        ##       ##                 ##           ##               ##                "<<endl;
    gotoxy(20,11);
    cout<<"## /###       /###     ########  ########   ##       /##       ## /###      ##    ###      ########   ######   "<<endl;
    gotoxy(20,12);
    cout<<"##/ ###  /   / ###  / ########  ########    ##      / ###      ##/ ###  /   ##     ###    ########   /#######  "<<endl;
    gotoxy(20,13);
    cout<<"##   ###/   /   ###/     ##        ##       ##     /   ###     ##   ###/    ##      ##       ##     /      ##  "<<endl;
    gotoxy(20,14);
    cout<<"##    ##   ##    ##      ##        ##       ##    ##    ###    ##    ##     ##      ##       ##            /   "<<endl;
    gotoxy(20,15);
    cout<<"##    ##   ##    ##      ##        ##       ##    ########     ##    ##     ##      ##       ##           /    "<<endl;
    gotoxy(20,16);
    cout<<"##    ##   ##    ##      ##        ##       ##    #######      ##    ##     ##      ##       ##          ###   "<<endl;
    gotoxy(20,17);
    cout<<"##    ##   ##    ##      ##        ##       ##    ##           ##    ##     ##      ##       ##           ###  "<<endl;
    gotoxy(20,18);
    cout<<"##    /#   ##    /#      ##        ##       ##    ####    /    ##    /#     ##      ##       ##            ### "<<endl;
    gotoxy(20,19);
    cout<<" ####/      ####/ ##     ##        ##       ### /  ######/      ####/       ### /   ### /    ##             ## "<<endl;
    gotoxy(20,20);
    cout<<"  ###        ###   ##     ##        ##       ##/    #####        ###         ##/     ##/      ##            ## "<<endl;
    gotoxy(20,21);
    cout<<"                                                                                                            /  "<<endl;
    gotoxy(20,22);
    cout<<"                                                                                                           /   "<<endl;
    gotoxy(20,23);
    cout<<"                                                                                                          /    "<<endl;
    gotoxy(20,24);
    cout<<"                                                                                                         /     "<<endl;
    gotoxy(20,25);
    setColor(15,0);
}
void print_maze()
{
    setColor(2,0);
    gotoxy(0,3);
    cout<<"******************************************************************************************************************************"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"**                                                                                                                          **"<<endl;
    cout<<"******************************************************************************************************************************"<<endl;
    setColor(15,0);
}
void scoreboard()
{
    setColor(4,0);
    gotoxy(132,15);
    cout<<"SCORE: "<<"          ";
    gotoxy(132,15);
    cout<<"SCORE: "<<score;
    gotoxy(132,17);
    cout<<"PLAYER HEALTH: "<<Playerh;
    gotoxy(132,19);
    cout<<"ENEMY 1 HEALTH: "<<Enemy1h;
    gotoxy(132,21);
    cout<<"ENEMY 2 HEALTH: "<<Enemy2h;
    gotoxy(132,23);
    cout<<"ENEMY 3 HEALTH: "<<Enemy3h;
    setColor(15,0);
}
void instructions()
{
    setColor(2,0);
    gotoxy(65, 10);
    cout<<"INSTRUCTIONS"<<endl;
    setColor(6,0);
    gotoxy(35,12);
    cout<<"1) Use Arrow Keys to move left and right."<<endl;
    Sleep(500);
    gotoxy(35,13);
    cout<<"2) Press Space Bar to shoot bullets. Shoot the enemies to destroy them."<<endl;
    Sleep(500);
    gotoxy(35,14);
    cout<<"3) Avoid enemy bullets. If you get hit, your health will decrease."<<endl;
    Sleep(500);
    gotoxy(35,15);
    cout<<"4) Collect pills (*) to increase your score ."<<endl;
    Sleep(500);
    gotoxy(35,16);
    cout<<"5) Your score will increase by collecting pills and decreasing by getting hit by enemy bullets."<<endl;
    Sleep(500);
    gotoxy(67,20);
    setColor(2,0);
    cout<<"GOOD LUCK"<<endl;
    Sleep(1000);
}
//player movements
void print_Player()
{
    setColor(6,0);
    gotoxy(pX,pY);
    cout<<"             ___              "<<endl;
    gotoxy(pX,pY+1);
    cout<<"            /   \\            "<<endl;
    gotoxy(pX,pY+2);
    cout<<" __________|     |__________  "<<endl;
    gotoxy(pX,pY+3);
    cout<<"/          |     |          \\"<<endl;
    gotoxy(pX,pY+4);
    cout<<"\\__________|     |__________/"<<endl;
    gotoxy(pX,pY+5);
    cout<<"            \\   /            "<<endl;
    gotoxy(pX,pY+6);
    cout<<"             \\ /             "<<endl;
    gotoxy(pX,pY+7);
    cout<<"             | |              "<<endl;
    gotoxy(pX,pY+8);
    cout<<"            /   \\            "<<endl; 
    gotoxy(pX,pY+9);
    cout<<"           /_| |_\\           "<<endl; 
    setColor(15,0);
}

void erase_Player()
{
    gotoxy(pX,pY);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+1);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+2);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+3);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+4);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+5);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+6);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+7);
    cout<<"                              "<<endl;
    gotoxy(pX,pY+8);
    cout<<"                              "<<endl; 
    gotoxy(pX,pY+9);
    cout<<"                              "<<endl;     
}
void move_playerLeft()
{
    if (getCharAtxy(pX-2,pY)==' ')
    {
        erase_Player();
        pX=pX-2;     // move player left
        print_Player();
    }
  
}
void move_playerRight()
{
   if (pX + 24 < 116 && getCharAtxy(pX+24,pY)==' ')
   {
     erase_Player(); 
     pX=pX+2;         //move player right
     print_Player();
   }
}
//player shooting
void shootBullet()
{
    for(int i=0; i<1000; i++)
    {
        if(!isBulletActive[i])    //activate bullet
        {
            bulletX[i]=pX+14;
            bulletY[i]=pY;
            isBulletActive[i]=true;
            break;
        }
    }
}
void moveBulletPlayer() 
{
    for(int i = 0; i < 1000; i++)
    {
        if(isBulletActive[i])
        {
            gotoxy(bulletX[i], bulletY[i]);
            cout << " ";
            bulletY[i] -= 1;
            if (bulletY[i] < 5)   // bullet to remain inside maze
            {
                isBulletActive[i] = false;
                continue;
            }
            if (Enemy1h>0 && bulletX[i] >= eX && bulletX[i] <= eX + 24 && bulletY[i] >= eY && bulletY[i] <= eY + 4)  //collision detection with enemy 1
            {
                score+=200;
                Enemy1h -= 10; 
                isBulletActive[i] = false;
            }
            else if (Enemy2h>0 && bulletX[i] >= EX && bulletX[i] <= EX + 24 && bulletY[i] >= EY && bulletY[i] <= EY + 4)  //collision detection with enemy 2
            {
                score+=200;
                Enemy2h -= 10; 
                isBulletActive[i] = false; 
            }
            else if (Enemy3h>0 && bulletX[i] >= EX3 && bulletX[i] <= EX3 + 24 && bulletY[i] >= EY3 && bulletY[i] <= EY3 + 4)   //collision detection with enemy 3
            {
                score+=200;
                Enemy3h -= 10; 
                isBulletActive[i] = false; 
            }

            if (isBulletActive[i])  // if bullet active then print it
            {
                setColor(6,0);
                gotoxy(bulletX[i], bulletY[i]);
                cout << "^";
                setColor(7,0);
            }
        }
    }
}
//enemies movement
void print_Enemy()
{  
    setColor(13,0);
    gotoxy(eX,eY);
    cout<<"         \\_/         "<<endl;
    gotoxy(eX,eY+1);
    cout<<"         / \\        "<<endl;
    gotoxy(eX,eY+2);
    cout<<"    ____|   |____    "<<endl;
    gotoxy(eX,eY+3);
    cout<<"  /_____|   |_____\\ "<<endl;
    gotoxy(eX,eY+4);
    cout<<"         \\_/        "<<endl;   
    setColor(15,0);
}

void erase_Enemy()
{
    gotoxy(eX,eY);
    cout<<"                    "<<endl;
    gotoxy(eX,eY+1);
    cout<<"                    "<<endl;
    gotoxy(eX,eY+2);
    cout<<"                    "<<endl;
    gotoxy(eX,eY+3);
    cout<<"                    "<<endl;
    gotoxy(eX,eY+4);
    cout<<"                    "<<endl;
}

void print_enemy2()
{
    setColor(13,0);
    gotoxy(EX,EY);
    cout<<"   __|__    "<<endl;
    gotoxy(EX,EY+1);
    cout<<"--o--o--o--"<<endl;
    gotoxy(EX,EY+2);
    cout<<"    \\  \\ "<<endl;
    gotoxy(EX,EY+3);
    cout<<"     \\__\\ "<<endl;
    
    setColor(15,0);
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
    setColor(13,0);
    gotoxy(EX3,EY3);
    cout<<" ______ "<<endl;
    gotoxy(EX3,EY3+1);
    cout<<"|  __  |"<<endl;
    gotoxy(EX3,EY3+2);
    cout<<"| |__| |"<<endl;
    gotoxy(EX3,EY3+3);
    cout<<"  |  |  "<<endl;
    gotoxy(EX3,EY3+4);
    cout<<"  /--\\ "<<endl;
    setColor(7,0);
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

void move_enemy()
{
    if(direct1)   
    {
        erase_Enemy();
        eX=eX+1;
        if(eX>=67)
        {
            direct1=false;
        }
        print_Enemy();
    }
    else   //reverse direction
    {
        erase_Enemy();
        eX=eX-1;
        if(eX<=30)
        {
            direct1=true;
        }
        print_Enemy();
    }
}


void move_enemy2()
{
    if(direct2)
    {
        erase_enemy2();
        EX += 1.3;
        EY += 1;
        if(EY>=23)
        {
            direct2=false;
        }
        print_enemy2();
    }
    else   //reverse direction
    {
        erase_enemy2();
        EX -= 1.3;
        EY -= 1;
        if(EY<=10)
        {
            direct2=true;
        }
        print_enemy2();
    }
}

void move_enemy3()
{
    if (direct3)
    {
        erase_enemy3();
        EX3 -= 1.3;  
        EY3 += 1;  
        if (EY3 >= 23)
        {
            direct3=false;
        }
        print_enemy3();
    }
    else   //reverse direction
    {
        erase_enemy3();
        EX3 += 1.3;
        EY3 -= 1;
        if (EY3 <= 10)
        {
            direct3=true;
        }
        print_enemy3();
    }
}
//enemies life check
bool CheckEnemyLife1()
{
    if (Enemy1h<=0)
    {
        return false;
    }
    return true;
}
bool CheckEnemyLife2()
{
    if (Enemy2h<=0)
    {
        return false;
    }
    return true;
}
bool CheckEnemyLife3()
{
    if (Enemy3h<=0)
    {
        return false;
    }
    return true;
}
//Bonus pills
void printPill()
{
    setColor(4,0);
    gotoxy(pillX,pillY);
    cout<<"*";
    setColor(7,0);
}

void erasePill()
{
    gotoxy(pillX,pillY);
    cout<<" ";
}

void movePill()
{
    if(pillY<35)  //pill to remain in maze
    {
        printPill();
        Sleep(30);
        erasePill();
        pillY++;
    }
    else
    {
        pillX = 2 + rand() % 114;
        pillY = 4;                
    }
    if ((pillX >= pX && pillX <= pX + 25) && (pillY >= pY && pillY <= pY + 9))
    {
        score += 10; 
        pillX = 2 + rand() % 114; 
        pillY = 4;                
    }
}
//enemy 1 shooting
void enemy1_Shoot()
{
    for ( int i = 0 ; i < max_bullets ; i++ ) 
    {
        if ( !enemy1_BulletActive[i])
        {
            enemy1_BulletX[i]=eX+11;
            enemy1_BulletY[i]=eY+5;
            enemy1_BulletActive[i]=true;  //activate bullet
            break;
        }
    }
}
void moveEnemy1_Bullets()
{
    for ( int i = 0 ; i<max_bullets ; i++ )
    {
        if( enemy1_BulletActive[i])
        {
            gotoxy(enemy1_BulletX[i],enemy1_BulletY[i]);
            cout<<" ";
            enemy1_BulletY[i]++;
            if(enemy1_BulletY[i] >= 35 || (enemy1_BulletX[i]>= pX && enemy1_BulletX[i]<=pX+25 && enemy1_BulletY[i] >= pY && enemy1_BulletY[i]<=pY+9)) //collision detection with player
            {
                if(enemy1_BulletX[i]>= pX && enemy1_BulletX[i]<=pX+25 && enemy1_BulletY[i] >= pY && enemy1_BulletY[i]<=pY+9)
                {
                    Playerh -= 100;
                    score -= 20;
                }
                enemy1_BulletActive[i]=false;
            }
            if(enemy1_BulletActive[i])
            {
                setColor(8,0);
                gotoxy(enemy1_BulletX[i],enemy1_BulletY[i]);
                cout<<"|";
                setColor(7,0);
            }
        }
    }
}
//enemy2 shooting
void enemy2_Shoot()
{
    for ( int i = 0 ; i < max_bullets ; i++ )
    {
        if ( !enemy2_BulletActive[i])   //activate bullet
        {
            enemy2_BulletX[i]=EX+7;
            enemy2_BulletY[i]=EY+4;
            enemy2_BulletActive[i]=true;
            break;
        }
    }
}
void moveEnemy2_Bullets()
{
    for ( int i = 0 ; i<max_bullets ; i++ )
    {
        if( enemy2_BulletActive[i])
        {
            gotoxy(enemy2_BulletX[i],enemy2_BulletY[i]);
            cout<<" ";
            enemy2_BulletY[i]++;
            if(enemy2_BulletY[i] >= 35 || (enemy2_BulletX[i]>= pX && enemy2_BulletX[i]<=pX+25 && enemy2_BulletY[i] >= pY && enemy2_BulletY[i]<=pY+9))
            {
                if(enemy2_BulletX[i]>= pX && enemy2_BulletX[i]<=pX+25 && enemy2_BulletY[i] >= pY && enemy2_BulletY[i]<=pY+9)   //collision detection with player
                {
                    Playerh -= 100;
                    score -= 20;
                }
                enemy2_BulletActive[i]=false;
            }
            if(enemy2_BulletActive[i])
            {
                setColor(8,0);
                gotoxy(enemy2_BulletX[i],enemy2_BulletY[i]);
                cout<<"%";
                setColor(7,0);
            }
        }
    }
}

//enemy 3 shooting
void enemy3_Shoot()
{
    for ( int i = 0 ; i < max_bullets ; i++ )
    {
        if ( !enemy3_BulletActive[i])  //activate bullet
        {
            enemy3_BulletX[i]=EX3+2;
            enemy3_BulletY[i]=EY+5;
            enemy3_BulletActive[i]=true;
            break;
        }
    }
}
void moveEnemy3_Bullets()
{
    for ( int i = 0 ; i<max_bullets ; i++ )
    {
        if( enemy3_BulletActive[i])
        {
            gotoxy(enemy3_BulletX[i],enemy3_BulletY[i]);
            cout<<"  ";
            enemy3_BulletY[i]++;
            if(enemy3_BulletY[i] >= 35 || (enemy3_BulletX[i]>= pX && enemy3_BulletX[i]<=pX+25 && enemy3_BulletY[i] >= pY && enemy3_BulletY[i]<=pY+9)) //collision detection with player
            {
                if(enemy3_BulletX[i]>= pX && enemy3_BulletX[i]<=pX+25 && enemy3_BulletY[i] >= pY && enemy3_BulletY[i]<=pY+9)
                {
                    Playerh -= 100;
                    score -= 20;
                }
                enemy3_BulletActive[i]=false;
            }
            if(enemy3_BulletActive[i])
            {
                setColor(8,0);
                gotoxy(enemy3_BulletX[i],enemy3_BulletY[i]);
                cout<<"~~";
                setColor(7,0);
            }
        }
    }
}
//game results
void win()
{
    system("cls"); 
    setColor(2,0);
    gotoxy(50,16);
    cout<<" ><<   ><<   ><<    ><<  ><<    ><<     ><<<   ><<    ><< ><<  ";
    gotoxy(50,17);
    cout<<" ><< ><<  ><<  ><< ><<  ><<     ><<  <  ><< ><<  ><<  ><<  ><<";
    gotoxy(50,18);
    cout<<"   ><<<  ><<    ><<><<  ><<     ><< ><  ><<><<    ><< ><<  ><<";
    gotoxy(50,19);
    cout<<"    ><<   ><<  ><< ><<  ><<     >< >< ><><< ><<  ><<  ><<  ><<";
    gotoxy(50,20);
    cout<<"   ><<      ><<      ><<><<     ><<<    ><<<   ><<    ><<<  ><<";
    gotoxy(50,21);
    cout<<" ><<                                                       ";
    gotoxy(70,24);
    cout<<"Score: "<< score;
    setColor(7,0);
}
void lose()
{
    system("cls");
    setColor(12,0);
    gotoxy(50,16);
    cout<<"                               ><<                   ><<  ";
    gotoxy(50,17);
    cout<<"                               ><<                   ><<  ";
    gotoxy(50,18);
    cout<<"><<   ><<   ><<    ><<  ><<    ><<   ><<     ><<<< ><>< ><";
    gotoxy(50,19);
    cout<<" ><< ><<  ><<  ><< ><<  ><<    ><< ><<  ><< ><<      ><<  ";
    gotoxy(50,20);
    cout<<"   ><<<  ><<    ><<><<  ><<    ><<><<    ><<  ><<<   ><<  ";
    gotoxy(50,21);
    cout<<"    ><<   ><<  ><< ><<  ><<    ><< ><<  ><<     ><<  ><<  ";
    gotoxy(50,22);
    cout<<"   ><<      ><<      ><<><<   ><<<   ><<    ><< ><<   ><< ";
    gotoxy(50,23);
    cout<<" ><<                                                    ";
    gotoxy(70,25);
    cout<<"Score: "<< score;
    setColor(7,0);
    
}
