//----------------------------------------------------------------------------------------------------------------------------------------------//
/* 
    Este trabalho foi desenvolvido pelos alunos: Carlos Eduardo, Érick Lima, Guilherme Oliveira e Thiago Ferreira
    E tem por objetivo representar, por meio de uma classe, um polinômio e suas propriedades
    Os métodos implementados abaixo foram prototipados no arquivo polinômio.h, que foi disponibilizado pelo professor.
 */

#include "polinomio.h"

//Abaixo está a implementação dos métodos construtores:

/*----------------------------Construtores----------------------------*/
//Este construtor é o responsável por alocar os recursos para o polinômio mais simples possível, com apenas 1 termo.
Polinomio::Polinomio()
{
    termos = 1;
    poli = (double *)calloc(1, sizeof(double));
}

//Este construtor é o responsável por alocar os recursos para o polinômio mais simples possível e atribuir um valor (informado pelo usuário) ao seu único termo.
Polinomio::Polinomio(const int num)
{
    termos = 1;
    poli = (double *)malloc(sizeof(double));
    *poli = num;
}

//Este construtor é responsável por alocar os resursos para o polinômio de tamanho n (informado pelo usuário) e o preenche com os n termos também informados pelo usuário.
Polinomio::Polinomio(unsigned int n, double *a)
{
    termos = n;
    poli = (double *)malloc(termos * sizeof(double));
    for (int i = 0; i < termos; i++)
        poli[i] = a[i];
}

//Este é o construtor de cópia. Ele é responsável por fazer a cópia no momento em que é feita uma atribuição no ato de instanciação de um novo Polinômio.
Polinomio::Polinomio(const Polinomio &p)
{
    this->termos = p.termos;
    poli = (double *)malloc(this->termos * sizeof(double));
    for (int i = 0; i < this->termos; i++)
        this->poli[i] = p.poli[i];
}

/*----------------------------Destrutor----------------------------*/

//Este é o método destrutor. Ele é responsável por desalocar os recursos alocados no ato da criação do objeto nos construtores.
Polinomio::~Polinomio()
{
    free(poli);
}


/*----------------------------Operadores----------------------------*/

//Abaixo estão implementadas as sobrecargas dos operadores sobre os polinômios.

//Abaixo, o operador de atribuição.

/* Se o objeto a ser atribuído for igual ao proprio objeto que invovou o método, então, retorna esse objeto. 
 * Senão, a quantidade de termos é copiada do objeto atribuído, a quantidade de memória utilizada é redefinida para a quantidade de termos
 * e os termos são copiados para o novo objeto.
 */

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

//Abaixo, o operador de soma:

/* Primeiro, é criado um objeto que receberá o resultado da operação, tendo em vista que o método é constante e não pode alterar nenhum parâmetro passado. 

  Se a quantidade de termos do primeiro objeto for maior ou igual à quantidade de termos do segundo objeto, toda a operação de redefinição de tamanho em memória do polinômio é refeita com base na quantidade de termos do objeto que invocou o método e
  polinômio do objeto resultado recebe os valores do primeiro polinômio. Logo após, esses valores são incrementados com os valores do segundo polinômio.

  Do contrário, a mesma operação é feita tendo como base o número de termos do polinômio passado como parâmetro.
 */

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

/* Primeiramente é criado o objeto do resultado e feito o processo de redefinição de uso de memória.
   
   Depois, o objeto de resultado recebe os valores dos termos do objeto invocador.

   Logo após, os valores dentro do objeto invocador são acrescidos do número passado como parâmetro.

 */
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

/* 
  Caso o numero de termos seja maior ou igual ao número de termos do objeto passado, é feito o incremento dos valores dos termos no objeto invocador.
  
  Caso contrário, criado um novo objeto semelhante à this (aux), e sua quantidade de memória é redefinida com base na quantidade de termos do objeto passado como parâmetro.

  Depois, para cada termo em this, o seu valor é o resultado da soma dos termos de aux com o objeto passado como parâmetro. 

  Ao final, a referência do objeto invocador é retornada.
 */
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

//A implementação deste método é semelhante ao anterior, entretanto, utiliza-se da sobrecarga do operador anteriormente implementada.

Polinomio &Polinomio::operator+=(const double &num)
{
    this->poli[0] += num;
    return *this;
}

//------Subtracao de objetos

//Esse método consiste em sobrecarregar o operador de subtração para que sejam feitas as subtrações dos valores de dois polinômios.
/* 
    Antes de tudo, é verificado se o polinômio invocador do método possui mais termos do que o subtrator.
    Na operação ...
    Primeiro, é criado um polinômio novo que será usado par fazer a operação e salvar os resultados
    Depois de ter o tamanho realocado, o polinômio criado recebe os valores dos termos do primeiro polinômio a se operar
    Em seguida, os valores contidos no polinômio resultado são decrementados com os valores dos termos do segundo polinômio
 */
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
//O funcionamento deste método é parecedio com o anterior, diferindo apenas no fato de que a subtração é feita de um valor fixo, 
//e não mais com os valores dos termos de um polinômio.

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

