#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class EPogresanBroj {
public:
	int broj;
	EPogresanBroj(int _broj):broj(_broj){}

	void ispis() {
		cout << broj << " je neispravan maticni broj!";
	}
};

class Autor {
private:
	int maticniBroj;
public:
	string ime, prezime;
	Autor(string _ime,string _prezime):ime(_ime),prezime(_prezime){}

	void setMaticniBroj(int temp) {
		try {
			if (temp > 0) {
				maticniBroj = temp;
			}
			else {
				throw EPogresanBroj(temp);
			}
		}
		catch (EPogresanBroj iznimka) {
			iznimka.ispis();
		}
	}

	int getMaticniBroj() {
		return maticniBroj;
	}
};

class Knjiga {
public:
	Autor* autor;
	string naziv, izdavac;
	Knjiga(string _naziv,string _izdavac):naziv(_naziv),izdavac(_izdavac){}

	/*prijenosni*/
	Knjiga(Knjiga&& temp) {
		delete[] autor;
		autor = temp.autor;
		temp.autor = NULL;
		naziv = temp.naziv;
		izdavac = temp.izdavac;
	}

	Knjiga& operator =(Knjiga&& temp) {
		if (this != &temp) {
			delete[] autor;
			autor = temp.autor;
			temp.autor = NULL;
			naziv = temp.naziv;
			izdavac = temp.izdavac;
		}
		return *this;
	}

	~Knjiga() {
		delete[] autor;
	}

	virtual string vrsta() {
		return "knjiga";
	}
};

class Skripta : public Knjiga {
public:
	Skripta(string _naziv,string _izdavac):Knjiga(_naziv,_izdavac){}
	string vrsta() {
		return "skripta";
	}
};

class Prirucnik : public Knjiga {
public:
	Prirucnik(string _naziv, string _izdavac) :Knjiga(_naziv, _izdavac) {}
	string vrsta() {
		return "prirucnik";
	}
};

class Udzbenik : public Knjiga {
public:
	Udzbenik(string _naziv, string _izdavac) :Knjiga(_naziv, _izdavac) {}
	string vrsta() {
		return "udzbenik";
	}
};

class Knjiznica {
public:
	/*kopirni*/
	vector<Knjiga*> knjiga;
	Knjiznica() {};
	Knjiznica(const Knjiznica& temp) {
		for (int i = 0; i < temp.knjiga.size(); i++) {
			knjiga.push_back(new Knjiga(temp.knjiga[i]->naziv,temp.knjiga[i]->izdavac));
		}
	}

	Knjiznica& operator =(Knjiznica& temp) {
		if (this != &temp) {
			for (int i = 0; i < knjiga.size(); i++) {
				delete[] knjiga[i];
			}
			knjiga.clear();
			for (int i = 0; i < temp.knjiga.size(); i++) {
				knjiga.push_back(new Knjiga(temp.knjiga[i]->naziv, temp.knjiga[i]->izdavac));
			}
		}
		return *this;
	}

	~Knjiznica() {
		for (int i = 0; i < knjiga.size(); i++) {
			delete[] knjiga[i];
		}
		knjiga.clear();
	}
};

class Kompleksni {
public:
	float re, im;
	Kompleksni() {};
	Kompleksni(float _re, float _im) :re(_re), im(_im){}

	Kompleksni operator*(Kompleksni& temp) {
		float realni, imaginarni;
		realni = re * temp.re - im * temp.im;
		imaginarni = re * temp.im + im * temp.re;
		return Kompleksni(realni, imaginarni);
	}
};

class Grad {
public:
	string naziv;
	int stanovnika;
	Grad(string _naziv,int _stanovnika):naziv(_naziv),stanovnika(_stanovnika){}
};

class anonimna {
public:
	bool operator()(Grad a, Grad b) const {
		return a.stanovnika > b.stanovnika;
	}
};

ostream& operator <<(ostream& cout, Knjiznica& temp) {
	for (int i = 0; i < temp.knjiga.size(); i++) {
		cout << temp.knjiga[i]->autor->ime << " " << temp.knjiga[i]->naziv << endl;
	}
	return cout;
}

void ispisVrsteKnjige(vector<Knjiga*> knjige) {
	for (int i = 0; i < knjige.size(); i++) {
		cout << knjige[i]->vrsta() << endl;
	}
}

template<class T1>
void mojPrint(T1 prvi) {
	cout << prvi;
}

template<class T1,class... Tostali>
void mojPrint(T1 prvi, Tostali... ostali) {
	mojPrint(ostali...);
	cout << prvi;
}



int main() {

	Autor autor("Marko", "Markic");
	autor.setMaticniBroj(-10); //greska

	Knjiznica knjiznica;
	Knjiga k1("Naziv1", "Marko");
	k1.autor = new Autor("Marko", "Markic");
	Knjiga k2("Naziv2", "Marko");
	k2.autor = new Autor("Marko", "Markic");
	Knjiga k3("Naziv3", "Marko");
	k3.autor = new Autor("Marko", "Markic");
	knjiznica.knjiga.push_back(&k1);
	knjiznica.knjiga.push_back(&k2);
	knjiznica.knjiga.push_back(&k3);
	cout << knjiznica << endl;

	//polimorfizam

	Skripta s1("skripta1","izdavac1");
	Prirucnik p1("prirucnik1","izdavac2");
	Udzbenik u1("udzbenik1","izdavac3");
	vector<Knjiga*> knjige = { &s1,&p1,&u1 };
	ispisVrsteKnjige(knjige);

	//kompleksni i 5 nacina koristenja lambbvda funkcije
	Kompleksni z1(0, 0);
	Kompleksni z2(1, -1);
	Kompleksni z3;

	z3 = [](Kompleksni z1, Kompleksni z2) {return z1 * z2; }(z1, z2); //predati kao parametar

	[&z3](Kompleksni z1, Kompleksni z2) {return z1 * z2; }(z1, z2); // predaja u klauzuli hvatanja

	[&]() {z3 = z1 * z2; }();

	[&z1, &z2, &z3]() {return z1 * z2; }();


	//gradovi
	int n;
	vector<Grad> gradovi;

	cout << "Unesite broj gradova : " << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string tempstring;
		int tempint;
		cout << "Unesite naziv grada i broj stanovnika: " << endl;
		cin >> tempstring >> tempint;
		gradovi.push_back(Grad(tempstring, tempint));
	}

	sort(gradovi.begin(), gradovi.end(), anonimna());

	for (int i = 0; i < n; i++) {
		cout << gradovi[i].naziv << " " << gradovi[i].stanovnika << endl;
	}

	//7. moj print - beskonacan ispis argumenata bilo kojeg tipa
	mojPrint(2); //2
	mojPrint(2, "D", 2.76); //2.76D2
	mojPrint(-1, "niz", 0.547, "X");//x0.547niz-1

	return 0;
}