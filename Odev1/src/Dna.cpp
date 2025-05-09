/*
 * @file          Dna.cpp
 * @description   Bu dosya Dna.txt isimli belgeden okunan satırların bir arada tutulduğu, kromozom tipinden düğümleri olan, Dna bağlı liste sınıfını bulundurur.
 * @course        1.Öğretim, B Grubu
 * @assignment    1.Ödev
 * @date          26 Kasım 2024
 * @author        Berat Resuloğlu (berat.resuloglu@ogr.sakarya.edu.tr)
 */
#include <iostream>
#include "Dna.hpp"
using namespace std;

Dna::Dna()
{
    ilkKromozom = nullptr;
    sonrakiKromozom = nullptr;
    kromozomSayisi = 0;
}

Dna::~Dna()
{
    Kromozom *gecici = ilkKromozom;
    while (gecici)
    {
        Kromozom *silinecek = gecici;
        gecici = gecici->getSonrakiKromozom();
        delete silinecek;
    }
}

void Dna::kromozomEkle(Kromozom *kromozom)
{
    if (!ilkKromozom)
    {
        ilkKromozom = kromozom;
        sonKromozom = kromozom; 
    }
    else
    {
        sonKromozom->setSonrakiKromozom(kromozom);
        sonKromozom = kromozom; 
    }
    kromozomSayisi++;
}

void Dna::ekranaYaz() const
{
    Kromozom *gecici = ilkKromozom;
    while (gecici)
    {
        char yazilacakGen = gecici->genGetir(0)->veri;          
        for (int i = gecici->getDugumSayisi() - 1; i >= 0; --i) 
        {
            if (gecici->genGetir(i)->veri < yazilacakGen) 
            {
                yazilacakGen = gecici->genGetir(i)->veri;
                break; 
            }
        }

        cout << yazilacakGen << " ";

        gecici = gecici->getSonrakiKromozom();
    }
    cout << endl;
}

Kromozom *Dna::getIlkKromozom() const
{
    return ilkKromozom;
}

Kromozom *Dna::kromozomGetir(int index)
{
    int sayac = 0;
    Kromozom *gecici = ilkKromozom;
    while (gecici != nullptr)
    {
        if (sayac == index)
            return gecici;

        gecici = gecici->getSonrakiKromozom();
        sayac++;
    }
    return 0;
}

int Dna::getKromozomSayisi()
{
    return kromozomSayisi;
}

int Dna::setKromozomSayisi(int deger)
{
    kromozomSayisi = deger;
}
