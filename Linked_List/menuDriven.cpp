#include<iostream>
#include<stdlib.h>
using namespace std;
#define clrscr();
class Node
{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

//insert at Beginning
Node* insert_Beg(Node* &head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
    return head;
}

//insert at tail
void insert_End(Node* &head,int val)
{
    Node* n = new Node(val);
    if(head == NULL)
    {
        head = n;
        n->next = NULL;
        return;
    }
    
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//Insert kth position
void insert_k(Node* &head, int pos, int val)
{
    
    if(pos==1)
    {
        insert_Beg(head,val);
        return;
    }

    if(pos<1) cout<<"\nInvalid position";
    Node* n = new Node(val);
    Node* fast = head;
    int count=1;
    while(count!=pos)
    {
        fast = fast->next;
        count++;
    }
    Node* slow = head;
    while(slow->next != fast){
        slow = slow->next;
    }
    
    slow->next = n;
    n->next = fast;
}

//insert after given element
void insert_After(Node* head, int ele, int val)
{
    Node* n = new Node(val);
    Node* temp = head;
    while(temp->data!=ele){
        temp = temp->next;
    }
    cout<<temp->data;
    Node* temp2 = head;
    while(temp2->next!=temp)
    {
        temp2=temp2->next;
    }
    temp2->next->next = n;
    n->next = temp->next;
}

//delete node from beginning
void delete_Beg(Node* &head)
{
    if(head==NULL){
        cout<<"List is empty...";
        return;
    }
    if(head->next == NULL){
        head = NULL;
        return;
    }
    Node* n = head;
    head = head->next;
    delete n;
}

//delete node from end
void delete_End(Node* head){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    //  if(head->next == NULL){
    //     head = NULL;
    //     // delete head;
    //     return;
    // }
    Node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = NULL;
    delete todelete;
}

//Display SLL
void display(Node* head)
{
    Node* temp = head;
    if(head == NULL)
        cout<<"\nList is empty";

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int size, ch, val, key;
    Node* head = NULL;
    cout<<"---------------------------------------------------------------------------------";
    cout<<"\n\t\tChoose the option to perform operation on Linked List";
    cout<<"\n\t\t\t1. Insert at Beginning";
    cout<<"\n\t\t\t2. Insert at End";
    cout<<"\n\t\t\t3. Insert at Kth Position";
    cout<<"\n\t\t\t4. Insert after given element";
    cout<<"\n\t\t\t5. Delete from Beginning";
    cout<<"\n\t\t\t6. Delete at End";
    cout<<"\n\t\t\t7. Delete at Kth Position";
    cout<<"\n\t\t\t8. display the Linked List";
    cout<<"\n---------------------------------------------------------------------------------";

    do
    {
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
    
        switch(ch)
        {
            case 1:
                cout<<"Enter the element ";
                cin>>val;
                insert_Beg(head, val);
                break;
            case 2: 
                cout<<"Enter the element ";
                cin>>val;
                insert_End(head,val);
                break;
            case 3:
                int pos;
                cout<<"Enter the position: ";
                cin>>pos;
                cout<<"Enter the element ";
                cin>>val;
                insert_k(head,pos,val);
                break;
            case 4:
                cout<<"\nEnter the key element: ";
                cin>>key;
                cout<<"\nEnter the element ";
                cin>>val;
                insert_After(head,key,val);
                break;
            case 5:
                delete_Beg(head);
                break;
            case 6:
                delete_End(head);
                break;
            case 7:
                //delete_k(head);
                break;
            case 8:
                display(head);
                break;
            case 9:
                cout<<"--------------------------------Exiting----------------------------------";
                break;

            default:
                cout<<"\nWrong Input...try again";
                break;
        }
    }while (ch!=9);
    
    return 0;
}