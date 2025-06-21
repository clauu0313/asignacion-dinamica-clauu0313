//b10.cpp
//este programa usa un doble puntero con mem dinamica

#include <iostream>
using namespace std;

int main() {
    //puntero a puntero
    int** p = new int*;
    *p = new int;       
    //asignar memoria para el entero
    **p = 1511;
    cout << "valor almacenado: " << **p << endl;

    delete *p; //liberar entero
    delete p;  //liberar puntero
    return 0;
}
