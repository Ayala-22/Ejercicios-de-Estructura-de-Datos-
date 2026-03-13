#include <iostream>
#include <string>

using namespace std;

struct Componente {
	
    string nombre;
    string marca;
    int capacidadGB;
    float precio; 
};

int main() {
    Componente comp;

    cout << "Nombre del componente: ";
    cin >> comp.nombre;

    cout << "Marca: ";
    cin >> comp.marca;

    cout << "Capacidad en GB: ";
    cin >> comp.capacidadGB;

    cout << "Precio: ";
    cin >> comp.precio;

    cout << "Registro de Inventario" << endl;
    cout << "Producto: " << comp.nombre << endl;
    cout << "Fabricante: " << comp.marca << endl;
    cout << "Capacidad: " << comp.capacidadGB << " GB" << endl;
    cout << "Costo: $" << comp.precio << endl;

    return 0;
}