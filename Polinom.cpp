#include <iostream>
using namespace std;

class Polinom{

private:
    int grad;
    double *v;

public:
    Polinom();  ///constructor de initializare FARA parametrii
    Polinom(int g); ///constructor de initializare CU parametrii
    Polinom(const Polinom &old_obj);    ///constructor de copiere
    ~Polinom(); ///destructorul

    friend istream& operator>> (istream &in, Polinom &ob);             ///supraincarcare operator citire
    friend ostream& operator<< (ostream &out, const Polinom &ob);      ///supraincarcare operator afisare

    void set_grad(int);                 ///set grad
    void set_adresa(double);            ///set adresa
    double get_grad(){return grad;}     ///get grad
    double get_adresa(){return *v;}     ///get adresa

    double punct(double x);             ///metoda pentru calculul valorii unui polinom intr-un punct
    Polinom operator+(Polinom op2);     ///supraincarcare operator +
    Polinom operator-(Polinom op2);     ///supraincarcare operator -
    Polinom operator*(Polinom op2);     ///supraincarcare operator *
};

Polinom::Polinom()
{
    grad=1;
    v = nullptr;
}

Polinom::Polinom(int g)
{
    grad = g;
    v = new double[g+1];
}

Polinom::Polinom(const Polinom &old_obj)
{
    grad=old_obj.grad;
    v = new double[grad+1];
    for(int i=0; i<=grad; i++)
        v[i] = old_obj.v[i];
}

Polinom::~Polinom()
{
    this->grad=0;
    delete[] v;
    v = nullptr;
}

istream& operator>>(istream& in, Polinom& ob)
{
    cout<<endl<<"=> Cititi gradul polinomului: ";
    in>>ob.grad;

    cout<<endl;

    ob.v = new double[ob.grad+1];                       ///alocam saptiu pentru indicii polinomului citit

    cout<<"=> Cititi coeficientii polinomului:"<<endl;
    for(int i=ob.grad; i>0; i--)                        ///se citesc coeficientii polinomului
    {                                                   ///indicele din vector al ficarui coeficient corespunde cu X-ul lui
        cout<<"  -> Coeficient X^"<<i<<": ";
        in>>ob.v[i];
    }
    cout<<"  -> Cititi termenul liber: ";               ///se citeste termenul liber
    in>>ob.v[0];

    cout<<endl<<"-----"<<endl;

    return in;                                          ///returnam polinomul citit
}

ostream& operator<<(ostream& out, const Polinom& ob)
{
    out<<"Polinom: ";

    int x = ob.grad;

    out<<ob.v[x]<<"X^"<<x;
    x--;

    for(int i=ob.grad-1; i>0; i--)
    {
        if(ob.v[i]>=0)
            out<<" +"<<ob.v[i]<<"X^"<<x;
        else out<<" "<<ob.v[i]<<"X^"<<x;
        x--;
    }

    if(ob.v[0]>=0)
        out<<" +"<<ob.v[0]<<endl;
    else out<<" "<<ob.v[0]<<endl;

    return out;                                         ///returnam polinomul pentru afisare
}

void Polinom::set_grad(int x)                           ///set grad
{
    grad = x;
}

void Polinom::set_adresa(double x)                      ///set adresa
{
    v = &x;
}

double Polinom::punct(double x)
{
    double suma=0;
    double h=x;

    for(int i=0; i<grad-1; i++)                         ///calculul punctului la puterea ce mai mare a polinomului
        h=h*x;

    for(int i=grad; i>0; i--)                           ///efectuarea sumei
    {
        suma=suma+h*v[i];
        h=h/x;
    }

    suma=suma+v[0];

    return suma;                                        ///returnarea sumei pentru afisare
}

Polinom Polinom::operator+(Polinom op2)
{
    if(op2.grad>grad)                                   ///efectuarea sumei pentru puterile comune
    {                                                   ///urmand sa se copieze restul

        Polinom temp(op2.grad);                         ///declarae obiect temporar

        for(int i=0; i<=grad; i++)
            temp.v[i]=op2.v[i]+v[i];
        for(int i=grad+1; i<=op2.grad; i++)
            temp.v[i]=op2.v[i];

        return temp;
    }
    else{
        Polinom temp(grad);

        for(int i=0; i<=op2.grad;i++)
            temp.v[i]=op2.v[i]+v[i];
        for(int i=op2.grad+1; i<=grad;i++)
            temp.v[i]=v[i];

        return temp;
    }

}

Polinom Polinom::operator-(Polinom op2)
{
    int mic, mare;
    int ok=0;                                           ///variabila ce memoreaza ce zemn are rezultatul

    if(grad>op2.grad)                                   ///efectuarea diferentei pentru puterile comune
    {                                                   ///urmand ca restul sa se copieze in functie de semnul corespunzator
        mic=op2.grad;
        mare=grad;
    }
    else{
        mic=grad;
        mare=op2.grad;ok=1;
    }

    Polinom temp(mare);

    for(int i=0;i<=mic;i++)
        temp.v[i]=v[i]-op2.v[i];

    if(ok==0)
    {
        for(int i=mic+1;i<=mare;i++)
            temp.v[i]=v[i];
    }
    else{
        for(int i=mic+1;i<=mare;i++)
            temp.v[i]=-op2.v[i];
    }

    return temp;
}

