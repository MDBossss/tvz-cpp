#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
vector<T> NeparniElementi(vector<T> v) {
	vector<T> temp;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 != 0) {
			temp.push_back(v[i]);
		}
	}
	return temp;
}

template<class T1, class T2>
class Kalkulator {
public:
	T1 a = 10;
	T2 b = 33.333;
	auto Zbroj();

};

template<class T1, class T2>
auto Kalkulator<T1, T2>::Zbroj() {
	return a + b;
}

class Student {
public:
	string ime1, prezime1, jmbag1;
	Student(string _ime,string _prezime,string _jmbag):ime1(_ime),prezime1(_prezime),jmbag1(_jmbag){}

	string ime() {
		return ime1;
	}

	string prezime() {
		return prezime1;
	}

	string jmbag() {
		return jmbag1;
	}
};

vector<Student*> nadji(vector<Student>& v, function<bool(Student*)> kriterij) {
	vector<Student*> temp;
	for (int i = 0; i < v.size(); i++) {
		if (kriterij(&v[i])) {
			temp.push_back(&v[i]);
		}
	}
	return temp;
}

vector<int> izdvoji(vector<int> v, function<bool(int)> kriterij) {
	vector<int> temp;
	for (int i = 0; i < v.size(); i++) {
		if (kriterij(v[i])) {
			temp.push_back(v[i]);
		}
	}
	return temp;
}

int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };
	vector<int> rez = izdvoji(brojevi, [](int n) {return ((n % 2) && (n % 3) && (n % 5)); });
	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 1 7 23 1 1 433 7 433

	Kalkulator<int, float> k;
	cout << k.Zbroj() << endl;

	int a = 10, b = 99;
	[&a,&b]() {
		int temp = a;
		a = b;
		b = temp;
	}();

	cout << a << " " << b << endl; //99 10

	vector<Student> v = { Student("Pero", "Peric", "3882"),
		Student("Ivo", "Ivic", "10991"),
		Student("Mara", "Maric", "40911"),
		Student("Ivan", "Juric", "93877"),
		Student("Ivo", "Kalic", "20991")
	};

	// nađi sve studente koji se zovu Ivo
	vector<Student*> r = nadji(v, [](Student* s) { return s->ime() == "Ivo"; });

	// ispisuje Ivo Ivić 10991 i Ivo Kalic 20991
	for (Student* s : r) {
		cout << s->ime() << " " << s->prezime() << " " << s->jmbag() << endl;
	}




	return 0;
}