//b02.cpp
// este programa crea un arreglo dinámico cuyo tamaño debe ser elegido y lo llena con valores consecutivos

#include <iostream>
using namespace std;

int main() {
    int n;

    // pedimos el tamaño del arreglo
    cout << "ingrese el tamaño del arreglo: ";
    cin >> n;

    // creamos un arreglo dinamico de tamaño n
    int* arr = new int[n];

    // llenamos el arreglo con valores consecutivos desde 1
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    // mostramos el contenido del arreglo
    cout << "valores en el arreglo: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // liberamos la memoria dinamica reservada para el arreglo
    delete[] arr;

    return 0;
}
