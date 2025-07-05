//i09.cpp
//este programa define una clase que administra un arreglo de enteros en memoria dinamica

#include <iostream>
using namespace std;

//clase que maneja un arreglo de enteros con memoria dinamica
class VectorEnteros {
private:
    int* arreglo;
    int tam;

public:
    //constructor, reserva memoria para el arreglo
    VectorEnteros(int n) {
        tam = n;
        arreglo = new int[tam];
    }

    //destructor, libera la memoria reservada
    ~VectorEnteros() {
        delete[] arreglo;
    }

    //llenar el arreglo con datos ingresados por el usuario
    void llenar() {
        cout << "ingresa " << tam << " numeros:" << endl;
        for (int i = 0; i < tam; ++i) {
            cout << "elemento " << i + 1 << ": ";
            cin >> arreglo[i];
        }
    }

    //mostrar los elementos del arreglo
    void mostrar() const {
        cout << "el contenido del arreglo es : ";
        for (int i = 0; i < tam; ++i) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "cuantos numeros quieres guardar? ";
    cin >> n;

    VectorEnteros v(n);
    v.llenar();
    v.mostrar();

    return 0;
}
