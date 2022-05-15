Potrebno je napraviti ispravne klase kako bi donji programski odsječak funkcionirao ispravno. Potrebno je modelirati nasljeđivanje,te osigurati da postoji apstraktna klasa u modelu (ispravno odabrati metodu koja je čista virtualna).

Dodatno, plaća za se računa na način da se osnovici plaće pribroje bonusi:

za igrača, svaki 10. gol donosi 10% osnovice kao bonus; dok svaka 5. asistencija donosi isto 10% osnovice kao bonus
za trenera, svaka 5. pobjeda donosi bonus od 10% osnovice, svaki 10. remi (nerijeseno) donosi isto 10% osnovice, dok se za svaki 8. poraz skida 10% osnovice
za detalje, pogledati primjere ispisa koda
```
int main()
{
Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
i.dodajGolove(7);
i.dodajAsistencije(12);
i.ispis(); //Luka Modric - golova: 7, asistencija: 12
cout << "Placa: " << i.izracunPlace() << endl; //Placa: 120000

Igrac i2("C", "Ronaldo", 234505);
i2.dodajGolove(57);
i2.dodajAsistencije(32);
i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
cout << "Placa: " << i2.izracunPlace() << endl; //Placa : 492461

Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
t1.dodajPobjede(88); //Dodati broj pobjeda (W)
t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

t1.dodajPobjede(11);
t1.dodajIzgubljene(47);
t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523

}
```


Demonstrirajte polimorfizam u funkciji main.
