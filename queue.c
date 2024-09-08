#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue
struct queue {
    int size;  // The maximum size of the queue
    int front; // The index of the front element (element to be dequeued)
    int rear;  // The index of the last element (most recently enqueued)
    int* arr;  // Dynamic array to hold queue elements
};

// Function to check if the queue is empty
int is_empty(struct queue* ptr) {
    // Queue is empty if front and rear are at the same position
    if (ptr->front == ptr->rear) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is full
int is_full(struct queue* ptr) {
    // Queue is full if rear has reached the maximum size minus 1
    if (ptr->rear == ptr->size - 1) {
        return 1;
    }
    return 0;
}

// Function to add (enqueue) an element to the queue
void enqueue(struct queue* ptr, int val) {
    // Check if the queue is full before adding the element
    if (is_full(ptr)) {
        printf("Queue is full\n");
        return;
    }
    // Increment the rear index and store the value at the new rear position
    ptr->arr[++ptr->rear] = val;
}

// Function to remove (dequeue) an element from the queue
void dequeue(struct queue* ptr) {
    // Check if the queue is empty before trying to remove an element
    if (is_empty(ptr)) {
        printf("Queue is empty\n");
        return;
    }
    // Move the front index forward to remove the front element
    ptr->front++;
}

// Function to get the element at the rear of the queue
int peek(struct queue* ptr) {
    // Return -1 if the queue is empty (nothing to peek)
    if (is_empty(ptr)) {
        return -1;
    }
    // Return the value at the rear of the queue
    return ptr->arr[ptr->rear];
}

// Function to print all elements in the queue
void print(struct queue* ptr) {
    // Loop through the queue from front+1 to rear and print each element
    for (int i = ptr->front + 1; i <= ptr->rear; i++) {
        printf("%d\n", ptr->arr[i]);
    }
}

// Main function
int main() {
    // Allocate memory for a queue structure and initialize its values
    struct queue* que = (struct queue*)malloc(sizeof(struct queue));
    que->front = -1;   // Front starts at -1 to indicate the queue is empty
    que->rear = -1;    // Rear also starts at -1 for an empty queue
    que->size = 50;    // Set the maximum size of the queue to 50
    que->arr = (int*)malloc(que->size * sizeof(int)); // Allocate memory for the array

    // Test the queue by enqueueing three elements and then dequeuing one
    enqueue(que, 15);  // Add 15 to the queue
    enqueue(que, 16);  // Add 16 to the queue
    enqueue(que, 17);  // Add 17 to the queue
    dequeue(que);      // Remove the front element (15)

    // Print the remaining elements in the queue
    print(que);

    return 0;  // Exit the program
}
