//a04.cpp
//este programa guarda varios numeros en una lista que se expnde sola como vector

#include <iostream>
using namespace std;

class VectorDinamico {
private:
    int* datos; 
    int capacidad;    
    int tam;          

public:
    
    VectorDinamico() {
        capacidad = 2;
        tam = 0;
        datos = new int[capacidad];
    }

    
    ~VectorDinamico() {
        delete[] datos;
    }

    //agrega un nuevo numero, si no hay espacio, se duplica la capacidad
    void agregar(int valor) {
        if (tam == capacidad) {
            //duplicar capacidad
            int nuevaCapacidad = capacidad * 2;
            int* nuevoArr = new int[nuevaCapacidad];

            //copiar los datos anteriores
            for (int i = 0; i < tam; ++i) {
                nuevoArr[i] = datos[i];
            }

            delete[] datos;
            datos = nuevoArr;
            capacidad = nuevaCapacidad;
        }

        datos[tam] = valor;
        tam++;
    }

    //mostrar todos los elementos guardados
    void mostrar() const {
        cout << "elementos en el vector: ";
        for (int i = 0; i < tam; ++i) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    VectorDinamico vec;
    int n, num;

    cout << "ingrese una cantidad de numeros a guardar: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "numero " << i + 1 << ": ";
        cin >> num;
        vec.agregar(num);
    }

    vec.mostrar();

    return 0;
}
