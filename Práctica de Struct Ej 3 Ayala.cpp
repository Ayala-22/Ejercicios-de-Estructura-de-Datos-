#include <iostream>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    float precio;
};

int main() {
    int cantidad;
    float totalCompra = 0;

    cout << "Cuantos productos desea registrar? ";
    cin >> cantidad;

    Producto* inventario = new Producto[cantidad];

    for (int i = 0; i < cantidad; i++) {
        cout << "\nProducto #" << i + 1 << endl;
        cout << "Nombre: ";
        cin >> inventario[i].nombre;
        cout << "Precio: ";
        cin >> inventario[i].precio;

        totalCompra += inventario[i].precio;
    }

    cout << "\n-----------------------------" << endl;
    cout << "Total de la compra: $" << totalCompra << endl;
    cout << "-----------------------------" << endl;

    delete[] inventario;
    cout << "Memoria liberada correctamente." << endl;

    return 0;
}