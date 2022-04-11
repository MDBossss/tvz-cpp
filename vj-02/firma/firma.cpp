#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Zaposlenik {
public:
	string ime, prezime;
	Zaposlenik(string _ime, string _prezime) :ime(_ime), prezime(_prezime) {
		cout << "Zaposlenik constructor called\n";
	}

	~Zaposlenik() {
		cout << "Zaposlenik destructor called\n";
	}
};

class Firma {
private:
	string naziv, oib, adresa;
	vector<Zaposlenik> zaposlenici;
public:
	void setNaziv(string noviNaziv) {
		if (noviNaziv.length() >= 5) {
			naziv = noviNaziv;
		}
		else {
			cout << "Krivo upisan naziv." << endl;
		}
	}

	void setOib(string noviOib) {
		if (noviOib.length() == 11) {
			oib = noviOib;
		}
		else {
			cout << "Krivo upisan oib." << endl;
		}
	}

	void setAdresa(string novaAdresa) {
		adresa = novaAdresa;
	}

	string getNaziv() const {
		return naziv;
	}

	string getOib() const {
		return oib;
	}

	string getAdresa() const {
		return adresa;
	}

	void dodajZaposlenika1(Zaposlenik z) {
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika2(Zaposlenik& z) {
		zaposlenici.push_back(z);
	}

	vector<Zaposlenik> ispisSvihZaposlenika() {
		return zaposlenici;
	}

	Zaposlenik nadjiZaposlenika1(string ime, string prezime) {
		for (int i = 0; i < zaposlenici.size(); i++) {
			if (ime == zaposlenici[i].ime) {
				if (prezime == zaposlenici[i].prezime) {
					zaposlenici[i].prezime[0] = '5';
					return zaposlenici[i];
				}
			}
		}
	}

	Zaposlenik* nadjiZaposlenika2(string ime, string prezime) {
		for (int i = 0; i < zaposlenici.size(); i++) {
			if (ime == zaposlenici[i].ime) {
				if (prezime == zaposlenici[i].prezime) {
					zaposlenici[i].prezime[0] = '5';
					return &zaposlenici[i];
				}
			}
		}
	}

	Zaposlenik& nadjiZaposelnika3(string ime, string prezime) {
		for (int i = 0; i < zaposlenici.size(); i++) {
			if (ime == zaposlenici[i].ime) {
				if (prezime == zaposlenici[i].prezime) {
					zaposlenici[i].prezime[0] = '5';
					return zaposlenici[i];
				}
			}
		}
	}


};

int main() {
	Firma firma;
	string tempString;
	firma.setNaziv("Gredelj");
	firma.setAdresa("Konvoska 3b");
	firma.setOib("23458678940");

	Zaposlenik z1("Marko","Prezimenko");
	Zaposlenik z2("Petar", "Nemiaran");

	firma.dodajZaposlenika1(z1);
	firma.dodajZaposlenika2(z2);

	Zaposlenik vraceni = firma.nadjiZaposlenika1("Marko", "Prezimenko");
	cout << vraceni.ime << " " << vraceni.prezime << endl;


	return 0;
}