#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 10
#define ITEMS 50

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;

CRITICAL_SECTION lock;

DWORD WINAPI producer(LPVOID arg)
{
    int i;

    for (i = 1; i <= ITEMS; i++) {

        while (1) {
            EnterCriticalSection(&lock);

            if (count < BUFFER_SIZE) {
                buffer[in] = i;
                in = (in + 1) % BUFFER_SIZE;
                count++;

                printf("Produced: %d | Buffer: %d\n", i, count);

                LeaveCriticalSection(&lock);
                break;
            }

            LeaveCriticalSection(&lock);
            Sleep(10);
        }

        Sleep(50);
    }

    return 0;
}

DWORD WINAPI consumer(LPVOID arg)
{
    int i;
    int item;

    for (i = 1; i <= ITEMS; i++) {

        while (1) {
            EnterCriticalSection(&lock);

            if (count > 0) {
                item = buffer[out];
                out = (out + 1) % BUFFER_SIZE;
                count--;

                printf("Consumed: %d | Buffer: %d\n", item, count);

                LeaveCriticalSection(&lock);
                break;
            }

            LeaveCriticalSection(&lock);
            Sleep(10);
        }

        Sleep(80);
    }

    return 0;
}

int main(void)
{
    HANDLE producerThread;
    HANDLE consumerThread;

    InitializeCriticalSection(&lock);

    producerThread = CreateThread(
        NULL,
        0,
        producer,
        NULL,
        0,
        NULL
    );

    consumerThread = CreateThread(
        NULL,
        0,
        consumer,
        NULL,
        0,
        NULL
    );

    if (producerThread == NULL || consumerThread == NULL) {
        printf("Failed to create threads.\n");

        if (producerThread != NULL)
            CloseHandle(producerThread);

        if (consumerThread != NULL)
            CloseHandle(consumerThread);

        DeleteCriticalSection(&lock);
        return 1;
    }

    WaitForSingleObject(producerThread, INFINITE);
    WaitForSingleObject(consumerThread, INFINITE);

    CloseHandle(producerThread);
    CloseHandle(consumerThread);

    DeleteCriticalSection(&lock);

    printf("\nAll tasks completed successfully.\n");

    return 0;
}
