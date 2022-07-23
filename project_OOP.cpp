#include <bits/stdc++.h>
#include <conio.h>
#include <string>
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

class offers
{
protected:
	float amount;
	int op;

public:
	offers()
	{
		amount = 0;
	}
	void flipkart()
	{
		cout << "\nEnter amount to pay : ";
		cin >> amount;
		amount = amount - (15.0 / 100.0) * amount;
	}
	void amazon()
	{
		cout << "\nEnter amount to pay : ";
		cin >> amount;
		if (amount >= 5000)
		{
			amount = amount - 0.25 * amount;
		}
	}
	void elecBill()
	{
		cout << "\nEnter amount to pay : ";
		cin >> amount;
		if (amount >= 1000)
		{
			amount = amount - 0.05 * amount;
		}
	}
	void waterBill()
	{
		cout << "\nEnter amount to pay : ";
		cin >> amount;
		if (amount >= 300)
		{
			amount = amount - 0.05 * amount;
		}
	}
	void GasBill()
	{
		cout << "\nEnter amount to pay : ";
		cin >> amount;
		amount = amount - 100;
	}

	void callFunctionShopping()
	{
		if (op == 1)
		{
			flipkart();
		}
		else if (op == 2)
		{
			amazon();
		}
		else
		{
			cout << "\nInvalid option";
		}
	}
	void callFunctionBill()
	{
		if (op == 1)
		{
			elecBill();
		}
		else if (op == 2)
		{
			waterBill();
		}
		else if (op == 3)
		{
			GasBill();
		}
		else
		{
			cout << "\nInvalid option";
		}
	}

	void displayShoppingOffers()
	{
		cout << "\n BEST OFFERS ";
		cout << "\n Shopping ";
		cout << "\n 1. Flipkart : flat 15% off on all orders ";
		cout << "\n 2. Amazon : flat 25% off on all orders *(above Rs5000)";
		cout << "\n Choose an option : ";
		cin >> op;
		callFunctionShopping();
	}
	void displayBilloptions()
	{
		cout << "\n BILL PAYMENT OPTIONS ";
		cout << "\n 1. Electricity bill : 5% off on bill amount above Rs1000";
		cout << "\n 2. Water Bill : 5% off on bill amount above Rs300";
		cout << "\n 3. Gas Bill : Rs100 off ";
		cout << "\n Choose an option : ";
		cin >> op;
		callFunctionBill();
	}
};

class account : public userDetails, public offers //Inheriting userDetails (class)
{
	int acno;
	static int accnoCounter; // Keep a count of number of accounts
	int loginPass;
	int netBankingPassword[8];
	int encryptedPassword[8];
	int balance;
	int type;

public:
	account()
	{					// Constructor
		accnoCounter++; // increase counter everytime object is created
		balance = 0;
		acno = 0;
		netBankingPassword[8] = {0};
		encryptedPassword[8] = {0};
	}
	void createAccount();			 // Create new Account
	void showAccountDetails() const; //Account Details
	void update();					 // Update account Details
	void deposit(int);				 // Add to balance amount
	void withdraw();				 // Reduce account balance amount
	void report() const;			 // Show data in tabular format
	int retacno() const;			 // Get account number
	int retBalance() const;			 // Get balance amount
	int rettype() const;			 // Get type of account
	bool checkLoginPass(int);		 // check Login password
	bool decryptPassword(int[]);	 // Consists of Password encrypted key (Pek) to decrypt and compare password
	void setPassword();				 // Read and save encrypted Password
	void setAmount();
};

int account::accnoCounter = 0;

void account::createAccount()
{
	static int counter = 0;
	cout << "\n\nBANK IFSC CODE : 6825\n\n";

	cout << "\nEnter User Details\n";
	setDetails();
	cout << "\nCreate Login Password (should be a number): ";
	cin >> loginPass;
	cout << "\nType of The account ";
	cout << "\n1. Savings Account (Min balance Rs3500) \n2.Savings Account (Zero balance) \n3.Fixed Deposit Account";
	cout << "\nEnter Type of The account (1/2/3) : ";
	cin >> type;
	cout << "\n\n\nAccount Created\n";
	acno = 68250 + loginPass;
	setPassword();
	cout << "\nYour Account No. is : " << acno;
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
	if (type == 3)
	{
		cout << "\nCannot Deposit in Fixed Deposit Account\n";
	}
	else
		balance += x;
}

void account::withdraw()
{
	try
	{
		if (type == 2)
		{
			if (balance - amount < 3500) //Exception Handling
				throw balance;
			else
				balance = balance - amount;
		}
		if (type == 1)
		{
			if (balance - amount < 0)
				throw balance;
			else
				balance = balance - amount;
		}
	}
	catch (int b)
	{
		cout << "\nInsufficient Balance\n";
	}
}

