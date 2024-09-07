#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure definition
struct stack {
    int size;     // The size of the stack
    int top;      // The index of the top element in the stack
    char* arr;    // Array to store elements of the stack
};

// Function to check if the stack is empty
char is_empty(struct stack* ptr) {
    if (ptr->top == -1) {   // Stack is empty if top equals -1
        return 1;
    }
    return 0;
}

// Function to check if the stack is full
char is_full(struct stack* ptr) {
    if (ptr->top == ptr->size - 1) {   // Stack is full if top equals size-1
        return 1;
    }
    return 0;
}

// Function to push an element onto the stack
char push(struct stack* ptr, char val) {
    if (is_full(ptr)) {  // Check if the stack is full before pushing
        return 1;        // Return 1 if stack is full
    }
    ptr->arr[++ptr->top] = val;  // Increment top and add value to stack
    return 0;
}

// Function to pop an element from the stack
char pop(struct stack* ptr) {
    if (is_empty(ptr)) {  // Check if the stack is empty before popping
        return 1;         // Return 1 if stack is empty
    }
    return ptr->arr[ptr->top--];  // Return the top element and decrement top
}

// Function to reverse a string (in-place)
void reverseString(char infix[]) {
    int n = strlen(infix);    // Find length of the string
    for (int i = 0; i < n / 2; i++) {  // Reverse string by swapping characters
        char temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }
}

// Function to convert an infix expression to a prefix expression
void infix_to_prefix(struct stack* ptr, char infix[], char prefix[]) {
    ptr->top = -1;  // Initialize stack top to -1 (empty)
    ptr->size = 50; // Set stack size
    ptr->arr = (char*)malloc(ptr->size * sizeof(char));  // Allocate memory for stack array
    int p = 0;      // Pointer for prefix array

    // Traverse the reversed infix expression
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == ')') {  // Push closing parenthesis to stack
            push(ptr, infix[i]);
        }
        else if (infix[i] == '(') {  // If opening parenthesis, pop until closing parenthesis
            while (ptr->arr[ptr->top] != ')') {
                prefix[p++] = pop(ptr);  // Add popped elements to prefix
            }
            pop(ptr);  // Pop the closing parenthesis
        }
        // Handle operators with precedence (/, *, +, -)
        else if (infix[i] == '/') {
            while (ptr->top >= 0 && ptr->arr[ptr->top] == '/') {
                prefix[p++] = pop(ptr);  // Pop operators with higher or equal precedence
            }
            push(ptr, infix[i]);  // Push the operator
        }
        else if (infix[i] == '*') {
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*')) {
                prefix[p++] = pop(ptr);  // Pop operators with higher or equal precedence
            }
            push(ptr, infix[i]);  // Push the operator
        }
        else if (infix[i] == '+') {
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*' || ptr->arr[ptr->top] == '+')) {
                prefix[p++] = pop(ptr);  // Pop operators with higher or equal precedence
            }
            push(ptr, infix[i]);  // Push the operator
        }
        else if (infix[i] == '-') {
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*' || ptr->arr[ptr->top] == '-')) {
                prefix[p++] = pop(ptr);  // Pop operators with higher or equal precedence
            }
            push(ptr, infix[i]);  // Push the operator
        }
        else {
            // If it's an operand, add it directly to the prefix
            prefix[p++] = infix[i];
        }
    }

    // Pop remaining operators from stack and add to prefix
    while (!is_empty(ptr)) {
        prefix[p++] = pop(ptr);
    }

    // Print the prefix expression
    printf("%s", prefix);
}

// Main function
int main() {
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));  // Allocate memory for stack
    char infix[] = "(a+b)/(c+d)*f-e";  // Infix expression to be converted
    char prefix[100] = "";  // Array to store the prefix expression

    // Reverse the infix expression (as part of the conversion process)
    reverseString(infix);

    // Convert infix to prefix
    infix_to_prefix(st, infix, prefix);

    return 0;
}
