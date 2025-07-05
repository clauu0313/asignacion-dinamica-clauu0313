//i06.cpp
//este programa permite ingresar numeros a un arreglo dinamico
//tmbien redimendsiona el arreglo a un nuevo tamaño, conservando los datos anteriores
//los nuevos espacios se llenan con ceros para completar el arreglo

#include <iostream>
using namespace std;

//funcion que redimensiona un arr dinamico
int* redimensionar(int* arreglo, int tamActual, int nuevoTam) {
    int* nuevoArr = new int[nuevoTam];

    //copia datos antiguos
    for (int i = 0; i < tamActual; ++i) {
        nuevoArr[i] = arreglo[i];
    }

    //llenar nuevos espacios con ceros
    for (int i = tamActual; i < nuevoTam; ++i) {
        nuevoArr[i] = 0;
    }

    delete[] arreglo;
    return nuevoArr;
}

int main() {
    int tamInicial = 3;//por ejm digamos q 3
    int* numeros = new int[tamInicial];

    //ingresar datos al arreglo original
    cout << "ingresa " << tamInicial << " numeros:" << endl;
    for (int i = 0; i < tamInicial; ++i) {
        cout << "numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    //mostrar arreglo original
    cout << "arreglo inicial: ";
    for (int i = 0; i < tamInicial; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    //redimensionar el arreglo a tamaño por ejm 7
    int nuevoTam = 7;
    numeros = redimensionar(numeros, tamInicial, nuevoTam);

    //mostrar el arr redimensionado
    cout << "el arreglo redimensionado es : ";
    for (int i = 0; i < nuevoTam; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    delete[] numeros;
    return 0;
}
