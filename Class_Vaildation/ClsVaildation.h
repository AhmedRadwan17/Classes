#pragma once 
#include <iostream>
#include <string>
#include <limits>
using namespace std;
class clsVaildate
{
 public:

 static bool IsNumberBetween(int Number , int From , int To)
{
  if(Number>From&&Number<To)
  {
   return true;
  }
  return false;
}
static bool IsNumberBetween(double Number , double From , double To)
{
  if(Number>From&&Number<To)
  {
   return true;
  }
  return false;
}
static int ReadIntNumber()
  {
    int Number;
    while (!(cin >> Number)) 
  {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"Invalid Number, Enter again\n";
    }
    return Number;
  }
static double ReaddoubleNumber()
  {
    double Number;
    while (!(cin >> Number)) 
  {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"Invalid Number, Enter again\n";
    }
    return Number;
  }
static int ReadintNumberBetween(int From, int To)
{
string Text = " Number is not within range , please enter Number?";
  int Number;
  do{
  
cout<<"Please, Enter Number Between (From:"<<From<<"-"<<"To:"<<To<<")?";
  }while(!(cin>>Number)||!(IsNumberBetween(Number,From,To)));
  return Number; 
}
static double ReaddoubleNumberBetween(double From, double To)
{
  double Number;
  do{
  
cout<<"Please, Enter Number Between (From:"<<From<<"-"<<"To:"<<To<<")?";
  }while(!(cin>>Number)||!(IsNumberBetween(Number,From,To)));
  return Number; 
}

};
