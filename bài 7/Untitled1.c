#include <stdio.h>
#include <stdlib.h>
int main(){

struct Student {
    int id[50];
    char name[50];
    int age[50];
    char phoneNumber[50];
};

struct deleteStudent[100];
    int position = -1;

    for (int i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            position = i;
            break;
        }
    }

    if (position == -1) {
        cout << "Khong tim thay sinh vien voi id " << id << endl;
        return;
    }
    for (int i = position; i < currentLength - 1; i++) {
        students[i] = students[i + 1];
    }

    currentLength--;
    cout << "Da xoa sinh vien voi id " << id << endl;
}

void printStudents(Student students[], int currentLength) {
    cout << "Danh sach sinh vien:" << endl;
    for (int i = 0; i < currentLength; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age
             << ", Phone: " << students[i].phoneNumber << endl;
    }
}

int main() {
    
    const int MAX_SIZE = 5;
    Student students[MAX_SIZE] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van C", 22, "0345678912"},
        {4, "Pham Thi D", 23, "0567891234"},
        {5, "Hoang Van E", 24, "0789123456"}
    };

    int currentLength = MAX_SIZE; 

    printStudents(students, currentLength);

    int idToDelete;
    cout << "Nhap id sinh vien can xoa: ";
    cin >> idToDelete;

    deleteStudent(idToDelete, students, currentLength);

    printStudents(students, currentLength);

    return 0;
}
}

