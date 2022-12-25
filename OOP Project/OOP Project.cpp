//KUTAY SARAÇ 402503
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
class Siparis {
public:
    int siparisNo;
    double siparisFiyat;
    Zaman siparisBaslangic;
    Zaman siparisUlasim;
    string siparisOzet;
    string siparisAdres;
    string siparisSahibi;
    Siparis(string siparisSahibi, double siparisFiyat, string siparisOzet, string siparisAdres) {
        this->siparisSahibi = siparisSahibi;
        this->siparisFiyat = siparisFiyat;
        this->siparisOzet = siparisOzet;
        this->siparisAdres = siparisAdres;
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
    string ePosta;
    string adresIlce;
    string sifre;
    string indirimKodu;
    char* dtarihi;
    Kullanici();
    Kullanici(string kullanici_adi, string sifre, string adres) {
        this->kullanici_adi = kullanici_adi;
        this->sifre = sifre;
        this->adresIlce = adres;
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
#pragma endregion

Kullanici kullanicim("", "", "");
Yonetici yoneticim("");
vector<Kiyafet> sepet;
vector<Kiyafet> geciciSepet;
vector<Siparis> faturalar;

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
    cout << "1. Elbise Ekle\n2. Tisort Ekle\n3. Pantolon Ekle\n4. Gomlek Ekle\n5. Etek Ekle\n6. Ayakkabi Ekle\n7. Geri Don";
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
    case 7:
        yoneticim.yoneticiMenu();
        break;
    default:
        yoneticim.urunGirisi();
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
        cout << "Geri gelmek icin lutfen 9'a basiniz.";
        cin.ignore();
        cin >> menuNum;
        if (menuNum == 9) {
            gecis = false;
            yoneticim.yoneticiMenu();
        }
    }

};
void Yonetici::kuryeAta() {};
void Yonetici::indirimKoduTanimla() {
    temizle();
    string indirimKodu;
    int indirimMiktari;
    string indirimSahibi;
    cout << "Indirim kodunu belirleyiniz: ";
    cin >> indirimKodu;
    cout << "\nIndirim miktarini belirleyiniz:";
    cin >> indirimMiktari;
    cout << "\nIndirimi tanimlamak istediginiz kullanicinin adi: ";
    cin >> indirimSahibi;

    ofstream indirimTXT;
    indirimTXT.open("indirim.txt", ios_base::app);
    indirimTXT << indirimKodu << endl;
    indirimTXT << indirimMiktari << endl;
    indirimTXT << indirimSahibi << endl;
    yoneticiMenu();
};
void Yonetici::faturaGoster() {
    temizle();
    int a = 1;
    if (faturalar.size() > 0) {
        for (int i = 0; i < faturalar.size(); i++)
        {
            string b = to_string(a);
            string fiyat = to_string(faturalar[i].siparisFiyat);
            cout << "Siparis sahibi: " + faturalar[i].siparisSahibi << endl;
            cout << faturalar[i].siparisOzet;
            cout << "Toplam fiyat: ";
            cout << faturalar[i].siparisFiyat << endl;
            cout << faturalar[i].siparisAdres << endl;
        }
    }
};
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
    cout << "1. Elbiseler\n2. Tisortler\n3. Pantolonlar\n4. Gomlekler\n5. Etekler\n6. Ayakkabilar\n";
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
        temizle();
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
    int toplamFiyat = 0;
    string adres;
    string ozet;

    string satir;
    vector<string> indirimler;
    ifstream indirimTXT;
    indirimTXT.open("indirim.txt");
    while (getline(indirimTXT, satir)) indirimler.push_back(satir);

