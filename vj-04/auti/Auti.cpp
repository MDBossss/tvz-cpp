#include <iostream>
#include<vector>
#include<string>

using namespace std;

class Auto
{
public:
    string vozac;
    
    Auto(string vozac) : vozac(vozac){}

    virtual string GetOsiguranjeInfo()
    {
        return "Nepoznato";
    };
    virtual float getProsjek() = 0;
    virtual ~Auto()
    {
        cout << "Unisten je auto"<<endl;
    }
};

class AutoPrednjiPogon : public Auto
{
public:
    float prosjek = 1500;
    AutoPrednjiPogon(string vozac) : Auto(vozac){}

    string GetOsiguranjeInfo() override
    {
        return "Generali osiguranje";
    }

    float getProsjek()
    {
        return prosjek;
    }
    ~AutoPrednjiPogon()
    {
        cout << "Unisten je auto sa prednjim pogonom"<<endl;
    }

};

class AutoStraznjiPogon : public Auto
{
public:
    float prosjek = 1650;
    AutoStraznjiPogon(string vozac) : Auto(vozac) {}

    string GetOsiguranjeInfo() override
    {
        return "Euroherc";
    }

    float getProsjek()
    {
        return prosjek;
    }
    ~AutoStraznjiPogon()
    {
        cout << "Unisten je auto sa prednjim pogonom"<<endl;
    }

};

double ProsjecnaTezina(vector <Auto*> utrka)
{
    float suma = 0;
    int broj = 0;
    for (int i = 0; i < utrka.size(); i++)
    {
        suma += utrka[i]->getProsjek();
        broj++;
    }
    return suma/broj;
}

int main()
{
    AutoStraznjiPogon A("Renato");

    AutoPrednjiPogon B("Luka");
    AutoPrednjiPogon C("Bruno");

    cout << "Osiguranje vozaca straznjeg pogona: " << A.GetOsiguranjeInfo() << endl;
    cout << "Osiguranje vozaca prednjeg pogona: " << B.GetOsiguranjeInfo() << endl;

    vector<Auto*> utrka = { &A,&B,&C };

    cout << ProsjecnaTezina(utrka)<<endl;


    Auto* a = new AutoPrednjiPogon("Ante");
    delete a;
    return 0;
}

