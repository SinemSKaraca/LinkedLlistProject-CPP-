hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/DosyaOku.o ./lib/Dugum.o ./lib/BagliListe.o ./src/Test.cpp

calistir:
	./bin/Test
	