#include <bits/stdc++.h>
//In the ﬁrst example t is ’abcabc’, answer is 3 because ’abcabc’ can be made from 2 copies of ’abc’.

using namespace std;

vector <int> prefix(string s) {
	int n = s.size();
	vector <int> p(n);
	p[0]=0;
	for (int i = 1; i < n; i++) {
		int k = p[i-1];
		while(k > 0 && s[i] != s[k]) {
			k = p[k-1];
		}
		if (s[i] == s[k])
			p[i] = k+1;
		else p[i]=0;
	}
	return p;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector <int> p = prefix(s);
	int m = n-p[n-1];
	if (n%m==0)
		cout << m;
	else cout << 1;
	
	return 0;
}