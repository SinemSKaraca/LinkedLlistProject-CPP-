#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP
#include "BagliListe.hpp"
#include <iostream>
using namespace std;

class DosyaOku {
private:
	int satirSayisi;
	BagliListe** satirlar;
	
	int maxElemanSayisi();
public:
	DosyaOku();
	string bosluksuzString(string);
	int satirSayisiBul();
	void ustAltListeDegistir(int, int);
	double ortalama(char);
	double virguldenSonraBirBasamak(double deger);
	~DosyaOku();
};

#endif