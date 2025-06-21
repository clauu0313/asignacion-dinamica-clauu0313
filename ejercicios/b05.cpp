//b05.cpp
//este programa crea un entero en memoria dinamica dentro de una funcion y lo devulve

#include <iostream>
using namespace std;

// funcion que devuelve un puntero a entero con valor asignado
int* crearEntero() {
    int* p = new int;
    *p = 13; // --> valor asignado
    return p;
}

int main() {
    // llamar a la funcion
    int* numero = crearEntero(); 

    cout << "valor devuelto: " << *numero << endl;

    //liberar memoria
    delete numero; 
    return 0;
}