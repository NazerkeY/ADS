#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
	char value;
	Node *ch[10];
	int cnt;
	bool isend;

	Node(char value) {
		this->value = value;
		this->cnt = 0;
		this->isend = false;
		for (int i = 0; i < 10; i++)
			this->ch[i]=NULL;
	}
};

bool ok  = true;

class Trie {
	public:
	Node *root;
	Trie() {
		root = new Node(' ');
	}

	void insert(string s) {
		Node *cur = root;
		for (int i = 0; i < s.size(); i++) {
			if (cur->ch[s[i]-'0'] != NULL)
				cur = cur->ch[s[i]-'0'];
			else {
				Node *node = new Node(s[i]);
				cur->ch[s[i]-'0'] = node;
				cur = node;
			}
			if (i == s.size()-1) {
				//cout << cur->value << endl;
				cur->isend = true;
			}
		}
	}

	void search(Node *node) {
	    if (node == NULL)
	      return;
	    if (node->isend) {
	    	int has = false;
	    	//cout << node->value << "--->";
	    	for (int i = 0; i < 10; i++)
	    		if (node->ch[i]!=NULL) {
	    			//cout << node->ch[i]->value << " ";
	    			has = true;
	    		}
	    	if (has)
	    		ok = false;
	    }

	    for (int i = 0; i < 10; i++) {
	      search(node->ch[i]);
	    }
  }

};

void solve() {
	Trie *trie = new Trie();
	int n;
	cin >> n;
	ok = true;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		reverse(num.begin(), num.end());
		trie->insert(num);
	}
	trie->search(trie->root);

	if (ok)
		cout << "YES";
	else cout << "NO";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
		solve();
}