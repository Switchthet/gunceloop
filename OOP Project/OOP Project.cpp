using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>

Kullanici kullanicim("default", "default");
Yonetici yoneticim("a");

void temizle();
void anaMenu();
void kullaniciGirisMenu();
void yoneticiGirisMenu();

#pragma region SINIFLAR

class Zaman {
public:
    int saat;
    int dakika;
};

class Kiyafet {
public:
    string kategori;
    int kiyafet_adi;
    double fiyat;
    string boyut;
    string renk;
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
    string sifre;
    Yonetici(string a) {
        this->sifre = a;
    }
    void urunGirisi();
    void elbiseGirisi();
    void tisortGirisi();
    void pantolonGirisi();
    void gomlekGirisi();
    void etekGirisi();
    void ayakkabiGirisi();
    void sikayetOku() ;
    void kuryeAta();
    void indirimKoduTanimla();
    void faturaGoster();
    void yoneticiMenu();
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

#pragma region FONKSİYONLAR
#pragma region YONETICI FONKSIYONLARI
void Yonetici::yoneticiMenu() {
    temizle();
    int menuNum;
    cout << "1. Urun Girisi\n2. Kurye Atama\n3. Sikayet ve Oneri Okuma\n4. Kullanicilara Indirim Kodu Tanimlama\n5. Siparislerin Faturalarini Goruntule\n6. Geri Don";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        yoneticim.urunGirisi();
        break;
    case 2:
        yoneticim.kuryeAta();
        break;
    case 3:
        yoneticim.sikayetOku();
        break;
    case 4:
        yoneticim.indirimKoduTanimla();
        break;
    case 5:
        yoneticim.faturaGoster();
        break;
    case 6:
        yoneticiGirisMenu();
        break;
    default:
        yoneticim.yoneticiMenu();
        break;
    }
}

void Yonetici::elbiseGirisi() {
    temizle();
    cin.ignore();
    string boyut;
    string renk;
    string kategori;
    int kiyafetAdi;
    double fiyat;

    ofstream elbiseTXT;
    elbiseTXT.open("elbise.TXT");
}

void Yonetici::tisortGirisi() {};


void Yonetici::pantolonGirisi() {};


void Yonetici::gomlekGirisi() {};


void Yonetici::etekGirisi() {};


void Yonetici::ayakkabiGirisi() {};

void Yonetici::urunGirisi() {
    int menuNo;
    cout << "1. Elbise Ekle\n2. Tisört Ekle\n3. Pantolon Ekle\n4. Gömlek Ekle\n5. Etek Ekle\6. Ayakkabi Ekle";
    cin >> menuNo;

    switch (menuNo) {
    case 1:
        yoneticim.elbiseGirisi();
        break;
    case 2:
        yoneticim.tisortGirisi();
        break;
    case 3:
        yoneticim.pantolonGirisi();
    case 4:

    case 5:

    case 6:

    default:
        break;
   }
};

void Yonetici::sikayetOku() {
    temizle();
    string satir;
    int menuNum;
    bool gecis = true;
    vector <string> oneriler;
    ifstream oneriTXT;
    oneriTXT.open("öneri.TXT");
    while (getline(oneriTXT, satir)) oneriler.push_back(satir);
    for (int i = 0; i < oneriler.size(); i++)
    {
        cout << oneriler[i] << endl;
    }

    while (gecis) {
        cout << "Geri gelmek icin lutfen 5'e basiniz.";
        cin.ignore();
        cin >> menuNum;
        if (menuNum == 5) {
            gecis = false;
            yoneticim.yoneticiMenu();
        }
    }

};

void Yonetici::kuryeAta() {};

void Yonetici::indirimKoduTanimla() {};

void Yonetici::faturaGoster() {};
#pragma endregion

#pragma region KULLANICI FONKSIYONLARI

void Kullanici::kullaniciMenu() {
    temizle();
    int menuNum;
    cout << "1. Kiyafet Kategorilerini Goster ve Urun Sec\n2. Siparis Takip\n3. Sikayet ve Oneri Olustur\n4. Sifre Degistir\n5. Geri Don\n";
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        kullanicim.kiyafetGoster();
        break;
    case 2:
        kullanicim.siparisGoster();
        break;
    case 3:
        kullanicim.sikayetOlustur();
        break;
    case 4:
        kullanicim.sifreDegistir();
        break;
    case 5:
        kullaniciGirisMenu();
        break;
    default:
        break;
    }
}

