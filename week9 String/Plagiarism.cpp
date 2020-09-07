//kbtuutbkkbtu utbkkbtukbtu kbtu
//1
#include <bits/stdc++.h>

using namespace std;

vector <int> computeLPS(string s) {
	vector <int> p(s.size());
	p[0]=0;
	for (int i = 1; i < s.size(); i++) {
		int k = p[i-1];
		while(k > 0 && s[i] != s[k])
			k = p[k-1];
		if (s[i]==s[k])
			p[i]=k+1;
		else p[i]=0;
	}
	return p;
}

vector <int>  KMPSearch(string text, string pat) {
	int n = text.size();
	int m = pat.size();
	vector <int> lps = computeLPS(pat);
	vector <int> res;
	int i = 0;
	int j = 0;
	while(i < n) {
		if (pat[j]==text[i]) {
			j++;
			i++;
		}
		if (j == m) {
			res.push_back(i-j);
			//cout << i - j << " ";
			j = lps[j-1];
		}
		else if (i < n && pat[j]!=text[i]) {
			if (j != 0)
				j = lps[j-1];
			else i++;
		}
	}
	return res;

}



int main() {
	string a, b, k;
	cin >> a >> b >> k;
	vector <int> f = KMPSearch(a, k);
	//cout << endl;
	vector <int> s = KMPSearch(b, k);
	
	vector <int> inter(f.size());
	auto it = set_intersection(f.begin(), f.end(), s.begin(), s.end(), inter.begin());
	cout << (it - inter.begin());

	int ans = 0;
}