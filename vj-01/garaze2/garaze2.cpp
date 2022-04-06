#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Predmet {
public:
	string naziv;
	int vrijednost;
};

class Garaza {
public:
	float x, y;
	string auto_vrata, lokacija;
	vector<Predmet> niz;
};

int main() {
	int m, n, x;
	vector<Garaza> garaze;
	cout << "Unesite broj garaza (n): ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Garaza temp;
		cout << "Unesite velicinu, lokaciju i podatak o vratima za " << i + 1 << ". garazu:" << endl;
		cin >> temp.x >> temp.y;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, temp.lokacija);
		cin >> temp.auto_vrata;
		garaze.push_back(temp);
	}

	cout << "Unesite broj predmeta (m): ";
	cin >> m;

	for (int i = 0; i < m; i++) {
		Predmet temp;
		cout << "Unesite redni broj garaze u koju spada " << i + 1 << ". predmet: ";
		cin >> x;
		x -= 1;
		cout << "Unesite naziv i vrijednost predmeta: ";
		cin >> temp.naziv >> temp.vrijednost;
		garaze[x].niz.push_back(temp);
	}

	cout << "Ispis garaza i predmeta: " << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << garaze[i].lokacija << " " << garaze[i].x << "x" << garaze[i].y << " - predmeti: ";
		for (int j = 0; j < garaze[i].niz.size(); j++) {
			cout << garaze[i].niz[j].naziv << " (" << garaze[i].niz[j].vrijednost << ")" << endl;
		}
	}

	return 0;
}