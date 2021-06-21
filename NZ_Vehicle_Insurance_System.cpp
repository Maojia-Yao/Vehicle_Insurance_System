// NZ_Vehicle_Insurance_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
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
	int car_value;
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
	string first_name;
	string last_name;
	string date;
	string time;
	char description[200];
	char detail[200];
	string contact_no;
	string email;
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
void insurancePolicy();
void claimRegistration();
void renewalScreen();
void benefitScreen();
void policyRegistration(int);

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

	cout << "\nMain Menu :\n";
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
		ifstream file("Customer_registration.txt", ios::in | ios::binary);

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

void customerScreen()
{
	int choice;
	while (true)
	{
		cout << "\nCustomer Screen :\n";
		cout << "\n1. Policy and insurance application process";
		cout << "\n2. Claim";
		cout << "\n3. Renewal";
		cout << "\n4. Benefits of NZ insurance";
		cout << "\n5. Exit";

		cin >> choice;
		string dummy;
		getline(cin, dummy);

		if (choice == 1) insurancePolicy();
		else if (choice == 2) claimRegistration();
		else if (choice == 3) renewalScreen();
		else if (choice == 4) benefitScreen();
		else if (choice == 5) break;
	}
}

void benefitScreen()
{
	cout << "\nNew sign-up discounts";
	cout << "\nMulti policy discount";
	cout << "\nRenewal discount";
	cout << "\ndiscount for reviewing the insurance and introducing friends or family discount";
}

void policyRegistration(int policy_num) {

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

	cout << "\nEnter your first name : ";
	cin >> p.first_name;
	cout << "\nEnter your last name : ";
	cin >> p.last_name;
	cout << "\nEnter your date of birth (dd/mm/yyyy) : ";
	cin >> p.dob;
	cout << "\nEnter your gender : ";
	cin >> p.gender;
	cout << "\nEnter your phone number : ";
	cin >> p.contact_no;
	cout << "\nEnter your email address : ";
	cin >> p.email;
	cout << "\nEnter your home address : ";
	cin >> p.address;
	cout << "\nEnter your vehicle registration number : ";
	cin >> p.vehicleRegNumber;
	cout << "\nEnter your vehicle name : ";
	cin >> p.vehicle_name;
	cout << "\nEnter your vehicle model : ";
	cin >> p.model;
	cout << "\nEnter how much you want to insure your car for : ";
	cin >> p.car_value;

	policies.open("policies.dat", ios::out | ios::app | ios::binary);

	policies.write(reinterpret_cast<char*>(&p), sizeof(p));

	policies.close();
}

void claimRegistration()
{
	char restart, end;
	fstream policies, claims;
	Claim claim;

	do
	{
		Claim claim;
		Policy p;



		cout << "\nEnter your policy number : ";
		cin >> claim.policy_no;

		policies.open("policies.dat", ios::in | ios::binary);

		while (policies.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			if (p.policy_no = claim.policy_no)
			{
				policies.read(reinterpret_cast<char*>(&p), sizeof(p));
				claim.first_name = p.first_name;
				claim.last_name = p.last_name;
				claim.email = p.email;
				claim.contact_no = p.contact_no;
			}
		}
		policies.close();
		cout << "Enter the date of the incident";
		cin >> claim.date;
		cout << "Enter the time of the incident";
		cin >> claim.time;
		cout << "Enter the incident description (200 character limit): ";
		cin.ignore();
		cin.getline(claim.description, 200);
		cout << "Enter the complaint details (200 character limit) : ";
		cin.getline(claim.detail, 200);


		cout << "\n\nSummary of Claim\n----------------\n\n";
		cout << "Policy Number : " << claim.policy_no << "\n";
		cout << "Name : " << claim.first_name << " " << claim.last_name << "\n";
		cout << "Date of incident : " << claim.date << "\n";
		cout << "Time of incident : " << claim.time << "\n";
		cout << "Claim Description : ";
		for (int i = 0; i < strlen(claim.description); i++)
		{
			cout << claim.description[i];
		}
		cout << "\n\nComplaint detail : ";
		for (int i = 0; i < strlen(claim.detail); i++)
		{
			cout << claim.detail[i];
		}
		cout << "\n\nPhone number : " << claim.contact_no << "\n";
		cout << "Email address : " << claim.email << "\n";

		cout << "\n\nIs this information correct? (y/n) : ";
		cin >> restart;
		if (tolower(restart) != 'y')
		{
			cout << "\nWould you like to re-enter you're details (y/n) : ";
			cin >> end;
			if (tolower(end) != 'y')
			{
				break;
			}
		}

	} while (tolower(restart) != 'y');

	if (tolower(restart) != 'y')
	{
		claims.open("claims.dat", ios::out | ios::app | ios::binary);
		claims.write(reinterpret_cast<char*>(&claim), sizeof(claim));
		claims.close();
	}
}

void adminScreen()
{
	int choice;
	fstream file;
	Customer customer;
	Claim claim;
	Renewal renewals;
	
	do
	{
		int i = 1;
		cout << "\n\tAdmin Screen\n\t------------\n\n";
		cout << " 1. Customer report\n";
		cout << " 2. Weekly claim report\n";
		cout << " 3. Weekly renewal report\n";
		cout << " 4. Weekly new registration report\n";
		cout << " 5. Update policy information and publish the special discounts\n";
		cout << " 6. Exit\n";

		cout << "\nPlease enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n\tList of customers\n\t-----------------\n\n";
			file.open("Customer_registration.txt", ios::in | ios::binary);
			while (!file.eof())
			{
				cout << "Customer " << i << " : ";
				file >> customer.first_name;
				file >> customer.last_name;
				cout << "\nName : " << customer.first_name << " " << customer.last_name;
				file >> customer.dob;
				cout << "\nDate of birth : " << customer.dob;
				file >> customer.gender;
				cout << "\nGender : " << customer.gender;
				file >> customer.contact_no;
				cout << "\nContact Number : " << customer.contact_no;
				file >> customer.email;
				cout << "\nEmail : " << customer.email;
				file >> customer.address;
				cout << "\nAddress : " << customer.address;
				file >> customer.vehicleRegNumber;
				cout << "\nVehicle registration number : " << customer.vehicleRegNumber;
				file >> customer.username;
				cout << "\nUsername : " << customer.username;
				file >> customer.password;
				cout << "\n\n";
				i++;
			}
			file.close();
			system("pause");
			break;

		}
		case 2:
		{
			cout << "\n\tWeekly claim report\n\t---------------------\n\n";
			file.open("claims.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&claim), sizeof(claim)))
			{
				cout << "Claim number " << i << " : ";
				cout << "\nPolicy number : " << claim.policy_no;
				cout << "\nFull Name : " << claim.first_name << " " << claim.last_name;
				cout << "\nDate of incident : " << claim.date;
				cout << "\nTime of incident : " << claim.time;
				cout << "\nIncident description : " << claim.description;
				cout << "\n\nComplaint Details : " << claim.detail;
				cout << "\n\nContact Number : " << claim.contact_no;
				cout << "\nEmail : " << claim.email;
				cout << "\n\n";
				i++;
			}
			file.close();
			break;
		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6: break;
		default:
			cout << "Please enter a valid choice"; break;
		}
	} while (choice != 6);

}