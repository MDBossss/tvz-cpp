Na natjecanju iz programiranja sudjeluju različiti tipovi studenata, a ovo su njihove karakteristike: 

Studenti stručnih studija - ukupan prosjek ocjena: 4.7 Studenti specijalističkih studija - ukupan prosjek ocjena: 4.6. od čega najviše ima studenata specijalističkog studija informatike sa ukupnim prosjekom ocjena 4.8. 

a) Sukladno navedenoj specifikaciji deklarirajte sve potrebne klase i prikažite ispravan model nasljedivanja. 

b) Svaki student ima svoj ``JMBAG`` koji treba inicijalizirati kontruktorom glavne bazne klase koja u konačnici mora biti realizirana kao apstraktna klasa. U funkciji main kreirajte novi objekt tipa `SpecStudent` sa proizvoljnim JMBAG-om. 

c) Svaki od studenata podrazumijevano ima podatak o nazivu smjera, a on se vraća pozivom metode `GetSmjerinfo()` Za sve studente ova metoda podrazurilevano treba vratiti "Nepoznato". U klasama `StrucStudent` `SpecStudent` implementirajte nadredenje (eng. override) te metode tako da vraćaju "Opci smjer" za klasu `StrucStudent` te "Programsko inzenjerstvo" za klasu `SpecStudent`. Demonstrirajte pozive nadredenih metoda u funkciji main. 

d) Napišite globalnu funkciju ```double UkupniProsjek(vector<Student, natjecanje); ```
koja treba vratiti ukupnu prosječnu ocjenu svih studenata u predanom vektoru. U funkciji main testirajte i demonstrirajte poziv ove funkcije tako da u vektor smjestite adrese barem 3 objekta (studenta) različitog tipa. Napomena: u funkciji `UkupniProsjek` potrebno je demonstrirati polimorfizam prilikom dohvata prosječne ocjene pojedinog tipa studenta. 

e) U funkciji main dodajte sljedeću pretvorbu na više: `Student* s = new StrucStudent("123456"); `
Prilikom dealokacije pokazivača 's potrebno je da se prvo izvrši destruktor klase `StrucStudent`. a zatim i destruktor klase `Student`. Demonstrirajte u funkciji main. 
