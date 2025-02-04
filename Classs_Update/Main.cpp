#include <iostream>
#include "clsVaildation.h"
#include "clsBankClient.h"
using namespace std;

void ReadClientInfo(clsBankClient &Client)
{
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
}

void UpdateClient()
{
    char readchoice = 'y';
    string AccountNumber;
    cout << "\nPlease Enter AccountNumber: ";
    AccountNumber = clsVaildate::ReadString();
    
    // التحقق من وجود العميل
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccountNumber is not found, Choose another one: ";
        AccountNumber = clsVaildate::ReadString();
    }

    // إيجاد العميل وطباعته
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    // التأكد إذا كان المستخدم يريد تحديث بيانات العميل
    cout << "Do you want to update this client? (y/n): ";
    cin >> readchoice;

    if (readchoice == 'y' || readchoice == 'Y')
    {
        // تحديث بيانات العميل
        ReadClientInfo(Client1);
        
        // حفظ التحديثات في الملف
        clsBankClient::AddDataLineToFile(Client1);
        cout << "\nClient data updated successfully!\n";
        Client1.Print();
    }
}

int main()
{
    // اختبار الدالة UpdateClient
    UpdateClient();

    return 0;
}
