//b04.cpp
//este programa guarda un nro decimal en memoria dinamica

#include <iostream>
using namespace std;

int main() {
    // crear puntero dinamico para float
    float* p = new float;
    // asignar valor
    *p = 3.1416;   

    cout << "valor: " << *p << endl;

    // liberar memoria
    delete p;
    return 0;
}
