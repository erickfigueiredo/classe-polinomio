#include "polinomio.h"

ostream& operator<<(ostream &os, const Polinomio &escreve)
{
    for (int i = escreve.termos - 1; i >= 0; i--)
    {
        if (escreve.poli[i] > 0)
        {
            if (i == escreve.termos - 1)
                os << escreve.poli[i] << "x^" << i;
            else if (i == 0)
                os << " + " << escreve.poli[i];
            else
                os << " + " << escreve.poli[i] << "x^" << i;
        }
        else if (escreve.poli[i] < 0)
        {
            if (i == escreve.termos)
                os << "- " << escreve.poli[i]*-1 << "x^" << i;
            else if (i == 0)
                os << " - " << escreve.poli[i]*-1;
            else
                os << " - " << escreve.poli[i]*-1 << "x^" << i;
        }
    }

    os << endl;

    return os;
}

int main()
{

    double *teste;
    teste = (double *)malloc(3 * sizeof(double));
    teste[0] = 4;
    teste[1] = 2;
    teste[2] = 3;
    Polinomio a(3, teste);
    teste[0] = -4;
    teste[1] = 6;
    teste[2] = 7;
    Polinomio b(3, teste);
    a += b;
    cout << "a: " << a;

    b = a + b;
    cout << "b: " << b;

    a = a + 5;
    cout << "a: " << a;

    a += 10;
    cout << "a: " << a;

    a++;
    cout << "a: " << a;

    ++a;
    cout << "a: " << a;

    Polinomio c = a.derivada();
    cout << "c: " << c;

    Polinomio d = a.integral();
    cout << "d: " << d;

    double avalia = a.avalia(0);

    cout << "Avaliação de A em 0: " << avalia << endl;

    //b = a;
    //cout << "b: " << b;

    if (a == b)
        cout << "É igual\n";
    else
        cout << "É diferente\n";

    /*  TESTEM OS METODOS AQUI   */
    free(teste);
    return 0;
}