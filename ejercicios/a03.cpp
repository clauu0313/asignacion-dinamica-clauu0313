//a03.cpp
//este programa guarda los numeros ingresados en forma de arbol binario, luego los muestra ordenadosde menor a mayor

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;

    Nodo(int val) : dato(val), izq(nullptr), der(nullptr) {}
};

//clase que representa el arbol binario completo
class ArbolBinario {
private:
    Nodo* raiz;

    //funcion recursiva para insertar un nuevo valor
    Nodo* insertarRecursivo(Nodo* nodo, int valor) {
        if (!nodo) {
            return new Nodo(valor);
        }
        if (valor < nodo->dato) {
            nodo->izq = insertarRecursivo(nodo->izq, valor);
        } else {
            nodo->der = insertarRecursivo(nodo->der, valor);
        }
        return nodo;
    }

    //recorre en orden (izq, raiz, der)
    void enOrden(Nodo* nodo) {
        if (!nodo) return;
        enOrden(nodo->izq);
        cout << nodo->dato << " ";
        enOrden(nodo->der);
    }

    //liberar memoria
    void liberar(Nodo* nodo) {
        if (!nodo) return;
        liberar(nodo->izq);
        liberar(nodo->der);
        delete nodo;
    }

public:
    //constructor, empieza con arbol vacio
    ArbolBinario() : raiz(nullptr) {}

    //destructor, libera toda la memoria
    ~ArbolBinario() {
        liberar(raiz);
    }

    //metodo para insertar un numero
    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    //muestra los elementos en orden
    void mostrarEnOrden() {
        cout << "elementos en orden: ";
        enOrden(raiz);
        cout << endl;
    }
};

int main() {
    ArbolBinario arbol;
    int n, num;

    cout << "ingrese la cantidad de numeros que quiere guardar en el arbol: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "numero " << i + 1 << ": ";
        cin >> num;
        arbol.insertar(num);
    }

    //mostrar los elementos en orden creciente
    arbol.mostrarEnOrden();

    return 0;
}
