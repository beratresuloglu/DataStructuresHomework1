/*
 * @file          Main.cpp
 * @description   Bu program DNA üzerinde çaprazlama ve mutasyon işlemleri gerçekleştirir. Ayrıca dosyadan DNA yapısını okuyarak otomatik işlemler yapar ve istenen formatta ekrana yazdırır.
 * @course        1.Öğretim, B Grubu
 * @assignment    1.Ödev
 * @date          26 Kasım 2024
 * @author        Berat Resuloğlu (berat.resuloglu@ogr.sakarya.edu.tr)
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Dna.hpp"
#include "Gen.hpp"
#include "Kromozom.hpp"
using namespace std;

void mutasyon(Dna &dna, int satir, int sutun)
{
    Kromozom *mutasyonluKromozom = new Kromozom();
    mutasyonluKromozom = dna.kromozomGetir(satir);
    Gen *mutasyonluGen = mutasyonluKromozom->genGetir(sutun);
    mutasyonluGen->veri = 'X';
    cout << "\nMutasyon islemi tamamlandi!\n"
         << endl;
}

void caprazlama(Dna &dna, int satir1, int satir2)
{
    Kromozom *birinciKromozom = dna.kromozomGetir(satir1);
    Kromozom *ikinciKromozom = dna.kromozomGetir(satir2);

    Kromozom *yeniKromozom1 = new Kromozom();
    Kromozom *yeniKromozom2 = new Kromozom();

    int birinciUzunluk = birinciKromozom->getDugumSayisi();
    int ikinciUzunluk = ikinciKromozom->getDugumSayisi();

    int birinciOrta = birinciUzunluk / 2;
    int ikinciOrta = ikinciUzunluk / 2;

    for (int i = 0; i < birinciOrta; i++)
    {
        char gen = birinciKromozom->genGetir(i)->veri;
        yeniKromozom1->genEkle(gen);
    }
    for (int i = ikinciOrta + (ikinciUzunluk % 2 == 0 ? 0 : 1); i < ikinciUzunluk; i++)
    {
        char gen = ikinciKromozom->genGetir(i)->veri;
        yeniKromozom1->genEkle(gen);
    }

    for (int i = birinciOrta + (birinciUzunluk % 2 == 0 ? 0 : 1); i < birinciUzunluk; i++)
    {
        char gen = birinciKromozom->genGetir(i)->veri;
        yeniKromozom2->genEkle(gen);
    }
    for (int i = 0; i < ikinciOrta; i++)
    {
        char gen = ikinciKromozom->genGetir(i)->veri;
        yeniKromozom2->genEkle(gen);
    }

    dna.kromozomEkle(yeniKromozom1);
    dna.kromozomEkle(yeniKromozom2);

    cout << "\nCaprazlama islemi tamamlandi!\n"
         << endl;
}

void otomatikIslemler(Dna &dna)
{
    ifstream dosya("Islemler.txt");
    string satir;

    if (!dosya.is_open())
    {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    while (getline(dosya, satir))
    {
        stringstream ss(satir);
        char islemTipi;
        int deger1, deger2;

        if (!(ss >> islemTipi >> deger1 >> deger2))
        {
            cerr << "Hatali satir: " << satir << endl;
            continue;
        }

        if (islemTipi == 'C')
        {
            if (deger1 < 0 || deger1 >= dna.getKromozomSayisi() ||
                deger2 < 0 || deger2 >= dna.getKromozomSayisi())
            {
                cerr << "Geçersiz çaprazlama indeksleri: " << deger1 << ", " << deger2 << endl;
                continue;
            }
            caprazlama(dna, deger1, deger2);
        }
        else if (islemTipi == 'M')
        {
            if (deger1 < 0 || deger1 >= dna.getKromozomSayisi() ||
                deger2 < 0 || deger2 >= dna.kromozomGetir(deger1)->getDugumSayisi())
            {
                cerr << "Geçersiz mutasyon indeksleri: " << deger1 << ", " << deger2 << endl;
                continue;
            }
            mutasyon(dna, deger1, deger2);
        }
        else
        {
            cerr << "Bilinmeyen işlem tipi: " << islemTipi << endl;
        }
    }

    dosya.close();
    cout << "\nOtomatik islemler tamamlandi!\n"
         << endl;
}

int main()
{
    //*-----------------------DNA DOSYASININ OKUNMASI---------------------*/
    ifstream dosya("Dna.txt");
    if (!dosya.is_open())
    {
        cerr << "Dosya acilamadi!" << endl;
        return 1;
    }

    string satir;
    Dna dna;
    int sayac = 0;

    while (getline(dosya, satir))
    {
        Kromozom *kromozom = new Kromozom();

        for (char gen : satir)
        {
            if (gen != ' ')
            {
                kromozom->genEkle(gen);
            }
        }

        dna.kromozomEkle(kromozom);
        sayac++;
    }

    dosya.close();

    //*--------------------------MENU--------------------------------*/
    while (true)
    {
        cout << "1)Caprazlama" << endl;
        cout << "2)Mutasyon" << endl;
        cout << "3)Otomatik islemler" << endl;
        cout << "4)Ekrana yaz" << endl;
        cout << "5)Cikis" << endl;
        int secim;
        cin >> secim;
        if (secim == 1)
        {
            int satir1;
            int satir2;

            cout << "Caprazlanacak kromozom satirlarini girin." << endl;
            cout << "Satir 1: ";
            cin >> satir1;
            cout << "Satir 2: ";
            cin >> satir2;

            if (satir1 < 0 || satir1 >= dna.getKromozomSayisi())
            {
                cout << "Hata: Satir 1 (" << satir1 << ") gecersiz! Kromozom sayisi: " << dna.getKromozomSayisi() << endl;
            }
            else if (satir2 < 0 || satir2 >= dna.getKromozomSayisi())
            {
                cout << "Hata: Satir 2 (" << satir2 << ") gecersiz! Kromozom sayisi: " << dna.getKromozomSayisi() << endl;
            }
            else if (satir1 == satir2)
            {
                cout << "Hata: Ayni satirlar (" << satir1 << " ve " << satir2 << ") caprazlanamaz!" << endl;
            }
            else
            {
                caprazlama(dna, satir1, satir2);
            }
        }
        else if (secim == 2)
        {
            int satir;
            int sutun;

            cout << "Mutasyona ugrayacak kromozom indexini girin: ";
            cin >> satir;
            cout << "Mutasyona ugrayacak gen indexini girin: ";
            cin >> sutun;

            if (satir < 0 || satir >= dna.getKromozomSayisi())
            {
                cout << "Hata: Kromozom indeksi (" << satir << ") gecersiz! Kromozom sayisi: " << dna.getKromozomSayisi() << endl;
            }
            else if (sutun < 0 || sutun >= dna.kromozomGetir(satir)->getDugumSayisi())
            {
                cout << "Hata: Gen indeksi (" << sutun << ") gecersiz! Kromozomdaki gen sayisi: " << dna.kromozomGetir(satir)->getDugumSayisi() << endl;
            }
            else
            {
                mutasyon(dna, satir, sutun);
            }
        }
        else if (secim == 3)
        {
            otomatikIslemler(dna);
        }
        else if (secim == 4)
        {
            dna.ekranaYaz();
        }
        else if (secim == 5)
        {
            return 0;
        }
        else
        {
            cout << "Lutfen gecerli bir secim yapiniz!" << endl;
        }
    }
}