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
			display_rec(num);
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


// function to write in file

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);

	ac.create_account();
	outFile.write((char*)&ac, sizeof(account));
	outFile.close();
}



// function to read specific record from file

void display_rep(int n)
{
	account ac;
	int flag = 0;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";
	while (inFile.read((char*)&ac, sizeof(account)))
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			flag = 1;
		}
	}
	inFile.close();
	if (flag == 0)
		cout << "\n\nAccount number does not exist";
}



//    	function to modify record of file

void modify_account(int n)
{
	int found = 0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (File.read((char*)&ac, sizeof(account)) && found == 0)
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modify();

			int pos = (-1) * sizeof(account);
			File.seekp(pos, ios::cur);
			File.write((char*)&ac, sizeof(account));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
}


//    	function to delete record of file
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("temp.dat", ios::binary);

	while (inFile.read((char*)&ac, sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write((char*)&ac, sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("temp.dat", "account.dat");
	cout << "\n\n\tRecord Deleted ..";
}


//    	function to display all accounts deposit list


void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "==========================================================\n";
	cout << "A/c no\t\tNAME\t\t\tType \t Balance\n";
	cout << "==========================================================\n";
	while (inFile.read((char*)&ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


//    	function to deposit and withdraw amounts


void deposit_withdraw(int n, int option)
{
	int amt;
	int found = 0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (File.read((char*)&ac, sizeof(account)) && found == 0)
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited. : ";
				cin >> amt;
				ac.depo(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw. : ";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 0 && ac.rettype() == 'S') || (bal < 0 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.wdraw(amt);
			}
			int pos = (-1) * sizeof(ac);
			File.seekp(pos, ios::cur);
			File.write((char*)&ac, sizeof(account));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
}


//     function to transfer amount

void transfer(int n, int op)
{

	int amt;
	int found = 0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (File.read((char*)&ac, sizeof(account)) && found == 0)
	{
		if (ac.retacno() == n)
		{
			cout << "\n\n\tCURRENT BALANCE AMOUNT\n";
			ac.show_account();
			cout << "\n\nEnter The amount to be transfer. : ";
			cin >> amt;
			if (op == 1)
			{
				cout << "\n\n\tTO SEND AMOUNT ";

				int bal = ac.retdeposit() - amt;
				if ((bal < 0 && ac.rettype() == 'S') || (bal < 0 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.wdraw(amt);
			}
			if (op == 2)
			{
				ac.depo(amt);
			}

			int pos = (-1) * sizeof(ac);
			File.seekp(pos, ios::cur);
			File.write((char*)&ac, sizeof(account));
			cout << "\n\n\t Record Updated";
			found = 1;

			cout << "\n\n\tNEW BALANCE AMOUNT \n";
			ac.show_account();
		}
	}
	File.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	return;
}



//    	INTRODUCTION FUNCTION

void intro()
{
	cout << "\t#<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#\t\t\tBANK MANAGEMENT SYSTEM\t\t\t\t\t\t#\n";
	cout << "\t#\t\t\t......................\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#\t\t    DESIGNNED AND PROGRAMMED BY \t\t\t\t\t#\n";
	cout << "\t#\t\t    ........................... \t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#\t\t\t    1, BEREKET DESTA \t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#\t\t\t    2, BEREKET LEMMA \t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#\t\t\t    3, EPHREM ALEMAYEHU\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#\tSCHOOL : UNITY UNIVERSITY\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n\t#\t\t\t\t\t\t\t\t\t\t\t#\n";
	cout << "\t#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>#\n";
	_getch();
}









