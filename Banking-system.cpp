#include<fstream>
#include<iostream>
#include<conio.h>

using namespace std;

// CLASS USED IN PROJECT

class account{
int acno;
char name[50];
double amount;
char type;

public:
void create_account();
void show_account();
void modify();
void depo(int);
void wdraw(int);
void report();
int retacno();
int retdeposit();
char rettype();
};

void account::create_account()
{
  cout<<"\n ACCount Num: "; cin>>acno;
  cout<<"\n Enter Account-Holder Name: "; cin>>name;
  cout<<"\n choose Account-Type (C/S): "; cin>>type;
  cout<<"\n Deposit Initial amount (>=$50): "; cin>>amount;
  cout<<"\n\n\n   Acount Created...";
}

void account::show_account()
{
  cout<<"\n Account Num: " <<acno;
  cout<<"\n Acount-Holder Name: " <<name;
  cout<<"\n Account-Type: " <<type;
  cout<<"\n Balance: $" <<amount;
}

void account::modify()
{
  cout<<"\n Account Num: " <<acno;
  cout<<"\n Enter Account-Holder Name: "; cin>>name;
  cout<<"\n Choose Account-Type (C/S): "; cin>>type;
  cout<<"\n Enter Amount: $"; cin>>amount;
}

void account::depo(int x)
{
  amount +=x;
}

void account::wdraw(int x)
{
  amount -= x
}

void account::report()
{
  cout<<acno <<"\t\t " <<name <<"\t\t" <<type <<"\t$" <<deposit <<endl;
}

int account::retacno()
{
  return acno;
}

int account::retdeposit()
{
  return amount;
}

int account::rettype()
{
  return type;
}

// function declaration

void write_account();				      //function to write record in binary file
void display_sp(int);				      //function to display account details given by user
void modify_account(int);			    //function to modify record of file
void delete_account(int);			    //function to delete record of file
void display_all();					      //function to display all account details
void deposit_withdraw(int, int);	// function to desposit/withdraw amount for given account
void intro();						          //introductory screen function
void transfer(int, int);			    //function to transfer amount.   


//THE MAIN FUNCTION

int main()
{
	system("color 0a");
	system("cls");
	char ch;
	int num;

	intro();
	do
	{
		system("cls");
		cout << "\t:---------------------------------------------------------------------------------------:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t   MAIN MENU\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t01. NEW ACCOUNT\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t02. DEPOSIT AMOUNT\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t03. WITHDRAW AMOUNT\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t04. TRANSFER AMOUNT\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t05. BALANCE ENQUIRY\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t06. CLOSE AN ACCOUNT\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t07. ALL ACCOUNT HOLDER LIST\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t08. MODIFY AN ACCOUNT\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t09. EXIT\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:\t\t\t\t\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n\t:\t\t\t\t\t\t\t\t\t\t\t:\n";
		cout << "\t:---------------------------------------------------------------------------------------:\n";
		cout << "\n\n\t\tSelect Your Option (1-9): "; cin >> ch;
    switch (ch)
		{
		case '1':
			system("cls");
			write_account();
			break;
		case '2':
			system("cls");
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("cls");
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("cls");
			cout << "\n\n\tEnter the senders account No. : "; cin >> num;
			transfer(num, 1);
			cout << "\n\n\tEnter the resivers account No. : "; cin >> num;
			transfer(num, 2);
			break;
		case '5':
			system("cls");
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			display_sp(num);
			break;
		case '6':
			system("cls");
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			delete_account(num);
			break;
		case '7':
			system("cls");
			display_all();
			break;
		case '8':
			system("cls");
			cout << "\n\n\tEnter The account No. : "; cin >> num;
			modify_account(num);
			break;
		case '9':
			system("cls");
			cout << "\n\n\tThanks for using bank managemnt system";
			break;
		default:cout << "\a";
		}
		_getch();
	} while (ch != '9');
	return 0;
}





