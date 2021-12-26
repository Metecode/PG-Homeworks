/******************************************************************************************
**                                SAKARYA UNIVERSITY
**                    FACULTY OF COMPUTER AND INFORMATION SCIENCES
**                               COMPUTER ENGINEERING
**                           INTRODUCTION TO PROGRAMMING
**
**                          PROJECT NUMBER : 1
**                          STUDENT'S NAMES : İSMAİL METE UÇAR
**                          STUDENT'S NUMBERS : G201210051
**                          LESSON GROUP : 2C
*******************************************************************************************/

//Added required libraries.
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <windows.h>

using namespace std;

//Created variables for products in Products class.
class Products
{
public:
    string name;
    string manufacturer;
    string leadTime;
    string date;
    string number;
    int vat;
    int stockQuantity;
    float price;
    float primePrice;
    string controlNumber;
};

//Created variables for customers in Customers class.
class Customers
{
public:
    string companyNo;
    string companyPhone;
    string companyName;
    string companyManager;
    string companyAddress;
    string companyCategory;
    string controlNumber;

};

//Created variables for orders in Orders class.
class Orders
{
public:
    string companyNo;
    float orderTotal;
    string orderBy;
    int productNumber;
    string category;
    string orderfile;
    string orderDate;
    int orderNumber;
    float singularPrice;
    int controlNumber;
    string address;
    string phone;
};

//Function that checks for value.
bool product_control(string controlNumber);
bool customer_control(string controlNumber);
bool order_control(int controlNumber);

//Function prototypes for each menu.
void mainMenu();
void productProcedures();
void customerProcedures();
void orderProcedures();
void productAdd();
void productSearch();
void productListing();
void productCorrection();
void productDelete();
void customerAdd();
void customerSearch();
void customerUpdate();
void customerDelete();
void orderEnter();
void orderSearch();
void orderDelete();
void orderUpdate();
void orderReport();
void orderTotal();
void orderListing();
void stock_update(int stockNumber, string stockUp);
void stock_correction(int old_quantity, int stockNumber, string stockUp);
void exit();

int main()
{
    while (true)
    {
        mainMenu();
        system("pause");
        return 0;
    }
}

void mainMenu() //Created "Main Menu" function. It is our main menu.
{
    system("CLS");
    cout << "                   ****WELCOME THE COMPUTER PRODUCTS SALES SYSTEM****                        \n" << endl;
    cout << "Please select action you want to do" << endl << endl;
    cout << "1. PRODUCT TRANSACTIONS " << endl;
    cout << "2. CUSTOMER TRANSACTIONS" << endl;
    cout << "3. ORDER TRANSACTIONS" << endl;
    cout << "4. EXIT PROGRAM" << endl;
    char select;
    select = _getch();
    switch (select)
    {
    case '1':
        productProcedures();
        break;
    case '2':
        customerProcedures();
        break;
    case '3':
        orderProcedures();
        break;
    case '4':
        system("cls");
        cout << "\n                    *    Thank you for using the COMPUTER PRODUCTS SALES SYSTEM !!    *            ";
        exit(0);
    default:
        cout << "Incorrect entry! \a \n";
        break;
    }
}

bool product_control(string controlNumber) //Created function to find out if product is registered in the program.
{
    Products product;

    bool control = 0; // If the product number is not registered in the program, it takes value 0.
    ifstream inProduct("product.txt", ios_base::in);

    while (!inProduct.eof())
    {
        inProduct >> product.number;
        inProduct.ignore();
        getline(inProduct, product.name);
        getline(inProduct, product.manufacturer);
        getline(inProduct, product.leadTime);
        inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;

        if (product.number == controlNumber)
        {
            control = 1;
        }
    }
    return control;
}

bool customer_control(string controlNumber) //Created function to find out if customer is registered in the program.
{
    Customers customer;

    bool control = 0; // If the company no is not registered in the program, it takes value 0.
    ifstream inCustomer("customer.txt", ios_base::in);

    while (!inCustomer.eof())
    {
        inCustomer >> customer.companyNo;
        inCustomer.ignore();
        getline(inCustomer, customer.companyName);
        inCustomer >> customer.companyPhone;
        inCustomer.ignore();
        getline(inCustomer, customer.companyManager);
        inCustomer >> customer.companyCategory;
        inCustomer.ignore();
        getline(inCustomer, customer.companyAddress);

        if (customer.companyNo == controlNumber)
        {
            control = 1;
        }
    }
    return control;
}

bool order_control(int controlNumber) //Created function to find out if order is registered in the program.
{
    Orders order;

    bool control = 0; // If the order no is not registered in the program, it takes value 0.
    ifstream inOrder("order.txt", ios_base::in);

    while (!inOrder.eof())
    {
        inOrder >> order.orderNumber;
        inOrder >> order.companyNo;
        inOrder.ignore();
        getline(inOrder, order.orderBy);
        inOrder >> order.category;
        inOrder >> order.phone;
        inOrder.ignore();
        getline(inOrder, order.address);
        inOrder >> order.orderTotal;
        inOrder >> order.orderfile;
        inOrder.ignore();
        getline(inOrder, order.orderDate);

        if (order.orderNumber == controlNumber)
        {
            control = 1;
        }
    }
    return control;
}


void productProcedures() //Created "Product transactions menu" function. It is our product menu.
{
    system("cls");
    string productMenu[6];
    productMenu[0] = "1. Add Product\n";
    productMenu[1] = "2. Search Product\n";
    productMenu[2] = "3. Listing Product\n";
    productMenu[3] = "4. Update Product\n";
    productMenu[4] = "5. Delete Product\n";
    productMenu[5] = "6. Main Menu \n";

    for (int i = 0; i < 6; i++) //loop to show product operations.
    {
        cout << productMenu[i] << endl;
    }
    cout << "Please select action you want to do" << endl;

    char pick;
    pick = _getch();
    switch (pick)
    {
    case '1':
        productAdd();
        break;
    case '2':
        productSearch();
        break;
    case '3':
        productListing();
        break;
    case '4':
        productCorrection();
        break;
    case '5':
        productDelete();
        break;
    case '6':
        exit();
        break;
    default:
        cout << "Incorrect entry! \a \n ";
        break;
    }
}

