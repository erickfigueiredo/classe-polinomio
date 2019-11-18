#include "polinomio.h"

/*----------------------------Construtores----------------------------*/
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

/*----------------------------Destrutor----------------------------*/
Polinomio::~Polinomio()
{
    free(poli);
}

/*----------------------------Operadores----------------------------*/

//------Atribuicao
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

//------Soma de objetos
Polinomio Polinomio::operator+(const Polinomio &p) const
{
    Polinomio resultado;
    if (this->termos >= p.termos)
    {
        resultado.termos = this->termos;
        free(resultado.poli);
        resultado.poli = (double *)malloc(resultado.termos * sizeof(double));
        for (int i = 0; i < resultado.termos; i++)
            resultado.poli[i] = this->poli[i];

        for (int i = 0; i < p.termos; i++)
            resultado.poli[i] += p.poli[i];
    }
    else
    {
        resultado.termos = p.termos;
        free(resultado.poli);
        resultado.poli = (double *)malloc(resultado.termos * sizeof(double));
        for (int i = 0; i < resultado.termos; i++)
            resultado.poli[i] = p.poli[i];

        for (int i = 0; i < this->termos; i++)
            resultado.poli[i] += this->poli[i];
    }

    return resultado;
}

//------Soma de objeto com um numero
Polinomio Polinomio::operator+(const double &num) const
{
    Polinomio resultado;

    resultado.termos = this->termos;
    free(resultado.poli);
    resultado.poli = (double *)malloc(resultado.termos * sizeof(double));

    for (int i = 0; i < this->termos; i++)
        resultado.poli[i] = this->poli[i];

    resultado.poli[0] += num;

    return resultado;
}

//------Incremento de um polinomio
Polinomio &Polinomio::operator+=(const Polinomio &p)
{
    if (this->termos >= p.termos)
    {
        for (int i = 0; i < p.termos; i++)
            this->poli[i] += p.poli[i];
    }
    else
    {
        Polinomio aux(*this);

        free(this->poli);
        this->poli = (double *)malloc(p.termos * sizeof(double));
        this->termos = p.termos;

        for (int i = 0; i < this->termos; i++)
        {
            if (i < aux.termos)
                this->poli[i] = p.poli[i] + aux.poli[i];
            else
                this->poli[i] = p.poli[i];
        }
    }

    return *this;
}

//------Incremento de um double
Polinomio &Polinomio::operator+=(const double &num)
{
    this->poli[0] += num;
    return *this;
}

//------Subtracao de objetos
Polinomio Polinomio::operator-(const Polinomio &p) const
{
    Polinomio resultado;
    if (this->termos >= p.termos)
    {
        resultado.termos = this->termos;
        free(resultado.poli);
        resultado.poli = (double *)malloc(resultado.termos * sizeof(double));
        for (int i = 0; i < resultado.termos; i++)
            resultado.poli[i] = this->poli[i];

        for (int i = 0; i < p.termos; i++)
            resultado.poli[i] -= p.poli[i];
    }
    else
    {
        resultado.termos = p.termos;
        free(resultado.poli);
        resultado.poli = (double *)malloc(resultado.termos * sizeof(double));
        for (int i = 0; i < resultado.termos; i++)
            resultado.poli[i] = p.poli[i];

        for (int i = 0; i < this->termos; i++)
            resultado.poli[i] -= this->poli[i];
    }

    return resultado;
}

//------Subtracao de objeto com um numero
Polinomio Polinomio::operator-(const double &num) const
{
    Polinomio resultado;

    resultado.termos = this->termos;
    free(resultado.poli);
    resultado.poli = (double *)malloc(resultado.termos * sizeof(double));

    for (int i = 0; i < this->termos; i++)
    {
        resultado.poli[i] = this->poli[i];
    }

    resultado.poli[0] -= num;

    return resultado;
}

