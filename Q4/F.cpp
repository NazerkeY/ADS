#include<iostream>
#include<cmath>

using namespace std;

class Node{
    public:
        int data;
        Node *right;
        Node *left;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class Tree{
    public:
        Node *root;
        Tree(){
        root = NULL;
    }
    Node * insert(Node *root,int value){
        if(root == NULL){
            return new Node(value);  
        }
        else{
            if(value > root->data){
                root->right = insert(root->right,value);
            }
            else if(value < root->data){
                root->left = insert(root->left,value);
            }
        }
        return root;
    }
    void show(Node *root){
        if(root == NULL){
            return;
        }
        else{      
            cout<<root->data<<" ";
            show(root->left);
            show(root->right);
        }
    }
    	Node* find(Node* root, int val) {
		if (root == NULL) {
			return NULL;
		} else if (root->data == val) {
			return root;
		} else if (root->data < val) {
			return find(root->right, val);
		} else {
			return find(root->left, val);
		}
	}
};

int main(){
    int n;
    Tree *tree = new Tree();
    cin>>n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
       tree->root = tree->insert(tree->root,a);
    }
    int subtree;
    cin >> subtree;
    Node *rootSub = tree->find(tree->root, subtree);
    tree->show(rootSub);

    return 0;
}