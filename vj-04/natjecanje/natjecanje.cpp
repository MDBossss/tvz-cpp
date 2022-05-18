#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
	string jmbag;
	Student(string _jmbag):jmbag(_jmbag){}

	virtual string GetSmjerInfo() {
		return "Nepoznato\n";
	}

	virtual float GetProsjek() = 0;

	virtual ~Student() {
		cout << "Student destruktor" << endl;
	}
};

class StrucStudent : public Student {
public:
	float prosjek = 4.7;
	StrucStudent(string _jmbag):Student(_jmbag){}

	string GetSmjerInfo() {
		return "Opci smjer\n";
	}

	float GetProsjek() {
		return prosjek;
	}

	~StrucStudent() {
		cout << "StrucStudent destruktor" << endl;
	}
};

class SpecStudent : public Student {
public:
	float prosjek = 4.6;
	SpecStudent(string _jmbag):Student(_jmbag){}
	
	string GetSmjerInfo() {
		return "Programsko inzenjerstvo\n";
	}

	float GetProsjek() {
		return prosjek;
	}

	~SpecStudent() {
		cout << "SpecStudent destruktor" << endl;
	}
};

class Informatika : public SpecStudent {
public:
	float prosjek = 4.8;
	Informatika(string _jmbag):SpecStudent(_jmbag){}

	float GetProsjek() {
		return prosjek;
	}

	~Informatika() {
		cout << "Informatika destruktor" << endl;
	}
};

double UkupniProsjek(vector<Student*> natjecanje) {
	float sum = 0;
	for (int i = 0; i < natjecanje.size(); i++) {
		sum += natjecanje[i]->GetProsjek();
	}
	return sum / natjecanje.size();
}

int main() {

	SpecStudent s1("0246039234");
	Student* s(&s1);
	cout << s->GetSmjerInfo();

	//ili

	Student* s2 = new SpecStudent("03492039593");
	cout << s2->GetSmjerInfo() << endl;

	Student* s3 = new StrucStudent("0019389395");


	SpecStudent n1("094830013");
	Informatika n2("905893293");
	StrucStudent n3("043090103");

	vector<Student*> v = { &n1,&n2,&n3 }; // pretvorba na vise
	cout << UkupniProsjek(v) << endl;

	Student* ns = new StrucStudent("123456");
	delete ns;

	return 0;
}