//------Decremento de um polinomio
Polinomio &Polinomio::operator-=(const Polinomio &p)
{
    if (this->termos >= p.termos)
    {
        for (int i = 0; i < p.termos; i++)
            this->poli[i] -= p.poli[i];
    }
    else
    {
        Polinomio aux(*this);

        free(this->poli);
        this->poli = (double *)malloc(p.termos * sizeof(double));
        this->termos = p.termos;

        for (int i = 0; i < this->termos; i++)
        {
            if (i < aux.termos)
                this->poli[i] = p.poli[i] - aux.poli[i];
            else
                this->poli[i] = p.poli[i];
        }
    }

    return *this;
}

//------Decremento de um double
Polinomio &Polinomio::operator-=(const double &num)
{
    this->poli[0] -= num;
    return *this;
}

//------Multiplicacao de objetos
Polinomio Polinomio::operator*(const Polinomio &p) const
{
    Polinomio resultado;
    resultado.termos = this->termos + p.termos - 1;
    free(resultado.poli);
    resultado.poli = (double *)calloc(resultado.termos, sizeof(double));
    for (int i = 0; i < this->termos; i++)
        for (int j = 0; j < p.termos; j++)
            resultado.poli[i + j] += this->poli[i] * p.poli[j];
    return resultado;
}

//------Multiplicacao de objeto com um numero
Polinomio Polinomio::operator*(const double &num) const
{

    Polinomio resultado(*this);

    for (int i = 0; i < this->termos; i++)
        resultado.poli[i] *= num;

    return resultado;
}

//------Multiplicacao incremental de objeto com objeto
Polinomio &Polinomio::operator*=(const Polinomio &p)
{
    Polinomio resultado;
    resultado.termos = this->termos + p.termos - 1;
    free(resultado.poli);
    resultado.poli = (double *)calloc(resultado.termos, sizeof(double));
    for (int i = 0; i < this->termos; i++)
        for (int j = 0; j < p.termos; j++)
            resultado.poli[i + j] += this->poli[i] * p.poli[j];
    free(this->poli);
    this->termos = resultado.termos;
    this->poli = (double *)calloc(this->termos, sizeof(double));

    for (int i = 0; i < this->termos; i++)
        this->poli[i] = resultado.poli[i];

    return *this;
}

//------Multiplicacao incremental de objeto com um numero
Polinomio &Polinomio::operator*=(const double &num)
{
    for (int i = 0; i < this->termos; i++)
        this->poli[i] *= num;

    return *this;
}

//------Div/igual por inteiro
Polinomio &Polinomio::operator/=(const int &divisor)
{
    try
    {
        if (divisor == 0)
            throw(ArgumentoInvalidoExcept());
        for (int i = 0; i < termos; i++)
            poli[i] /= divisor;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao invalida!\n";
    }

    return *this;
}

//-------Divisao por inteiro
Polinomio Polinomio::operator/(const int &divisor) const
{
    Polinomio resultado(*this);
    try
    {
        if (divisor == 0)
            throw(ArgumentoInvalidoExcept());

        for (int i = 0; i < termos; i++)
            resultado.poli[i] /= divisor;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao invalida!\n";
    }

    return resultado;
}

//------Divisao de polinomios
Polinomio Polinomio::operator/(const Polinomio &p) const
{
    try
    {
        if (p.termos != 2)
            throw(ArgumentoInvalidoExcept());

        Polinomio resultado;
        resultado.termos = this->termos - 1;
        free(resultado.poli);
        resultado.poli = (double *)calloc(resultado.termos, sizeof(double));
        double raiz = -p.poli[0];
        resultado.poli[resultado.termos - 1] = this->poli[this->termos - 1];
        for (int i = resultado.termos - 2; i >= 0; i--)
            resultado.poli[i] = (resultado.poli[i + 1] * raiz) + this->poli[i + 1];

        return resultado;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao invalida!\n";
    }
}

