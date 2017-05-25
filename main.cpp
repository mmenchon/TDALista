#include <iostream>
#include "Lista.h"
using namespace std;

void cargarLista(Lista<int>* &lista)
{
    int size = 10;
    int n=0;
    if (lista->esVacia())
        cout << "la lista esta vacia" << endl;
    lista->inic();
    for(int i=0; i<size; i++)
    {
        cin  >> n ;
        lista->agregarAlFinal(n);
    }
}

void imprimirLista(Lista<int>* lista)
{
    lista->inic();
    while (!lista->final())
    {
        cout << lista->elemento() << endl;
        lista->sig();
    }
}

int main()
{
    Lista<int>* lista = new Lista<int>();
    cargarLista(lista);

    cout << "el elemento en la pos 2  es: " << lista->devolver(9) << endl;
    cout << "El tamanio de la lista es " << lista->size() << endl;

    imprimirLista(lista);

    cout << "El tamanio de la lista es " << lista->size() << endl;

    int n=0;
    cin >> n;
    if (lista->esta(n))
        cout << "el elemento esta en la lista" << endl;
    else
        cout << "el elemento NO esta en la lista" << endl;

    lista->eliminar(0);
    imprimirLista(lista);
    lista->agregarAlPrincipio(50);
    cout << "elemento agregado" << endl;
    lista->~Lista();
    cout << "lista eliminada " << lista->devolver(0) << endl;
    return 0;
}
