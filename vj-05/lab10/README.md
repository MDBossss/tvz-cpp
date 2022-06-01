1. napisi lamba funkciju za zamjenu varijabli bilo kakav prijenos
int a=2;
int b=3;
*lamba*
cout<<a<<b;

2. napisi predlozak klase koja ima vektor te metodu/funkc koja vraca samo neparne elemente

3. napisi predlozak klase Red i metode za dodavanje i oduzimanje zadnjih elemenata te int brElemenata koji ispisuje koliko ih je trenutno u redu

4. napisi funkciju koja iz vektora ispisuje samo dvoznamenkaste
npr vector<int> vektor = 10,4,123,23 itd
vector<int> v2;
v2=funkcija(vektor, *lambda izraz*);





5.Napišite program za pretraživanje gradova tako da radi kako je ispod prikazano.

int main() {
    vector<Grad> v = { Grad("Zagreb", 900000, "Hrvatska"),
                        Grad("Berlin", 2500000, "Njemacka"),
                        Grad("Graz", 1200000, "Austrija"),
                        Grad("Frankfurt", 2300000, "Njemacka") };

    // nađi sve gradove u Njemackoj
    vector<Grad*> r = nadji(v, [](Grad* s) { return s->drzava() == "Njemacka"; });

    /* Ispisuje
        Berlin 2500000 Njemacka
        Frankfurt 2300000 Njemacka
    */
    for (Grad* p : r) {
        cout << p->ime() << " " << p->populacija() << " " << p->drzava() << endl;
    }

    return 0;
}
