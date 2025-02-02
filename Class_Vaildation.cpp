#include <iostream>
#include <string>
#include "clsInputValidate.h"
using namespace std;

int main() 
{
 cout<<"Bool (Int) Number return: "<<clsVaildate::IsNumberBetween(5, 1 , 10)<<endl;
cout<<"Bool (double) Number return: " <<clsVaildate::IsNumberBetween(5.5,1.1,10.0)<<endl;
  
cout<<"enter x?";
 int x = clsVaildate::ReadIntNumber();
 cout<<"x: "<<x<<endl;
  cout<<"enter y?";
double y =clsVaildate::ReaddoubleNumber();
cout<<"y: "<<y<<endl;
int z =clsVaildate::ReadintNumberBetween(1,10);
cout<<"z: "<<z<<endl;
 cout<<"enter A? ";
int A = clsVaildate ::ReaddoubleNumberBetween(1.1,10.5);
cout<<"A: "<<A<<endl;
system("pause");
}