void customerProcedures() //Created "Customer transactions menu" function. It is our customer menu.
{
    system("cls");
    string customerMenu[5];
    customerMenu[0] = "1. Add Customer \n";
    customerMenu[1] = "2. Search Customer  \n";
    customerMenu[2] = "3. Update Customer  \n";
    customerMenu[3] = "4. delete Customer  \n";
    customerMenu[4] = "5. Main Menu \n";

    for (int i = 0; i < 5; i++) //loop to show customer operations.
    {
        cout << customerMenu[i] << endl;
    }

    cout << "Please select action you want to do" << endl;
    char pick;
    pick = _getch();

    switch (pick)
    {
    case '1':
        customerAdd();
        break;
    case '2':
        customerSearch();
        break;
    case '3':
        customerUpdate();
        break;
    case '4':
        customerDelete();
        break;
    case '5':
        exit();
        break;
    default:
        cout << "Incorrect entry!\n";
        break;
    }
}

void orderProcedures() //Created method for order operations.
{
    system("cls");
    string orderMenu[6];
    orderMenu[0] = "1. Enter Order\n";
    orderMenu[1] = "2. Search Order\n";
    orderMenu[2] = "3. Update Order \n";
    orderMenu[3] = "4. Delete Order \n";
    orderMenu[4] = "5. Report Order \n";
    orderMenu[5] = "6. Main Menu \n";

    for (int i = 0; i < 6; i++) //loop to show order operations.
    {
        cout << orderMenu[i] << endl;
    }

    cout << "Please select action you want to do" << endl;

    char pick;
    pick = _getch();

    switch (pick)
    {
    case '1':
        orderEnter();
        break;
    case '2':
        orderSearch();
        break;
    case '3':
        orderUpdate();
        break;
    case '4':
        orderDelete();
        break;
    case '5':
        orderReport();
        break;
    case '6':
        exit();
    default:
        cout << "Incorrect entry! \a \n";
        break;
    }
}

//Created "Add Product" function. Adding product for user.
void productAdd()
{
    char answer;
    string controlNumber;
    system("cls");
    ofstream inProduct("product.txt", ios_base::app); //Opened our readers file for output.
    Products product;
    do
    {
        system("cls");
        cout << "Product number : "; cin >> product.number;
        controlNumber = product.number;
        if (product_control(controlNumber) == 1) //Checking here if entered product number registered before. If registered before, "add product menu" will be closed.
        {
            cout << "This product number has already been used, please enter a different product number ! \a" << endl;
            Sleep(2000);
            cout << "\nDo you want to continue add product operation? (y/n)" << endl;
            string answerexit; cin >> answerexit;
            if (answerexit == "y")
            {
                productAdd();
            }
            else if (answerexit == "n")
            {
                inProduct.close();
                productProcedures();
                return;
            }
        }
        cout << endl;
        cin.ignore();
        cout << "Product name : ";
        getline(cin, product.name);
        cout << endl;
        cout << "Producing company  : ";
        getline(cin, product.manufacturer);
        cout << endl;
        cout << "Lead time  : ";
        getline(cin, product.leadTime);
        cout << endl;
        cout << "Date of production  : "; cin >> product.date;
        cout << endl;
        cout << "Price for general customers  : "; cin >> product.price;
        cout << endl;
        cout << "Product price for prime customers : "; cin >> product.primePrice;
        cout << endl;
        cout << "Value-added tax (VAT) : " << "\n -The standard rate is 18% \n -Discounted rate is 8% \n -Super discount rate is 1% \n ";
        cout << "Please enter a value without percent sign at beginning... "; cin >> product.vat;
        cout << endl;
        cout << "Stock quantity : "; cin >> product.stockQuantity;
        cout << endl;
        inProduct << product.number << endl << product.name << endl << product.manufacturer << endl << product.leadTime << endl
            << product.date << endl << product.price << endl << product.primePrice << endl << product.vat << endl << product.stockQuantity << endl << endl;

        cout << "\n Will you add another product? (y/n) "; cin >> answer;
    } while (!(answer == 'n'));

    //Closing file.
    inProduct.close();

    productProcedures(); //Return to product transactions.
}

void productSearch() //Created method  for product search 
{
    system("cls");
    string controlNumber;
    cout << " Enter number of product you are looking for. " << endl;
    cin >> controlNumber;
    Products product;
    ifstream inProduct("product.txt", ios_base::in); //Opened our product file for input.
    if (product_control(controlNumber) == 0) //Checking if there is a user with entered product number. If yes, code will proceed.
    {
        cout << "There is no product With This product number! \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to product operations " << endl;
        _getch();
        system("cls");
        productProcedures();
        inProduct.close();
    }
    else
    {
        while (!(inProduct.eof())) //Searching product whose product number was entered.
        {

            inProduct >> product.number;
            inProduct.ignore();
            getline(inProduct, product.name);
            getline(inProduct, product.manufacturer);
            getline(inProduct, product.leadTime);
            inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;
            if (!inProduct) break; //to get out of the loop
            if (controlNumber == product.number) //If entered product number matches one in the system.
            {
                cout << "Product Name: " << product.name << endl << "Manufacturer: " << product.manufacturer << endl << "Lead time: " << product.leadTime << endl
                    << "Date : " << product.date << endl << "Price: " << product.price << endl << "Prime price: " << product.primePrice << endl << "VAT: " << product.vat << endl << "Stock :" << product.stockQuantity << endl;
            }
        }
    }
    inProduct.close();

    cout << endl;
    cout << "Press any key to return to product operations " << endl;
    _getch();

    system("cls");

    productProcedures();
}

