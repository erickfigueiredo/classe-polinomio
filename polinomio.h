#ifndef __POLINOMIO
#define __POLINOMIO

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

class PosicaoInvalidaExcept
{
};
class DivisaoInvalidaExcept
{
};
class ArgumentoInvalidoExcept
{
};
class NaoHaRaizesExcept
{
};
class NaoRaizesReaisExcept
{
};

class Polinomio
{
public:
	/* construtores e destrutores */

	// construtor padrão. Deve representar o número 0
	Polinomio(); //--FEITO--

	// Cria um Polinomio a partir de um número inteiro (positivo ou negativo)
	Polinomio(const int); //--FEITO--

	// Cria um Polinomio a partir de um vetor de coeficientes. Os coeficientes
	// deverão ser os coeficientes do polinômio (Posição 0 será a_0, posição 1 será a_1, ...).
	// O primeiro parâmetro representa o grau do polinômio.
	Polinomio(unsigned int n, double *a); //--FEITO--

	// Construtor de cópia
	Polinomio(const Polinomio &); //--FEITO--

	// destrutor
	~Polinomio(); //--FEITO--

	/* Operadores */

	// atribuição
	Polinomio &operator=(const Polinomio &); //--FEITO--

	// soma
	// adiciona dois Polinômios
	Polinomio operator+(const Polinomio &) const; //--FEITO--
	// adiciona um polinômio a um número
	Polinomio operator+(const double &) const; //--FEITO--
	Polinomio &operator+=(const Polinomio &);  //--FEITO--
	Polinomio &operator+=(const double &);	 //--FEITO--

	// subtração (segue o mesmo padrão da adição)
	Polinomio operator-(const Polinomio &) const; //--FEITO--
	Polinomio operator-(const double &) const;	//--FEITO--
	Polinomio &operator-=(const Polinomio &);	 //--FEITO--
	Polinomio &operator-=(const double &);		  //--FEITO--

	// multiplicação
	// TODO: você também deve implementar a multiplicação por um número à esquerda
	//Falta fazer isso aqui em cima
	Polinomio operator*(const Polinomio &)const;				   //--FEITO--
	Polinomio operator*(const double &)const;					   //--FEITO--
	Polinomio &operator*=(const Polinomio &);					   //--FEITO--
	Polinomio &operator*=(const double &);						   //--FEITO--
	friend Polinomio operator*(const double &, const Polinomio &); //--FEITO--

	// divisão por um polinômio de grau 1 da forma (x - a)
	// deve lançar 'ArgumentoInvalidoExcept' se o denominador não for da forma especificada acima
	// Sugestão: https://pt.wikipedia.org/wiki/Algoritmo_de_Briot-Ruffini
	Polinomio operator/(const Polinomio &) const; //--FEITO--
	Polinomio &operator/=(const Polinomio &);	 //--FEITO--

	// divide os coeficiente por um número
	Polinomio operator/(const int &) const; //--FEITO--
	Polinomio &operator/=(const int &);		//--FEITO--

	// resto da divisão por um polinômio de grau 1 da forma (x - 1)
	// deve lançar 'ArgumentoInvalidoExcept' se o denominador não for da forma especificada acima
	// Sugestão: https://pt.wikipedia.org/wiki/Algoritmo_de_Briot-Ruffini
	Polinomio operator%(const Polinomio &) const; //--FEITO--
	Polinomio &operator%=(const Polinomio &);	 //--FEITO--

	// Retorna i-ésimo coeficiente
	// Deve lançar 'PosicaoInvalidaExcept' se houver tentativa de acessar um bit não existente
	// Posição 0 indica o coeficiente do termo constante
	double operator[](int) const; //--FEITO--
	double &operator[](int);	  //--FEITO--

	// incrementos (adicionar 1) ao termo constante

	Polinomio operator++();		//--FEITO--
	Polinomio &operator++(int); //--FEITO--
	Polinomio operator--();		//--FEITO--
	Polinomio &operator--(int); //--FEITO--

	/* Comparação */

	// igualdade
	// Verificar se dois polinômios tem o mesmo grau e mesmos coeficientes
	bool operator==(const Polinomio &) const; //--FEITO--

	/* Entrada Saída */

	// lê/imprime de streams de entrada e saída
	friend istream &operator>>(istream &, Polinomio &);		  //--FEITO--
	friend ostream &operator<<(ostream &, const Polinomio &); //--FEITO--

	/* Operações (sem operadores) */

	// retorna a derivada do polinômio
	Polinomio derivada() const; //--FEITO--

	// retorna a integral do polinômio
	Polinomio integral() const; //--FEITO--

	// Dado um número 'a', calcula P(a)
	double avalia(double) const; //--FEITO--

	// resolve P(x) = 0. Encontra as raízes reais do polinômio
	// o parâmetro inteiro é o número de raízes encontradas
	// Se não encontrar raízes, deve lançar uma exceção
	// sugestão: use o método de Newton para encontrar uma raiz,
	// use o algoritmo de divisão para simplificar o polinômio...
	double *resolve(int &) const;

	int getGrau() const;

private:
	double *poli;
	int termos;
	void organizaVetor();
	double avaliaPoli(int, int, double) const;
	double delta() const;
};

#endif