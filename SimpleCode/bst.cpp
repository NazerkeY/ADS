//Binary Search Tree
#include <iostream>
using namespace std;

struct Node{
     int data;
     Node *left;
     Node *right;

     Node(int x){
          data = x;
          left = NULL;
          right = NULL;
     }
};

struct BST{
Node *root;

BST(){
     root = NULL;
}

Node *insert(Node *node, int data){
     if(node == NULL){
          node = new Node(data);
          return node;
     }
     if (data <= node->data)
     node->left = insert(node->left, data);
     else
     node->right = insert(node->right, data);
     return node;
}

void sort(Node *node){
     if(node == NULL) return;
     sort(node->left);
     cout<<node->data<<" ";
     sort(node->right);
}

Node *findMin(Node *node){
     while(node->left!=NULL)
     node = node->left;
     return node;
}
Node *findMax(Node *node){
     while(node->right!=NULL)
     node = node->right;
     return node;
}

Node *deleteNode(Node *node, int data){
     if(node == NULL){
          return NULL;
     }
     if(data < node->data)
     node->left = deleteNode(node->left, data);
     else if(data > node->data)
     node->right = deleteNode(node->right, data);
     else{
          if(node -> right == NULL && node->left == NULL)
          node = NULL;
          else if(node->left == NULL)
          node = node->right;
          else if(node->right == NULL)
          node = node->left;
          else{
               Node *tmp = findMin(node->right);
               node->data = tmp->data;
               node->right = deleteNode(node->right, tmp->data);
          }
     }
     return node;
}
};

int main(){
     BST *bst = new BST();
     bst->root = bst->insert(bst->root, 50);
     bst->root = bst->insert(bst->root, 35);
     bst->root = bst->insert(bst->root, 30);
     bst->root = bst->insert(bst->root, 40);
     bst->root = bst->insert(bst->root, 32);
     bst->root = bst->insert(bst->root, 36);
     bst->root = bst->insert(bst->root, 80);
     bst->root = bst->insert(bst->root, 60);
     bst->root = bst->insert(bst->root, 90);
     bst->root = bst->insert(bst->root, 70);

     bst->sort(bst->root);
     cout<<endl;
     bst->root = bst->deleteNode(bst->root, 35);
     bst->sort(bst->root);
     cout<<endl;
     Node *nodeMin = bst->findMin(bst->root);
     cout<<nodeMin->data<<" ";

     Node *nodeMax = bst->findMax(bst->root);
     cout<<nodeMax->data;
     return 0;
}