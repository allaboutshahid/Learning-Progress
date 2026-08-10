#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

bool push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return false;
    }
    s->items[++s->top] = value;
    return true;
}

bool pop(Stack *s, int *value) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return false;
    }
    *value = s->items[s->top--];
    return true;
}

int peek(Stack *s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);