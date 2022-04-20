#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
	string ime, jmbag;
	int brojBodova;
	Student(){}
	Student(string _ime,string _jmbag):ime(_ime),jmbag(_jmbag){}
};

class Kolegij {
public:
	vector<Student*> student;
	Kolegij(){}


	void dodaj(Student* s) {
		student.push_back(s);
	}

	//------------kopirni--------//
	Kolegij(const Kolegij& k) {
		for (int i = 0; i < k.student.size(); i++) {
			student.push_back(new Student(k.student[i]->ime, k.student[i]->jmbag));
			student[i]->brojBodova = k.student[i]->brojBodova;
		}
	}

	Kolegij& operator = (const Kolegij& k) {
		if (this != &k) {
			for (int i = 0; i < student.size(); i++) {
				delete student[i];
			}
			student.clear();
			for (int i = 0; i < k.student.size(); i++) {
				student.push_back(new Student(k.student[i]->ime, k.student[i]->jmbag));
				student[i]->brojBodova = k.student[i]->brojBodova;
			}
		}
		return *this;
	}


	//---------prijenosni--------//
	Kolegij(Kolegij&& k) {
		for (int i = 0; i < student.size(); i++) {
			delete student[i];
		}
		student.clear();
		for (int i = 0; i < student.size(); i++) {
			student.push_back(k.student[i]);
			k.student[i] = NULL;
		}
	}

	Kolegij& operator = (Kolegij&& k) {
		for (int i = 0; i < student.size(); i++) {
			delete student[i];
		}
		student.clear();
		for (int i = 0; i < student.size(); i++) {
			student.push_back(k.student[i]);
			k.student[i] = NULL;
		}
		return *this;
	}

	~Kolegij() {
		for (int i = 0; i < student.size(); i++) {
			delete student[i];
		}
	}
};

int main() {
	Kolegij OOP;
	OOP.dodaj(new Student("Ante Antic", "02460123456"));
	OOP.dodaj(new Student("Ivica Ivic", "02460567890"));

	Kolegij OOP2 = OOP;
	OOP.student[0]->brojBodova = 10;
	OOP2.student[0]->brojBodova = 20;
	cout << OOP.student[0]->brojBodova << endl; // 10
	cout << OOP2.student[0]->brojBodova << endl; // 20

	Kolegij Java;
	Java = OOP2;
	OOP2.student[0]->brojBodova = 10;
	Java.student[0]->brojBodova = 20;
	cout << OOP2.student[0]->brojBodova << endl; // 10
	cout << Java.student[0]->brojBodova << endl; // 20




	return 0;
}
