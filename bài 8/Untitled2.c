#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int id;
    char name;
    int age;
    char phoneNumber;
};

bool compareByName(const SinhVien &a, const SinhVien &b) {
    return a.name < b.name;
}

void sapXepSinhVien(SinhVien svArray[], int size) {
    sort(svArray, svArray + size, compareByName);
}

void inDanhSachSinhVien(SinhVien svArray[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "ID: " << svArray[i].id
             << ", Name: " << svArray[i].name
             << ", Age: " << svArray[i].age
             << ", Phone: " << svArray[i].phoneNumber << endl;
    }
}

int main() {
    // Khai báo m?ng sinh viên v?i 5 ph?n t?
    SinhVien danhSach[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 22, "0987654321"},
        {3, "Le Van C", 19, "0345678912"},
        {4, "Pham Thi D", 21, "0567891234"},
        {5, "Hoang Van E", 20, "0789123456"}
    };

    cout << "Danh sach sinh vien truoc khi sap xep:\n";
    inDanhSachSinhVien(danhSach, 5);

    sapXepSinhVien(danhSach, 5);

    cout << "\nDanh sach sinh vien sau khi sap xep:\n";
    inDanhSachSinhVien(danhSach, 5);

    return 0;
}

