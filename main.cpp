#include "polinomio.h"

int main(){
    /*  TESTEM OS METODOS AQUI   */
    double v[3] = {};
    Polinomio a(3,v);
    cin >> a;
    int n ;
    cin >> n;
    try{
        cout << a[n] << endl;
    }
    catch (posicaoInvalidaExcept &a){
        cout << "voce esta acessando uma posicao invalida, tente novamente" << endl;
    }
    return 0;
}