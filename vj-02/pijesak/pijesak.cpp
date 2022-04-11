#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Zrno {
public:
	string boja;
	float promjer;
};


class Pijesak {
public:
	int kolicina;
	Zrno* zrno; // vec imamo pokazivac na polje
	//konstruktor
	Pijesak(int _kolicina):kolicina(_kolicina){
		zrno = new Zrno[_kolicina]; // dinamicka alokacija polja zrno
	}

	/*Naš je cilj da se prilikom poziva kopirnog konstruktora za svaki novi objekt dinamički alocira
	novi niz. Tako bi izbjegli dijeljenje memorijskih adresa među pokazivačima, pa i sve
	komplikacije koje iz toga proizlaze. Da bi to realizirali moramo napisati vlastitu
	implementaciju kopirnog konstruktora koja radi duboko kopiranje (eng. deep copy).*/



	//KOPIRTNI KONSTRUKTOR - deep copy ako klasa sadrzi pokazivace, ako ne nema potrebe za kopirnim konstruktorom
	//Kopirni konstruktor kao parametar prima konstantnu referencu objekta svoje klase. 
	Pijesak(const Pijesak& p) {
		zrno = new Zrno[p.kolicina];
		for (int i = 0; i < p.kolicina; i++) {
			zrno[i] = p.zrno[i];
		}
		kolicina = p.kolicina;
	}
													// } i jedan i drugi su potrebni za deep copy, kao jedno
	//OPERATOR SEMANTIKOE KOPIRANJA (COPY)
	Pijesak& operator = (const Pijesak& p) {
		if (this != &p) {
			delete[] zrno;
			zrno = new Zrno[p.kolicina];
			for (int i = 0; i < p.kolicina; i++) {
				zrno[i] = p.zrno[i];
			}
			kolicina = p.kolicina;
		}
		return *this;
	}

	//KONSTRUKTRO SEMANTIKE PRIJENOSA (MOVE)
	Pijesak(Pijesak&& temp) {
		zrno = temp.zrno; //preusmjeri pokazivac
		temp.zrno = NULL; //privremeni objekt vise nije vlasnik pokazivaca
		kolicina = temp.kolicina;

	}

	//OPERATOR SEMANTIKE PRIJENOSA (MOVE)
	Pijesak& operator = (Pijesak&& temp) {
		if (this != &temp) {
			delete[] zrno;
			zrno = temp.zrno;
			temp.zrno = NULL;
			kolicina = temp.kolicina;
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

	//semantika kopiranja
	Pijesak sahara(igraliste);

	//semanitka prijenosa
	Pijesak indija = Pijesak(300000);
	Pijesak nekaPustinja(Pijesak(20));

	cout << "U saharni ima " << sahara.kolicina << " zrna pijeska!\n";
	cout << "U indiji ima " << indija.kolicina << " zrna pijeska!\n";
	cout << "U nekoj pustinji ima " << nekaPustinja.kolicina << " zrna pijeska!\n";
 


	return 0;
}
