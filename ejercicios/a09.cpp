//a09.cpp
//este programa crea arr dinamicos para cualquier tipo de dato

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array {
private:
    T* datos;
    int tam;

public:
    //constructor
    Array(int n) {
        tam = n;
        datos = new T[tam];
    }

    //destructor
    ~Array() {
        delete[] datos;
    }

    T& operator[](int i) {
        return datos[i];
    }

    //funcion para mostrar los elementos del arreglo
    void mostrar() {
        for (int i = 0; i < tam; ++i) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    //arreglo de enteros
    cout << "arreglo de enteros: " << endl;
    Array<int> arrEnteros(5);
    for (int i = 0; i < 5; ++i) {
        arrEnteros[i] = i + 1;
    }
    arrEnteros.mostrar();

    //arreglo con float
    cout << "\narreglo de decimales: " << endl;
    Array<float> arrFloats(3);
    arrFloats[0] = 1.1;
    arrFloats[1] = 2.2;
    arrFloats[2] = 3.3;
    arrFloats.mostrar();

    //arreglo de strings
    cout << "\narreglo de strings:" << endl;
    Array<string> arrStrings(2);
    arrStrings[0] = "winter";
    arrStrings[1] = "autumn";
    arrStrings.mostrar();

    return 0;
}
