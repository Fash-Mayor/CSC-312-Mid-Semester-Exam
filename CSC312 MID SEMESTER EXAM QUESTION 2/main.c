#include <stdio.h>
#include <stdlib.h>

int main()
{
struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}


void push(struct Stack* stack, char c) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = c;
    }
}

char pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return '\0'; // Empty stack
}


bool isPalindrome(const char* str) {
    int length = strlen(str);
    struct Stack stack;
    initialize(&stack);


    int mid = length / 2;
    for (int i = 0; i < mid; i++) {
        push(&stack, str[i]);
    }


    if (length % 2 != 0) {
        mid++;
    }


    for (int i = mid; i < length; i++) {
        char ele = pop(&stack);
        if (ele != str[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("Yes, it's a palindrome!\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}

}
