#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node * n = new node(val);
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

//Insert at end
void insertAtEnd(node* &head, int val){

    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void show(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void delete_k_node(node* &head, int pos){
    node* temp = head;
    int count =1;
    if(head == NULL){
        return;
    }
    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    while(temp!=NULL && count != pos){
        temp = temp ->next;
        count++;
    }
    temp ->prev->next = temp->next;
    if(temp->next != NULL){
    temp->next->prev = temp->prev;
    }
    delete temp;
}

int main(){
    node* head = NULL;
     int n,ele,k,pos;
    cout<<"\nEnter the total size: ";
    cin>>n;
    cout<<"\nEnter the elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        insertAtEnd(head,ele);
    }
    show(head);
    cout<<"\nEnter value to insert at head: ";
    cin>>k;
    insertAtHead(head,k);
    show(head);
    cout<<"\nEnter the position to delete: ";
    cin>>pos;
    delete_k_node(head,pos);
    show(head);
    return 0;
}

