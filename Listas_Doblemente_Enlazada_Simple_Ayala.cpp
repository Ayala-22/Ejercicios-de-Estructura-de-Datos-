#include <iostream>

using namespace std;

// Estructura para una Lista Doblemente Enlazada
struct Nodo {
    int dato;
    Nodo *Siguiente; 
    Nodo *Anterior;  // Tiene un Puntero al elemento previo por que esta lista tiene doble sentido
};

void Insertar_Lista_Doble_Simple (Nodo*& Frente, int valor);

int main () {
    
    Nodo* Lista_Doble_Simple = nullptr;
    int valor = 50;

    cout << "-Prueba de Ingreso-" << endl;
    
    Insertar_Lista_Doble_Simple(Lista_Doble_Simple, valor);

    cout << " Prueba realizada Exitosamente " << endl;

    return 0;
}

void Insertar_Lista_Doble_Simple (Nodo*& Frente, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr, nullptr}; // Inicializamos el nodo con ambos brazos en nullptr
    
    if (!Frente) { // El nuevo nodo es el inicio y no tiene nada atrás ni adelante
        Frente = nuevo;
    } else {
        Nodo* temp = Frente;
        
        while (temp->Siguiente) { // Recorremos hasta el final de la lista
            temp = temp->Siguiente;
        }
    
        temp->Siguiente = nuevo; // El último nodo apunta al nuevo
         
        nuevo->Anterior = temp; // El nuevo nodo debe apuntar hacia atrás al que solía ser el último (temp) 
    }
    cout << "Insertado en la Lista Doble: " << valor << endl;
}