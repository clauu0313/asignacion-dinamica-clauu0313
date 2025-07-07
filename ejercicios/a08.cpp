//a08.cpp
//este programa guarda solo los valores no 0 de una matriz para ahorrar memoria

#include <iostream>
using namespace std;

//nodo para guardar datos no 0 de la matriz
struct Nodo {
    int fila, columna, valor;
    Nodo* siguiente;
};

//inserta un nuevo valor no 0 en la lista
void insertar(Nodo*& cabeza, int f, int c, int v) {
    if (v == 0) return;

    Nodo* nuevo = new Nodo{f, c, v, nullptr};

    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

//busca el valor en una posicion dada
int buscar(Nodo* cabeza, int f, int c) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->fila == f && actual->columna == c) {
            return actual->valor;
        }
        actual = actual->siguiente;
    }
    return 0;
}

//muestra toda la matriz incluyendo los 0
void imprimirMatriz(Nodo* cabeza, int filas, int columnas) {
    cout << "matriz completa:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout<< buscar(cabeza, i, j) << " ";
        }
        cout<<endl;
    }
}

//libera la memoria
void liberar(Nodo*& cabeza) {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    Nodo* matriz = nullptr;
    int filas = 3, columnas = 4;

    
    insertar(matriz, 0, 1, 5);
    insertar(matriz, 1, 3, 8);
    insertar(matriz, 2, 0, -2);

    imprimirMatriz(matriz, filas, columnas);

    liberar(matriz);
    return 0;
}
