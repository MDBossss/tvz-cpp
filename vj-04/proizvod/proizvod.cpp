#include <iostream>
#include <vector>

using namespace std;

class Proizvod {
public:
	float cijena;
	Proizvod(float _cijena):cijena(_cijena){}
	virtual void print() = 0;
};

class LegoIgracka : public Proizvod {
public:
	string naziv;
	float kolicina;
	LegoIgracka(string _naziv,float _cijena,float _kolicina):naziv(_naziv),Proizvod(_cijena),kolicina(_kolicina){}

	void print() {
		cout << naziv << " - " << kolicina << ", " << cijena << "kn" << endl;
	}
};

class Automobil : public Proizvod {
public:
	string naziv;
	int godina;
	float brzina;
	Automobil(string _naziv,float _cijena,int _godina,float _brzina):naziv(_naziv),Proizvod(_cijena),godina(_godina),brzina(_brzina){}

	void print() {
		cout << naziv << ", " << godina << ", " << brzina << " " << cijena << "kn" << endl;
	}
};

int main()
{
	vector<Proizvod*> vp = {
	new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
	new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
	new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
	new Automobil("Yugo 45", 14500, 1988, 127.88),
	};

	for (int i = 0; i < 4; i++) {
		vp[i]->print();
	}

	/*
	Dodati kod za pronalazak proizvoda s najvećim koeficijentom i ispis tog proizvoda i odgovarajućeg koeficijenta. cijene?
	*/

	float max = 0;
	for (int i = 0; i < 4; i++) {
		if (vp[i]->cijena > vp[max]->cijena) {
			max = i;
		}
	}
	cout << "-------------\n" << "Najskuplji proizvod : \n";
	vp[max]->print();

	return 0;
}