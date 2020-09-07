#include <iostream>
using namespace std;
string getPrefSuf(string s1, string s2, int l){
     string prefix = s1.substr(0, l);
     string suffix = s2.substr(s2.size() - l);
     return prefix + suffix;
}
int main(){
     string a, b;
     int g;
     cin >> a >> b >> g;
     cout << getPrefSuf(a, b, g);
     return 0;
}