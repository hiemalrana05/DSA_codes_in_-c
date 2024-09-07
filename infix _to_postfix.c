#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the stack structure to handle infix to postfix conversion
struct stack {
    int size;    // Maximum size of the stack
    int top;     // Index of the top element in the stack
    char* arr;   // Dynamic array to hold the stack elements
};

// Function to check if the stack is empty
char is_empty(struct stack* ptr) {
    if (ptr->top == -1) {  // Stack is empty when top is -1
        return 1;
    }
    return 0;
}

// Function to check if the stack is full
char is_full(struct stack* ptr) {
    if (ptr->top == ptr->size - 1) {  // Stack is full when top is equal to size-1
        return 1;
    }
    return 0;
}

// Function to push a value onto the stack
char push(struct stack* ptr, char val) {
    if (is_full(ptr)) {  // If stack is full, return error
        return 1;
    }
    ptr->arr[++ptr->top] = val;  // Increment top and add value to stack
    return 0;
}

// Function to pop a value from the stack
char pop(struct stack* ptr) {
    if (is_empty(ptr)) {  // If stack is empty, return error
        return 1;
    }
    return ptr->arr[ptr->top--];  // Return the top value and decrement top
}

// Function to convert infix expression to postfix expression
void infix_to_postfix(struct stack* ptr, char infix[], char postfix[]) {
    ptr->top = -1;  // Initialize the stack to be empty
    ptr->size = 50;  // Set the maximum size of the stack
    ptr->arr = (char*)malloc(ptr->size * sizeof(char));  // Dynamically allocate memory for stack array

    int p = 0;  // p is the index for the postfix array
    // Loop through each character in the infix expression
    for (int i = 0; i < strlen(infix); i++) {
        // Handle division operator
        if (infix[i] == '/') {
            // Pop operators from the stack with equal precedence
            while (ptr->top >= 0 && ptr->arr[ptr->top] == '/') {
                postfix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);  // Push the current operator onto the stack
        }
        // Handle multiplication operator
        else if (infix[i] == '*') {
            // Pop higher or equal precedence operators from the stack
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*')) {
                postfix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);  // Push the current operator onto the stack
        }
        // Handle addition operator
        else if (infix[i] == '+') {
            // Pop higher or equal precedence operators from the stack
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*' || ptr->arr[ptr->top] == '+')) {
                postfix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);  // Push the current operator onto the stack
        }
        // Handle subtraction operator
        else if (infix[i] == '-') {
            // Pop higher or equal precedence operators from the stack
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*' || ptr->arr[ptr->top] == '-')) {
                postfix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);  // Push the current operator onto the stack
        }
        // Handle left parenthesis
        else if (infix[i] == '(') {
            push(ptr, infix[i]);  // Push '(' onto the stack
        }
        // Handle right parenthesis
        else if (infix[i] == ')') {
            // Pop all operators until '(' is encountered
            while (ptr->arr[ptr->top] != '(') {
                postfix[p++] = pop(ptr);
            }
            pop(ptr);  // Pop the '(' from the stack
        }
        // Handle operands (letters, numbers, etc.)
        else {
            postfix[p++] = infix[i];  // Directly append operands to the postfix expression
        }
    }

    // Pop any remaining operators from the stack and append to postfix
    while (ptr->top != -1) {
        postfix[p++] = pop(ptr);
    }
    postfix[p] = '\0';  // Null-terminate the postfix string

    printf("%s", postfix);  // Print the final postfix expression
}

int main() {
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));  // Dynamically allocate memory for stack
    char infix[] = "(a+b)/(c+d)*f-e";  // Example infix expression
    char postfix[100] = "";  // Array to store the postfix expression
    infix_to_postfix(st, infix, postfix);  // Call the conversion function
    return 0;
}
