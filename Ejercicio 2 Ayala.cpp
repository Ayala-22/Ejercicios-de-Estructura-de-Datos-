#include <iostream>
using namespace std;
// Función que recibe "las llaves" (punteros)
void intercambiar(int *ptrA, int *ptrB) {
int auxiliar = *ptrA; // Guardo lo que hay en la primera caja
*ptrA = *ptrB; // Pongo lo de la segunda caja en la primera
*ptrB = auxiliar; // Pongo lo que guardé en la segunda caja
}
int main() {
int x = 5, y = 10;
cout << "Original: x=" << x << ", y=" << y << endl;
// Enviamos las direcciones con '&'
intercambiar(&x, &y);
cout << "Intercambiado: x=" << x << ", y=" << y << endl;
return 0;
}