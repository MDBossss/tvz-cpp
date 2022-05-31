#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Niz {
public:
	vector<T> polje;
	Niz(vector<T> _polje):polje(_polje){}

	bool manje_od(const Niz& temp) {
		for (int i = 0; i < polje.size(); i++) {
			for (int j = 0; j < temp.polje.size(); j++) {
				if (polje[i] > temp.polje[i]) {
					cout << "false\n";
					return false;
					break;
				}
			}
		}
		cout << "true\n";
		return true;
	}
	bool operator <(const Niz& temp);
	bool operator >=(const Niz& temp);
};

template <class T>
class Niz2 {
public:
	vector<T> polje;
	Niz2(vector<T> _polje) :polje(_polje) {}

	bool manje_od(const Niz2& temp) {
		for (int i = 0; i < polje.size(); i++) {
			for (int j = 0; j < temp.polje.size(); j++) {
				if (polje[i] > temp.polje[i]) {
					cout << "false\n";
					return false;
					break;
				}
			}
		}
		cout << "true\n";
		return true;
	}
	bool operator <(const Niz2& temp) {
		return manje_od(temp);
	}
};

template<class T>
bool Niz<T>::operator<(const Niz& temp) {
	return manje_od(temp);
}

template<class T>
bool Niz<T>::operator>=(const Niz& temp) {
	if (manje_od(temp) == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 11,0,13 };

	Niz<int> p1(v1);
	Niz<int> p2(v2);

	cout << (p1 < p2) << endl;  // operator <

	return 0;
}
