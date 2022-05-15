#include <iostream>
#include <vector>

using namespace std;

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

class FilterVeciOd : public Filter {
public:
    int broj;
    FilterVeciOd(int _broj):broj(_broj){}

    bool provjera(int element) {
        if (element > broj) {
            return true;
        }
        return false;
    }
};

class FilterManjiOd : public Filter {
public:
    int broj;
    FilterManjiOd(int _broj):broj(_broj){}

    bool provjera(int element){
        if (element < broj) {
            return true;
        }
        return false;
    }
        
};

ostream& operator <<(ostream& cout, vector<int> temp) {
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    return cout;
}

int main() {
    vector<int> v = { 14, 3, 18, 5, 6, 10, 2, 8, 1, 7 };

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