#include <iostream>
using namespace std;
 int cnt = 0;
struct Node{
     int data;
     Node *left, *right;

     Node(int data){
          this->data = data;
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
          if(data <= node->data)
          node->left = insert(node->left, data);
          else 
              node->right = insert(node->right, data);
              return node;
     }

     void inOrder(Node *node){
          if(node == NULL)
          return;
          inOrder(node->left);
          cout<<node->data<<" ";
          inOrder(node->right);
     }

     int findVertex(Node *node){
          while(node->left != NULL){
          node = node->left;
          while(node->right != NULL)
          node = node->right;
     if(node->right == NULL && node->right == NULL)
         cnt++;
          }
     return cnt;
     }
};

    

int main(){

     BST *bst = new BST();
     int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];         
        } 
         
bst->insert(NULL, a[0]);
for(int i =1 ;i<n; i++)
bst->insert(bst->root, a[i]);
     // bst->root = bst->insert(bst->root, 4);
     // bst->root = bst->insert(bst->root, 3);
     //  bst->root = bst->insert(bst->root, 5);
     //  bst->root = bst->insert(bst->root, 1);
     //  bst->root = bst->insert(bst->root, 2);
        
        cout<<bst->findVertex(bst->root);
       

     /*bst->inOrder(bst->root);
     cout<<endl;  */

    /* Node *node = bst->findMin(bst->root);
     cout<<node->data<<endl;  */

   /*  Node *node_max = bst->findMax(bst->root);
     cout<<node_max->data<<endl;  */

   /*  bst->root = bst->delete_node(bst->root, 35);
     bst->inOrder(bst->root);  */

     return 0;
}