#include<bits/stdc++.h>
using namespace std;
int main()
{
  string p;
  cin >> p;
  int n;
  int mx = 0;
  cin >> n;
  string a[n];
  vector<int> pr;
  vector<string> result;
  for( int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i][0] += 32;
    string text = a[i] + "@" + p;
    vector<int> kmp;
    kmp.push_back(0);
    for( int k = 1; k < text.size(); k++)
    {
      int j = kmp[k - 1];
      while(j > 0 && text[j] != text[k])
        j = kmp[j - 1];
      if(text[j] == text[k])
        j++;
      kmp.push_back(j);
    }
    pr.push_back(kmp[kmp.size() - 1]);
    mx = max(mx, kmp[kmp.size() - 1]);
  }
  for( int i = 0; i < n; i++)
  {
    if(pr[i] == mx && pr[i] > 0)
      result.push_back(a[i]);
  }
  cout << result.size() << "\n";
  for( int i = 0; i < result.size(); i++)
  {
    result[i][0] -= 32;
    cout << result[i] << "\n";
  }
}