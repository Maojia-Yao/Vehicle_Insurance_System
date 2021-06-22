// NZ_Vehicle_Insurance_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//structure definition
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

//function declaration
int main_menu();
void customerRegistration(struct Customer&);
void customerLogin(string, string);
void customerScreen();
void adminLogin();
void adminScreen();
void insurancePolicy();
void claimRegistration();
void renewalScreen();
void benefitScreen();
void policyRegistration(int);

void adminLogin();


int main()
{
	struct Customer customer;
	string s_username, s_password;

	cout << "\n\t\t\t\t\tWelcome to NZ Vehicle Insurance System\n";
	cout << "\n\t\t\t\t******************************************************\n";

	while (true)
	{
		int choice = main_menu();
		if (choice == 1) customerRegistration(customer);
		else if (choice == 2) customerLogin(s_username, s_password);
		else if (choice == 3) adminLogin();
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

	cout << "\n\t\t\t\t\t\t Main Menu\n";
	cout << "\n\t\t\t\t\t1 Customer registration";
	cout << "\n\t\t\t\t\t2 Customer login";
	cout << "\n\t\t\t\t\t3 Administrator login";
	cout << "\n\t\t\t\t\t4 Insurance company info and contact details";
	cout << "\n\t\t\t\t\t5 Exit";
	cout << "\n\nPlease select an option from the menu: ";
	cin >> choice;
	return choice;
}

void customerRegistration(struct Customer& customer)
{
	cout << "\n\t\t\t\t\t\t Customer Registration\n";
	cout << "\n\t\t\t\t\tEnter your first name : ";
	cin >> customer.first_name;
	cout << "\n\t\t\t\t\tEnter your last name : ";
	cin >> customer.last_name;
	cout << "\n\t\t\t\t\tEnter your date of birth : ";
	cin >> customer.dob;
	cout << "\n\t\t\t\t\tEnter your gender : ";
	cin >> customer.gender;
	cout << "\n\t\t\t\t\tEnter your contact number : ";
	cin >> customer.contact_no;
	cout << "\n\t\t\t\t\tEnter your email : ";
	cin >> customer.email;
	cout << "\n\t\t\t\t\tEnter your physical address : ";
	cin >> customer.address;
	cout << "\n\t\t\t\t\tEnter your vehicle registration number : ";
	cin >> customer.vehicleRegNumber;
	cout << "\n\t\t\t\t\tEnter your username: ";
	cin >> customer.username;
	cout << "\n\t\t\t\t\tEnter your password: ";
	cin >> customer.password;

	//write into file
	ofstream file("Customer_Registration.txt", ios::out | ios::app | ios::binary);

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

void customerLogin(string s_username, string s_password)
{
	Customer customer;
	int chance = 3;

	while (chance > 0)
	{
		chance--;
		cout << "\n\t\t\t\t\t\t Customer Login\n";
		cout << "\n\t\t\t\t\tEnter your username: ";
		cin >> s_username;
		cout << "\n\t\t\t\t\tEnter your password: ";
		cin >> s_password;

		//opening the file in read mode
		ifstream file("Customer_registration.txt", ios::in | ios::binary);

		bool loginSucceeded = false;
		while (!file.eof())
		{
			// reading the content from the file
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

			//checking whether the login is successful by username and password
			if (s_username == customer.username && s_password == customer.password)
			{
				loginSucceeded = true;
				customerScreen();
				break;
			}
		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\nUsername or password is wrong, you can't login again. Please try it again after 30 minutes";
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "\nUsername or password is wrong, please enter again.";
			continue;
		}
		else
		{
			cout << "\nLogin successfully!";
			break;
		}
	}
}

void adminLogin()
{
	string username, password;
	string u_username, p_password;
	int chance = 3;

	while (chance > 0)
	{
		chance--;
		cout << "\n\t\t\t\t\t\t Administrator Login\n";
		cout << "\n\t\t\t\t\tEnter your username: ";
		cin >> username;
		cout << "\n\t\t\t\t\tEnter your password: ";
		cin >> password;

		//opening the file in read mode
		ifstream file("administrators.txt", ios::in | ios::binary);

		bool loginSucceeded = false;
		if (file.is_open())
		{
			while (!file.eof())
			{
				// reading the content from the file
				file >> u_username;
				file >> p_password;

				//checking whether the login is successful by username and password
				if (username == u_username && password == p_password)
				{
					loginSucceeded = true;
					adminScreen();
					break;
				}
			}
		}
		else
		{
			cout << "\nFile unable to access...";

		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\nUsername or password is wrong, you can't login again. Please try it again after 30 minutes";
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "\nUsername or password is wrong, please enter again.";
			continue;
		}
		else
		{
			cout << "\nLogin successfully!";
			break;
		}
	}
}

void customerScreen()
{
	int choice;

	while (true)
	{
		cout << "\n\t\t\t\t\t\t Customer Screen\n";
		cout << "\n\t\t\t\t\t1. Policy and insurance application process";
		cout << "\n\t\t\t\t\t2. Claim";
		cout << "\n\t\t\t\t\t3. Renewal";
		cout << "\n\t\t\t\t\t4. Benefits of NZ insurance";
		cout << "\n\t\t\t\t\t5. Exit";
		cin >> choice;

		if (choice == 1) insurancePolicy();
		else if (choice == 2) claimRegistration();
		else if (choice == 3) renewalScreen();
		else if (choice == 4) benefitScreen();
		else if (choice == 5) break;
	}
}

void benefitScreen()
{
	cout << "\n\t\t\t\t\t\t Benefits Screen\n";
	cout << "\n\t\t\t\t\tNew sign-up discounts";
	cout << "\n\t\t\t\t\tMulti policy discount";
	cout << "\n\t\t\t\t\tRenewal discount";
	cout << "\n\t\t\t\t\tdiscount for reviewing the insurance and introducing friends or family discount";
}

void policyRegistration(int policy_num) 
{
	cout << "\n\t\t\t\t\t\t Policy Registration\n";
	Policy p;
	fstream policies;
	int temp_num = 100 + policy_num;
	bool check = true;

	policies.open("policies.dat", ios::in | ios::binary);

	while (check == true)
	{
		check = false;
		while (policies.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			if (p.policy_no = temp_num)
			{
				cout << temp_num;
				temp_num += 100;
				check = true;
			}
		}
	}

	p.policy_no = temp_num;

	policies.close();

	cout << "\n\t\t\t\t\tEnter your first name : ";
	cin >> p.first_name;
	cout << "\n\t\t\t\t\tEnter your last name : ";
	cin >> p.last_name;
	cout << "\n\t\t\t\t\tEnter your date of birth (dd/mm/yyyy) : ";
	cin >> p.dob;
	cout << "\n\t\t\t\t\tEnter your gender : ";
	cin >> p.gender;
	cout << "\n\t\t\t\t\tEnter your phone number : ";
	cin >> p.contact_no;
	cout << "\n\t\t\t\t\tEnter your email address : ";
	cin >> p.email;
	cout << "\n\t\t\t\t\tEnter your home address : ";
	cin >> p.address;
	cout << "\n\t\t\t\t\tEnter your vehicle registration number : ";
	cin >> p.vehicleRegNumber;
	cout << "\n\t\t\t\t\tEnter your vehicle name : ";
	cin >> p.vehicle_name;
	cout << "\n\t\t\t\t\tEnter your vehicle model : ";
	cin >> p.model;

	policies.open("policies.dat", ios::out | ios::app | ios::binary);

	policies.write(reinterpret_cast<char*>(&p), sizeof(p));

	policies.close();
}
