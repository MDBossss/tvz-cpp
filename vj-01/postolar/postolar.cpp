#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cipela {
public:
    int velicina;
    string materijal, boja;
    Cipela(int _velicina, string _materijal, string _boja): velicina(_velicina), materijal(_materijal), boja(_boja){}
};

class Narudzba {
public:
    string narucitelj;
    vector<Cipela> cipele;
    Narudzba(string _narucitelj): narucitelj(_narucitelj){}
    Narudzba(){}
    void dodajCipelu(Cipela cipela) {
        cipele.push_back(cipela);
    }
};

class Postolar {
public:
    vector<Narudzba> naruceno;

    double preuzmiNarudzbu(Narudzba n) {
        double cijena = 0;
        for (int i = 0; i < n.cipele.size(); i++) {
            cijena += (n.cipele[i].velicina * 10, 5);
        }
        naruceno.push_back(n);
        return cijena;
    }

    void ispisiNarudzbe() {

    }
};

int main() {
    Postolar p;

    Narudzba n1;
    n1.narucitelj = "Susjed Mirko";

    //Cipela ima broj (velicinu), materijal i boju

    n1.dodajCipelu(Cipela(47, "Sky", "plava"));
    n1.dodajCipelu(Cipela(44, "Platno", "zelena"));

    //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5

    double c1 = p.preuzmiNarudzbu(n1);
    cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;

    Narudzba n2("Barica");
    n2.dodajCipelu(Cipela(43, "Koza", "crna"));

    double c2 = p.preuzmiNarudzbu(n2);
    cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;

    //Ispisuje sve narudzbe
    //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene

    p.ispisiNarudzbe();

	return 0;
}