#include "polinomio.h"

int main()
{

    Polinomio a, b, c;
    double constante;

    /* cout << "\n=====SOMAS=====\n";
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
*/
    cout << "=====DIVISÃO=====\n";

    cout << "Informe três polinômios, sendo o primeiro deles um binômio e outros dois de sua escolha, para a divisão\n";
    cin >> a >> b >> c;
    Polinomio aux(b);
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
    return 0;
}