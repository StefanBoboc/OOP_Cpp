#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

class Meniu{
protected:
    string tip;

public:
    Meniu();                        ///constructor FARA parametrii
    Meniu(string x);                ///constructor CU parametrii
    Meniu(const Meniu &old_obj);    ///constructor de copiere
    virtual ~Meniu();

    virtual void citire(istream &in);               ///citire virtuala - late binding
    virtual void afisare(ostream &out);             ///afisare virtuala - late binding

    friend istream& operator>>(istream&, Meniu&);
    friend ostream& operator<<(ostream&, Meniu&);
    Meniu& operator=(Meniu &old_obj);               ///supraincarcare operator =
};

Meniu::Meniu()
{
    tip = "";
}

Meniu::Meniu(string x)
{
    tip = x;
}

Meniu::Meniu(const Meniu &old_obj)
{
    tip = old_obj.tip;
}

Meniu::~Meniu()
{
}

void Meniu::citire(istream &in)
{
    cout<<"Client: ";

    string aux;
    getline(in,aux);

    tip = aux;
}
istream& operator>>(istream& in,Meniu& h)
{
    h.citire(in);

    return in;
}

void Meniu::afisare(ostream &out)
{
    out<<tip;
}
ostream& operator<<(ostream& out, Meniu& h)
{
    h.afisare(out);

    return out;
}

Meniu& Meniu::operator=(Meniu &old_obj)
{
    tip=old_obj.tip;

    return *this;
}

///==============================

class Ciorba:public Meniu{

private:
    bool ardei;
    bool smantana;

public:
    Ciorba();                           ///constructor FARA parametrii
    Ciorba(string, bool, bool);         ///constructor CU parametrii
    Ciorba(const Ciorba& old);          ///constructor de copiere
    ~Ciorba();                          ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Ciorba&);
    friend ostream& operator<<(ostream&, Ciorba&);
};

Ciorba::Ciorba():Meniu()
{
    ardei = 0;
    smantana = 0;
}

Ciorba::Ciorba(string x, bool a, bool s):Meniu(x)
{
    ardei = a;
    smantana = s;
}

Ciorba::Ciorba(const Ciorba &old):Meniu(old)
{
    ardei = old.ardei;
    smantana = old.smantana;
}

Ciorba::~Ciorba()
{}

void Ciorba::citire(istream &in)
{
    cout<<"Ospatar: Ciorba? De burta, de legume sau de ciuperci?"<<endl;

    Meniu::citire(in);

    if(tip == "De burta" or tip == "De legume")
    {
        cout<<"Ospatar: Doriti ardei?"<<endl;
        cout<<"Client: ";

        string aux;
        getline(in, aux);

        if(aux == "Da")
            ardei = 1;

        else
            if (aux == "Nu")
                ardei = 0;

        cout<<"Ospatar: Doriti smantana?"<<endl;
        cout<<"Client: ";

        string aux1;
        getline(in, aux1);

        if(aux1 == "Da")
            smantana = 1;

        else
            if (aux1 == "Nu")
                smantana = 0;
    }
}
void Ciorba::afisare(ostream &out)
{
    out<<"Ciorba ";

    if(tip == "De ciuperci")
    {
        out<< "de ciuperci -> 23 RON"<<endl;
    }
    else
        {
            if(tip == "De burta")
            {
                out<<"de burta ";

                int pret = 30;

                if(ardei == 1)
                {
                    out<<"+ ardei ";
                    pret = pret+2;
                }

                if(smantana == 1)
                {
                    out<<"+ smantana ";
                    pret = pret+3;
                }

                out<<"-> "<<pret<<endl;
            }

            if(tip == "De legume")
            {
                out<<"de legume ";

                int pret = 20;

                if(ardei == 1)
                {
                    out<<"+ ardei ";
                    pret = pret+2;
                }
                if(smantana == 1)
                {
                    out<<"+ smantana ";
                    pret = pret+3;
                }

                out<<"-> "<<pret<<endl;
            }
        }
}
istream& operator>>(istream& in,Ciorba& h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Ciorba& h)
{
    h.afisare(out);

    return out;
}

///------------------------------

class Fel1:public Meniu{

private:
    int pui;
    int facut;
    int fel;
    int cantitate;

public:
    Fel1();                             ///constructor FARA parametrii
    Fel1(string, int, int, int, int);   ///constructor CU parametrii
    Fel1(const Fel1 &old);              ///constructor de copiere
    ~Fel1();                            ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Fel1&);
    friend ostream& operator<<(ostream&, Fel1&);
};

