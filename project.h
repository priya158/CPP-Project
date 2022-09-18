#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <regex>
using namespace std;

class Authentication
{
    string username1 ,password1,password_confirm1 , pass1 ,user;
    string username2, password2, password_confirm2;
    string username3, password3, password_confirm3;
public:
int count1 , count2,count3;
string line1 , line2 , line3; 
    void CustomerLogin();
    void CustomerRegistration();
    void MerchantLogin();
    void MerchantRegistration();
    void CourierLogin();
    void CourierRegistration();
    int idGeneration();
    void mainMenu();
};
class Customer
{
    std::string line1, name, price;
    std::string delimiter = ";";
    std::string token;
    std::string id, customer_id;
    std::string merchant_id, merId;
    int cusId;
public:
    int customerChoice;
    std::string line;
    int ProductBuy;
    void CustomerBuy();
    void CustomerChoiceDisplay();
    void showProducts();
    void orderStatus();
    void CancelOrder();
    int idGenerate();
    void customerMenu();
};

class Merchant
{
public:
    std::string merchantId, productId;
    std::string productName, productPrice;
    std::string productType, productCount; //,MerchantChoice;
    int productChoice, MerchantChoice;
    void addProducts();
    void merchantOptions();
    void searchProducts();
    void displayOutOfStock();
    void assignCourier();
    void cancelledProducts();
    void OrderStatusView();
    int idGeneration();
    void merchantMenu();
};

class Courier
{
public:
void listOfOrders();
void courierOptions();
void StatusUpdate();
void PendingAndDelivered();
void courierMenu();
};