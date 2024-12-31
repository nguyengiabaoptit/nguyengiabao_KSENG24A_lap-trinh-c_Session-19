#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void deleteStudent(int id, struct Student students[], int *currentLength) {
    int i, j;
    int found = 0;
    for (i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--; 
            printf("Sinh vien voi ID %d duoc xoa la \n", id);
            break;
        }
    }

    if (!found) {
        printf("Sinh vien voi ID %d khong ton tai trong danh sach la \n", id);
    }
}
void printStudents(struct Student students[], int currentLength) {
    printf("\nDanh sach sinh vien:\n");
    int i; 
    for (i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int currentLength = 5; 
    students[0] = (struct Student) {1, "Nguyen A", 20, "0901234567"};
    students[1] = (struct Student) {2, "Tran B", 21, "0912345678"};
    students[2] = (struct Student) {3, "Le C", 22, "0923456789"};
    students[3] = (struct Student) {4, "Pham D", 23, "0934567890"};
    students[4] = (struct Student) {5, "Hoang E", 24, "0945678901"};
    printStudents(students, currentLength);
    int idToDelete;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &idToDelete);
    deleteStudent(idToDelete, students, &currentLength);
    printStudents(students, currentLength);
    return 0;
}

