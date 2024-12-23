#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int id;
    string ten;
    int tuoi;
    string lop;
};

void hienThiDanhSach(const vector<SinhVien>& ds) {
    if (ds.empty()) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }
    for (const auto& sv : ds) {
        cout << "ID: " << sv.id << ", Ten: " << sv.ten << ", Tuoi: " << sv.tuoi << ", Lop: " << sv.lop << endl;
    }
}

void themSinhVien(vector<SinhVien>& ds) {
    SinhVien sv;
    cout << "Nhap ID: ";
    cin >> sv.id;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, sv.ten);
    cout << "Nhap tuoi: ";
    cin >> sv.tuoi;
    cin.ignore();
    cout << "Nhap lop: ";
    getline(cin, sv.lop);
    ds.push_back(sv);
    cout << "Them sinh vien thanh cong!" << endl;
}

void suaThongTinSinhVien(vector<SinhVien>& ds) {
    int id;
    cout << "Nhap ID sinh vien can sua: ";
    cin >> id;
    for (auto& sv : ds) {
        if (sv.id == id) {
            cin.ignore();
            cout << "Nhap ten moi: ";
            getline(cin, sv.ten);
            cout << "Nhap tuoi moi: ";
            cin >> sv.tuoi;
            cin.ignore();
            cout << "Nhap lop moi: ";
            getline(cin, sv.lop);
            cout << "Sua thong tin thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ID da nhap!" << endl;
}

void xoaSinhVien(vector<SinhVien>& ds) {
    int id;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> id;
    auto it = remove_if(ds.begin(), ds.end(), [id](const SinhVien& sv) {
        return sv.id == id;
    });
    if (it != ds.end()) {
        ds.erase(it, ds.end());
        cout << "Xoa sinh vien thanh cong!" << endl;
    } else {
        cout << "Khong tim thay sinh vien voi ID da nhap!" << endl;
    }
}

void timKiemSinhVien(const vector<SinhVien>& ds) {
    int id;
    cout << "Nhap ID sinh vien can tim: ";
    cin >> id;
    for (const auto& sv : ds) {
        if (sv.id == id) {
            cout << "ID: " << sv.id << ", Ten: " << sv.ten << ", Tuoi: " << sv.tuoi << ", Lop: " << sv.lop << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ID da nhap!" << endl;
}

void sapXepDanhSach(vector<SinhVien>& ds) {
    sort(ds.begin(), ds.end(), [](const SinhVien& a, const SinhVien& b) {
        return a.ten < b.ten;
    });
    cout << "Sap xep danh sach thanh cong!" << endl;
}

int main() {
    vector<SinhVien> danhSach;
    int luaChon;

    do {
        cout << "\nMENU\n";
        cout << "1. Hien thi danh sach sinh vien\n";
        cout << "2. Them sinh vien\n";
        cout << "3. Sua thong tin sinh vien\n";
        cout << "4. Xoa sinh vien\n";
        cout << "5. Tim kiem sinh vien\n";
        cout << "6. Sap xep danh sach sinh vien\n";
        cout << "7. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                hienThiDanhSach(danhSach);
                break;
            case 2:
                themSinhVien(danhSach);
                break;
            case 3:
                suaThongTinSinhVien(danhSach);
                break;
            case 4:
                xoaSinhVien(danhSach);
                break;
            case 5:
                timKiemSinhVien(danhSach);
                break;
            case 6:
                sapXepDanhSach(danhSach);
                break;
            case 7:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long nhap lai!" << endl;
        }
    } while (luaChon != 7);

    return 0;
}

