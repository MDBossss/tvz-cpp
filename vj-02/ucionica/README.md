kopirni i prijenosni konstruktor, operatori =
U svakoj učionici (klasa Ucionica) se nalazi određen broja računala. Svako računalo (klasa Racunalo) ima svoj naziv, naziv procesora i količinu memorije. U učionici se ne zna unaprijed koliko računala će biti, pa se preko pokazivača i operatora new dinamički alocira potreban broj računala pri kreiranju svake učionice. Slijedeći programski kod u nastavku napišite sve potrebne klase, metode i funkcije koje su potrebne da bi funkcija main radila kao što je to i predviđeno.
```
int main(){
	// Učionica 'A' s 15 računala istih specifikacija
	Ucionica A(15, "Koncar", "Intel I5", "4 GB"); 
	// Učionica B ima također 15 računala istih specifikacija kao i učionica 'A'
	Ucionica B = A;	
	cout << B.brRacunala << endl; // 15
	// Računala iz učionice 'C' se prenose u  učionicu 'B'
	Ucionica C = move(B);
	cout << B.brRacunala << endl; // 0
	// Privremena ucionica se zatvara i njena racunala se prenose u ucionicu 'B'
	B = Ucionica(15, "Dell", "Intel I7", "8 GB");	
	return 0;
}
```
Također, u klasi Ucionica deklarirajte i implementirajte operator pridruživanja s semantikom kopiranja.

