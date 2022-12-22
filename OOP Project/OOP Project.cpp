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
    string kiyafetAdi;
    double fiyat;
    string beden;
    string renk;
    string kategori;
    Kiyafet(string kategori, string kiyafetAdi, string beden, string renk, double fiyat) {
        this->kategori = kategori;
        this->kiyafetAdi = kiyafetAdi;
        this->beden = beden;
        this->renk = renk;
        this->fiyat = fiyat;
    }
};

class Siparis : public Kiyafet {
public:
    int siparisNo;
    double siparisFiyat;
    Zaman siparisBaslangic;
    Zaman siparisUlasim;
    Siparis(Zaman siparisBaslangic, Zaman siparisUlasim, double siparisFiyat, int siparisNo) {
        this->siparisBaslangic = siparisBaslangic;
        this->siparisUlasim = siparisUlasim;
        this->siparisFiyat = siparisFiyat;
        this->siparisNo = siparisNo;
    }
};

class Kisi {
public:
    string adSoyad;
    string telno;
};

class Kurye : public Kisi{
public:
    Zaman dagitimBitisler;
    int siparisNumaralari;
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
    void sepetiGoruntule();
};

Kullanici kullanicim("","");
Yonetici yoneticim("");
vector<Kiyafet> sepet;
vector<Kiyafet> geciciSepet;
vector<Siparis> siparis;
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

