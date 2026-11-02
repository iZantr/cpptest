#include <iostream>
using namespace std;
class BankAccount {
private:
	const int accountId;
	string owner{"Client"};
	double balance{ 0.0 };
	inline static int nextId{ 5001 };
	inline static int activeAccounts{ 0 };
	inline static double totalBankVault{ 0.0 };
public:
	BankAccount(string ow, double initalDeposit) : accountId{ nextId++ }, owner{ ow },
		balance{ initalDeposit > 0 ? initalDeposit : 0.0 }
	{
		activeAccounts++;
		totalBankVault += balance;

	}
	BankAccount(string ow) : BankAccount{ ow,0.0 } {};
	~BankAccount() {
		activeAccounts--;
		totalBankVault -= balance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			totalBankVault += amount;

		}
	}
	static double getBankVault() { return totalBankVault; }
	static double getActiveAccounts() { return activeAccounts; }


};

int main() {
	cout << BankAccount::getBankVault() << "";
	BankAccount a1{ "Andriry", 1000.0 };
	BankAccount a2{ "Olrna", 1000.0 };
	a1.deposit(500.0);
	cout << BankAccount::getBankVault() << "";
}