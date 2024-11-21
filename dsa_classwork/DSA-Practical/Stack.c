#include <stdio.h>
#include <stdlib.h>
#define MAX 100  
struct Stack {
    int data[MAX];
    int top;  
};
void initialize(struct Stack* stack) {
    stack->top = -1;  
}
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
//Insert an element in the top of the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->data[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
//Delete the Top element in the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;  
    } else {
        int poppedValue = stack->data[stack->top--];
        printf("Popped %d from the stack.\n", poppedValue);
        return poppedValue;
    }
}
//Checks the element at the top without poping it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack->data[stack->top];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);
    return 0;
}
