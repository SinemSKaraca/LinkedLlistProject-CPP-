#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP
#include "Dugum.hpp"

class BagliListe {
private:
	Dugum* listeBasi;
	int elemanSayisi;
public:
	BagliListe();
	void sonaEkle(const int&);
	//void listeYazdir();
	int veriGetir(int);
	int listeElemanSayisi();
	//friend ostream& operator<<(ostream&, BagliListe&);
	~BagliListe();
};

#endif