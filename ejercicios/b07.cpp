///b07.cpp
//este programa crea un arreglo dinamico de estructuras Producto

#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

int main() {
    int n;
    cout << "cuantos productos desea ingresar? ";
    cin >> n;
    cin.ignore(); // para limpiar el salto de linea

    Producto* productos = new Producto[n];

    for (int i = 0; i < n; ++i) {
        cout << "producto " << i + 1 << " nombre: ";
        getline(cin, productos[i].nombre);
        cout << "producto " << i + 1 << " precio: ";
        cin >> productos[i].precio;
        cin.ignore();
    }

    // mostrar los prod 
    cout << "\nlista de productos:\n";
    for (int i = 0; i < n; ++i) {
        cout << productos[i].nombre << " - S/" << productos[i].precio << endl;
    }
    //para libera mem
    delete[] productos;
    return 0;
}
