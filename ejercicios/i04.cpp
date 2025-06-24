//i04.cpp
//este programa te deja registrar libros con su título y autor luego, te muestra toda la lista de los libros que ingresaste.

#include <iostream>
#include <string>
using namespace std;

//estrctura con los datos de un libro
struct Libro {
    string titulo;
    string autor;
};

int main() {
    int n;

    //se pide la cant a registrar
    cout << "cuantos libros desea ingresar?:";
    cin >> n;

    //crear arreglo dinamico d punteros a Libro
    Libro** libros = new Libro*[n];

    //se ingresan los datos de cada libro
    for (int i = 0; i < n; ++i) {
        //se reserva memoria para cada objeto
        libros[i] = new Libro; 
        cin.ignore(); //-->para limpiar buffer

        cout << "libro " << i + 1 << "  titulo: ";
        getline(cin, libros[i]->titulo);

        cout << "autor: ";
        getline(cin, libros[i]->autor);
    }

    //mostrar lista de libros 
    cout << "\nLista de libros:\n";
    for (int i = 0; i < n; ++i) {
        cout << "- " << libros[i]->titulo << " por " << libros[i]->autor << endl;
    }

    //liberar memoria
    for (int i = 0; i < n; ++i) {
        delete libros[i];
    }
    delete[] libros;

    return 0;
}
