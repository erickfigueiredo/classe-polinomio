#include "polinomio.h"

int main()
{

    Polinomio a, b, c;
    double constante;
    Polinomio aux(b);
/* 
    cout << "\n=====SOMAS=====\n";
    cout << "Informe dois polinômios para a soma\n";
    cin >> a >> b;
    cout << "informe a constante a ser usada no operador: ";
    cin >> constante;
    cout << "(" << a << ") + " << constante << " = " << a + constante << "\n\n";

    cout << "(" << a << ")++"
         << " = " << a++ << "\n\n";
    a--;

    cout << "(" << a << ") + (" << b << ") = " << a + b << "\n\n";

    a += b;

    cout << "(" << aux << ") += "
         << "(" << b << ") <--> " << a << "\n\n";

    cout << "=====SUBTRAÇÕES=====\n";

    cout << "Informe dois polinômios para a subtração\n";
    cin >> a >> b;
    aux = a;
    cout << "informe a constante a ser usada no operador: ";
    cin >> constante;
    cout << "(" << a << ") - " << constante << " = " << a - constante << "\n\n";

    cout << "(" << a << ")--"
         << " = " << a-- << "\n\n";
    a++;

    cout << "(" << a << ") - (" << b << ") = " << a - b << "\n\n";

    a -= b;

    cout << "(" << aux << ") -= "
         << "(" << b << ") <--> " << a << "\n\n";

    cout << "=====MULTIPLICAÇÃO=====\n";

    cout << "Informe dois polinômios para a multiplicação\n";
    cin >> a >> b;
    aux = a;
    cout << "informe a constante a ser usada no operador: ";
    cin >> constante;
    cout << "(" << a << ") * " << constante << " = " << a * constante << "\n\n";

    cout << "(" << a << ") * (" << b << ") = " << a * b << "\n\n";

    a *= b;

    cout << "(" << aux << ") *= "
         << "(" << b << ") <--> " << a << "\n\n";

    cout << "=====DIVISÃO=====\n";

    cout << "Informe três polinômios, sendo o primeiro deles um binômio e outros dois de sua escolha, para a divisão\n";
    cin >> a >> b >> c;
    aux = a;
    cout << "informe a constante a ser usada no operador: ";
    cin >> constante;
    try
    {
        cout << "(" << b << ") / " << constante << " = " << b / constante << "\n\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão inválida\n";
    }

    try
    {
        cout << "(" << b << ") / (" << a << ") = " << b / a << "\n\n";
    }
    catch (DivisaoInvalidaExcept &ex)
    {
        cout << "Divisão inválida\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão invalida\n";
    }

    try
    {
        cout << "(" << c << ") / (" << b << ") = " << c / b << "\n\n";
    }
    catch (DivisaoInvalidaExcept &ex)
    {
        cout << "Divisão inválida\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão invalida\n";
    }

    try
    {
        aux = b;
        b /= a;
        cout << "(" << aux << ") /= "
             << "(" << a << ") <--> " << b << "\n\n";

        b = aux;
    }
    catch (DivisaoInvalidaExcept &ex)
    {
        cout << "Divisão inválida\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão invalida\n";
    }

    try
    {
        aux = c;
        c /= b;
        cout << "(" << aux << ") /= "
             << "(" << b << ") <--> " << c << "\n\n";
    }
    catch (DivisaoInvalidaExcept &ex)
    {
        cout << "Divisão inválida\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão invalida\n";
    }



    cout << "=====COMPARAÇÃO DE POLINÔMIOS=====\n";
    cout << "Informe dois polinômios a serem comparados\n";
    cin >> a >> b;

    if(a == b)
        cout << "(" << a << ") == (" << b << ")\n";
    else
        cout << "(" << a << ") != (" << b << ")\n";
    
    cout << "=====INTEGRAL E DERIVADA DO POLINÔMIO=====\n";
    cout << "Informe um polinômio para ser integrado e outro para ser derivado\n";
    cin >> a >> b;

    cout << "Derivada de (" << a << ") = (" << a.derivada() << ")" << endl;
    cout << "Integral de (" << b << ") = (" << b.integral() << ")" << endl;
 
  */
    cout << "=====RAIZES E AVALIAÇÃO EM DADO X=====\n";
    cout << "Informe um polinômio para ser avaliado em certo X e para ser informado suas raizes\n";
    cin >> a;
    cout << "Informe um número para o polinômio ser avaliado: ";
    cin >> constante;
    try{
        cout << a.avalia(constante) << endl;

    }catch(NaoPodeAvaliar &e){
        cout << "Constantes não podem receber parâmetros de avaliação!\n";
    }

    /*
    try
    {
        int num;
        double *raizes = a.resolve(num);
        for(int i=0;i<num;i++)
            cout << "Raiz " << i << ": " << raizes[i] << endl;
        free(raizes);

    }
    catch(NaoHaRaizesExcept &ex)
    {
        cout << "O polinômio informado não tem raizes.\n";
    }
    catch(NaoRaizesReaisExcept &ex)
    {
        cout << "O polinômio não tem raiz real.\n";
    }

    cout << "(" << a << ") avaliado em x = " << constante << " é: " << a.avalia(constante) << endl;  


    cout << "=====RESTO DA DIVISÃO=====\n";

    cout << "Informe dois polinômios, sendo o primeiro deles obrigatoriamente um binômio:\n";
    cin >> a >> b;

    aux = a;

    try
    {
        cout << "(" << b << ") / (" << a << ") = " << b % a << "\n\n";
    }
    catch (DivisaoInvalidaExcept &ex)
    {
        cout << "Divisão inválida\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão invalida\n";
    }

    try
    {
        aux = b;
        b %= a;
        cout << "(" << aux << ") /= "
             << "(" << a << ") <--> " << b << "\n\n";

        b = aux;
    }
    catch (DivisaoInvalidaExcept &ex)
    {
        cout << "Divisão inválida\n";
    }
    catch (ArgumentoInvalidoExcept &ex)
    {
        cout << "Divisão invalida\n";
    }
    */
    
    return 0;
}