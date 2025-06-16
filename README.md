[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/EYUiBR6O)
﻿# Tarea  – Asignación Dinámica
Resolver los ejercicios ubicados en el archivo asignacionDinamica.md en la carpeta ejercicios

## Nombres de tus archivos 
Sigue esta convención para cada ejercicio que resuelvas:

- `b01.cpp` → Ejercicio 1 del nivel básico
- `i02.cpp` → Ejercicio 2 del nivel intermedio
- `a01.cpp` → Ejercicio 1 del nivel avanzado

Guarda **todos tus archivos dentro de la carpeta `ejercicios/`** que ya está creada en el repositorio.

---

## Comentarios en el código

En cada archivo `.cpp` debes incluir **comentarios** que expliquen lo que estás haciendo en cada parte del programa. Usa comentarios para:

- Describir el objetivo del ejercicio
- Explicar secciones clave del código
- Documentar ideas, incluso si el código no está terminado

Ejemplo:

```cpp
// b02.cpp
// Este programa suma dos números ingresados por el usuario

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Ingresa dos números: ";
    cin >> a >> b;
    // Se suman los dos números
    cout << "La suma es: " << (a + b) << endl;
    return 0;
}
```

## Trabaja con Git y GitHub

p1) Clonar el repositorio: Abre tu terminal y ejecuta
    `git clone <URL-del-repositorio>`

p2) Trabaja localmente: dentro de la carpeta ejercicios/

p3) Guarda tu progreso con commits: incluso si no terminas
    un ejercicio haz commits frecuentes 

```bash
git add ejercicios/b01.cpp
git commit -m "Comencé ejercicio b01 - declaré variables"
```
Haz commit cada vez que avances
```bash
git add .
git commit -m "Terminé lectura de datos en b01"  
```

p4) Sube los cambios a gitHub
    `git push`



