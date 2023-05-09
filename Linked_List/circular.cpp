#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

//insert at head
void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        n->next = n;
        head= n;
        return;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

//insert at tail
void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
       insertAtHead(head,val);
        return;
    }

    Node* temp = head;
    while(temp->next!= head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

//delete from head
void deleteFromHead(Node* &head){
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    Node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

//deletion at k position
void deletion(Node* head, int pos){
    if(pos == 1){
        deleteFromHead(head);
        return;
    }
    Node* temp = head;
    int count=1;
    while(count != pos-1){
        temp = temp->next;
        count++;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void show(Node* head){
    Node* temp = head;
   do{
    cout<<temp->data<<"->";
    temp = temp->next;
   }while(temp!=head);
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
    insertAtTail(head,99);
    insertAtTail(head,66);
    show(head);
    insertAtHead(head,199);
    show(head);
    deletion(head,1);
    show(head);
    return 0;
}