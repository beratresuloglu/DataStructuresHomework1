/*
 * @file          Kromozom.cpp
 * @description   Bu dosya gen düğümlerinin tutulduğu kromozom bağlı liste sınıfının bulunduğu dosyadır. Kromozom bağlı liste sınıfının metodları bulunur.
 * @course        1.Öğretim, B Grubu
 * @assignment    1.Ödev
 * @date          26 Kasım 2024
 * @author        Berat Resuloğlu (berat.resuloglu@ogr.sakarya.edu.tr)
 */
#include <iostream>
#include "Kromozom.hpp"
#include "Gen.hpp"
using namespace std;
Kromozom::Kromozom()
{
    ilkGen = nullptr;
    sonrakiKromozom = nullptr;
    dugumSayisi = 0;
    satirIndex = 0;
};

Kromozom::~Kromozom()
{
    Gen *gecici = ilkGen;
    while (gecici)
    {
        Gen *silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
    ilkGen = nullptr;
    dugumSayisi = 0;
}

Gen *Kromozom::getIlkGen() const
{
    return ilkGen;
}

Kromozom *Kromozom::getSonrakiKromozom()
{
    return sonrakiKromozom;
}


int Kromozom::getSatirIndex()
{
    return satirIndex;
}

void Kromozom::setSatirIndex(int s)
{
    satirIndex = s;
}

int Kromozom::getDugumSayisi()
{
    return dugumSayisi;
}

void Kromozom::setDugumSayisi(int deger)
{
    dugumSayisi = deger;
}

void Kromozom::setSonrakiKromozom(Kromozom *yeni)
{
    sonrakiKromozom = yeni;
}

void Kromozom::yazdir() const
{
    Gen *gecici = ilkGen;
    while (gecici)
    {
        cout << gecici->veri << " ";
        gecici = gecici->sonraki;
    }
    cout << endl;
}

void Kromozom::genEkle(char v)
{

    Gen *yeniGen = new Gen(v);
    if (!ilkGen)
    {
        ilkGen = yeniGen;
    }
    else
    {
        Gen *gecici = ilkGen;
        while (gecici->sonraki)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniGen;
    }
    dugumSayisi++;
}

Gen *Kromozom::genGetir(int index)
{
    int sayac = 0;
    Gen *gecici = ilkGen;
    while (gecici != 0)
    {
        if (sayac == index)
            return gecici;

        gecici = gecici->sonraki;
        sayac++;
    }
    return 0;
}