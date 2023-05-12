#include "Manage.h"

Account* getNode(AccountInf a) {
    Account* p = new Account;
    if (p == NULL) {
        printf("loi het bo nho: "); exit(0);
    }

    p->acc = a;
    p->next = NULL;
    return p;
}

void loadAccount(AccountList& l) {
    fstream fin;
    fin.open("account.csv", ios::in);
    string line, word, temp;
    int n = 0;
    while (fin >> temp) {

        string row[10];
        stringstream s(temp);
        AccountInf k;
        int i = 0;
        string::size_type sz;
        while (getline(s, word,',')) {  
            row[i] = word;
            i++;
        }
        if (n==0){ 
            row[0].erase(0,3);
            k.username = row[0]; 
        }
        else k.username = row[0];
        k.password = row[1];
        k.firstName = row[2];
        k.lastName = row[3];
        k.Gender = stoi(row[4],&sz);
        k.SocialID = row[5];
        stringstream ss(row[6]);
        string token;
        int count = 0;
        while (!ss.eof()) {
            getline(ss, token,'-');
            if (count == 0) k.Dob.yy = stoi(token, &sz);
            else if (count == 1) k.Dob.mm = stoi(token, &sz);
            else k.Dob.dd = stoi(token, &sz);
            count++;
        }
        k.Role = stoi(row[7], &sz);

        Account* temp, * p;
        temp = getNode(k);
        if (l.Head == NULL) {
            l.Head = temp;
        }
        else {
            p = l.Head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
        n++;
    }

}
void outputAcc(AccountList l) {
    for (Account* p = l.Head; p; p=p->next) {
        cout << p->acc.username << "\t" << p->acc.password << "\t" << p->acc.lastName << endl;
    }
}

int login(AccountList l,Account* a) {

	for (Account* p = l.Head; p; p = p->next) {
		if ((p->acc.username == a->acc.username) && (p->acc.password == a->acc.password)) {
			printf("Dang nhap thanh cong. ");
            a = p;
            return 1;
		}
	}
	printf("Dang nhap khong thanh cong !!!");
    _getch();
    return 0;
}

void Menu(Account * a) {
	switch (a->acc.Role)
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

int main() {
    AccountList l;
    l.Head = new Account;
    if (l.Head == NULL) {
        printf("khong du bo nho: ");
        exit(0);
    }
    l.Head->next = NULL;
    cout << "loading account...\n";
    loadAccount(l);
    //outputAcc(l);
    Account* a = new Account;
    do { 
        system("cls");
        cout << "User name: ";
        getline(cin, a->acc.username);
        cout << "Password: ";
        getline(cin, a->acc.password);
    } while (!login(l,a));


    return 0;

}