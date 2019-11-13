#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <conio.h>
#include <ctime>
#include <dos.h>
#include <iomanip>
using namespace std;

int i,j,li,lp,rec,valid;

COORD coord = {0, 0};

void gotoxy(int x, int y)

{

 COORD coord;

coord.X = x;

coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void help();

//**************************** **********

//  GLOBAL VARIABLE DECLARATIONS

//**************************** **********



//int i,j,li,lp;

char ch,choice;



//**********************************************************

// THIS CLASS CONTROLS ALL THE FUNCTIONS RELATED TO FEES

//**********************************************************



class FEE

{

 private :

 int  Class ;

 float tuition, ac, science, computer, activity ;

 void DISPLAY(int) ;

 void MODIFY_RECORD(int, float, float, float, float, float) ;



 public :

 void ADDITION(void) ;

 //void MODIFICATION(void) ;

 void FEE_SLIP(void) ;

 void LIST(void) ;

 void HELP(void);

}fee ;



//****************************************

//                  MAIN MENU FUNCTION

//****************************************

void mainmenu()

{

 system("cls");




gotoxy(15,10);



printf("Press the corresponding Keys for the desired action");

gotoxy(35,16);



printf("F: FEE SLIP");

gotoxy(35,19);


printf("L: LIST");

gotoxy(35,22);



printf("H: HELP");

gotoxy(35,25);



printf("Q: QUIT");

 choice=getch();

ch=toupper(choice);

 switch(ch)

 {

 case'F':fee.FEE_SLIP();

 break;

 case'L':fee.LIST();

 break;

 case'H':fee.HELP();

 break;

case'Q':exit(0);

 break;

default:gotoxy(33,40);

cout<<"Illegal Choice Press any key to return to Main Menu";

getch();

mainmenu();

 }

}

//Main Menu Function End



//**********************************************************

// FUNCTION TO ADD FEE STRUCTURE IN FEE FILE

//**********************************************************



void FEE :: ADDITION(void)

{

    fstream file ;

    file.open("FEE.DAT", ios::in) ;

     if (!file.fail())

     return ;

    file.close() ;

    file.open("FEE.DAT", ios::app) ;

     for (int i=1; i<=12; i++)

     {

     Class   = i ;

     tuition  = 0.0 ;

     ac      = 0.0 ;

     science = 0.0 ;

     computer= 0.0 ;

     activity= 0.0 ;

    file.write((char *) this, sizeof(FEE)) ;

     }

    file.close() ;
         MODIFY_RECORD(12,450,50,60,60,50) ;

         MODIFY_RECORD(11,450,50,60,60,50) ;

         MODIFY_RECORD(10,350,50,30,60,50) ;

         MODIFY_RECORD(9,350,50,20,60,50) ;

         MODIFY_RECORD(8,300,50,20,40,50) ;

         MODIFY_RECORD(7,300,50,20,40,50) ;

         MODIFY_RECORD(6,300,50,20,40,50) ;

         MODIFY_RECORD(5,250,50,0,40,40) ;

         MODIFY_RECORD(4,250,50,0,40,40) ;

         MODIFY_RECORD(3,250,50,0,40,40) ;

         MODIFY_RECORD(2,250,50,0,40,40) ;

         MODIFY_RECORD(1,250,50,0,40,40) ;

}



//**********************************************************

// FUNCTION TO DISPLAY TOTAL FEE AS LIST

//**********************************************************



void FEE :: LIST()

{

 system("cls") ;


gotoxy(27,3) ;

cout<<"TOTAL FEES FOR THE CLASSES" ;


gotoxy(5,5) ;

cout<<"CLASS             TOTAL FEES" ;


 float total ;

 int row=8 ;

fstream file ;

file.open("FEE.DAT", ios::in) ;

 while (file.read((char *) this, sizeof(FEE)))

 {

 total = tuition + ac + science + computer + activity ;

gotoxy(6,row) ;

cout<<Class ;

gotoxy(23,row) ;

cout<<total ;

 row++ ;

 }

file.close() ;

gotoxy(5,23) ;

cout<<"Press any key to continue............." ;

getch() ;

mainmenu();

}



//**********************************************************

// FUNCTION TO DISPLAY THE RECORD FOR THE GIVEN CLASS

//**********************************************************



void FEE :: DISPLAY(int tclass)

{

fstream file ;

file.open("FEE.DAT", ios::in) ;

 while (file.read((char *) this, sizeof(FEE)))

 {

 if (Class == tclass)

 {

gotoxy(5,5) ;

cout<<"Class : " <<Class ;

gotoxy(5,7) ;

cout<<"~~~~~~~~~~~~" ;

gotoxy(5,8) ;

cout<<"Tution Fee  : " <<tuition ;

gotoxy(5,9) ;

cout<<"Annual charges Fee  : " <<ac ;

gotoxy(5,10) ;

cout<<"Science Fee : " <<science ;

gotoxy(5,11) ;

cout<<"Computer Fee: " <<computer ;

gotoxy(5,12) ;

cout<<"Activity Fee : " <<activity ;

 break ;

 }

 }

file.close() ;

}



//**********************************************************

// FUNCTION TO MODIFY THE FEE RECORD FOR THE GIVEN DATA

//**********************************************************



void FEE :: MODIFY_RECORD(int tclass, float ttution, float tac, float

tscience, float tcomputer, float tactivity)

{

fstream file ;

file.open("FEE.DAT", ios::in) ;

fstream temp ;

temp.open("temp.dat", ios::out) ;

file.seekg(0,ios::beg) ;

 while (!file.eof())

 {

file.read((char *) this, sizeof(FEE)) ;

 if (file.eof())

 break ;

 if (tclass == Class)

 {

 Class   = tclass ;

 tuition  = ttution ;

 ac      = tac ;

 science = tscience ;

 computer= tcomputer ;

 activity= tactivity ;

temp.write((char *) this, sizeof(FEE)) ;

 }

 else

temp.write((char *) this, sizeof(FEE)) ;

 }

file.close() ;

temp.close() ;

file.open("FEE.DAT", ios::out) ;

temp.open("temp.dat", ios::in) ;

temp.seekg(0,ios::beg) ;

 while (!temp.eof())

 {

temp.read((char *) this, sizeof(FEE)) ;

 if (temp.eof())

 break ;

file.write((char *) this, sizeof(FEE)) ;

 }

file.close() ;

temp.close() ;

}


//**********************************************************

// FUNCTION TO DISPLAY THE FEE SLIP FOR THE CLASS

//**********************************************************



void FEE :: FEE_SLIP(void)

{

 system("cls") ;



 char  ch, t1[10] ;

 int   valid=0, t=0, tclass=0 ;

 do

 {

 valid = 1 ;

gotoxy(5,25) ;

cout<<"Press <ENTER> for EXIT" ;

gotoxy(5,5) ;

cout<<"Enter Class to see the Fee Structure : " ;

 gets(t1) ;

 t = atoi(t1) ;

tclass = t ;

 if (strlen(t1) == 0)

 return ;

 if (tclass< 1 || tclass> 12)

 {

 valid = 0 ;

gotoxy(5,25) ;

cout<<"Enter correctly" ;

getch() ;

 }

 } while (!valid) ;

 char name[26] ;

 do

 {

gotoxy(5,25) ;

cout<<"ENTER NAME OF THE STUDENT" ;

 valid = 1 ;

gotoxy(5,7) ;

cout<<"Name : " ;

 gets(name) ;

 if (strlen(name) < 1 || strlen(name) > 25)

 {

 valid = 0 ;

gotoxy(5,25) ;

cout<<"NAME SHOULD NOT BE GREATER THAN 25" ;

getch() ;

 }

 } while (!valid) ;

 system("cls") ;

cout<<"         YOUR SCHOOL      " ;

 int d1, m1, y1 ;

time_t td = time(0);

 struct tm * now = localtime( & td );

 d1 = now->tm_mday ;

 m1 = (now->tm_mon +1 ) ;

 y1 = (now->tm_year +1900 );

gotoxy(45,4) ;

cout<<"Date: " <<d1 <<"/" <<m1 <<"/" <<y1 ;


gotoxy(22,6) ;

cout<<"NAME  : " <<name ;

gotoxy(22,7) ;

cout<<"CLASS : " <<tclass ;


gotoxy(21,9) ;

cout<<"    PARTICULARS               AMOUNT" ;

gotoxy(25,21) ;

cout<<"TOTAL" ;

gotoxy(54,23) ;

cout<<"CASHIER" ;

fstream file ;

file.open("FEE.DAT", ios::in) ;

 while (!file.eof())

{

file.read((char *) this, sizeof(FEE));

 if (Class == tclass)

 {

cout<<"found"<<endl;

 break ;

 }

file.close() ;

}

 float total=0.0 ;

gotoxy(23,12) ;

cout<<"Tuition fees               " <<setprecision(2) <<tuition ;

 total = total+tuition ;

gotoxy(23,13) ;

cout<<"Annual charges fees       " <<setprecision(2) <<ac ;

 total = total+ac ;

gotoxy(23,14) ;

cout<<"Science fees              " <<setprecision(2) <<science ;

 total = total+science ;

gotoxy(23,15) ;

cout<<"Computer fees             " <<setprecision(2) <<computer ;

 total = total+computer ;

gotoxy(23,16) ;

cout<<"Activity fees             " <<setprecision(2) <<activity ;

 total = total+activity ;

//d.LINE_VER(9,21,46,179) ;

 char tt[15] ;

sprintf(tt,"%f",total) ;

gotoxy(49,21) ;

cout<<tt ;

gotoxy(33,40);

cout<<"Press any key to return to the main menu........";

getch() ;

mainmenu();

}



void FEE::HELP()

{

 system("cls");



cout<<"This is a fee structure program"<<endl;

cout<<"It can be used to :  "<<endl;

cout<<"1. View the fee slip of a student of a class"<<endl;

cout<<"2. Modify the fee structure of the school"<<endl;

cout<<"3. View the fee structure of the school in the form of alist"<<endl;

cout<<"The menu functions are described as follows"<<endl;

cout<<"1. FEE SLIP:  This function displays the fee slip for a givenstudent"<<endl;

cout<<" from the class entered by the user. "<<endl;

cout<<" The user can change the fees for various fields"<<endl;

cout<<"3. LIST:      This function displays the list of total fees for all the"<<endl;

cout<<"Press any key to continue..........."<<endl;

getch();

mainmenu();

}



//**********************************************************

// MAIN FUNCTION TO CREATE MENU AND CALL OTHER FUNCTIONS

//**********************************************************



int main()

{

     FEE fee;

    fee.ADDITION();

     system("cls");



     for(i=10;i<71;i++)

     {

        gotoxy(i,15);

         Sleep(30);

        printf("/");

     }

     for(i=70;i>=10;i--)

     {

        gotoxy(i,33);

         Sleep(30);

        printf("/");

     }

     for(j=16;j<=31;j++)

     {

        gotoxy(10,j);

         Sleep(100);

        printf("-");

     }

     for(j=31;j>=16;j--)

     {

        gotoxy(70,j);

         Sleep(100);

        printf("-");

     }

    gotoxy(16,17);

    printf("Fee Structure System");

    gotoxy(12,20);

    printf(" Prepared By.\n\t\tJay Kshirsagar(18dce045)\n\t\tFenil Gadhiya (18dce029)\n\t\tRaj Koladiya(18dce044)\n\t\tAnay Patel(18dce069)");

    printf("\n\n\n\t\t\tPress Any Key To .......Continue");

    getch();

    mainmenu();



     return 0;

}

