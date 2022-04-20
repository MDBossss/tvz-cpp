#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automobil {
private:
	string proizvodac;
public:
	string gorivo;
	int cijena;
	void setProizvodac(string noviProizvodac) {
		noviProizvodac[0] = toupper(noviProizvodac[0]);
		for (int i = 1; i < noviProizvodac.length(); i++) {
			noviProizvodac[i] = tolower(noviProizvodac[i]);
		}
		proizvodac = noviProizvodac;
	}

	string getProizvodac() {
		return proizvodac;
	}
};

class Salon {
public:
	vector<Automobil*> automobil;
	string naziv, adresa;
	Salon(){}
	//kopirni
	Salon(const Salon& temp) {
		for (int i = 0; i < temp.automobil.size(); i++) {
			automobil.push_back(new Automobil);
			automobil[i]->cijena = temp.automobil[i]->cijena;
			automobil[i]->gorivo = temp.automobil[i]->gorivo;
		}
		naziv = temp.naziv;
		adresa = temp.adresa;
	}

	//operator
	Salon operator = (const Salon& temp) {
		if (this != &temp) {
			for (int i = 0; i < automobil.size(); i++) {
				delete[] automobil[i];
			}
			automobil.clear();
			for (int i = 0; i < temp.automobil.size(); i++) {
				automobil.push_back(new Automobil);
				automobil[i]->cijena = temp.automobil[i]->cijena;
				automobil[i]->gorivo = temp.automobil[i]->gorivo;
			}
			naziv = temp.naziv;
			adresa = temp.adresa;
		}
		return *this;
	}

	//prijenosni konstuktor
	Salon(Salon&& temp) {
		for (int i = 0; i < temp.automobil.size(); i++) {
			automobil.push_back(temp.automobil[i]);
			temp.automobil[i] = NULL;
		}
		naziv = temp.naziv;
		adresa = temp.adresa;
	}

	//operator
	Salon operator = (Salon&& temp) {
		if (this != &temp) {
			for (int i = 0; i < automobil.size(); i++) {
				delete[] automobil[i];
			}
			automobil.clear();
			for (int i = 0; i < temp.automobil.size(); i++) {
				automobil.push_back(temp.automobil[i]);
				temp.automobil[i] = NULL;
			}
		}
		return *this;
	}

	//destruktor
	~Salon() {
		for(int i=0;i<automobil.size();i++){
			delete[] automobil[i];
		}
		automobil.clear();
	}
};

int main() {
	Salon salon1,salon3;
	Salon salon2 = salon1; 
	salon3 = salon1;
	salon1 = Salon();


	return 0;
}