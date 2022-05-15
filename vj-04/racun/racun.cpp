#include <iostream>
#include <vector>

using namespace std;

class Stavka {
public:
	string naziv;
	float kolicina, jedCijena;
	Stavka(string _naziv,float _kolicina, float _jedCijena):naziv(_naziv),kolicina(_kolicina),jedCijena(_jedCijena){}

	bool operator ==(const Stavka temp) {
		if (naziv == temp.naziv) {
			return true;
		}
		return false;
	}
};

class Dokument {
public:
	string autor, datum, vrijeme, ID;
	Dokument(string _autor,string _datum,string _vrijeme, string _ID):autor(_autor),datum(_datum),vrijeme(_vrijeme),ID(_ID){}
};

class Racun : public Dokument {
public:
	vector<Stavka> stavke;
	string JIR, tip;
	Racun(string _autor, string _datum, string _vrijeme, string _ID,string _JIR,string _tip):Dokument(_autor,_datum,_vrijeme,_ID),JIR(_JIR),tip(_tip){}
	void ispis() {
		cout << autor << " " << datum << " " << vrijeme << " " << ID << " :" << endl;
		for (int i = 0; i < stavke.size(); i++) {
			cout << stavke[i].naziv << " " << stavke[i].jedCijena << "kn/kom " << stavke[i].kolicina << " komada." << endl;
		}
	}

	void ukupnaCijena() {
		float suma = 0;
		for (int i = 0; i < stavke.size(); i++) {
			suma += (stavke[i].kolicina * stavke[i].jedCijena);
		}
		cout << suma << endl;
	}

	void ukupnaCijenaPopust() {
		float suma = 0;
		for (int i = 0; i < stavke.size(); i++) {
			suma += ((stavke[i].kolicina * stavke[i].jedCijena) * 0.95);
		}
		cout << suma << endl;
	}
};

int main() {

	Racun racun1("Marko", "22.02.2003", "19:23", "4209-424/3", "4938", "R1");
	Stavka secer("Secer", 2, 10);
	Stavka cokolada("Cokolada", 5, 4.99);
	racun1.stavke.push_back(secer);
	racun1.stavke.push_back(cokolada);

	racun1.ispis();
	racun1.ukupnaCijena();
	racun1.ukupnaCijenaPopust();

	return 0;
}