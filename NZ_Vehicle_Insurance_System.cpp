// NZ_Vehicle_Insurance_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
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
	char address[50];
	string vehicleRegNumber;
	string username;
	string password;

	Customer()
	{
		strcpy_s(address, " ");
	}
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
	int monthly_cost;
	string first_name;
	string last_name;
	string dob;
	string gender;
	string contact_no;
	string email;
	char address[50];
	string vehicleRegNumber;
	string vehicle_name;
	string model;

	Policy()
	{
		policy_no = 0;
		car_value = 0;
		monthly_cost = 0;
		strcpy_s(address, " ");
	}
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

	Claim()
	{
		policy_no = 0;
		strcpy_s(description, " ");
		strcpy_s(detail, " ");
	}
};

struct Renewal
{
	int policy_no;
	string full_name;
	string new_policy_name;
	string contact_no;
	string visa_card_no;

	Renewal()
	{
		policy_no = 0;
	}
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
void policyRegistration(int, int, int);

int main()
{
	struct Customer customer;
	string username, password;

	cout << "\n\t\t\t\t\tWelcome to NZ Vehicle Insurance System\n";
	cout << "\n\t\t\t\t******************************************************\n";

	while (true)
	{
		int choice = main_menu();
		if (choice == 1) customerRegistration(customer);
		else if (choice == 2) customerLogin(username, password);
		else if (choice == 3) adminLogin();
		else if (choice == 4)
		{
			cout << "\n NZ Vehicle Insurance System have been helping New Zealanders with their insurance for more than 100 years.\n Today we manage around 900,000 policies for more than 400,000 Kiwis.\n In that time, we have worked hard to build up a pretty good understanding of New Zealanders' insurance needs.\n\n Contact us : 0800 802 424\n 8.00am - 6.00pm (Mon - Fri)\n 9.00am - 6.00pm (Sat - Sun & public holidays)\n\n";
		}
		else if (choice == 5) break;
	}

	cout << "\n\n";
	return 0;
}

int main_menu()
{
	int choice;

	cout << "\n\n\tMain Menu\n\t---------\n";
	cout << "\n 1 Customer registration";
	cout << "\n 2 Customer login";
	cout << "\n 3 Administrator login";
	cout << "\n 4 Insurance company info and contact details";
	cout << "\n 5 Exit";
	cout << "\n\n Please select an option from the menu : ";
	cin >> choice;
	return choice;
}

void customerRegistration(struct Customer& customer)
{
	cout << "\n\n\tCustomer Registration\n\t---------------------\n";
	cout << "\n Enter your first name : ";
	cin >> customer.first_name;
	cout << "\n Enter your last name : ";
	cin >> customer.last_name;
	cout << "\n Enter your date of birth : ";
	cin >> customer.dob;
	cout << "\n Enter your gender : ";
	cin >> customer.gender;
	cout << "\n Enter your contact number : ";
	cin >> customer.contact_no;
	cout << "\n Enter your email : ";
	cin >> customer.email;
	cin.ignore();
	cout << "\n Enter your physical address : ";
	cin.getline(customer.address, 50);
	cout << "\n Enter your vehicle registration number : ";
	cin >> customer.vehicleRegNumber;
	cout << "\n Enter your username: ";
	cin >> customer.username;
	cout << "\n Enter your password: ";
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

void customerLogin(string username, string password)
{
	Customer customer;
	int chance = 3;

	while (chance > 0)
	{
		chance--;
		cout << "\n\n\tCustomer Login\n\t--------------\n";
		cout << "\n Enter your username: ";
		cin >> username;
		cout << "\n Enter your password: ";
		cin >> password;

		//opening the file in read mode
		ifstream file("Customer_Registration.txt", ios::in | ios::binary);

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
			if (username == customer.username && password == customer.password)
			{
				loginSucceeded = true;
				break;
			}
		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\n Username or password is wrong, you can't login again. Please try it again after 30 minutes";
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "\n Username or password is wrong, please enter again.";
			continue;
		}
		else
		{
			cout << "\n Login successfully!\n";
			break;
		}

	}

	//display customer screen if the login is successful
	customerScreen();
}

void adminLogin()
{
	fstream file;
	string username, password;
	string u_username, p_password;
	int chance = 3;

	while (chance > 0)
	{
		chance--;
		cout << "\n\n\tAdministrator Login\n\t--------------\n";
		cout << "\n Enter your username: ";
		cin >> username;
		cout << "\n Enter your password: ";
		cin >> password;

		//opening the file in read mode
		file.open("administrators.txt", ios::in | ios::binary);

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
					break;
				}
			}
		}
		else
		{
			cout << "\n File unable to access...";

		}
		file.close();

		if (loginSucceeded == false && chance == 0)
		{
			cout << "\n Username or password is wrong, you can't login again. Please try it again after 30 minutes";
			return;
		}
		else if (loginSucceeded == false && chance > 0)
		{
			cout << "\n Username or password is wrong, please enter again.";
			continue;
		}
		else
		{
			cout << "\n Login successfully!";
			break;
		}
	}

	//display admin screen if the login is successful
	adminScreen();
}

