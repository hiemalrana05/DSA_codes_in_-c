#include<stdio.h>
#include<stdlib.h>

// Structure representing a stack
struct stack {
    int size;   // The maximum size of the stack
    int top;    // The index of the top element in the stack
    int* arr;   // Pointer to the array holding the stack elements
};

// Function to check if the stack is empty
int is_empty(struct stack* ptr) {
    if (ptr->top == -1) {  // If top is -1, the stack is empty
        return 1;
    }
    return 0;
}

// Function to check if the stack is full
int is_full(struct stack* ptr) {
    if (ptr->top == ptr->size - 1) {  // If top equals size-1, the stack is full
        return 1;
    }
    return 0;
}

// Function to push an element onto the stack
void push(struct stack* ptr, int val) {
    if (is_full(ptr)) {  // Check if the stack is full
        printf("Stack is full\n");
    } else {
        ptr->arr[++ptr->top] = val;  // Increment top and assign value to the stack
    }
}

// Function to pop an element from the stack
void pop(struct stack* ptr) {
    if (is_empty(ptr)) {  // Check if the stack is empty
        printf("Stack is empty\n");
    } else {
        ptr->arr[ptr->top--];  // Decrement top, effectively removing the top element
    }
}

// Function to peek at the top element of the stack
int peek(struct stack* ptr) {
    if (is_empty(ptr)) {  // Check if the stack is empty
        return -1;        // Return -1 as a sentinel value if the stack is empty
    }
    return ptr->arr[ptr->top];  // Return the top element
}

// Function to print the elements of the stack
void print(struct stack* ptr) {
    for (int i = 0; i <= ptr->top; i++) {  // Loop through and print elements from bottom to top
        printf("%d\n", ptr->arr[i]);
    }
}

int main() {
    // Dynamically allocate memory for the stack
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    
    st->size = 50;          // Set the stack size to 50
    st->top = -1;           // Initialize top to -1, indicating an empty stack
    st->arr = (int*)malloc(st->size * sizeof(int));  // Allocate memory for the stack array

    // Push elements onto the stack
    push(st, 53);
    push(st, 54);
    push(st, 55);
    push(st, 56);

    // Pop the top two elements from the stack
    pop(st);  // Removes 56
    pop(st);  // Removes 55

    // Print the remaining elements in the stack
    print(st);

    // Free allocated memory for the stack
    free(st->arr);
    free(st);

    return 0;
}
