#include "polinomio.h"

/*      Construtores      */
Polinomio::Polinomio()
{
    termos = 1;
    poli = (double *)calloc(1, sizeof(double));
}

Polinomio::Polinomio(const int num)
{
    termos = 1;
    poli = (double *)malloc(sizeof(double));
    *poli = num;
}

Polinomio::Polinomio(unsigned int n, double *a)
{
    termos = n;
    poli = (double *)malloc(termos * sizeof(double));
    for (int i = 0; i < termos; i++)
        poli[i] = a[i];
}

Polinomio::Polinomio(const Polinomio &p)
{
    this->termos = p.termos;
    poli = (double *)malloc(this->termos * sizeof(double));
    for (int i = 0; i < this->termos; i++)
        this->poli[i] = p.poli[i];
}

/*      Destrutor      */
Polinomio::~Polinomio()
{
    free(poli);
}

/*      Operadores      */

//Atribuicao
Polinomio &Polinomio::operator=(const Polinomio &p)
{
    if (this == &p)
        return *this;
    this->termos = p.termos;
    free(this->poli);
    poli = (double *)malloc(this->termos * sizeof(double));
    for (int i = 0; i < this->termos; i++)
        this->poli[i] = p.poli[i];
}

//Soma de polinômios
Polinomio Polinomio::operator+(const Polinomio &p) const
{
    Polinomio resultado;
    if (this->termos >= p.termos)
    {
        resultado.termos = this->termos;
        for (int i = 0; i < resultado.termos; i++)
            resultado.poli[i] = this->poli[i];

        for (int i = 0; i < p.termos; i++)
            resultado.poli[i] += p.poli[i];
    }
    else
    {
        resultado.termos = p.termos;
        for (int i = 0; i < resultado.termos; i++)
            resultado.poli[i] = p.poli[i];

        for (int i = 0; i < this->termos; i++)
            resultado.poli[i] += this->poli[i];
    }

    return resultado;
}

//Soma de polinômio com um número
Polinomio Polinomio::operator+(const double &num) const
{
    Polinomio resultado;

    resultado.termos = this->termos;

    for (int i = 0; i < this->termos; i++)
    {
        resultado.poli[i] = this->poli[i];
    }

    resultado.poli[0] += num;

    return resultado;
}

//Atribuição de um polinomio em outro
Polinomio &Polinomio::operator+=(const Polinomio &p)
{

    /*FALTA O DESENVOLVIMENTO*/

    return *this;
}

//Atribuição de um valor ao termo independente de um polinomio
Polinomio &Polinomio::operator+=(const double &num)
{
    this->poli[0] += num;
    return *this;
}

//Comparação
bool Polinomio::operator==(const Polinomio &p) const
{
    if (this == &p)
        return true;
    if (p.termos == this->termos)
    {
        for (int i = 0; i < this->termos; i++)
            if (this->poli[i] != p.poli[i])
                return false;
    }
    return true;
}

/* Polinomio Polinomio::operator++(){
    int ultimo = (sizeof(this->poli))-1;
    this->poli[ultimo]++;
    return *this;
} */

/* Polinomio Polinomio::operator++(int num){
    int ultimo = (sizeof(this->poli))-1;
    this->poli[ultimo]+num;
    return *this;
} */

//Incremento de 1
Polinomio Polinomio::operator++(){
    this->poli[0]++;
    return *this;
}

//Incremento de uma determinada quantidade
Polinomio Polinomio::operator++(int num){
    this->poli[0] = poli[0]+num;
}

/*      Operações (sem operadores)       */

//Derivada
Polinomio Polinomio::derivada() const
{
    Polinomio d;
    d.termos = this->termos - 1;
    d.poli = (double *)malloc((d.termos) * sizeof(double));

    for (int i = 1; i < this->termos; i++)
        d.poli[i - 1] = i * this->poli[i];
    return d;
}

//Integral
Polinomio Polinomio::integral() const
{
    Polinomio dx;
    dx.termos = this->termos + 1;
    dx.poli = (double *)calloc(dx.termos, sizeof(double));

    for (int i = 0; i < this->termos; i++)
    {
        if (i == 0)
            dx.poli[1] = this->poli[0];
        dx.poli[i + 1] = (this->poli[i]) / (i + 1);
    }
    return dx;
}

double Polinomio::avalia(double a) const
{
    return avaliaPoli(poli, termos, 0, a);
}

//Avaliação de polinômio pelo método de Horner
double Polinomio::avaliaPoli(double *poli, int termos, int aux, double a) const
{
    //Verificamos se o calculo já se encontra no coeficiente multiplicado pelo segundo maior grau
    if (aux == termos - 2)
        return poli[termos - 1] * a + poli[termos - 2];
    
    //Mais externo para o mais interno
    return avaliaPoli(poli, termos, aux + 1, a) * a + poli[aux];
}