void customerScreen()
{
	int choice;

	while (true)
	{
		cout << "\n\n\tCustomer Screen\n\t---------------\n";
		cout << "\n 1. Policy and insurance application process";
		cout << "\n 2. Claim";
		cout << "\n 3. Renewal";
		cout << "\n 4. Benefits of NZ insurance";
		cout << "\n 5. Exit";
		cout << "\n\n Please select an option from the menu: ";
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
	int choice;

	do
	{
		cout << "\n\n\tBenefits Screen\n\t---------------\n";
		cout << "\n 1. New sign-up discounts";
		cout << "\n 2. Multi policy discount";
		cout << "\n 3. Renewal discount";
		cout << "\n 4. Discount for reviewing the insurance and introducing friends or family discount";
		cout << "\n 5. Exit";
		cout << "\n\n Please select an option from the menu : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n If you are a new registered user and purchase insurance from our company\n for the first time, you will be able to enjoy a 10% discount.\n";
			break;
		}
		case 2:
		{
			cout << "\n Enjoy a multi-policy discount of up to 20%. When you take out more than\n one type of vehicle insurance with us, you may qualify for our multi policy discount.\n";
			break;
		}
		case 3:
		{
			cout << "\n There are also certain discounts for renewal policies. This discount is based on\n the driving situation and the risk situation in the previous year.\n You can get a 15% discount if you are in a good condition after evaluation.\n";
			break;
		}
		case 4:
		{
			cout << "\n Regarding policy review and introducing family and friends to purchase our vehicle insurance,\n you can get an additional 8% discount provided by our company.\n";
			break;
		}
		case 5: break;
		default:
		{
			cout << "\n Please enter a valid choice";
		}
		}
	} while (choice != 5);
}

void policyRegistration(int policy_num, int carvalue, int monthlycost)
{
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
				temp_num += 100;
				check = true;
			}
		}
	}
	policies.close();

	p.policy_no = temp_num;

	cout << "\n\n\tPolicy Registration\n\t-------------------\n";
	cout << "\n Enter your first name : ";
	cin >> p.first_name;
	cout << "\n Enter your last name : ";
	cin >> p.last_name;
	cout << "\n Enter your date of birth (dd/mm/yyyy) : ";
	cin >> p.dob;
	cout << "\n Enter your gender : ";
	cin >> p.gender;
	cout << "\n Enter your phone number : ";
	cin >> p.contact_no;
	cout << "\n Enter your email address : ";
	cin >> p.email;
	cin.ignore();
	cout << "\n Enter your home address : ";
	cin.getline(p.address, 50);
	cout << "\n Enter your vehicle registration number : ";
	cin >> p.vehicleRegNumber;
	cout << "\n Enter your vehicle name : ";
	cin >> p.vehicle_name;
	cout << "\n Enter your vehicle model : ";
	cin >> p.model;

	p.monthly_cost = monthlycost;
	p.car_value = carvalue;

	cout << "\n Policy saved";

	cout << "\n Policy number is : " << p.policy_no;

	policies.open("policies.dat", ios::out | ios::app | ios::binary);

	policies.write(reinterpret_cast<char*>(&p), sizeof(p));

	policies.close();
}