Polinom Polinom::operator*(Polinom op2)
{
    Polinom temp1(op2.grad+grad);                       ///avand polinoame de dimensiune
                                                        ///egala cu gradul plus 1, de la cel al termenului liber
    for(int i=0; i<=grad; i++)                          ///la cel de grad maxim,
        for(int j=0; j<=op2.grad; j++)                  ///atunci stim ca produsul a doua polinoame de acest tip
            temp1.v[i+j] += v[i]*op2.v[j];              ///are gradul m+n+1, unde m este gradul polinom_1 si n este gradul polinom_2
                                                        ///acel "+1" se adauga in constructorul de copiere
    return temp1;
}

void meniu_output()
{
    cout<<"\n Boboc Stefan 141 - Proiect 1 - Tema 10. Polinom. \n";
    cout<<"\n\t MENIU:";
    cout<<"\n=============================================\n";
    cout<<"\n";
    cout<<"1. Citeste n polinoame."<<endl;
    cout<<"2. Afiseaza cele n polinoame citite."<<endl;
    cout<<"3. Calcul valorii unui polinom intr-un punct."<<endl;
    cout<<"4. Suma a doua polinoame."<<endl;
    cout<<"5. Diferenta a doua polinoame."<<endl;
    cout<<"6. Produsul a doua polinoame."<<endl;
    cout<<"0. EXIT!"<<endl;
}

void meniu()
{
    int comanda;    /// ce comanda alege utilizatorul
    comanda = 0;

    int n;          ///numarul de elemente citite

    Polinom *p;     ///pointer care arata catre vectorul de obiecte (/polinoame)

    do{
        meniu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>> comanda;

        ///COMANDA 1
        if(comanda==1)
        {
            cout<<endl<<"     # Introduceti numarul de polinoame: ";
            cin>>n;
            cin.get();  ///Eliminare ENTER din buffer

            p = new Polinom[n];     ///alocare spatiu pentru n obiecte

            if(n>0)
            {
                for(int i=0; i<n; i++)
                {
                    cin>>p[i];      ///citirea celor n obiecte
                    cin.get();
                }
            }
            else
                cout<<"Valoarea n trebuie sa fie pozitiva!";
        }

        ///COMANDA 2
        if(comanda == 2)
        {
            cout<<endl<<"     # Polinoamele introduse sunt:"<<endl<<endl;

            if(n!=0)
            {
                for(int i=0; i<n; i++)
                    cout<<p[i];     ///afisarea celor n obiecte
            }
        }

        ///COMANDA 3
        if(comanda==3)
        {
            cout<<endl<<"     # Introduceti indicele polinomului pentru care doriti sa aflati valoarea lui intr-un anumit punct."<<endl<<endl;
            for(int i=0; i<n; i++)
                cout<<i<<". "<<p[i];

            int a;
            cout<<endl<<"=> Polinomul cu indicele: "; cin>>a;
            cin.get();

            int x;
            cout<<endl<<"=> Introduceti punctul in care doriti sa calculati: "; cin>>x;
            cin.get();

            cout<<endl<<"REZULTAT: "<<p[a].punct(x);        ///apelare metoda pentru calculul valorii unui polinom intr-un punct
        }


        ///COMANDA 4
        if(comanda==4)
        {
            cout<<endl<<"     # Introduceti indicele polinoamelor pentru care doriti sa faceti suma."<<endl<<endl;
            for(int i=0; i<n; i++)
                cout<<i<<". "<<p[i];

            int a;
            cout<<endl<<"=> Polinom 1: "; cin>>a;
            cin.get();

            int b;
            cout<<"=> Polinom 2: "; cin>>b;
            cin.get();

            cout<<endl<<"REZULTAT:"<<endl;
            cout<<p[a]+p[b];
        }

        ///COMANDA 5
        if(comanda==5)
        {
            cout<<endl<<"     # Introduceti indicele polinoamelor pentru care doriti sa faceti diferenta."<<endl;
            cout<<"   * Diferenta se va realiza sub forma 'Polinom 1 - Polinom 2'."<<endl<<endl;
            for(int i=0; i<n; i++)
                cout<<i<<". "<<p[i];

            int a;
            cout<<endl<<"=> Polinom 1: "; cin>>a;
            cin.get();

            int b;
            cout<<"=> Polinom 2: "; cin>>b;
            cin.get();

            cout<<endl<<"REZULTAT:"<<endl;
            cout<<p[a]-p[b];
        }

        ///COMANDA 6
        if(comanda==6)
        {
            cout<<endl<<"     # Introduceti indicele polinoamelor pentru care doriti sa faceti produsul."<<endl<<endl;
            for(int i=0; i<n; i++)
                cout<<i<<". "<<p[i];

            int a;
            cout<<endl<<"=> Polinom 1: "; cin>>a;
            cin.get();

            int b;
            cout<<"=> Polinom 2: "; cin>>b;
            cin.get();

            cout<<endl<<"REZULTAT:"<<endl;
            cout<<p[a]*p[b];
        }

        ///COMANDA 0
        if(comanda==0)
        {
            cout<<endl<<"EXIT!"<<endl;
        }


        cout<<endl;
        system("pause");
        system("cls");
    }while(comanda!=0);

    delete[] p;         ///stergere valori alocate dinamic
    p = nullptr;        ///pointerul nu mai arata catre o zona de memorie
}

int main()
{
    meniu();

    return 0;
}