/* 
  O decremento do polinômio é feito da seguinte forma:
  Primeiro, é feito o teste para saber se o primeiro polinômio é menor ou igual ao segundo.
  Caso seja, o decremento é feito, termo a termo, tradicionalmente.
  Caso contrário, é criado um polinômio de resultado (aux) com o número de termos do maior polinômio
  Em seguida a quantidade de termos do polinômio passado é copiado para o polinômio invocador.
  Após isso é feito o decremento com base na quantidade de termos do polinômio.
 */
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

/* 
    Nesse método, o decremento é feito sempre no termo independente. Um valor double é passado, e o termo é decrescido do valor passado.
 */
Polinomio &Polinomio::operator-=(const double &num)
{
    this->poli[0] -= num;
    return *this;
}

//------Multiplicacao de objetos

/* 
    O procedimento padrão dessa operação é semelhante aos demais métodos descritos. 
    Após o procedimento padrão, para a quantidade de termos do polinômio invocador, e, para a quantidade de termos do
    polinômio passado como parâmetro, o polinômio de resultado recebe a multiplicação entre os respectivos termos dos dois polinômios.

 */
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
/* 
    A multiplicação de um polinômio por um número baseia-se em percorrer os termos do polinômio e fazer a multiplicação termo a termo
    pelo número em questão. 
 */

Polinomio Polinomio::operator*(const double &num) const
{

    Polinomio resultado(*this);

    for (int i = 0; i < this->termos; i++)
        resultado.poli[i] *= num;

    return resultado;
}

//------Multiplicacao incremental de objeto com objeto

/* 
    Para esse método é feito o procedimento padrão de criação e dimensionamento do polinômio de resultado
    Logo após, é feita a multiplicação incremental dos elementos no polinômio de resultado de acordo com a quantidade de termos do
    polinômio invocador.
 */
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
/* 
  A implementação desse método é bem simples. A multiplicação é feita termo a termo incrementalmente pelo número passado.
 */
Polinomio &Polinomio::operator*=(const double &num)
{
    for (int i = 0; i < this->termos; i++)
        this->poli[i] *= num;

    return *this;
}

//------Div/igual por inteiro

/* A divisão dos termos de um polinômio por um número inteiro é feita somente se o divisor for diferente de 0. Caso seja igual a 0,
   e lançada uma exceção de divisão inválida.
   Se o divisor for diferente de 0, cada termo é dividido individualmente pelo numero passado.
 */
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

/* 
    Procedimento semelhante ao do método anterior, mudando apenas o tipo do divisor par iteiro.
 */
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

/* 
    A divisão de um polinômio por outro é feita através desse método.
    Se a quantidade de termos do polinômio passado como parâmetro for diferente de 2, é lançada uma exceção de argumento inválido.
    
 */
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
    int tam = 0;
    try
    {
        Polinomio p(*this);

        double *bin, *raizes;
        double x1, x = num;
        bool temRaiz = false;
        if (p.termos == 1)
        {
            throw NaoHaRaizesExcept();
        }
        for (int i = termos; i > 3; i--)
        {
            if (p.derivada().avalia(x) == 0)
            {
                num = tam;
                throw ArgumentoInvalidoExcept();
            }
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
                bin[0] = -x;
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
                    raizes[0] = (-1 * p.poli[1] + sqrt(p.delta())) / (2 * p.poli[2]);
                    raizes[1] = (-1 * p.poli[1] - sqrt(p.delta())) / (2 * p.poli[2]);
                    tam = 2;
                }
                else
                {
                    raizes = (double *)realloc(raizes, (tam + 2) * sizeof(double));
                    raizes[tam] = (-1 * p.poli[1] + sqrt(p.delta())) / (2 * p.poli[2]);
                    raizes[tam + 1] = (-1 * p.poli[1] - sqrt(p.delta())) / (2 * p.poli[2]);
                    tam += 2;
                }
            }
        }
        if (termos == 2)
        {
            raizes = (double *)malloc(sizeof(double));
            raizes[0] = -p.poli[0] / p.poli[1];
            tam++;
        }
        if (tam == 0)
            throw NaoRaizesReaisExcept();

        num = tam;
        return raizes;
    }
    catch (NaoHaRaizesExcept &e)
    {
        cout << "O polinômio não possui raiz!\n";
        num = tam;
    }
    catch (NaoRaizesReaisExcept &e)
    {
        cout << "Não foi possível encontrar as raizes no intervalo ou não há raízes reais\n";
        num = tam;
    }
    catch (ArgumentoInvalidoExcept &e)
    {
        cout << "Divisao inválida por ZERO!\n";
    }
}

double Polinomio::delta() const
{
    return (pow(this->poli[1], 2) - (4 * this->poli[2] * this->poli[0]));
}