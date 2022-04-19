#include <iostream>
#include <vector>

using namespace std;

class Stan {
public:
	string vlasnik;
	int velicina, soba;

	Stan(string _vlasnik, int _velicina, int _soba) :vlasnik(_vlasnik), velicina(_velicina), soba(_soba) {
		cout << "Stan constructor called.";
	}

	~Stan() {
		cout << "Stan destructor called.";
	}
};

class Zgrada {
private:
	string naziv, adresa;
	int katovi;
public:
	vector<Stan> niz;
	void setNaziv(string noviNaziv) {
		if (noviNaziv.length() >= 5) {
			naziv = noviNaziv;
		}
		else {
			cout << "Krivo upisan naziv.";
		}
	}

	void setAdresa(string novaAdresa) {
		adresa = novaAdresa;
	}

	void setKatovi(int noviKatovi) {
		if (noviKatovi > 0) {
			katovi = noviKatovi;
		}
		else {
			cout << "Krivo upisani katovi.";
		}
	}

	string getNaziv() const{
		return naziv;
	}

	string getAdresa() const{
		return adresa;
	}

	int getKatovi() const{
		return katovi;
	}

	void dodajStan1(Stan z) {
		niz.push_back(z);
	}

	void dodajStan2(Stan& z) {
		niz.push_back(z);
	}

	void dodajStan3(Stan* z) {
		niz.push_back(*z);
	}

	void ispisSvihStanova() {
		for (int i = 0; i < niz.size(); i++) {
			cout << niz[i].vlasnik << " " << niz[i].soba << " " << niz[i].velicina << endl;
		}
	}

	Stan nadjiStan1(string vlasnik) {
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i].vlasnik == vlasnik) {
				niz[i].soba += 10;
				return niz[i];
			}
		}
	}

	Stan* nadjiStan2(string vlasnik) {
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i].vlasnik == vlasnik) {
				niz[i].soba += 10;
				return &niz[i];
			}
		}
	}

	Stan& nadjiStan3(string vlasnik) {
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i].vlasnik == vlasnik) {
				niz[i].soba += 10;
				return niz[i];
			}
		}
	}



};

int main() {
	Zgrada zgrada;
	zgrada.setAdresa("Konavoska 3b");
	zgrada.setNaziv("Moja zgrada");
	zgrada.setKatovi(10);

	Stan stan1("Marko", 400, 3);
	Stan stan2("Petar", 200, 2);
	Stan stan3("Marija", 1000, 10);

	zgrada.dodajStan1(stan1);
	zgrada.dodajStan2(stan2);
	zgrada.dodajStan3(&stan3);

	zgrada.ispisSvihStanova();

	zgrada.nadjiStan1("Marko");
	zgrada.nadjiStan2("Petar");
	zgrada.nadjiStan3("Marija");

	zgrada.ispisSvihStanova();


	return 0;
}