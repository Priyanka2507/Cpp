#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class userDetails
{
protected:
	string email;
	string name;
	string phone;
	string address;
	string aadharCard;
	string panCard;

public:
	void setDetails();			 // Get User Details
	void updateDetails();		 // Update User Details
	void displayDetails() const; // Display User Details
};

void userDetails ::setDetails()
{
	cout << "\nEnter NAME (All Capital): ";
	cin >> name;
	cout << "\nEnter PHONE NUMBER : ";
	cin >> phone;
	cout << "\nEnter EMAIL ID : ";
	cin >> email;
	cout << "\nEnter ADDRESS : ";
	cin >> address;
	cout << "\nEnter AADHAR CARD NUMBER : ";
	cin >> aadharCard;
	cout << "\nEnter PAN CARD NUMBER : ";
	cin >> panCard;
}

void userDetails ::displayDetails() const
{
	cout << "\n Name : " << name;
	cout << "\n Phone number : " << phone;
	cout << "\n Email : " << email;
	cout << "\n Aadhar Card number : " << aadharCard;
	cout << "\n Pan Card number : " << panCard;
}

void userDetails ::updateDetails()
{
	cout << "\nEnter new NAME (All Capital): ";
	cin >> name;
	cout << "\nEnter new PHONE NUMBER : ";
	cin >> phone;
	cout << "\nEnter new EMAIL ID : ";
	cin >> email;
	cout << "\nEnter new ADDRESS : ";
	cin >> address;
}

class account : public userDetails //Inheriting userDetails (class)
{
	string acno;
	static int accnoCounter; // Keep a count of number of accounts
	int loginPass;
	int netBankingPassword[16];
	int encryptedPassword[16];
	int balance;
	string type;

public:
	void createAccount();			 // Create new Account
	void showAccountDetails() const; //Account Details
	void update();					 // Update account Details
	void deposit(int);				 // Add to balance amount
	void withdraw(int);				 // Reduce account balance amount
	void report() const;			 // Show data in tabular format
	string retacno() const;			 // Get account number
	int retBalance() const;			 // Get balance amount
	string rettype() const;			 // Get type of account
	bool checkLoginPass(int);		 // check Login password
	bool decryptPassword(int[]);	 // Consists of Password encrypted key (Pek) to decrypt and compare password
	void setPassword();				 // Read and save encrypted Password
};

int account::accnoCounter = 0;

void account::createAccount()
{

	cout << "\n\nBANK IFSC CODE : 6825\n\n";

	cout << "\nEnter User Details\n";
	setDetails();
	cout << "\nCreate Login Password (should be a number): ";
	cin >> loginPass;
	cout << "\nType of The account ";
	cout << "\n1. Savings Account (Min balance Rs3500) \n2.Savings Account (Zero balance) \n3.Fixed Deposit Account";
	cout << "\nEnter Type of The account (MinBalance/ZeroBalance/FixedDeposit) : ";
	cin >> type;
	cout << "\n\n\nAccount Created\n";
	accnoCounter++;
	acno = "20206825" + accnoCounter;
	setPassword();
	cout << "\nYour Account No. is : " << acno;
	setPassword();
}

void account::showAccountDetails() const
{
	cout << "\nAccount No. : " << acno;
	cout << "\nAccount Holder Details ";
	displayDetails();
	cout << "\nType of Account : " << type;
	cout << "\nBalance amount : " << balance;
}

void account::update()
{
	cout << "\nAccount No. : " << acno;
	cout << "\nUpdate Account Holder Details : ";
	updateDetails();
}

void account::deposit(int x)
{
	if (type == "FixedDeposit")
	{
		cout << "\nCannot Deposit in Fixed Deposit Account\n";
	}
	else
		balance += x;
}

void account::withdraw(int x)
{
	try
	{
		if (type == "MinBalance")
		{
			if (balance - x < 3500) //Exception Handling
				throw balance;
			else
				balance = balance - x;
		}
		if (type == "ZeroBalance")
		{
			if (balance - x < 0)
				throw balance;
			else
				balance = balance - x;
		}
	}
	catch (int b)
	{
		cout << "\nInsufficient Balance\n";
	}
}

void account ::setPassword()
{
	cout << "\nCreate Net Banking Password (16-digit number ): ";
	for (int i = 0; i < 16; i++)
	{
		netBankingPassword[i] = getch();
		cout << "*";
	}

	for (int i = 0; i < 16; i++)
	{
		encryptedPassword[i] = netBankingPassword[16 - i - 1] + 25;
	}
	for (int i = 0; i < 16; i++)
	{
		netBankingPassword[i] = encryptedPassword[i];
	}

	cout << "\n\nNET BANKING PASSWORD IS HIGHLY SECURED . DO NOT DISCLOSE\n\n";
}

bool account ::decryptPassword(int p[])
{
	int b;
	bool flag;
	for (int i = 0; i < 16; i++)
	{
		p[i] = p[i] + 25; // applying same operation on user given password
	}					  // and compare if recorded password matches to user given password
	for (int i = 0; i < 16; i++)
	{
		b = p[i];
		p[i] = p[16 - i - 1];
		p[16 - i - 1] = b;
	}
	for (int i = 0; i < 16; i++)
	{
		if (p[i] == netBankingPassword[i])
			flag = true;
		else
			flag = false;
	}
	return flag;
}

