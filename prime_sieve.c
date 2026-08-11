#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 100

void sieveOfEratosthenes(int n) {
    bool isComposite[LIMIT + 1];
    memset(isComposite, false, sizeof(isComposite));

    for (int i = 2; i * i <= n; i++) {
        if (!isComposite[i]) {
            for (int j = i * i; j <= n; j += i) {
                isComposite[j] = true;
            }
        }
    }

    printf("Primes up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (!isComposite[i]) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    sieveOfEratosthenes(100);
    return 0;
}