void productListing() // Method to listing products.
{
    system("cls");
    Products product;
    ifstream inProduct("product.txt", ios_base::in); //Opened our readers file for input.
    if (!inProduct) //if there is no data in "product.txt" file.
    {
        system("cls");
        cerr << "Error opening file" << endl;

        cout << "Press any key to return to product operations " << endl;
        _getch();
        system("cls");
        productProcedures();
        inProduct.close();
    }
    else {
        while (!(inProduct.eof()))
        {
            inProduct >> product.number;
            inProduct.ignore();
            getline(inProduct, product.name);
            getline(inProduct, product.manufacturer);
            getline(inProduct, product.leadTime);
            inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;
            if (!inProduct)break; //to get out of the loop
            cout << "Product Number : " << product.number << endl << "Product Name: " << product.name << endl << "Manufacturer: " << product.manufacturer << endl << "Lead time: " << product.leadTime << endl
                << "Date : " << product.date << endl << "Price: " << product.price << endl << "Prime price: " << product.primePrice << endl << "VAT: " << product.vat << endl << "Stock :" << product.stockQuantity << endl << endl;
        }
    }

    inProduct.close();

    cout << endl;
    cout << "Press any key to return to product operations " << endl;
    _getch();

    system("cls");

    productProcedures();
}

void productCorrection() //Created "Update product" function. It let us make some changes about a product.
{
    system("cls");
    string controlNumber;
    string controlTemp;
    cout << "Please enter product number you want to update" << endl;
    cin >> controlNumber;

    controlTemp = controlNumber;
    cin.ignore();

    Products product;
    //Opened product input file and a temporary output file for product.
    ifstream inProduct("product.txt");
    ofstream temporary("temporary.txt", ios_base::app);

    if (product_control(controlNumber) == 0) //Loop that checks the registered product code.
    {
        inProduct.close();

        cout << "There is no product With This product number! \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to product operations " << endl;

        _getch();
        system("cls");
        productProcedures();
    }
    else
    {
        do
        {
            inProduct >> product.number;
            inProduct.ignore();
            getline(inProduct, product.name);
            getline(inProduct, product.manufacturer);
            getline(inProduct, product.leadTime);
            inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;
        } while (controlTemp != product.number);

        cout << "Product Number : "; cin >> product.number; cout << endl;
        controlNumber = product.number;
        if (product_control(controlNumber) == 1) //Checking here if entered product number registered before. If registered before, "add product menu" will be closed.
        {
            cout << "This product number has already been used, please enter a different product number ! \a" << endl;
            Sleep(2000);
            cout << "\nDo you want to continue update operation? (y/n)" << endl;
            string answerexit; cin >> answerexit;
            if (answerexit == "y")
            {
                productCorrection();
            }
            else if (answerexit == "n")
            {
                temporary.close();
                remove("temporary.txt");
                productProcedures();
            }
        }
        else
            cin.ignore();
        cout << "Product Name : ";
        getline(cin, product.name);
        cout << endl;
        cout << "Producing company : ";
        getline(cin, product.manufacturer);
        cout << endl;
        cout << "Lead time : ";
        getline(cin, product.leadTime);
        cout << endl;
        cout << "Date of production : "; cin >> product.date; cout << endl;
        cout << "Price for general customers : "; cin >> product.price; cout << endl;
        cout << "Product price for prime customers : "; cin >> product.primePrice; cout << endl;
        cout << "Value-added tax (VAT) : "; cin >> product.vat; cout << endl;
        cout << "Stock quantity : "; cin >> product.stockQuantity; cout << endl << endl;

        //After changes updated informations will be added in our temporary product file.
        temporary << product.number << endl << product.name << endl << product.manufacturer << endl << product.leadTime << endl << product.date << endl << product.price << endl << product.primePrice << endl << product.vat << endl << product.stockQuantity << endl << endl;

        inProduct.close();
        inProduct.open("product.txt");

        //Searching our member which is not matched with entered product number and adding them in our temporary product files.
        while (!inProduct.eof())
        {
            inProduct >> product.number;
            inProduct.ignore();
            getline(inProduct, product.name);
            getline(inProduct, product.manufacturer);
            getline(inProduct, product.leadTime);
            inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;

            if (inProduct.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlTemp != product.number)
            {
                temporary << product.number << endl;
                temporary << product.name << endl;
                temporary << product.manufacturer << endl;
                temporary << product.leadTime << endl;
                temporary << product.date << endl;
                temporary << product.price << endl;
                temporary << product.primePrice << endl;
                temporary << product.vat << endl;
                temporary << product.stockQuantity << endl << endl;
            }
        }
        //files closed.
        temporary.close();
        inProduct.close();
        //files removed and renamed.
        remove("product.txt");
        rename("temporary.txt", "product.txt");
    }
    cout << "Press any key to return to product operations " << endl;
    _getch();

    system("cls");

    productProcedures();
}

//Created "product delete" function.
void productDelete()
{
    //Opened product input file and a temporary output file for product.
    ifstream inProduct("product.txt");

    Products product;
    string controlNumber;

    system("CLS");

    cout << "Remove product" << endl;
    cout << "Please enter product number : "; cin >> controlNumber;

    if (product_control(controlNumber) == 0) //Checking if there is a user with entered product number. If yes, code will proceed.
    {
        inProduct.close();
        remove("temporary.txt");
        cout << "There is no product With This product number \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to product operations " << endl;

        _getch();
        system("cls");
        productProcedures();
    }
    else
    {
        ofstream temporary("temporary.txt", ios_base::app);
        //Checking and removing product here.
        while (!inProduct.eof())
        {
            inProduct >> product.number;
            inProduct.ignore();
            getline(inProduct, product.name);
            getline(inProduct, product.manufacturer);
            getline(inProduct, product.leadTime);
            inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;

            if (inProduct.eof())
            {
                break;
            }

            if (controlNumber != product.number)
            {
                temporary << product.number << endl;
                temporary << product.name << endl;
                temporary << product.manufacturer << endl;
                temporary << product.leadTime << endl;
                temporary << product.date << endl;
                temporary << product.price << endl;
                temporary << product.primePrice << endl;
                temporary << product.vat << endl;
                temporary << product.stockQuantity << endl << endl;
            }
        }
        cout << "Product successfully removed !" << endl;
        //files closed.
        temporary.close();
        inProduct.close();
        //files removed and renamed.
        remove("product.txt");
        rename("temporary.txt", "product.txt");
    }

    cout << endl;
    cout << "Press any key to return to product operations " << endl;
    _getch();

    system("cls");

    productProcedures();
}