void account::report() const
{
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << balance << endl;
}

string account::retacno() const
{
	return acno;
}

int account::retBalance() const
{
	return balance;
}

string account::rettype() const
{
	return type;
}

bool account::checkLoginPass(int p)
{
	if (loginPass == p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void write_account();				// write records in binary file
void display_sp(string);			// display account details
void update_account(string);		// update records of file
void delete_account(string);		// delete records of file
void display_all();					// display all account details
void deposit_withdraw(string, int); // desposit/withdraw amount for given account
void intro();						//introductory screen function

int main()
{
	char ch;
	string accno;
	intro();
	do
	{
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\n\t02. DEPOSIT AMOUNT";
		cout << "\n\n\t03. WITHDRAW AMOUNT";
		cout << "\n\n\t04. BALANCE ENQUIRY";
		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t06. CLOSE ACCOUNT";
		cout << "\n\n\t07. UPDATE ACCOUNT";
		cout << "\n\n\t08. EXIT";
		cout << "\n\n\tSelect Your Option (1-8) ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			deposit_withdraw(accno, 1);
			break;
		case '3':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			deposit_withdraw(accno, 2);
			break;
		case '4':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			display_sp(accno);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			delete_account(accno);
			break;
		case '7':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			update_account(accno);
			break;
		case '8':
			cout << "\n\n\tThanks for using bank managemnt system";
			break;
		default:
			cout << "\a";
		}
	} while (ch != '8');
	return 0;
}

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.createAccount();
	outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
	outFile.close();
}

void display_sp(string n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	int p;
	cout << "\n\tEnter password to Get Account Details : ";
	cin >> p;
	if (ac.checkLoginPass(p))
	{
		cout << "\nBALANCE DETAILS\n";

		while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
		{
			if (ac.retacno() == n)
			{
				ac.showAccountDetails();
				flag = true;
			}
		}
		inFile.close();
		if (flag == false)
			cout << "\n\nAccount does not exist";
	}
	else
	{
		cout << "Wrong Password";
	}
}

void update_account(string n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			int p;
			cout << "\n\tEnter password to modify Account : ";
			cin >> p;
			if (ac.checkLoginPass(p))
			{
				ac.showAccountDetails();
				cout << "\n\nEnter The New Details of account" << endl;
				ac.update();
				int pos = (-1) * static_cast<int>(sizeof(account));
				File.seekp(pos, ios::cur);
				File.write(reinterpret_cast<char *>(&ac), sizeof(account));
				cout << "\n\n\t Record Updated";
				found = true;
			}
			else
			{
				cout << "Wrong Password";
			}
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

void delete_account(string n)
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
	int p;
	cout << "\n\tEnter password to Delete Account : ";
	cin >> p;
	if (ac.checkLoginPass(p))
	{
		outFile.open("Temp.dat", ios::binary);
		inFile.seekg(0, ios::beg);
		while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
		{
			if (ac.retacno() != n)
			{
				outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
			}
		}
		inFile.close();
		outFile.close();
		remove("account.dat");
		rename("Temp.dat", "account.dat");
		cout << "\n\n\tRecord Deleted ..";
	}
	else
	{
		cout << "Wrong Password";
	}
}

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
	int p;
	cout << "\n\tEnter password to Get Account Details : ";
	cin >> p;
	if (ac.checkLoginPass(p))
	{
		cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
		cout << "====================================================\n";
		cout << "A/c no.          NAME           Type  Balance\n";
		cout << "====================================================\n";
		while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
		{
			ac.report();
		}
		inFile.close();
	}
	else
	{
		cout << "Wrong Password";
	}
}

void deposit_withdraw(string n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			int p[16];
			cout << "\n\tEnter Net Banking Password to make payment or deposit Account : ";
			for (int i = 0; i < 16; i++)
			{
				cin >> p[i];
			}
			if (ac.decryptPassword(p))
			{
				ac.showAccountDetails();
				if (option == 1)
				{
					cout << "\n\n\tTO DEPOSITE AMOUNT ";
					cout << "\n\nEnter The amount to be deposited";
					cin >> amt;
					ac.deposit(amt);
				}
				if (option == 2)
				{
					cout << "\n\n\tTO WITHDRAW AMOUNT ";
					cout << "\n\nEnter The amount to be withdraw";
					cin >> amt;
					ac.withdraw(amt);
				}
				int pos = (-1) * static_cast<int>(sizeof(ac));
				File.seekp(pos, ios::cur);
				File.write(reinterpret_cast<char *>(&ac), sizeof(account));
				cout << "\n\n\t Record Updated";
				found = true;
			}
			else
			{
				cout << "Wrong Password";
			}
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

void intro()
{
	cout << "----------------------------------------BANK MANAGEMENT SYSTEM-----------------------------------------------";
}
