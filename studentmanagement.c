#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    int age;
    char course[50];
    float marks;
} Student;

Student students[MAX];
int count = 0;

void saveToFile() {
    FILE *file = fopen("students.dat", "wb");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);

    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("students.dat", "rb");

    if (file == NULL)
        return;

    fread(&count, sizeof(int), 1, file);
    fread(students, sizeof(Student), count, file);

    fclose(file);
}

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Course: ");
    scanf(" %[^\n]", students[count].course);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    saveToFile();

    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n================ STUDENT RECORDS ================\n");

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID     : %d\n", students[i].id);
        printf("Name   : %s\n", students[i].name);
        printf("Age    : %d\n", students[i].age);
        printf("Course : %s\n", students[i].course);
        printf("Marks  : %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int id;
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID     : %d\n", students[i].id);
            printf("Name   : %s\n", students[i].name);
            printf("Age    : %d\n", students[i].age);
            printf("Course : %s\n", students[i].course);
            printf("Marks  : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found.\n");
}

void updateStudent() {
    int id;
    int found = 0;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New Course: ");
            scanf(" %[^\n]", students[i].course);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            saveToFile();

            printf("\nStudent updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found.\n");
}

void deleteStudent() {
    int id;
    int found = 0;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            saveToFile();

            printf("\nStudent deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found.\n");
}

int main() {
    int choice;

    loadFromFile();

    while (1) {
        printf("\n\n========== STUDENT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("===============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}