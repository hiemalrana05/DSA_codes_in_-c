#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the circular linked list
struct node{
    int data; // Data part of the node
    struct node* next; // Pointer to the next node
}*head; // Global head pointer

// Function to print the elements in the circular linked list
void print(struct node* ptr){
    // Use do-while loop to handle circular list printing
    do{
        printf("%d\n", ptr->data); // Print the data of the current node
        ptr = ptr->next; // Move to the next node
    } while(ptr != head); // Stop when it comes back to the head (circular list)
}

// Function to delete the first node of the list
void deletion_at_first(){
    struct node* temp = head; // Store the current head node in temp
    head = head->next; // Move head to the next node
    temp->next = NULL; // Break the link to the next node
    free(temp); // Free the memory of the old head

    struct node* last = head; // Find the last node to restore circular property
    while(last->next != temp){ // Traverse until the last node
        last = last->next;
    }
    last->next = head; // Point the last node to the new head
}

// Function to delete the last node of the list
void deletion_at_last(){
    struct node* temp = head; // Temp pointer for traversal
    struct node* prev = NULL; // Pointer to keep track of the previous node

    // Traverse until we reach the last node
    while(temp->next != head){
        prev = temp; // Store current node in prev
        temp = temp->next; // Move to the next node
    }

    prev->next = head; // Update second last node's next to head
    free(temp); // Free the last node's memory
}

// Function to delete a node at a specific index
void deletion_at_index(){
    struct node* temp = head; // Temporary pointer to traverse the list
    struct node* prev = NULL; // Previous node pointer to keep track of the node before the target
    int n; // Variable to store the index
    printf("index you want to delete: ");
    scanf("%d", &n); // Input the index to delete

    if (n == 1) { // If the index is 1, call deletion_at_first
        deletion_at_first();
        return; // Exit the function after deletion
    }

    // Traverse the list until we reach the nth node
    for(int i = 1; i <= n && temp->next != head; i++){
        prev = temp; // Store the previous node
        temp = temp->next; // Move to the next node
    }

    // Unlink the nth node by pointing prev to temp's next node
    prev->next = temp->next;
    free(temp); // Free the memory of the deleted node
}

int main(){
    // Initialize the circular linked list with 4 nodes
    head = NULL; // Initialize the head as NULL

    // Allocate memory for 4 nodes
    head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    // Assign data and link the nodes
    head->data = 55;
    head->next = second;

    second->data = 66;
    second->next = third;

    third->data = 77;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = head; // Make the list circular by pointing the last node to head

    // Perform deletions
    deletion_at_first(); // Delete the first node
    deletion_at_last(); // Delete the last node
    deletion_at_index(); // Delete a node at a given index

    // Print the remaining list
    print(head);

    return 0; 
}
