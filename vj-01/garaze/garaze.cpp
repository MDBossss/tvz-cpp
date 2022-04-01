#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Kljuc {
public:
	string ime, prezime;
};

class Garaza {
public:
	int x,y, cijena;
	string lokacija;
	vector<Kljuc> niz;
};

int main() {
	int n, m, x;
	vector<Garaza> garaza;

	cout << "Unesite broj garaza (n): ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		Garaza temp;
		cout << "Unesite velicinu, lokaciju i cijenu za " << i + 1 << " garazu:" << endl;
		cin >> temp.x >> temp.y;
		// cin >> temp.lokacija
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, temp.lokacija);
		cin	>> temp.cijena;
		garaza.push_back(temp);
	}

	cout << "Unesite broj kljuceva (m): ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		Kljuc temp;
		cout << "Unesite redni broj garaze kojoj pripada " << i + 1 << " kljuc: ";
		cin >> x;
		x -= 1;
		cout << "Unesite ime vlasnika kljuca: ";
		cin >> temp.ime >> temp.prezime;
		garaza[x].niz.push_back(temp);
	}

	cout << "Ispis garaza i kljuceva:";
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << i + 1 << ". " << garaza[i].lokacija << " " << garaza[i].x << "x" << garaza[i].y << " - kljucevi: ";
		for (int j = 0; j < garaza[i].niz.size(); j++) {
			cout << garaza[i].niz[j].ime << " " << garaza[i].niz[j].prezime << endl;
		}
	}
	
	return 0;
}
