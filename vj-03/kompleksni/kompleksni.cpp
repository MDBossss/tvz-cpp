#include <iostream>

using namespace std;

class Kompleksni {
public:
	float re, im;
	Kompleksni(float _re,float _im):re(_re),im(_im){}

	Kompleksni operator +(const Kompleksni& temp) {
		return Kompleksni(re + temp.re, im + temp.im);
	}

	Kompleksni operator *(const Kompleksni& temp) {
		return Kompleksni(re * temp.re -im * temp.im, re * temp.im + temp.re * im);
	}

	Kompleksni& operator ++() {
		++this->re;
		++this->im;
		return *this;
	}

	Kompleksni operator ++(int) {
		Kompleksni temp = *this;
		++(*this);
		return temp;

	}
};

ostream& operator <<(ostream& cout,Kompleksni temp) {
	cout << temp.re << temp.im << "i" << endl;
	return cout;
}

Kompleksni operator -(Kompleksni temp, double broj) {
	return Kompleksni(temp.re - broj, temp.im);
}

Kompleksni operator -(double broj, Kompleksni temp) {
	return Kompleksni(broj - temp.re, temp.im);
}

int main() {

	// Z1 = 1, Z2 = 2 - i
	Kompleksni Z1(1, 0), Z2(2, -1);

	// članska operatorska funkcija + (Kompleksni)
	Kompleksni Suma = Z1 + Z2;
	cout << Suma << endl; // 3 - 1i

	// članska operatorska funkcija * (Kompleksni)
	Kompleksni Umnozak = Z1 * Z2;
	cout << Umnozak << endl; // 2 - 1i

	// ne-članska operatorska funkcija - (Kompleksni, double)
	Kompleksni Razlika = Suma - 3;
	cout << Razlika << endl; // 0 - 1i

	// ne-članska operatorska funkcija - (double, Kompleksni)
	Kompleksni Razlika2 = 3 - Suma;
	cout << Razlika2 << endl; // 0 - 1i


	return 0;
}