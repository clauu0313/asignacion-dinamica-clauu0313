//i03.cpp
//este programa crea una tabla (matriz) con filas y columnas que se eligen, luego, llena la tabla con nros y la muestra
#include <iostream>
using namespace std;

int main() {
    int filas, columnas;

    //se piden las dimensiones
    cout << "ingrese numero de filas:";
    cin >> filas;
    cout << "ingrese numero de columnas:";
    cin >> columnas;

    //se crea un arr de punteros-filas
    int** matriz = new int*[filas];

    //cada fila es un arr dinamico de columnas
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }

    //se llena la matriz con valores fila*columna
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = (i + 1) * (j + 1);
        }
    }

    //se imprime el contenido
    cout << "matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    //liberar memoria
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
