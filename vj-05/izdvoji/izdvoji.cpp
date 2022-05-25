#include <iostream>
#include <vector>
#include <functional>

using namespace std;



int main(){

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	/*vector<int> izdvoji(const vector<int> &brojevi, function<bool(int)>kriterij) {
		vector<int> temp;
		for (int i = 0; i < brojevi.size(); i++) {
			if (kriterij(brojevi[i])) {
				temp.pushback(brojevi[i]);
			}
		}
		return temp;
	}

	vector<int> rez = izdvoji(brojevi, [](int n) {
		return true;
	});*/

	vector<int> rez;
	[&rez](const vector<int>& brojevi) {
		for (int i = 0; i < brojevi.size(); i++) {
			if (brojevi[i] % 3 == 0) {
				rez.push_back(brojevi[i]);
			}
		}
	}(brojevi);

	for (int i = 0; i < rez.size(); i++) {
		cout << rez[i] << " ";
	}
	//ispis: 3 6 12 87 66 3 72 42

}