#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Pedalina {
public:
	string boja;
	int kapacitet;
};

class Lokacija {
public:
	string ime, prezime;
	double x, y;
	vector<Pedalina> niz;
};

int main() {
	int n, m, x;
	vector<Lokacija> lokacija;

	cout << "Unesite broj lokacija (n): ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		Lokacija temp;
		cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << " lokaciju:" << endl;
		cin >> temp.ime >> temp.prezime >> temp.x >> temp.y;
		lokacija.push_back(temp);
	}

	cout << "Unesite broj pedalina (m): ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		Pedalina temp;

		cout << "Unesite redni broj lokacija kojoj pripada " << i + 1 << " pedalina: ";
		cin >> x;
		x -= 1;

		cout << "Unesite boju i kapacitet pedaline: ";
		cin >> temp.boja >> temp.kapacitet;
		lokacija[x].niz.push_back(temp);
	}

	cout << "Ispis lokacija i pedalina: " << endl;
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i + 1 << "." << " " << lokacija[i].x << " " << lokacija[i].y << " " << lokacija[i].ime << " " << lokacija[i].prezime << " - pedaline: ";
		for (int j = 0; j < lokacija[i].niz.size(); j++) {
			cout << lokacija[i].niz[j].boja << " " << lokacija[i].niz[j].kapacitet << endl;
		}
	}

	return 0;
}