a) Napišite klasu Niz s jednom generičkim parametrom koja se može instancirati

na sljedeći način:



	vector<int> v1 = {1, 2, 3};

	vector<int> v2 = {11, 0, 13};

	Niz<int> p1(v1);

	Niz<int> p2(v2);



b) Klasa Niz treba imati metodu "manje_od" s jednim parametrom tip const Niz& 

koja uspoređuje svoj niz (postavljen kod inicijalizacije) s nizom u parametru i 

vraća 1 ako su svi elementi vektora ovog objekta manji od svakog elementa 

vektora parametra, inače vraća 0.



c) Upotrebom predložaka napišite nečlanski operator < tako da taj operator 

vraća rezultat metode "manje_od" kao rezultat usporedbe. Na primjer,



	vector<int> v1 = {1, 2, 3};

	vector<int> v2 = {11, 0, 13};

	Niz<int> p1(v1);

	Niz<int> p2(v2);

	cout << (p1 < p2) << endl;  // operator <



d) Upotrebom predložaka napišite operator >= koji vraća 1 samo ako operator < 

vraća 0 za zadane parametre.



e) Napišite klasu Niz2 koja radi kao klasa Niz, s tim da je operator < 

definiran kao članska funkcija.