void claimRegistration()
{
	char restart, end;
	fstream policies, claims;
	Claim claim;
	bool policy_found;

	do
	{
		Claim claim;
		Policy p;
		policy_found = false;

		cout << "\n\n\tClaim Registration\n\t------------------\n";
		cout << "\n Enter your policy number : ";
		cin >> claim.policy_no;

		policies.open("policies.dat", ios::in | ios::binary);

		while (policies.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			if (p.policy_no == claim.policy_no)
			{
				policies.read(reinterpret_cast<char*>(&p), sizeof(p));
				claim.first_name = p.first_name;
				claim.last_name = p.last_name;
				claim.email = p.email;
				claim.contact_no = p.contact_no;
				policy_found = true;
			}
		}
		policies.close();

		if (policy_found)
		{
			cout << "\n Enter the date of the incident : ";
			cin >> claim.date;
			cout << "\n Enter the time of the incident : ";
			cin >> claim.time;
			cin.ignore();
			cout << "\n Enter the incident description (200 character limit) : ";
			cin.getline(claim.description, 200);
			cout << "\n Enter the complaint details (200 character limit) : ";
			cin.getline(claim.detail, 200);


			cout << "\n\tSummary of Claim\n\t----------------\n";
			cout << "\n Policy Number : " << claim.policy_no;
			cout << "\n Name : " << claim.first_name << " " << claim.last_name;
			cout << "\n Date of incident : " << claim.date;
			cout << "\n Time of incident : " << claim.time;
			cout << "\n Claim Description : " << claim.description;
			cout << "\n Complaint detail : " << claim.detail;
			cout << "\n Phone number : " << claim.contact_no;
			cout << "\n Email address : " << claim.email;

			cout << "\n\n Is this information correct? (y/n) : ";
			cin >> restart;
			if (tolower(restart) != 'y')
			{
				cout << "\n Would you like to re-enter your details (y/n) : ";
				cin >> end;
				if (tolower(end) != 'y')
				{
					break;
				}
			}
		}
		else
		{
			cout << "\n Policy number not found\n";
			return;
		}

	} while (tolower(restart) != 'y');

	if (tolower(restart) == 'y')
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
	Renewal r;

	do
	{
		int i = 1;
		cout << "\n\n\tAdmin Screen\n\t------------\n";
		cout << "\n 1. Customer report";
		cout << "\n 2. Weekly claim report";
		cout << "\n 3. Weekly renewal report";
		cout << "\n 4. Weekly new registration report";
		cout << "\n 5. Update policy information and publish the special discounts";
		cout << "\n 6. Exit";

		cout << "\n\n Please select an option from the menu : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "\n\tList of customers\n\t-----------------\n";
			file.open("Customer_Registration.txt", ios::in | ios::binary);

			while (file.peek() != EOF)
			{

				cout << "\n Customer " << i << " : ";
				file >> customer.first_name;
				file >> customer.last_name;
				cout << "\n Name : " << customer.first_name << " " << customer.last_name;
				file >> customer.dob;
				cout << "\n Date of birth : " << customer.dob;
				file >> customer.gender;
				cout << "\n Gender : " << customer.gender;
				file >> customer.contact_no;
				cout << "\n Contact Number : " << customer.contact_no;
				file >> customer.email;
				cout << "\n Email : " << customer.email;
				file >> customer.address;
				cout << "\n Address : " << customer.address;
				file >> customer.vehicleRegNumber;
				cout << "\n Vehicle registration number : " << customer.vehicleRegNumber;
				file >> customer.username;
				cout << "\n Username : " << customer.username;
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
			cout << "\n\tWeekly claim report\n\t---------------------\n";
			file.open("claims.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&claim), sizeof(claim)))
			{
				cout << "\n Claim number " << i << " : ";
				cout << "\n Policy number : " << claim.policy_no;
				cout << "\n Full Name : " << claim.first_name << " " << claim.last_name;
				cout << "\n Date of incident : " << claim.date;
				cout << "\n Time of incident : " << claim.time;
				cout << "\n Incident description : " << claim.description;
				cout << "\n\n Complaint Details : " << claim.detail;
				cout << "\n\n Contact Number : " << claim.contact_no;
				cout << "\n Email : " << claim.email;
				cout << "\n\n";
				i++;
			}
			file.close();
			break;
		}
		case 3:
		{
			cout << "\n\tList of renewals\n\t-----------------\n";
			file.open("renewals.dat", ios::in | ios::binary);

			while (file.read(reinterpret_cast<char*>(&r), sizeof(r)))
			{
				cout << "\n Policy number : " << r.policy_no;
				cout << "\n Full name : " << r.full_name;
				cout << "\n Policy changes : " << r.new_policy_name;
				cout << "\n Contact number" << r.contact_no;
				cout << "\n Visa card number : " << r.visa_card_no;
				cout << "\n\n";
			}


		}
		case 4:
		{
			cout << "\n\tList of customers\n\t-----------------\n";
			file.open("Customer_Registration.txt", ios::in | ios::binary);

			while (file.peek() != EOF)
			{

				cout << "\n Customer " << i << " : ";
				file >> customer.first_name;
				file >> customer.last_name;
				cout << "\n Name : " << customer.first_name << " " << customer.last_name;
				file >> customer.dob;
				cout << "\n Date of birth : " << customer.dob;
				file >> customer.gender;
				cout << "\n Gender : " << customer.gender;
				file >> customer.contact_no;
				cout << "\n Contact Number : " << customer.contact_no;
				file >> customer.email;
				cout << "\n Email : " << customer.email;
				file >> customer.address;
				cout << "\n Address : " << customer.address;
				file >> customer.vehicleRegNumber;
				cout << "\n Vehicle registration number : " << customer.vehicleRegNumber;
				file >> customer.username;
				cout << "\n Username : " << customer.username;
				file >> customer.password;
				cout << "\n\n";

				i++;
			}
			break;
		}
		case 5:
		{
			cout << "Work in progress...\n";
			break;
		}
		case 6: break;
		default:
			cout << "\n Please enter a valid choice"; break;
		}
	} while (choice != 6);
}

