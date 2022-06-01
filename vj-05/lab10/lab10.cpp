#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
class Elementi {
public:
	vector<T> niz;

	auto neparni() {
		vector<T> temp;
		for (int i = 0; i < niz.size(); i++) {
			if (niz[i]%2!=0) {
				temp.push_back(niz[i]);
			}
		}
		return temp;
	}
};

template<class T>
class Red {
public:
	vector<T> red;
	int brElemenata = 0;
	void dodavanje(T temp){
		red.push_back(temp);
		brElemenata++;
	}

	void oduzimanje() {
		red.pop_back();
		brElemenata--;
	}
};

class Grad {
public:
	int populacija1;
	string ime1, drzava1;
	Grad(string _ime, int _populacija, string _drzava):ime1(_ime), populacija1(_populacija), drzava1(_drzava){}

	string ime() {
		return ime1;
	}

	string drzava() {
		return drzava1;
	}

	int populacija() {
		return populacija1;
	}
};

vector<int> dvoznamenkasti(vector<int>& v, function<bool(int)> kriterij) {
	vector<int> temp;
	for (int i = 0; i < v.size(); i++) {
		if (kriterij(v[i])) {
			temp.push_back(v[i]);
		}
	}
	return temp;
}

vector<Grad*> nadji(vector<Grad>& v, function <bool(Grad*)> kriterij) {
	vector<Grad*> temp;
	for (int i = 0; i < v.size(); i++) {
		if (kriterij(&v[i])) {
			temp.push_back(&v[i]);
		}
	}
	return temp;
}

int main() {

	int a = 2, b = 3;

	/*lambda za zamjenu vrijednosti varijabli*/
	[&a,&b]() {
		int temp = a;
		a = b;
		b = temp;
	}();

	cout << a << " " << b;


	/*2. napisi predlozak klase koja ima vektor te metodu/funkc koja vraca samo neparne elemente*/
	Elementi<int> e;
	e.niz = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	vector<int> rez = e.neparni();
	for (int i = 0; i < rez.size(); i++) {
		cout << rez[i] << " " << endl;
	}

	/*3. napisi predlozak klase Red i metode za dodavanje i oduzimanje zadnjih elemenata te int brElemenata koji ispisuje koliko ih je trenutno u redu*/
	Red<int> r1;
	r1.dodavanje(2);
	r1.dodavanje(3);
	r1.dodavanje(4);
	r1.dodavanje(5);
	cout << "-----------------\n" << r1.brElemenata << endl;
	r1.oduzimanje();
	cout << r1.brElemenata << endl;
	r1.oduzimanje();
	cout << r1.brElemenata << endl <<"------------------" << endl;

	/*4. napisi funkciju koja iz vektora ispisuje samo dvoznamenkaste
	npr vector<int> vektor = 10,4,123,23 itd
	vector<int> v2;
	v2=funkcija(vektor, *lambda izraz*);*/

	vector<int> vektor = { 10,4,123,23,153,54,12,53,11,111,2,5,3,109,99,11 };
	vector<int> rez2 = dvoznamenkasti(vektor, [&](int n) {return ((n >= 10) && (n < 100)); });
	for (int i = 0; i < rez2.size(); i++) {
		cout << rez2[i] << " " << endl;
	}

	/*5.Napišite program za pretraživanje gradova tako da radi kako je ispod prikazano.*/

	vector<Grad> v = { Grad("Zagreb", 900000, "Hrvatska"),
						Grad("Berlin", 2500000, "Njemacka"),
						Grad("Graz", 1200000, "Austrija"),
						Grad("Frankfurt", 2300000, "Njemacka") };

	// nađi sve gradove u Njemackoj
	vector<Grad*> r = nadji(v, [](Grad* s) { return s->drzava() == "Njemacka"; });

	/* Ispisuje
		Berlin 2500000 Njemacka
		Frankfurt 2300000 Njemacka
	*/
	for (Grad* p : r) {
		cout << p->ime() << " " << p->populacija() << " " << p->drzava() << endl;
	}
	

	return 0;
}