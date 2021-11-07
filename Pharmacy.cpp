#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<typeinfo>
using namespace std;

char luni[12][4] = {"Ian","Fab","Mar","Apr","Mai","Iun","Iul","Aug","Sep","Oct","Noi","Dec"};

class Farmacie{
protected:
    string sef_farma;
public:
    Farmacie();                     ///constructor FARA parametrii
    Farmacie(string sef);           ///constructor CU parametrii
    Farmacie(const Farmacie& old);  ///constructor copiere
    virtual ~Farmacie();            ///destructor

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);

    friend istream& operator>>(istream&, Farmacie&);    ///supraincarcare operator citire
    friend ostream& operator<<(ostream&, Farmacie&);    ///supraincarcare operator afisare

    Farmacie& operator=(Farmacie &old);                 ///dupraincarcare operator =

};
Farmacie::Farmacie()
{
    sef_farma = "";
}
Farmacie::Farmacie(string x)
{
    sef_farma = x;
}

Farmacie::Farmacie(const Farmacie &old)
{
    sef_farma = old.sef_farma;
}

Farmacie::~Farmacie()
{
}

void Farmacie::citire(istream &in)
{
    cout<<"Introduceti numele sefului de farmacie: ";

    string aux;
    in>>aux;

    sef_farma = aux;
}
istream& operator>>(istream& in,Farmacie& h)
{
    h.citire(in);
    return in;
}

void Farmacie::afisare(ostream &out)
{
    cout<<"Numele sefului de farmacie: ";
    out<<sef_farma;
    cout<<endl;
}
ostream& operator<<(ostream& out, Farmacie& h)
{
    h.afisare(out);
    return out;
}

Farmacie& Farmacie::operator=(Farmacie &old)
{
    sef_farma=old.sef_farma;

    return *this;
}

///---------------------------------------------

class Farmacie_fizica: public Farmacie{
private:
    string denumire;
    int nr_angajati;
    vector<double> profituri;       /// folosim template-ul vector

    static int index;
public:
    Farmacie_fizica();                                                      ///constructor FARA parametrii
    Farmacie_fizica(string sef, string den, int nr, vector<double> prof);   ///constructor CU parametrii
    Farmacie_fizica( Farmacie_fizica &old);                                 ///constructor copiere
    ~Farmacie_fizica();                                                     ///destructor

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Farmacie_fizica&);     ///supraincarcare operator citire
    friend ostream& operator<<(ostream&, Farmacie_fizica&);     ///supraincarcare operator afisare

    Farmacie_fizica& operator=(Farmacie_fizica &old);           ///supraincarcare operator =
};

Farmacie_fizica::Farmacie_fizica():Farmacie()
{
    denumire = "Fara denumire";
    nr_angajati = 0;
    profituri.assign(12,0);         ///utilizare modificator assign din template-ul vector
}
Farmacie_fizica::Farmacie_fizica(string sef, string den, int nr, vector<double> prof):Farmacie(sef)
{
    denumire = den;

    try{                            ///exceptie daca nr de angajati este negativ
        if(nr<0)
            throw nr;
    }
    catch(int x)
    {
        cout<<"Eroare: Constructor<Farmacie_fizica>. Numarul de angajati nu poate fi negativ."<<endl;
        exit(EXIT_FAILURE);
    }

    nr_angajati = nr;

    profituri.swap(prof);           ///utilizare modificator swap din template-ul vector
}


Farmacie_fizica::Farmacie_fizica( Farmacie_fizica &old):Farmacie(old)
{
    denumire = old.denumire;
    nr_angajati = old.nr_angajati;
    profituri.swap(old.profituri);
}
Farmacie_fizica::~Farmacie_fizica()
{
}

void Farmacie_fizica::citire(istream &in)
{
    cout<<"Denumire farmacie: ";

    string aux;
    in>>aux;
    denumire = aux;

    Farmacie::citire(in);

    cout<<"Numar de angajati: ";

    in>>nr_angajati;

    cout<<"Profituri pe fiecare luna: "<<endl;

    for(int i=0; i<profituri.size(); i++)
    {
        cout<<luni[i]<<": ";
        in>>profituri[i];
    }
}
istream& operator>>(istream& in,Farmacie_fizica& h)
{
    h.citire(in);
    return in;
}

