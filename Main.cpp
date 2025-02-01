#include <iostream>
#include <iomanip>
#include "clsDate.h"  

using namespace std;

int main()
{ 
    clsUtility::Srand();
    
    cout <<"Random Number: " << clsUtility::RandomNumber(1, 10) << endl;
    cout <<"Random Letter: " << clsUtility::GetLetter(clsUtility::smallLetter) << endl;
    cout<<"Word: "<<clsUtility::GenerateWord(clsUtility::smallLetter,5)<<endl;
    cout<<"\n";
   cout<<"Key: "<<clsUtility::GenerateKey()<<endl;
clsUtility::GenerateKeys(5,clsUtility::smallLetter);
    cout<<endl;
    int x = 10, y = 13;
    clsUtility::Swap(x, y);
    cout<<left<<"After Swap (int): x = " << x << ", y = " << y << endl;

    double a = 11.5, b = 12.5;
    clsUtility::Swap(a, b);
    cout <<"After Swap (double): a = " << a << ", b = " << b << endl;

    char A = 'A', B = 'B';
    clsUtility::Swap(A, B);
    cout <<"After Swap (char): A = " << A << ", B = " << B << endl;
    
    string C = "Iam a man", D = "Iam a Woman";
    clsUtility::Swap(C, D);
    cout <<"After Swap (string): C = " << C << ", D = " << D << endl;
    bool E = true, F = false;
    clsUtility::Swap(E,F);
    cout <<"After Swap (bool): E = " << E << ", F = " << F << endl;
   cout<<"\n";
    int ar[100];
clsUtility::RandomArray(ar,5,1,10);
    cout<<"\n";
 string Text = "Iam Very Happy To Know That You Get A High Marks in OOP.";
cout<<"Before Encryption: \n"<<clsUtility::Decryption(Text,2)<<endl;
cout<<"After Encryption: \n"<<clsUtility::Encryption(Text,2)<<endl;
    cout<<"\n";

 string ar1[100];
cout<<"Random Array with Words: ";
clsUtility::RandomArrayWithWords(ar1,2,"Capital");
cout<<"\n\n";
int arr[100]= {1,2,3,4,5,6};
cout<<"Before suffle Array: ";
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
cout<<"After Suffle Array: ";
clsUtility::ShuffleArray(arr,6);
    
}