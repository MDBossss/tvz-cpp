#include <iostream>
#include <vector>

using namespace std;

class Racunalo {
public:
	string naziv, procesor, ram;
	Racunalo(){}
	Racunalo(string _naziv,string _procesor, string _ram):naziv(_naziv),procesor(_procesor),ram(_ram){}

};

class Ucionica {
public:
	Racunalo* racunalo;
	int brRacunala;
	//-------obinci konstruktor----------//
	Ucionica(int _brRacunala, string naziv,string procesor, string ram) {
		brRacunala = _brRacunala;
		racunalo = new Racunalo[brRacunala];
		for (int i = 0; i < brRacunala; i++) {
			racunalo[i].naziv = naziv;
			racunalo[i].procesor = procesor;
			racunalo[i].ram = procesor;
		}
	}
	//-------kopirni----------//
	Ucionica(const Ucionica& temp) {
		racunalo = new Racunalo[temp.brRacunala];
		for (int i = 0; i < temp.brRacunala; i++) {
			racunalo[i].naziv = temp.racunalo[i].naziv;
			racunalo[i].procesor = temp.racunalo[i].procesor;
			racunalo[i].ram = temp.racunalo[i].ram;
		}
		brRacunala = temp.brRacunala;
	}


	Ucionica operator = (const Ucionica& temp) {
		if (this != &temp) {
			delete[] racunalo;
			racunalo = new Racunalo[temp.brRacunala];
			for (int i = 0; i < temp.brRacunala; i++) {
				racunalo[i].naziv = temp.racunalo[i].naziv;
				racunalo[i].procesor = temp.racunalo[i].procesor;
				racunalo[i].ram = temp.racunalo[i].ram;
			}
			brRacunala = temp.brRacunala;
		}
		return *this;
	}

	//-------prijenosni----------//
	Ucionica(Ucionica&& temp) {
		racunalo = temp.racunalo;
		temp.racunalo = NULL;
		brRacunala = temp.brRacunala;
		temp.brRacunala = 0;
	}

	Ucionica operator = (Ucionica&& temp) {
		if (this != &temp) {
			racunalo = temp.racunalo;
			temp.racunalo = NULL;
			brRacunala = temp.brRacunala;
			temp.brRacunala = 0;
		}
		return *this;
	}

	~Ucionica() {
		delete[] racunalo;
	}
};

int main() {

	// Učionica 'A' s 15 računala istih specifikacija
	Ucionica A(15, "Koncar", "Intel I5", "4 GB");
	// Učionica B ima također 15 računala istih specifikacija kao i učionica 'A'
	Ucionica B = A;
	cout << B.brRacunala << endl; // 15
	// Računala iz učionice 'C' se prenose u  učionicu 'B'
	Ucionica C = move(B);
	cout << B.brRacunala << endl; // 0
	// Privremena ucionica se zatvara i njena racunala se prenose u ucionicu 'B'
	B = Ucionica(15, "Dell", "Intel I7", "8 GB");
	return 0;



	return 0;
}