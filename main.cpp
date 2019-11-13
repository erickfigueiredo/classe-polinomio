#include "polinomio.h"

ostream &operator<<(ostream &os, const Polinomio &escreve)
{
    if (escreve.termos != 1)
    {
        for (int i = escreve.termos - 1; i >= 0; i--)
        {
            if (escreve.poli[i] > 0)
            {
                if (i == escreve.termos - 1)
                    os << escreve.poli[i] << "x^" << i;
                else if (i == 0)
                    os << " + " << escreve.poli[i];
                else if(i == 1)
                    os << " + " << escreve.poli[i] << "x";
                else
                    os << " + " << escreve.poli[i] << "x^" << i;
            }
            else if (escreve.poli[i] < 0)
            {
                if (i == escreve.termos)
                    os << "- " << escreve.poli[i] * -1 << "x^" << i;
                else if (i == 0)
                    os << " - " << escreve.poli[i] * -1;
                else if(i == 1)
                    os << " - " << escreve.poli[i] << "x";
                else
                    os << " - " << escreve.poli[i] * -1 << "x^" << i;
            }
        }
    }
    else
        os << escreve.poli[0];

    os << endl;

    return os;
}

istream &operator>>(istream &is, Polinomio &a)
{
    cout << "Informe a quantidade de termos do polinômio: ";
    is >> a.termos;
    a.poli = (double *)realloc(a.poli, a.termos * sizeof(double));

    cout << "Informe os coeficientes do polinômio(termo indepedente, x, x^2, etc): ";
    for (int i = 0; i < a.termos; i++)
        is >> a.poli[i];
}

Polinomio operator*(const double &num, const Polinomio &p)
{
    Polinomio resultado(p);
    for (int i = 0; i < p.termos; i++)
        resultado.poli[i] *= num;
    return resultado;
}

int main()
{

    double *teste;
    teste = (double *)malloc(2 * sizeof(double));
    teste[0] = 1;
    teste[1] = 1;
    Polinomio a(2, teste);
    Polinomio b;
    cin >> b;
    //cout << "a: " << a;

    cout << b / a;

    b -= a;
    cout << b;

    //Polinomio e = a*b;

    //cout << "e: " << e;
    /*int i = 4;
    try
    {
        a = a/i;
        cout << "teste " << a;
    }
    catch (invalidException &e)
    {
        cout << "xapuletei\n";
    }

    a += b;
    cout << "a: " << a;

    b = a + b;
    cout << "b: " << b;

    a = a + 5;
    cout << "a: " << a;

    a += 10;
    cout << "a: " << a;]
    
    Polinomio c = a.derivada();
    cout << "c: " << c;

    Polinomio d = a.integral();
    cout << "d: " << d;

    double avalia = a.avalia(0);

    cout << "Avaliação de A em 0: " << avalia << endl;

    b = a;
    cout << "b: " << b;

    if (a == b)
        cout << "É igual\n";
    else
        cout << "É diferente\n";*/

    /*b *= 3;
    cout << "b: " << b;

    b = b*3;
    cout << "b: " << b; 

    /*  TESTEM OS METODOS AQUI   */
    free(teste);
    return 0;
}