void renewalScreen() {

	fstream file, r_file;
	Policy p;
	Renewal r;
	int choice;
	int policy_num;
	char change;

	do
	{
		bool found = false;
		cout << "\n\n\tPolicy Renewal / Changes\n\t------------------------\n";
		cout << "\n 1. Renewal";
		cout << "\n 2. Policy change";
		cout << "\n 3. Exit";
		cout << "\n\n Please enter your choice : ";
		cin >> choice;
		if (choice == 1 || choice == 2)
		{
			cout << "\n Please enter your policy number : ";
			cin >> policy_num;
		}
		switch (choice)
		{
		case 1:
			cout << "\n\n\tCurrent Policy";
			file.open("policies.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&p), sizeof(p)))
			{
				if (p.policy_no == policy_num)
				{
					cout << "\n First name : " << p.first_name;
					cout << "\n Last name : " << p.last_name;
					cout << "\n Date of birth : " << p.dob;
					cout << "\n Gender : " << p.gender;
					cout << "\n Phone number : " << p.contact_no;
					cout << "\n Email address : " << p.email;
					cout << "\n Home address : " << p.address;
					cout << "\n Vehicle registration number : " << p.vehicleRegNumber;
					cout << "\n Vehicle name : " << p.vehicle_name;
					cout << "\n Vehicle model : " << p.model;
					cout << "\n Monthly cost : " << p.monthly_cost;
					cout << "\n Car value : " << p.car_value;
					found = true;
					cout << "\n\n Would you like to renew this policy (y/n) : ";
					cin >> change;
					if (tolower(change) == 'y')
					{
						r_file.open("renewals.dat", ios::binary | ios::out | ios::app);

						r.policy_no = policy_num;
						r.full_name = p.first_name + " " + p.last_name;
						cout << "\n Enter the Enxtended policy date : ";
						cin >> r.new_policy_name;
						r.contact_no = p.contact_no;
						cout << "\n Enter your visa card number : ";
						cin >> r.visa_card_no;

						r_file.write(reinterpret_cast<char*>(&r), sizeof(r));
						r_file.close();

						cout << "\n One of our staff will contact you to confirm these changes\n\n";
						break;
					}
				}

			}
			if (!found)
			{
				cout << "\n Policy number not found\n";
			}
			file.close();
			break;
		case 2:
		{
			cout << "\n\n\tCurrent Policy";
			file.open("policies.dat", ios::binary | ios::in);
			while (file.read(reinterpret_cast<char*>(&p), sizeof(p)))
			{
				if (p.policy_no == policy_num)
				{
					cout << "\n First name : " << p.first_name;
					cout << "\n Last name : " << p.last_name;
					cout << "\n Date of birth : " << p.dob;
					cout << "\n Gender : " << p.gender;
					cout << "\n Phone number : " << p.contact_no;
					cout << "\n Email address : " << p.email;
					cout << "\n Home address : " << p.address;
					cout << "\n Vehicle registration number : " << p.vehicleRegNumber;
					cout << "\n Vehicle name : " << p.vehicle_name;
					cout << "\n Vehicle model : " << p.model;
					cout << "\n Monthly cost : " << p.monthly_cost;
					cout << "\n Car value : " << p.car_value;
					found = true;

					cout << "\n\n Would you like to change this policy (y/n) : ";
					cin >> change;
					if (tolower(change) == 'y')
					{
						r_file.open("renewals.dat", ios::binary | ios::out | ios::app);

						r.policy_no = policy_num;
						r.full_name = p.first_name + " " + p.last_name;
						cout << "\n Enter the policy change : ";
						cin >> r.new_policy_name;
						r.contact_no = p.contact_no;
						cout << "\n Enter your visa card number : ";
						cin >> r.visa_card_no;

						r_file.write(reinterpret_cast<char*>(&r), sizeof(r));
						r_file.close();
						cout << "\n\n One of our staff will contact you to confirm these changes\n\n";
						break;
					}
				}
			}
			if (!found)
			{
				cout << "\n Policy number not found\n";
			}
			file.close();
			break;

		}
		case 3: break;
		default: cout << "\n Invalid Input\n"; break;
		}
	} while (choice != 3);

}

void insurancePolicy()
{
	int vehicle_type = 1, policy_type = 1, car_value, monthly_cost;
	char confirm;

	cout << "\n\n\tInsurance Policy\n\t----------------\n";

	do
	{
		cout << "\n Which type of vehicle would you like to insure?\n";
		cout << "\n 1. Car";
		cout << "\n 2. Motorcycle";
		if (vehicle_type != 1 && vehicle_type != 2)
		{
			cout << "\n\n Please select 1 or 2";
		}
		cout << "\n\n Please enter your choice : ";
		cin >> vehicle_type;
	} while (vehicle_type != 1 && vehicle_type != 2);


	do
	{
		cout << "\n\n Which type of insurance would you like?\n";
		cout << "\n 1. Full, Comprehensive Cover";
		cout << "\n 2. 3rd Party Fire and Theft";
		if (policy_type != 1 && policy_type != 2)
		{
			cout << "\n\n Please select 1 or 2\n\n";
		}
		cout << "\n\n Please enter your choice : ";
		cin >> policy_type;
	} while (policy_type != 1 && policy_type != 2);


	cout << "\n\n Please enter the value of your vehicle : $";
	cin >> car_value;

	monthly_cost = (car_value / 8) / 12;

	cout << "\n Summary : \n Vehicle type : ";

	switch (vehicle_type)
	{
	case 1:
	{
		cout << "\n Car\n Policy type : ";
		switch (policy_type)
		{
		case 1: {
			monthly_cost *= (int)1.8;
			cout << "\n Full, Comprehensive Cover";
			break;
		}
		case 2: {
			monthly_cost *= (int)1.7;
			cout << "\n 3rd Party Fire and Theft";
			break;
		}
		default: cout << "\n Error\n"; return;
		}
		break;

	}
	case 2:
	{
		cout << "\n Motorcycle\n Policy type : ";

		switch (policy_type)
		{
		case 1: {
			monthly_cost *= (int)1.2;
			cout << "\n Full, Comprehensive Cover";
			break;
		}
		case 2: {
			monthly_cost *= (int)1.1;
			cout << "\n 3rd Party Fire and Theft";
			break;
		}
		default: cout << "\n Error\n"; return;
		}
		break;
	}
	default: cout << "\n Error\n"; return;
	}
	cout << "\n Car value : $" << car_value;
	cout << "\n Monthly cost : $" << monthly_cost;

	cout << "\n\n Do you wish to purchase this policy? (y/n) : ";
	cin >> confirm;
	if (tolower(confirm) == 'y')
	{
		policyRegistration(vehicle_type * 10 + policy_type, car_value, monthly_cost);
	}
}
