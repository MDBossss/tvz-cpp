#include <iostream>

using namespace std;

class Zrno {
public:
	string boja;
	float promjer;
};

class Pijesak {
public:
	int kolicina;
	Zrno* zrno;
	Pijesak(int _kolicina) :kolicina(_kolicina) {
		zrno = new Zrno[_kolicina];
		cout << "Obicni konstruktor\n";
	}

	//----------------KOPIRNI--------------//
	Pijesak(const Pijesak& p) {
		zrno = new Zrno[p.kolicina];
		for (int i = 0; i < p.kolicina; i++) {
			zrno[i].boja = p.zrno[i].boja;
			zrno[i].promjer = p.zrno[i].promjer;
		}
		kolicina = p.kolicina;
		cout << "Kopirni konstruktor\n";

	}

	Pijesak& operator = (const Pijesak& p) {
		if (this != &p) {
			zrno = new Zrno[p.kolicina];
			for (int i = 0; i < p.kolicina; i++) {
				zrno[i].boja = p.zrno[i].boja;
				zrno[i].promjer = p.zrno[i].promjer;
			}
			kolicina = p.kolicina;
			cout << "Operator copy\n";
		}
		return *this;
	}

	//----------------PRIJENOS--------------//
	Pijesak(Pijesak&& p) {
		zrno = p.zrno;
		p.zrno = NULL;
		kolicina = p.kolicina;
		cout << "Konstriktor prijenosa\n";
	}

	Pijesak& operator = (Pijesak&& p) {
		if (this != &p) {
			delete[] zrno;
			zrno = p.zrno;
			p.zrno = NULL;
			kolicina = p.kolicina;
			cout << "Operator move\n";
		}
		return *this;
	}


	~Pijesak() {
		delete[] zrno;
	}
};


int main() {

	Pijesak igraliste(1000000);
	cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

	Pijesak skola = igraliste; // kopirni konstruktor
	Pijesak vrtic(0); 
	vrtic = skola; // operator = copy
	Pijesak skola2 = move(Pijesak(500000)); //konstruktor prijenosa
	Pijesak skola3(0);
	skola3 = Pijesak(500000); // operator = move


	return 0;
}