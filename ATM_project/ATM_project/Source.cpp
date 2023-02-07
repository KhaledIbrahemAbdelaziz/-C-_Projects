#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void menu() {
	cout << "1. Check balance " << endl;
	cout << "2. Deposit " << endl;
	cout << "3. Withdraw " << endl;
}

double Deposit(double balance, double money) {
	double result;
	result = balance + money;
	return result;
}

double Withdraw(double balance, double money) {
	double result;
	if (balance < money) {
		cout << "You can't withdraw this money. Your balance is small." << endl;
		return balance;
	}
	else {
		result = balance - money;
		return result;
	}
}

int main() {
	
	int password,choices;
	fstream Users;
	string line,space = " ",no = "";
	double balance, money;


	cout << "Hello sir. Please enter your password: " << endl;
	cin >> password;

	Users.open("Users.txt", ios::in);
	if (Users.is_open()) {
			while (getline(Users, line))//!Users.eof()
			{
				if (no == line) {
					continue;
				}
				else if (space == line) {
					continue;
				}
			    else if (password == stoi(line)) {
					cout << "Welcome sir. Your password is "<<password << endl;
					menu();
					cout << "Enter your choice: " << endl;
					cin >> choices;
					switch (password)
					{
					case 2266: {balance = 7000.6257; break; }
					case 2626: {balance = 5000.55549; break; }
					case 2255: {balance = 500.000; break; }
					case 2525: {balance = 1000.356974; break; }
					default:
						break;
					}
					switch (choices)
					{
					case 1: {cout << "Your balance is " << balance << endl;
						break;
					}
					case 2: {cout << "Enter the amount of money you want to deposit: " <<  endl;
						cin >> money;
						double newbalance = Deposit(balance, money);
						cout << "Your balance now is " << newbalance << endl;
						break;
					}
					case 3: {
						  cout << "Enter the amount of money you want to withdraw: "<< endl;
						  cin >> money;
						  double newbalance = Withdraw(balance, money);
						  cout << "Your balance now is " << newbalance << endl;
						  break;
					}
					default:
						break;
					}
					//break;
				}
				else {
					//cout << "Wrong password." << endl;
					//cin >> password;
					continue;
					//return 1;
				}
			}
			Users.close();
	}
	

	return 0;
}