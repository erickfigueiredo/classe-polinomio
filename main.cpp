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
                else if (i == 1)
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
                else if (i == 1)
                    os << " - " << escreve.poli[i] * -1 << "x";
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
    cout << "Informe o grau do polinômio: ";
    is >> a.termos;
    a.termos++;
    a.poli = (double *)realloc(a.poli, a.termos * sizeof(double));

    cout << "Informe os coeficientes do polinômio(termo independente, x, x^2, etc): ";
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
    Polinomio a;
    int n = -1;
    cin >> a;

    double *raiz = a.resolve(n);

    if(n != 0){
        for(int i=0;i<n;i++)
            cout << raiz[i] << endl;
        free(raiz);    
    }
            
    return 0;
}