void Kullanici::kiyafetGoster() {};

void Kullanici::siparisGoster() {};

void Kullanici::sikayetOlustur() {
    temizle();
    cin.ignore();
    cout << "Onerinizi yaziniz: " << endl;
    string oneri;
    getline(cin, oneri);
    

    ofstream öneriTXT;
    öneriTXT.open("öneri.TXT");
    öneriTXT << oneri << endl;
    öneriTXT.close();

    kullanicim.kullaniciMenu();
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

    ifstream kullanicilarTXTokuma;
    kullanicilarTXTokuma.open("kullanıcılar.txt");
    while (getline(kullanicilarTXTokuma, satir)) kullanicilar.push_back(satir);
    kullanicilarTXTokuma.close();

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        if (kontrol == kullanicilar[i]) {
            kullanicim.sifre == yeniSifre;
            kullanicilar[i] = kullanicim.kullanici_adi + "." + yeniSifre;
            kullanicilar[i + 2] = yeniSifre;
        }
    }
    

    ofstream kullanicilarTXTyazma;
    kullanicilarTXTyazma.open("kullanıcılar.txt", ios::trunc);
    for (int a = 0; a < kullanicilar.size(); a++)
    {
        kullanicilarTXTyazma << kullanicilar[a] << endl;
    }
    kullanicilarTXTyazma.close();
};

#pragma endregion

#pragma region GIRIS FONKSIYONLARI

void yoneticiGirisMenu() {
    string sifre;
    string kontrol;
    string satir;
    vector<string> kullanicilar;
    temizle();

    cout << "Sifre: ";
    cin >> sifre;
    kontrol = "yonetici." + sifre;

    ifstream kullanicilarTXT;
    kullanicilarTXT.open("kullanıcılar.txt");
    while (getline(kullanicilarTXT, satir)) kullanicilar.push_back(satir);

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        if (kontrol == kullanicilar[i]) {
            yoneticim.yoneticiMenu();
        }
    }
}

void kullaniciGirisMenu() {
    string kullaniciAdi;
    string sifre;
    string kontrol;
    string satir;
    string objeAdi;
    vector<string> kullanicilar;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "\nSifre: ";
    cin >> sifre;
    kontrol = kullaniciAdi + "." + sifre;

    ifstream kullanicilarTXT;
    kullanicilarTXT.open("kullanıcılar.txt");
    while (getline(kullanicilarTXT, satir)) kullanicilar.push_back(satir);

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        cout << kullanicilar[i] << endl;
        if (kontrol == kullanicilar[i]) {
            cout << "basarili" << endl;
            //string objeNo = to_string(i);
            objeAdi = kullaniciAdi;
            Kullanici objeAdi(kullaniciAdi, sifre);
            kullanicim = objeAdi;
            kullanicim.kullaniciMenu();
            break;
        }
    }
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

#pragma endregion

void temizle() {
    cout << "\x1B[2J\x1B[H";
}

void kullaniciUyeKayit() {
    string sifre;
    string eMail;
    string kullaniciAdi;
    string satirlar;
    int menuNo;
    bool gecis = true;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;
    cout << "\nSifre: ";
    cin >> sifre;
    cout << "\nE-Mail: ";
    cin >> eMail;

    ofstream kullanicilarTXT;
    kullanicilarTXT.open("kullanıcılar.TXT",ios_base::app);
    kullanicilarTXT << kullaniciAdi + "." + sifre << endl;
    kullanicilarTXT << kullaniciAdi << endl;
    kullanicilarTXT << sifre << endl;
    kullanicilarTXT << eMail << endl;
    kullanicilarTXT.close();

    while (gecis) {
        cout << "\nBasariyla kaydoldunuz. Geri gelmek icin lutfen 5'e basiniz.";
        cin.ignore();
        cin >> menuNo;
        if (menuNo == 5) {
            gecis = false;
            anaMenu();
        }
    }

}

void anaMenu() {
    temizle();
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
#pragma endregion

int main()  
{
    anaMenu();
}