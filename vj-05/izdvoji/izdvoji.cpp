#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<int> izdvoji(vector<int> polje, function<bool(int)> kriterij) { // neka bool funkcija koja prima int parametar
	vector<int> temp;
	for (int i = 0; i < polje.size(); i++) {
		if (kriterij(polje[i])) {
			temp.push_back(polje[i]);
		}
	}
	return temp;
}

int main(){

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, [](int n) {return!(n % 3); });

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 3 6 12 87 66 3 72 42

	return 0;
}
