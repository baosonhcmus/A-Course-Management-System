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
            *a = *p;
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
void viewProfileAcc(Account* a) {
    cout << "First Name: " << a->acc.firstName << endl;
    cout << "Last Name: " << a->acc.lastName << endl;
    cout << "Gender: ";
    if (a->acc.Gender == 0) cout << "Male" << endl;
    else cout << "Female" << endl;
    cout << "Social ID: " << a->acc.SocialID << endl;
    cout << "Date of birth: " << a->acc.Dob.dd << "/" << a->acc.Dob.mm << "/" << a->acc.Dob.yy << endl;
    cout << "Position: ";
    if (a->acc.Role == 1) cout << "Staff" << endl;
    else cout << "Student" << endl;
}
void changePassAcc(AccountList& l, Account* a) {
    cout << "Enter old password: ";
    string oldpass;
    cin.ignore(1);
    getline(cin, oldpass);
    if (oldpass == a->acc.password) {
        cout << "Enter new password: ";
        string newpass;
        getline(cin, newpass);
        Account* p = l.Head;
        while (p->acc.username != a->acc.username) {
            p = p->next;
        }
        p->acc.password = newpass;
        fstream fin;
        fin.open("account.csv", ios::in);
        string line[50];
        string temp;
        int i = 0;
        int pos =0;
        while (fin >> temp) {
            line[i] = temp;
            if (temp.find(a->acc.SocialID) != string::npos) pos = i;
            i++;
        }
        fin.close();
        ofstream outfile;
        outfile.open("account.csv", ios::out | ios::trunc);
        for (int j = 0; j < i; j++) {
            if (j != pos) outfile << line[j] << endl;
        }
        outfile << a->acc.username << "," << newpass << "," << a->acc.firstName << "," << a->acc.lastName << "," << a->acc.Gender << "," << a->acc.SocialID << "," << a->acc.Dob.yy << "-" << a->acc.Dob.mm << "-" << a->acc.Dob.dd << "," << a->acc.Role;
        outfile.close();
        cout << "Change password successfully.";
    }
    else cout << "Wrong password !!!";
}

int App_Student(AccountList& l,Account* a) {
    int k;
    while (true) {
        system("cls");
        cout << "STUDENT\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Change pass.                                  **\n";
        cout << "**  2. View profile.                                 **\n";
        cout << "**  3. ...                                           **\n";
        cout << "**  4. Log out.                                      **\n";
        cout << "**  0. Exit.                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> k;
        switch (k) {
        case 1:
            changePassAcc(l, a);
            _getch();
            break;
        case 2:
            viewProfileAcc(a);
            _getch();
            break;
        case 4:
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

    if (a->acc.Role == 2) {
        App_Student(l, a);
    }


    return 0;

}