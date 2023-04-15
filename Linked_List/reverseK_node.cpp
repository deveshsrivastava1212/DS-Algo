#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val){
    node* n = new node(val);
    if(head== NULL){
        n->next = head;
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp ->next;
    }
    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//REVERSE Kth Node
node* reverseKnode(node* &head, int k){
    node* pre = NULL;
    node* curr = head;
    node* nextptr;
    int count =0;
    while(curr!=NULL && count<k){
        nextptr = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextptr;
        count++;
    }

    if(nextptr!=NULL){
    head->next = reverseKnode(nextptr,k);
    }

    return pre;
}

int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    node* newhead = reverseKnode(head,2);
    display(newhead);

    return 0;
}