    #include <iostream>
    using namespace std;

    /* Односвязный список */

    struct node{
        int data;
        node *pNext;
        
        node(int x){
        data = x;
        pNext = NULL;
        }
    };

    struct List{
    node *head;
    node *end;

    List(){
        head = NULL;
        end = NULL;
    }

    void push_back(int x){
        if(end == NULL){
            end = new node(x);
            head = end;
        }
        else{
            node *n = new node(x);
            end -> pNext = n;
            end = n;
        }
    }

    void print(){
        node *cur = head;
        while(cur != NULL){
            cout<< cur->data<< " ";
            cur = cur->pNext;
        }
        cout<<endl;
    }
    };

    int main(){
        int a[] = {1,2,3,4,5,12,34,54,65,11};
        List l;
        for(int i=0; i<sizeof(a)/sizeof(int); i++){
            l.push_back(a[i]);
        }
        l.print();
        return 0;
    }