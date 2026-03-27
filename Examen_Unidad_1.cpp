#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Producto {
    int id;
    string descripcion;
    string gestion;
    float precio;
};

int main() {
    vector<Producto> inventario;
    int opcion;

    do {

        cout << "\n--- MENU DE GESTION DE INVENTARIO ---" << endl;
        cout << "1. Ingresar Productos (Minimo 3)" << endl;
        cout << "2. Mostrar Inventario Ordenado" << endl;
        cout << "3. Eliminar Producto por ID" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { 
                int cantidad;
                cout << "\n¿Cuantos productos desea ingresar? ";
                cin >> cantidad;

                if (cantidad < 3) {
                    cout << "Error: Debe ingresar al menos 3." << endl;
                } else {
                    for (int i = 0; i < cantidad; i++) {
                        Producto p;
                        cout << "\nProducto #" << i + 1 << endl;
                        cout << "ID: "; cin >> p.id;
                        cin.ignore(); // Limpiar el buffer
                        cout << "Descripcion: "; getline(cin, p.descripcion);
                        cout << "Gestion: "; getline(cin, p.gestion);
                        cout << "Precio: "; cin >> p.precio;
                        
                        inventario.push_back(p);
                    }
                    cout << "\n¡Productos registrados con exito!" << endl;
                }
                break;
            }

            case 2: { 
                if (inventario.empty()) {
                    cout << "\nEl inventario esta vacio." << endl;
                } else {
                    
                    for (int i = 0; i < inventario.size() - 1; i++) {
                        for (int j = 0; j < inventario.size() - i - 1; j++) {
                            if (inventario[j].descripcion > inventario[j + 1].descripcion) {
                                swap(inventario[j], inventario[j + 1]);
                            }
                        }
                    }

                    cout << "\nID\tDESCRIPCION\tGESTION\t\tPRECIO" << endl;
                    cout << "----------------------------------------------------" << endl;
                    for (const auto& prod : inventario) {
                        cout << prod.id << "\t" << prod.descripcion << "\t\t" 
                             << prod.gestion << "\t\t$" << prod.precio << endl;
                    }
                }
                break;
            }

            case 3: { 
                if (inventario.empty()) {
                    cout << "\nNada que eliminar, el inventario esta vacio." << endl;
                } else {
                    int idBuscado;
                    bool encontrado = false;
                    cout << "\nIngrese el ID del producto a eliminar: ";
                    cin >> idBuscado;

                    for (int i = 0; i < inventario.size(); i++) {
                        if (inventario[i].id == idBuscado) {
                            inventario.erase(inventario.begin() + i);
                            cout << "Producto eliminado correctamente." << endl;
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) cout << "No se encontro el ID." << endl;
                }
                break;
            }

            case 4:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida, intente de nuevo." << endl;
        }

    } while (opcion != 4);

    return 0;
}