void Farmacie_fizica:: afisare(ostream &out)
{
    cout<<"Numele farmaciei fizice: ";
    out<<denumire;
    cout<<endl;

    Farmacie::afisare(out);

    cout<<"Numar de angajati: ";
    out<<nr_angajati;
    cout<<endl;

    cout<<"Profituri pe fiecare luna: ";
    cout<<endl;
    for(int i=0; i<profituri.size(); i++)
    {
        cout<<luni[i]<<": ";
        out<<profituri[i];
        cout<<endl;
    }
    cout<<endl;
}

ostream& operator<<(ostream& out,Farmacie_fizica& h)
{
    h.afisare(out);
    return out;
}

Farmacie_fizica& Farmacie_fizica::operator=(Farmacie_fizica &old)
{
    denumire = old.denumire;
    nr_angajati = old.nr_angajati;
    profituri.swap(old.profituri);

    return *this;
}

///==============================================================================================

class Farmacie_online: public Farmacie{
private:
    string adresa_web;
    int nr_vizitatori;
    double discount;
public:
    Farmacie_online();                                                  ///constructor FARA parametrii
    Farmacie_online(string sef, string web, int vizit, double dis);     ///constructor CU parametrii
    Farmacie_online(const Farmacie_online &obj);                        ///constructor copiere
    virtual ~Farmacie_online();                                         ///destructor

    int get_vizitatori(){return nr_vizitatori;}                         ///get-er pt numarul de vizitatori

    void citire(istream &in);
    void afisare(ostream &out);

    friend istream& operator>>(istream&, Farmacie_online&);             ///supraincarcare operator citire
    friend ostream& operator<<(ostream&, Farmacie_online&);             ///supraincarcare operator afisare

    Farmacie_online& operator=(Farmacie_online &old);                   ///supraincarcare operator =
};

Farmacie_online::Farmacie_online():Farmacie()
{
    adresa_web = "Fara adresa web";
    nr_vizitatori = NULL;
    discount = NULL;
}
Farmacie_online::Farmacie_online(string sef, string web, int vizit, double dis):Farmacie(sef)
{
    adresa_web = web;
    nr_vizitatori = vizit;
    discount = dis;
}
Farmacie_online::Farmacie_online(const Farmacie_online &old):Farmacie(old)
{
    adresa_web = old.adresa_web;
    nr_vizitatori = old.nr_vizitatori;
    discount = old.discount;
}
Farmacie_online::~Farmacie_online()
{
}
void Farmacie_online::citire(istream &in)
{
    cout<<"Adresa web a farmacie online: ";

    string aux;
    in>>aux;
    adresa_web = aux;

    Farmacie::citire(in);

    cout<<"Numar de vizitatori: ";

    in>>nr_vizitatori;

    cout<<"Discount: ";

    in>>discount;
}
istream& operator>>(istream& in,Farmacie_online& h)
{
    h.citire(in);
    return in;
}

void Farmacie_online:: afisare(ostream &out)
{
    cout<<"Adresa web a farmaciei online: ";
    out<<adresa_web;
    cout<<endl;

    Farmacie::afisare(out);

    cout<<"Numar de vizitatori: ";
    out<<nr_vizitatori;
    cout<<endl;

    cout<<"Discount: ";
    out<<discount;
    cout<<endl;
}

ostream& operator<<(ostream& out,Farmacie_online& h)
{
    h.afisare(out);
    return out;
}

