#include "Manage.h"

Account* login(AccountList* src,Account * acc) {
	string username;
	string password;
	cout << "User name: ";
	getline(cin, acc->username);
	cout << "Password: ";
	getline(cin, acc->password);
	
	for (Account* p = src->Head; p; p = p->next) {
		if ((p->username == acc->username) && (p->password == acc->password)) {
			printf("Dang nhap thanh cong. ");
            return p;
		}
	}
	printf("Dang nhap khong thanh cong !!!");
}

void Menu(Account * acc) {
	switch (acc->Role)
	{
	case 1:
	case 2:
	case 3:

	default:
		break;
	}
}

int StudentMenu() {
    int k;
    while (true) {
        system("cls");
        cout << "HOC SINH\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Nhap danh sach sinh vien.                     **\n";
        cout << "**  2. Xuat danh sach sinh vien.                     **\n";
        cout << "**  3. Dem so luong sinh vien.                       **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> k;
        switch (k) {
        case 1:
            _getch();
            break;
        case 2:
            _getch();
            break;
        case 3:
            _getch();
            break;
        case 0:
            cout << "\nThoat. ";
            _getch();
            return 0;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong menu.";
            _getch();
            break;
        }
    }
}