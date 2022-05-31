#include <iostream>
#include <vector>
#include <functional>

using namespace std;


vector<int> izdvoji(vector<int>& br, function<bool(int)> kriterij) {
	vector<int> temp;
	for (int i = 0; i < br.size(); i++) {
		if (kriterij(br[i])) {
			temp.push_back(br[i]);
		}
	}
	return temp;
}

int main()
{
	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, [](int br) {return ((br / 10 < 10) && br/10 > 0); });

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 12 65 32 87 55 23 22 66 32 76 72 42

}