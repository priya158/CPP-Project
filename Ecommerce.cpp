#include "project.h"

fstream file1;
void Authentication::mainMenu()
{
	Customer cust;
	Merchant Mer;
	Courier C;
	std::string choice;
	//while(true){
	std::cout << "\n\n*******************************************************************************\n\n";
    std::cout << "                           Welcome to ShopTronics                               \n\n";
    std::cout << "****************************       MENU        ********************************\n\n";
    std::cout << "1.Customer\n";
    std::cout << "2.Merchant\n";
    std::cout << "3.Courier\n";
    std::cout << "4.Exit\n";
    std::cout << "\n";
    std::cout << "Enter your choice : ";
    std::cout << "\n";
    std::cin >> choice;
	std::regex f("^[1-4]$");

    if (!(regex_match(choice, f)))
    {
        std::cout << "\nInvalid Choice .....Please try again\n";
        mainMenu();
    }
	switch(stoi(choice))
	{
		case 1:
		cust.customerMenu();
		break;
		
		case 2:
		Mer.merchantMenu();
		break;

		case 3:
		C.courierMenu();
		break;
		
		case 4:
		std::cout<<"\n.....Thankyou for Shopping.....\n";
		exit(0);

	}
}
int Authentication::idGeneration()
{
	int id;
	srand(time(0));		   // srand() initialize random number generators
	id = rand() % 100 + 1; // generate random numbers
	return id;
}
void Authentication::CustomerRegistration()
{
	size_t pos = 0;
	std::string delimiter = ";";
	std::regex s("^[a-zA-Z0-9\\s]+$");
user1:
	std::cout << "Enter your desired username : ";
	getline(cin >> ws, username1);
	if (!(regex_match(username1, s)))
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user1;
	}
	// Validatecustomer(username1);
	ifstream in1;
	bool found = false;
	in1.open("CustomerAuthentication.txt", ios::in);
	while (std::getline(in1, line1))
	{
		std::string token = line1.substr(0, pos);

		if (line1.find(username1) != string::npos)
		{
			found = true;
		}
		line1.erase(0, pos + delimiter.length());
	}

	if (found)
	{
		std::cout << "Username already exists" << std::endl;
		found = false;
		goto user1;
		// CustomerRegistration();
	}

	in1.close();
	fstream file1;
	file1.open("CustomerAuthentication.txt", ios::in | ios::out | ios::app);
	std::cout << "Enter password :";
	std::cin >> password1;
    passwordStart1:
	std::cout << "Enter password to confirm :";
	std::getline(std::cin >> std::ws, password_confirm1);

	if (password1 != password_confirm1)
	{
		std::cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart1;
	}
	else
	{
		std::cout << "Awesome....Your Registration is successful......" << std::endl;
	}
	std::cout << "Your USERNAME :"
		 << "\e[1m" << username1 << std::endl;
	file1 << "Username " << username1 << ";"
		  << "Password " << password1 << ";"
		  << "CustomerID " << idGeneration() << ";" << std::endl;
	file1.close();
	std::cout << "\n";
	return;
}

////////////////////////////////////////////////////////////////////////////////////

