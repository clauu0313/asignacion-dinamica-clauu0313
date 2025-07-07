//a01.cpp
//este programa te permite ingresar varios numeros y los guarda en una lista enlazada

#include <iostream>
using namespace std;

//estructura de un nodo de la lista
struct Nodo {
    int dato;
    Nodo* siguiente;
};

//inserta un nuevo nodo con valor al final de la lista
void insertarFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo;        //para reservar memoria
    nuevo->dato = valor;           //asignar el valor
    nuevo->siguiente = nullptr;    //el nuevo nodo apunta a null
    
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;  //enlazando el nuevo nodo al final
    }
}

//muestra todos los elementos de la lista enlazada
void mostrarLista(Nodo* cabeza) {
    cout << "lista enlazada: ";
    Nodo* actual = cabeza;
    while (actual) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

//libera la memoria de todos los nodos
void liberarLista(Nodo*& cabeza) {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;  //eliminamos cada nodo
    }
    cabeza = nullptr;
}

int main() {
    Nodo* lista = nullptr;
    int n, valor;
    
    cout << "cuantos numeros quieres agregar a la lista? ";
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cout << "numero " << i + 1 << ": ";
        cin >> valor;
        insertarFinal(lista, valor);
    }
    
    mostrarLista(lista);
    liberarLista(lista);
    
    return 0;
}