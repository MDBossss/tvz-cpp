Definirajte potrebne dijelove da bi funkcija "main" radila kako je opisano.
Klase Filter, FilterVeciOd i FilterManjiOd trebaju "filtrirati" vrijednosti
prema zadanom parametru.


```
class Filter {
public:
    virtual vector<int> uvjet(vector<int> vec) final {
        vector<int> rezultat;
        for (int element : vec) {
            if (provjera(element)) {
                rezultat.push_back(element);
            }
        }
        return rezultat;
    }

    virtual bool provjera(int element) = 0;
};

int main() {
    vector<int> v = {14, 3, 18, 5, 6, 10, 2, 8, 1, 7};

    Filter* filter = new FilterVeciOd(5);        // propusti samo vrijednosti vece od 5
    vector<int> rezultat = filter->uvjet(v);
    cout << rezultat;        // ispisuje 14 18 6 10 8 7
    delete filter;

    filter = new FilterManjiOd(5);        // propusti samo vrijednosti manje od 5
    rezultat = filter->uvjet(v);
    cout << rezultat;        // ispisuje 3 2 1
    delete filter;

    return 0;
}
