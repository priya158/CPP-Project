#include "project.h"
std::string choice;
void Courier::courierMenu()
{
    Authentication auth;
    std::string CourierChoice;
    std::cout << "******************************************************************************\n\n";
    std::cout << "                        Welcome to Courier Portal                             \n\n";
    std::cout << "******************************************************************************\n\n";
    std::cout << "1.Login\n";
    std::cout << "2.Register\n";
    std::cout << "3.Previous Menu\n";
    std::cout << "Enter choice : \n";
    std::cin >> CourierChoice;
    std::regex z("^[1-3]$");
    if (!(regex_match(CourierChoice, z)))
    {
        std::cout << "Invalid Choice !!.....Please try again\n";
        courierMenu();
    }
    switch (stoi(CourierChoice))
    {
        case 1: {
            auth.CourierLogin();
            courierOptions();
        }break;
        case 2: {
            auth.CourierRegistration();
            courierMenu();
            //courierOptions();
        }break;
        case 3: {
            auth.mainMenu();
        }break;
            
    }
}
void Courier::courierOptions()
{
    std::string courierchoice;
    std::cout << "\n\n*********WELCOME TO COURIER PORTAL********\n\n";
    std::cout << "\t1. View assigned orders \n";
    std::cout << "\t2. Update status of orders \n";
    std::cout << "\t3. List of pending and completed delivery \n";
    std::cout << "\t4. LOGOUT\n\n";
    std::cout << "\nEnter your choice: ";
    std::cin >> courierchoice;
    std::regex k("^[1-4]$");
    if (!(regex_match(courierchoice, k)))
    {
        std::cout << "Invalid Choice !!.....Please try again\n";
        courierOptions();
    }
    switch (stoi(courierchoice))
    {
        case 1: {
            listOfOrders();
            courierOptions();
        }break;
        case 2: {
            StatusUpdate();
            courierOptions();
        }break;
        case 3: {
            PendingAndDelivered();
            courierOptions();
        }break;
        case 4: {
            courierMenu();
        }break;
    }
    
}
void Courier::listOfOrders()
{
    std::string location;
    std::string Name, OrderID, Count, Courier, Type;
    std::cout << "1.Kochi\n2.Ernakulam\n";
ch:
    std::cout << "Enter choice :";
    std::getline(std::cin >> std::ws, choice);
    if (choice == "1")
    {
        location = "Kochi";
    }
    else if (choice == "2")
    {
        location = "Ernakulam";
    }
    else
    {
        std::cout << "       ===Not a valid choice !! Please retry.......===\n";
        goto ch;
    }

    std::string line, Location, Status1, defStatus = "Shipping";
    bool found = false, flag1 = false;
    int c = 0, d = 0;
    std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
    while (std::getline(in, line))
    {
        size_t pos = 0;
        std::string originalLine = line;
        std::string token;
        found = false;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID = token.substr(8);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                Name = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                Count = token.substr(5);
            }
            if (token.rfind("Courier ", 0) == 0)
            {
                Location = token.substr(8);
                if (location == Location)
                {
                    found = true;
                }
            }
            if (token.rfind("Status ", 0) == 0 && found)
            {
                Status1 = token.substr(7);
                if (Status1 == defStatus)
                {
                    flag1 = true;
                    std::cout << "Order ID " << OrderID << " | "
                         << "Name " << Name << " | "
                         << "Type " << Type << " | "
                         << "Count " << Count << std::endl;
                    c++;
                }
            }
            line.erase(0, pos + delimiter.length());
        }
    }
    if (c == 0)
    {
        std::cout << "No Products have been assigned to deliver" << std::endl;
        return;
    }
    in.close();
}

void Courier::StatusUpdate()
{
    std::string Orderid;
    // listOfOrders();
////////////////////////////////////////////////////////////////
    std::string location;
    std::string Name1, OrderID1, Count1, Courier1, Type1;
    std::cout << "1.Kochi\n2.Ernakulam\n";
ch:
    std::cout << "Enter choice :";
    std::getline(std::cin >> std::ws, choice);
    if (choice == "1")
    {
        location = "Kochi";
    }
    else if (choice == "2")
    {
        location = "Ernakulam";
    }
    else
    {
        std::cout << "       ===Not a valid choice !! Please retry.......===\n";
        goto ch;
    }

    std::string line1, Location, Status1, defStatus = "Shipping";
    bool found = false, flag1 = false;
    int c = 0, d = 0;
    ifstream in("orders.txt", ios::in);
    while (std::getline(in, line1))
    {
        size_t pos = 0;
        std::string originalLine = line1;
        std::string delimiter=";";
        std::string token;
        found = false;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID1 = token.substr(8);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                Name1 = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type1 = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                Count1 = token.substr(5);
            }
            if (token.rfind("Courier ", 0) == 0)
            {
                Location = token.substr(8);
                if (location == Location)
                {
                    found = true;
                }
            }
            if (token.rfind("Status ", 0) == 0 && found)
            {
                Status1 = token.substr(7);
                if (Status1 == defStatus)
                {
                    flag1 = true;
                    std::cout << "Order ID " << OrderID1 << " | "
                         << "Name " << Name1 << " | "
                         << "Type " << Type1 << " | "
                         << "Count " << Count1 << std::endl;
                    c++;
                }
            }
            line1.erase(0, pos + delimiter.length());
        }
    }
    if(c==0){
        std::cout<<"No Prducts to update"<<std::endl;
        return;
    }