//Created "Add Customer" function.
void customerAdd()
{
    string controlNumber;
    char answer;
    system("cls");
    ofstream inCustomer("customer.txt", ios_base::app); //Opened our customer file for output.
    Customers customer;
    do
    {
        system("cls");
        cout << "Company no : "; cin >> customer.companyNo;
        controlNumber = customer.companyNo;
        if (customer_control(controlNumber) == 1) //Checking here if entered product number registered before. If registered before, "add product menu" will be closed.
        {
            cout << "This company no has already been used, please enter a different company no ! \a " << endl;
            Sleep(2000);
            cout << "\nDo you want to continue customer add operation? (y/n)" << endl;
            string answerexit; cin >> answerexit;
            if (answerexit == "y")
            {
                customerAdd();
            }
            else if (answerexit == "n")
            {
                inCustomer.close();
                customerProcedures();
                return;
            }
        }
        cout << endl;
        cin.ignore();
        cout << "Company name : ";
        getline(cin, customer.companyName);
        cout << endl;
        cout << "Company phone : "; cin >> customer.companyPhone;
        cout << endl;
        cin.ignore();
        cout << "Company manager : ";
        getline(cin, customer.companyManager);
        cout << endl;
        cout << "Customer category (prime or general) : "; cin >> customer.companyCategory;
        cout << endl;
        cin.ignore();
        cout << "Address : ";
        getline(cin, customer.companyAddress);

        inCustomer << customer.companyNo << endl;
        inCustomer << customer.companyName << endl;
        inCustomer << customer.companyPhone << endl;
        inCustomer << customer.companyManager << endl;
        inCustomer << customer.companyCategory << endl;
        inCustomer << customer.companyAddress << endl << endl;

        cout << "Will you add another customer? (y/n) ? "; cin >> answer;
    } while (!(answer == 'n'));

    //Closing file.
    inCustomer.close();

    customerProcedures(); //Return to customer transactions.
}

void customerSearch() //Created method  for customer search 
{
    system("cls");
    string controlNumber;
    cout << " Enter no of customer you are looking for." << endl;
    cin >> controlNumber;
    Customers customer;
    ifstream inCustomer("customer.txt", ios_base::in); //Opened our readers file for input.
    if (customer_control(controlNumber) == 0) //Checking if there is a user with entered customer no. If yes, code will proceed.
    {
        inCustomer.close();

        cout << "There is no company With This company no! \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to customer operations " << endl;

        _getch();
        system("cls");
        customerProcedures();
    }
    else
    {
        while (!(inCustomer.eof()))   //Searching product whose product number was entered.
        {
            inCustomer >> customer.companyNo;
            inCustomer.ignore();
            getline(inCustomer, customer.companyName);
            inCustomer >> customer.companyPhone;
            inCustomer.ignore();
            getline(inCustomer, customer.companyManager);
            inCustomer >> customer.companyCategory;
            inCustomer.ignore();
            getline(inCustomer, customer.companyAddress);
            if (!inCustomer)break; //to get out of the loop
            if (controlNumber == customer.companyNo) //If entered product number matches one in the system.
            {
                cout << "Company Name: " << customer.companyName << endl << "Company Phone: " << customer.companyPhone << endl << " Company Manager: " << customer.companyManager << endl
                    << "Company Category: " << customer.companyCategory << endl << "Address: " << customer.companyAddress << endl;
            }
        }
    }
    inCustomer.close();
    cout << "Press any key to return to customer operations " << endl;
    _getch();

    system("cls");

    customerProcedures();
}

void customerUpdate() //Created "Update customer" function. It let us make some changes about a customer.
{
    system("cls");
    string controlNumber;
    string controlTemp;
    cout << "Enter no of the company you want to update" << endl;
    cin >> controlNumber;
    controlTemp = controlNumber;
    Customers customer;

    if (customer_control(controlNumber) == 0)  //Checking if there is a user with entered customer no. If yes, code will proceed.
    {

        cout << "There is no customer With This company no! \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to customer operations " << endl;

        _getch();
        system("cls");

        customerProcedures();
    }
    else
    {
        //Opened product input file and a temporary output file for product.
        ifstream inCustomer("customer.txt");
        ofstream temporary("temporary.txt", ios_base::app);
        do
        {
            inCustomer >> customer.companyNo;
            inCustomer.ignore();
            getline(inCustomer, customer.companyName);
            inCustomer >> customer.companyPhone;
            inCustomer.ignore();
            getline(inCustomer, customer.companyManager);
            inCustomer >> customer.companyCategory;
            inCustomer.ignore();
            getline(inCustomer, customer.companyAddress);
        } while (controlTemp != customer.companyNo);

        cout << "Company no: "; cin >> customer.companyNo; cout << endl;
        controlNumber = customer.companyNo;
        if (customer_control(controlNumber) == 1) //Checking here if entered product number registered before. If registered before, "add product menu" will be closed.
        {
            cout << "This company no has already been used, please enter a different company no ! \a " << endl;
            Sleep(2000);
            cout << "\nDo you want to continue update customer operation? (y/n)" << endl;
            string answerexit; cin >> answerexit;
            if (answerexit == "y")
            {
                //files closed.
                inCustomer.close();
                temporary.close();
                customerUpdate();
            }
            else if (answerexit == "n")
            {
                //files closed.
                inCustomer.close();
                temporary.close();

                remove("temporary.txt");
                customerProcedures();
            }
        }
        cin.ignore();
        cout << "Company name : ";
        getline(cin, customer.companyName);
        cout << endl;
        cout << "Company phone : "; cin >> customer.companyPhone; cout << endl;
        cin.ignore();
        cout << "Company manager : ";
        getline(cin, customer.companyManager);
        cout << endl;
        cout << "Company category : "; cin >> customer.companyCategory; cout << endl;
        cin.ignore();
        cout << "Company Address : ";
        getline(cin, customer.companyAddress);

        //After changes updated informations will be added in our temporary customer file.
        temporary << customer.companyNo << endl << customer.companyName << endl << customer.companyPhone << endl << customer.companyManager << endl << customer.companyCategory << endl << customer.companyAddress << endl << endl;

        inCustomer.close();
        inCustomer.open("customer.txt");

        //Searching our member which is not matched with entered customer no and adding them in our temporary customer files.
        while (!inCustomer.eof())
        {
            inCustomer >> customer.companyNo;
            inCustomer.ignore();
            getline(inCustomer, customer.companyName);
            inCustomer >> customer.companyPhone;
            inCustomer.ignore();
            getline(inCustomer, customer.companyManager);
            inCustomer >> customer.companyCategory;
            inCustomer.ignore();
            getline(inCustomer, customer.companyAddress);

            if (inCustomer.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlTemp != customer.companyNo)
            {
                temporary << customer.companyNo << endl;
                temporary << customer.companyName << endl;
                temporary << customer.companyPhone << endl;
                temporary << customer.companyManager << endl;
                temporary << customer.companyCategory << endl;
                temporary << customer.companyAddress << endl << endl;
            }
        }

        //files closed.
        temporary.close();
        inCustomer.close();
        //files removed and renamed.
        remove("customer.txt");
        rename("temporary.txt", "customer.txt");
    }
    cout << "Press any key to return to customer operations " << endl;
    _getch();

    system("cls");

    customerProcedures();
}

