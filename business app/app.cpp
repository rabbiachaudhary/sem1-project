#include<iostream>
#include<conio.h>
using namespace std;
void header();
int signup_options();
void signup_user();
void signin();
void admin();
void program_manager();
void digital_marketing();
void proffesional();
void event_manager();
void customer();

main()
{   
    int main_choice;
    while(true)
       {
          system("cls");
          header();
          main_choice=signup_options();
          if (main_choice==1)
          {
            signup_user();
          }  

          else if (main_choice==2)
          {
            signin();
          }
          else if(main_choice==3)
          {
            break;
          }
       }
}
   


void header()
{   
    system("cls");
    cout<<"==========================================================================================================================================================="<<endl; 
    cout<<"   ###### ##   ## ###### ####### #####  ######    ###   ###### ####### #####         ##   ## ####### ##      ##      ##   ## #######  #####   #####  "<<endl;
    cout<<"     ##   ###  ##   ##   ##     ##   ## ##   ##  ## ##    ##   ##      ##  ##        ##   ## ##      ##      ##      ###  ## ##      ##   ## ##   ##  "<<endl;
    cout<<"     ##   #### ##   ##   ##     ##      ##   ## ##   ##   ##   ##      ##   ##       ##   ## ##      ##      ##      #### ## ##      ##      ##       "<<endl;
    cout<<"     ##   ## ####   ##   #####  ##  ### ##   ## ##   ##   ##   #####   ##   ##       ## # ## #####   ##      ##      ## #### #####    #####   #####   "<<endl;
    cout<<"     ##   ##  ###   ##   ##     ##   ## ######  #######   ##   ##      ##   ##       ####### ##      ##      ##      ##  ### ##           ##      ##  "<<endl;
    cout<<"     ##   ##   ##   ##   ##     ##   ## ##  ##  ##   ##   ##   ##      ##  ##        ### ### ##      ##      ##      ##   ## ##      ##   ## ##   ##  "<<endl;
    cout<<"   ###### ##   ##   ##   ####### #####  ##   ## ##   ##   ##   ####### #####         ##   ## ####### ####### ####### ##   ## #######  #####   #####   "<<endl;
    cout<<"                                                                                                                                                                                                            "<<endl;
    cout<<"      ##   ##   ###   ##   ##   ###    #####  ####### ##   ## ####### ##   ## ######         #####   ##   ##   #####    ######  #######  ##   ##      "<<endl;
    cout<<"      ### ###  ## ##  ###  ##  ## ##  ##   ## ##      ### ### ##      ###  ##   ##          ##   ##  ##   ##  ##   ##     ##    ##       ### ###      "<<endl;
    cout<<"      ####### ##   ## #### ## ##   ## ##      ##      ####### ##      #### ##   ##          ##       ##   ##  ##          ##    ##       #######      "<<endl;
    cout<<"      ## # ## ##   ## ## #### ##   ## ##  ### #####   ## # ## #####   ## ####   ##           #####    #####    #####      ##    #####    ## # ##      "<<endl;
    cout<<"      ##   ## ####### ##  ### ####### ##   ## ##      ##   ## ##      ##  ###   ##               ##    ###         ##     ##    ##       ##   ##      "<<endl;
    cout<<"      ##   ## ##   ## ##   ## ##   ## ##   ## ##      ##   ## ##      ##   ##   ##          ##   ##    ###    ##   ##     ##    ##       ##   ##      "<<endl;
    cout<<"      ##   ## ##   ## ##   ## ##   ##  #####  ####### ##   ## ####### ##   ##   ##           #####     ###     #####      ##    #######  ##   ##      "<<endl;
    cout<<"==========================================================================================================================================================="<<endl; 
} 

int signup_options()
{
    int option;
    cout<<"Select your option"<<endl<<endl;
    cout<<"1. Signup"<<endl;
    cout<<"2. Signin"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter Option: ";
    cin>>option;
    return option;
}

void admin()
{
    system("cls");
    cout<<"Welcome Admin.."<<endl<<endl;
    cout << "1. Input Patients" << endl;
    cout << "2. Display Patients" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
    int option;
    cin>>option;
    cout<<"Click on any key to return";
    getch();
    main();
}
void program_manager()
{
    system("cls");
    cout<<"Welcome Programs Manager.."<<endl<<endl;
    cout<<"Click on any key to return";
    getch();
    main();    
}
void proffesional()
{
    system("cls");
    cout<<"Welcome Proffesionals.."<<endl<<endl;
    cout<<"Click on any key to return";
    getch();   
    main();
}
void event_manager()
{
    system("cls");
    cout<<"Welcome Events Manager.."<<endl<<endl;
    cout<<"Click on any key to return";
    getch();
    main();
}
void customer()
{
    system("cls");
    cout<<"Welcome Customer.."<<endl<<endl;
    cout<<"Click on any key to return";
    getch();
    main();
}
void digital_marketing()
{
    system("cls");
    cout<<"Welcome Digital marketing Manager.."<<endl;
    cout<<"Click on any key to return"<<endl;
    getch();
    main();
}