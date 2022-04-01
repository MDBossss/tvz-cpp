Vlasnik ste niza garaža u velegradu Zagrebu i iznajmljujete ih za razumnu cijenu, i već vam je pomalo nespretno voditi evidenciju o tome koje sve garaže postoje i tko ima koje ključeve, pa ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz garaža, i u svakoj garaži bilježiti niz ključeva koji su vaši (kako vam ne bi nestali).

Klasa Garaza ima sljedeća svojstva:<br/>

veličinu (širina x duljina)<br/>
cijenu iznajmljivanja<br/>
lokaciju<br/>
niz ključeva koji su vaši<br/>


Klasa Kljuc ima sljedeća svojstva:<br/>

ime i prezime osobe kod koje je ključ<br/>
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N garaža. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj ključeva, te je potrebno unijeti tih M ključeva (neka garaža može imati više ključeva).

Primjer izvođenja:<br/>
```
Unesite broj garaža (N):2
 Unesite velicinu, lokaciju i cijenu za 1. garazu:
 10 20
 Konavoska 3
 500
 Unesite velicinu, lokaciju i cijenu 2. garazu:
 15 25
 Konavoska 3b
 440
 Unesite broj kljuceva (M): 1
 Unesite redni broj garaze kojoj pripada 1. kljuc: 2
 Unesite ime vlasnika kljuca: Ana Anic
 
 Ispis garaza i kljuceva:
 1. Konavoska 3 10x20 - kljucevi:
 2. Konavoska 3b 15x25 - kljucevi: Ana Anic
