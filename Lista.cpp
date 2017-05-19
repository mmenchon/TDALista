#include "Lista.h"
#include <iostream>
using namespace std;
template <typename T>
Lista<T>::Lista()
{
    primero = 0;
    ultimo = 0;
    cantidad = 0;
}

template <typename T>
void Lista<T>::agregarAlPrincipio(T elemento)
{
    nodo* nuevo = new nodo();
    nuevo->elemento = elemento;
    nuevo->sig = primero;
    primero = nuevo;
    if (cantidad == 0 )
        ultimo = primero;
    cantidad++;
}

template <typename T>
void Lista<T>::agregarAlFinal(T elemento)
{
    nodo* nuevo = new nodo();
    nuevo->elemento = elemento;
    nuevo->sig = 0;
    if (primero == 0)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
    cantidad++;
}

template <typename T>
void Lista<T>::agregarEnPos(int pos, T elemento)
{
    int c = 0;
    if (pos < cantidad)
    {
        agregarEnPos(primero, pos, elemento, c);
        cantidad++;
    }
    else
    {
        if (pos == cantidad-1)
        {
            agregarAlFinal(elemento);
            cantidad++;
        }
    }
}

template<typename T>
void Lista<T>::agregarEnPos(nodo* &punt, int pos, T elemento, int c)
{
    if (punt != 0)
    {
        if (c == pos)
        {
            nodo* nuevo = new nodo();
            nuevo->elemento=elemento;
            nuevo->sig=punt;
            punt=nuevo;
        };
        agregarEnPos(punt->sig, pos, elemento, ++c);
    }
}

template <typename T>
int Lista<T>::size() const
{
    return cantidad;
}

template <typename T>
Lista<T>::~Lista()
{
    //dtor
}

template<typename T>
void Lista<T>::imprimir()
{
    nodo* punt = primero;
    while (punt != 0)
    {
        cout << punt->elemento << endl;
        punt=punt->sig;
    }
}
template class Lista<int>;
