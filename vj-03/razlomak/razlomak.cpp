#include <iostream>

using namespace std;

class Razlomak {
public:
	int brojnik, nazivnik;
	Razlomak(){}
	Razlomak(int _brojnik,int _nazivnik):brojnik(_brojnik),nazivnik(_nazivnik){}

	Razlomak& operator =(int broj) {
		brojnik = broj;
		nazivnik = 1;
		return *this;
	}

	Razlomak operator +(Razlomak& temp) {
		return Razlomak(brojnik * temp.nazivnik + nazivnik * temp.brojnik, nazivnik * temp.nazivnik);
	}

	Razlomak operator*(Razlomak& temp) {
		return Razlomak(brojnik * temp.brojnik, nazivnik * temp.nazivnik);
	}

	Razlomak& operator ++(int) {
		Razlomak temp = *this;
		brojnik += nazivnik;
		return temp;
	}
};

ostream& operator <<(ostream& cout, Razlomak temp) {
	cout << temp.brojnik << "/" << temp.nazivnik << endl;
	return cout;
}

int main() {

	Razlomak r1(2, 3), r2, r3;
	r2 = 2;  // 2/1
	r3 = r1 + r2;
	cout << r3++ << endl;	// 8/3
	cout << r3 * r1 << endl;	// 18/12


	return 0;
}