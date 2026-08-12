#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByXOR(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int main() {
    int x = 5, y = 10;

    printf("Before: x=%d y=%d\n", x, y);
    swapByPointer(&x, &y);
    printf("After pointer swap: x=%d y=%d\n", x, y);

    swapByXOR(&x, &y);
    printf("After XOR swap: x=%d y=%d\n", x, y);

    return 0;
}