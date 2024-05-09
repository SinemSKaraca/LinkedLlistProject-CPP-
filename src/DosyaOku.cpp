/**
* @file          DosyaOku.cpp
* @description   Sayilar.txt dosyasini okuyarak heap bellek bolgesinde bagli listelerin..
*                ..ilk dugumlerinin adreslerini barindiran bir pointer dizisi olusturulur. Bu dizinin..
*                ..her indisinde bir satirin once onlar sonra birler basamagini veri olarak tutan..
*                ..tek yonlu bagli listeler bulunur. Programda, kullanicidan alinan konum bilgilerine gore..
*                ..onlar ve birler basamagi listelerinden birer tanesinin yerleri degistirilebilmektedir.
*                ..Ayrıca tum onlar ve birler basamaklarinin ortalamalari hesaplanabilmektedir.
* @course        1(A)
* @assignment    1. Odev
* @date          20/07/2023
* @author        Sinem Saziye Karaca, saziye.karaca@ogr.sakarya.edu.tr
*/

#include "DosyaOku.hpp"
#include "BagliListe.hpp"
#include "Dugum.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

DosyaOku::DosyaOku() {
	this->satirSayisi = satirSayisiBul();	
	this->satirlar = new BagliListe*[satirSayisi * 2];
	fstream dosya;
	dosya.open("Sayilar.txt", ios::in);
	if(dosya.is_open()) {
		string satir;	
		for(int i = 0; i < satirSayisi * 2; i++) {
			satirlar[i] = new BagliListe();
			//cout << satirlar[i] << endl;
		}	
		int index = 0;
		do {
			while(getline(dosya, satir)) {
				satir = bosluksuzString(satir);
				// Ust ve Alt Satirlari Tutan Dizi
				for(int i = index; i < index + 2; i++) {
					satirlar[i] = new BagliListe();
					if(i % 2 == 0) {
						//cout << "Onlar Basamagi" << endl;
						for(int j = 0; j < satir.length() - 1; j += 2) {
						//cout << satir[j] << endl;
						satirlar[i]->sonaEkle(satir[j] - 48);
						}
						//satirlar[i]->listeYazdir();
					}
					if(i % 2 == 1) {
						//cout << "Birler Basamagi" << endl;
						for(int j = 1; j < satir.length(); j += 2) {
							//cout << satir[j] << endl;
							satirlar[i]->sonaEkle(satir[j] - 48);
						}
						//satirlar[i]->listeYazdir();
					}
				}
				//cout << "----------------" <<endl;
				index += 2;
				break;	
			}
		} while(index < satirSayisi * 2);
	} 
	dosya.close();
}

string DosyaOku::bosluksuzString(string satir) {
	for(size_t i = 0; i < satir.length(); i++) {
		if(satir[i] == ' ') {
			satir.erase(i, 1);
			--i;
		}
	}
	return satir;
}

int DosyaOku::satirSayisiBul() {
	fstream dosya;
	dosya.open("Sayilar.txt", ios::in); // dosyadan oku
	
	int _satirSayisi = 0;
	if(dosya.is_open()) {
		string satir;
		while(getline(dosya, satir)) {
			_satirSayisi++;
		}
		dosya.close();
	}
	return _satirSayisi;
} 

void DosyaOku::ustAltListeDegistir(int _konumA, int _konumB) {
	if(_konumA < 0 || _konumA >= satirSayisi || _konumB < 0 || _konumB >= satirSayisi)
		throw "Lutfen Gecerli Konum Bilgisi Giriniz!";
	BagliListe* gecici;
	_konumA = _konumA * 2;
	_konumB = (_konumB * 2) + 1;
	gecici = satirlar[_konumA];
	satirlar[_konumA] = satirlar[_konumB];
	satirlar[_konumB] = gecici;
//	
//	for(int i = 0; i < satirSayisi * 2; i++) {
//		if(i % 2 == 0) {
//			cout << "Onlar Basamagi" << endl;
//			satirlar[i]->listeYazdir();
//		}
//		else {
//			cout << "Birler Basamagi" << endl;
//			satirlar[i]->listeYazdir();
//		}
//		cout << "-----------------" << endl;
//	}
}

double DosyaOku::ortalama(char tur) {
	if(tur == 'u') {
		double sonuc = 0.0f;
		for(int k = 0; k < maxElemanSayisi(); k++) {
			double toplam = 0.0f;
			double bolen = 0.0f;
			for(int i = 0; i < (satirSayisi * 2) - 1; i += 2) {
				for(int j = k; j < k + 1; j++) {
					if(satirlar[i]->veriGetir(j) != -1) {
						toplam += satirlar[i]->veriGetir(j);
						bolen++;
					}
				}
			} // Bu dongu sonunda elimizde ilk indislerin toplami var
			//cout << "toplam= " << toplam << " - bolen= " << bolen << " - bolum= " << toplam/bolen << endl;
			
			sonuc = sonuc + virguldenSonraBirBasamak(toplam / bolen);
			
			//cout << "sonuc= " << sonuc << endl;
		}
		return sonuc;
	}
	if(tur == 'a') { 
		double sonuc = 0.0;
		for(int k = 0; k < maxElemanSayisi(); k++) {
			double toplam = 0.0;
			double bolen = 0.0;
			for(int i = 1; i < satirSayisi * 2; i += 2) {
				for(int j = k; j < k + 1; j++) {
					if(satirlar[i]->veriGetir(j) != -1) {
						toplam += satirlar[i]->veriGetir(j);
						bolen++;
					}
				}
			}
			//cout << "toplam= " << toplam << " - bolen= " << bolen << " - bolum= " << toplam/bolen << endl;
			
			sonuc = sonuc + virguldenSonraBirBasamak(toplam / bolen);
			
			//cout << "sonuc= " << sonuc << endl;
		}
		return sonuc;
	}
}

double DosyaOku::virguldenSonraBirBasamak(double deger) {
	return int(deger * 10) / 10.0f;
}

int DosyaOku::maxElemanSayisi() {
	int max = 0;
	for(int i = 0; i < satirSayisi * 2; i++) {
		int listeEleman = satirlar[i]->listeElemanSayisi();
		if(max < listeEleman) {
			max = listeEleman;
		}	
	}
	return max;
}

DosyaOku::~DosyaOku() {
	//cout << "Dosya yikicisi calisti" << endl;
	for(int i = 0; i < satirSayisi * 2; i++) {
		delete satirlar[i];
	}
	delete[] satirlar;
}
