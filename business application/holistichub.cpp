#include<iostream>
#include<conio.h>
#include<windows.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//menus
void header();
void adminmode_Header();
int admin();
void programsManager_Header();
int programs_manager();
void customer_Header();
int customer();
//signin signup headers
void signup_Header();
void signin();
string signup_options();
//functionalities headers
void createNewUser_Header();  
void editacc_header();
void deleteAccounts_Header();
void viewAllUser_Header();
void viewFeedback_Header();
void viewPrograms_Header();
void addPrograms_Header();
void deleteProgram_Header();
void updateProgram_Header(string programs[][3], int &idxp, const int maxProgram);
void registerForProgram_Header();
void personalInfo_Header();
void provideFeedback_Header();
void resetPass_Header();
//functionalities
bool signup(string username[], string pass[], string role[], int &idx);
void displayUserAccounts(string username[], string pass[], string role[], int &idx);  
bool createNewUser(string username[], string pass[], string role[], int &idx);
bool EditAccounts(string edit_user,string username[], string pass[], string role[], int &idx);
void viewRegisteredCustomers(string registeredCustomers[][6],const int MAX_registered, int &idxr);
string deleteAccounts(string username[], string pass[], string role[], int &idx);
void ViewallUsers(string username[], string pass[], string role[], int &idx);
void viewFeedback(int &idxf, string feedback[][3], const int MAX_FEEDBACK);
void viewPrograms(string programs[][3], int &idxp, const int maxProgram);       
bool addPrograms(string programs[][3], int &idxp, const int maxProgram);
string deleteProgram(string programs[][3], int &idxp, const int maxProgram);
bool updateProgram(string program,string programs[][3], int &idxp, const int maxProgram);
bool registerForProgram(string username[], string pass[], string role[], int &idx,string programs[][3], int &idxp, const int maxProgram, int &idxc,string registeredCustomers[][6],const int MAX_registered, int &idxr);
void personalInfo(string customerInfo[][4],const int MAX_customerRecords, int &idxc);
void provideFeedback(int &idxf, string feedback[][3], const int MAX_FEEDBACK);
void displayProgram(string programs[][3], int &idxp, const int maxProgram);
bool resetPass(string username[], string pass[], string role[], int &idx);
//validations
bool isAplphabetOny(string x);
bool firstLetterCapital(string x);
bool isNumberOnly(string x);
bool isAlNum(string x);
bool isValidRole(string x);
int lenghtOfString(string x);
bool email_check(string email);
//file handling 
void readData(string username[], string pass[], string role[], int &idx);
void writeData(string username[], string pass[], string role[], int &idx);
string getField(string record, int field);
void writePrograms_ToFile(string programs[][3],const int maxProgram , int &idxp);
void readPrograms_FromFile(string programs[][3],const int maxProgram , int &idxp);
void setColor(int textColor, int bgColor);
void gotoxy(int x, int y);


