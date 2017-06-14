#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista
{
    private:
        struct nodo
        {
            T elemento;
            nodo* sig;
        };
        nodo* primero;
        nodo* ultimo;
        nodo* iterador;
        int cantidad;

        //metodos para el uso recursivo
        void agregarEnPos(nodo* &punt, int pos, T elemento, int c);
        bool esta(nodo* punt, T elemento);
        const T & devolver(nodo* punt, int pos, int c);

    public:
        Lista();
        virtual ~Lista();
        void agregarAlPrincipio(T elemento);
        void agregarAlFinal(T elemento);
        void agregarEnPos(int pos, T elemento);
        int size() const; //retorna el tamaño de la lista
        bool esVacia() const; // verifica que si la lista es vacia
        bool esta(T elemento); //verifica si esta el elemento
        const T & devolver(int pos); //devuelve elemento segun posicion
        void eliminar(int pos); //elimina un nodo dado una posicion

        // metodo para recorrer de manera iterativa
        void inic(); //reinicia el puntero iterator a la posicion primera
        void sig(); //hace que el puntero iterator apunte al siguiente
        const T & elemento(); //retorna el elemento del nodo en el cual iterator esta apuntando
        bool final(); // verifica si iterator esta en el ultimo nodo
};

#endif // LISTA_H
