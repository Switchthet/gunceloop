using namespace std;
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <regex>
#include <conio.h>

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
    void sikayetOku();
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
    Kullanici(string kullanici_adi, string sifre) {
        this->kullanici_adi = kullanici_adi;
        this->sifre = sifre;
    }
    void kiyafetGoster();
    void siparisTakip();
    void sikayetOlustur();
    void sifreDegistir();
    void kullaniciMenu();

    void elbiseGoster();
    void tisortGoster();
    void pantolonGoster();
    void gomlekGoster();
    void etekGoster();
    void ayakkabiGoster();

};

Kullanici kullanicim("asdasd", "asdasda");
Yonetici yoneticim("a");

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
        anaMenu();
        break;
    default:
        yoneticim.yoneticiMenu();
        break;
    }
}

#pragma region URUN GIRISLERI
void Yonetici::elbiseGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    string kiyafetAdi;
    double fiyat;

    cout << "Kiyafet Adi:";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream elbiseTXT;
    elbiseTXT.open("elbise.TXT", ios_base::app);
    elbiseTXT << kiyafetAdi + "." + beden + "." + renk << endl;
    elbiseTXT << kiyafetAdi << endl;
    elbiseTXT << beden << endl;
    elbiseTXT << renk << endl;
    elbiseTXT << fiyat << endl;
    elbiseTXT.close();
    yoneticim.yoneticiMenu();
}

void Yonetici::tisortGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream tisortTXT;
    tisortTXT.open("elbise.TXT", ios_base::app);
    tisortTXT << beden + "." + renk << endl;
    tisortTXT << fiyat << endl;
    tisortTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::pantolonGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream pantolonTXT;
    pantolonTXT.open("elbise.TXT", ios_base::app);
    pantolonTXT << beden + "." + renk << endl;
    pantolonTXT << fiyat << endl;
    pantolonTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::gomlekGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream gomlekTXT;
    gomlekTXT.open("elbise.TXT", ios_base::app);
    gomlekTXT << beden + "." + renk << endl;
    gomlekTXT << fiyat << endl;
    gomlekTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::etekGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream etekTXT;
    etekTXT.open("elbise.TXT", ios_base::app);
    etekTXT << beden + "." + renk << endl;
    etekTXT << fiyat << endl;
    etekTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::ayakkabiGirisi() {
    temizle();
    cin.ignore();
    string numara;
    string renk;
    double fiyat;
    cout << "Numara: ";
    cin >> numara;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream ayakkabiTXT;
    ayakkabiTXT.open("elbise.TXT", ios_base::app);
    ayakkabiTXT << numara + "." + renk << endl;
    ayakkabiTXT << fiyat << endl;
    ayakkabiTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::urunGirisi() {
    temizle();
    int menuNo;
    cout << "1. Elbise Ekle\n2. Tisort Ekle\n3. Pantolon Ekle\n4. Gomlek Ekle\n5. Etek Ekle\n6. Ayakkabi Ekle";
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
        break;
    case 4:
        yoneticim.gomlekGirisi();
        break;
    case 5:
        yoneticim.etekGirisi();
        break;
    case 6:
        yoneticim.ayakkabiGirisi();
        break;
    default:
        break;
    }
};
#pragma endregion

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
        kullanicim.siparisTakip();
        break;
    case 3:
        kullanicim.sikayetOlustur();
        break;
    case 4:
        kullanicim.sifreDegistir();
        break;
    case 5:
        anaMenu();
        break;
    default:
        break;
    }
}

void Kullanici::kiyafetGoster() {
    temizle();
    int menuNo;
    cout << "1'e bas\n";
    cin >> menuNo;

    switch (menuNo) {
    case 1:
        kullanicim.elbiseGoster();
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    default:
        break;
    }
};