    if (sepet.size() > 0) {
        for (int i = 0; i < sepet.size(); i++) {
            string b = to_string(a);
            string fiyat = to_string(sepet[i].fiyat);
            cout << b + "." + sepet[i].renk + " " + sepet[i].kiyafetAdi + " " + sepet[i].kategori + "\nBeden: " + sepet[i].beden + "\nFiyat: " + fiyat + "\n";
            a++;
            ozet = ozet + b + "." + sepet[i].renk + " " + sepet[i].kiyafetAdi + " " + sepet[i].kategori + "\nBeden: " + sepet[i].beden + "\nFiyat: " + fiyat + "\n";
            toplamFiyat = sepet[i].fiyat + toplamFiyat;
        }
        cout << "Toplam sepet tutari: ";
        cout << toplamFiyat;

        cout << "\n\n1. Sepeti onayla\n2. Sepeti temizle" << endl;
        cin >> menuNum;

        if (menuNum == 1) {
            temizle();
            int k;
            string indirimKuponu;
            cout << "1. Indirim kuponu girin\n2. Kupon olmadan devam edin\n";
            cin >> k;
            if (k == 1) {
                    cout << "Indirim kuponunu giriniz: ";
                    cin >> indirimKuponu;
                    for (int i = 0; i < indirimler.size(); i++)
                    {
                        if (indirimler[i] == indirimKuponu && indirimler[i + 2] == kullanicim.kullanici_adi) {
                            int indirim;
                            indirim = stoi(indirimler[i + 1]);
                            toplamFiyat = toplamFiyat - (toplamFiyat * indirim / 100);
                            Siparis siparisim(kullanicim.kullanici_adi, toplamFiyat, ozet, kullanicim.adresIlce);
                            faturalar.push_back(siparisim);
                            sepet.clear();
                            kullaniciMenu();
                        }
                    }
            }
            else {
                    Siparis siparisim(kullanicim.kullanici_adi, toplamFiyat, ozet, kullanicim.adresIlce);
                    faturalar.push_back(siparisim);
                    sepet.clear();
                    kullaniciMenu();
                }

            if (menuNum == 2) {
                sepet.clear();
                kullaniciMenu();
            }

        }
        else {
            int menuNum;
            cout << "Sepetiniz bos, geri gelmek icin lütfen 9'a basiniz:";
            cin >> menuNum;
            switch (menuNum)
            {
            case 9:
                kullaniciMenu();
                break;
            default:
                sepetiGoruntule();
                break;
            }
        }

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
    kontrol = kullanicim.kullanici_adi + kullanicim.sifre;
    vector<string> kullanicilar;

    ifstream kullanicilarTXTokuma;
    kullanicilarTXTokuma.open("kullanıcılar.txt");
    while (getline(kullanicilarTXTokuma, satir)) kullanicilar.push_back(satir);
    kullanicilarTXTokuma.close();

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        if (kontrol == kullanicilar[i]) {
            kullanicim.sifre == yeniSifre;
            kullanicilar[i] = kullanicim.kullanici_adi + yeniSifre;
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
    string kontrol = "asdfgh";
    string satir;
    
    temizle();

    cout << "Sifre: ";
    cin >> sifre;
    if (sifre == kontrol) {
        yoneticim.yoneticiMenu();
    }
    else {
        cout << "Tekrar deneyin.";
        yoneticiGirisMenu();
    }

    
}
void kullaniciGirisMenu() {
    string kullaniciAdi;
    string sifre;
    string kontrol;
    string satir;
    string objeAdi;
    string adres;
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
    kontrol = kullaniciAdi + sifre;

    ifstream kullanicilarTXT;
    kullanicilarTXT.open("kullanıcılar.txt");
    while (getline(kullanicilarTXT, satir)) kullanicilar.push_back(satir);

    for (int i = 0; i < kullanicilar.size(); i++)
    {
        if (kontrol == kullanicilar[i]) {
            adres = kullanicilar[i + 4];
            Kullanici kontrol(kullaniciAdi, sifre, adres);
            kullanicim = kontrol;
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
    string adres;
    string dogumTarihi;
    int menuNo;
    regex patternemail("^[a-zA-Z0-9][a-zA-Z0-9._]*@[a-zA-Z0-9]+([.][a-zA-Z]+)+$");
    regex patternDogumTarihi("^(0[1-9]|1[0-9]|2[0-9]|3[0,1])([/+-])(0[1-9]|1[0-2])([/+-])(19|20)[0-9]{2}$");
    bool gecis = true;
    temizle();

    cout << "Kullanici Adi: ";
    cin >> kullaniciAdi;

    cout << "\nSifre(Sifre 1 kucuk karakter, 1 buyuk karakter, 1 rakam, 1 ozel karakter icermek zorundadir): ";
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
    cout << "\n\nAdres: ";
    cin >> adres;

    bool rakam = false, ozelKarakter = false;
    bool kucukKarakter = false, buyukKarakter = false;
    string karakterler = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    for (int i = 0; i < sifre.length(); i++) {
        if (islower(sifre[i]))
            kucukKarakter = true;
        if (isupper(sifre[i]))
            buyukKarakter = true;
        if (isdigit(sifre[i]))
            rakam = true;

        size_t ozel = sifre.find_first_not_of(karakterler);
        if (ozel != string::npos)
            ozelKarakter = true;
    }

    cin.ignore();
    cout << "\nE-Mail: ";
    getline(cin, eMail);

    cout << "\nDogum Tarihi(gg-aa-yy): ";
    getline(cin, dogumTarihi);
    if (kucukKarakter && buyukKarakter && rakam && ozelKarakter) {
        if (regex_search(dogumTarihi, patternDogumTarihi)) {
            if (regex_search(eMail, patternemail))
            {
                ofstream kullanicilarTXT;
                kullanicilarTXT.open("kullanıcılar.TXT", ios_base::app);
                kullanicilarTXT << kullaniciAdi + sifre << endl;
                kullanicilarTXT << kullaniciAdi << endl;
                kullanicilarTXT << sifre << endl;
                kullanicilarTXT << eMail << endl;
                kullanicilarTXT << adres << endl;
                kullanicilarTXT.close();
            }
            else {
                cout << "Lutfen gecerli bir email adresi giriniz." << endl;
                kullaniciUyeKayit();
            }
        }
        else {
            cout << "Dogum tarihinizi gecersiz sekilde girdiniz, lutfen tekrar deneyin." << endl;
            kullaniciUyeKayit();
        }
    }
    else {
        cout << "Zayif sifre girdiniz." << endl;
        kullaniciUyeKayit();
    }
    

    while (gecis) {
        cout << "\nBasariyla kaydoldunuz. Geri gelmek icin lutfen 9'a basiniz.\n";
        cin >> menuNo;
        if (menuNo == 9) {
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