void Authentication::CustomerLogin()
{
	int cAuthenticate = 0;
	bool ifound = false, flag = false;
	std::string line5, token, CustomerID, pass;
	std::string ChecK_name;
	std::string delimiter = ";";
	size_t pos = 0;
	std::cout << "Hello Customer...\nSo Glad to see you back......." << std::endl;
usera:
	std::cout << "Please enter the following details" << std::endl;
	std::cout << "\e[1m"
		 << "USERNAME :";
	std::cin >> username1;
retry:
	std::cout << "\e[1m"
		 << "PASSWORD :";
	std::cin >> password1;

	ifstream input("CustomerAuthentication.txt", ios::in);
	ofstream cus("customerId.txt", ios::out);
	while (std::getline(input, line5))
	{

		while ((pos = line5.find(delimiter)) != std::string::npos)
		{
			token = line5.substr(0, pos);

			if (token.rfind("Username ", 0) == 0)
			{
				ChecK_name = token.substr(9);
				if (username1 == ChecK_name)
				{
					ifound = true;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
				if(pass == password1)
				{
					flag = true;
					cAuthenticate++;
				}
			}
			if (token.rfind("CustomerID ", 0) == 0 && ifound)
			{
				CustomerID = token.substr(11);
			}
			line5.erase(0, pos + delimiter.length());
		}
		if(flag)
		{
			std::cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			flag = false;
			cus << CustomerID << std::endl;
		}
	}
	ifound = false;
	if (cAuthenticate == 0)
	{
		std::cout << "\n";
		    std::cout << "       ===Invalid name! Please try again.===\n";
		    std::cout << "\n";
		    goto usera;
	}
	input.close();
	cus.close();
}
/////////////////////////////////////////////////////////////////////////////////////////

void Authentication::MerchantRegistration()
{
	count2 = 0;
	string username2, password2, password_confirm2;
	size_t pos = 0;
	string delimiter = ";";

	std::regex s("^[a-zA-Z0-9\\s]+$");
user2:
	cout << "Enter your desired username : ";
	getline(cin >> ws, username2);
	if (!(regex_match(username2, s)))
	{
		std::cout << "\n";
		std::cout << "===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user2;
	}
	// Validatemerchant(username2);
	
	// int count1;
	
	ifstream in2;
	bool found = false;
	in2.open("merchantAuthentication.txt", ios::in);
	while (std::getline(in2, line2))
	{
		if (line2.find(username2) != string::npos)
		{
			//count2++;
			found = true;
		}
		line2.erase(0, pos + delimiter.length());
	}
	if (found)
	{
		std::cout << "Username already exists" << std::endl;
		found = false;
		goto user2;
		// MerchantRegistration();
	}
	in2.close();
	fstream file2;
	file2.open("merchantAuthentication.txt", ios::out | ios::app);

	std::cout << "Enter password :";
	std::cin >> password2;
passwordStart2:
	std::cout << "Enter password to confirm :";
	std::getline(std::cin >> std::ws, password_confirm2);
	if (password2 != password_confirm2)
	{
		std::cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart2;
	}
	else
	{
		std::cout << "Awesome....Your Registration is successful......" << std::endl;
	}
	std::cout << "Your USERNAME :"
		 << "\e[1m" << username2 << std::endl;
	file2 << "Username "<< username2 << ";" 
	      << "Password "<< password2 << ";"
		  << "MerchantID " << idGeneration() << ";" << std::endl;
	file2.close();
	std::cout << "\n";
	return;
}

void Authentication::MerchantLogin()
{
	bool ifound = false, flag = false;
	std::string line6, token, MerchantID, pass;
	std::string Check_name;
	std::string delimiter = ";";
	size_t pos = 0;
	std::string username2, password2, u, p, condition;
	int mAuthenticate = 0;

	std::cout << "Hello Merchant..........So Glad to see you back......." << std::endl;
merchant:
	std::cout << "Please enter the following details" << endl;
	std::cout << "\e[1m"
		 << "USERNAME :";
	std::cin >> username2;
retry:
	std::cout << "\e[1m"
		 << "PASSWORD :";
	std::cin >> password2;

	ifstream merchantFile("merchantAuthentication.txt");
	ofstream mer("merchantId.txt", ios::out);
	while (std::getline(merchantFile, line6))
	{
		while ((pos = line6.find(delimiter)) != std::string::npos)
		{
			token = line6.substr(0, pos);

			if (token.rfind("Username ", 0) == 0)
			{
				Check_name = token.substr(9);
				if (username2 == Check_name)
				{
					ifound = true;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
				if (pass == password2)
				{
					flag = true;
					mAuthenticate++;
				}
			}
			if (token.rfind("MerchantID ", 0) == 0 && ifound)
			{
				MerchantID = token.substr(11);
			}
			line6.erase(0, pos + delimiter.length());
		}
		if (flag)
		{
			std::cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			flag = false;
			mer << MerchantID << endl;
		}
	}
	ifound = false;
	if (mAuthenticate == 0)
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto merchant;
	}
	merchantFile.close();
}

///////////////////////////////////////////////////////////////////////

void Authentication::CourierRegistration()
{

	count3 = 0;
	std::regex s("^[a-zA-Z0-9\\s]+$");
user3:
	std::cout << "Enter your desired username : ";
	std::getline(std::cin >> std::ws, username3);
	if (!(regex_match(username3, s)))
	{
		std::cout << "\n";
		std::cout << "===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user3;
	}
	// Validatecourier(username3);
	ifstream in3;
	in3.open("CourierAuthentication.txt");
	while (std::getline(in3, line3))
	{
		if (line3.find(username3) != string::npos)
		{
			count3++;
		}
	}
	if (count3 > 0)
	{
		count3 = 0;
		std::cout << "Username already exists...!" << std::endl;
		goto user3;
		// CourierRegistration();
	}
	in3.close();
	fstream file3;
	file3.open("CourierAuthentication.txt", ios::out | ios::app);
	std::cout << "Enter password :";
	std::cin >> password3;
passwordStart3:
	std::cout << "Enter password to confirm :";
	std::getline(std::cin >> std::ws, password_confirm3);
	if (password3 != password_confirm3)
	{
		std::cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart3;
	}
	else
	{
		std::cout << "Awesome....Your Registration is successful......" << std::endl;
	}
	cout << "Your USERNAME :"
		 << "\e[1m" << username3 << std::endl;
	file3 << username3 << " " << password3 << std::endl;
	file3.close();
	std::cout << "\n";
	return;
}
void Authentication::CourierLogin()
{
	bool ifound = false, flag = false;
	std::string line8, token, pass;
	std::string Check_name;
	std::string delimiter = ";";
	size_t pos = 0;
	std::string username3, password3, u, p;
	int courierAuthenticate = 0;
	std::cout << "Hello Courier........So Glad to see you back......." << std::endl;
courier:
	std::cout << "Please enter the following details" << std::endl;
	std::cout << "\e[1m"
		 << "USERNAME :";
	std::cin >> username3;
retry:
	std::cout << "\e[1m"
		 << "PASSWORD :";
	std::cin >> password3;

	ifstream courierFile1("CourierAuthentication.txt");
	while (std::getline(courierFile1, line8))
	{
		while ((pos = line8.find(delimiter)) != std::string::npos)
		{
			token = line8.substr(0, pos);

			if (token.rfind("Username ", 0) == 0)
			{
				Check_name = token.substr(9);
				if (username3 == Check_name)
				{
					ifound = true;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
				if (pass == password3)
				{
					flag = true;
					courierAuthenticate++;
				}
			}
			line8.erase(0, pos + delimiter.length());
		}
		if (flag)
		{
			cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			flag = false;
		}
	}
	ifound = false;
	if (courierAuthenticate == 0)
	{
	
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto courier;
	}
	courierFile1.close();

}
