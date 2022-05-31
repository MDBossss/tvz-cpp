#include <iostream>
#include <vector>

using namespace std;

class Kompleksni {
public:
	float re, im;
	Kompleksni(float _re,float _im):re(_re),im(_im){}

	Kompleksni operator +(float temp) {
		return Kompleksni(re + temp, im);
	}
};

ostream& operator <<(ostream& cout, Kompleksni temp) {
	cout << temp.re << " " << temp.im << "i" << endl;
	return cout;
}

class Matematika {
public:
	template <class T1, class T2>
	auto suma(T1 a, T2 b) {
		return a + b;
	}
};

int main() {
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}
