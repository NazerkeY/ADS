#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> prefix(string s)
{
  int n =  s.size();
  vector<int> p(n);
  p[0]  = 0;
  for(int i = 1; i < n; i++)
  {
    int j = p[i - 1];
    while(s[i] != s[j] && j > 0) 
    j = p[j - 1];
    if(s[i] == s[j])
    j++;
    p[i] = j; 
  }
  return p;
}

vector<int> KMP(string s,string t)
{
  string s1 = t + "@" + s;
  vector<int> p = prefix(s1);
  vector<int> pStr ;
  for(int i = 0; i < s1.size(); i++)
    if(p[i] == t.size())
    {
      pStr.push_back(i - t.size() - t.size());
    }
  return pStr;  
}

bool comparator(pair<string,int>&firstElem , pair<string,int>&secondElem)
{
  return firstElem.second < secondElem.second;
}

int main()
{
  string s,t;
  while(true)
  {
  int n;
  cin >> n;
  if(n == 0)
  return 0; 
  vector<string> str;
  for(int i = 0; i < n; i++)
  {
    string s1;
    cin >> s1;
    str.push_back(s1);
  }
  string substr;
  cin >> substr;
  vector<pair<string,int> >pairstr;
  for(int i = 0; i < str.size();i++)
  {
    vector<int> pi = KMP(substr,str[i]);

    pairstr.push_back(make_pair(str[i], pi.size()));
  }
  sort(pairstr.begin(), pairstr.end(), comparator);

  int mx=pairstr[pairstr.size() - 1].second;

  cout<<pairstr[pairstr.size() - 1].second << endl; 
  cout << pairstr[pairstr.size() - 1].first << endl;
  
   
  }  
}