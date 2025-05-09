/*
 * @file          Dna.cpp
 * @description   Bu dosya Dna.txt isimli belgeden okunan satırların bir arada tutulduğu, kromozom tipinden düğümleri olan, Dna bağlı liste sınıfını bulundurur.
 * @course        1.Öğretim, B Grubu
 * @assignment    1.Ödev
 * @date          26 Kasım 2024
 * @author        Berat Resuloğlu (berat.resuloglu@ogr.sakarya.edu.tr)
 */
#ifndef DNA_HPP
#define DNA_HPP
#include <Gen.hpp>
#include <Kromozom.hpp>
#include <iostream>
class Dna
{
private:
    Kromozom *ilkKromozom;
    Kromozom *sonKromozom;
    Kromozom *sonrakiKromozom;
    int kromozomSayisi;

public:
    Dna();
    ~Dna();
    void kromozomEkle(Kromozom *kromozom);
    void ekranaYaz() const;
    Kromozom *getIlkKromozom() const;
    Kromozom *kromozomGetir(int index);
    int getKromozomSayisi();
    int setKromozomSayisi(int v);
};
#endif