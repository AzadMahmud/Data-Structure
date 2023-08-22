#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* head;
node* createNode(int data){
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertAtBeg(int data){
   node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    newNode->next = temp;
    head = newNode;
}
void insertAtEnd(int data){
    node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp->next = newNode;
}
void insertAtNth(int data, int n){
    node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    node* temp = head;
    for(int i = 0; i<n-2; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFirst(){
    if(head == NULL) return;
    node* temp = head;
    head = head->next;
    delete(temp);
}
void deleteLast(){
    if(head == NULL) return;
    if(head->next == NULL){
        node* temp = head;
        head = NULL;
        delete temp;
        return;
    }
    node* temp1 = head;
    node* temp2 = temp1;
    while(temp1->next != NULL){
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    delete temp1;
}
void deleteAtNth(int n){
    if(head == NULL) return;
    if(n==1){
        deleteFirst();
        return;
    }
    node* temp = head;
    for(int i = 0; i<n-2; i++){
        temp = temp->next;
    }
    node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;

}
node* search(int data){
    if(head == NULL) return NULL;
    node* temp = head;
    while(temp != NULL && temp->data != data){
        temp = temp->next;
    }
    return temp;
}
void sort(){
    if(head == NULL) return;
    node* temp = head;
    while (temp != NULL)
    {
        node* temp1 = temp->next;
        while(temp1 != NULL){
            if(temp1->data < temp->data){
                int d = temp1->data;
                temp1->data = temp->data;
                temp->data = d;
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    
}
void reverse(){
    node* current, *prev, *nxt;
    current = head;
    prev = NULL;
    while(current != NULL){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    head = prev;
}
void print(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}
int main(){
    head = NULL;
    // insertAtBeg(3);insertAtBeg(2);insertAtBeg(7);insertAtBeg(5);
    // insertAtEnd(3);insertAtEnd(2);insertAtEnd(7);insertAtEnd(5);
    insertAtNth(3,1);insertAtNth(2,2);insertAtNth(7,3);insertAtNth(5,2);
    // deleteFirst();
    // deleteLast();
    // deleteAtNth(3);
    // node* temp = search(7);
    // if(temp == NULL){
    //     cout<<"Element not found"<<endl;
    // } 
    // else cout<<temp->data<<endl;

    // print();
    // sort();
    // print();
    // reverse();
    print();
}