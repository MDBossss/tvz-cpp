#include <iostream>
#include <vector>

using namespace std;

class Osoba {
private:
	string ime, prezime;
	int rodenje;
public:
	void setIme(string novoIme) {
		if (novoIme.length() >= 3) {
			ime = novoIme;
		}
	}

	void setPrezime(string novoPrezime) {
		if (novoPrezime.length() >= 3) {
			prezime = novoPrezime;
		}
	}

	void setRodenje(int novoRodenje) {
		if (novoRodenje > 1900) {
			rodenje = novoRodenje;
		}
	}

	string getIme() const {
		return ime;
	}

	string getPrezime() const {
		return prezime;
	}

	int getRodenje() const {
		return rodenje;
	}
};

class Ljudi {
public:
	Osoba niz[3];

	void najstarijaOsoba() {
		int najstariji = 0;
		for (int i = 0; i < 3; i++) {
			if (niz[i].getRodenje() < niz[najstariji].getRodenje()) {
				najstariji = i;
			}
		}
		cout << "Najstarija osoba: " << niz[najstariji].getIme() << " " << niz[najstariji].getPrezime() << " " << niz[najstariji].getRodenje() << endl;
	}
};

int main() {
	Ljudi ljudi;
	string tempString;
	int tempInt;
	for (int i = 0; i < 3; i++) {
		cin >> tempString;
		ljudi.niz[i].setIme(tempString);
		cin >> tempString;
		ljudi.niz[i].setPrezime(tempString);
		cin >> tempInt;
		ljudi.niz[i].setRodenje(tempInt);
	}

	ljudi.najstarijaOsoba();
	return 0;
}