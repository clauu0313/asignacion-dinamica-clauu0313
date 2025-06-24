//i02.cpp
//este programate te pide el nombre y edad de un estudiante, luego te los muestra

#include <iostream>
#include <cstring>
using namespace std;

//se define la estructura "Estudiante" con un campo dinamico para el nombre
struct Estudiante {
    //memoria dinamica para el nombre
    char* nombre; 
    int edad;
};

int main() {
    Estudiante est;
    char temp[72];

    //pidiendo los datos
    cout << "ingrese el nombre del estudiante: ";
    cin.getline(temp, 72);

    //se asigna memoria y se copia el nombre
    est.nombre = new char[strlen(temp) + 1];
    // se copia el nombre a memoria dinámica
    strcpy(est.nombre, temp); 
    cout << "ingrese la edad: ";
    cin >> est.edad;

    //se muestran los datos
        cout << "Estudiante: " << est.nombre << ", edad: " << est.edad << endl;

    //se libera la memoria usada para el nombre
    delete[] est.nombre;

    return 0;
}