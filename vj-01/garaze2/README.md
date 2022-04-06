Vlasnik ste niza garaža u velegradu Zagrebu i iznajmljujete ih za razumnu cijenu, i već vam je pomalo nespretno voditi evidenciju o tome koje sve garaže postoje i koje predmete imate u njima, pa ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz garaža, i u svakoj garaži bilježiti niz predmeta koji su vaši (kako vam ne bi nestali).

Klasa Garaza ima sljedeća svojstva:

veličinu (širina x duljina)
podatak o tome jesu li vrata s automatskim upravljanjem ili ne
lokaciju
niz predmeta koji su vaši


Klasa Predmet ima sljedeća svojstva:

naziv
vrijednost
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N garaža. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj predmeta koji spadaju u garaže, te je potrebno unijeti tih M predmeta (neka garaža može imati više predmeta)

Primjer izvođenja:
```
Unesite broj garaža (N):2
 Unesite velicinu, lokaciju i podatak o vratima za 1. garazu:
 10 20
 Konavoska 3
 DA
 Unesite velicinu, lokaciju i podatak o vratima za 2. garazu:
 15 25
 Konavoska 3b
 NE
 Unesite broj predmeta (M): 1
 Unesite redni broj garaze u koju spada 1. predmet: 2
 Unesite naziv i vrijednost predmeta: Lopta 400
 
 Ispis garaza i predmeta:
 1. Konavoska 3 10x20 - predmeti:
 2. Konavoska 3b 15x25 - predmeti: Lopta (400kn)
