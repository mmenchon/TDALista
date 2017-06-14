#include <iostream>
#include "Lista.h"
using namespace std;

void cargarLista(Lista<int> &lista)
{
    int size = 10;
    int n=0;
    if (lista.esVacia())
        cout << "la lista esta vacia" << endl;
    lista.inic();
    for(int i=0; i<size; i++)
    {
        cin  >> n ;
        lista.agregarAlFinal(n);
    }
}

void imprimirLista(Lista<int> lista)
{
    lista.inic();
    while (!lista.final())
    {
        cout << lista.elemento() << endl;
        lista.sig();
    }
}

int main()
{
    Lista<int> lista ;
    //cargarLista(lista);
    cout << "pipa" << endl;
    lista.agregarEnPos(0, 8);
    cout << "pipa2" << endl;
    lista.agregarEnPos(1,4);
    lista.agregarAlFinal(5);
    cout << "el elemento en la pos 0  es: " << lista.devolver(0) << endl;
    cout << "El tamanio de la lista es " << lista.size() << endl;

    imprimirLista(lista);

    cout << "El tamanio de la lista es " << lista.size() << endl;

    int n=0;
    cin >> n;
    if (lista.esta(n))
        cout << "el elemento esta en la lista" << endl;
    else
        cout << "el elemento NO esta en la lista" << endl;

    lista.eliminar(0);
    imprimirLista(lista);
    lista.agregarAlPrincipio(50);
    cout << "elemento agregado" << endl;
    imprimirLista(lista);
    lista.~Lista();
    cout << "lista eliminada " << endl;
    imprimirLista(lista);
    return 0;
}
