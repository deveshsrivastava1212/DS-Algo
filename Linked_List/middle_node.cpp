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

//Middle node of the linked list
void middle(node* head){
    int count=0;
    node* curr = head;
    node* nextptr = head;
    while(nextptr->next!=NULL){
        nextptr = nextptr->next;
        count++;
    }
    int t = count/2;
    while(t--){
        curr = curr->next;
    }
    cout<<curr->data<<" ";
}

int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    display(head);
    middle(head);

    return 0;
}