U zadatku je prema "pričici" potrebno definirati klase i njihovu međusobnu povezanost po vlastitoj procjeni. Imati na umu da je potrebno definirati barem jedno nasljeđivanje.

Nadograđujete sustav koji se bavi informatizacijom poduzeća. Zaduženi ste za informatizaciju dokumenata. Trenutno je poznato da postoji nekoliko vrsta dokumenata. Za svaki dokument se zna da ima podatke o tome tko ga je napravio, datum i vrijeme nastanka dokumenta, te njegov jedinstveni broj (svaki dokument ima jedinstveni broj - string koji može sadržavati brojke, crtice "-" i slasheve "/" ). Vi ste zaduženi da napravite dokument koji predstavlja račun. Račun, uz osnovne podatke koje ima svaki dokument, ima također JIR i tip računa (R1 ili obični). Račun ima niz stavki. Svaka stavka sadrži podatak o nazivu usluge koja je napravljena, količinu i jediničnu cijenu. Za račun se također mora znati kolika je ukupna suma njegovih stavki. Račun mora imati mogućnost obračunavanja popusta, na način da se postotak popusta primijeni na svaku stavku. Također, račun se mora moći ispisati (zajedno sa svim podacima i stavkama).

Način bodovanja

Program koji se ne prevodi uspješno ne može ostvariti više od 2 boda.

Barem 3 klase (smislene) - 1 bod
Članovi ne smiju biti javni - 1 bod
Barem jedan operator - 1 bod
Barem jedno nasljeđivanje (smisleno) - 1 bod
Demonstracija funkcionalnosti u main programu - 1 bod
Za dodatnih 2 boda, potrebno je implementirati i obračunavanje PDV-a -gdje je za svaku stavku potrebno izraziti PDV. Imati na umu problem zaokruživanja - naime, ukupna suma računa * 25% mora biti jednako sumi PDV-a za svaku stavku. (primjer: ukupna suma = 9,90kn; PDV = 2,48kn. Međutim, račun ima 9 stavki po 1,10kn (PDV=0,28 za svaku stavku), što daje sumu od 2,52kn). Predložiti i implementirati rješenje problema.
