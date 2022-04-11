#include <iostream>
#include <vector>

using namespace std;

class Osoba {
private:
	string Ime;
	string Prezime;
	int GodinaRodenja;
public:
	string getIme() const {
		return Ime;
	}
	string getPrezime() const {
		return Prezime;
	}
	int getGodinaRodenja() const {
		return GodinaRodenja;
	}

	void setIme(string novoIme) {
		novoIme[0] = toupper(novoIme[0]);
		for (int i = 1; i < novoIme.length(); i++) {
			novoIme[i] = tolower(novoIme[i]);
		}
		Ime = novoIme;
	}
	void setPrezime(string novoPrezime) {
		novoPrezime[0] = toupper(novoPrezime[0]);
		for (int i = 1; i < novoPrezime.length(); i++) {
			novoPrezime[i] = tolower(novoPrezime[i]);
		}
		Prezime = novoPrezime;
	}
	void setGodinaRodenja(int novaGodinaRodenja) {
		if (novaGodinaRodenja >= 1900) {
			GodinaRodenja = novaGodinaRodenja;
		}
	}
};

int main() {
	vector<Osoba> osobe(3);
	string tempIme, tempPrezime;
	int tempGodine;
	int najstariji = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Upisite ime " << i + 1 << " osobe:";
		cin >> tempIme;
		osobe[i].setIme(tempIme);

		cout << "Upisite prezime " << i + 1 << " osobe:";
		cin >> tempPrezime;
		osobe[i].setPrezime(tempPrezime);

		cout << "Upisite godine" << i + 1 << " osobe:";
		cin >> tempGodine;
		osobe[i].setGodinaRodenja(tempGodine);
		
		if (osobe[i].getGodinaRodenja() > osobe[najstariji].getGodinaRodenja()) {
			najstariji = i;
		}
	}

	cout << "Najstariji student je: " << osobe[najstariji].getIme() << " " << osobe[najstariji].getPrezime() << " " << osobe[najstariji].getGodinaRodenja() << endl;

	return 0;
}
