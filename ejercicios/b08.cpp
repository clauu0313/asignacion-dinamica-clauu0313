//b08.cpp
//este programa intenta acceder a memoria ya liberada

#include <iostream>
using namespace std;

int main() {
    int* ptr = new int;
    *ptr = 504;
    delete ptr;

    //accediendo a memoria liberada
    cout << "valor despues de delete (no es recomnedable): " << *ptr << endl;

    return 0;
    //acceder a este es un comportamiento indefinido, ya que puede fallar o mostrar valores basura

}
