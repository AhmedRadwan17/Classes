#pragma once 

#include <iostream>
#include <windows.h>
using namespace std;

class clsHour
{
  private:
          int _Hour=0;
          int _Mintue=0;
          int _Second=0;
          bool _Found = true;
 public:
       clsHour(int Hour , int Mintue , int Second,bool Found=true)
       {
         _Hour = Hour;
         _Second = Second;
         _Mintue = Mintue;
         _Found = Found;
       }
    void StartClock()
    {
      while(_Found)
      {
           system("cls");
        if(_Second>59)
        {
        _Mintue++;
        _Second=0;
        }
        if(_Mintue>59)
        {
          _Hour++;
          _Mintue=0;
        }
        if(_Hour>23)
        {
          _Hour=0;
        }
    cout << "Hour: " << _Hour << ":" << _Mintue << ":" << _Second << endl;
     _Second++;
     Sleep(1000);
    }  
  }
  
};
