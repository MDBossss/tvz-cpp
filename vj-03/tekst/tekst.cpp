#include <iostream>
#include <string>

using namespace std;

class Tekst {
public:
	Tekst(){}
	Tekst(string s): niz(s){}

    Tekst operator *(int broj) {
        string r = "";
        for (int i = 0; i < broj; i++) {
            r += niz;
        }
        return Tekst(r);
    }

    Tekst operator +(const Tekst& temp) {
        return Tekst(niz + temp.niz);
    }

    Tekst operator-(char slovo) {
        string r = "";
        for (int i = 0; i < niz.size(); i++) {
            if (niz[i] != slovo) {
                r += niz[i];
            }
        }
        return Tekst(r);
    }

    string getTekst() const {
        return niz;
    }


private:
	string niz;
};

ostream& operator <<(ostream& izlaz, const Tekst& tekst) {
    cout << tekst.getTekst();
    return izlaz;
}

Tekst operator*(int broj, Tekst& tekst) {
    string r = "";
    for (int i = 0; i < broj; i++) {
        r += tekst.getTekst();
    }
    return Tekst(r);
}




int main() {
    Tekst t("abc");
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc
}

