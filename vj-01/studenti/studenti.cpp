#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    string ime, jmbag;
    Student(string _ime,string _jmbag): ime(_ime),jmbag(_jmbag){}
};

class Bodovi {
public:
    Student student;
    int bodovi;
    Bodovi(Student _student, int _bodovi): student(_student),bodovi(_bodovi){}
};

class Kolegij {
public:
    string naziv;
    vector<Bodovi> bodovi;
    Kolegij(string _naziv, vector<Bodovi> _bodovi): naziv(_naziv), bodovi(_bodovi){}
};

bool usporedba(Bodovi a, Bodovi b) {
    return a.bodovi < b.bodovi;
}

int main() {
    vector<Bodovi> OOPBodovi{

              Bodovi(Student("Ivana Ivic", "0246002475"), 25),

              Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),

              Bodovi(Student("Marko Markic", "0246004234"), 32)

    };

    Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);


    sort(OOP.bodovi.begin(), OOP.bodovi.end(), usporedba);

    cout << OOP.naziv <<" bodovi: " << endl;
    for (int i = 0; i < OOP.bodovi.size(); i++) {
        cout << OOP.bodovi[i].student.ime << " " << OOP.bodovi[i].student.jmbag << " " << OOP.bodovi[i].bodovi << endl;
    }

	return 0;
}