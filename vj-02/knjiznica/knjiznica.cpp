#include <iostream>
#include <vector>

using namespace std;

class Knjiga {
public:
	string autor, naslov, isbn;
	Knjiga(string _autor, string _naslov, string _isbn) : autor(_autor), naslov(_naslov), isbn(_isbn) {
		cout << "Knjiga constructor called.\n";
	}

	~Knjiga() {
		cout << "Knjiga destructor called.\n";
	}
};

class Knjiznica {
private:
	string adresa, naziv, kategorija;
public:
	vector<Knjiga> niz;
	string kategorije[4] = { "djecja", "znanstvena", "citaonica", "opcenito" };
	void setAdresa(string novaAdresa) {
		adresa = novaAdresa;
	}

	void setNaziv(string noviNaziv) {
		if (noviNaziv[0] >= 'A' || noviNaziv[0] <= 'Z') {
			naziv = noviNaziv;
		}
	}

	void setKategorija(string novaKategorija) {
		for (int i = 0; i<sizeof(kategorije);i++) {
			if (novaKategorija == kategorije[i]) {
				kategorija = novaKategorija;
				break;
			}
		}
	}

	string getAdresa() {
		return adresa;
	}

	string getNaziv() {
		return naziv;
	}

	string getKategorija() {
		return kategorija;
	}

	void dodajKnjigu1(Knjiga z){
		niz.push_back(z);
	}
	void dodajKnjigu2(Knjiga& z){
		niz.push_back(z);
	}
	void dodajKnjigu3(Knjiga* z){
		niz.push_back(*z);
	}

	void ispisSvihKnjiga() {
		for (int i = 0; i < niz.size(); i++) {
			cout << niz[i].autor << " " << niz[i].naslov << " " << niz[i].isbn << endl;
		}
	}

	Knjiga nadjiKnjigu1(string isbn){
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i].isbn == isbn) {
				niz[i].naslov = "Auto biografija";
				return niz[i];
			}
		}
	}
	Knjiga* nadjiKnjigu2(string isbn){
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i].isbn == isbn) {
				niz[i].naslov = "Auto biografija";
				return &niz[i];
			}
		}
	}
	Knjiga& nadjiKnjigu3(string isbn){
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i].isbn == isbn) {
				niz[i].naslov = "Auto biografija";
				return niz[i];
			}
		}
	}
};

int main() {
	Knjiznica knjiznica;
	knjiznica.setAdresa("Konavosa 3b");
	knjiznica.setNaziv("Citko");
	knjiznica.setKategorija("djecja");

	Knjiga k1("Marko", "Biografija", "098432");
	Knjiga k2("Petar", "Biografija", "543432");
	Knjiga k3("Stevo", "Biografija", "333333");

	knjiznica.dodajKnjigu1(k1);
	cout << "---------------------\n";
	knjiznica.dodajKnjigu2(k2);
	cout << "---------------------\n";
	knjiznica.dodajKnjigu3(&k3);
	cout << "---------------------\n";

	knjiznica.ispisSvihKnjiga();

	knjiznica.nadjiKnjigu1("098432");
	knjiznica.nadjiKnjigu2("543432");
	knjiznica.nadjiKnjigu3("333333");

	knjiznica.ispisSvihKnjiga();

	return 0;
}