Za klasu Pijesak napišite konstruktore i operatore pridruživanja s semantikom kopiranja i semantikom prijenosa. U funkciji main demonstrirajte njihove pozive.

 
```
#include <iostream>

#include <string>

using namespace std;

 

class Zrno{

public:

       string boja;

       float promjer;

};

class Pijesak{

public:

       int kolicina;

       Zrno* zrno;

       Pijesak(int _kolicina) : kolicina(_kolicina){

             // dinamički alocirajte polje 'zrno'

       }

       ~Pijesak(){

             // ?

       }

};

int main(){

       Pijesak igraliste(1000000);

       cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

 

       // Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja

       return 0;

}
