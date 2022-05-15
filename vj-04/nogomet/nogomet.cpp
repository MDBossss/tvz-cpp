#include <iostream>
#include <vector>

using namespace std;

class Pozicija {
public:
	string ime, prezime;
	float osnovica;
	Pozicija(string _ime,string _prezime,float _osnovica):ime(_ime),prezime(_prezime),osnovica(_osnovica){}

	virtual void ispis() = 0;
	virtual float izracunPlace() = 0;
};

class Igrac : public Pozicija {
public:
	float golovi=0, asistencije=0;
	Igrac(string _ime, string _prezime, float _osnovica):Pozicija(_ime,_prezime,_osnovica){}

	void dodajGolove(int broj) {
		golovi += broj;
	}

	void dodajAsistencije(int broj) {
		asistencije += broj;
	}

	void ispis() {
		cout << ime << " " << prezime << " - golova: " << golovi << ", asistencija: " << asistencije << endl;
	}

	float izracunPlace() {
		float g = (golovi / 10) * (osnovica * 0.1);
		float a = (asistencije / 5) * (osnovica * 0.1);
		return g + a + osnovica;
	}
};

class Trener : public Pozicija {
public:
	int pobjede=0, remi=0, izgubljene=0;
	Trener(string _ime, string _prezime, float _osnovica) :Pozicija(_ime, _prezime, _osnovica) {}

	void dodajPobjede(int broj) {
		pobjede += broj;
	}

	void dodajRemi(int broj) {
		remi += broj;
	}

	void dodajIzgubljene(int broj) {
		izgubljene += broj;
	}

	void ispis() {
		cout << ime << " " << prezime << " - Omjer (W/D/L): " << pobjede << " / " << remi << " / " << izgubljene << endl;
	}

	float izracunPlace(){
		int p = (pobjede / 5) * (osnovica * 0.1);
		int r = (remi / 10) * (osnovica * 0.1);
		int i = (izgubljene / 8) * (osnovica * 0.1);

		return osnovica + p + r - i;
	}
};

int main()
{
	Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
	i.dodajGolove(7);
	i.dodajAsistencije(12);
	i.ispis(); //Luka Modric - golova: 7, asistencija: 12
	cout << "Placa: " << i.izracunPlace() << endl; //Placa: 120000

	Igrac i2("C", "Ronaldo", 234505);
	i2.dodajGolove(57);
	i2.dodajAsistencije(32);
	i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
	cout << "Placa: " << i2.izracunPlace() << endl; //Placa : 492461

	Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
	t1.dodajPobjede(88); //Dodati broj pobjeda (W)
	t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
	t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

	t1.dodajPobjede(11);
	t1.dodajIzgubljene(47);
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523

	//demonstracija polimorfizma
	Pozicija* p;
	Igrac i3("Marko", "Nogometas", 1000);
	p = &i3;
	p->ispis();

}

