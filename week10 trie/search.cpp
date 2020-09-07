#include <iostream>
using namespace std;

class Node{
     public:
     bool isEnd;
     char data;
     Node *ch[26];
     Node(char data){
          this->data = data;
          for(int i = 0; i < 26; i++){
               this->ch[i] = NULL;
          }
          isEnd= false;
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
              cur->isEnd = true;
          }

          bool search(Node *node, string s){
               Node *cur = root;
               for(int i = 0; i < s.size(); i++){
                    if(!cur->ch[s[i] - 'a'])
                    return false;
                    cur = cur->ch[s[i] - 'a'];
               }
               return (cur != NULL && cur->isEnd);
          }
};

int main(){
     Trie *trie = new Trie();
     string s;
     cin >> s;
     for(int i = 0; i < s.size(); i++){
          string s1 = s.substr(i);
          trie->insert(s1);
     }
     string find;
     cin >> find;
     trie->search(trie->root, find)? cout<<"YES\n":cout<<"NO\n";
     return 0;
}