Farmacie_online& Farmacie_online::operator=(Farmacie_online &old)
{
    adresa_web = old.adresa_web;
    nr_vizitatori = old.nr_vizitatori;
    discount = old.discount;

    return *this;
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


template <class t> class GestionareFarmacii                 ///template
{
private:
    static int index;               ///index-ul fiecarei farmacii
    //const int id_lant;
    t *v;                           ///structura de obiecte alocata dinamic
    int nr;                         ///numarul de obiecte
public:
    GestionareFarmacii(t *p=NULL, int n=0)      ///constructor
    {
        index++;
        nr = n;
        v = new t[n];               ///alocare memorie pt obiecte
        for(int i=0; i<n; i++)
        {
            v[i] = p[i];
        }
    }
    GestionareFarmacii(const int id)
    {
        index++;

    }
    ~GestionareFarmacii()                       ///destructor
    {
        delete []v;                 ///dezalocare memorie
    }

    int get_nr() {return nr;}       ///get-er numar obiecte
    t get_v(int i) {return v[i];}   ///get-er obiect

    friend istream& operator>>(istream &in, GestionareFarmacii <t> &z)      ///supraincarcare operator citire
    {
        cout<<endl;
        cout<<"    aaaaa* Introduceti nr de obiecte: ";
        in>>z.nr;
        z.v = new t[z.nr];

        cout<<endl;
        cout<<"=> Introduceti obiectele:"<<endl;
        for(int i=0; i<z.nr; i++)
        {
            in>>z.v[i];
            cout<<endl;
        }

        return in;
    }

     friend ostream& operator <<(ostream &out, GestionareFarmacii<t> &z)    ///supraincarcare operator afisare
    {
        cout<<endl;
        out<<"    * In Aplicatia de gestionare a farmaciilor se gasesc urmatoarele "<<z.nr<<" farmacii:"<<"\n";
        cout<<endl;

        for(int i=0; i<z.nr; i++)
        {
            out<<z.v[i]<<"\n";
            cout<<"--------------------------"<<endl;
        }

        return out;
    }
};

template <class t> int GestionareFarmacii<t> ::index;

template <> class GestionareFarmacii<Farmacie_online>       ///specializare clasa Farmacie_online
{
private:
    Farmacie_online *v;                 ///structura de obiecte alocata dinamic
    int nr;                             ///numar de obiecte
    int total_vizitatori;               ///calculam numarul de vizitatori total din toate farmaciile online
public:
    GestionareFarmacii(Farmacie_online *p=NULL, int n=0)    ///constructor
    {
        total_vizitatori = 0;
        nr = n;
        v = new Farmacie_online[n];

        for(int i=0; i<n; i++)
        {
            v[i] = p[i];
            for (int j=0; j<n; j++)
                total_vizitatori += v[i].get_vizitatori();

        }
    }
    GestionareFarmacii(GestionareFarmacii &f)               ///constructor copiere
    {
        nr = f.nr;
        total_vizitatori = 0;
        v = new Farmacie_online[nr];

        for(int i=0; i<nr; i++)
        {
            v[i] = f.v[i];
            for (int j=0; j<nr; j++)
                total_vizitatori += v[i].get_vizitatori();
        }
    }
    ~GestionareFarmacii()                                   ///destructor
    {
        delete [] v;
    }

    int get_nr() {return nr;}
    Farmacie_online get_v(int i) {return v[i];}

    friend istream& operator >> (istream &in, GestionareFarmacii <Farmacie_online> &z)      ///supraincarcare operator citire
    {
        cout<<endl<<"     * Introduceti numarul de Farmacii online: ";
        in>>z.nr;
        z.v = new Farmacie_online[z.nr];
        cout<<endl<<"=> Introduceti obiectele"<<endl<<endl;
        for(int i=0; i<z.nr; i++)
        {
            in>>z.v[i];

            z.total_vizitatori += z.v[i].get_vizitatori();

           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, GestionareFarmacii<Farmacie_online> &z)       ///supraincarcare operator afisare
    {
        out<<"=> In Aplicatia de gestionare a farmaciilor sunt "<<z.nr<<" farmacii online"<<endl<<endl;
        for(int i=0; i<z.nr; i++)
        {
            out<<z.v[i]<<"\n";
            cout<<"--------------------------"<<endl;
        }
        out<<"Numarul total de vizitatori din acestea este: "<<z.total_vizitatori<<endl;
        return out;
    }
};

void fizica_online(Farmacie *&p, int i)             ///functie ce afla ce tip de farmacie urmeaza sa fie introdus
{
    string tip;
    cout<<endl;
    cout<<"=> Introduceti tipul farmaciei cu nr. "<<i+1<<": ";
    cin>>tip;
    try{                                            ///in cazul in care datele introduse nu sunt corecte afisam eroare
        if(tip=="fizica")
        {
                p = new Farmacie_fizica;
                cin>>*p;
                i++;
        }
        else
            if(tip=="online")
            {
                p = new Farmacie_online;
                cin>>*p;
                i++;
            }
            else
                throw 6;
    }
    catch (bad_alloc var)
    {
        cout << "Eroare de alocare\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Tipurile de farmacii disponibile sunt: fizica sau online."<<endl;
    }
}



void meniu_output()
{
    cout<<"---------------------------------------------------";
    cout<<"\n Boboc Stefan 141 - Proiect 3 - Tema 6. Farmaciile.";
    cout<<"\n---------------------------------------------------";
    cout<<"\n\n\t MENIU:";
    cout<<"\n=============================================\n";
    cout<<"\n";
    cout<<"1. Cititi n farmacii cu datele lor."<<endl;
    cout<<"2. Afisati informatiile despre farmaciile introduse."<<endl;
    cout<<"3. GestionareFarmacii --- TEMPLATE (Farmacii online)."<<endl;
    cout<<"4. Evidenta tipurilor de farmacii --- DYNAMIC_CAST (DOWNCAST)."<<endl;
    cout<<"0. EXIT!"<<endl;
    cout<<"\n=============================================\n";
}

int main()
{
    int comanda = 0;
    int n=0;

    Farmacie **v;                                   ///vector cu pointeri"

    do{
        meniu_output();

        cout<<endl;
        cout<<"\t # Introduceti numarul actiunii: ";
        cin>>comanda;

        ///COMANDA 1
        if(comanda == 1)
        {
            cout<<endl;
            cout<<"     * Introduceti nr de farmacii citite: ";
            cin>>n;

            v = new Farmacie*[n];                   ///alocam memorie pt "vectorul de pointeri"

            if(n>0)
            {
                for(int i=0; i<n; i++)
                    fizica_online(v[i],i);          ///decidem de ce tip sunt farmaciile
            }
            else
                cout<<"Valoare n trebuie sa fie pozitiva."<<endl;
        }

        ///COMANDA 2
        if(comanda == 2)
        {
            cout<<endl;
            cout<<"     * Farmaciile introduse sunt:"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"\n"<<*v[i];
                cout<<"\n--------------------------\n";
            }
        }

        ///COMANDA 3
        if(comanda == 3)
        {
            GestionareFarmacii<Farmacie_online> x;          ///creare obect de tip specializare Farmacie_online
            cin>>x;
            cout<<"     * Afisarea datelor introduse:"<<endl;
            cout<<x;
        }

        ///COMANDA 4
        if(comanda == 4)
        {
            int nr_fizic, nr_online;
            nr_fizic = nr_online = 0;
            if (n>0)
            {
                for(int i=0;i<n;i++)
                {
                    Farmacie_fizica *p1=dynamic_cast<Farmacie_fizica*>(v[i]); ///incerc cast catre Farmacie fizica

                    Farmacie_online *p2=dynamic_cast<Farmacie_online*>(v[i]); ///incerc cast catre Farmacie online

                    ///daca sunt nenuli atunci incrementez corespunzator
                    if (p1)
                        nr_fizic++;
                    if (p2)
                        nr_online++;
                }
                cout<<endl;
                cout<<"   Numarul de farmacii fizice: "<<nr_fizic<<"\n";
                cout<<"   Numarul de farmacii online: "<<nr_online<<"\n";
                cout<<endl;            }
                else
                    cout<<endl<<"   ! Nu s-au citit informatii despre farmacii. Reveniti la actiunea 1. !\n"<<endl;
        }

        ///COMANDA 0
        if (comanda == 0)
        {
            cout<<"\nEXIT\n\n";
        }

        ///Comenzi gresite
        if(comanda<0 or comanda>4)
        {
            cout<<endl<<"   ! Nu exista comanda "<<comanda<<". Introduceti o comanda din cele afisate pe ecran. !"<<endl<<endl;
        }

        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei

    }while(comanda!=0);

    return 0;
}
