// 2              //4
// aba            //aba
// bab
// ababababac

#include <bits/stdc++.h>

using namespace std;

vector <int> prefix(string pattern) {
	int n = pattern.size();
	vector <int> p(n);
	p[0]=0;
	for (int i = 1; i < n; i++) {
		int k = p[i-1];
		while(k > 0 && pattern[i]!=pattern[k])
			k++;
		if (pattern[i]==pattern[k])
			p[i]=k+1;
		else p[i]=0;
	}
	return p;
}

int main() {
	int n;
	cin >> n;
	vector <string> words;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}

	string s;
	cin >> s;
	map <string, int> freq;
	int maxi = 0;

	for (string word : words) {
		vector <int> p = prefix(word);
		int i = 0;
		int j = 0;
		int cnt = 0;
		//KMP
		while(i < s.size()) {
			if (word[j]==s[i]) {
				i++;
				j++;
			}

			if (j == word.size()) {
				freq[word]=++cnt;
				j = p[j-1];
			}
			else if (i < s.size() && word[j]!=s[i]) {
				if (j != 0)
					j = p[j-1];
				else i++;
			}
		}
		maxi = max(maxi, cnt);
	}
	
	cout << maxi << endl;
	for (auto x : freq) {
		if (x.second == maxi)
			cout << x.first << endl;
	}
}