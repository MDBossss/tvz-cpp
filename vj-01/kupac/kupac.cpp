#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Artikl {
public:
    string naziv;
    float cijena, kolicina;
    Artikl(string _naziv, float _kolicina, float _cijena) :naziv(_naziv), kolicina(_kolicina), cijena(_cijena) {}
};

class Racun {
public:
    int broj;
    float ukupnaCijena=0;
    vector<Artikl> stavka;
    
    Racun(int _broj): broj(_broj) {}

    void dodaj(Artikl artikl) {
        stavka.push_back(artikl);
        ukupnaCijena += (artikl.cijena * artikl.kolicina);
    }

};

class Kupac {
public:
    Racun racun;
    Kupac(Racun _racun): racun(_racun){}
};

int main() {


    Kupac Ante(Racun(1)); // Ante ima racun broj 1

    Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg

    Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg

    Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca

    cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn
    
    int najskuplji = 0;
    for (int i = 0; i < Ante.racun.stavka.size(); i++) {
        if (Ante.racun.stavka[i].cijena > Ante.racun.stavka[najskuplji].cijena) {
            najskuplji = i;
        }
    }

    cout << "Najskuplje placeni artikl je " << Ante.racun.stavka[najskuplji].naziv << " " << Ante.racun.stavka[najskuplji].cijena * Ante.racun.stavka[najskuplji].kolicina << "kn" << endl;

	return 0;
}