main()
{
    //variables for sigin and signup
    string username[50];
    string pass[50];
    string role[50];
    int idx=0;
    //varaibles for programs manager
    int idxp;
    const int maxProgram=100;
    string programs[maxProgram][3]; // 0 name 1 description 2 duration
    //variabls for customer
    int idxc;
    const int MAX_customerRecords=100;
    string customerInfo[MAX_customerRecords][4]; // 0 name 1 age 2 gender 3 number 
    //registered users
    int idxr;
    const int MAX_registered=100;
    string registeredCustomers[MAX_registered][6]; // 0 program name, 1 user name , 2 age, 3 email, 4 phone , 5 gender
    //variables for feedback
    int idxf=0;
    const int MAX_FEEDBACK=100;
    string feedback[MAX_FEEDBACK][3]; //0 feedback, 1 username, 2 program name
    int currentMenu;
    string signin_username, signin_pass, signin_role;
    string edit_user;
    system("cls");
    readPrograms_FromFile(programs,maxProgram ,idxp);
    readData(username,pass,role,idx);
    currentMenu=0;
    while(true)
    { 
        if(currentMenu==0)
        {
            header();
            string option=signup_options();
            if (option=="1")
            {
                signup_Header();
                if (signup(username,pass,role,idx))
                {
                    writeData(username,pass,role,idx);
                    cout<<"                                                          signup successful"<<endl;
                }
                else
                {
                    cout<<"                                                          signup failed"<<endl;
                }
                cout<<"                                                          Click on any key to return..."<<endl;
                getch();
                idx++;
            }
            else if (option=="2")
            {
                signin();
                cout<<  "                                                          Enter username: ";
                cin>>signin_username;
                cout<<endl;
                cout<<  "                                                          Enter passcode: ";
                cin>>signin_pass;
                cout<<endl;
                cout<<  "                                                          Enter Role: ";
                cin>>signin_role;
                cout<<endl;
                bool flag;
                for (int i=0; i<idx; i++)
                {
                    if (signin_username==username[i] && signin_role==role[i] && signin_pass==pass[i])
                    {
                        cout<<"                                                          sign in successful"<<endl;
                        cout<<"                                                          spress any key to continue..";
                        getch();
                        flag=true;
                        if (signin_role=="Admin" || signin_role=="admin")
                        {
                            currentMenu=1;
                        }
                        if(signin_role=="Manager" || signin_role=="manager")
                        {
                            currentMenu=2;
                        }
                        if(signin_role=="Customer" || signin_role=="customer")
                        {
                            currentMenu=3;
                        }
                        break;
                    }
                }
                if (!flag)
                {
                    cout<<"                                                          You have entered incorrect information"<<endl;
                    cout<<"                                                          Press any key to conitnue..."<<endl;
                    getch();
                }
            }   
            else if(option=="3")
            {
                break;
            }
            else
            {
                cout<<"                                                             Incorrect option"<<endl;
                cout<<"                                                             Press any kry to continue.."<<endl;
                getch();
            }
        }
        else if(currentMenu==1)
        {
            adminmode_Header();
            int opt=admin();
            if(opt==1)
            {
                createNewUser_Header();
                if(createNewUser(username,pass,role,idx))
                {
                    writeData(username,pass,role,idx);
                    cout<<  "Account created successfully."<<endl;
                }
                else
                {
                    cout<<"This role doesnot exist"<<endl;
                }
                idx++;
                cout<<"press any key to continue..."<<endl;
                getch();
            }
            else if(opt==2)
            {
                editacc_header();
                displayUserAccounts(username,pass,role,idx);
                cout <<   "Enter the username to be edited: ";
                cin >> edit_user;
                if(EditAccounts(edit_user,username,pass,role,idx))
                {
                    cout<<"Account updated successfully"<<endl;
                }
                else
                {
                    cout<<"This user does not exist"<<endl;
                }
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==3)
            {
                deleteAccounts_Header();
                cout<<deleteAccounts(username,pass,role,idx)<<endl;
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==4)
            {
                viewAllUser_Header();
                ViewallUsers(username,pass,role,idx);
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==5)
            {
                viewPrograms_Header();
                viewPrograms(programs,idxp,maxProgram);
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==6)
            {
                deleteProgram_Header();
                cout<<deleteProgram(programs,idxp,maxProgram)<<endl;
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==7)
            {
                viewFeedback_Header();
                viewFeedback(idxf,feedback,MAX_FEEDBACK);
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==8)
            {
                viewRegisteredCustomers( registeredCustomers,MAX_registered, idxr);
                cout<<"Press any key to continue..."<<endl;
                getch();
            }
            else if(opt==9)
            {
                currentMenu=0;
            }
            else
            {
                cout<<  "Invalid option. Please try again."<<endl;
                cout<<  "press any key to continue..."<<endl;
                getch();
            }
        }
        else if(currentMenu==2)
        {
            programsManager_Header();
            int option=programs_manager();
            if (option==1)
            {
                viewPrograms_Header();
                viewPrograms(programs,idxp,maxProgram);
                cout<<  "Press any key to return..";
                getch();
            }
            else if(option==2)
            {
                addPrograms_Header();
                if(addPrograms(programs,idxp,maxProgram))
                {
                  cout<<"Program added successfully"<<endl;
                }
                else
                {
                  cout<<"This program already exists"<<endl;
                }
                cout<<  "Press any key to return..";
                getch();
            }
            else if (option==3)
            {
                deleteProgram_Header();
                cout<<deleteProgram(programs,idxp,maxProgram)<<endl;
                cout<<  "Press any key to return..";
                getch();
            }
            else if (option==4)
            {
                string program;
                updateProgram_Header(programs,idxp,maxProgram);
                cout<<"Enter the name of Program you want to update..."<<endl;
                cin>>program;
                if(updateProgram(program,programs,idxp,maxProgram))
                {
                    cout<<"Program updated successfully"<<endl;
                }
                else
                {
                    cout<<"Program not found"<<endl;
                }
            }
            else if(option==5)
            {
                resetPass_Header();
                if(resetPass(username,pass,role,idx))
                {
                    cout<<"Password reset successfully"<<endl;
                }
                else
                {
                    cout<<"Try again"<<endl;
                }
                cout<<"Press any key to continue...";
                getch();
            }
            else if(option==6)
            {
                currentMenu=0;
            }
            else
            {
              cout<<  "Invalid Option"<<endl;
              cout<<  "press any key to continue...";
              getch();
            }
        }
        else if(currentMenu=3)
        {
            customer_Header();
            int opt=customer();
            if (opt==1)
            {
                viewPrograms_Header();
                viewPrograms(programs,idxp,maxProgram);
                cout<<  "Press any key to return..";
                getch();
            }
            else if (opt==2)
            {
                registerForProgram_Header();
                if(registerForProgram(username,pass,role,idx,programs,idxp,maxProgram,idxc, registeredCustomers,MAX_registered, idxr))
                {
                    cout<<"Program registered successfully"<<endl;
                }
                else
                {
                    cout<<"program not found "<<endl;  
                }
                cout<<"Press any key to continue...";
                getch();
            }
            else if (opt==3)
            {
                personalInfo_Header();
                personalInfo(customerInfo, MAX_customerRecords, idxc);
                cout<<"Press any key to continue...";
                getch();
            }
            else if (opt==4)
            {
                provideFeedback_Header();
                displayProgram(programs,idxp,maxProgram);
                provideFeedback(idxf,feedback,MAX_FEEDBACK);
                cout<<"Press any key to continue...";
                getch();
            }
            else if (opt==5)
            {
                resetPass_Header();
                if(resetPass(username,pass,role,idx))
                {
                    cout<<"Password reset successfully"<<endl;
                }
                else
                {
                    cout<<"Try again"<<endl;
                }
                cout<<"Press any key to continue...";
                getch();
            }
            else if (opt==6)
            {
                currentMenu=0; 
            }
            else
            {
                cout <<   "Invalid option. Please try again."<< endl;
                getch();
            }
        }
    }
} 
   
