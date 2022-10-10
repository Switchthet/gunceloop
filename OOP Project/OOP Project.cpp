using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

void clear();
void MainMenu();
void Reload();

class Courier {
private:
    int courierNo;
    bool isBusy;
public:
    Courier(int courierNo, bool isBusy) {
        SetCourierNo(courierNo);
        SetIsBusy(isBusy);
    }
    //getter setter fonksiyonları
    void SetCourierNo(int courierNo) { this->courierNo = courierNo; }
    int GetCourierNo() { return courierNo; }
    void SetIsBusy(bool isBusy) {this->isBusy = isBusy;}
    bool GetIsBusy() {return isBusy;}
};

class Member {
public:
    string userName;
    string password;
    string eMail;
    Member() {};
    Member(string fName, string lName, string password, string eMail) {
        this->userName = fName + " " + lName;
        this->password = password;
        this->eMail = eMail;
        cout << "Kullanici adiniz: " + this->userName;
    }
};

class Manager : public Member {
public:
    void ReadComplaint() {};
    void AssignCourier() {};
    void GiveDiscountCode() {};
    void ShowReceipt() {};
    Manager(string sifre) {}
};

class Customer : public Member {
public:
    Customer(string username, string sifre) {
        this->userName = username;
        this->password = password;
    }
    void ShowClothes() {};
    void ShowOrder() {};
    void CreateComplaint() {};
    void ChangePassword() {};
};

class Order {

};


#pragma region functions

void ManagerMenu(Manager& admin) {
    clear();
    int menuNum;
    cout << "1. Urun Girisi\n2. Kurye Atama\n3. Sikayet ve Oneri Okuma\n4. Kullanicilara Indirim Kodu Tanimlama\n5. Siparislerin Faturalarini Goruntule\n";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        break;
    case 2:
        admin.AssignCourier();
    case 3:
        admin.ReadComplaint();
    case 4:
        admin.GiveDiscountCode();
    case 5:
        admin.ShowReceipt();
    default:
        break;
    }
}

void ManagerLogInMenu() {
    string password;
    string managerPassword;
    int menuNum;
    clear();
    cout << "Sifre:";
    cin >> password;
    ifstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    getline(kullanıcılarTXT, managerPassword);
    Manager manager1(password);
    if (managerPassword == password) ManagerMenu(manager1);
    else ManagerLogInMenu();
    
}

void CustomerLogInMenu() {
    string userName;
    string password;
    string control;
    int menuNum;
    string lines;
    int customerNo;
    vector<string> customers;
    clear();
    cout << "Kullanici Adi: ";
    cin >> userName;
    cout << "\nSifre: ";
    cin >> password;
    control = userName + ":" + password;
    fstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    while (getline(kullanıcılarTXT, lines, '|')) customers.push_back(lines);
    if (control == lines)
    {
        cout << "basarili giris";
    }

    else {
        cout << "tekrar deneyin";
        CustomerLogInMenu();
    }
}

void clear() {
    cout << "\x1B[2J\x1B[H";
}

void LogInMenu() {
    int menuNum;
    clear();
    cout << "1. Yonetici Giris\n2. Musteri Giris\n3. Geri\n";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        ManagerLogInMenu();
        break;
    case 2:
        CustomerLogInMenu();
        break;
    case 3:
        MainMenu();
    default:
        break;
    }
}

void CustomerSignUp() {
    string password;
    string eMail;
    string username;
    string lines;
    int menuNo;
    bool gecis = true;
    vector<string> customers;
    clear();
    cout << "Kullanici Adi: ";
    cin >> username;
    cout << "\nSifre: ";
    cin >> password;
    cout << "\nE-Mail: ";
    cin >> eMail;
    fstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.TXT",ios_base::app);
    kullanıcılarTXT <<username + ":" + password + "|" + eMail + "|" + "\n";
    while (getline(kullanıcılarTXT, lines, '|')) customers.push_back(lines);
    while (gecis == true) {
        cout << "\nBasariyla kaydoldunuz. Geri gelmek için lütfen 5'e basiniz.";
        cin >> menuNo;
        if (menuNo == 5) {
            gecis = false;
            MainMenu();
        }
    }

}

void MainMenu() {
    int menuNum;
    cout << "1. Giris\n2. Uye Kaydi\n3. Cikis\n";
    cin >> menuNum;
    switch (menuNum) {
    case 1:
        LogInMenu();
        break;
    case 2:
        CustomerSignUp();
        break;
    default:
        break;
    }
}

void Reload() {
    string lines;
    int customerNo;
    vector<string> customers;
    fstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    while (getline(kullanıcılarTXT, lines, '|')) customers.push_back(lines);
}

#pragma endregion
int main()
{
    MainMenu();
}