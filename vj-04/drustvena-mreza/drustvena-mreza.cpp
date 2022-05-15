#include <iostream>
#include <vector>

using namespace std;

class Sadrzaj {
public:
	string datum, vrijeme, ime, prezime;
	int razina;
	Sadrzaj(string _datum,string _vrijeme, string _ime, string _prezime, int _razina):datum(_datum),vrijeme(_vrijeme),ime(_ime),prezime(_prezime),razina(_razina){}
};

class Link : public Sadrzaj {
public:
	string url, naslov, opis;
	Link(string _datum, string _vrijeme, string _ime, string _prezime, int _razina, string _url, string _naslov, string _opis): Sadrzaj(_datum, _vrijeme, _ime, _prezime, _razina),url(_url),naslov(_naslov),opis(_opis){}
};

class Korisnik {
public:
	string ime, prezime, mail;
	vector<Sadrzaj*> sadrzaj;
	Korisnik(string _ime, string _prezime, string _mail):ime(_ime),prezime(_prezime),mail(_mail){}

	bool operator == (Korisnik& temp) {
		if (ime == temp.ime) {
			if (prezime == temp.prezime) {
				return true;
			}
		}
		return false;
	}
};

int main() {

	Korisnik marko("Marko", "Markic", "markogmail.com");
	Korisnik petar("Petar", "Petric", "petargmail.com");
	
	Link biografija1("22.02.2003", "19:43", "Marko", "Markic", 3, "www.marko-biografija.com", "Biografija", "Markova biografija");
	Link biografija2("22.02.2003", "20:43", "Marko", "Markic", 3, "www.marko-biografija.com", "Biografija", "Markova biografija");
	Link biografija3("22.02.2003", "23:43", "Marko", "Markic", 3, "www.marko-biografija.com", "Biografija", "Markova biografija");

	marko.sadrzaj.push_back(&biografija1);
	marko.sadrzaj.push_back(&biografija2);
	marko.sadrzaj.push_back(&biografija3);

	for (int i = 0; i < marko.sadrzaj.size(); i++) {
		cout << marko.sadrzaj[i]->ime << " " << marko.sadrzaj[i]->prezime << " " << marko.sadrzaj[i]->datum << " " << marko.sadrzaj[i]->vrijeme << endl;
	}

	if (marko == petar) {
		cout << "Isti.";
	}
	else {
		cout << "Razliciti.";
	}

	return 0;
}