#include <iostream>
#include <conio.h> 
#include <string>

using namespace std;

struct Nodo {
    string nombres;
    Nodo *siguiente;
};

void agregarPila(Nodo *&pila, string d);
void mostrarPila(Nodo *pila);
void eliminarPila(Nodo *&pila); 

int main() {
    Nodo *pila = nullptr;
    string nombre;
    int opcion;

    do {
        cout << "\n--- Gestion de Nombres ---" << endl;
        cout << "1. Insertar un nombre" << endl;
        cout << "2. Mostrar todos los nombres" << endl;
        cout << "3. Eliminar el ultimo nombre ingresado" << endl;
        cout << "4. Finalizar el Programa" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                cout << "\nIngrese el nombre: ";
                getline(cin, nombre);
                agregarPila(pila, nombre);
                break;
            case 2:
                mostrarPila(pila);
                break;
            case 3:
                eliminarPila(pila);
                break;
            case 4:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion no valida, intente de nuevo." << endl;
        }
        
        if (opcion != 4) {
            cout << "\nPresione una tecla para continuar...";
            getch();
        }

    } while (opcion != 4);

    return 0;
}

void agregarPila(Nodo *&pila, string d) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombres = d;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "\nElemento \"" << d << "\" cargado exitosamente." << endl;
}

void mostrarPila(Nodo *pila) {
    Nodo *aux = pila;
    if (pila == NULL) {
        cout << "\nLa pila esta vacia." << endl;
    } else {
        cout << "\n--- Elementos en la Pila ---" << endl;
        while (aux != NULL) {
            cout << " - " << aux->nombres << endl;
            aux = aux->siguiente;
        }
    }
}

void eliminarPila(Nodo *&pila) {
    if (pila == NULL) {
        cout << "\nNo hay elementos para eliminar (Pila vacia)." << endl;
    } else {
        Nodo *aux = pila;          
        string nombreEliminado = aux->nombres;
        pila = aux->siguiente;      
        delete aux;                
        cout << "\nElemento \"" << nombreEliminado << "\" eliminado correctamente." << endl;
    }
}