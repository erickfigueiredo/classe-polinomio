#include "polinomio.h"

int main()
{

    int opcao;
    cout << "= = = Menu de Seleção = = =\n\n1-Soma              2-Subtração\n3-Multiplicação     4-Divisão\n5-Cálculo           6-Raiz(es)\n7-Avalia            8-Comparação\n9-Limpa polinômio   10-Sair\n\nOpção: ";

    cin >> opcao;
    while (opcao != 10)
    {
        switch (opcao)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;

        default:
            cout << "Está opção não existe. Tente novamente.\n";
            break;
        }

        cout << "Opção: ";
        cin >> opcao;
    }

    return 0;
}