void customerDelete()
{

    Customers customer;
    string controlNumber;

    system("CLS");

    cout << "Remove customer" << endl;
    cout << "Please enter company no : "; cin >> controlNumber;

    if (customer_control(controlNumber) == 0) //Checking if there is a user with entered customer no. If yes, code will proceed.
    {

        cout << "There is no company With This company no! \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to customer operations " << endl;

        _getch();
        system("cls");
        //file closed.

        customerProcedures();
    }

    else
    {
        //Opened product input file and a temporary output file for product.
        ifstream inCustomer("customer.txt");
        ofstream temporary("temporary.txt", ios_base::app);
        //Checking and removing customer here.
        while (!inCustomer.eof())
        {
            inCustomer >> customer.companyNo;
            inCustomer.ignore();
            getline(inCustomer, customer.companyName);
            inCustomer >> customer.companyPhone;
            inCustomer.ignore();
            getline(inCustomer, customer.companyManager);
            inCustomer >> customer.companyCategory;
            inCustomer.ignore();
            getline(inCustomer, customer.companyAddress);

            if (inCustomer.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlNumber != customer.companyNo)
            {
                temporary << customer.companyNo << endl;
                temporary << customer.companyName << endl;
                temporary << customer.companyPhone << endl;
                temporary << customer.companyManager << endl;
                temporary << customer.companyCategory << endl;
                temporary << customer.companyAddress << endl << endl;
            }
        }
        cout << "Customer successfully removed !" << endl;
        //files closed.
        temporary.close();
        inCustomer.close();
        //files removed and renamed.
        remove("customer.txt");
        rename("temporary.txt", "customer.txt");

        Sleep(2000);
        system("cls");
    }
    cout << "Press any key to return to customer operations " << endl;
    _getch();

    system("cls");

    customerProcedures();
}

//Created "Enter order" function.
void orderEnter()
{
    int order_numb;
    srand(time(0));
    time_t now = time(0);
#pragma warning(suppress : 4996)
    char* time = ctime(&now); //Used ctime for order date.

    system("CLS");
    char answer;
    //Opened our order file and order list file for output.
    ofstream inOrder("order.txt", ios_base::app);
    ofstream inOrderlist("orderList.txt", ios_base::app);
    Orders order;
    Products product;
    do
    {
        system("CLS");

        order_numb = rand(); //Used random values for order.
        cout << "Order Number : " << order_numb << endl;
        inOrder << order_numb << endl;
        inOrderlist << order_numb << endl;
        cout << "Company no : ";
        orderTotal();
        cout << "Order date :" << " " << time;
        inOrder << "orderList.txt" << endl;
        inOrder << time << endl << endl;
        cout << "\n Will you add another order?(y/n) "; cin >> answer;
    } while (!(answer == 'n'));

    //closing file.
    inOrder.close();
    inOrderlist.close();

    orderProcedures(); //Return to order transactions.

    system("CLS");
}

//Created method  for order search
void orderSearch()
{
    system("cls");
    string controlNumber;
    cout << "Enter company no" << endl;
    cin >> controlNumber;
    Orders order;
    Products product;
    ifstream inOrder("order.txt", ios_base::in); //Opened our readers file for input.
    ifstream inOrderlist("orderList.txt", ios_base::in);
    if (customer_control(controlNumber) == 0) //Checking if there is a user with entered customer no. If yes, code will proceed.
    {
        cout << "There is no order With This company no! " << endl;

        Sleep(2000);

        cout << "Press any key to return to order operations" << endl;

        _getch();
        inOrder.close();
        inOrderlist.close();
        orderProcedures();
    }
    else
    {
        while (!(inOrder.eof())) //Searching product whose product number was entered.
        {

            inOrder >> order.orderNumber;
            inOrder >> order.companyNo;
            inOrder.ignore();
            getline(inOrder, order.orderBy);
            inOrder >> order.category;
            inOrder >> order.phone;
            inOrder.ignore();
            getline(inOrder, order.address);
            inOrder >> order.orderTotal;
            inOrder >> order.orderfile;
            inOrder.ignore();
            getline(inOrder, order.orderDate);

            if (!inOrder)break; //If input file comes end loop will stop.
            if (controlNumber == order.companyNo) //If entered product number matches one in the system.
            {
                cout << "Order Number : " << order.orderNumber << endl << "Company No: " << order.companyNo << endl << "Company Name: " << order.orderBy << endl << "Category :" << order.category << endl << "Phone: " << order.phone << endl << "Address: " << order.address << endl << "Order total (VAT included): " << order.orderTotal << endl
                    << "Order file name : " << order.orderfile << endl << "Date : " << order.orderDate << endl;
                int orderControl = order.orderNumber;
                while (!(inOrderlist.eof()))
                {
                    inOrderlist >> order.orderNumber;
                    inOrderlist >> order.singularPrice;
                    inOrderlist >> product.number;
                    inOrderlist >> order.productNumber;
                    inOrderlist >> product.name;
                    inOrderlist >> product.vat;

                    if (!inOrderlist)break;
                    if (orderControl == order.orderNumber)
                    {
                        cout << "Unit price: " << order.singularPrice << endl << "Product number: " << product.number << endl << "Quantity: " << order.productNumber << endl << "Product: " << product.name << endl << "VAT: " << product.vat << endl << endl;
                    }
                }
            }
        }
        //files closed.
        inOrder.close();
        inOrderlist.close();
        cout << "Press any key to return to order operations " << endl;
        _getch();

        system("cls");

        orderProcedures();
    }
}