///////////////////////////////////////
    std::cout << "Enter Order ID to be updated : ";
    std::getline(std::cin >> std::ws, Orderid);
    std::string OrderId, line;
    bool flag = false;
    int CourierChoice, count = 0;
    std::string delimiter = ";";
    ifstream courier("orders.txt", ios::in);
    ofstream temp("Temp.txt", ios::out);
    std::string OrderID, ProductID, Name, Type, Count, Status;
    while (std::getline(courier, line))
    {
        size_t pos = 0;
        std::string token, OriginalLine = line;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID = token.substr(8);
                if (OrderID == Orderid)
                {
                    flag = true;
                    count++;
                }
            }
            if (token.rfind("ProductID ", 0) == 0 && flag)
            {
                ProductID = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0 && flag)
            {
                Name = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && flag)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && flag)
            {
                Count = token.substr(6);
            }
            if (token.rfind("Status ", 0) == 0 && flag)
            {
                Status = token.substr(7);
            }
            line.erase(0, pos + delimiter.length());
        }
        switch (stoi(choice))
        {
        case 1:
            if (flag)
            {
                std::cout << "Updated Successfully......" << std::endl;
                temp << "OrderID " << OrderID << ";"
                     << "ProductID " << ProductID << ";"
                     << "Name " << Name << ";"
                     << "Type " << Type << ";"
                     << "Count " << Count << ";"
                     << "Courier "
                     << "Kochi"
                     << ";"
                     << "Status "
                     << "Delivered"
                     << ";" << std::endl;
                flag = false;
                break;
            }
            else
            {
                temp << OriginalLine << std::endl;
            }
            break;
        case 2:
            if (flag)
            {
                temp << "OrderID " << OrderID << ";"
                     << "ProductID " << ProductID << ";"
                     << "Name " << Name << ";"
                     << "Type " << Type << ";"
                     << "Count " << Count << ";"
                     << "Courier "
                     << "Ernakulam"
                     << ";"
                     << "Status "
                     << "Delivered"
                     << ";" << std::endl;
                flag = false;
                break;
            }
            else
            {
                temp << OriginalLine << endl;
            }
            break;
        default:
            std::cout << "Not Valid...." << std::endl;
        }
    }
    if (count == 0)
    {
        std::cout << "No Orders to be updated....." << std::endl;
        return;
    }
    courier.close();
    temp.close();
    remove("orders.txt");
    rename("Temp.txt", "orders.txt");
}

void Courier::PendingAndDelivered()
{
    std::string stats;
    std::string Name, OrderID, ProductID, Count, Type;
    int choice;
W:
    std::cout << "\n1.List of Pending\n2.List of Delivered\n";
    std::cout << "Enter your choice :";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "\nOrders Pending\n";
        stats = "Shipping";
        break;

    case 2:
        std::cout << "\nOrders Delivered\n";
        stats = "Delivered";
        break;

    default:
        std::cout << "\n...Not a valid choice !! Please retry...\n";
        goto W;
    }

    std::string line, Stats;
    bool found = false;
    int i = 0;
    std::string delimiter = ";";
    ifstream temp("orders.txt", ios::in);
    while (std::getline(temp, line))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);

            if (token.rfind("Name ", 0) == 0)
            {
                Name = token.substr(5);
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(9);
            }
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID = token.substr(8);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                Count = token.substr(5);
            }
            if (token.rfind("Status", 0) == 0)
            {
                Stats = token.substr(7);
                if (stats == Stats)
                {
                    found = true;
                    i++;
                }
            }
            line.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            std::cout << "OrderID " << OrderID << "|"
                      << " ProductID " << ProductID << "|"
                      << " Name " << Name << "|"
                      << " Type " << Type << "|"
                      << " Count " << Count << std::endl;
            found = false;
        }
    }
    if (i == 0)
    {
        std::cout << "No orders present...." << std::endl;
    }
    temp.close();
}