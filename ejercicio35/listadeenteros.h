#ifndef LISTADEENTEROS_H
#define LISTADEENTEROS_H

template <class T>
class ListaDeEnteros : public QVector<T> {
public:
    void ordenar(void (Ordenador<T>::*pf)(T * v, int n)){
//        pf(v,n);
        T * datos = this->data();
        int cantidad = this->size();

        (ordenador.*pf)(datos,cantidad);
    }

private:
    Ordenador<T> ordenador;
};

#endif // LISTADEENTEROS_H
