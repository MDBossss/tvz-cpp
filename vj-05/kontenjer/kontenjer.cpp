#include <iostream>
#include <vector>


using namespace std;

template <class T>
class Polje {
public:
	int n;
	T* polje;
	Polje(int _n):n(_n){
		polje = new T[n];
	}
	~Polje() {
		delete[] polje;
	}

	T& operator [](int indeks);
	T Sadrzi(T temp) {
		int lok = -1;
		for (int i = 0; i < n; i++) {
			if (polje[i] == temp) {
				lok = i;
			}
		}
		return lok;
	}
};

template <class T>
T& Polje<T>::operator[](int indeks) {
	return polje[indeks];
}

int main() {

	Polje<int> A(100);
	// inicijalizacija elemenata slučajnim vrijednostima 1-100
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
		A[i] = rand() % 100 + 1; // A.polje[i] ...
		// ispiši broj elemenata
	cout << "Polje ima " << A.n << " elemenata " << endl;
	// da li se u polju nalazi broj x?
	int x = 58;
	int indeks = A.Sadrzi(x);
	if (indeks != -1)
		cout << "Broj " << x << " se nalazi u elementu s indeksom " << indeks << "!\n";
	else
		cout << "Broj " << x << " se ne nalazi u polju!\n";

	return 0;
}