void account ::setPassword()
{
	cout << "\nCreate Net Banking Password (8-digit number ): ";
	for (int i = 0; i < 8; i++)
	{
		netBankingPassword[i] = int(getch());
		cout << "*";
	}

	for (int i = 0; i < 8; i++)
	{
		encryptedPassword[i] = netBankingPassword[8 - i - 1] + 25;
	}
	for (int i = 0; i < 8; i++)
	{
		netBankingPassword[i] = encryptedPassword[i];
	}

	cout << "\n\nNET BANKING PASSWORD IS HIGHLY SECURED . DO NOT DISCLOSE\n\n";
}

bool account ::decryptPassword(int p[])
{
	int b;
	bool flag;
	for (int i = 0; i < 8; i++)
	{
		p[i] = p[i] + 25; // applying same operation on user given password
	}					  // and compare if recorded password matches to user given password
	for (int i = 0; i < 4; i++)
	{
		b = p[i];
		p[i] = p[8 - i - 1];
		p[8 - i - 1] = b;
	}
	for (int i = 0; i < 8; i++)
	{
		if (p[i] == netBankingPassword[i])
			flag = true;
		else
			flag = false;
	}
	return flag;
}

void account ::setAmount()
{
	cout << "\n\n\tTO WITHDRAW AMOUNT ";
	cout << "\n\nEnter The amount to be withdraw";
	cin >> amount;
}

void account::report() const
{
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << balance << endl;
}

int account::retacno() const
{
	return acno;
}

int account::retBalance() const
{
	return balance;
}

int account::rettype() const
{
	return type;
}

bool account::checkLoginPass(int p)
{
	bool flag;
	if (loginPass == p)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	return flag;
}

void write_account(account &ac);			  // write records in binary file
void display_sp(int, account &ac);			  // display account details
void update_account(int, account &ac);		  // update records of file
void delete_account(int, account &ac);		  // delete records of file
void display_all(account &ac);				  // display all account details
void deposit_withdraw(int, int, account &ac); // desposit/withdraw amount for given account
void intro();								  //introductory screen function

int main()
{
	char ch;
	account ac;
	offers off;
	int accno;
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
		cout << "\n\n\t08. BEST SHOPPING OFFERS";
		cout << "\n\n\t09. BILL PAYMENT";
		cout << "\n\n\t10. EXIT";
		cout << "\n\n\tSelect Your Option (1-10) ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			write_account(ac);
			break;
		case '2':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			deposit_withdraw(accno, 1, ac);
			break;
		case '3':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			ac.setAmount();
			deposit_withdraw(accno, 2, ac);
			break;
		case '4':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			display_sp(accno, ac);
			break;
		case '5':
			display_all(ac);
			break;
		case '6':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			delete_account(accno, ac);
			break;
		case '7':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			update_account(accno, ac);
			break;
		case '8':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			off.displayShoppingOffers();
			deposit_withdraw(accno, 2, ac);
			break;
		case '9':
			cout << "\n\n\tEnter The account No. : ";
			cin >> accno;
			off.displayBilloptions();
			deposit_withdraw(accno, 2, ac);
			break;
		case '10':
			cout << "\n\n\tThanks for using bank managemnt system";
			break;
		default:
			cout << "\a";
		}
	} while (ch != '8');
	return 0;
}

void write_account(account &ac)
{
	ofstream outFile;
	outFile.open("account.txt", ios::binary | ios::app);
	ac.createAccount();
	outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n, account &ac)
{
	bool flag = false;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	int p = 0;
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

void update_account(int n, account &ac)
{
	bool found = false;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	int p = 0;
	cout << "\n\tEnter password to modify Account : ";
	cin >> p;
	if (ac.checkLoginPass(p))
	{
		while (!File.eof() && found == false)
		{
			File.read(reinterpret_cast<char *>(&ac), sizeof(account));
			if (ac.retacno() == n)
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
		}
		File.close();
		if (found == false)
			cout << "\n\n Record Not Found ";
	}
	else
	{
		cout << "Wrong Password";
	}
}

void delete_account(int n, account &ac)
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	int p = 0;
	cout << "\n\tEnter password to Delete Account : ";
	cin >> p;
	if (ac.checkLoginPass(p))
	{
		outFile.open("Temp.txt", ios::binary);
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
		remove("account.txt");
		rename("Temp.txt", "account.txt");
		cout << "\n\n\tRecord Deleted ..";
	}
	else
	{
		cout << "Wrong Password";
	}
}

void display_all(account &ac)
{

	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	int p = 0;
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

void deposit_withdraw(int n, int option, account &ac)
{
	float amt;
	bool found = false;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
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
			for (int i = 0; i < 8; i++)
			{
				p[i] = int(getch());
				cout << "*";
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
					ac.withdraw();
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