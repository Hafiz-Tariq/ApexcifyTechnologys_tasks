#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using std::string;

//function declarations

//check if user exists
bool checkUser(string userName);

//register new user name
string registerUser(string userName);

//register password for new user
void registerPassword(string userName, string password);

//login existing user
string loginUser(string userName);

//login password for existing user
void loginPassword(string userName, string password);


//main function
int main() {
	string userName, password;
	string choice;

	while (true) {
		cout << "\nWelcome! Select from Menu: ";
		cout << "\n<-------------------MENU------------------->\n";
		cout << "1. Register\n";
		cout << "2. Login\n";
		cout << "3. Exit\n";
		cout << "-------------------------------------------\n";
		cout << "press q to get back at menu\n";
		cout << "Enter your choice (1/2/3/): ";
		cin >> choice;
		
		if(choice == "1") {
			userName = registerUser(userName);
			if (userName == "") {
				continue;
			}
			registerPassword(userName, password);
		}
		else if(choice == "2") {
			userName = loginUser(userName);
			if (userName == "") {
				continue;
			}
			loginPassword(userName, password);
		}
		else if(choice == "3") {
			cout << "Exiting the program. Goodbye!\n";
			break;
		}
		else {
			cout << "\nInvalid choice. Please select 1, 2, or 3.\n";
		}
	}


	return 0;
}


//function definitions

bool checkUser(string userName) {
	string fileName = userName + ".txt";
	ifstream file(fileName);
	return file.good();
}

string registerUser(string userName) {

	cout << "UserName should not include any spaces.\n";
	cout << "Enter your UserName: ";
	cin >> userName;

	if (userName == "q") {
		return "";
	}
	if (checkUser(userName)) {
		cout << "\nSorry, UserName already exists, Try another username: ";
		return registerUser(userName);
	}
	else {
		string fileName = userName + ".txt";
		ofstream file(fileName);
		return userName;
	}
}

void registerPassword(string userName, string password) {

	cout << "Enter your Password: ";
	cin >> password;

	if(password == "q") {
		return;
	}
	if (password.length() < 6) {
		cout << "Password must be at least 6 characters long.\n";
		registerPassword(userName, password);
	}
	else {
		string fileName = userName + ".txt";
		ofstream file(fileName);
		file << password;
		cout << "Registration Successful!\n";
		file.close();
	}
}

string loginUser(string userName) {

	cout << "Enter your UserName: ";
	cin >> userName;

	if(userName == "q") {
		return "";
	}
	if (!checkUser(userName)) {
		cout << "UserName does not exist. Please register first.\n";
		return loginUser(userName);
	}
	else {
		string fileName = userName + ".txt";
		ifstream file(fileName);
		return userName;
	}
}

void loginPassword(string userName, string password) {

	cout << "Enter your Password: ";
	cin >> password;

	string fileName = userName + ".txt";
	ifstream file(fileName);
	string storedPassword;
	getline(file, storedPassword);

	if(password == "q") {
		return;
	}
	if (password != storedPassword) {
		cout << "Incorrect Password. Try again.\n";
		loginPassword(userName, password);
	}
	else {
		cout << "Login Successful!\n";
	}
}



