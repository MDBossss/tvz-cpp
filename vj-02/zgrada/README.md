Napraviti klasu Zgrada sa sljedećim (privatnim) poljima:

naziv građevinske firme
broj katova
adresa
Omogućiti korisniku kreiranje nove zgrade i postavljanje naziva građ. firme, broja katova i adrese. Treba pripaziti na sljedeća pravila:

Naziv firme mora biti barem 5 znakova – ako je manji, odustati od postavljanja naziva i ispisati poruku korisniku
Broj katova mora biti veći od 0. Ukoliko pravilo nije zadovoljeno, odustati od postavljanja vrijednosti, i ispisati poruku korisniku
Sve provjere pravila je potrebno napraviti unutar klase Zgrada. (Gdje?)

Dodati klasu Stan s nekoliko proizvoljnih polja (vlasnik, velicina, koliko soba, ...). Neka klasa Stan ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Stan constructor called“ korisniku, te jedan destruktor u kojem treba ispisati "Stan destructor called" korisniku. Proširiti klasu Zgrada s poljem vector<Stan> i dodati u klasu Zgrada metode:

dodajStan1(Stan z)
dodajStan2(Stan& z)
dodajStan3(Stan* z) 
Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? Zašto se ispisuje više puta destruktor nego konstruktor?

Dodati u klasu Zgrada metodu „ispisSvihStanova“.

Dodati u klasu Zgrada metode:

Stan nadjiStan1(string vlasnik)
Stan* nadjiStan2(string vlasnik)
Stan& nadjiStan3(string vlasnik)
Koristeći nadjiStan1 naći i zatim izmjeniti podatke o jednom stanu, a zatim koristeći metodu nadjiStan2 naći i zatim izmjeniti podatke o drugom stanu, te koristeći metodu nadjiStan3 naći i zatim izmjeniti podatke o trećem stanu. Pozvati „ispisSvihStanova“ za zgradu. Što zapažate?

Koje su prednosti a koji nedostaci u načinima pozivanja metoda s objektima kao parametrima i vraćanja objekata kao vrijednosti iz funkcije? Kada koristiti jedan način a kada drugi?
