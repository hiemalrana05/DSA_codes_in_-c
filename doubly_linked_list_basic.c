#include<stdio.h>
#include<stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    int data;              // To store data (an integer in this case)
    struct node* prev;     // Pointer to the previous node in the list
    struct node* next;     // Pointer to the next node in the list
};

int main() {
    struct node* head;     // Declare a pointer to the head (first node) of the list
    head = NULL;           // Initialize the head to NULL, meaning the list is initially empty

    // Dynamically allocate memory for four nodes (head, second, third, and fourth)
    head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    // Initialize data and pointers for the first node (head)
    head->data = 55;       // Set the data of the head node to 55
    head->next = second;   // Set the next pointer of head to the second node
    head->prev = NULL;     // Set the previous pointer of head to NULL (no previous node)

    // Initialize data and pointers for the second node
    second->prev = head;   // Set the previous pointer of second node to head
    second->data = 66;     // Set the data of the second node to 66
    second->next = third;  // Set the next pointer of second node to third node

    // Initialize data and pointers for the third node
    third->prev = second;  // Set the previous pointer of third node to second node
    third->data = 77;      // Set the data of the third node to 77
    third->next = fourth;  // Set the next pointer of third node to fourth node

    // Initialize data and pointers for the fourth node
    fourth->prev = third;  // Set the previous pointer of fourth node to third node
    fourth->data = 88;     // Set the data of the fourth node to 88
    fourth->next = NULL;   // Set the next pointer of fourth node to NULL (no next node)

    // Traverse the list from head to tail using the 'next' pointer
    printf("list from next pointer\n");
    while (head != NULL) {
        printf("%d\n", head->data);   // Print the data of the current node
        head = head->next;            // Move to the next node in the list
    }

    // Traverse the list from tail to head using the 'prev' pointer
    printf("list from using prev pointer\n");
    while (fourth != NULL) {
        printf("%d\n", fourth->data); // Print the data of the current node
        fourth = fourth->prev;        // Move to the previous node in the list
    }

    return 0;   // End of the program
}
