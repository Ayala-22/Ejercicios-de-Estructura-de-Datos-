#include <iostream>
using namespace std;

int main() {
    // Definimos el arreglo de 5 enteros
    int numeros[5] = {10, 20, 30, 40, 50};
    
    // Declaramos un puntero que apunte al inicio del arreglo
    int *ptr = numeros; 

    cout << "Recorriendo el arreglo usando solo punteros:" << endl;

    for (int i = 0; i < 5; i++) {
        // *(ptr + i) accede al valor contenido en la dirección
        // (ptr + i) nos da la dirección de memoria actual
        cout << "Valor: " << *(ptr + i) 
             << " | Direccion de memoria: " << (ptr + i) << endl;
    }

    return 0;
}