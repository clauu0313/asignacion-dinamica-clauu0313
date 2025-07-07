//a10.cpp
//este programa simula un archivo usando un buffer de texto dinamico

#include <iostream>
#include <cstring>
using namespace std;

class ArchivoVirtual {
private:
    char* buffer;      
    int capacidad;    
    int longitud;  

public:
    //constructor
    ArchivoVirtual(int cap = 50) {
        capacidad = cap;
        buffer = new char[capacidad];
        buffer[0] = '\0'; 
        longitud = 0;
    }

    //destructor
    ~ArchivoVirtual() {
        delete[] buffer;
    }

    //funcion para escribir contenido al final del buffer
    void escribir(const char* texto) {
        int lenTexto = strlen(texto);

        //redimensionar si no hay suficiente espacio
        if (longitud + lenTexto + 1 > capacidad) {
            int nuevaCapacidad = capacidad * 2;
            char* nuevoBuffer = new char[nuevaCapacidad];
            strcpy(nuevoBuffer, buffer);
            delete[] buffer;
            buffer = nuevoBuffer;
            capacidad = nuevaCapacidad;
        }

        //añadir el texto nuevo al final del buffer
        strcat(buffer, texto);
        longitud += lenTexto;
    }

    //funcion para mostrar el contenido actual del buffer
    void mostrar() const {
        cout << "contenido del archivo virtual:\n";
        cout << buffer << endl;
    }
};

int main() {
    ArchivoVirtual archivo;

    archivo.escribir("hola ");
    archivo.escribir("hello ");
    archivo.escribir("adios ");

    archivo.mostrar();

    return 0;
}
