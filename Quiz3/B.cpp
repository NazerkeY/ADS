#include <iostream>
using namespace std;

class Node{
     public:
     char data;
     Node *ch[26];
     Node(char data){
          this->data = data;
          for(int i = 0; i < 26; i++){
               this->ch[i] = NULL;
          }
     }
};

     class Trie{
          public:
          Node *root;
          Trie(){
               root = new Node(' ');
          }

          void insert(string s){
               Node *cur = root;
               for(int i = 0; i < s.size(); i++){
                    if(cur->ch[s[i] - 'a'] != NULL)
                    cur = cur->ch[s[i] - 'a'];
                    else{
                         Node *node = new Node(s[i]);
                         cur->ch[s[i] - 'a'] = node;
                         cur = node;
                    }
               }
          }

          bool search(Node *node, string s){
               Node *cur = root;
               for(int i = 0; i < s.size(); i++){
                    if(!cur->ch[s[i] - 'a'])
                    return false;
                    cur = cur->ch[s[i] - 'a'];
               }
               return (cur != NULL);
          }
};

int main(){
     Trie *trie = new Trie();
     string s;
     bool ok = false;
     cin >> s;
     int count;
     cin >> count;
     for(int i = 0; i < s.size(); i++){
          string s1 = s.substr(i);
          trie->insert(s1);
     }
     string find[count];
     for(int i = 0; i < count; i++){
          cin >> find[i];
     }
     for(int i = 0; i < count; i++){
      string newstr = find[0] + find[1];
     if(trie->search(trie->root, find[0]) && trie->search(trie->root, find[1])
      && newstr == s && newstr.size() <= 500000){
          ok = true;
     }
     else{
          ok = false;
          break;
     }
     }
     if(ok) cout << "YES";
     else   cout<< "NO";
     return 0;
}