#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = head->next;
    return;
}

//Inset at tail
void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

//Insert after node which is divisible by 12
void insert(Node* &head, int val){
    Node* n = new Node(val);
    Node* temp = head;
    if(head == NULL)
    {
        insertAtHead(head,val);
        return;
    }
    while(temp->next != NULL)
    {
        if((temp->data)%12 == 0)
        {
            n->next = temp->next;
            temp->next = n;
            break;
        }
        temp = temp->next;
    }
}

//display
void show(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()

{
    Node* head = NULL;
    int n;
    insertAtTail(head,35);
    insertAtTail(head,21);
    insertAtTail(head,24);
    insertAtTail(head,60);
    insertAtTail(head,48);
    insertAtTail(head,59);
    insertAtTail(head,66);
    show(head);
    cout<<"\nEnter the Value to insertAtTail: ";
    cin>>n;
    insert(head,n);
    show(head);
}