#include "Lista.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <typename T>
Lista<T>::Lista()
{
    primero = nullptr;
    ultimo = nullptr;
    iterador = primero;
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
    nuevo->sig = nullptr;
    if (primero == nullptr)
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
    if (pos == 0)
    {
        agregarAlPrincipio(elemento);
    }
    else
    {
        if (pos == cantidad)
        {
            agregarAlFinal(elemento);
        }
        else
            if (pos < cantidad)
            {
                agregarEnPos(primero, pos, elemento, c);
                cantidad++;
            }
    }
}

template<typename T>
void Lista<T>::agregarEnPos(nodo* &punt, int pos, T elemento, int c)
{
    if (punt != nullptr)
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
    while (primero != nullptr)
    {
        eliminar(0);
    }
}

template <typename T>
bool Lista<T>::esVacia() const
{
    return (primero == nullptr);
}

template <typename T>
bool Lista<T>::esta(T elemento)
{
    return esta(primero, elemento);
}

template <typename T>
bool Lista<T>::esta(nodo* punt, T elemento)
{
    if (punt != nullptr)
    {
        if (punt->elemento == elemento)
            return true;
        else
            return esta(punt->sig, elemento);
    }
    else
        return false;
}

template <typename T>
const T& Lista<T>::devolver(int pos)
{
    assert(pos < cantidad);
    int c = 0;
    return devolver(primero, pos,c);
}

template <typename T>
const T& Lista<T>::devolver(nodo *punt, int pos, int c)
{
    if (punt != nullptr )
    {
        if (c == pos)
        {
            return punt->elemento;
        }
        return devolver(punt->sig, pos, ++c);
    }
}

template <typename T>
void Lista<T>::inic()
{
    iterador = primero;
}

template <typename T>
void Lista<T>::sig()
{
    iterador = iterador->sig;
}

template <typename T>
const T& Lista<T>::elemento()
{
    return iterador->elemento;
}

template <typename T>
bool Lista<T>::final()
{
    return (iterador == nullptr);
}

template <typename T>
void Lista<T>::eliminar(int pos)
{
    assert(pos < cantidad);
    nodo* cursor = primero;
    nodo* aEliminar;
    int c = 0;
    bool termino = 0;
    if (pos > 0)
    {
        while (!termino)
        {
            if (c == pos-1)
            {
                aEliminar = cursor->sig;
                if (ultimo == aEliminar)
                    ultimo = cursor;
                cursor->sig = aEliminar->sig;
                delete aEliminar;
                aEliminar = nullptr;
                termino = 1;
            }
            c++;
            cursor =cursor->sig;
        }
    }
    if ( pos == 0)
    {
        aEliminar = cursor;
                if (ultimo == aEliminar)
                    ultimo = nullptr;
                cursor = aEliminar->sig;
                delete aEliminar;
                aEliminar = nullptr;
                primero = cursor;
    }
    cantidad--;
}



/***********************************************************************************/

template class Lista<int>;
template class Lista<char>;
template class Lista<bool>;
template class Lista<float>;
template class Lista<double>;
