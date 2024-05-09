/**
* @file         BagliListe.cpp
* @description  Dugum sinifi kullanilarak olusturulan dugumlerle bagli liste olusturulur.
*               Olusturulan bagli listeler uzerinde cesitli islemler yapilir.
* @course       1(A)
* @assignment   1. Odev
* @date         21/07/2023
* @author       Sinem Saziye Karaca, saziye.karaca@ogr.sakarya.edu.tr
*/

#include "BagliListe.hpp"
#include <iostream>
using namespace std;

BagliListe::BagliListe() {
	listeBasi = NULL;
}

void BagliListe::sonaEkle(const int& yeniVeri) {
	Dugum* yeniDugum = new Dugum(yeniVeri);
	// Bos listeye ilk elemani ekleme
	if(listeBasi == NULL) {
		listeBasi = yeniDugum;
	}
	// Bos olmayan listeye yeni eleman ekleme
	else {
		Dugum* gecici = listeBasi;
		// Son turunda gecici son elemani gösteriyor
		while(gecici->sonraki != 0) {
			gecici = gecici->sonraki; // i++ mantıgıyla calisiyor
		}
		gecici->sonraki = yeniDugum;
	}
}

int BagliListe::veriGetir(int konum) {
	Dugum* gecici = listeBasi;
	int indis = 0;
	while(gecici != 0) {
		if(konum == indis) return gecici->veri;
		indis++;
		gecici = gecici->sonraki;
	}
	return -1;
}

int BagliListe::listeElemanSayisi() {
	Dugum* gecici = listeBasi;
	this->elemanSayisi = 0;
	while(gecici != 0) {
		elemanSayisi++;
		gecici = gecici->sonraki;
	}
	return elemanSayisi;
}

//void BagliListe::listeYazdir() {
//	Dugum* gecici = listeBasi;
//	while(gecici != 0) {
//		cout << gecici->veri << endl;
//		gecici = gecici->sonraki;
//	}
//}

// Silme istemi liste basindan sonuna dogru yapilir
BagliListe::~BagliListe() { 
	//cout << "Liste yikicisi calisti" << endl;
	Dugum* gecici = listeBasi;
	while(gecici != 0) {
		Dugum* silinecek = gecici;
		gecici = gecici->sonraki;
		delete silinecek;
	}
}