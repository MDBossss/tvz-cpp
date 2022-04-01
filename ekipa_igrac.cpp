#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Igrac {
public:
	
	string ime, prezime;
	int broj, cijena;

	Igrac(string _ime, string _prezime) {
		ime = _ime;
		prezime = _prezime;
	}
	
	void ispisi() {
		cout << ime << " " << prezime << " - broj " << broj << " - vrijednost " << cijena << endl;
	}

};

bool cijenaUsporedba(Igrac i1, Igrac i2) {
	return i1.cijena > i2.cijena;
}

class Ekipa {
public:
	string naziv;
	vector<Igrac> niz;
	void dodajIgraca(Igrac igrac) {
		niz.push_back(igrac);
	}

	void ispisi() {
		for (int i = 0; i < niz.size(); i++) {
			cout << niz[i].ime << " " << niz[i].prezime  << " " << niz[i].broj << " " << niz[i].cijena << endl;

		}
	}

	Igrac dohvatiNajskupljeg() {
		sort(niz.begin(), niz.end(), cijenaUsporedba);
		return niz[0];
	}

	int ukupnaCijena() {
		int cijena = 0;
		for (int i = 0; i < niz.size(); i++) {
			cijena += niz[i].cijena;
		}
		return cijena;
	}

	float prosjecnaCijena() {
		float cijena = 0;
		for (int i = 0; i < niz.size(); i++) {
			cijena += niz[i].cijena;
		}
		return (cijena / niz.size());
	}
};


int main() {
	Ekipa ekipa;

	ekipa.naziv = "Tim raketa";

	Igrac i1("Luka", "Modric");
	i1.broj = 10;
	i1.cijena = 50000000;
	ekipa.dodajIgraca(i1);

	Igrac i2("Mario", "Mandzukic");
	i2.broj = 9;
	i2.cijena = 27000000;
	ekipa.dodajIgraca(i2);

	Igrac i3("Darijo", "Srna");
	i3.broj = 11;
	i3.cijena = 14500000;
	ekipa.dodajIgraca(i3);

	ekipa.ispisi();
	cout << endl;

	Igrac najskuplji = ekipa.dohvatiNajskupljeg();

	cout << "Najskuplji igrac: ";
	najskuplji.ispisi();

	cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
	cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;

	return 0;
}