#ifndef LISTADO_H
#define LISTADO_H

template <class T> class Listado  {
public:
        Listado(int n=10);
        bool add(T nuevo);
        T get(int i) const;
        int length() const;
        Listado<T> operator+(const Listado<T> otro);

private:
        int cantidad;
        int libre;
        T *v;
};


template <class T> Listado<T>::Listado(int n) : cantidad(n), libre(0), v(new T[n])  {

}

template <class T> bool Listado<T>::add(T nuevo)  {
        if (libre < cantidad)  {
                v[libre] = nuevo;
                libre++;
                return true;
        }
        return false;
}


template <class T> T Listado<T>::get(int i) const  {  return v[i];  }

template <class T> int Listado<T>::length() const  {  return libre;  }

template <class T> Listado<T> Listado<T>::operator+(const Listado<T> otro)  {
        Listado<T> res(this->length() + otro.length());

        for(int i = 0;i<this->length();i++)
            res.add(this->get(i));

        for(int i = 0;i<otro.length();i++)
            res.add(otro.get(i));

        return res;
}

#endif // LISTADO_H
