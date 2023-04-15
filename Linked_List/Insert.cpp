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

//insert at head
void insertAtHead(node* &head, int val){
    node * n = new node(val);
    n->next = head;
    head = n;
}

//Inset at tail
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

//Display each node
void display(node* head){
    node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

//search for any element
bool search(node* head, int key){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

//delete from head
void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}


//delete at specified position
void deletion (node* &head, int val)
{
    if(head == NULL)
        return;
    
    // if(head->next == NULL){
    //     deleteAtHead(head);
    //     return;
    // }
    
    node* temp = head;
    while(temp->next->data != val){
        temp= temp->next;
    }
    
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main(){
    node* head = NULL;
    int n,key, ele;
    char ch;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    cout<<"Enter the value to insert at head: ";
    cin>>n;
    insertAtHead(head,n);
     display(head);

    cout<<"Enter the element to search, 0->not present and 1->present ";
    cin>>key;
    cout<<search(head,key);

    cout<<"\nDo you want to delete element from head: (y/n): ";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        deleteAtHead(head);
    }
    else{
        cout<<"\nEnter the element you want to delete: ";
        cin>>ele;
        deletion(head,ele);
    }
    display(head);

    return 0;
}