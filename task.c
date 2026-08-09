#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TITLE_SIZE 100

typedef struct {
    int id;
    char title[TITLE_SIZE];
    int completed;
    int priority;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("\nTask limit reached.\n");
        return;
    }

    Task *task = &tasks[taskCount];

    task->id = taskCount + 1;

    printf("\nEnter task title: ");
    fgets(task->title, TITLE_SIZE, stdin);
    task->title[strcspn(task->title, "\n")] = '\0';

    do {
        printf("Priority (1=Low, 2=Medium, 3=High): ");
        scanf("%d", &task->priority);
        clearInput();
    } while (task->priority < 1 || task->priority > 3);

    task->completed = 0;
    taskCount++;

    printf("\nTask added successfully.\n");
}

void showTasks() {
    if (taskCount == 0) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n========== TASKS ==========\n");

    for (int i = 0; i < taskCount; i++) {
        Task *task = &tasks[i];

        printf("\nID: %d", task->id);
        printf("\nTitle: %s", task->title);

        printf("\nPriority: ");

        if (task->priority == 1)
            printf("Low");
        else if (task->priority == 2)
            printf("Medium");
        else
            printf("High");

        printf("\nStatus: %s\n",
               task->completed ? "Completed" : "Pending");

        printf("---------------------------\n");
    }
}

void completeTask() {
    int id;

    printf("\nEnter task ID: ");
    scanf("%d", &id);
    clearInput();

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            printf("\nTask marked as completed.\n");
            return;
        }
    }

    printf("\nTask not found.\n");
}

void deleteTask() {
    int id;

    printf("\nEnter task ID: ");
    scanf("%d", &id);
    clearInput();

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {

            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
                tasks[j].id = j + 1;
            }

            taskCount--;

            printf("\nTask deleted successfully.\n");
            return;
        }
    }

    printf("\nTask not found.\n");
}

void showStatistics() {
    int completed = 0;
    int pending = 0;
    int highPriority = 0;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed)
            completed++;
        else
            pending++;

        if (tasks[i].priority == 3)
            highPriority++;
    }

    printf("\n========== STATISTICS ==========\n");
    printf("Total tasks      : %d\n", taskCount);
    printf("Completed tasks  : %d\n", completed);
    printf("Pending tasks    : %d\n", pending);
    printf("High priority    : %d\n", highPriority);

    if (taskCount > 0) {
        double progress =
            ((double)completed / taskCount) * 100;

        printf("Progress         : %.1f%%\n", progress);
    }

    printf("================================\n");
}

void searchTask() {
    char query[TITLE_SIZE];
    int found = 0;

    printf("\nSearch task: ");
    fgets(query, TITLE_SIZE, stdin);
    query[strcspn(query, "\n")] = '\0';

    for (int i = 0; i < taskCount; i++) {
        if (strstr(tasks[i].title, query) != NULL) {
            printf("\n[%d] %s - %s",
                   tasks[i].id,
                   tasks[i].title,
                   tasks[i].completed
                       ? "Completed"
                       : "Pending");

            found = 1;
        }
    }

    if (!found)
        printf("\nNo matching tasks found.\n");
}

int main() {
    int choice;

    printf("=================================\n");
    printf("       C TASK MANAGER\n");
    printf("=================================\n");

    while (1) {
        printf("\n");
        printf("1. Add Task\n");
        printf("2. Show Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Delete Task\n");
        printf("5. Search Task\n");
        printf("6. Statistics\n");
        printf("7. Exit\n");

        printf("\nChoose an option: ");
        scanf("%d", &choice);
        clearInput();

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                showTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                searchTask();
                break;

            case 6:
                showStatistics();
                break;

            case 7:
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("\nInvalid option.\n");
        }
    }

    return 0;
}