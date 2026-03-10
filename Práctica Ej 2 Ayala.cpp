#include <iostream>
using namespace std;

// Función que intercambia los valores usando punteros
void swap(int *a, int *b) {
    int temporal;    // Variable auxiliar para no perder el valor de 'a'
    temporal = *a;   // Guardamos el valor al que apunta 'a' en temporal
    *a = *b;         // Asignamos el valor de 'b' a la dirección de 'a'
    *b = temporal;   // Asignamos el valor guardado en temporal a la dirección de 'b'
}

int main() {
    int x = 50, y = 10;
    cout << "Antes: x=" << x << ", y=" << y << endl;

    // Llamada a la función pasando las direcciones de memoria
    swap(&x, &y);

    cout << "Despues: x=" << x << ", y=" << y << endl;
    return 0;
}