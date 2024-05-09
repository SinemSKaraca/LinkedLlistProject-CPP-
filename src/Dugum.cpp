/**
* @file         Dugum.cpp
* @description  Yeni dugum olusturulur.
* @course       1(A)
* @assignment   1. Odev
* @date         21/07/2023
* @author       Sinem Saziye Karaca, saziye.karaca@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(int veri) {
	this->veri = veri;
	this->sonraki = NULL;
}