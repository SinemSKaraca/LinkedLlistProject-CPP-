/**
* @file         Test.cpp
* @description  Kullanıcıdan alınan konum bilgilerine gore liste degisimi yapilir.
*               Parametre olarak girilen ust(onlar b.) ve alt(birler b.) bilgisine bagli olarak..
*               ..onlar ve birler basamagi listelerinin ortalamalari hesaplanir.
* @course       1(A)
* @assignment   1. Odev
* @date         20/07/2023
* @author       Sinem Saziye Karaca, saziye.karaca@ogr.sakarya.edu.tr
*/

#include "DosyaOku.hpp"
#include "Dugum.hpp"
#include <iostream>
using namespace std;

int main() {
	DosyaOku* d = new DosyaOku();
	
	// Gecersiz konum bilgisi girilirse uyari gonderilir ve program sonlanir.
	try {
		int konumA, konumB;
		cout << "Konum A: ";
		cin >> konumA;
		cout << "Konum B: ";
		cin >> konumB;
		d->ustAltListeDegistir(konumA, konumB);
		char ust = 'u';
		char alt = 'a';
		cout << "Ust: " << d->ortalama(ust) << endl;
		cout << "Alt: " << d->ortalama(alt) << endl;
	}
	catch(const char* uyari) {
		cout << uyari << endl;
		cout << "Konum Bilgisi 0 - " << d->satirSayisiBul() - 1 << " Araliginda Olmalidir!" << endl;
	}
	
	delete d;
	return 0;
}