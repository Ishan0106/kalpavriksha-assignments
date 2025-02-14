#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int student_id;
    char name[50];
    float grade;
} Student;

void addStudent(int index, Student* students, int id, const char* name, float grade) {
    students[index].student_id = id;
    strncpy(students[index].name, name, sizeof(students[index].name) - 1);
    students[index].grade = grade;
}

void printStudents(Student* students, int n) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Student ID: %d, Name: %s, Grade: %.2f\n", students[i].student_id, students[i].name, students[i].grade);
    }
}

void freeMemory(Student* students) {
    free(students);
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = malloc(n * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int id;
        char name[50];
        float grade;

        printf("\nEnter data for student %d\n", i + 1);
        printf("Enter student ID: ");
        scanf("%d", &id);

        getchar();

        printf("Enter student name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter grade: ");
        scanf("%f", &grade);

        addStudent(i, students, id, name, grade);
    }

    printStudents(students, n);

    freeMemory(students);

    return 0;
}
