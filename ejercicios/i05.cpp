//i05.cpp
//este programa crea dos cadenas de texto y muestra qué pasa cuando copias una,aunque cambies una la otra queda igual gracias a la copia

#include <iostream>
#include <cstring>
using namespace std;

class Cadena {
private:
    char* buffer; //-> almacena el texto

public:
    //constructor--> crea el buffer dinamicamente
    Cadena(const char* texto) {
        buffer = new char[strlen(texto) + 1];
        strcpy(buffer, texto);
    }

    //constructor d copia profunda-> crea una copia independiente del buffer
    Cadena(const Cadena& otra) {
        buffer = new char[strlen(otra.buffer) + 1];
        strcpy(buffer, otra.buffer);
    }

    //destructor-->libera la memoria del buffer
    ~Cadena() {
        delete[] buffer;
    }

    //metodo para cambiar el contenido del buffer
    void cambiar(const char* nuevoTexto) {
        delete[] buffer;
        buffer = new char[strlen(nuevoTexto) + 1];
        strcpy(buffer, nuevoTexto);
    }

    //mostrar el contnido actual
    void mostrar() const {
        cout << buffer << endl;
    }
};

int main() {
    //se crea una cadena original
    Cadena c1("right were u left me");

    //se crea una copia con constructor de copia profunda
    Cadena c2 = c1;

    //modifica la original
    c1.cambiar("champagne problems");

    //mostrar resultados
    cout << "cadena 1: ";
    c1.mostrar(); 

    cout << "cadena 2: ";
    c2.mostrar(); 
    return 0;
}
