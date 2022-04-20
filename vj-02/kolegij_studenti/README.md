Potrebno je napisati program za evidenciju studenata na određenom kolegiju. Student ima ime, jmbag i broj bodova na tom kolegiju, dok svaki kolegij ima popis studenata koji slušaju predavanja. Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.
```
int main(){
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
```
U klasi Kolegij deklarirajte i implementirajte operator pridruživanja s semantikom prijenosa, a u funkciji main demonstrirajte njegov poziv.
