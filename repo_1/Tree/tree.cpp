#include<iostream>
using namespace std;

node *s[1001];
int tops = -1;
node *root;

struct node
{
    int data;
    node* left, *right, *next;
};

class mystack{
    public:

    void push(node *n){
        if(tops == 1001 -1){
            cout<<"stack is full"<<endl;
            return;
        }
        s[++tops] = n;
    }
    void pop(){
        if(tops == -1){
            cout<<"stack is empty"<<endl;
            return;
        }
        tops--;
    }
    bool Isempty(){
        if(tops == -1) return true;
        else return false;
    
    }
    node* top(){
        if(tops == -1){
            cout<<"stack is empty"<<endl;
        }
        return s[tops];
    }

};
node* createNode(int data){
    node * temp = new node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}
void insert(int value, mystack s){
    if(root == nullptr){
        node *newNode = createNode(value);
        s.push(newNode);
        return;
    }
    node *temp = s.top();
    while(temp->next != nullptr){
        node* newNode = createNode(value);
        temp->next = newNode;
    }


}
int main(){
    root = nullptr;
    mystack sk;
}