void orderUpdate() //Created "Update order" function. It let us make some changes about a order.
{
    int newPrice;
    system("cls");
    int controlNumber;

    orderListing(); //function to listing orders.

    int stockNumber;
    string stockUp;

    cout << "Please enter the order number you want to update.." << endl;
    cin >> controlNumber;
    system("cls");

    Orders order;
    Products product;

    //Opened product input file and a temporary output file for product.

    if (order_control(controlNumber) == 0) //Checking if there is a user with entered order number. If yes, code will proceed.
    {
        cout << "There is no order With This order number! \a" << endl;
        Sleep(2000);
        cout << "Press any key to return to order operations " << endl;

        _getch();
        system("cls");

        orderProcedures();
    }
    else
    {
        ifstream inOrderlist("orderList.txt");
        ofstream temporary("temporary.txt", ios_base::app);
        do
        {
            inOrderlist >> order.orderNumber;
            inOrderlist >> order.singularPrice;
            inOrderlist >> product.number;
            inOrderlist >> order.productNumber;
            inOrderlist >> product.name;
            inOrderlist >> product.vat;
        } while (controlNumber != order.orderNumber);

        cout << "Order number : "; cout << order.orderNumber << endl;
        cout << "Unit price : "; cout << order.singularPrice << endl;
        cout << "Product number : "; cout << product.number << endl;
        int old_quantity = order.productNumber;
        cout << "Quantity : "; cin >> order.productNumber;
        cout << "Product : "; cout << product.name << endl;
        cout << "VAT: "; cout << product.vat << endl;

        newPrice = (order.singularPrice * order.productNumber) + (order.singularPrice * order.productNumber * product.vat / 100);

        //After changes updated informations will be added in our temporary orderlist file.
        temporary << order.orderNumber << endl << order.singularPrice << endl << product.number << endl << order.productNumber << endl << product.name << endl << product.vat << endl << endl;
        stockUp = product.number;
        stockNumber = order.productNumber;

        inOrderlist.close();
        inOrderlist.open("orderList.txt");

        //Searching our member which is not matched with entered customer no and adding them in our temporary customer files.
        while (!inOrderlist.eof())
        {
            inOrderlist >> order.orderNumber;
            inOrderlist >> order.singularPrice;
            inOrderlist >> product.number;
            inOrderlist >> order.productNumber;
            inOrderlist >> product.name;
            inOrderlist >> product.vat;
            if (inOrderlist.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlNumber != order.orderNumber)
            {
                temporary << order.orderNumber << endl;
                temporary << order.singularPrice << endl;
                temporary << product.number << endl;
                temporary << order.productNumber << endl;
                temporary << product.name << endl;
                temporary << product.vat << endl << endl;
            }
        }
        //files closed. 
        temporary.close();
        inOrderlist.close();
        //files removed and renamed.
        remove("orderList.txt");
        rename("temporary.txt", "orderList.txt");

        ifstream inOrder("order.txt");
        ofstream temp("temp.txt", ios_base::app);

        do
        {
            inOrder >> order.orderNumber;
            inOrder >> order.companyNo;
            inOrder.ignore();
            getline(inOrder, order.orderBy);
            inOrder >> order.category;
            inOrder >> order.phone;
            inOrder.ignore();
            getline(inOrder, order.address);
            inOrder >> order.orderTotal;
            inOrder >> order.orderfile;
            inOrder.ignore();
            getline(inOrder, order.orderDate);
        } while (controlNumber != order.orderNumber);

        cout << "Order number : "; cout << order.orderNumber << endl;
        cout << "Company no : "; cout << order.companyNo << endl;
        cout << "Customer : "; cout << order.orderBy << endl;
        cout << "Category :"; cout << order.category << endl;
        cout << "Phone: "; cout << order.phone << endl;
        cout << "Address: "; cout << order.address << endl;
        cout << "Order total (VAT included): "; cout << newPrice << endl;
        cout << "Order file name : "; cout << order.orderfile << endl;
        cout << "Date : "; cout << order.orderDate << endl;

        //After changes updated informations will be added in our temporary orderlist file.
        temp << order.orderNumber << endl;
        temp << order.companyNo << endl;
        temp << order.orderBy << endl;
        temp << order.category << endl;
        temp << order.phone << endl;
        temp << order.address << endl;
        temp << newPrice << endl;
        temp << order.orderfile << endl;
        temp << order.orderDate << endl << endl;

        inOrder.close();
        inOrder.open("order.txt");

        //Searching our member which is not matched with entered customer no and adding them in our temporary customer files.
        while (!inOrder.eof())
        {
            inOrder >> order.orderNumber;
            inOrder >> order.companyNo;
            inOrder.ignore();
            getline(inOrder, order.orderBy);
            inOrder >> order.category;
            inOrder >> order.phone;
            inOrder.ignore();
            getline(inOrder, order.address);
            inOrder >> order.orderTotal;
            inOrder >> order.orderfile;
            inOrder.ignore();
            getline(inOrder, order.orderDate);

            if (inOrder.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlNumber != order.orderNumber)
            {
                temp << order.orderNumber << endl;
                temp << order.companyNo << endl;
                temp << order.orderBy << endl;
                temp << order.category << endl;
                temp << order.phone << endl;
                temp << order.address << endl;
                temp << order.orderTotal << endl;
                temp << order.orderfile << endl;
                temp << order.orderDate << endl;
            }
        }
        //Files closed.
        temp.close();
        inOrder.close();

        //Files removed and renamed.
        remove("order.txt");
        rename("temp.txt", "order.txt");

        stock_correction(old_quantity, stockNumber, stockUp);

        cout << "Order updated, Press any key to return to order operations " << endl;
        _getch();

        system("cls");

        orderProcedures();
    }
}

