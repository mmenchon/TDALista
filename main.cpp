#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista<int>* lista = new Lista<int>();
    int size = 10;
    int n=0;
    for(int i=0; i< size; i++)
    {
        cin  >> n ;
        lista->agregarAlPrincipio(n);
    }


    cout << lista->size() << endl;
    lista->imprimir();
    cout << lista->size() << endl;

    return 0;
}
