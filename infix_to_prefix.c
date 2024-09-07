#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char* arr;
};

char is_empty(struct stack* ptr) {
    if (ptr->top == -1) {
        return 1;
    }
    return 0;
}

char is_full(struct stack* ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    }
    return 0;
}

char push(struct stack* ptr, char val) {
    if (is_full(ptr)) {
        return 1;
    }
    ptr->arr[++ptr->top] = val;
    return 0;
}

char pop(struct stack* ptr) {
    if (is_empty(ptr)) {
        return 1;
    }
    return ptr->arr[ptr->top--];
}

void reverseString(char infix[]) {
    int n = strlen(infix);
    for (int i = 0; i < n / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[n - i - 1];
        infix[n - i - 1] = temp;
    }
}

void infix_to_prefix(struct stack* ptr, char infix[], char prefix[]) {
    ptr->top = -1;
    ptr->size = 50;
    ptr->arr = (char*)malloc(ptr->size * sizeof(char));
    int p = 0;
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == ')') {
            push(ptr, infix[i]);
        }
        else if (infix[i] == '(') {
            while (ptr->arr[ptr->top] != ')') {
                prefix[p++] = pop(ptr);
            }
            pop(ptr);
        }
        else if (infix[i] == '/') {
            while (ptr->top >= 0 && ptr->arr[ptr->top] == '/') {
                prefix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);
        }
        else if (infix[i] == '*') {
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*')) {
                prefix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);
        }
        else if (infix[i] == '+') {
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*' || ptr->arr[ptr->top] == '+')) {
                prefix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);
        }
        else if (infix[i] == '-') {
            while (ptr->top >= 0 && (ptr->arr[ptr->top] == '/' || ptr->arr[ptr->top] == '*' || ptr->arr[ptr->top] == '-')) {
                prefix[p++] = pop(ptr);
            }
            push(ptr, infix[i]);
        }
        else {
            prefix[p++] = infix[i];
        }
    }
    while (!is_empty(ptr)) {
        prefix[p++] = pop(ptr);
    }
    prefix[p] = '\0';
    printf("%s", prefix);
}

int main() {
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    char infix[] = "(a+b)/(c+d)*f-e";
    char prefix[100] = "";
    reverseString(infix);
    infix_to_prefix(st, infix, prefix);
    return 0;
}
