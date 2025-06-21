//b01.cpp
//este programa muestra como guardar un nro entero mediante asignacion dinamica
#include <iostream>
using namespace std;

int main() {
    // asignacion dinamica
    int* p = new int; 
    // asignacion de valor
    *p = 42; 
    cout << "Valor: " << *p << endl;
    // liberar memoria
    delete p;  
    return 0;
}