// menus

void header()
{   
    system("cls");
    setColor(11,0);
    gotoxy( 20,12);
    cout << " __    __    ______    __       __       _______..___________. __    ______     __    __   __    __  .______    ";
    gotoxy( 20,13);
    cout << "|  |  |  |  /  __  \\  |  |     |  |     /       ||           ||  |  /      |   |  |  |  | |  |  |  | |   _  \\   ";
    gotoxy( 20,14);
    cout << "|  |__|  | |  |  |  | |  |     |  |    |   (----``---|  |----`|  | |  ,----'   |  |__|  | |  |  |  | |  |_)  |  ";
    gotoxy( 20,15);
    cout << "|   __   | |  |  |  | |  |     |  |     \\   \\        |  |     |  | |  |        |   __   | |  |  |  | |   _  <   ";
    gotoxy( 20,16);
    cout << "|  |  |  | |  `--'  | |  `----.|  | .----)   |       |  |     |  | |  `----.   |  |  |  | |  `--'  | |  |_)  |  ";
    gotoxy( 20,17);
    cout << "|__|  |__|  \\______/  |_______||__| |_______/        |__|     |__|  \\______|   |__|  |__|  \\______/  |______/   ";
    gotoxy( 20,18);
    cout << "                                                                                                                ";
    cout<<endl;
} 
void adminmode_Header()
{
    system("cls");
    setColor(11,0);
    gotoxy(0,7);
    cout << "                                            _        _             _          __  __                     \n";
    cout << "                                           / \\    __| | _ __ ___  (_) _ __   |  \\/  |  ___  _ __   _   _ \n";
    cout << "                                          / _ \\  / _` || '_ ` _ \\ | || '_ \\  | |\\/| | / _ \\| '_ \\ | | | |\n";
    cout << "                                         / ___ \\| (_| || | | | | || || | | | | |  | ||  __/| | | || |_| |\n";
    cout << "                                        /_/   \\_\\\\__,_||_| |_| |_||_||_| |_| |_|  |_| \\___||_| |_| \\__,_|\n \n \n";
    cout << "                                                                   \n";
    setColor(15, 0);
}
int admin()
{
    int option_admin;
    cout <<   "           1. Create new user accounts" << endl;
    cout <<   "           2. Edit user accounts" << endl;
    cout <<   "           3. Delete user accounts" << endl;
    cout <<   "           4. View all users"<< endl;
    cout <<   "           5. View wellness programs"<< endl;
    cout <<   "           6. Delete wellness programs"<< endl;
    cout <<   "           7. View participants' feedback"<< endl;
    cout<<    "           8. view Registered Customers"<<endl;
    cout <<   "           9. Exit"<< endl << endl; 
    cout<<    "           enter option..";
    cin>>option_admin; 
    return option_admin;    
}
void programsManager_Header()
{
    system("cls");
    setColor(11, 0);
    cout << "                                     __  __                                           __  __                      \n";
    cout << "                                    |  \\/  |  __ _  _ __    __ _   __ _   ___  _ __  |  \\/  |  ___  _ __   _   _ \n";
    cout << "                                    | |\\/| | / _` || '_ \\  / _` | / _` | / _ \\| '__| | |\\/| | / _ \\| '_ \\ | | | |\n";
    cout << "                                    | |  | || (_| || | | || (_| || (_| ||  __/| |    | |  | ||  __/| | | || |_| |\n";
    cout << "                                    |_|  |_| \\__,_||_| |_| \\__,_| \\__, | \\___||_|    |_|  |_| \\___||_| |_| \\__,_|\n";
    cout << "                                                                  |___/                                           \n \n \n";
    setColor(15, 0);
}
void customer_Header()
{
    system("cls");
    
    setColor(11, 0);
    cout << "   ____             _                                  __  __                      \n";
    cout << "  / ___|_   _  ___ | |_  ___   _ __ ___    ___  _ __  |  \\/  |  ___  _ __   _   _ \n";
    cout << " | |   | | | |/ __|| __|/ _ \\ | '_ ` _ \\  / _ \\| '__| | |\\/| | / _ \\| '_ \\ | | | |\n";
    cout << " | |___| |_| |\\__ \\| |_| (_) || | | | | ||  __/| |    | |  | ||  __/| | | || |_| |\n";
    cout << "  \\____|\\__,_||___/ \\__|\\___/ |_| |_| |_| \\___||_|    |_|  |_| \\___||_| |_| \\__,_|\n";
    cout << "                                                                                   \n \n \n";
    setColor(15, 0);
}


