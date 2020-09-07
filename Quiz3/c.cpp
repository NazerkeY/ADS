#include<iostream>
#include <vector>
using namespace std;
int main()
{
  string s;
  int n;
  int maxi = 0;
  cin >> s;
  cin >> n;
  string a[n];
  vector<int> v;
  vector<string> result;
  for( int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i][0] += 32;
    string text = a[i] + "@" + s;
    vector<int> data;
    data.push_back(0);
    for( int k = 1; k < text.size(); k++)
    {
      int j = data[k - 1];
      while(j > 0 && text[k] != text[j])
        j = data[j - 1];
      if(text[j] == text[k])
        j++;
      data.push_back(j);
    }
    v.push_back(data[data.size() - 1]);
    maxi = max(maxi, data[data.size() - 1]);
  }
  for( int i = 0; i < n; i++)
  {
    if(v[i] == maxi)
      result.push_back(a[i]);
  }
  cout << result.size() << endl;
  for( int i = 0; i < result.size(); i++)
  {
    result[i][0] -= 32;
    cout << result[i] << endl;
  }
  for(int i = 0 ; i < j; i++)
  cout<<result[i - j] << " ";
  
}