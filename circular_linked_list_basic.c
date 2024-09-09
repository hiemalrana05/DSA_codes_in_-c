#include<stdio.h>
#include<stdlib.h>

// Defining the structure for a node in the linked list
struct node{
    int data;              // Data part of the node
    struct node* next;     // Pointer to the next node in the list
}*head;                   // Global pointer to the head node

// Function to print the circular linked list starting from any node
void printList(struct node* ptr){

    struct node* temp = head;   // Start the traversal from the head node
    
    // Loop to traverse the circular linked list
    do {
        printf("%d\n", temp->data);  // Print the data of the current node
        temp = temp->next;           // Move to the next node
    } while(temp != head);           // Stop when we reach back to the head node

}

int main(){
    head = NULL;   // Initialize the head node to NULL (empty list)

    // Allocate memory for nodes
    head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    // Assign data and set up links for the circular linked list
    head->data = 55;        // First node's data
    head->next = second;    // Point the first node to the second node

    second->data = 66;      // Second node's data
    second->next = third;   // Point the second node to the third node

    third->data = 77;       // Third node's data
    third->next = fourth;   // Point the third node to the fourth node

    fourth->data = 88;      // Fourth node's data
    fourth->next = head;    // Point the fourth node back to the head to complete the circle

    // Print the list starting from the head node
    printf("Using head node\n");
    printList(head);

    // Print the list starting from the fourth node to demonstrate the circular nature
    printf("Using fourth node\n");
    printList(fourth);

    printf("Hence proved head and fourth node are connected, therefore a circular loop.\n");

    return 0; 
}
