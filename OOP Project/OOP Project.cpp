using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>

void temizle();
void anaMenu();
void yenile();

#pragma region SINIFLAR

class Zaman {
public:
    int saat;
    int dakika;
};

class Kiyafet {
public:
    char* kategori;
    int kiyafet_adi;
    double fiyat;
    char* boyut;
    char* renk;
};

class Siparis : public Kiyafet {
public:
    int siparis_no;
    double siparis_fiyat;
    Zaman siparis_baslangic;
    Zaman siparis_ulasim;
};

class Kisi {
public:
    char* ad_soyad;
    char telno;
};

class Kurye : public Kisi{
public:
    Zaman* dagitim_bitisler;
    int* siparis_numaralari;
};

class Yonetici : public Kisi {
public:
    char* sifre;
    void sikayetOku() {};
    void kuryeAta() {};
    void indirimKoduTanimla() {};
    void faturaGoster() {};
};

class Kullanici : public Kisi {
public:
    void kiyafetGoster() {};
    void siparisGoster() {};
    void sikayetOlustur() {};
    void sifreDegistir() {};
};
#pragma endregion

#pragma region FONKSİYONLAR
void yoneticiMenu(Yonetici& admin) {
    temizle();
    int menuNum;
    cout << "1. Urun Girisi\n2. Kurye Atama\n3. Sikayet ve Oneri Okuma\n4. Kullanicilara Indirim Kodu Tanimlama\n5. Siparislerin Faturalarini Goruntule\n";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        break;
    case 2:
        admin.kuryeAta();
    case 3:
        admin.sikayetOku();
    case 4:
        admin.indirimKoduTanimla();
    case 5:
        admin.faturaGoster();
    default:
        break;
    }
}

void yoneticiGirisMenu() {
    string sifre;
    string yoneticiSifre;
    int menuNum;
    temizle();
    cout << "Sifre:";
    cin >> sifre;
    ifstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    getline(kullanıcılarTXT, yoneticiSifre);    
}

void kullaniciGirisMenu() {
    string kullaniciAdi;
    string sifre;
    string kontrol;
    int menuNum;
    string satir;
    vector<string> kullanicilar;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "\nSifre: ";
    cin >> sifre;
    kontrol = kullaniciAdi + ":" + sifre;

    ifstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    while (getline(kullanıcılarTXT, satir)) {
        stringstream ss(satir);
        while (getline(ss, satir, '.')) {
            kullanicilar.push_back(satir);
        }
    }

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        if (kontrol == kullanicilar[i]) {
            cout << "basarili";
            break;
        }
        else {
            cout << "basarisiz";
        }
    }
}

void temizle() {
    cout << "\x1B[2J\x1B[H";
}

void girisMenu() {
    int menuNum;
    temizle();
    cout << "1. Yonetici Giris\n2. Musteri Giris\n3. Geri\n";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        yoneticiGirisMenu();
        break;
    case 2:
        kullaniciGirisMenu();
        break;
    case 3:
        anaMenu();
    default:
        break;
    }
}

void kullaniciUyeKayit() {
    string sifre;
    string eMail;
    string kullaniciAdi;
    string satirlar;
    int menuNo;
    bool gecis = true;
    vector<string> kullanicilar;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "\nSifre: ";
    cin >> sifre;
    cout << "\nE-Mail: ";
    cin >> eMail;

    ofstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.TXT",ios_base::app);
    kullanıcılarTXT << kullaniciAdi + ":" + sifre + "." + eMail + "." << endl;
    kullanıcılarTXT.close();

    while (gecis == true) {
        cout << "\nBasariyla kaydoldunuz. Geri gelmek icin lutfen 5'e basiniz.";
        cin >> menuNo;
        if (menuNo == 5) {
            gecis = false;
            anaMenu();
        }
    }

}

void anaMenu() {
    int menuNum;
    cout << "1. Giris\n2. Uye Kaydi\n3. Cikis\n";
    cin >> menuNum;
    switch (menuNum) {
    case 1:
        girisMenu();
        break;
    case 2:
        kullaniciUyeKayit();
        break;
    default:
        break;
    }
}

void yenile() {
    string line;
    int customerNo;
    vector<string> customers;

    ifstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    while (getline(kullanıcılarTXT, line)) {
        stringstream ss(line);
        while (getline(ss, line, '.')) {
            customers.push_back(line);
        }
    }
    kullanıcılarTXT.close();
}
#pragma endregion

int main()  
{
    yenile();
    anaMenu();
}