int programs_manager()
{
    cout<<  "            1. View Programs"<<endl;
    cout<<  "            2. Add Programs"<<endl;
    cout<<  "            3. Delete Programs"<<endl;
    cout<<  "            4. Update Program "<<endl;
    cout<<  "            5. Reset Passwords"<<endl;
    cout<<  "            6. Exit"<<endl;
    cout<<  "            Select Option.."<<endl;
    int option;
    cin>>option;
    return option;
}

int customer()
{
    int opt;
    cout<<  "           1. View Wellness Programs"<<endl;
    cout<<  "           2. Register for a Wellness Program"<<endl;
    cout<<  "           3. Enter Personal Information"<<endl;
    cout<<  "           4. Provide Feedback on a Wellness Program"<<endl;
    cout<<  "           5. Reset Password"<<endl;
    cout<<  "           6. Exit"<<endl;
    cout<<  "           Select an option to continue..."<<endl;
    cin>>opt;
    return opt;
}
//signup signin headers
void signup_Header()
{
    system("cls");
    setColor(11,0);
    gotoxy(0,10);
    cout << "                                                            ____   _                              \n";
    cout << "                                                           / ___| (_)  __ _  _ __   _   _  _ __  \n";
    cout << "                                                           \\___ \\ | | / _` || '_ \\ | | | || '_ \\ \n";
    cout << "                                                            ___) || || (_| || | | || |_| || |_) |\n";
    cout << "                                                           |____/ |_| \\__, ||_| |_| \\__,_|| .__/ \n";
    cout << "                                                                      |___/               |_|     \n \n \n ";
    setColor( 15,0);
}
void signin()
{
    system("cls");
    setColor(11,0);
    gotoxy(0,10);
    cout << "                                                            ____   _                _         \n";
    cout << "                                                           / ___| (_)  __ _  _ __  (_) _ __   \n";
    cout << "                                                           \\___ \\ | | / _` || '_ \\ | || '_ \\  \n";
    cout << "                                                            ___) || || (_| || | | || || | | | \n";
    cout << "                                                           |____/ |_| \\__, ||_| |_||_||_| |_| \n";
    cout << "                                                                      |___/                   \n \n \n ";
    setColor(15,0); 
}
string signup_options()
{
    string option;
    setColor(15,0);
    cout<<endl<<endl;
    cout<< "                                                             Select your option"<<endl<<endl;
    cout<<"                                                             1. Signup"<<endl;
    cout<<"                                                             2. Signin"<<endl;
    cout<<"                                                             3. Exit"<<endl<<endl;
    cout<<"                                                             Enter Option: ";
    cin>>option;
    return option;
}
//functionalities headers
void createNewUser_Header()
{
    system("cls");
    setColor(11,0);
    cout<<  "*******************************************************"<<endl;
    cout<<  "*                 NEW USER ACCOUNT                    *"<<endl;
    cout<<  "*******************************************************"<<endl<<endl;
    setColor(15,0);
}
void editacc_header()
{
    system("cls");
    setColor(11,0);
    cout<<  "***********************************************************"<<endl;
    cout<<  "*                   EDIT USER ACCOUNT                     *"<<endl;
    cout<<  "***********************************************************"<<endl<<endl;
    setColor(15,0);
}
void deleteAccounts_Header()
{
    system("cls");
    setColor(11, 0);
    cout << "*******************************************************" << endl;
    cout << "*                 DELETE USER ACCOUNT                 *" << endl;
    cout << "*******************************************************" << endl << endl;
    setColor(15, 0);
}
void viewAllUser_Header()
{
    system("cls");
    setColor(11, 0);
    cout << "*******************************************************" << endl;
    cout << "*                   VIEW ALL USERS                    *" << endl;
    cout << "*******************************************************" << endl << endl;
    setColor(15, 0);
}
void viewFeedback_Header()
{
    system("cls");
    setColor(11, 0);
    cout <<   "*******************************************************"<< endl;
    cout <<   "*                    VIEW FEEDBACKS                   *"<< endl;
    cout <<   "*******************************************************"<< endl << endl;
    setColor(15, 0);
}