void Kullanici::elbiseGoster() {
    temizle();
    cin.ignore();
    string satir;
    vector<string> elbiseler;
    ifstream elbiseTXT;
    elbiseTXT.open("elbise.txt");
    while (getline(elbiseTXT, satir)) elbiseler.push_back(satir);

    int menuNum;
    int a = 1;
    cout << "1.Ekoseli Elbise\n2.Drapeli Elbise\n3.Straplez Elbise" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        temizle();
        for (int i = 0; i < elbiseler.size(); i++)
        {
            if (elbiseler[i] == "Ekoseli") { 
                string b = to_string(a);
                cout << b + "." + elbiseler[i + 2] + " Ekoseli Elbise\nBeden: " + elbiseler[i + 1] + "\nFiyat: " + elbiseler[i + 3] << endl;
                a++;
            }
        }
        break;
    case 2:
        for (int i = 0; i < elbiseler.size(); i++)
        {
            if (elbiseler[i] == "Drapeli") {
                string b = to_string(a);
                cout << b + "." + elbiseler[i + 2] + " Drapeli Elbise\nBeden: " + elbiseler[i + 1] + "\nFiyat: " + elbiseler[i + 3] << endl;
                a++;
            }
        }
        break;
    case 3:
        for (int i = 0; i < elbiseler.size(); i++)
        {

            if (elbiseler[i] == "Straplez") {

                string b = to_string(a);
                cout << b + "." + elbiseler[i + 2] + " Straplez Elbise\nBeden: " + elbiseler[i + 1] + "\nFiyat: " + elbiseler[i + 3] << endl;
                a++;
            }
        }
        break;
    default:
        break;
    }
}
void Kullanici::tisortGoster() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream tisortTXT;
    tisortTXT.open("elbise.TXT", ios_base::app);
    tisortTXT << beden + "." + renk << endl;
    tisortTXT << fiyat << endl;
    tisortTXT.close();
    yoneticim.yoneticiMenu();
};
void Kullanici::pantolonGoster() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream pantolonTXT;
    pantolonTXT.open("elbise.TXT", ios_base::app);
    pantolonTXT << beden + "." + renk << endl;
    pantolonTXT << fiyat << endl;
    pantolonTXT.close();
    yoneticim.yoneticiMenu();
};
void Kullanici::gomlekGoster() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream gomlekTXT;
    gomlekTXT.open("elbise.TXT", ios_base::app);
    gomlekTXT << beden + "." + renk << endl;
    gomlekTXT << fiyat << endl;
    gomlekTXT.close();
    yoneticim.yoneticiMenu();
};
void Kullanici::etekGoster() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    double fiyat;
    cout << "Beden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream etekTXT;
    etekTXT.open("elbise.TXT", ios_base::app);
    etekTXT << beden + "." + renk << endl;
    etekTXT << fiyat << endl;
    etekTXT.close();
    yoneticim.yoneticiMenu();
};
void Kullanici::ayakkabiGoster() {
    temizle();
    cin.ignore();
    string numara;
    string renk;
    double fiyat;
    cout << "Numara: ";
    cin >> numara;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream ayakkabiTXT;
    ayakkabiTXT.open("elbise.TXT", ios_base::app);
    ayakkabiTXT << numara + "." + renk << endl;
    ayakkabiTXT << fiyat << endl;
    ayakkabiTXT.close();
    yoneticim.yoneticiMenu();
};

void Kullanici::siparisTakip() {};

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

#pragma region GIRIS VE KAYIT FONKSIYONLARI

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
    char karakter = _getch();
    while (karakter != '\r')
    {
        if (karakter == '\b')
        {
            if (sifre.length() > 0)
            {
                sifre.erase(sifre.length() - 1);
                _putch('\b');
                _putch(' ');
                _putch('\b');
            }
        }
        else {
            sifre += karakter;
            _putch('*');
        }
        karakter = _getch();
    }

    kontrol = kullaniciAdi + "." + sifre;

    ifstream kullanicilarTXT;
    kullanicilarTXT.open("kullanıcılar.txt");
    while (getline(kullanicilarTXT, satir)) kullanicilar.push_back(satir);

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        cout << kullanicilar[i] << endl;
        if (kontrol == kullanicilar[i]) {
            cout << "basarili" << endl;
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

void kullaniciUyeKayit() {
    string sifre;
    string eMail;
    string kullaniciAdi;
    string satirlar;
    int menuNo;
    regex pattern("^[a-zA-Z0-9][a-zA-Z0-9._]*@[a-zA-Z0-9]+([.][a-zA-Z]+)+$");
    bool gecis = true;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;

    cout << "\nSifre: ";
    char karakter = _getch();
    while (karakter != '\r')
    {
        if (karakter == '\b')
        {
            if (sifre.length() > 0)
            {
                sifre.erase(sifre.length() - 1);
                _putch('\b');
                _putch(' ');
                _putch('\b');
            }
        }
        else {
            sifre += karakter;
            _putch('*');
        }
        karakter = _getch();
    }

    cin.ignore();
    cout << "\n\nE-Mail: ";
    getline(cin, eMail);
    if (regex_search(eMail, pattern))
    {
        ofstream kullanicilarTXT;
        kullanicilarTXT.open("kullanıcılar.TXT", ios_base::app);
        kullanicilarTXT << kullaniciAdi + "." + sifre << endl;
        kullanicilarTXT << kullaniciAdi << endl;
        kullanicilarTXT << sifre << endl;
        kullanicilarTXT << eMail << endl;
        kullanicilarTXT.close();
    }
    else {
        kullaniciUyeKayit();
    }

    while (gecis) {
        cout << "\nBasariyla kaydoldunuz. Geri gelmek icin lutfen 5'e basiniz.\n";
        cin >> menuNo;
        if (menuNo == 5) {
            gecis = false;
            anaMenu();
        }
    }
}
#pragma endregion

void temizle() {
    cout << "\x1B[2J\x1B[H";
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