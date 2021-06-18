// NZ_Vehicle_Insurance_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Customer
{
	string first_name;
	string last_name;
	string dob;
	string gender;
	string contact_no;
	string email;
	string address;
	string vehicleRegNumber;
	string username;
	string password;
};

struct Administrator
{
	string username;
	string password;
};

struct Policy
{
	int policy_no;
	string first_name;
	string last_name;
	string dob;
	string gender;
	string contact_no;
	string email;
	string address;
	string vehicleRegNumber;
	string vehicle_name;
	string model;
};

struct Claim
{
	int policy_no;
	string full_name;
	string date;
	string time;
	string description;
	string detail;
	string contact;
};

struct Renewal
{
	string description;
	int policy_no;
	string full_name;
	string new_policy_name;
	string contact_no;
	string visa_card_no;
};

int main_menu();
void customerRegistration();
void customerLogin();
void customerScreen();
void adminScreen();

int main()
{
	cout << "Welcome to NZ Vehicle Insurance System" << endl;

	while (true)
	{
		int choice = main_menu();
		if (choice == 1) customerRegistration();
		else if (choice == 2) customerLogin();
		else if (choice == 3) adminScreen();
		else if (choice == 4)
		{
			cout << "Insurance company information and contact details" << endl;
		}
		else if (choice == 5) break;
	}

	cout << "\n\n";
	return 0;
}

int main_menu()
{
	int choice;

	cout << "\nMain Menu:";
	cout << "\n1 Customer registration";
	cout << "\n2 Customer login";
	cout << "\n3 Administration login";
	cout << "\n4 Insurance company info and contact details";
	cout << "\n5 Exit";
	cout << "\nPlease select an option from the menu: ";
	cin >> choice;

	string dummy;
	getline(cin, dummy);

	return choice;
}

void customerRegistration()
{
	Customer customer;

	cout << "\nCustomer Registration :\n";

	cout << "\nEnter your first name : ";
	cin >> customer.first_name;
	cout << "\nEnter your last name : ";
	cin >> customer.last_name;
	cout << "\nEnter your date of birth : ";
	cin >> customer.dob;
	cout << "\nEnter your gender : ";
	cin >> customer.gender;
	cout << "\nEnter your contact number : ";
	cin >> customer.contact_no;
	cout << "\nEnter your email : ";
	cin >> customer.email;
	cout << "\nEnter your physical address : ";
	cin >> customer.address;
	cout << "\nEnter your vehicle registration number : ";
	cin >> customer.vehicleRegNumber;
	cout << "\nEnter your username: ";
	cin >> customer.username;
	cout << "\nEnter your password: ";
	cin >> customer.password;

	//input password again
	string dummy;
	getline(cin, dummy);

	//write into file
	ofstream file("Customer_Registration.txt", ios::out | ios::app);

	file << customer.first_name << endl;
	file << customer.last_name << endl;
	file << customer.dob << endl;
	file << customer.gender << endl;
	file << customer.contact_no << endl;
	file << customer.email << endl;
	file << customer.address << endl;
	file << customer.vehicleRegNumber << endl;
	file << customer.username << endl;
	file << customer.password << endl;

	file.close();
}

void customerLogin()
{
	Customer customer;
	string username, password;
	int chance = 3;

	while (chance > 0)
	{
		chance--;
		cout << "\nCustomer login:\n";
		cout << "\nEnter your username: ";
		cin >> username;
		cout << "\nEnter your password: ";
		cin >> password;
		string dummy;
		getline(cin, dummy);

		//opening the file in read mode
		ifstream file("Customer_registration.txt", ios::in);

		bool loginSucceeded = false;
		while (!file.eof())
		{
			file >> customer.first_name;
			file >> customer.last_name;
			file >> customer.dob;
			file >> customer.gender;
			file >> customer.contact_no;
			file >> customer.email;
			file >> customer.address;
			file >> customer.vehicleRegNumber;
			file >> customer.username;
			file >> customer.password;

			//check
			if (username == customer.username && password == customer.password)
			{
				loginSucceeded = true;
				break;
			}
		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\nUsername or password is wrong, you can't login again. Please try it again after 30 minutes" << endl;
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "Username or password is wrong, please enter again." << endl;
			continue;
		}
		else
		{
			cout << "Login successfully" << endl;
			break;
		}
	}

	customerScreen();
}

