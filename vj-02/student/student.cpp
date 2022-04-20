#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
	char* jmbag;
public:
	Student() {}
	Student(char* _jmbag){
		jmbag = new char[11];
		strcpy_s(jmbag, 11, _jmbag);
	}
	~Student() {
		delete[] jmbag;
	}

	void SetJMBAG(char* noviJmbag) {
		strcpy_s(jmbag, 11, noviJmbag);
	}

	char* GetJMBAG() const {
		return &jmbag[0];
	}

	Student(Student& temp) {
		jmbag = new char[11];
		strcpy_s(jmbag, 11, temp.GetJMBAG());
	}

	Student operator = (const Student& temp) {
		if (this != &temp) {
			jmbag = new char[11];
			strcpy_s(jmbag, 11, temp.GetJMBAG());
		}
		return *this;
	}
};

int main() {

	Student Ante("1122334455");
	Student Ivica = Ante;

	Ante.SetJMBAG("6677889900");
	cout << Ante.GetJMBAG() << endl;  // 6677889900
	cout << Ivica.GetJMBAG() << endl; // 6677889900 ?!?!

	Student Marko;
	Marko = Ante;
	Marko.SetJMBAG("1234567890");
	cout << Marko.GetJMBAG() << endl; // 1234567890
	cout << Ante.GetJMBAG() << endl;  // 1234567890 ?!?!



	return 0;
}