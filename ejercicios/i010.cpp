//i10.cpp
//este programa te permite ingresar varias palabras y luego mostrarlas,todo en memoria dinamica

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int cantidad;

    //pedir cuantas palabras quiere ingresar
    cout << "cuentas palabras deseas ingresar? : ";
    cin >> cantidad;

    //crear un arreglo dinamico de punteros a char
    char** palabras = new char*[cantidad];

    cin.ignore();

    //pedimos cada palabra y reservamos memoria para ella
    for (int i = 0; i < cantidad; ++i) {
        char temp[503]; 
        cout << "palabra " << i + 1 << ": ";
        cin.getline(temp, 100);

        //reservar memoria exacta para la palabra y copiar su contenido
        palabras[i] = new char[strlen(temp) + 1];
        strcpy(palabras[i], temp);
    }

    //mostrar todas las palabras ingresadas
    cout << "\npalabras ingresadas:" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << "- " << palabras[i] << endl;
    }

    //liberamos toda la memoria usada
    for (int i = 0; i < cantidad; ++i) {
        delete[] palabras;
    }
    delete[] palabras; //liberamos el arr

    return 0;
}
