#include "polinomio.h"

int main()
{
    Polinomio a;
    double *r;
    int n;
    cin >> a;

    r = a.resolve(n);
    
    for(int i = 0; i < n; i++){
        cout << r[i] << endl;
    }

    free(r);
        
    return 0;
}