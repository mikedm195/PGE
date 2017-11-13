#ifndef ORDENADOR_H
#define ORDENADOR_H

template <class T>
class Ordenador  {
public:
    void burbuja(T * v, int n)  {
        qDebug() << "Burbuja";
        int i, j;
        T aux;
        for(i=0 ; i<=n ; i++)  {
            for(j=0 ; j<n-1 ; j++)  {
                if(v[j] > v[j+1])  {
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }
    void insercion(T * v, int n)  {
        qDebug() << "Insercion";
        int i,j;
        T aux;
        for (i = 1; i < n; i++) {
            j = i;
            while (j > 0 && v[j-1] > v[j]){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                j--;
            }
        }
    }

    void seleccion(T * v, int n)  {
        qDebug() << "Seleccion";
        int i,j;
        T aux;
        for (j = 0; j < n-1; j++) {
            int iMin = j;
            for (i = j+1; i < n; i++)
                if (v[i] < v[iMin])
                    iMin = i;
            if (iMin != j){
                aux = v[j];
                v[j] = v[iMin];
                v[iMin] = aux;
            }
        }
    }
};

#endif // ORDENADOR_H