Fel1::Fel1():Meniu()
{
    pui = NULL;
    facut = NULL;
    fel = NULL;
    cantitate = NULL;
}

Fel1::Fel1(string x, int p, int fa, int f, int c):Meniu(x)
{
    pui = p;
    facut = fa;
    fel = f;
    cantitate = c;
}
Fel1::Fel1(const Fel1 &old):Meniu(old)
{
    pui = old.pui;
    facut = old.facut;
    fel = old.fel;
    cantitate = old.cantitate;
}

Fel1::~Fel1()
{}

void Fel1::citire(istream &in)
{
    cout<<"Ospatar: Fel principal? Pui sau vita?"<<endl;

    Meniu::citire(in);

    if(tip == "Pui")
    {
        cout<<"Ospatar: Frigarui sau tocana?"<<endl;
        cout<<"Client: ";

        string aux;
        getline(in,aux);

        if(aux == "Frigarui")
            pui = 1;

        if(aux == "Tocana")
            pui = 2;
    }

    if(tip == "Vita")
    {
        cout<<"Ospatar: Cum sa fie facut? Bine facut, mediu sau in sange?"<<endl;
        cout<<"Client: ";

        string aux;
        getline(in,aux);

        if(aux == "Bine facut")
            facut = 3;
        else if(aux == "Mediu")
                facut = 2;
            else if(aux == "In sange")
                    facut = 1;

        cout<<"Ospatar: Stroganoff sau file?"<<endl;
        cout<<"Client: ";

        string aux1;
        getline(in,aux1);

        if(aux1 == "Stroganoff")
            fel = 1;
        else if(aux1 == "File")
                fel = 2;

        cout<<"Ospatar: Cate grame?"<<endl;
        cout<<"Client: ";

        in>>cantitate;
        in.get();
    }
}
void Fel1::afisare(ostream &out)
{
    if(tip == "Pui")
    {
        if(pui == 1)
            out<<"Frigarui pui -> 10 RON"<<endl;
        else if(pui == 2)
                out<<"Tocana pui -> 12 RON"<<endl;
    }
    else
        if(tip == "Vita")
        {
            if(fel == 1)
                out<<"Vita stroganoff x ";
            else if(fel == 2)
                    out<<"Vita file x ";

            out<<cantitate<<"g -> "<<cantitate * 21 / 100<<" RON"<<endl;
        }
}
istream& operator>>(istream& in,Fel1 &h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Fel1 &h)
{
    h.afisare(out);

    return out;
}

///------------------------------

class Garnitura:public Meniu{

private:
    int tip_cartofi;

public:
    Garnitura();                            ///constructor FARA parametrii
    Garnitura(string, int);                 ///constructor CU parametrii
    Garnitura(const Garnitura &old);        ///constructor de copiere
    ~Garnitura();                           ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Garnitura&);
    friend ostream& operator<<(ostream&, Garnitura&);
};

Garnitura::Garnitura():Meniu()
{
    tip_cartofi = NULL;
}

Garnitura::Garnitura(string x, int b):Meniu(x)
{
    tip_cartofi = b;
}
Garnitura::Garnitura(const Garnitura &old):Meniu(old)
{
    tip_cartofi=old.tip_cartofi;
}

Garnitura::~Garnitura()
{}

void Garnitura::citire(istream &in)
{
    cout<<"Ospatar: Garnitura? Cartofi sau orez sarbesc?"<<endl;

    Meniu::citire(in);

    if(tip == "Cartofi")
    {
        cout<<"Ospatar: Prajiti sau piure?"<<endl;
        cout<<"Client: ";

        string aux;
        getline(in,aux);

        if(aux == "Prajiti")
            tip_cartofi = 1;

        if(aux == "Piure")
            tip_cartofi = 2;
    }
}
void Garnitura::afisare(ostream &out)
{
    if(tip == "Cartofi")
    {
        if(tip_cartofi == 1)
            out<<"Cartofi prajiti -> 5 RON"<<endl;

        if(tip_cartofi == 2)
            out<<"Cartofi piure -> 6 RON"<<endl;
    }
    else
        if(tip == "Orez sarbesc")
        {
            out<<"Orez sarbesc -> 7 RON"<< endl;
        }
}
istream& operator>>(istream& in,Garnitura& h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Garnitura& h)
{
    h.afisare(out);

    return out;
}

///---------------------------------

class Desert:public Meniu{

private:
    int cupe;

public:
    Desert();                       ///constructor FARA parametrii
    Desert(string, int);            ///constructor CU parametrii
    Desert(const Desert &old);      ///constructor de copiere
    ~Desert();                      ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Desert&);
    friend ostream& operator<<(ostream&, Desert&);
};

