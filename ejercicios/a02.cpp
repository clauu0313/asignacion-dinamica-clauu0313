//a02.cpp
//este programa crea una clase con regla de 5 (constructor, destructor,constructor copia, operador de asignación copia, constructor y asignacion por movimiento)

#include <iostream>
#include <cstring>
using namespace std;

class Buffer {
private:
    char* texto;   
    int tam;     

public:
    //crea buffer con texto inicial
    Buffer(const char* msg = "hola") {
        tam = strlen(msg);
        texto = new char[tam + 1];
        strcpy(texto, msg);
        cout << "creado: " << texto << endl;
    }
    
    //destruir buffer, liberar memoria
    ~Buffer() {
        cout << "destruyendo: " << (texto ? texto : "vacio") << endl;
        delete[] texto;
    }
    
    //copiar de otro buffer
    Buffer(const Buffer& otro) {
        tam = otro.tam;
        texto = new char[tam + 1];
        strcpy(texto, otro.texto);
        cout << "copiado: " << texto << endl;
    }
    
    //asignar desde otro buffer
    Buffer& operator=(const Buffer& otro) {
        if (this != &otro) { 
            delete[] texto;   //liberar memoria antigua
            tam = otro.tam;
            texto = new char[tam + 1];
            strcpy(texto, otro.texto);
            cout << "asignado: " << texto << endl;
        }
        return *this;
    }
    
    //mover desde buffer temporal
    Buffer(Buffer&& temporal) noexcept {
        texto = temporal.texto;
        tam = temporal.tam;
        temporal.texto = nullptr;  //queda vacio el temporal
        temporal.tam = 0;
        cout << "movido" << endl;
    }
    
    //asignar moviendo desde buffer temporal
    Buffer& operator=(Buffer&& temporal) noexcept {
        if (this != &temporal) {
            delete[] texto;     
            texto = temporal.texto;
            tam = temporal.tam;
            temporal.texto = nullptr;
            temporal.tam = 0;
            cout << "movido por asignacion" << endl;
        }
        return *this;
    }
    
    //mostrar el contenido del buffer
    void mostrar() const {
        cout << "contenido: " << (texto ? texto : "(vacio)") << endl;
    }
};

int main() {
    cout << "---creando buffers---" << endl;
    
    //crear buffer original
    Buffer buf1("hola");
    
    //hacer copia del buffer
    Buffer buf2 = buf1;
    
    //crear buffer vacio y luego asignarle contenido
    Buffer buf3;
    buf3 = buf1;
    
    //crear buffer desde objeto temporal 
    Buffer buf4 = Buffer("pizza");
    
    //asignar desde otro objeto temporal
    buf4 = Buffer("rojo");
    
    cout << "\n--resultado--" << endl;
    cout << "buffer 1: "; buf1.mostrar();
    cout << "buffer 2: "; buf2.mostrar();
    cout << "buffer 3: "; buf3.mostrar();
    cout << "buffer 4: "; buf4.mostrar();
    
    cout << "\n---destruyendo todo---" << endl;
    return 0;
}