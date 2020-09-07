
#include <iostream>
#include <conio.h>
#include <iostream>
 
using namespace std;
 
struct Node {
    Node* l, *r;
    int val;
    char  x;
};  
void Node_Add(Node*& p, char x);
int  Node_Height(const Node* p);
 
int main(void){
 
    Node* tr = NULL;
    
     int n,how_much; 
    char x;
 cin >> n;

 char *s = new char[n];
     for(int i = 0; i < n; i++)
     {
         cin >> s[i];
        Node_Add(tr, s[i]);
     }
 
    cout << "height: " << Node_Height(tr) << endl;
    return 0;
}
 
//вставка
void Node_Add(Node*& p, char x){
    if(p == NULL){
        p = new Node();
        if(p != NULL){
            p->l = p->r = NULL;
            p->x = x;
        }
    } else if(x < p->x)
        Node_Add(p->l, x);
    else
        Node_Add(p->r, x);
}

 
//высота дерева
int Node_Height(const Node* p){
    int l, r, h = 0;
    if(p != NULL){
        l = Node_Height(p->l);
        r = Node_Height(p->r);
        h = ((l > r) ? l : r) + 1;
    }
    return h;
}