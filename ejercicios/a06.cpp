//a06.cpp
//este programa crea un arreglo 3D y llenarlo con numeros

#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    //pedir dimensiones
    cout << "dimensiones del arreglo 3D (X, Y, Z): ";
    cin >> x >> y >> z;

    //crear arreglo 3D con memoria dinamica
    int*** arreglo = new int**[x];
    for (int i = 0; i < x; ++i) {
        arreglo[i] = new int*[y]; 
        for (int j = 0; j < y; ++j) {
            arreglo[i][j] = new int[z];
        }
    }

    //llenar el arreglo con valores
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                arreglo[i][j][k] = i + j + k;
            }
        }
    }

    //mostrar valores guardados
    cout << "valores del arreglo 3D:\n";
    for (int i = 0; i < x; ++i) {
        cout << "capa " << i << ":\n";
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << arreglo[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //liberar memoria por nivel
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            delete[] arreglo[i][j];
        }
        delete[] arreglo[i];
    }
    delete[] arreglo;

    return 0;
}
