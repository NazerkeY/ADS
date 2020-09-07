#include <iostream>
using namespace std;

class Node{
     public:
     int value;
     Node *left, *right;

     Node(int value){
          this->value=  value;
          left= NULL;
          right = NULL:
     }
};

class BST{
     public: 
     Node *root;
     BST(){
          root = NULL;
     }

     Node *insert(Node *node, int data){
          if(node == NULL){
               node = new Node(value);
               return node;
          }
          if(data <= node->left)
          node->left = insert(node->left, value);
          else
          node->right = insert(node->right, value);
          return node;
     }

     void Sort(Node *node){
          if(node == NULL) return;
          Sort(node->left);
          cout<<node->value<<" ";
          Sort(node->right);
     }

     Node *findMin(Node *node){
          while(node->left!=NULL)
          node=node->left;
          return node;
     }
     Node *findMax(Node *node){
          while(node->right!=NULL)
          node = node->right;
          return node;
     }

     Node *deleteNode(Node *node, int value){
          if(node == NULL) return NULL;
          if(value < node->value)
               node->left = deleteNode(node->left, value);
          else if(value > node->value)
               node->right = deleteNode(node->right, value);
          
     }
}

int main(){
     return 0;
}