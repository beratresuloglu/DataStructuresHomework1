/*
 * @file          Kromozom.cpp
 * @description   Bu dosya gen düğümlerinin tutulduğu kromozom bağlı liste sınıfının bulunduğu dosyadır. Kromozom bağlı liste sınıfının metodları bulunur.
 * @course        1.Öğretim, B Grubu
 * @assignment    1.Ödev
 * @date          26 Kasım 2024
 * @author        Berat Resuloğlu (berat.resuloglu@ogr.sakarya.edu.tr)
 */
#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "Gen.hpp"
#include <iostream>
class Kromozom
{
private:
    Gen *ilkGen;
    Kromozom *sonrakiKromozom;
    int satirIndex;
    int dugumSayisi;

public:
    Kromozom();
    ~Kromozom();
    Gen *getIlkGen() const;
    Kromozom *getSonrakiKromozom();
    int getSatirIndex();
    void setSatirIndex(int s);
    int getDugumSayisi();
    void setDugumSayisi(int deger);
    void setSonrakiKromozom(Kromozom *yeni);
    void yazdir() const;
    void genEkle(char v);
    Gen *genGetir(int index);
};
#endif