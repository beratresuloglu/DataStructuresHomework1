/*
* @file          Gen.cpp
* @description   Bu dosya kromozom bağlı liste sınıfının düğümlerini oluşturan gen sınıfını bulundurur. İçerisinde gen sınıfının kurucu metodu bulunur.
* @course        1.Öğretim, B Grubu
* @assignment    1.Ödev
* @date          26 Kasım 2024
* @author        Berat Resuloğlu (berat.resuloglu@ogr.sakarya.edu.tr)
*/
#include <iostream>
#include "Gen.hpp"
using namespace std;
Gen::Gen(char v)
{
    sutun = 0;
    veri = v;
    sonraki = nullptr;
};