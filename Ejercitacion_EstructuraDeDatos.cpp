#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Producto {
    int id;
    string descripcion;
    string gestion;
    float precio;
};

void ordenarAlfabeticamente(vector<Producto> &lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j].descripcion > lista[j + 1].descripcion) {
                swap(lista[j], lista[j + 1]);
            }
        }
    }
}

int main() {
    int cantidad;

    cout << "========================================" << endl;
    cout << "   SISTEMA DE GESTION DE INVENTARIO" << endl;
    cout << "========================================" << endl;

    do {
        cout << "Ingrese la cantidad de productos (minimo 10): ";
        cin >> cantidad;
        if (cantidad < 10) {
            cout << "-> Error: Debe ingresar al menos 10 registros para continuar." << endl;
        }
    } while (cantidad < 10);

    vector<Producto> inventario(cantidad);

    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Producto #" << i + 1 << " ---" << endl;
        
        cout << "ID: ";
        cin >> inventario[i].id;
    
        cin.ignore(1000, '\n'); 

        cout << "Descripcion: ";
        getline(cin, inventario[i].descripcion);

        cout << "Gestion: ";
        getline(cin, inventario[i].gestion);

        cout << "Precio: ";
        cin >> inventario[i].precio;

        cin.ignore(1000, '\n'); 
    }

    cout << "\n* Ordenando productos alfabeticamente..." << endl;
    ordenarAlfabeticamente(inventario);

    cout << "\n" << setfill('=') << setw(70) << "" << endl;
    cout << setfill(' ') << left 
         << setw(10) << "ID" 
         << setw(25) << "DESCRIPCION" 
         << setw(20) << "GESTION" 
         << setw(10) << "PRECIO" << endl;
    cout << setfill('-') << setw(70) << "" << endl;

    for (const auto& p : inventario) {
        cout << setfill(' ') << left 
             << setw(10) << p.id 
             << setw(25) << p.descripcion 
             << setw(20) << p.gestion 
             << fixed << setprecision(2) << "$" << p.precio << endl;
    }
    cout << setfill('=') << setw(70) << "" << endl;

    return 0;
}