Polinomio &Polinomio::operator/=(const Polinomio &p)
{
    try
    {
        if (p.termos != 2)
            throw(ArgumentoInvalidoExcept());

        Polinomio resultado;
        resultado.termos = this->termos - 1;
        free(resultado.poli);
        resultado.poli = (double *)calloc(resultado.termos, sizeof(double));
        double raiz = -p.poli[0];
        resultado.poli[resultado.termos - 1] = this->poli[this->termos - 1];
        for (int i = resultado.termos - 2; i >= 0; i--)
        {
            resultado.poli[i] = (resultado.poli[i + 1] * raiz) + this->poli[i + 1];
        }

        *this = resultado;

        return *this;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao invalida!\n";
    }
}

Polinomio Polinomio::operator%(const Polinomio &p) const
{
    try
    {
        double resto;
        if (p.termos != 2)
            throw(ArgumentoInvalidoExcept());

        Polinomio resultado;
        resultado.termos = this->termos - 1;
        free(resultado.poli);
        resultado.poli = (double *)calloc(resultado.termos, sizeof(double));
        double raiz = -p.poli[0];
        resultado.poli[resultado.termos - 1] = this->poli[this->termos - 1];
        for (int i = resultado.termos - 2; i >= 0; i--)
            resultado.poli[i] = (resultado.poli[i + 1] * raiz) + this->poli[i + 1];

        resto = (resultado.poli[0] * raiz) + this->poli[0];
        resultado.termos = 1;
        free(resultado.poli);
        resultado.poli = (double *)malloc(sizeof(double));
        resultado.poli[0] = resto;
        return resultado;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao invalida!\n";
    }
}

Polinomio &Polinomio::operator%=(const Polinomio &p)
{
    try
    {
        double resto;
        if (p.termos != 2)
            throw(ArgumentoInvalidoExcept());

        Polinomio resultado;
        resultado.termos = this->termos - 1;
        free(resultado.poli);
        resultado.poli = (double *)calloc(resultado.termos, sizeof(double));
        double raiz = -p.poli[0];
        resultado.poli[resultado.termos - 1] = this->poli[this->termos - 1];
        for (int i = resultado.termos - 2; i >= 0; i--)
            resultado.poli[i] = (resultado.poli[i + 1] * raiz) + this->poli[i + 1];

        resto = (resultado.poli[0] * raiz) + this->poli[0];
        this->termos = 1;
        free(this->poli);
        this->poli = (double *)malloc(sizeof(double));
        this->poli[0] = resto;
        return *this;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao invalida!\n";
    }
}

//------Incremento de 1
Polinomio &Polinomio::operator++(int)
{
    poli[0]++;
    return *this;
}

Polinomio Polinomio::operator++()
{
    Polinomio resultado(*this);
    resultado.poli[0]++;
    return resultado;
}

//------Decremento de 1
Polinomio &Polinomio::operator--(int)
{
    poli[0]--;
    return *this;
}

Polinomio Polinomio::operator--()
{
    Polinomio resultado(*this);
    resultado.poli[0]--;
    return resultado;
}

//------Operadores de indexacao
double Polinomio ::operator[](int i) const
{
    if (i == 0)
        return poli[0];

    try
    {
        if (i < 0 || i > termos)
            throw(PosicaoInvalidaExcept());
        return poli[i - 1];
    }
    catch (PosicaoInvalidaExcept &e)
    {
        cout << "Posição invalida!\n";
    }
}

double &Polinomio ::operator[](int i)
{
    if (i == 0)
        return poli[0];

    try
    {
        if (i < 0 || i > termos)
            throw(PosicaoInvalidaExcept());
        return poli[i - 1];
    }
    catch (PosicaoInvalidaExcept &e)
    {
        cout << "Posição invalida!\n";
    }
}

//------Operador de comparacao
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

/*----------------------------Calculos----------------------------*/

//------Derivacao de polinomio
Polinomio Polinomio::derivada() const
{
    Polinomio d;
    d.termos = this->termos - 1;
    free(d.poli);
    d.poli = (double *)malloc((d.termos) * sizeof(double));

    for (int i = 1; i < this->termos; i++)
        d.poli[i - 1] = i * this->poli[i];
    return d;
}

