U zadatku je prema "pričici" potrebno definirati klase i njihovu međusobnu povezanost po vlastitoj procjeni. Imati na umu da je potrebno definirati barem jedno nasljeđivanje.

Nadograđujete sustav koji se bavi informatizacijom poduzeća. Zaduženi ste za informatizaciju dokumenata. Trenutno je poznato da postoji nekoliko vrsta dokumenata. Za svaki dokument se zna da ima podatke o tome tko ga je napravio, datum i vrijeme nastanka dokumenta, te njegov jedinstveni broj (svaki dokument ima jedinstveni broj - string koji može sadržavati brojke, crtice "-" i slasheve "/" ). Vi ste zaduženi da napravite dokument koji predstavlja otpremnicu. Otpremnica, uz osnovne podatke koje ima svaki dokument, ima također naziv skladišta i lokaciju skladišta. Otpremnica ima niz stavki. Svaka stavka sadrži podatak o količini otpremljenog materijala, jediničnoj cijeni, jediničnoj težini i nazivu. Za otpremnicu se također mora znati kolika je ukupna težina otpremljenih stavki. Otpremnica mora imati mogućnost smanjenja količine svih elemenata, na način da se postotak smanjenja primijeni na svaku stavku (primjerice, ako je ukupna težina 10tona, a kamion može odvesti samo 7t, potrebno je smanjiti svaku stavku za 30%). Također, otpremnica se mora moći ispisati (zajedno sa svim podacima i stavkama).

Način bodovanja

Program koji se ne prevodi uspješno ne može ostvariti više od 2 boda.

Barem 3 klase (smislene) - 1 bod
Članovi ne smiju biti javni - 1 bod
Barem jedan operator - 1 bod
Barem jedno nasljeđivanje (smisleno) - 1 bod
Demonstracija funkcionalnosti u main programu - 1 bod
Za dodatnih 2 boda, potrebno je implementirati i obračunavanje škarta -gdje je za svaku stavku potrebno izraziti očekivani škart (očekivani škart je uvijek 5%). Svaka količina se zaokružuje na 2 decimale, tako da treba imati na umu problem zaokruživanja - naime, ukupna suma stavki na otpremnici * 5% mora biti jednako sumi očekivanog škarta za svaku stavku. (primjer: ukupna težina = 9,90t; škart = 0,50t. Međutim, otpremnica se odnosi na 9 elemenata po 1,10t (škart=0,06 za svaku stavku), što daje sumu od 0,54t). Predložiti i implementirati rješenje problema.
