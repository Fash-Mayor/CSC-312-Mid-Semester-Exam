#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct {
        double *data;
        int top;
        int capacity;
    } Stack;


    Stack *createStack(int capacity) {
        Stack *stack = (Stack *)malloc(sizeof(Stack));
        stack->data = (double *)malloc(capacity * sizeof(double));
        stack->top = -1;
        stack->capacity = capacity;
        return stack;
    }

    void push(Stack *stack, double value) {
        if (stack->top == stack->capacity - 1) {
            printf("Stack is full. Cannot push.\n");
            return;
        }
        stack->data[++stack->top] = value;
    }


    double pop(Stack *stack) {
        if (stack->top == -1) {
            printf("Stack is empty. Cannot pop.\n");
            return 0.0;
        }
        return stack->data[stack->top--];

        return 0;

    }
}
