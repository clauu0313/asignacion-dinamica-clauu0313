//b09.cpp
//este programa inicializa un arr. dinamico con valores del 1 - 5 y muestra

#include <iostream>
using namespace std;

int main() {
    //inicializamos un arr dinamico de 5 enteros
    int* arr = new int[5];

    //asignacion de valores del 1 al 5 con bucle
    for (int i = 0; i < 5; ++i) {
        arr[i] = i + 1;
    }

    
    //se muestran los valores del arr
    cout << "arreglo: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    //liberar la memoria
    delete[] arr;
    return 0;
}