Desert::Desert():Meniu()
{
    cupe = NULL;
}

Desert::Desert(string x, int b):Meniu(x)
{
    cupe = b;
}
Desert::Desert(const Desert &old):Meniu(old)
{
    cupe=old.cupe;
}

Desert::~Desert()
{}

void Desert::citire(istream &in)
{
    cout<<"Ospatar: Desert? Inghetata sau tort krantz?"<<endl;

    Meniu::citire(in);

    if(tip == "Inghetata")
    {
        cout<<"Ospatar: Cate cupe?"<<endl;
        cout<<"Client: ";

        int a;
        in>>a;
        in.get();

        while(a<3 or 5<a)
        {
            cout<<"Ospatar: Puteti comanda minim 3 si maxim 5 cupe. Deci? Cate cupe doriti?"<<endl;
            cout<<"Client: ";

            in>>a;
            in.get();
        }

        cupe = a;
    }
}
void Desert::afisare(ostream &out)
{
    if(tip == "Inghetata")
        out<<cupe<<" cupe inghetata -> "<<cupe*2<<" RON"<<endl;

    else
        if(tip == "Tort krantz")
            out<<"Tort krantz -> 9 RON"<< endl;
}
istream& operator>>(istream& in,Desert& h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Desert&h)
{
    h.afisare(out);

    return out;
}

///------------------------------

class Vin:public Meniu{

private:
    int culoare;
    int tip_sticla;
    int cantitate;

public:
    Vin();                          ///constructor FARA parametrii
    Vin(string, int, int, int);     ///constructor CU parametrii
    Vin(const Vin& old);            ///constructor de copiere
    ~Vin();                         ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Vin&);
    friend ostream& operator<<(ostream&, Vin&);
};

Vin::Vin():Meniu()
{
    culoare = NULL;
    tip_sticla = NULL;
    cantitate = 0;
}

Vin::Vin(string x, int color, int s, int c):Meniu(x)
{
    culoare = color;
    tip_sticla = s;
    cantitate = c;
}

Vin::Vin(const Vin &old):Meniu(old)
{
    culoare = old.culoare;
    tip_sticla = old.tip_sticla;
    cantitate = old.cantitate;
}

Vin::~Vin()
{}

void Vin::citire(istream &in)
{
    cout<<"Ospatar: Vin? La pahar sau la sticla?"<<endl;

    Meniu::citire(in);

    if (tip == "La pahar")
    {
        cout<<"Ospatar: Rosu sau alb?"<<endl;
        cout<<"Client: ";

        string aux;
        getline(in, aux);

        if(aux == "Alb")
            culoare = 1;

        else
            if (aux == "Rosu")
                culoare = 2;

        cout<<"Ospatar: Cati mililitrii?"<<endl;
        cout<<"Client: ";

        in>>cantitate;

        cout<<endl;
    }
    else
        if(tip == "La sticla")
        {
            cantitate = NULL;

            cout<<"Ospatar: De care vin sa fie? Bordeux din 1996 sau Castel Bolovanu 2004? Primul sau al doilea?"<<endl;
            cout<<"Client: ";

            string aux;
            getline(in, aux);

            if(aux == "Primul")
               tip_sticla = 1;

            else
                if (aux == "Al doilea")
                    tip_sticla = 2;
        }
}
void Vin::afisare(ostream &out)
{
    if(tip == "La pahar")
    {
        if(culoare == 1)
            out<<"Vin alb x "<<cantitate<<"ml -> "<<cantitate*8/100<<" RON"<<endl;

        else
            if(culoare == 2)
                out<<"Vin rosu x "<<cantitate<<"ml -> "<<cantitate*7/100<<" RON"<<endl;
    }
    else
        if(tip == "La sticla")
            if(tip_sticla == 1)
                out<<"Vin Bordeux 1996 -> 400 RON"<<endl;

            else
                if(tip_sticla == 2)
                    out<<"Vin Castle Bolovanu 2004 -> 200 RON"<<endl;
}
istream& operator>>(istream& in,Vin& h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Vin& h)
{
    h.afisare(out);

    return out;
}

///------------------------------

class Bere:public Meniu{

private:
    int sortiment;

public:
    Bere();                     ///constructor FARA parametrii
    Bere(string, int);          ///constructor CU parametrii
    Bere(const Bere &old);      ///constructor de copiere
    ~Bere();                    ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Bere&);
    friend ostream& operator<<(ostream&, Bere&);
};