//------Integracao de polinomio
Polinomio Polinomio::integral() const
{
    Polinomio dx;
    dx.termos = this->termos + 1;
    free(dx.poli);
    dx.poli = (double *)calloc(dx.termos, sizeof(double));

    for (int i = 0; i < this->termos; i++)
    {
        if (i == 0)
            dx.poli[1] = this->poli[0];
        dx.poli[i + 1] = (this->poli[i]) / (i + 1);
    }
    return dx;
}

//------Avaliacao do polinomio
double Polinomio::avalia(double a) const
{
    return avaliaPoli(termos, 0, a);
}

//Método de Horner
double Polinomio::avaliaPoli(int termos, int aux, double a) const
{
    //Verificamos se o calculo já se encontra no coeficiente multiplicado pelo segundo maior grau
    if (aux == termos - 2)
        return poli[termos - 1] * a + poli[termos - 2];

    //Mais externo para o mais interno
    return avaliaPoli(termos, aux + 1, a) * a + poli[aux];
}

//------Metodo de Newton-Rhapson
//x(n+1) = x(n) - f(x)/f'(x)
//achar um intervalo onde f(x) troca de sinal(possivel raiz)
//avaliar em um dos extremos, se for suficientemente bom
//chamar briot-ruffini, diminuido o grau, e repetir ate o final

double *Polinomio ::resolve(int &num) const
{
    try
    {
        Polinomio p(*this);
        double *bin, *raizes;
        double x1, x = num;
        int tam = 0;
        bool temRaiz = false;
        if (p.termos == 1)
        {
            throw NaoHaRaizes();
        }
        for (int i = termos; i > 3; i--)
        {
            cout << "entrou nao era" << endl;
            for (int i = 0; i < 10e6; i++)
            {
                x1 = x - p.avalia(x) / p.derivada().avalia(x);
                if (x == x1)
                {
                    temRaiz = true;
                    break;
                }
                x = x1;
            }
            if (temRaiz)
            {
                if (tam == 0)
                {
                    raizes = (double *)malloc(sizeof(double));
                    raizes[0] = x;
                    tam++;
                }
                else
                {
                    raizes = (double *)realloc(raizes, (tam + 1) * sizeof(double));
                    raizes[tam] = x;
                    tam++;
                }
                bin = (double *)malloc(2 * sizeof(double));
                bin[0] = x;
                bin[1] = 1;
                Polinomio binomio(2, bin);
                free(bin);
                p /= binomio;
            }
            temRaiz = false;
        }
        if (tam == termos - 3)
        {
            if (p.delta() >= 0)
            {
                if (tam == 0)
                {
                    raizes = (double *)calloc(2, sizeof(double));
                    raizes[0] = (-p.poli[1] + sqrt(p.delta())) / (2 * p.poli[2]);
                    raizes[1] = (-p.poli[1] - sqrt(p.delta())) / (2 * p.poli[2]);
                    tam = 2;
                }
                else
                {
                    raizes = (double *)realloc(raizes, (tam + 2) * sizeof(double));
                    raizes[tam] = (-p.poli[1] + sqrt(p.delta())) / (2 * p.poli[2]);
                    raizes[tam + 1] = (-p.poli[1] - sqrt(p.delta())) / (2 * p.poli[2]);
                    tam += 2;
                }
            }
        }
        if(termos == 2){
            raizes = (double *)malloc(sizeof(double));
            raizes[0] = -p.poli[0] / p.poli[1];
            tam++;
        }
        if(tam == 0)
            throw NaoRaizesReais();

        return raizes;
    }
    catch (NaoHaRaizes &e)
    {
        cout << "O polinômio não possui raiz!\n";
    }
    catch(NaoRaizesReais &e){
        cout << "Não foi possível encontrar as raizes no intervalo ou não há raízes reais\n";
    }
}

double Polinomio::delta() const
{
    return (pow(this->poli[1], 2) - (4 * this->poli[2] * this->poli[0]));
}