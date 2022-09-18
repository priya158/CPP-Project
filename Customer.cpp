#include "project.h"
ifstream customer("products.txt", ios::in);
ifstream Customerid("customerId.txt", ios::in);
ifstream MerchantId("merchantId.txt", ios::in);
void Customer::customerMenu()
{
    //while(true){
    Authentication auth;
    std::string CustChoice;
        std::cout << "********************************************************************************\n\n";
        std::cout << "                          Welcome to Customer Portal                             \n\n";
        std::cout << "****************************        MENU        ********************************\n\n";
        std::cout << "1.Login\n";
        std::cout << "2.Register\n";
        std::cout << "3.Previous Menu\n";
        std::cout << "Enter choice : ";
        std::cin >> CustChoice;
        std::regex v("^[1-3]$");
        if (!(regex_match(CustChoice, v)))
        {
            std::cout << "Invalid Choice .....Please try again\n";
            customerMenu();
        }
        switch (stoi(CustChoice))
        {
        case 1:
            auth.CustomerLogin();
            CustomerChoiceDisplay();
            break;
        case 2:
            auth.CustomerRegistration();
            customerMenu();
            CustomerChoiceDisplay();
            break;

        case 3:
            auth.mainMenu();
            break;
    
        }
}
//}

int Customer::idGenerate()
{
    int id;
    srand(time(0));        // srand() initialize random number generators
    id = rand() % 100 + 1; // generate random numbers
    return id;
}