void viewPrograms_Header()
{
    system("cls");
    setColor(11, 0);
    cout <<   "*******************************************************"<< endl;
    cout <<   "*                VIEW WELLNESS PROGRAMS               *"<< endl;
    cout <<   "*******************************************************"<< endl << endl;
    setColor(15, 0);
}
void addPrograms_Header()
{
    system("cls");
    setColor(11, 0);
    cout <<   "*******************************************************"<< endl;
    cout <<   "*                ADD WELLNESS PROGRAMS                *"<< endl;
    cout <<   "*******************************************************"<< endl << endl;
    setColor(15, 0);
}
void deleteProgram_Header()
{
    system("cls");
    setColor(11, 0);
    cout <<   "*******************************************************" << endl;
    cout <<   "*               DELETE WELLNESS PROGRAMS              *" << endl;
    cout <<   "*******************************************************" << endl << endl;
    setColor(15, 0);
}
void updateProgram_Header(string programs[][3], int &idxp, const int maxProgram)
{
    system("cls");
    setColor(11, 0);
    cout <<   "**********************************************************"<< endl;
    cout <<   "*                 UPDATE WELLNESS PROGRAMS                *"<< endl;
    cout <<   "**********************************************************"<< endl << endl;
    setColor(15, 0);
    for ( int i = 0 ; i < idxp ; i++)
    {
        if (programs[i][0]!="")
        {
            cout<<"Program Name: "<< programs[i][0]<<endl;
            cout<<"Description: "<<programs[i][1]<<endl;
            cout<<"Duration: "<<programs[i][2]<<" months"<<endl<<endl;
        }
    }
}
void registerForProgram_Header()
{
    system("cls");
    
    setColor(11, 0);
    cout <<   "**********************************************************"<< endl;
    cout <<   "*           REGISTER FOR A WELLNESS PROGRAMS             *"<< endl;
    cout <<   "**********************************************************"<< endl << endl;
    setColor(15, 0);
}
void personalInfo_Header()
{
    system("cls");
    setColor(11, 0);
    cout <<   "**********************************************************"<< endl;
    cout <<   "*                  PERSONAL INFORMATION                  *"<< endl;
    cout <<   "**********************************************************"<< endl << endl;
    setColor(15, 0);
}
void provideFeedback_Header()
{
    system("cls");
    cout <<   "**********************************************************" << endl;
    cout <<   "*                        FEEDBACK                        *" << endl;
    cout <<   "**********************************************************" << endl << endl;
    setColor(15, 0);
}
void resetPass_Header()
{
    system("cls");
    cout <<   "**********************************************************" << endl;
    cout <<   "*                    RESET PASSWORD                      *" << endl;
    cout <<   "**********************************************************" << endl << endl;
    setColor(15, 0);
} 

//functionalities 
    //admin
