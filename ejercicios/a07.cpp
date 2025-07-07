//a07.cpp
//este programa te deja guardar palabras en un diccionario y verlas o borrarlas

#include <iostream>
#include <cstring>
using namespace std;

class Diccionario {
private:
    char** palabras;
    int cantidad;
    int capacidad;

    //aumentar espacio cuando se llena
    void redimensionar() {
        int nuevaCap = capacidad * 2;
        char** nuevo = new char*[nuevaCap];
        for (int i = 0; i < cantidad; ++i) {
            nuevo[i] = palabras[i];
        }
        delete[] palabras;
        palabras = nuevo;
        capacidad = nuevaCap;
    }

public:
    //constructor
    Diccionario(int cap = 5) {
        capacidad = cap;
        cantidad = 0;
        palabras = new char*[capacidad];
    }

    //destructor
    ~Diccionario() {
        for (int i = 0; i < cantidad; ++i) {
            delete[] palabras[i];
        }
        delete[] palabras;
    }

    //agregar nueva palabra
    void agregar(const char* nueva) {
        if (cantidad == capacidad) {
            redimensionar();
        }
        palabras[cantidad] = new char[strlen(nueva) + 1];
        strcpy(palabras[cantidad], nueva);
        cantidad++;
    }

    //mostrar todas las palabras
    void mostrar() const {
        cout << "palabras en el diccionario:\n";
        for (int i = 0; i < cantidad; ++i) {
            cout << "- " << palabras[i] << endl;
        }
    }

    //eliminar una palabra
    void eliminar(const char* objetivo) {
        for (int i = 0; i < cantidad; ++i) {
            if (strcmp(palabras[i], objetivo) == 0) {
                delete[] palabras[i];
                for (int j = i; j < cantidad - 1; ++j) {
                    palabras[j] = palabras[j + 1];
                }
                cantidad--;
                break;
            }
        }
    }
};

int main() {
    Diccionario dic;

    dic.agregar("carro");
    dic.agregar("tren");
    dic.agregar("avion");
    dic.agregar("barco");

    dic.mostrar();

    cout << "\neliminando la palabra 'tren'...\n";
    dic.eliminar("tren");

    dic.mostrar();

    return 0;
}
