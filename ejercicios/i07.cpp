//i07.cpp
//este programa pide a una funcion que cree un numero en memoria y lo llene con un valor x
//luego, muestra el numero

#include <iostream>
using namespace std;

//esta funcion crea un numero nuevo y le asignamos un valor x ejm: 1304
void asignarMemoria(int** p) {
    *p = new int;     //crea un espacio para el numero
    **p = 1304;        //guarda el numero
}

int main() {
    int* ptr = nullptr;  //declaramos el puntero

    asignarMemoria(&ptr); //llamamos a la funcion para que cree el numero y lo llene

    cout << "el valor asignado es : " << *ptr << endl;

    delete ptr;

    return 0;
}
