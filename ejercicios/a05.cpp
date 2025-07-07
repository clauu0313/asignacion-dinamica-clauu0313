//a05.cpp
//este programa guarda numeros en hash para encontrarlos facilmente despues

#include <iostream>
using namespace std;

//nodo para una lista enlazada
struct Nodo {
    int clave;
    Nodo* siguiente;
};

//tabla hash simple con listas enlazadas
class TablaHash {
private:
    Nodo** tabla; 
    int capacidad;

    //funcion hash
    int hash(int clave) {
        return clave % capacidad;
    }

public:
    //constructor
    TablaHash(int tam) {
        capacidad = tam;
        tabla = new Nodo*[capacidad];
        for (int i = 0; i < capacidad; ++i) {
            tabla[i] = nullptr;
        }
    }

    //destructor
    ~TablaHash() {
        for (int i = 0; i < capacidad; ++i) {
            Nodo* actual = tabla[i];
            while (actual) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
        delete[] tabla;
    }
    //insertar nueva clave
    void insertar(int clave) {
        int idx = hash(clave);
        Nodo* nuevo = new Nodo{clave, tabla[idx]};
        tabla[idx] = nuevo;
    }

    //busca una clave en la tabla
    bool buscar(int clave) {
        int idx = hash(clave);
        Nodo* actual = tabla[idx];
        while (actual) {
            if (actual->clave == clave) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    //muestra la tabla
    void mostrar() {
        cout << "contenido de la tabla hash:\n";
        for (int i = 0; i < capacidad; ++i) {
            cout << "[" << i << "]: ";
            Nodo* actual = tabla[i];
            while (actual) {
                cout << actual->clave << " -> ";
                actual = actual->siguiente;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    TablaHash tabla(5);
    int n, valor;

    cout << "ingrese la cantidad de numeros para insertar en la tabla hash:  ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "numero " << i + 1 << ": ";
        cin >> valor;
        tabla.insertar(valor);
    }

    tabla.mostrar();

    int claveBuscar;
    cout << "que numero quieres buscar en la tabla? ";
    cin >> claveBuscar;

    if (tabla.buscar(claveBuscar)) {
        cout << "si esta en la tabla\n";
    } else {
        cout << "no se encontro\n";
    }

    return 0;
}
