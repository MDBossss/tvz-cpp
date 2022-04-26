#include <iostream>

using namespace std;

class Slika {
public:
	static float ukupno, kolicina;
	float cijena;
	Slika(float _cijena):cijena(_cijena){
		ukupno += _cijena;
		kolicina++;
	}

	float ProsjecnaCijena() {
		return ukupno / kolicina;
	}
};
float Slika::ukupno = 0;
float Slika::kolicina = 0;

int main() {

	Slika Slika1(2000); // 2000 eura

	Slika Slika2(3000); // 3000 eura

	Slika Slika3(1800); // 1800 eura

	cout << Slika1.ProsjecnaCijena() << " eura"; // 2266.67 eura

	return 0;
}