void Customer::CustomerChoiceDisplay()
{
    std::string options;
    //while(true){
    std::cout << "***********************       MENU        ********************************\n\n";
    std::cout << "1.Buy Product\n";
    std::cout << "2.Show Product\n";
    std::cout << "3.Order Status\n";
    std::cout << "4.Cancel Order\n";
    std::cout << "5.Press 5 to logout\n"
         << std::endl;
    std::cout << "Enter choice : ";
    std::cin >> options;
    std::regex w("^[1-5]$");
    if (!(regex_match(options, w)))
    {
        std::cout << "\nInvalid Choice .....Please try again\n";
        CustomerChoiceDisplay();
    }
    switch (stoi(options))
    {
        case 1: {
            CustomerBuy();
            CustomerChoiceDisplay();
        }break;
        case 2: {
            showProducts();
            CustomerChoiceDisplay();
        }break;
        case 3:{
            orderStatus();
            CustomerChoiceDisplay();
        }break;
        case 4: {
            CancelOrder();
            CustomerChoiceDisplay();
        }break;
        case 5: {
            customerMenu();
        }break;
    
    }
}
void Customer::showProducts()
{
    ifstream in("products.txt", ios::in);
    while (std::getline(in, line1))
    {
        size_t pos = 0;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                std::cout << "Product ID: " << token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                std::cout << " |Name : " << token.substr(5);
            }
            if (token.rfind("Price ", 0) == 0)
            {
                std::cout << " |"
                     << "Price : " << token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                std::cout << " |"
                     << "Type : " << token.substr(5) << endl;
            }
            line1.erase(0, pos + delimiter.length());
        }
    }
    in.close();
}
void Customer::CustomerBuy()
{
    ifstream customer1("products.txt", ios::in);
    std::regex obj("^[1-5]$");
    std::string Cproduct, line2, name, ProductID, count, ProductType, Val, Price; /// cProduct   --- Customer Product
    bool found = false;
    int i = 0;
    ofstream buy("orders.txt", ios::out | ios::app);
    showProducts();
    std::cout << std::endl;
    std::cout << "Enter the product name you want to buy :";
    std::getline(std::cin >> std::ws, Cproduct);
gotobuy:
    std::cout << "How many would you like to buy? ";
    std::cin >> count;
    if (!(regex_match(count, obj)))
    {
        std::cout << "Invalid input or you cannot buy more than 5 products " << std::endl;
        goto gotobuy;
    }
    ofstream temp("temp.txt", ios::out | ios::app);
    ifstream in1("products.txt", ios::in);
    bool idfound = false;
    int j = 0;
    while (std::getline(Customerid, id))
    {
        customer_id = id;
    }
    while (std::getline(MerchantId, merId))
    {
        merchant_id = merId;
    }
    while (std::getline(in1, line))
    {
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line;
        
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);

            if (token.rfind("Name ", 0) == 0)
            {
                std::string Pname = token.substr(5);
                if (Pname == Cproduct)
                {
                    idfound = true;
                    j++;
                }
            }
            if (token.rfind("Count ", 0) == 0 && idfound)
            {
                Val = token.substr(6);
            }

            line.erase(0, pos + delimiter.length());
        }
    }
    if (j == 0)
    {
        std::cout << "Product not found " << std::endl;
        CustomerChoiceDisplay();
    }
    in1.close();
    int TempCount;
    int ProductC;

    TempCount = stoi(count);
    ProductC = stoi(Val);
    ifstream in3("products.txt", ios::in);
    std::string line3;
    while (std::getline(in3, line3))
    {
        // std::string delimiter = ";";
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line3;
        // std::string token;
        while ((pos = line3.find(delimiter)) != std::string::npos)
        {
            token = line3.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                std::string ChecK_name = token.substr(5);
                if (Cproduct == ChecK_name)
                {
                    idfound = true;
                }
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(10);
            }
            if (token.rfind("Price ", 0) == 0)
            {
                Price = token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                ProductType = token.substr(5);
            }
            line3.erase(0, pos + delimiter.length());
        }
        if (idfound)
        {
            if (ProductC - TempCount < 0)
            {
                std::cout << "Product Out of stock......\nPlease try again later\n";
                CustomerChoiceDisplay();
            }
            else
            {
                temp << "ProductID " << ProductID;
                temp << ";Name " << Cproduct;
                temp << ";Price " << Price;
                temp << ";Type " << ProductType;
                temp << ";Count " << ProductC - TempCount << ";" << endl;
            }
        }
        else
        {

            temp << originalLine << endl;
        }
    }
    temp.close();
    in3.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");
    while (std::getline(customer1, line2))
    {
        size_t pos = 0;
        // std::string token;
        while ((pos = line2.find(delimiter)) != std::string::npos)
        {
            token = line2.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                name = token.substr(5);

                if (Cproduct == name)
                {
                    found = true;
                    i++;
                }
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(10);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                ProductType = token.substr(5);
            }

            line2.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            std::cout << "Order added to cart successfully......\n";
            buy << "CustomerID " << customer_id << ";"
                << "MerchantID " << merchant_id << ";"
                << "OrderID " << idGenerate() << ";"
                << "ProductID " << ProductID << ";"
                << "Name " << name << ";"
                << "Type " << ProductType << ";"
                << "Count " << count
                << ";Status "
                << "Pending"
                << ";" << std::endl;
            found = false;

            break;
        }
    }
    buy.close();
}
/*Code to check status of order*/
void Customer::orderStatus()
{
    std::string line1, name, price, Customer_ID, file;
    // std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
    ifstream cuID("customerId.txt", ios::in);
    bool idCustomer = false;
    int buy = 0;
    while (std::getline(cuID, file))
    {
        Customer_ID = file;
    }
    while (std::getline(in, line1))
    {
        std::string ProductS, nameS, PriceS, TypeS, Status, countS, CustomerIdS;
        size_t pos = 0;
        // std::string token;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("CustomerID ", 0) == 0)
            {
                CustomerIdS = token.substr(11);
                if (CustomerIdS == Customer_ID)
                {
                    idCustomer = true;
                    buy++;
                }
            }
            if (token.rfind("ProductID ", 0) == 0 && idCustomer)
            {
                ProductS = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0 && idCustomer)
            {
                nameS = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && idCustomer)
            {
                TypeS = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && idCustomer)
            {
                countS = token.substr(6);
            }
            if (token.rfind("Status ", 0) == 0 && idCustomer)
            {
                Status = token.substr(7);
            }
            line1.erase(0, pos + delimiter.length());
        }
        if(idCustomer)
        {
        std::cout << "ProductID " << ProductS << "|"
             << "Name " << nameS << "|"
             << "Type "
             << TypeS << "|"
             << "Count "
             << countS << "|"
             << "Status "
             << Status
             << std::endl;
             idCustomer = false;
        }
    }
    if (buy == 0)
    {
        std::cout << "\nYou haven't made any orders...." << std::endl;
        CustomerChoiceDisplay();
    }
    in.close();
}
void Customer::CancelOrder()
{
    ifstream Customerid("customerId.txt", ios::in);
    ifstream MerchantId("merchantId.txt", ios::in);
    ifstream view("orders.txt", ios::in);
    std::cout << "***********************      Orders     ********************************\n";
    std::string line1, Cid, defstatus = "Pending", defstatus1 = "Shipping", status, Order, Name, Type, iDCustomer, id1, id2;
    // std::string delimiter = ";";
    //bool st = false;
    int count2 = 0;
    while (std::getline(Customerid, id1))
    {
        customer_id = id1;
    }
    Customerid.close();
    while (std::getline(MerchantId, id2))
    {
        merchant_id = id2;
    }
    MerchantId.close();
    while (std::getline(view, line1))
    {
        bool idCustomer = false, st = false;
        size_t pos = 0;
        // std::string token;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("CustomerID ", 0) == 0)
            {
                Cid = token.substr(11);
                if (Cid == customer_id)
                {
                    idCustomer = true;
                }
            }
            if (token.rfind("OrderID ", 0) == 0)
            {
                Order = token.substr(8);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                Name = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Status ", 0) == 0)
            {

                status = token.substr(7);
                if (status == defstatus || status == defstatus1)
                {
                    st = true;
                    count2++;
                }
            }
            line1.erase(0, pos + delimiter.length());
        }
        if (st)
        {
            std::cout << "Order ID " << Order << "|"
                 << "Name " << Name << "|"
                 << "Type "
                 << Type << "|"
                 << "Status "
                 << status
                 << std::endl;
            st = false;
        }
        idCustomer = false;
    }
    if (count2 == 0)
    {
        std::cout << "No orders to cancel.....\n";
        CustomerChoiceDisplay();
    }
    view.close();
    ////////////////////////////////////////////////////////////////////////////
    std::string line2, id, CancelId, Pid, Name1, Type1, Count1;
    ifstream orders("orders.txt", ios::in);
    ofstream temp1("temp.txt", ios::out);
    std::regex obj("^[0-9]*$");
    int count = 0;
    bool found = false;
    while (std::getline(Customerid, id))
    {
        customer_id = id;
    }
    while (std::getline(MerchantId, merId))
    {
        merchant_id = merId;
    }
cancel:
    std::cout << "Enter the Order ID you want to cancel :";
    getline(std::cin >> std::ws, CancelId);
    while (std::getline(orders, line2))
    {
        std::string OriginalLine = line2;
        size_t pos = 0;
        // std::string token;
        while ((pos = line2.find(delimiter)) != std::string::npos)
        {
            token = line2.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                id = token.substr(8);
                if (CancelId == id)
                {
                    found = true;
                    count++;
                }
            }
            if (token.rfind("ProductID ", 0) == 0 && found)
            {
                Pid = token.substr(10);
            }
            if (token.rfind("Name ", 0) == 0 && found)
            {
                Name1 = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && found)
            {
                Type1 = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && found)
            {
                Count1 = token.substr(6);
            }
            line2.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            std::cout << "Cancelled Succesfully" << std::endl;
            temp1 << "CustomerID " << customer_id;
            temp1 << ";MerchantID " << merchant_id;
            temp1 << "OrderID " << id;
            temp1 << ";ProductID " << Pid;
            temp1 << ";Name " << Name1;
            temp1 << ";Type " << Type1;
            temp1 << ";Count " << Count1 << ";";
            temp1 << "Status "
                  << "Cancelled;" << std::endl;
            found = false;
        }
        else
        {
            temp1 << OriginalLine << endl;
        }
    }
    if (count == 0)
    {
        std::cout << "No Such Order ID exists......." << std::endl;
        CustomerChoiceDisplay();
    }
    remove("orders.txt");
    rename("temp.txt", "orders.txt");
    int TempCount = stoi(Count1);
    int ProductCount;
    std::string PorderID, PCount;
    ifstream in("products.txt", ios::in);
    std::string line3;
    bool idfound1 = false;
    while (std::getline(in, line3))
    {
        size_t pos = 0;
        // std::string token;
        idfound1 = false;
        while ((pos = line3.find(delimiter)) != std::string::npos)
        {
            token = line3.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                PorderID = token.substr(10);
                if (Pid == PorderID)
                {
                    idfound1 = true;
                }
            }
            if (token.rfind("Count ", 0) == 0 && idfound1)
            {
                PCount = token.substr(6);
            }
            line3.erase(0, pos + delimiter.length());
        }
        if (idfound1)
        {
            ProductCount = stoi(PCount);
            idfound1 = false;
        }
    }
    in.close();
    //////////////////////////////////////////////////////////////////////////
    ifstream updation("products.txt", ios::in);
    ofstream Temp("temp2.txt", ios::out);
    std::string line4, name, Price, Type2, Count;
    bool isfound = false;
    while (std::getline(updation, line4))
    {
        std::string originalLine1 = line4;
        size_t pos = 0;
        // std::string token;
        while ((pos = line4.find(delimiter)) != std::string::npos)
        {
            token = line4.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                PorderID = token.substr(10);
                if (Pid == PorderID)
                {
                    isfound = true;
                }
            }
            if (token.rfind("Name ", 0) == 0 && isfound)
            {
                name = token.substr(5);
            }
            if (token.rfind("Price ", 0) == 0 && isfound)
            {
                Price = token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0 && isfound)
            {
                Type2 = token.substr(5);
            }
            line4.erase(0, pos + delimiter.length());
        }
        if (isfound)
        {
            Temp << "ProductID " << PorderID;
            Temp << ";MerchantID " << merchant_id;
            Temp << ";Name " << name;
            Temp << ";Price " << Price;
            Temp << ";Type " << Type2;
            Temp << ";Count " << TempCount + ProductCount << ";" << std::endl;
            isfound = false;
        }
        else
        {
            Temp << originalLine1 << endl;
        }
    }
    in.close();
    Temp.close();
    remove("products.txt");
    rename("temp2.txt", "products.txt");
}