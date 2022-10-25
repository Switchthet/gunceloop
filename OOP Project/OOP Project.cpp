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
void kullaniciGirisMenu();

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
    string kullanici_adi;
    char* eposta;
    char* adres_ilce;
    string sifre;
    char* indirim_kodu;
    char* dtarihi;
    Kullanici();
    Kullanici(string kullanici_adi, string sifre) {
        this->kullanici_adi = kullanici_adi;
        this->sifre = sifre;
    }
    void kiyafetGoster();
    void siparisGoster();
    void sikayetOlustur();
    void sifreDegistir();
    void kullaniciMenu();
};
#pragma endregion

Kullanici kullanicim("","");

#pragma region FONKSİYONLAR
//void yoneticiMenu() {
//    temizle();
//    int menuNum;
//    cout << "1. Urun Girisi\n2. Kurye Atama\n3. Sikayet ve Oneri Okuma\n4. Kullanicilara Indirim Kodu Tanimlama\n5. Siparislerin Faturalarini Goruntule\n";
//    cin >> menuNum;
//    switch (menuNum)
//    {
//    case 1:
//        break;
//    case 2:
//        kuryeAta();
//    case 3:
//        admin.sikayetOku();
//    case 4:
//        admin.indirimKoduTanimla();
//    case 5:
//        admin.faturaGoster();
//    default:
//        break;
//    }
//}

void Kullanici::kullaniciMenu() {
    temizle();
    int menuNum;
    cout << "1. Kiyafet Kategorilerini Goster ve Urun Sec\n2. Siparis Takip\n3. Sikayet ve Oneri Olustur\n4. Sifre Degistir\n5. Geri Don\n";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        kullanicim.kiyafetGoster();
    case 2:
        kullanicim.siparisGoster();
    case 3:
        kullanicim.sikayetOlustur();
    case 4:
        kullanicim.sifreDegistir();
    case 5:
        kullaniciGirisMenu();
    default:
        break;
    }
}

void Kullanici::kiyafetGoster() {};

void Kullanici::siparisGoster() {};

void Kullanici::sikayetOlustur() {
    ofstream öneriTXT;
    string öneri;
    bool gecis = true;
    öneriTXT.open("öneri.TXT",ios_base::app);
    cout << "\noneri yaziniz: " << endl;
    cin >> öneri;
    öneriTXT << öneri << endl;
    öneriTXT.close();
    kullaniciMenu();
};

void Kullanici::sifreDegistir() {
    string yeniSifre;
    string eskiSifre;
    string satir;
    string kontrol;
    cout << "Eski sifrenizi giriniz: ";
    cin >> eskiSifre;
    cout << "\nYeni sifrenizi giriniz: ";
    cin >> yeniSifre;
    kontrol = kullanicim.kullanici_adi + "." + kullanicim.sifre;
    vector<string> kullanicilar;

    ifstream kullanıcılarTXTokuma;
    kullanıcılarTXTokuma.open("kullanıcılar.txt");
    while (getline(kullanıcılarTXTokuma, satir)) kullanicilar.push_back(satir);
    kullanıcılarTXTokuma.close();

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        if (kontrol == kullanicilar[i]) {
            kullanicim.sifre == yeniSifre;
            kullanicilar[i] = kullanicim.kullanici_adi + "." + yeniSifre;
            kullanicilar[i + 2] = yeniSifre;
        }
    }
    

    ofstream kullanıcılarTXTyazma;
    kullanıcılarTXTyazma.open("kullanıcılar.txt", ios::trunc);
    for (int a = 0; a < kullanicilar.size(); a++)
    {
        kullanıcılarTXTyazma << kullanicilar[a] << endl;
    }
    kullanıcılarTXTyazma.close();
};

void yoneticiGirisMenu() {
    int a = 5;
}

void kullaniciGirisMenu() {
    string kullaniciAdi;
    string sifre;
    string kontrol;
    string satir;
    string objeNo;
    vector<string> kullanicilar;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "\nSifre: ";
    cin >> sifre;
    kontrol = kullaniciAdi + "." + sifre;

    ifstream kullanıcılarTXT;
    kullanıcılarTXT.open("kullanıcılar.txt");
    while (getline(kullanıcılarTXT, satir)) kullanicilar.push_back(satir);

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        cout << kullanicilar[i] << endl;
        if (kontrol == kullanicilar[i]) {
            cout << "basarili" << endl;
            string objeNo = to_string(i);
            Kullanici i(kullaniciAdi, sifre);
            kullanicim = i;
            kullanicim.kullaniciMenu();
            break;
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
    kullanıcılarTXT << kullaniciAdi + "." + sifre << endl;
    kullanıcılarTXT << kullaniciAdi << endl;
    kullanıcılarTXT << sifre << endl;
    kullanıcılarTXT << eMail << endl;
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
    yenile();
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
    anaMenu();
}