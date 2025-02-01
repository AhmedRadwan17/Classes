#include <iostream>
#include "clsString.h"
using namespace std;
int main() { 
clsString String1;

String1.SetValue("Ali Radwan");
  
cout<<"String1: "<<String1.GetValue()<<endl; 
cout<<"CountLetters: "<<String1.CountWords()<<endl;
cout<<"SmallCase: "<<String1.LowerCase()<<endl;
cout<<"UpeerCase: "<<String1.UpperCase()<<endl;
cout <<"ReverseString: " << String1.ReverseString(String1.GetValue()) << endl;
cout<<"Vowels: "; 
String1.PrintVowels();
cout<<"\nCountVowels: "<<String1.CountVowels()<<endl;

}