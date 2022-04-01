Vlasnik ste koncerna za iznajmljivanje pedalina diljem Jadrana. Imate niz lokacija na kojima iznamljujete, te vam je već pomalo nespretno voditi evidenciju o tome gdje su koje pedaline te ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz lokacija gdje iznamljujete, i za svaku lokaciju bilježiti koje pedaline iznamljujete (kako vam ne bi nestale).

Klasa Lokacija ima sljedeća svojstva:<br/>

ime i prezime odgovorne osobe<br/>
GPS koordinate (double X i double Y)<br/>
niz predmeta koji su dostupni<br/>


Klasa Pedalina ima sljedeća svojstva:<br/>

boja<br/>
kapacitet<br/>
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N lokacija. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj pedalina, te je potrebno unijeti tih M pedalina (neka lokacija može nuditi više pedalina).

Primjer izvođenja:
```
Unesite broj lokacija (N):2
 Unesite odgovornu osobu i GPS koordinate za 1. lokaciju:
 Pero Jankovic
 43.346216 16.734324
 Unesite odgovornu osobu i GPS koordinate za 2. lokaciju:
 Danko Stankovic
 43.246216 16.834324
 Unesite broj pedalina (M): 1
 Unesite redni broj lokacije kojoj pripada 1. pedalina: 2
 Unesite boju i kapacitet pedaline: Crvena 7
 
 Ispis lokacija i pedalina:
 1. 43.346216 16.734324 Pero Jankovic – pedaline:
 2. 43.246216 16.834324 Danko Stankovic – pedaline: Crvena (7)
