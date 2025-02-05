#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    
    static const string FileName; // إضافة تعريف اسم الملف

    static clsBankClient _ConvertLinetoObject(string line, string separator = "#//#")
    {
        vector<string> vClientData = clsString::splitstring(line, separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
                             vClientData[4], vClientData[5], stod(vClientData[6]));
    }
     static string ConvertRecordToLine(clsBankClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.GetFirstName() + Seperator;  // استخدام GetFirstName()
    stClientRecord += Client.GetLastName() + Seperator;   // استخدام GetLastName()
    stClientRecord += Client.GetEmail() + Seperator;      // استخدام GetEmail()
    stClientRecord += Client.GetPhone() + Seperator;      // استخدام GetPhone()
    stClientRecord += Client.AccountNumber() + Seperator;
    stClientRecord += Client.GetPinCode() + Seperator;   // استخدام GetPinCode()
    stClientRecord += to_string(Client.GetAccountBalance()); // استخدام GetAccountBalance()
    return stClientRecord;
}

     static vector<clsBankClient>LoadClientsDataFromFile() // تصحيح اسم الدالة
    {
        vector<clsBankClient>vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // وضع القراءة

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                 clsBankClient Client = _ConvertLinetoObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }
    
    
  public:
    static void AddDataLineToFile(clsBankClient Client)
    {
    string s1 = ConvertRecordToLine(Client);

    fstream MyFile;
    MyFile.open("Clients.txt", ios::out | ios::app);
    
    if (MyFile.is_open()) {
        MyFile << s1 << endl;
        MyFile.close();
       }
  }
  static void AddNewClientDataLineToFile(clsBankClient Client) {
    string s1 = ConvertRecordToLine(Client);
    fstream MyFile;
    MyFile.open("Clients.txt", ios::out | ios::app);
    
    if (MyFile.is_open()) {
        MyFile << s1 << endl;
        MyFile.close();
        cout << "Client record added successfully!\n\n"; // ✅ رسالة تأكيد
    } else {
        cout << "Error: Could not open file!\n";
    }
}
 public:                
    static clsBankClient _GetEmptyClientMode()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0.000);
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
                  string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << GetFirstName();
        cout << "\nLastName    : " << GetLastName();
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << GetEmail();
        cout << "\nPhone       : " << GetPhone();
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in); // استخدام المتغير FileName

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                clsBankClient Client = _ConvertLinetoObject(line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientMode();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in); // استخدام المتغير FileName

        if (MyFile.is_open())
        {
            string line;
            while (getline(MyFile, line))
            {
                clsBankClient Client = _ConvertLinetoObject(line);
                if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientMode();
    }

    bool IsEmpty()
    {
        return _AccountNumber.empty();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
};

// تعريف `FileName` خارج الكلاس
const string clsBankClient::FileName = "Clients.txt";
