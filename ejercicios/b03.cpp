//b03.cpp
// este programa cambia el tamaño de un arreglo dinamico

#include <iostream>
using namespace std;

int main() {
    int n;

    // pedimos el tamaño inicial del arreglo
    cout << "ingrese el tamaño inicial del arreglo: ";
    cin >> n;

    // creamos el arreglo dinamico original
    int* arreglo = new int[n];

    // llenamos el arreglo con valores del 1 al n
    for (int i = 0; i < n; ++i) {
        arreglo[i] = i + 1;
    }

    // mostramos el arreglo original
    cout << "arreglo original: ";
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // simulamos redimensionar: creamos nuevo arreglo de tamaño mayor
    int nuevoTam = n + 3; // por ejemplo, agrandamos en 3
    int* nuevoArreglo = new int[nuevoTam];

    // copiamos los valores del arreglo original al nuevo
    for (int i = 0; i < n; ++i) {
        nuevoArreglo[i] = arreglo[i];
    }

    // llenamos el resto con ceros
    for (int i = n; i < nuevoTam; ++i) {
        nuevoArreglo[i] = 0;
    }

    // liberamos la memoria del arreglo original
    delete[] arreglo;

    // el puntero ahora apunta al nuevo arreglo
    arreglo = nuevoArreglo;
    n = nuevoTam;

    // mostramos el arreglo redimensionado
    cout << "arreglo redimensionado: ";
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // liberamos el nuevo arreglo
    delete[] arreglo;

    return 0;
}