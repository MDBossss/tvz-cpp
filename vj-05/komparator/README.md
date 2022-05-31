a) Napišite klasu "Komparator" koja ima jedan generički parametar T i metodu 

"vece_ili_jednako" koja ima dva parametra tipa T i koja vraća rezultat 

usporedbe tih dvaju parametara operacijom >=.



b) Napišite zaglavlje funkcije "usporedi" koja ima jedan generički parametar 

P koji označava tip elemenata u vektoru. Isto tako, funkcija treba imati dva 

parametra: prvi je vektor s elementima tipa P koje uspoređujemo (vector<P>), a 

drugi objekt klase "Komparator" koja radi s elementima tipa P (Komparator<P>). 



c) Upotrebom objekta tipa Komparator i njegove metode "vece_ili_jednako" 

funkcija "usporedi" treba vratiti 0 ako elementi u vektoru nisu poslagani 

u opadajućem redoslijedu, odnosno 1 ako jesu.



d) Upotreba funkcije "usporedi" treba izgledati ovako:



	vector<int> v = {12, 2, 1};

	bool r = usporedi<int>(v, Komparator<int>());

	cout << "rezultat: " << r << endl;  // treba ispisati 1



e) Implementirajte metodu "usporedi" tako da radi s bilo kojom klasom koja ima

metodu "vece_ili_jednako" povratnog tipa bool, s dva parametra (to jest, ne 

radi samo s klasom Komparator).
