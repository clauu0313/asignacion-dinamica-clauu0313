//i08.cpp
//este programa pide una frase, la separa por palabra y las muestra de a una a una

#include <iostream>
#include <sstream>
#include <cstring>  
using namespace std;

int main() {
    string frase;
    cout << "ingresar una frase : ";
    getline(cin, frase);

    istringstream iss(frase); //para dividir la frase
    string palabra;
    int cantidad = 0;

    //cantidad d palabras
    while (iss >> palabra) {
        ++cantidad;
    }

    //regresamos al inicio del stream
    iss.clear();
    iss.seekg(0); //volver al principio del stream

    //arreglo dinamico para guardar cada palabra
    char** palabras = new char*[cantidad];

    //guardamos cada palabra en memoria dinamica
    int i = 0;
    while (iss >> palabra) {
        palabras[i] = new char[palabra.length() + 1]; 
        strcpy(palabras[i], palabra.c_str());
        ++i;
    }

    //mostrar las palabras una por una
    cout << "\npalabras encontradas :" << endl;
    for (int j = 0; j < cantidad; ++j) {
        cout << "-" << palabras[j] << endl;
    }

    //liberar la memoria usada
    for (int j = 0; j < cantidad; ++j) {
        delete[] palabras[j];
    }
    delete[] palabras;

    return 0;
}
