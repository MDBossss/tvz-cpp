#include <iostream>
#include <cmath>

using namespace std;


class PotencijaBrojaException {
public:
	float p;
	PotencijaBrojaException(float _p):p(_p){}

	void ispis(){
		cout << "Potencija " << p << " nije ispravna!" << endl;
	}
};

class PotencijaBroja {
private:
	float baza, potencija;
public:
	static int count;
	PotencijaBroja(){}
	PotencijaBroja(float _baza,float _potencija):baza(_baza),potencija(_potencija){
		float number = pow(_baza, _potencija);
		if (number == (int)number) {
			count++;
		}
	}
	void SetPotencija(float novaPotencija);

	void setBaza(float novaBaza) {
		baza = novaBaza;
	}

	float getBaza() const{
		return baza;
	}

	float getPotencija() const {
		return potencija;
	}

	static int brojac() {
		return count;
	}

	PotencijaBroja& operator++() {
		++this->potencija;
		return *this;
	}

	PotencijaBroja& operator++(int) {
		++this->potencija;
		return *this;
	}
};

int PotencijaBroja::count = 0;

void PotencijaBroja::SetPotencija(float novaPotencija) {
	try {
		if (novaPotencija < 0) {
			throw PotencijaBrojaException(novaPotencija);
		}
		else {
			potencija = novaPotencija;
		}
	}
	catch (PotencijaBrojaException iznimka) {
		iznimka.ispis();
	}
}

float operator +(PotencijaBroja b1, PotencijaBroja b2) {
	return((pow(b1.getBaza(), b1.getPotencija())) + (pow(b2.getBaza(), b2.getPotencija())));
}

ostream& operator <<(ostream& cout, PotencijaBroja temp) {
	cout << temp.getBaza() << "^" << temp.getPotencija();
	return cout;
}

istream& operator >>(istream& cin, PotencijaBroja& temp) {
	float b, p;
	//cin >> temp.setBaza(b) >> temp.SetPotencija(p);
	cin >> b >> p;
	temp.setBaza(b);
	temp.SetPotencija(p);
	return cin;
}

int main() {

	PotencijaBroja b1(16, 0.25);
	PotencijaBroja b2(5, 0.33);
	PotencijaBroja b3(5, 2);
	cout << PotencijaBroja::brojac() << endl;

	b2.SetPotencija(-3);
	b2.SetPotencija(0.5);

	float zbroj = b1 + b3;
	cout << zbroj << endl;

	cout << b3 << endl;
	++b3;
	cout << b3 << endl;
	b3++;
	cout << b3 << endl;

	PotencijaBroja b4;
	cin >> b4;
	cout << b4 << endl;

	return 0;
}