bool signup(string username[], string pass[], string role[], int &idx)
{
    cout<<"                                                          Enter username: ";
    cin>>username[idx];
    while(!(isAplphabetOny(username[idx])) || !(firstLetterCapital(username[idx])) || (lenghtOfString(username[idx])<4))
    {
        cout<<"                                                          The username must begin with a capital letter."<<endl<<"                                                          The username must have atleast 4 aplphabets."<<endl;
        cout<<"                                                          Enter username: ";
        cin>>username[idx];
    }
    cout<<endl;
    cout<<"                                                          Enter passcode: ";
    cin>>pass[idx];
    while(!isAlNum(pass[idx]) || (lenghtOfString(pass[idx])<6))
    {
        cout<<"                                                          Password should contain atleast 6 characters."<<endl<<"                                                          Only Numbers and letters should be used.."<<endl;
        cout<<"                                                          Enter passcode:";
        cin>>pass[idx];
    }
    cout<<endl;
    cout<<"                                                          Enter role (Admin, Customer, Manager): ";
    cin>>role[idx];
    cout<<endl;
    if (role[idx]=="Admin" || role[idx]=="Customer" || role[idx]=="Manager" || role[idx]=="admin" || role[idx]=="customer" || role[idx]=="manager")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void displayUserAccounts(string username[], string pass[], string role[], int &idx)
{
    cout<<"\t Username \t Role"<<endl;
    for (int i = 0; i < idx; i++) 
    {
        cout<<"\t "<<username[i]<<"\t "<<role[i]<<endl;
    }
}
bool createNewUser(string username[], string pass[], string role[], int &idx)
{
    cout<<"Enter username"<<endl;
    cin>>username[idx];
    while(!(isAplphabetOny(username[idx])) || !(firstLetterCapital(username[idx])) || (lenghtOfString(username[idx])<4))
    {
        cout<<"The username must begin with a capital letter."<<endl<<"The username must have atleast 4 aplphabets."<<endl;
        cout<<"Enter username"<<endl;
        cin>>username[idx];
    }
    cout<<endl;
    cout<<"Enter passcode"<<endl;
    cin>>pass[idx];
    while(!isAlNum(pass[idx]) || (lenghtOfString(pass[idx])<6))
    {
        cout<<"Password should contain atleast 6 characters."<<endl<<"Only Numbers and letters should be used.."<<endl;
        cout<<"Enter passcode"<<endl;
        cin>>pass[idx];
    }
    cout<<endl;
    cout<<"Enter role"<<endl<<"(Admin, Customer, Manager)"<<endl;
    cin>>role[idx];
    cout<<endl;
    if (role[idx]=="Admin" || role[idx]=="Customer" || role[idx]=="Manager" || role[idx]=="admin" || role[idx]=="customer" || role[idx]=="manager")
    {
        return true;
    }
    else
    {
      return false;
    }
}
bool EditAccounts(string edit_user,string username[], string pass[], string role[], int &idx)
{
    bool userFound = false;
    int userIndex = -1;
    for (int i = 0; i < idx; i++) 
    {
        if (username[i] == edit_user) 
        {
            userIndex = i;
            userFound = true;
            break;
        }
    }

    if (userFound)
    {
        cout << "Enter new Username: ";
        cin >> username[userIndex];
        while(!(isAplphabetOny(username[userIndex])) || !(firstLetterCapital(username[userIndex])) || (lenghtOfString(username[userIndex]) < 4))
        {
            cout << "The username must begin with a capital letter." << endl << "The username must have at least 4 alphabets." << endl;
            cout << "Enter username: ";
            cin >> username[userIndex];
        }
        cout << "Enter new Password: ";
        cin >> pass[userIndex];
        while(!isAlNum(pass[userIndex]) || (lenghtOfString(pass[userIndex]) < 6))
        {
            cout << "Password should contain at least 6 characters." << endl << "Only Numbers and letters should be used." << endl;
            cout << "Enter passcode: ";
            cin >> pass[userIndex];
        }
        cout << "Enter new Role: ";
        cin >> role[userIndex];
        if (!(role[userIndex] == "Admin" || role[userIndex] == "Customer" || role[userIndex] == "Manager" || 
              role[userIndex] == "admin" || role[userIndex] == "customer" || role[userIndex] == "manager"))
        {
            cout << "This role does not exist." << endl;
            return false;
        }

        return true; 
    }
    else
    {
        return false;
    }
}
string deleteAccounts(string username[], string pass[], string role[], int &idx) {
    
    displayUserAccounts(username,pass,role,idx); 
    cout << "Enter username of the account to delete: ";
    string deleteUser ;
    cin >> deleteUser ;

    bool userFound = false;
    string tempUsername[50];
    string tempPass[50];
    string tempRole[50];
    int tempIdx = 0;

    for (int i = 0; i < idx; i++) 
    {
        if (username[i] != deleteUser ) 
        {
            tempUsername[tempIdx] = username[i];
            tempPass[tempIdx] = pass[i];
            tempRole[tempIdx] = role[i];
            tempIdx++;
        } 
        else 
        {
            userFound = true; 
        }
    }

    if (userFound)
    {
        idx = tempIdx;
        for (int i = 0; i < idx; i++) 
        {
            username[i] = tempUsername[i];
            pass[i] = tempPass[i];
            role[i] = tempRole[i];
        }
        writeData(username,pass,role,idx);
        return "User  account deleted successfully.";
    } 
    else 
    {
        return "User  not found.";
    }
}
void ViewallUsers(string username[], string pass[], string role[], int &idx)
{
    cout<<"\t Username \t Role"<<endl;
    for (int i = 0; i < idx; i++) 
    {
        cout<<"\t "<<username[i]<<"\t "<<role[i]<<endl;
    }
}
void viewFeedback(int &idxf, string feedback[][3], const int MAX_FEEDBACK)
{
    if (idxf == 0) 
    {
        cout << "No feedback available." << endl;
        return;
    }
    for ( int j = 0 ; j < idxf ; j++)
    {
        cout<<"Name: "<<feedback[j][1]<<endl;
        cout<<"Program: "<<feedback[j][2]<<endl;
        cout<<"Feedback: "<<feedback[j][0]<<endl;
        cout<<endl;
    }
}
void viewRegisteredCustomers(string registeredCustomers[][6],const int MAX_registered, int &idxr)
{
    cout<<"Username \t"<<"Program \t"<<"Age \t"<<"Gender \t"<<"Phone Number \t"<<"Email"<<endl;
    if (idxr==0)
    {
        cout << "No registered customers available." << endl;
    }
    else
    {
        for (int i = 0; i < idxr; i++)
        {
            cout << registeredCustomers[i][1] << "\t         " 
             << registeredCustomers[i][0] << "\t     "
             << registeredCustomers[i][2] << "\t      "
             << registeredCustomers[i][5] << "\t      "
             << registeredCustomers[i][4] << "\t      "
             << registeredCustomers[i][3] << endl;
            i++;
        }
    }
}
    //manager
void displayProgram(string programs[][3], int &idxp, const int maxProgram)
{
    for ( int i = 0 ; i < idxp ; i++)
    {
        if (programs[i][0]!="")
        {
            cout<<"Program Name: "<< programs[i][0]<<endl;
            cout<<"Description: "<<programs[i][1]<<endl;
            cout<<"Duration: "<<programs[i][2]<<" months"<<endl<<endl;
        }
    }
}

void viewPrograms(string programs[][3], int &idxp, const int maxProgram)
{
    int num=1;
    for ( int i = 0 ; i < idxp ; i++)
    {
        if (programs[i][0]!="")
        {
            cout<<"Program Name: "<< programs[i][0]<<endl;
            cout<<"Description: "<<programs[i][1]<<endl;
            cout<<"Duration: "<<programs[i][2]<<" months"<<endl<<endl;
        }
    }
}

bool addPrograms(string programs[][3], int &idxp, const int maxProgram)
{
    cout<<  "Enter the name of the new program : "<<endl;
    cin.ignore();
    getline(cin, programs[idxp][0]);
    for (int i=0; i<(idxp-1); i++)
    {
        if (programs[0][i]==programs[idxp][0])
        {
            return false;
        }
    }
    cout<<  "Enter the description of Program: "<<endl;
    getline(cin, programs[idxp][1]);
    cout<<  "Enter the duration of the program in months : "<<endl;
    getline(cin,programs[idxp][2] );
    while(!isNumberOnly(programs[idxp][2]))
    {
        cout<<"The duration should be a number.."<<endl;
        cout<<  "Enter the duration of the program in months : "<<endl;
        getline(cin,programs[idxp][2] );
    }
    idxp++;
    return true;
}

string deleteProgram(string programs[][3], int &idxp, const int maxProgram)
{
    cout<<"\t Name \t \t Duration"<<endl;
    for (int i = 0; i < idxp; i++) 
    {
        cout<<"\t "<<programs[i][0]<<"\t \t"<<programs[i][2]<<endl;
    }
    cout <<   "Enter Name of wellness program to delete: ";
    string deleteProgram;
    cin.ignore();
    getline(cin, deleteProgram);
    bool Found = false;
    for (int i = 0; i < idxp; i++) 
    {
        if (programs[i][0] == deleteProgram) 
        {
            Found = true;
            for (int j = i; j < idxp - 1; j++) 
            {
                programs[j][0] = programs[j + 1][0];
                programs[j][1] = programs[j + 1][1];
                programs[j][2] = programs[j + 1][2];
            }
            idxp--; 
            return "Program  account deleted successfully." ;
        }
    }
    if (!Found) 
    {
        return "Program not found.";
    }
}
bool updateProgram(string program,string programs[][3], int &idxp, const int maxProgramp)
{
    for (int i= 0; i < idxp; i++)
    {
        if(programs[i][0]==program)
        {
            cout<<"Enter new name: ";
            cin.ignore();
            getline(cin, programs[i][0]);
            cout<<"Enter new Description: ";
            getline(cin, programs[i][1]);
            cout<<"Enter new duration: ";
            getline(cin, programs[i][2]);
            return true;
            break;
        }
    }
    return false;
}

    //customer
bool registerForProgram(string username[], string pass[], string role[], int &idx,string programs[][3], int &idxp, const int maxProgram , int &idxc,string registeredCustomers[][6],const int MAX_registered, int &idxr)
{  
    string program;
    cout<<  "Available Programs: "<<endl;
    int num=1;
    for ( int i = 0 ; i < idxp ; i++)
    {
        if (programs[i][0]!="")
        {
            cout<<"   "<<num<<". "<<programs[i][0]<<endl;
            num++;
        }
    }
    cout<<  "Enter program name you want to register: ";
    cin.ignore();
    getline(cin, program);
    bool found=false;
    for (int i=0 ; i< idxp; i++)
    {
        if (programs[i][0]==program)
        {
            registeredCustomers[idxc][0]=program;
            found=true;
            cout<<"Enter Your username: ";
            cin>>registeredCustomers[idxc][1];
            for (int j=0 ; j<idx ; j++)
            {
                if (username[j]==registeredCustomers[idxc][1])
                {
                    registeredCustomers[idxr][0]==program;
                    cout<<"Enter Your Age: ";
                    cin>>registeredCustomers[idxr][2];
                    while(!isNumberOnly(registeredCustomers[idxr][2]) || !lenghtOfString(registeredCustomers[idxr][2])==2)
                    {
                        cout<<"Age should be a number of 2 digits.."<<endl;
                        cout<<  "Enter Your Age: ";
                        cin>>registeredCustomers[idxr][2];
                    }
                    cout<<  "Enter your email: ";
                    cin>>registeredCustomers[idxr][3];
                    while(!email_check(registeredCustomers[idxr][3]))
                    {
                        cout<<"Enter a valid email"<<endl;
                        cout<<  "Enter your email: ";
                        cin>>registeredCustomers[idxr][3];
                    }
                    cout<<"Enter your Phone number: ";
                    cin>>registeredCustomers[idxr][4];
                    while(!isNumberOnly(registeredCustomers[idxr][4]) || !lenghtOfString(registeredCustomers[idxr][4])==11)
                    {
                        cout<<"Phone number should be a number of 11 digits.."<<endl;
                        cout<<  "Enter your Phone number: ";
                        cin>>registeredCustomers[idxr][4];
                    }
                    cout<<"Enter your gender(Male/Female): ";
                    cin>>registeredCustomers[idxr][5];
                    while(!(registeredCustomers[idxr][5]=="Male") && !(registeredCustomers[idxr][5]=="Female"))
                    {
                        cout<<"Gender should be either Male or Female.."<<endl;
                        cout<<  "Enter your gender (Male/Female): ";
                        cin>>registeredCustomers[idxr][5];
                    }
                    idxr++;
                }
            }
        }
    }
    return found;
}

void personalInfo(string customerInfo[][4],const int MAX_customerRecords, int &idxc)
{
    cout<<  "Enter your name: ";
    cin>>customerInfo[idxc][0];
    cout<<  "Enter your age: ";
    cin>>customerInfo[idxc][1];
    cout<<  "Enter your gender (M/F): ";
    cin>>customerInfo[idxc][2];
    cout<<  "Enter you phone number: ";
    cin>>customerInfo[idxc][3];
}

void provideFeedback(int &idxf, string feedback[][3], const int MAX_FEEDBACK)
{
    cout<<  "Enter your name: ";
    cin.ignore();
    getline(cin,feedback[idxf][1]);
    cout<<  "Enter the name of program: ";
    getline(cin,feedback[idxf][2]);
    cout<<  "Enter your Feedback: ";
    getline(cin,feedback[idxf][0]);
    cout<<  "Thank you for providing feedback."<<endl;
    idxf++;
}

bool resetPass(string username[], string pass[], string role[], int &idx)
{
    bool check;
    string resetPassword, resetUsername, newPassword, confirmPassword;
    cout<<"Enter the username : ";
    cin>>resetUsername;
    cout<<"Enter the old password: ";
    cin>>resetPassword;
    for (int i=0 ; i<idx ; i++)
    {
        if (resetUsername == username[i] && resetPassword == pass[i])
        {
            cout<<"Enter new password: ";
            cin>>newPassword;
            cout<<"Confirm password: ";
            cin>>confirmPassword;
            if(newPassword==confirmPassword)
            {
                pass[i] = newPassword;
                check= true;
                break;
            }
            else
            {
                cout<<"Passwords do not match."<<endl;
                check= false;
            }
        }
        else
        {
            check= false;
        }
    }
    return check;
}
//gotoxy and color 
void setColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//validations
bool isAplphabetOny(string x)
{
    for (int i = 1; i < x.length(); i++) 
    {
        if (!((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z')))
        {
            return false; 
        }
    }
    return true; 
}

bool firstLetterCapital(string x)
{
    if (!(x[0] >= 'A' && x[0] <= 'Z'))
    {
        return false; 
    }
    return true;
}

bool isNumberOnly(string x)
{ 
    for (int i=0; i<x.length(); i++)
    {
        if ((x[i]<'0' || x[i]>'9')) 
        {
            return false;
        } 
    }
    return true;
}
bool isAlNum(string x)
{
    for (int i=0; i<x.length(); i++)
    {
        if (!isalnum(x[i]))
        {
            return false;
            break;
        }
    }
    return true;
}

int lenghtOfString(string x)
{
    int count=0;
    for (int i=0; x[i]!='\0' ;i++)
    {
        count++;
    }
    return count;
}
bool email_check(string email)
{
    bool valid_email = false;
    bool isSpace = false;
    bool isAtRate = false;
    bool isDot = false;
    int length = 0;
    for (int i = 0; email[i] != '\0'; i++)
    {
        length++;
    }
    for (int idx = 0; idx < length; idx++)
    {
        if (email[idx] == '@')
        {
            isAtRate = true;
        }
        if (email[idx] == '.')
        {
            isDot = true;
        }
        if (email[idx] == ' ')
        {
            isSpace = true;
        }
    }
    if (isAtRate == true && isSpace == false && isDot == true)
    {
        valid_email = true;
    }
    return valid_email;
}

bool isValidRole(string x)
{
    if(x=="Admin" || x=="admin" || x=="Manager" || x=="manager" || x=="Customer" || x=="customer" )
    {
        return true;
    }
    else
    {
        return false;
    }
}
//file handling
void readData(string username[], string pass[], string role[], int &idx)
{
    string record; 
    fstream data;
    data.open("credentials.csv", ios:: in);
    while(!(data.eof()))
    {
        getline(data, record);
        username[idx]=getField(record,1);
        pass[idx]=getField(record,2);
        role[idx]=getField(record,3);
        idx++;
    }
}
string getField(string record, int field)
{
    int commaCount=1;
    string item;
    for (int idx=0; idx<record.length() ; idx++)
    {
        if(record[idx]==',')
        {
            commaCount++;
        }
        else if(commaCount==field)
        {
            item+=record[idx];
        }
    }
    return item;
}
void writeData(string username[], string pass[], string role[], int &idx)
{
    fstream fwrite;
    string line;
    fwrite.open("credentials.csv", ios::app);
    fwrite<<username[idx]<<","<<pass[idx]<<","<<role[idx]<<endl;
    fwrite.close();
}

void readPrograms_FromFile(string programs[][3],const int maxProgram , int &idxp)
{
    string record; 
    fstream data;
    data.open("programs.csv", ios:: in);
    while(!(data.eof()))
    {
        getline(data, record);
        programs[idxp][0]=getField(record,1);
        programs[idxp][1]=getField(record,2);
        programs[idxp][2]=getField(record,3);
        idxp++;
    }
}
void writePrograms_ToFile(string programs[][3],const int maxProgram , int &idxp)
{
    fstream fwrite;
    string line;
    fwrite.open("programs.csv", ios::app);
    fwrite<<programs[idxp][0]<<","<<programs[idxp][1]<<","<<programs[idxp][2]<<endl;
    fwrite.close();
}