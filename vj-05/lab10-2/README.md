1.	Napišite predložak funkcije "NeparniElementi" koji prima vektor podataka bilo kojeg tipa, a vraća samo neparne elemente tog vektora.
2.)Potrebno je nadopuniti donji programski odsječak na način da napišete funkciju "izdvoji", za koju vrijedi sljedeće:
•	vraća vector<int> (novi vektor)
•	prvi argument: vector<int>&
•	drugi argument: funkcija
Funkcija izdvoji mora iz vektora "brojevi" izdvojiti samo one brojeve koji nisu djeljivi s 2, 3 ni 5. Drugi argument funkcije potrebno je poslati kao lambda izraz (nadopuniti).
int main()
{
vector<int> brojevi = {1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42};
vector<int> rez = izdvoji(brojevi, /*lambda izraz*/);
for (int i = 0; i < rez.size(); i++)
cout << rez[i] << " ";
//ispis: 1 7 23 1 1 433 7 433
}
3.) Napišite predložak klase Kalkulator koja u sebi treba sadržavati dva podatka različitog (korisnički definiranog) tipa. Klasa treba sadržavati metodu Zbroj koja vraća sumu ta dva podatka. Metodu Zbroj implementirajte van klase.

4) Napišite lambda funkciju za zamjenu dvije varijable. Samostalno odrediti način prijenosa.
int a = 10, b = 99;
//lambda...
cout << a << " " << b << endl; //99 10

5) Napišite program za pretraživanje studenata tako da radi kako je ispod prikazano.

int main() {
	vector<Student> v = {Student("Pero", "Peric", "3882"),
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
