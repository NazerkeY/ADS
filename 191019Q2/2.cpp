#include <iostream>
using namespace std;

struct Node{
     int data;
     Node *left, *right;
     char h;

     Node(int data){
          this->data = data;
          left = NULL;
          right = NULL;
     }
};

struct Tree{
     Node *root;

     Tree(){
          root = NULL;
     }

     Node *add(Node *node, int data){
          if(node == NULL){
               node = new Node(data);
               return node;
          }
          if(data <= node->data)
          node->left = add(node->left, data);
          else
          node->right = add(node->right, data);
          return node; 
     }

     int height(const Node *node){
          int l, r, h = 0;
          if(node!=NULL){
               l = node->left;
               r = node->right;
               h = ((l > r) ? l : r) + 1;
          }
          return h;
     }

     
};
int main(){
     Tree *tree = new Tree();
     tree->root = tree->add(tree->root, 4);
     tree->root = tree->add(tree->root, 2);
     tree->root = tree->add(tree->root, 6);
     tree->root = tree->add(tree->root, 1);
     tree->root = tree->add(tree->root, 3);
     tree->root = tree->add(tree->root, 5);
     tree->root = tree->add(tree->root, 7);
     cout << height(tree->root);
}
