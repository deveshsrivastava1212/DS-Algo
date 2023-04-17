//Important algorithm
//Floyd's Algorithm

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

//input
void insert(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        n->next = head;
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

//Display linked list
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//Make cycle
void makeCycle(node* &head, int pos){
    node*temp = head;
    node* startNode;
    int count = 1;
    while(temp->next != NULL){
        if(count==pos){
            startNode=temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

//Detect whether cycle present or not
bool detect(node* head){
    node* fast = head;
    node* slow = head;
    while (fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        return true;
    }
     
    return false;
}


//remove the cycle from LL
void removeCycle(node* &head){
    node* fast = head;
    node* slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int main(){
    node* head = NULL;
    int n,ele;
    cout<<"\nEnter the total size: ";
    cin>>n;
    cout<<"\nEnter the elements: ";
    for(int i=0;i<n;i++){
        cin>>ele;
        insert(head,ele);
    }
    display(head);
    makeCycle(head,4);
    //display(head);
    cout<<detect(head)<<endl;  
    removeCycle(head);  
    cout<<detect(head);
    return 0;

}