void orderDelete() //Created "Delete order" function.
{
    //Opened order input file and a temporary output file for order.
    ifstream inOrder("order.txt");
    Products product;
    Orders order;
    int controlNumber;
    system("CLS");

    cout << "Remove order" << endl;
    cout << "Please enter order number : "; cin >> controlNumber;

    if (order_control(controlNumber) == 0) //Checking if there is a user with entered order number. If yes, code will proceed.
    {
        cout << "\n There is no order With This order number! \a \n" << endl;
        Sleep(2000);
        cout << "Press any key to return to order operations " << endl;

        _getch();
        system("cls");
        inOrder.close();
        orderProcedures();
    }
    else
    {
        ofstream temporary("temporary.txt", ios_base::app);
        //Checking and removing order here.
        while (!inOrder.eof())
        {
            inOrder >> order.orderNumber;
            inOrder >> order.companyNo;
            inOrder.ignore();
            getline(inOrder, order.orderBy);
            inOrder >> order.category;
            inOrder >> order.phone;
            inOrder.ignore();
            getline(inOrder, order.address);
            inOrder >> order.orderTotal;
            inOrder >> order.orderfile;
            inOrder.ignore();
            getline(inOrder, order.orderDate);

            if (inOrder.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlNumber != order.orderNumber)
            {
                temporary << order.orderNumber << endl;
                temporary << order.companyNo << endl;
                temporary << order.orderBy << endl;
                temporary << order.category << endl;
                temporary << order.phone << endl;
                temporary << order.address << endl;
                temporary << order.orderTotal << endl;
                temporary << order.orderfile << endl;
                temporary << order.orderDate << endl << endl;

            }
        }

        //files closed.
        temporary.close();
        inOrder.close();
        //files removed and renamed.
        remove("order.txt");
        rename("temporary.txt", "order.txt");

        ifstream inOrderlist("orderList.txt", ios_base::in);
        ofstream temp("temp.txt", ios_base::app);
        //Checking and removing order list here.
        while (!inOrderlist.eof())
        {
            inOrderlist >> order.orderNumber;
            inOrderlist >> order.singularPrice;
            inOrderlist >> product.number;
            inOrderlist >> order.productNumber;
            inOrderlist >> product.name;
            inOrderlist >> product.vat;

            if (inOrderlist.eof()) //If input file comes end loop will stop.
            {
                break;
            }

            if (controlNumber != order.orderNumber)
            {
                temp << order.orderNumber << endl;
                temp << order.singularPrice << endl;
                temp << product.number << endl;
                temp << order.productNumber << endl;
                temp << product.name << endl;
                temp << product.vat << endl << endl;
            }
        }
        temp.close();
        inOrderlist.close();
        remove("orderList.txt");
        rename("temp.txt", "orderList.txt");

        cout << "Order successfully removed !" << endl;

        cout << "Press any key to return to order operations " << endl;
        _getch();

        system("cls");

        orderProcedures();
    }
}

void orderReport() //Created "Report order" function.
{
    orderListing();
    cout << "Press any key to return to order operations " << endl;
    _getch();

    system("cls");

    orderProcedures();
}

void orderTotal() //Created function to enter stock quantity and determine category.
{
    Products product;
    Orders order;
    Customers customer;
    // Opened input and output files for order.
    ifstream inProduct("product.txt", ios_base::in);
    ofstream inOrder("order.txt", ios_base::app);
    ofstream inOrderList("orderList.txt", ios_base::app);
    cin >> order.companyNo; cout << endl;
    ifstream inCustomer("customer.txt", ios_base::in);
    while (!(inCustomer.eof()))
    {
        inCustomer >> customer.companyNo;
        inCustomer.ignore();
        getline(inCustomer, customer.companyName);
        inCustomer >> customer.companyPhone;
        inCustomer.ignore();
        getline(inCustomer, customer.companyManager);
        inCustomer >> customer.companyCategory;
        inCustomer.ignore();
        getline(inCustomer, customer.companyAddress);
        if (!inCustomer)break; //If input file comes end loop will stop.
        if (order.companyNo == customer.companyNo)
        {
            order.category = customer.companyCategory;
            inOrder << customer.companyNo << endl;
            inOrder << customer.companyName << endl;
            inOrder << customer.companyCategory << endl;
            inOrder << customer.companyPhone << endl;
            inOrder << customer.companyAddress << endl;
        }

    }
    inCustomer.close();
    cout << "Please enter number of the product you want to add " << endl << endl;
    string controlNumber;
    cin >> controlNumber;
    string stockUp = controlNumber;
    int stockNumber;
    while (!(inProduct.eof()))
    {
        inProduct >> product.number;
        inProduct.ignore();
        getline(inProduct, product.name);
        getline(inProduct, product.manufacturer);
        getline(inProduct, product.leadTime);
        inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;
        if (!inProduct)break; //If input file comes end loop will stop.
        if (controlNumber == product.number)
        {
            cout << product.name << endl << "prime : " << product.primePrice << " " << "general : " << product.price << endl << "Customer is " << order.category << endl;
            cout << "Quantity you want to buy (" << "Current stock :" << product.stockQuantity << ")----->  ";  cin >> order.productNumber;

            if (order.productNumber > product.stockQuantity)
            {
                cout << "Not enough stock. Delivery time may be extended \a !" << endl;
            }
            stockNumber = order.productNumber;
            //Pricing according to customer and add vat.
            if (order.category == "prime")
            {
                order.orderTotal = (product.primePrice * order.productNumber) + (product.primePrice * order.productNumber * product.vat / 100);
                inOrderList << product.primePrice << endl;
            }
            else
            {
                order.orderTotal = (product.price * order.productNumber) + (product.price * order.productNumber * product.vat / 100);
                inOrderList << product.price << endl;
            }
            cout << "Order total (VAT included): " << order.orderTotal << endl;
            inOrder << order.orderTotal << endl;
            inOrderList << product.number << endl;
            inOrderList << order.productNumber << endl;
            inOrderList << product.name << endl;
            inOrderList << product.vat << endl << endl;

            inProduct.close();
            inOrder.close();
            inOrderList.close();
        }
    }
    stock_update(stockNumber, stockUp); //Function parameters for stock update.
}

