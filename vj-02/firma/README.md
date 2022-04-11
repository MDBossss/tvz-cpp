Napraviti klasu Firma sa sljedećim (privatnim) poljima:

naziv
OIB
Adresa sjedišta
Omogućiti korisniku kreiranje nove firme i postavljanje naziva, OIBa i adrese sjedišta. Treba pripaziti na sljedeća pravila:

Naziv mora biti barem 5 znakova – ako je manji, odustati od postavljanja naziva i ispisati poruku korisniku
OIB mora biti od točno 11 znamenki. Ukoliko pravilo nije zadovoljeno, odustati od postavljanja vrijednosti, i ispisati poruku korisniku
Sve provjere pravila je potrebno napraviti unutar klase Firma. Gdje?

Dodati klasu Zaposlenik s nekoliko proizvoljnih polja (ime, prezime,...). Neka klasa Zaposlenik ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Zaposlenik constructor called“ korisniku, te jedan destruktor u kojem treba ispisati "Zaposlenik destructor called" korisniku. Proširiti klasu Firma s poljem vector<Zaposlenik> i dodati u klasu Firma metode:

dodajZaposlenika1(Zaposlenik z)
dodajZaposlenika2(Zaposlenik& z)
dodajZaposlenika3(Zaposlenik* z) 
Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? Zašto se ispisuje više puta destruktor nego konstruktor?

Dodati u klasu Firma metodu „ispisSvihZaposlenika“.

Dodati u klasu Firma metode:

Zaposlenik nadjiZaposlenika1(string ime, string prezime)
Zaposlenik* nadjiZaposlenika2(string ime, string prezime)
Zaposlenik& nadjiZaposelnika3(string ime, string prezime)
Koristeći nadjiZaposlenika1 naći i zatim izmjeniti podatke o jednom zaposleniku, a zatim koristeći metodu nadjiZaposlenika2 naći i zatim izmjeniti podatke o drugom zaposleniku i koristeći metodu nadjiZaposlenika3 naći i zatim izmjeniti podatke o trećem zaposleniku. Pozvati „ispisSvihZaposlenika“ za firmu. Što zapažate?

Koje su prednosti a koji nedostaci u načinima pozivanja metoda s objektima kao parametrima i vraćanja objekata kao vrijednosti iz funkcije? Kada koristiti jedan način a kada drugi?
