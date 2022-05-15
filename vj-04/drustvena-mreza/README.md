U zadatku je prema "pričici" potrebno definirati klase i njihovu međusobnu povezanost po vlastitoj procjeni. Imati na umu da je potrebno definirati barem jedno nasljeđivanje.

Implementirate društvenu mrežu koja će nadmašiti facebook, sasvim sigurno. Da bi stvar bila što brža, upravo C++ ste odabrali za razvoj središnjeg dijela aplikacije. Krećete od izrade klasa. Prvo čime se bavite je objavljivanje sadržaja na mreži. Korisnici mogu objaviti sadržaj na svoj profil. Svaki korisnik ima osnovne podatke (ime, prezime, mail...), te niz sadržaja koje je objavio. Ima nekoliko tipova sadržaja koji se mogu objaviti - ono što im je zajedničko je da imaju datum i vrijeme objave, razinu privatnosti i korisnika koji je objavio sadržaj. U ovoj fazi potrebno je napraviti funkcionalnost za sadržaj koji je link na neku stranicu, no treba imati na umu da će se u kasnijim fazama projekta pojaviti ostali sadržaji. Uz podatke koji su zajednički svakom tipu sadržaja, ovaj sadržaj ima još url stranice, naslov koji će se prikazati i kratki opis. Potrebno je omogućiti prikaz top N sadržaja koje je korisnik objavio, na način da je najsvježiji sadržaj na vrhu, idući ispod, itd.

Način bodovanja

Program koji se ne prevodi uspješno ne može ostvariti više od 2 boda.

Barem 3 klase (smislene) - 1 bod
Članovi ne smiju biti javni - 1 bod
Barem jedan operator - 1 bod
Barem jedno nasljeđivanje (smisleno) - 1 bod
Demonstracija funkcionalnosti u main programu - 1 bod
Za dodatnih 2 boda, potrebno je implementirati i funkcionalnost povezanosti - svaki korisnik može biti povezan s nizom ostalih korisnika. Omogućiti korisnicima da dobiju listu top 3 drugih korisnika koje bi mogli poznavati a još nisu povezani s njima. Predložiti način utvrđivanja vjerojatnosti poznanstva i implementirati predloženo riješenje.