void orderListing() //Created function to listing orders.
{
    system("cls");
    Orders order;
    ifstream inOrder("order.txt", ios_base::in);
    if (!inOrder) //if there is no data in "product.txt" file.
    {
        system("cls");
        cerr << "Error opening file" << endl;

        cout << "Press any key to return to order operations " << endl;
        _getch();
        system("cls");
        orderProcedures();

        inOrder.close();
    }
    else
    {
        while (!(inOrder.eof()))
        {
            inOrder >> order.orderNumber;
            inOrder >> order.companyNo;
            inOrder.ignore();
            getline(inOrder, order.orderBy);
            inOrder >> order.category;
            inOrder >> order.phone;
            inOrder.ignore();
            getline(inOrder, order.address);
            inOrder >> order.orderTotal;
            inOrder >> order.orderfile;
            inOrder.ignore();
            getline(inOrder, order.orderDate);
            if (!inOrder)break;
            cout << "Order number :" << order.orderNumber << endl << "Company Number : " << order.companyNo << endl << "Company Name: " << order.orderBy << endl << "Category: " << order.category << endl << "Customer Phone: " << order.phone << endl << "Address: " << order.address << endl << "Order total (VAT included): " << order.orderTotal << endl
                << "Order file: " << order.orderfile << endl << "Date : " << order.orderDate << endl << endl;
        }
        inOrder.close();
    }
}

void stock_update(int stockNumber, string stockUp) //Stock update when order is entered
{
    Products product;

    //Opened product input file and a temporary output file for update product stock.
    ifstream inProduct("product.txt", ios_base::in);
    ofstream temp("temporary0.txt", ios_base::app);

    do
    {
        inProduct >> product.number;
        inProduct.ignore();
        getline(inProduct, product.name);
        getline(inProduct, product.manufacturer);
        getline(inProduct, product.leadTime);
        inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;
    } while (stockUp != product.number);

    product.stockQuantity = product.stockQuantity - stockNumber; //Mathematical operation for stock update.

        //After changes updated informations will be added in our temporary orderlist file.
    temp << product.number << endl << product.name << endl << product.manufacturer << endl << product.leadTime << endl << product.date << endl << product.price << endl << product.primePrice << endl << product.vat << endl << product.stockQuantity << endl << endl;

    inProduct.close();
    inProduct.open("product.txt");

    //Searching our member which is not matched with entered customer no and adding them in our temporary customer files.
    while (!inProduct.eof())
    {
        inProduct >> product.number;
        inProduct.ignore();
        getline(inProduct, product.name);
        getline(inProduct, product.manufacturer);
        getline(inProduct, product.leadTime);
        inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;

        if (inProduct.eof())
        {
            break;
        }

        if (stockUp != product.number)
        {
            temp << product.number << endl;
            temp << product.name << endl;
            temp << product.manufacturer << endl;
            temp << product.leadTime << endl;
            temp << product.date << endl;
            temp << product.price << endl;
            temp << product.primePrice << endl;
            temp << product.vat << endl;
            temp << product.stockQuantity << endl << endl;
        }
    }

    //files closed.
    temp.close();
    inProduct.close();
    //files removed and renamed.
    remove("product.txt");
    rename("temporary0.txt", "product.txt");
}

void stock_correction(int old_quanity, int stockNumber, string stockUp) //Stock update when order is update.
{
    Products product;

    //Opened product input file and a temporary output file for update product stock.
    ifstream inProduct("product.txt", ios_base::in);
    ofstream temp1("temporary1.txt", ios_base::app);

    do
    {
        inProduct >> product.number;
        inProduct.ignore();
        getline(inProduct, product.name);
        getline(inProduct, product.manufacturer);
        getline(inProduct, product.leadTime);
        inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;
    } while (stockUp != product.number);

    product.stockQuantity = product.stockQuantity + (old_quanity - stockNumber); //Mathematical operation for stock update.

    //After changes updated informations will be added in our temporary orderlist file.
    temp1 << product.number << endl << product.name << endl << product.manufacturer << endl << product.leadTime << endl << product.date << endl << product.price << endl << product.primePrice << endl << product.vat << endl << product.stockQuantity << endl << endl;

    inProduct.close();
    inProduct.open("product.txt");

    //Searching our member which is not matched with entered customer no and adding them in our temporary customer files.
    while (!inProduct.eof())
    {
        inProduct >> product.number;
        inProduct.ignore();
        getline(inProduct, product.name);
        getline(inProduct, product.manufacturer);
        getline(inProduct, product.leadTime);
        inProduct >> product.date >> product.price >> product.primePrice >> product.vat >> product.stockQuantity;

        if (inProduct.eof())
        {
            break;
        }

        if (stockUp != product.number)
        {
            temp1 << product.number << endl;
            temp1 << product.name << endl;
            temp1 << product.manufacturer << endl;
            temp1 << product.leadTime << endl;
            temp1 << product.date << endl;
            temp1 << product.price << endl;
            temp1 << product.primePrice << endl;
            temp1 << product.vat << endl;
            temp1 << product.stockQuantity << endl << endl;
        }
    }

    //files closed.
    temp1.close();
    inProduct.close();
    //files removed and renamed.
    remove("product.txt");
    rename("temporary1.txt", "product.txt");
}

//Created "Exit" function.
void exit()
{
    mainMenu();
}



