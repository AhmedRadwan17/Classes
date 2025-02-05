#include <iostream>
#include "clsBankClient.h"
#include "clsVaildation.h"  
using namespace std;

clsBankClient ReadClientInfo()
{
    // إنشاء كائن فارغ باستخدام الدالة `_GetEmptyClientMode()`
    clsBankClient Client = clsBankClient::_GetEmptyClientMode();

    cout << "\nEnter FirstName: ";
    Client.SetFirstName(clsVaildate::ReadString());

    cout << "\nEnter LastName: ";
    Client.SetLastName(clsVaildate::ReadString());

    cout << "\nEnter Email: ";
    Client.SetEmail(clsVaildate::ReadString());

    cout << "\nEnter Phone: ";
    Client.SetPhone(clsVaildate::ReadString());

    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsVaildate::ReadString());

    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsVaildate::ReadFloatNumber());

    return Client;
}

int main() 
{
    char ReadChoice = 'y';
    string AccountNumber;

    cout << "Enter Account Number: ";
    cin >> AccountNumber;

    while (!clsBankClient::IsClientExist(AccountNumber))  
    {
        cout << "\nAccountNumber is not found, Choose another one: ";
        cout << "\nAre you want to add new client? (y/n): ";
        cin >> ReadChoice;
        cin.ignore(); 

        if(ReadChoice == 'y' || ReadChoice == 'Y')
        {
            clsBankClient Client = ReadClientInfo();
            clsBankClient::AddNewClientDataLineToFile(Client);
            cout << "\nData has been saved successfully ";
            Client.Print();
        }
    }

    return 0;
}
