#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the doubly linked list
struct node{
    int data;
    struct node* prev;
    struct node* next;
}*head,*newnode;

// Function to insert a new node at the start of the list
void insert_at_start(struct node** head){
    // Create a new node
    struct node* newnode;
    newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=44;
    newnode->next=(*head);
    // Update the previous node's next pointer to point to the new node
    (*head)->prev=newnode;
    // Update the head pointer to point to the new node
    (*head)=newnode;
}

// Function to insert a new node at the end of the list
void insert_at_end(struct node** head) {
    // Create a new node
    newnode=NULL;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 99;
    newnode->next = NULL;

    // Traverse the list to find the last node
    struct node* temp = *head;  
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the last node's next pointer to point to the new node
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next=NULL;
}

// Function to insert a new node at a specific index in the list
void insert_at_index(struct node** head){
    // Create a new node
    newnode=NULL;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=1;
    newnode->next=NULL;
    newnode->prev=NULL;
    int n;
    printf("enter the index you want to insert:");
    scanf("%d",&n);
    struct node* temp=(*head);
    // Traverse the list to find the node at the specified index
    for(int i=0;i<n;i++){
        temp=temp->next;
    }
    // Update the new node's next pointer to point to the node at the specified index
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
}

// Function to print the contents of the list
void print(struct node* head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}

int main(){
    head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
     head->data=55;
     head->next=second;
     head->prev=NULL;

     second->prev=head;
     second->data=66;
     second->next=third;

     third->prev=second;
     third->data=77;
     third->next=fourth;

     fourth->prev=third;
     fourth->data=88;
     fourth->next=NULL;

     // Insert a new node at the start of the list
     insert_at_start(&head);
     // Insert a new node at the end of the list
     insert_at_end(&head);
     // Insert a new node at a specific index in the list
     insert_at_index(&head);

     // Print the contents of the list
     print(head);

     return 0;
}