Bere::Bere():Meniu()
{
    sortiment = NULL;
}

Bere::Bere(string x, int b):Meniu(x)
{
    sortiment = b;
}
Bere::Bere(const Bere &old):Meniu(old)
{
    sortiment=old.sortiment;
}

Bere::~Bere()
{}

void Bere::citire(istream &in)
{
    cout<<"Ospatar: Bere? Cu sau fara alcool?"<<endl;

    Meniu::citire(in);

    cout<<"Ospatar: Ce sortiment? Blonda, bruna sau alba?"<<endl;
    cout<<"Client: ";

    string aux;
    getline(in, aux);

    if(aux == "Blonda")
        sortiment = 1;

    else
        if(aux == "Bruna")
            sortiment = 2;

        else
            if(aux == "Alba")
                sortiment = 3;
}
void Bere::afisare(ostream &out)
{
    out<<"Bere ";

    if(sortiment == 1)
        out<<"blonda ";

    else
        if(sortiment == 2)
            out<<"bruna ";

        else
            if(sortiment == 3)
                out<<"alba ";

    Meniu::afisare(out);
    out<<" alcool -> 6 RON"<<endl;
}
istream& operator>>(istream& in,Bere& h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Bere& h)
{
    h.afisare(out);

    return out;
}

///------------------------------

class Apa:public Meniu{

private:
    int brand;

public:
    Apa();                  ///constructor FARA parametrii
    Apa(string, int);       ///constructor CU parametrii
    Apa(const Apa &old);    ///constructor de copiere
    ~Apa();                 ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Apa&);
    friend ostream& operator<<(ostream&, Apa&);
};

Apa::Apa():Meniu()
{
    brand = NULL;
}

Apa::Apa(string x, int b):Meniu(x)
{
    brand = b;
}

Apa::Apa(const Apa &old):Meniu(old)
{
    brand = old.brand;
}

Apa::~Apa()
{}

void Apa::citire(istream &in)
{
    cout<<"Ospatar: Apa? Bucovina sau Perla?"<<endl;
    cout<<"Client: ";

    string aux;
    getline(in,aux);

    if(aux == "Bucovina")
        brand = 1;

    else
        if(aux == "Perla")
            brand = 2;

    cout<<"Ospatar: La pahar sau la sticla?"<<endl;
    Meniu::citire(in);

}
void Apa::afisare(ostream &out)
{
    out<<"Apa ";

    if(brand == 1)
        out<<" Bucovina";

    else
        if(brand == 2)
            out<<" Perla";

    Meniu::afisare(out);

    if(tip == "La pahar")
        out<<" -> 1 RON"<<endl;

    else
        if(tip == "La sticla")
            out<<" -> 2 RON"<<endl;


}
istream& operator>>(istream& in,Apa& h)
{
    h.citire(in);

    return in;
}

ostream& operator<<(ostream& out, Apa& h)
{
    h.afisare(out);

    return out;
}

///==============================

meniu_output()
{
    cout<<"\n Boboc Stefan 141 - Proiect 2 - Tema 15. Restaurant. \n";
    cout<<"\n\t MENIU:";
    cout<<"\n=============================================\n";
    cout<<"\n";
    cout<<"1. Citeste n comenzi"<<endl;
    cout<<"2. Afiseaza comenzile"<<endl;
    cout<<"3. Cineva vrea sa plece"<<endl;
    cout<<"4. Un grup vrea sa plece"<<endl;
    cout<<"5. Toata lumea pleaca"<<endl;
    cout<<"0. EXIT!"<<endl;
}

void meniu()
{
    int comanda;
    comanda = 0;

    int n;

    Meniu *p;

    do{
        meniu_output();

        cout<<"Introduceti numarul actiunii: ";
        cin>>comanda;

        if(comanda == 1)
        {
            cout<<"Introduceti numarul de grupuri: ";
            cin>> n;
            cin.get();

            cout<<"Introduceti numarul de persoane: ";

            if(n>0)
            {
                for(int i=0; i<n; i++)
                {
                    cin>>p[i];
                    cin.get();
                }
            }
            else
                cout<<"Valoarea n trebuie sa fie pozitiva!";
        }

        if(comanda == 2)
        {

        }

        if(comanda == 3)
        {

        }

        if(comanda == 4)
        {

        }

        if(comanda == 5)
        {

        }

        if(comanda == 0)
        {
            cout<<endl<<"EXIT!"<<endl;
        }

        cout<<endl;
        system("pause");
        system("cls");

    }while(comanda!=0);

    delete[] p;
}

int main()
{
    meniu();

    return 0;
}