void Yonetici::elbiseGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    string kiyafetAdi;
    string kategori;
    double fiyat;

    cout << "Kategori: ";
    cin >> kategori;
    cout << "\nKiyafet Adi: ";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream elbiseTXT;
    elbiseTXT.open("elbise.TXT", ios_base::app);
    elbiseTXT << kategori << endl;
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
    string kiyafetAdi;
    string kategori;
    double fiyat;

    cout << "Kategori: ";
    cin >> kategori;
    cout << "\nKiyafet Adi: ";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream tisortTXT;
    tisortTXT.open("tisort.TXT", ios_base::app);
    tisortTXT << kategori << endl;
    tisortTXT << kiyafetAdi << endl;
    tisortTXT << beden << endl;
    tisortTXT << renk << endl;
    tisortTXT << fiyat << endl;
    tisortTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::pantolonGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    string kiyafetAdi;
    string kategori;
    double fiyat;

    cout << "Kategori: ";
    cin >> kategori;
    cout << "\nKiyafet Adi: ";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream pantolonTXT;
    pantolonTXT.open("pantolon.TXT", ios_base::app);
    pantolonTXT << kategori << endl;
    pantolonTXT << kiyafetAdi << endl;
    pantolonTXT << beden << endl;
    pantolonTXT << renk << endl;
    pantolonTXT << fiyat << endl;
    pantolonTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::gomlekGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    string kiyafetAdi;
    string kategori;
    double fiyat;

    cout << "Kategori: ";
    cin >> kategori;
    cout << "\nKiyafet Adi: ";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream gomlekTXT;
    gomlekTXT.open("gomlek.TXT", ios_base::app);
    gomlekTXT << kategori << endl;
    gomlekTXT << kiyafetAdi << endl;
    gomlekTXT << beden << endl;
    gomlekTXT << renk << endl;
    gomlekTXT << fiyat << endl;
    gomlekTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::etekGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    string kiyafetAdi;
    string kategori;
    double fiyat;

    cout << "Kategori: ";
    cin >> kategori;
    cout << "\nKiyafet Adi: ";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream etekTXT;
    etekTXT.open("etek.TXT", ios_base::app);
    etekTXT << kategori << endl;
    etekTXT << kiyafetAdi << endl;
    etekTXT << beden << endl;
    etekTXT << renk << endl;
    etekTXT << fiyat << endl;
    etekTXT.close();
    yoneticim.yoneticiMenu();
};
void Yonetici::ayakkabiGirisi() {
    temizle();
    cin.ignore();
    string beden;
    string renk;
    string kiyafetAdi;
    string kategori;
    double fiyat;

    cout << "Kategori: ";
    cin >> kategori;
    cout << "\nKiyafet Adi: ";
    cin >> kiyafetAdi;
    cout << "\nBeden: ";
    cin >> beden;
    cout << "\nRenk: ";
    cin >> renk;
    cout << "\nFiyat: ";
    cin >> fiyat;

    ofstream ayakkabiTXT;
    ayakkabiTXT.open("ayakkabi.TXT", ios_base::app);
    ayakkabiTXT << kategori << endl;
    ayakkabiTXT << kiyafetAdi << endl;
    ayakkabiTXT << beden << endl;
    ayakkabiTXT << renk << endl;
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
    cout << "1. Kiyafet Kategorilerini Goster ve Urun Sec\n2. Siparis Takip\n3. Sikayet ve Oneri Olustur\n4. Sifre Degistir\n5. Sepeti Goruntule\n6. Geri Don\n";
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
        sepetiGoruntule();
        break;
    case 6:
        anaMenu();
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
        elbiseGoster();
        break;
    case 2:
        tisortGoster();
        break;
    case 3:
        pantolonGoster();
        break;
    case 4:
        gomlekGoster();
        break;
    case 5:
        etekGoster();
        break;
    case 6:
        ayakkabiGoster();
        break;
    default:
        break;
    }
};
void Kullanici::elbiseGoster() {
    temizle();
    cin.ignore();
    geciciSepet.clear();
    string satir;
    vector<string> elbiseler;
    ifstream elbiseTXT;
    elbiseTXT.open("elbise.txt");
    while (getline(elbiseTXT, satir)) elbiseler.push_back(satir);

    int menuNum;
    int a = 1;
    int tercih;
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
                string kategori = elbiseler[i - 1];
                string kiyafetAdi = elbiseler[i];
                string renk = elbiseler[i + 2];
                string beden = elbiseler[i + 1];
                double fiyat = stod(elbiseler[i + 3]);

                Kiyafet kiyafetim(kategori,kiyafetAdi,beden,renk,fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + elbiseler[i + 2] + " " + elbiseler[i] + " " +  elbiseler[i - 1] + "\nBeden: " + elbiseler[i + 1] + "\nFiyat: " + elbiseler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih-1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;

    case 2:
        for (int i = 0; i < elbiseler.size(); i++)
        {
            if (elbiseler[i] == "Drapeli") {
                string b = to_string(a);
                string kategori = elbiseler[i - 1];
                string kiyafetAdi = elbiseler[i];
                string renk = elbiseler[i + 2];
                string beden = elbiseler[i + 1];
                double fiyat = stod(elbiseler[i + 3]);

                Kiyafet kiyafetim(kategori,kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + elbiseler[i + 2] + " " + elbiseler[i] + " " + elbiseler[i - 1] + "\nBeden: " + elbiseler[i + 1] + "\nFiyat: " + elbiseler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    case 3:
        for (int i = 0; i < elbiseler.size(); i++)
        {

            if (elbiseler[i] == "Straplez") {

                string b = to_string(a);
                string kategori = elbiseler[i - 1];
                string kiyafetAdi = elbiseler[i];
                string renk = elbiseler[i + 2];
                string beden = elbiseler[i + 1];
                double fiyat = stod(elbiseler[i + 3]);

                Kiyafet kiyafetim(kategori,kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + elbiseler[i + 2] + " " + elbiseler[i] + " " + elbiseler[i - 1] + "\nBeden: " + elbiseler[i + 1] + "\nFiyat: " + elbiseler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    default:
        break;
    }
}
void Kullanici::tisortGoster() {
    temizle();
    cin.ignore();
    geciciSepet.clear();
    string satir;
    vector<string> tisortler;
    ifstream tisortTXT;
    tisortTXT.open("tisort.txt");
    while (getline(tisortTXT, satir)) tisortler.push_back(satir);

    int menuNum;
    int a = 1;
    int tercih;
    cout << "1.V Yaka Tisort\n2.Bisiklet Yaka Tisort\n3.Polo Yaka Tisort" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        temizle();
        for (int i = 0; i < tisortler.size(); i++)
        {
            if (tisortler[i] == "VYaka") {
                string b = to_string(a);
                string kategori = tisortler[i - 1];
                string kiyafetAdi = tisortler[i];
                string renk = tisortler[i + 2];
                string beden = tisortler[i + 1];
                double fiyat = stod(tisortler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + tisortler[i + 2] + " " + tisortler[i] + " " + tisortler[i - 1] + "\nBeden: " + tisortler[i + 1] + "\nFiyat: " + tisortler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;

    case 2:
        for (int i = 0; i < tisortler.size(); i++)
        {
            if (tisortler[i] == "BisikletYaka") {
                string b = to_string(a);
                string kategori = tisortler[i - 1];
                string kiyafetAdi = tisortler[i];
                string renk = tisortler[i + 2];
                string beden = tisortler[i + 1];
                double fiyat = stod(tisortler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + tisortler[i + 2] + " " + tisortler[i] + " " + tisortler[i - 1] + "\nBeden: " + tisortler[i + 1] + "\nFiyat: " + tisortler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    case 3:
        for (int i = 0; i < tisortler.size(); i++)
        {

            if (tisortler[i] == "PoloYaka") {

                string b = to_string(a);
                string kategori = tisortler[i - 1];
                string kiyafetAdi = tisortler[i];
                string renk = tisortler[i + 2];
                string beden = tisortler[i + 1];
                double fiyat = stod(tisortler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + tisortler[i + 2] + " " + tisortler[i] + " " + tisortler[i - 1] + "\nBeden: " + tisortler[i + 1] + "\nFiyat: " + tisortler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    default:
        break;
    }
};
void Kullanici::pantolonGoster() {
    temizle();
    cin.ignore();
    geciciSepet.clear();
    string satir;
    vector<string> pantolonlar;
    ifstream pantolonTXT;
    pantolonTXT.open("pantolon.txt");
    while (getline(pantolonTXT, satir)) pantolonlar.push_back(satir);

    int menuNum;
    int a = 1;
    int tercih;
    cout << "1.Dar Paca Pantolon\n2.Ispanyol Paca Pantolon\n3.Boru Paca Pantolon" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        temizle();
        for (int i = 0; i < pantolonlar.size(); i++)
        {
            if (pantolonlar[i] == "DarPaca") {
                string b = to_string(a);
                string kategori = pantolonlar[i - 1];
                string kiyafetAdi = pantolonlar[i];
                string renk = pantolonlar[i + 2];
                string beden = pantolonlar[i + 1];
                double fiyat = stod(pantolonlar[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + pantolonlar[i + 2] + " " + pantolonlar[i] + " " + pantolonlar[i - 1] + "\nBeden: " + pantolonlar[i + 1] + "\nFiyat: " + pantolonlar[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;

    case 2:
        for (int i = 0; i < pantolonlar.size(); i++)
        {
            if (pantolonlar[i] == "IspanyolPaca") {
                string b = to_string(a);
                string kategori = pantolonlar[i - 1];
                string kiyafetAdi = pantolonlar[i];
                string renk = pantolonlar[i + 2];
                string beden = pantolonlar[i + 1];
                double fiyat = stod(pantolonlar[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + pantolonlar[i + 2] + " " + pantolonlar[i] + " " + pantolonlar[i - 1] + "\nBeden: " + pantolonlar[i + 1] + "\nFiyat: " + pantolonlar[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    case 3:
        for (int i = 0; i < pantolonlar.size(); i++)
        {

            if (pantolonlar[i] == "BoruPaca") {

                string b = to_string(a);
                string kategori = pantolonlar[i - 1];
                string kiyafetAdi = pantolonlar[i];
                string renk = pantolonlar[i + 2];
                string beden = pantolonlar[i + 1];
                double fiyat = stod(pantolonlar[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + pantolonlar[i + 2] + " " + pantolonlar[i] + " " + pantolonlar[i - 1] + "\nBeden: " + pantolonlar[i + 1] + "\nFiyat: " + pantolonlar[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    default:
        break;
    }
};
void Kullanici::gomlekGoster() {
    temizle();
    cin.ignore();
    geciciSepet.clear();
    string satir;
    vector<string> gomlekler;
    ifstream gomlekTXT;
    gomlekTXT.open("gomlek.txt");
    while (getline(gomlekTXT, satir)) gomlekler.push_back(satir);

    int menuNum;
    int a = 1;
    int tercih;
    cout << "1.Oduncu Gomlek\n2.Keten Gomlek\n3.Cizgili Gomlek" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        temizle();
        for (int i = 0; i < gomlekler.size(); i++)
        {
            if (gomlekler[i] == "Oduncu") {
                string b = to_string(a);
                string kategori = gomlekler[i - 1];
                string kiyafetAdi = gomlekler[i];
                string renk = gomlekler[i + 2];
                string beden = gomlekler[i + 1];
                double fiyat = stod(gomlekler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + gomlekler[i + 2] + " " + gomlekler[i] + " " + gomlekler[i - 1] + "\nBeden: " + gomlekler[i + 1] + "\nFiyat: " + gomlekler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;

    case 2:
        for (int i = 0; i < gomlekler.size(); i++)
        {
            if (gomlekler[i] == "Keten") {
                string b = to_string(a);
                string kategori = gomlekler[i - 1];
                string kiyafetAdi = gomlekler[i];
                string renk = gomlekler[i + 2];
                string beden = gomlekler[i + 1];
                double fiyat = stod(gomlekler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + gomlekler[i + 2] + " " + gomlekler[i] + " " + gomlekler[i - 1] + "\nBeden: " + gomlekler[i + 1] + "\nFiyat: " + gomlekler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    case 3:
        for (int i = 0; i < gomlekler.size(); i++)
        {

            if (gomlekler[i] == "Cizgili") {

                string b = to_string(a);
                string kategori = gomlekler[i - 1];
                string kiyafetAdi = gomlekler[i];
                string renk = gomlekler[i + 2];
                string beden = gomlekler[i + 1];
                double fiyat = stod(gomlekler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + gomlekler[i + 2] + " " + gomlekler[i] + " " + gomlekler[i - 1] + "\nBeden: " + gomlekler[i + 1] + "\nFiyat: " + gomlekler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    default:
        break;
    }
};
void Kullanici::etekGoster() {
    temizle();
    cin.ignore();
    geciciSepet.clear();
    string satir;
    vector<string> etekler;
    ifstream etekTXT;
    etekTXT.open("etek.txt");
    while (getline(etekTXT, satir)) etekler.push_back(satir);

    int menuNum;
    int a = 1;
    int tercih;
    cout << "1.Uzun Etek\n2.Kisa Etek\n3.Kalem Etek" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        temizle();
        for (int i = 0; i < etekler.size(); i++)
        {
            if (etekler[i] == "Uzun") {
                string b = to_string(a);
                string kategori = etekler[i - 1];
                string kiyafetAdi = etekler[i];
                string renk = etekler[i + 2];
                string beden = etekler[i + 1];
                double fiyat = stod(etekler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + etekler[i + 2] + " " + etekler[i] + " " + etekler[i - 1] + "\nBeden: " + etekler[i + 1] + "\nFiyat: " + etekler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;

    case 2:
        for (int i = 0; i < etekler.size(); i++)
        {
            if (etekler[i] == "Kisa") {
                string b = to_string(a);
                string kategori = etekler[i - 1];
                string kiyafetAdi = etekler[i];
                string renk = etekler[i + 2];
                string beden = etekler[i + 1];
                double fiyat = stod(etekler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + etekler[i + 2] + " " + etekler[i] + " " + etekler[i - 1] + "\nBeden: " + etekler[i + 1] + "\nFiyat: " + etekler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    case 3:
        for (int i = 0; i < etekler.size(); i++)
        {

            if (etekler[i] == "Kalem") {

                string b = to_string(a);
                string kategori = etekler[i - 1];
                string kiyafetAdi = etekler[i];
                string renk = etekler[i + 2];
                string beden = etekler[i + 1];
                double fiyat = stod(etekler[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + etekler[i + 2] + " " + etekler[i] + " " + etekler[i - 1] + "\nBeden: " + etekler[i + 1] + "\nFiyat: " + etekler[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    default:
        break;
    }
};
void Kullanici::ayakkabiGoster() {
    temizle();
    cin.ignore();
    geciciSepet.clear();
    string satir;
    vector<string> ayakkabilar;
    ifstream ayakkabiTXT;
    ayakkabiTXT.open("ayakkabi.txt");
    while (getline(ayakkabiTXT, satir)) ayakkabilar.push_back(satir);

    int menuNum;
    int a = 1;
    int tercih;
    cout << "1.Spor Ayakkabi\n2.Topuklu Ayakkabi\n3.Babet Ayakkabi" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:
        temizle();
        for (int i = 0; i < ayakkabilar.size(); i++)
        {
            if (ayakkabilar[i] == "Spor") {
                string b = to_string(a);
                string kategori = ayakkabilar[i - 1];
                string kiyafetAdi = ayakkabilar[i];
                string renk = ayakkabilar[i + 2];
                string beden = ayakkabilar[i + 1];
                double fiyat = stod(ayakkabilar[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + ayakkabilar[i + 2] + " " + ayakkabilar[i] + " " + ayakkabilar[i - 1] + "\nBeden: " + ayakkabilar[i + 1] + "\nFiyat: " + ayakkabilar[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;

    case 2:
        for (int i = 0; i < ayakkabilar.size(); i++)
        {
            if (ayakkabilar[i] == "Topuklu") {
                string b = to_string(a);
                string kategori = ayakkabilar[i - 1];
                string kiyafetAdi = ayakkabilar[i];
                string renk = ayakkabilar[i + 2];
                string beden = ayakkabilar[i + 1];
                double fiyat = stod(ayakkabilar[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + ayakkabilar[i + 2] + " " + ayakkabilar[i] + " " + ayakkabilar[i - 1] + "\nBeden: " + ayakkabilar[i + 1] + "\nFiyat: " + ayakkabilar[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    case 3:
        for (int i = 0; i < ayakkabilar.size(); i++)
        {

            if (ayakkabilar[i] == "Babet") {

                string b = to_string(a);
                string kategori = ayakkabilar[i - 1];
                string kiyafetAdi = ayakkabilar[i];
                string renk = ayakkabilar[i + 2];
                string beden = ayakkabilar[i + 1];
                double fiyat = stod(ayakkabilar[i + 3]);

                Kiyafet kiyafetim(kategori, kiyafetAdi, beden, renk, fiyat);
                geciciSepet.push_back(kiyafetim);
                cout << b + "." + ayakkabilar[i + 2] + " " + ayakkabilar[i] + " " + ayakkabilar[i - 1] + "\nBeden: " + ayakkabilar[i + 1] + "\nFiyat: " + ayakkabilar[i + 3] << endl;
                a++;
            }
        }
        cout << "Lutfen tercihinizi giriniz: \n";
        cin >> tercih;
        sepet.push_back(geciciSepet[tercih - 1]);
        cout << "Urun sepete eklendi.";
        kullaniciMenu();
        break;
    default:
        break;
    }
};

void Kullanici::sepetiGoruntule() {
    int a = 1;
    int menuNum;
    for (int i = 0; i < sepet.size(); i++) {
        string b = to_string(a);
        string fiyat = to_string(sepet[i].fiyat);
        cout << b + "." + sepet[i].renk + " " + sepet[i].kiyafetAdi + " " + sepet[i].kategori + "\nBeden: " + sepet[i].beden + "\nFiyat: " + fiyat << endl;
        a++;
    }
    cout << "\n\n1. Sepeti onayla\n2. Sepeti temizle" << endl;
    cin >> menuNum;
    switch (menuNum)
    {
    case 1:

        break;
    case 2:
        sepet.clear();
        kullanicim.kullaniciMenu();
        break;
    default:
        break;
    }
}
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