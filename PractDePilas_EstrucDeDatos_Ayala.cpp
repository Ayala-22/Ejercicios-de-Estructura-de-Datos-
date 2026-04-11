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

int main() {
    Nodo *pila = NULL;
    string nombre;
    char respuesta;

    do {
        cout << "Ingrese un nombre para la pila: ";
        getline(cin, nombre);
        
        agregarPila(pila, nombre);

        cout << "¿Desea agregar otro nombre? (s/n): ";
        cin >> respuesta;
        cin.ignore(); 
    } while (respuesta == 's' || respuesta == 'S');

    mostrarPila(pila);

    cout << "\nPresione una tecla para salir...";
    getch(); 
    return 0;
}

void agregarPila(Nodo *&pila, string d) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombres = d;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Elemento \"" << d << "\" cargado exitosamente.\n" << endl;
}

void mostrarPila(Nodo *pila) {
    Nodo *aux = pila; 
    
    if (pila == NULL) {
        cout << "\nLa pila esta vacia." << endl;
    } else {
        cout << "\nMostrando elementos de la Pila:" << endl;
        while (aux != NULL) {
            cout << " - " << aux->nombres << endl;
            aux = aux->siguiente; 
        }
    }
}