#include "Lista.h"
template <typename T>
Lista<T>::Lista()
{
    primero = 0;
    ultimo = 0;
    cantidad = 0;
}

template <typename T>
void Lista<T>::AgregarAlPrincipio(T elemento)
{
    nodo* nuevo = new Lista();
    nuevo->elemento = elemento;
    nuevo->sig = primero;
    primero = nuevo;
    if (cantidad == 0 )
        ultimo = primero;
    cantidad++;
}


template <typename T>
Lista<T>::~Lista()
{
    //dtor
}
