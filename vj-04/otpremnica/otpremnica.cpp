#include <iostream>
#include <vector>

using namespace std;

class Stavka {
public:
	float kolicina, jedCijena, jedTezina;
	string naziv;
	Stavka(string _naziv, float _kolicina, float _jedCijena, float _jedTezina):naziv(_naziv),kolicina(_kolicina),jedCijena(_jedCijena),jedTezina(_jedTezina){}
};

class Dokument {
public:
	string autor, datum, vrijeme, ID;
	Dokument(string _autor, string _datum, string _vrijeme, string _ID): autor(_autor),datum(_datum),vrijeme(_vrijeme),ID(_ID){}
};

class Otpremnica : public Dokument {
public:
	string naziv, lokacija;
	vector<Stavka> stavke;
	Otpremnica(string _autor, string _datum, string _vrijeme, string _ID,string _naziv, string _lokacija):Dokument(_autor,_datum,_vrijeme,_ID),naziv(_naziv),lokacija(_lokacija){}

	float ukupnaTezina() {
		float temp = 0;
		for (int i = 0; i < sizeof(stavke); i++) {
			temp += (stavke[i].jedTezina * stavke[i].kolicina);
		}
		return temp;
	}
	
	void ispis() {
		cout << ID << " " << naziv << " " << lokacija << " " << autor << " " << datum << " " << vrijeme << " :\n";
		for (int i = 0; i < stavke.size(); i++) {
			cout << stavke[i].naziv << " " << stavke[i].kolicina << endl;
		}
	}

	Otpremnica& operator--() {
		for (int i = 0; i < stavke.size(); i++) {
			this->stavke[i].kolicina--;
		}
		return *this;
	}

	Otpremnica& operator--(int) {
		for (int i = 0; i < stavke.size(); i++) {
			this->stavke[i].kolicina--;
		}
		return *this;
	}
};

int main() {

	Otpremnica otp("Marko", "22.02.2003", "14:04", "109-403", "Otpremnica Kupusa", "Moja lokacija");

	otp.stavke.push_back(Stavka("Krumpiri", 2, 10, 1));
	otp.stavke.push_back(Stavka("Kutije", 5, 6, 3));
	otp.ispis();

	--otp;
	otp.ispis();

	otp--;
	otp.ispis();

	return 0;
}