#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
class clsString
{
private:
string _value;
public:
clsString()
{
  _value = "";
}
clsString(string value)
{
  _value = value;
}
void SetValue(string value)
{
  _value = value;
}
string GetValue()
{
  return _value;
}
 static short CountWords(string s1)
{
  short pos = 0;
  string delim = " ";
  string sWord;
  short counter =0;
  while((pos=s1.find(delim))!=std:: string::npos)
    {
      sWord = s1.substr(0,pos);
      if(sWord!="")
      {
        counter++;
      }
s1.erase(0,pos+ delim.length());
    }
      if(s1!="")
      {
        counter++;
      }
      return counter;
    }
short CountWords()
{
  return CountWords(_value);
}
vector<string>splitstring(string s1,string delim )
{
    short pos =0;
    string sWord="";
  vector<string>vstring;
    while((pos=s1.find(delim))!=string::npos)
     {
        sWord=s1.substr(0,pos);
        if(sWord!="")
        {
        vstring.push_back(sWord);
        }
         s1.erase(0,pos+delim.length());
     }
      if(s1!="")    
      {
          vstring.push_back(s1);
      }
       return vstring;
}
 string ReverseString(string s1)
{
    vector <string>so;
    string s2="";
    so=splitstring(s1," ");
    vector<string>::iterator iter=so.end();
    while(iter!=so.begin())
    {
        iter--;
        s2+=*iter+" ";
    }
 s2=s2.substr(0,s2.length()-1);
 return s2;
}
 static string UpperCase(string s1)
{
  string s2="";
  for(int i = 0;i<s1.length();i++)
    {
      s2+=toupper(s1[i]);
    }
  return s2;
}
string UpperCase()
{
  return UpperCase(_value);
}
static string LowerCase(string s1)
{
  string s2 = "";
  for(int i = 0;i<s1.length();i++)
    {
      s2 +=tolower(s1[i]);
    }
  return s2;
}
string LowerCase()
{
  return LowerCase(_value);
}
string ReplaceWordInString(string s1 , string ToReplace,string replaceWith)
{
  short pos = s1.find(ToReplace);
  while(pos!=std::string::npos)
  {
    s1.replace(pos,ToReplace.length(),replaceWith);
    pos = s1.find(ToReplace);
  }
  return s1;
}
static string RemovePunctionFromString(string s1)
{
  string s2="";
  for(int i = 0;i<s1.length();i++)
    {
      if(!ispunct(s1[i]))
        {
          s2+=s1[i];
        }
    }
  return s2;
}
string RemovePunctionFromString()
{
  return RemovePunctionFromString(_value);
}
static void PrintVowels(string s1)
{ 
  for(int i = 0; i < s1.length(); i++)
  {
      s1[i] = tolower(s1[i]);
    if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u')
    {
      
      cout<<s1[i]<<" ";
    }
  }
}
void PrintVowels()
{
  PrintVowels(_value); 
}
 string CountVowels(string s1)
{
  short counter = 0;
  for(int i = 0; i < s1.length(); i++)
  {
   
      s1[i] = tolower(s1[i]);
    if(s1[i]=='a' || s1[i]=='e' || s1[i]=='i' || s1[i]=='o' || s1[i]=='u')
    {
      
      counter++;
    }
  }
  return to_string(counter);
}
string CountVowels()
{
  return CountVowels(_value);
}
string JoinString(vector<string>vstring, string delim)
{
    string s1="";
    for(string &s: vstring)
    {
        s1=s1+s+delim;
    }
return s1.substr(0,s1.length()-delim.length());
}
string ReplaceWoeInString(string s1, string StringToReplace, string sReplaceTo,bool matchcase=true)
{
vector<string>vstring=splitstring(s1," ");

   for(string &s:vstring)
   {
    if(matchcase)
    {
        if(s==StringToReplace)
        {
            s=sReplaceTo;
        }
    }
    else
    {
        if(LowerCase(s)==LowerCase(StringToReplace))
        {
            s=sReplaceTo;
        }
    }
   }
   return JoinString(vstring," ");
}
};