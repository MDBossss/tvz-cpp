#include <iostream>
#include <vector>

using namespace std;

class Racunalo {
public:
    string os;
    virtual string getTip() = 0;
    Racunalo(string _os):os(_os){}
};

class Tablet : public Racunalo {
public:
    Tablet(string _os):Racunalo(_os){}
    string getTip() {
        return "Tablet";
    }
};

class Laptop : public Racunalo {
public:
    Laptop(string _os):Racunalo(_os){}
    string getTip() {
        return "Laptop";
    }
};

void AnalizaUcionice(vector<Racunalo*> v,int *brTableta,int *brLaptopa,int *brAndroida,int *brWindowsa,int *brLinuxa) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getTip() == "Tablet") {
            (*brTableta)++;
        }
        if (v[i]->getTip() == "Laptop") {
            (*brLaptopa)++;
        }
        if (v[i]->os == "Android") {
            (*brAndroida)++;
        }
        if (v[i]->os == "Windows") {
            (*brWindowsa)++;
        }
        if (v[i]->os == "Linux") {
            (*brLinuxa)++;
        }
    }
}

int main() {
    int brTableta = 0, brLaptopa = 0;
    int brAndroida = 0, brWindowsa = 0, brLinuxa = 0;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);



    cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala:" << endl;
    cout << "Broj tablet racunala: " << brTableta << endl;
    cout << "Broj laptop racunala: " << brLaptopa << endl;
    cout << "Android OS: " << brAndroida << endl;
    cout << "Windows OS: " << brWindowsa << endl;
    cout << "Linux OS: " << brLinuxa << endl;
    /* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    */
    return 0;
}
