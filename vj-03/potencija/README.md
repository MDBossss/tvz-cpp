Deklarirajte klasu `PotencijaBroja` tako da su baza (broj) i njegova potencija u privatnom dijelu klase te se inicijaliziraju konstruktorom koji ima dva parametra. Zatim, realizirajte sljedeće: 

a) Ispišite koliko postoji potencija (objekata tipa PotencijaBroja) koji su se prilikom kreiranja tih objekata mogli predstavIti prirodnim brojevima (pozitivnim cijelim brojevima bez ostatka). Npr. potencija 16^1/4 (4. korjen od 16) mogla se predstaviti prirodnim brojem 2. U funkciji main ispisati traženu kolićinu pozivom metode `brojac` na sljedeči način: `cout « PotencijaBroja::brojac() « endl: `

b) U klasi PotencijaBroja deklarirajte metodu SetPotencija koja kao parametar ima realan broj. Ukoliko je potencija negativan broj metoda mora baciti iznimku tipa 'PotencijaBrojaException', a u protivnom potrebno je postaviti potenciju baze (broja) na zadanu vrijednost. Metodu SetPotencija implementirajte van klase a u funkciji main demonstrirajte njen poziv gdje se prilikom hvatanja iznimke treba izvršiti metoda `ispis` klase `PotencijaBrojaException`, koja će ispisati odgovarajuću poruku korisniku. 

c) Implementirajte operaciju zbrajanja dva objekta tipa PotencijaBroja kao nečlansku operatorsku funkciju koja kao rezultat vraća realan broj, te demonstrirajte njen poziv u funkciji main. Baza i potencija broja moraju ostati privatni u klasi PotencijaBroja. d) Implernentirajte prefiks i postfiks operatore unutar klase PotencijaBroja. Oba operatora trebaju uvećati potenciju broja za vrijednost 1. 

e) Preopteretite operatore `<<` i `>>` za ispis i unos objekata tipa PotencijaBroja. 
