//i01.cpp
//este programa t pide un nmero y crea un arreglo con multiplos de 10, luego los smuestra

#include <iostream>
#include <cstring>
using namespace std;

//funcion que crea un arreglo dinmico con multiplos de10
int* crearArreglo(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = (i) * 10;
    }
    return arr;
}

int main() {
    int tam;
    cout << "ingrese el tamano del arreglo: ";
    cin >> tam;

    //llamamos a la funcion
    int* arreglo = crearArreglo(tam);

    //mostramos el contenido del arreglo
    cout << "arreglo con multiplos de 10: ";
    for (int i = 0; i < tam; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    //´para liberar la memoria
    delete[] arreglo;

    return 0;
}