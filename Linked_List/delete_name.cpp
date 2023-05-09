// #include<iostream>
// #include<stdlib.h>
// #include<string.h>
// using namespace std;

// class Node
// {
//     public:
//         char name[20];
//         Node* next;

//         Node(char val[20])
//         {
//             strcpy(name,val);
//             next = NULL;
//         }
// };

// //insert at Beginning
// Node* insert_Beg(Node* &head, char val[20])
// {
//     Node* n = new Node(val);
//     n->next = head;
//     head = n;
//     return head;
// }

// //insert at tail
// void insert_End(Node* &head,char val[20])
// {
//     Node* n = new Node(val);
//     if(head == NULL)
//     {
//         head = n;
//         n->next = NULL;
//         return;
//     }
    
//     Node* temp = head;
//     while(temp->next!=NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = n;
// }

// void display(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->name<<"->";
//         temp = temp->next;
//     }
//     cout<<"NULL"<<endl;
// }

// Node* delete_A(Node* head) {
//     Node *current = head, *prev = NULL;
    
//     while (current != NULL) {
//         if (current->name[0] == 'A') {
//             // Delete current node
//             if (prev == NULL) {
//                 head = current->next;
//                 delete current;
//                 current = head;
//             }
//             else {
//                 prev->next = current->next;
//                 delete current;
//                 current = prev->next;
//             }
//         }
//         else {
//             prev = current;
//             current = current->next;
//         }
//     }
    
//     return head;
// }

// int main()
// {
//     int size;
//     char val[20];
//     Node* head = NULL;
//     cout<<"\nEnter the size of linked list: ";
//     cin>>size;
//     for(int i=0;i<size;i++)
//     {
//         cout<<"\nEnter the name: ";
//         cin>>val;
//         insert_End(head, val);
//     }
//     display(head);

//     // Node* h1 = delete_A(head);
//     head = delete_A(head);
//     display(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    struct node* next;
};

// Function to delete nodes starting with 'A'
struct node* deleteANodes(struct node* head) {
    struct node *current = head, *prev = NULL;
    
    while (current != NULL) {
        if (current->name[0] == 'A' || current->name[0] == 'a') {
            // Delete current node
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            }
            else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}

// Function to print the linked list
void printList(struct node* head) {
    struct node* current = head;
    
    printf("Linked List: ");
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list
    struct node* head = (struct node*) malloc(sizeof(struct node));
    strcpy(head->name, "glice");
    head->next = (struct node*) malloc(sizeof(struct node));
    strcpy(head->next->name, "aob");
    head->next->next = (struct node*) malloc(sizeof(struct node));
    strcpy(head->next->next->name, "Aharlie");
    head->next->next->next = (struct node*) malloc(sizeof(struct node));
    strcpy(head->next->next->next->name, "adam");
    head->next->next->next->next = NULL;
    
    // Print the original list
    printList(head);
    
    // Delete nodes starting with 'A'
    head = deleteANodes(head);
    
    // Print the updated list
    printList(head);
    
    // Free memory
    struct node* current = head;
    while (current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}
