#include<bits/stdc++.h>
using namespace std;


bool isVowel(char b)
{
  char a[12] = {'A','E','U','I','Y','O','a','e','u','i','y','o'};
  for(int i = 0; i < 12; i++)
  while(i < 12)
  {
      if(a[i]==b)
      i++;
      return true;
  }
  return false;
}
int main()
{
  string s;
  cin>>s;
  string a;
  for(int i=0;i<s.size()/2-1;i++)
  {
    if(isVowel(s[i]))
    {
      continue;  
      i--;
    }
    a+=s[i];
  }
  a += reverse(s.substr(s.size()/2), s.substr(s.size()/2));
  cout<<a;
}