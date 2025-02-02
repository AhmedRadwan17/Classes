#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class clsUtility
{
public:
    static void Srand()
    {
        srand(time(0));
    }

    static int RandomNumber(int from, int to)
    {
        return rand() % (to - from + 1) + from;
    }

    enum enNumberType { smallLetter = 1, capitalLetter = 2, specialCharacter = 3, digit = 4 };

    static char GetLetter(enNumberType NumberType)
    {
        if (NumberType == enNumberType::smallLetter)
            return char(RandomNumber(97, 122));
        else if (NumberType == enNumberType::capitalLetter)
            return char(RandomNumber(65, 90));
        else if (NumberType == enNumberType::specialCharacter)
            return char(RandomNumber(33, 47));
        else
            return char(RandomNumber(48, 57));
    }

    static string GenerateWord(enNumberType NumberType, short length)
    {
        string sWord = "";
        for (int i = 0; i < length; i++)
        {
            sWord += GetLetter(NumberType);
        }
        return sWord;
    }

    static string GenerateKey(enNumberType NumberType = capitalLetter)
    {
        string key = "";
        for (int i = 0; i < 4; i++)
        {
            key += GenerateWord(NumberType, 4);
            if (i < 3) key += "-";
        }
        return key;
    }

    static void GenerateKeys(short NumberOfKeys, enNumberType NumberType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [ " << i << " ] : " << GenerateKey(NumberType) << endl;
        }
    }

    // Swap Functions
    static void Swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    static void Swap(double& a, double& b)
    {
        double temp = a;
        a = b;
        b = temp;
    }

    static void Swap(char& A, char& B)
    {
        char temp = A;
        A = B;
        B = temp;
    }

    static void Swap(bool& N, bool& H)
    {
        bool temp = N;
        N = H;
        H = temp;
    }

    static void Swap(string& C, string& D)
    {
        string temp = C;
        C = D;
        D = temp;
    }

    // Random Array Generation
    static void RandomArray(int ar[], int length, int From, int To)
    {
        for (int i = 0; i < length; i++)
        {
            ar[i] = RandomNumber(From, To);
        }

        cout << "Array is: ";
        for (int i = 0; i < length; i++)
        {
            cout << ar[i] << " ";
        }
        cout << "\n";
    }

    // Encryption Function
    static string Encryption(string Text, int Key)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + Key);
        }
        return Text;
    }

    // Decryption Function
    static string Decryption(string Text, int Key)
    {
   string Text1 = Encryption(Text,Key);
        for (int i = 0; i < Text1.length(); i++)
        {
            Text1[i] = char((int)Text1[i] - Key);
        }
        return Text1;
    }
static void RandomArrayWithWords(string ar1[100],short length,string Choice)
{
    for(int i =0;i<length;i++)
        {          ar1[i]=GenerateWord(enNumberType::capitalLetter,length);
         }
        
      for(int i=0;i<length;i++)
          {
            cout<<ar1[i]<<" ";
          }
}
static  void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
for(int i =0;i<arrLength;i++)
            {
             cout<<arr[i]<<" "; 
            }
    }
};
