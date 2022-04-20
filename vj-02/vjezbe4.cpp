#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Automobil
{
private:
    string proizvodac;
public:
    string gorivo;
    int cijena;
    void setPro(string _p)
    {
        _p.at(0) = toupper(_p.at(0));
        for (int i = 0; i < _p.size(); i++)
        {
            _p.at(i) = tolower(_p.at(i));
        }
        proizvodac = _p;
    }
    string getPro() const
    {
        return proizvodac;
    }
};

class AutoSalon
{
public:
    vector<Automobil*> polje;
    string naziv, adresa;
    AutoSalon(){}
    //KOPIRNI KONSTRUKTOR
    AutoSalon(const AutoSalon& tmp)
    {
        for (int i = 0; i < tmp.polje.size(); i++)
        {
            polje.push_back(new Automobil);
            polje[i] = tmp.polje[i];
        }
        naziv = tmp.naziv;
        adresa = tmp.adresa;
    }
    //OPERATOR PRIDRUZIVANJA SA DUBOKIM KOPIRANJEM
    AutoSalon& operator = (const AutoSalon& tmp)
    {
        if (this != &tmp)
        {
            for (int i = 0; i < polje.size(); i++)
            {
                delete polje[i];
            }
            polje.clear();
            for (int i = 0; i < tmp.polje.size(); i++)
            {
                polje.push_back(new Automobil);
                polje[i] = tmp.polje[i];
            }
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }
    //OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
    AutoSalon& operator = (AutoSalon&& tmp) noexcept
    {
        if (this != &tmp)
        {
            for (int i = 0; i < polje.size(); i++)
            {
                delete polje[i];
            }
            polje.clear();
            for (int i = 0; i < tmp.polje.size(); i++)
            {
                polje.push_back(tmp.polje[i]);
                tmp.polje[i] = NULL;
            }
            naziv = tmp.naziv;
            adresa = tmp.adresa;
        }
        return *this;
    }
    //DESTRUKTOR
    ~AutoSalon() 
    {
        for (int i = 0; i < polje.size(); i++)
        {
            delete polje[i];
        }
        polje.clear();
    }
};

int main()
{
    AutoSalon A, C;
    AutoSalon B = A; //pozivanje kopirnog
    C = B; // operator pridruzivanja
    A = AutoSalon(); // operator pridruzivanja sa prijenosom
    return 0;
}
