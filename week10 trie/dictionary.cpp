#include <map>
#include <bits/stdc++.h> 
using namespace std; 
  
// Structure for Trie 
struct Trie { 
    bool isEnd; 
    map<char, Trie*> m; 
    string meaning; 
}; 
  
// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
    Trie* node = new Trie; 
    node->isEnd = false; 
    return node; 
} 
  
// Function to insert a word with its meaning 
// in the dictionary built using a Trie 
void insert(Trie*& root, const string& str, 
            const string& meaning) 
{ 
  
    // If root is null 
    if (root == NULL) 
        root = getNewTrieNode(); 
  
    Trie* cur = root; 
    for (int i = 0; i < str.length(); i++) { 
        // Make a new node if there is no path 
        if (cur->m.find(str[i]) == cur->m.end()) 
            cur->m[str[i]] = getNewTrieNode(); 
  
        cur = cur->m[str[i]]; 
    } 
  
    // Mark end of word and store the meaning 
    cur->isEnd = true; 
    cur->meaning = meaning; 
} 
  
// Function to search a word in the Trie 
// and return its meaning if the word exists 
string getMeaning(Trie* root, const string& word) 
{ 
  
    // If root is null i.e. the dictionary is empty 
    if (root == NULL) 
        return ""; 
  
    Trie* cur = root; 
  
    // Search a word in the Trie 
    for (int i = 0; i < word.length(); i++) { 
        cur = cur->m[word[i]]; 
        if (cur == NULL) 
            return ""; 
    } 
  
    // If it is the end of a valid word stored 
    // before then return its meaning 
    if (cur->isEnd) 
        return cur->meaning; 
    return ""; 
} 
  
// Driver code 
int main() 
{ 
    Trie* root = NULL; 
  
    // Build the dictionary 
    insert(root, "language", "the method of human communication"); 
    insert(root, "computer", "A computer is a machine that can be instructed to carry out sequences of arithmetic or logical operations automatically via computer programming"); 
    insert(root, "map", "a diagrammatic representation of an area"); 
    insert(root, "book", "a written or printed work consisting of pages glued or sewn together along one side and bound in covers."); 
    insert(root, "science", "the intellectual and practical activity encompassing the systematic study of the structure and behaviour of the physical and natural world through observation and experiment."); 
  
    string word1;
    cin >> word1; 
    
    cout << getMeaning(root, word1); 
  
    return 0; 
} 