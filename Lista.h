#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregarAlPrincipio(T elemento);
        void agregarAlFinal(T elemento);
        void agregarEnPos(int pos, T elemento);
        int size() const;
        void imprimir();

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

        void agregarEnPos(nodo* &punt, int pos, T elemento, int c);
};

#endif // LISTA_H
