#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Niz {
public:
	vector<T> vektor;
	Niz(vector<T> _vektor): vektor(_vektor){}
	bool operator<(const Niz<T>& temp);

	bool manje_od(const Niz& temp) {
		bool state = true;
		for (int i = 0; i < vektor.size(); i++) {
			for (int j = 0; j < temp.vektor.size(); j++) {
				if (vektor[i] > temp.vektor[j]) {
					state = false;
					break;
				}
			}
		}
		return state;
	}
};
template <class T>
bool Niz<T>::operator<(const Niz<T>& temp) {
	return manje_od(temp);
}

int main() {

	vector<int> v1 = { 1, 2, 3 };

	vector<int> v2 = { 11, 12, 13 };

	Niz<int> p1(v1);

	Niz<int> p2(v2);

	cout << (p1 < p2) << endl;  // operator <


	return 0;
}