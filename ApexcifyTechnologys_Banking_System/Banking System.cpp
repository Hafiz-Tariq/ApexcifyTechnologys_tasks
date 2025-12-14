#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;

//class to store transaction history(statement) of an account
class transactionHistory {
	private:
		double amount;
		string type;
		string details;

	public:
		//constructor
		transactionHistory() {  
			amount = 0.0;
			type = "";
			details = "";
		}
		// destructor
		~transactionHistory() {} 

		// setters and getters
		void setAmount(double amt) {
			amount = amt;
		}
		double getAmount() const {
			return amount;
		}
		void setType(string t) {
			type = t;
		}
		string getType() {
			return type;
		}
		void setDetails(string det) {
			details = det;
		}
		string getDetails() {
			return details;
		}
};

// class to handle transactions of an account
class transaction {
	private:
		vector<transactionHistory> history;
		double balance;

	public:
		// constructor
		transaction() { 
			balance = 0.0;
		}
		// destructor
		~transaction() {} 
		
		// function to add a transaction to transaction history
		void addTransaction(string type, double amount, string details) {
			transactionHistory tH;
			tH.setType(type);
			tH.setAmount(amount);
			tH.setDetails(details);
			history.push_back(tH);	
		}
		// function to deposit money
		void deposit() {
			double amount;
			cout << "\nEnter amount to deposit: ";
			cin >> amount;
			balance += amount;
			addTransaction("Deposit", amount, "Deposited to account");
		}
		// function to withdraw money
		void withdraw() {
			double amount;
			cout << "\nEnter amount to withdraw: ";
			cin >> amount;
			if (amount > balance) {
				cout << "\nInsufficient balance!" << endl;
			} else {
				balance -= amount;
				addTransaction("Withdrawal", amount, "Withdrawn from account");
			}
		}
		// function to transfer money
		void transfer() {
			double amount = 0.0;
			string toAccount;
			cout << "\nEnter account number to transfer to: ";
			cin >> toAccount;
			cout << "\nEnter amount to transfer: ";
			cin >> amount;
			if (amount > balance) {
				cout << "\nInsufficient balance!" << endl;
			} else {
				balance -= amount;
				addTransaction("Transfer", amount, "Transferred to account: " + toAccount);
			}
		}
		// function to check balance
		void checkBalance() const {
			cout << "\nCurrent balance: " << balance << endl;
		}
		// function to display transaction history
		void displayTransactions() {
			for (int i = 0; i < history.size(); i++) {
				cout << "Type: " << history[i].getType() << ", Amount: " << history[i].getAmount() << ", Details: " << history[i].getDetails() << endl;	
			}
		}

};

// class to represent a bank account
class account : public transaction{
	private:
		long accountNumber;

	public:
		// constructor
		account() {
			accountNumber = 0;
		}
		// destructor
		~account() {}

		// function to create account with unique account number
		void createAccount(int i) {
			long aacountGenerator = 11111110; // Simple account number generator
			accountNumber = aacountGenerator + i;
			cout << "account created with account number: " << accountNumber << endl;
		}
		// function to show account information
		void showInfo() {
			cout << "\nAccount Number: " << accountNumber;
			checkBalance();
			cout << "Recent Transactions:" << endl;
			displayTransactions();
		}
 };

// class to represent a customer
class customer {
	private:
		string name;

	public:
		// constructor
		customer() {
			name = "";
		}
		// destructor
		~customer(){}

		// setters and getters
		void setName(string n) {
			name = n;
		}
		string getName() {
			return name;
		}

		// function to show customer information
		void showCustomer() const {
			cout << "\nCustomer Name: " << name << endl;

		}
};


int main() {
	// create variables for customer and accounts
	string choice;
	string name;
	customer c1;
	account c1a1;
	account c1a2;

	// create customer and accounts
	cout << "Enter customer name to create account: ";
	getline(cin, name);
	c1.setName(name);
	cout << "\nFirst ";
	c1a1.createAccount(1);
	cout << "\nSecond ";
	c1a2.createAccount(2);

	// main menu loop
	while (true) {
		// display main menu
		cout << "\n\n-----------MENU-----------";
		cout << "\n1. Manage first account: ";
		cout << "\n2. Manage second account: ";
		cout << "\n3. Exit.\n";
		cin >> choice;
		
		// first account menu loop
		if (choice == "1") {
			while (true) {
				// display first account menu
				cout << "\n\n---FIRST_ACCOUNT_MENU---";
				cout << "\n1. Deposit.";
				cout << "\n2. Withdraw.";
				cout << "\n3. Transfer";
				cout << "\n4. Check Balance.";
				cout << "\n5. Check Statement.";
				cout << "\n6. Back to Main Menu.\n";
				cin >> choice;
				if (choice == "1") {
					c1a1.deposit();
				}
				else if (choice == "2") {
					c1a1.withdraw();
				}
				else if (choice == "3") {
					c1a1.transfer();
				}
				else if (choice == "4") {
					c1a1.checkBalance();
				}
				else if (choice == "5") {
					c1.showCustomer();
					c1a1.showInfo();
				}
				else if (choice == "6") {
					break;
				}
				else {
					cout << "\nInvalid choice. Try again.";
				}
			}
		}

		// second account menu loop
		else if (choice == "2") {
			while (true) {
				// display second account menu
				cout << "\n\n---SECOND_ACCOUNT_MENU---";
				cout << "\n1. Deposit.";
				cout << "\n2. Withdraw.";
				cout << "\n3. Transfer";
				cout << "\n4. Check Balance.";
				cout << "\n5. Check Statement.";
				cout << "\n6. Back to Main Menu.\n";
				cin >> choice;
				if (choice == "1") {
					c1a2.deposit();
				}
				else if (choice == "2") {
					c1a2.withdraw();
				}
				else if (choice == "3") {
					c1a2.transfer();
				}
				else if (choice == "4") {
					c1a2.checkBalance();
				}
				else if (choice == "5") {
					c1.showCustomer();
					c1a2.showInfo();
				}
				else if (choice == "6") {
					break;
				}
				else {
					cout << "\nInvalid choice. Try again.";
				}
			}
		}
		else if (choice == "3") {
			break;
		}
		else {
			cout << "\nInvalid choice. Try again.";
		}
	}

	return 0;
}