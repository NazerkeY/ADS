#include <bits/stdc++.h>
using namespace std;  
  
// trie node 
class Node { 
    public: 
    bool isEnd; 
    char data;
    Node *ch[26];
    Node(char data){
         this->data = data;
         for(int i = 0; i < 26; i++){
              this->ch[i] = NULL;
         }
         isEnd = false;
    }
}; 
  
// Returns new trie node (initialized to NULLs) 
class Trie{ 
  public:
  Node *root;
  Trie(){
       root = new Node(' ');
  }

void insert(string s) 
{ 
   Node *cur = root;
  
    for (int i = 0; i < s.size(); i++) { 
        int index = s[i] - 'a'; 
        if (cur->ch[index] != NULL) 
        cur = cur->ch[index];
        else{
             Node *node = new Node(s[i]);
             cur->ch[index] = node;
             cur = node;
        }
    } 
    // mark last node as leaf 
    cur->isEnd = true; 
} 

bool search(Node* node, string s) 
{ 
    Node *cur = root; 
  
    for (int i = 0; i < s.size(); i++) { 
        int index = s[i] - 'a'; 
        if (!cur->ch[index]) 
            return false; 
  
        cur = cur->ch[index]; 
    } 
  
    return (cur != NULL); 
} 
  
bool isEmpty(Node* node) 
{ 
    for (int i = 0; i < 26; i++) 
        if (node->ch[i]) 
            return false; 
    return true; 
} 
  
  Node *remove(Node* node, string s, int depth = 0) 
{ 
    // If tree is empty 
    if (!node) 
        return NULL; 
  
    // If last character of key is being processed 
    if (depth == s.size()) { 
  
        // This node is no more end of word after 
        // removal of given key 
        if (node->isEnd) 
            node->isEnd = false; 
  
        // If given is not prefix of any other word 
        if (isEmpty(node)) { 
            delete (node); 
            node = NULL; 
        } 
  
        return node; 
    } 
  
    // If not last character, recur for the child 
    // obtained using ASCII value 
    int index = s[depth] - 'a'; 
    node->ch[index] =  
          remove(node->ch[index], s, depth + 1); 
  
    // If root does not have any child (its only child got  
    // deleted), and it is not end of another word. 
    if (isEmpty(node) && node->isEnd == false) { 
        delete (node); 
        node = NULL; 
    } 
  
    return node; 
} 
  

}; 
  
int main() 
{ 
     Trie *trie = new Trie();
     string s;
     cin >> s;
     for(int i = 0; i < s.size(); i++){
          string s1 = s.substr(i);
          trie->insert(s1);
     }
     int count;
     cin >> count;
     string find[count];
     for(int i = 0; i < count; i++){
     cin >> find[i];
     }
     for(int i = 0; i < count; i++){
          trie->search(trie->root, find[i])? cout << "YES\n" : cout << "NO\n";
     }
     string del;
     cin >> del;
     (trie->search(trie->root, del) && trie->remove(trie->root, del)) ? cout<<"YES\n" : cout<<"NO\n";
    return 0;
} 