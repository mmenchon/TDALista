#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista<int>* lista = new Lista<int>();
    int size = 10;
    int n=0;
    if (lista->esVacia())
        cout << "la lista esta vacia" << endl;
    lista->inic();
    for(int i=1; i<50; i++)
    {
        cin  >> n ;
        lista->agregarAlFinal(n);
    }

    cout << "el elemento en la pos 2  es: " << lista->devolver(2) << endl;
    cout << "El tamanio de la lista es " << lista->size() << endl;
    lista->inic();
    while (!lista->final())
    {
        cout << lista->elemento() << endl;
        lista->sig();
    }
    cout << "El tamanio de la lista es " << lista->size() << endl;
    cin >> n;
    if (lista->esta(n))
        cout << "el elemento esta en la lista" << endl;
    else
        cout << "el elemento NO esta en la lista" << endl;
        lista->inic();
        cout << lista->elemento() << endl;

    return 0;
}
