#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void AgregarAlPrincipio(T elemento);

    protected:

    private:
        struct nodo
        {
            T elemento;
            nodo* sig;
        };
        nodo* primero;
        nodo* ultimo;
        int cantidad;
};

#endif // LISTA_H
