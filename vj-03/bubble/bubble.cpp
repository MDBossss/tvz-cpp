#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>


using namespace std;

class Bubble {
public:
	string boja;
	double radijus;

	Bubble(string _boja,double _radijus):boja(_boja),radijus(_radijus){}

	Bubble operator + (const Bubble& temp) {
		string novaBoja;
		double volumen = ((4.0 / 3) * (radijus * radijus * radijus) * M_PI) + ((4.0 / 3) * (temp.radijus * temp.radijus * temp.radijus) * M_PI);
		double noviRadijus = pow((3.0 * volumen) / (4.0 * M_PI), 1.0 / 3);
		if (radijus < temp.radijus) {
			novaBoja = temp.boja;
		}
		else {
			novaBoja = boja;
		}

		return Bubble(novaBoja, noviRadijus);
	}

	Bubble operator - (const Bubble& temp) {
		double volumen = ((4.0 / 3) * (radijus * radijus * radijus) * M_PI) - ((4.0 / 3) * (temp.radijus * temp.radijus * temp.radijus) * M_PI);
		double noviRadijus = pow((3.0 * volumen) / (4.0 * M_PI), 1.0 / 3);
		return Bubble(boja, noviRadijus);
	}

	bool operator ==(const Bubble& temp) {
		if (boja == temp.boja) {
			if ((radijus - temp.radijus) <= 0.0001) {
				return true;
			}
		}
		return false;
	}
};

ostream& operator <<(ostream& cout, Bubble temp) {
	cout << temp.boja << ": " << temp.radijus << endl;
	return cout;
}

int main() {

	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat će novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	Bubble y = x + c;
	cout << y; //green: 20.12

	Bubble z = y - x;
	cout << z; //green: 18.8

	if (z == c)
		cout << "OK" << endl; //OK

	return 0;
}