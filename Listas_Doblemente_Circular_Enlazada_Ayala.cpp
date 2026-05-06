#include <iostream>

using namespace std;

// Estructura para una Lista Circular Doble
struct Nodo {
    int dato;
    Nodo *Siguiente; // Puntero al sucesor
    Nodo *Anterior;  // Puntero al predecesor
};

void Insertar_Lista_Doble_Circular_Simple (Nodo*& Frente, int valor);

int main () {
    
    Nodo* Lista_Doble_Circular_Simple = nullptr;
    int valor = 50;

    cout << "-Prueba de Ingreso-" << endl;

    Insertar_Lista_Doble_Circular_Simple(Lista_Doble_Circular_Simple, valor);

    cout << " Prueba realizada Exitosamente " << endl;

    return 0;
}

void Insertar_Lista_Doble_Circular_Simple(Nodo*& Frente, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr, nullptr}; // El nodo nace con punteros nulos temporalmente

    if (!Frente) {
        Frente = nuevo;
        Frente->Siguiente = Frente->Anterior = Frente; // Al ser el único, se apunta a sí mismo por delante y por detrás
    } else {
        Nodo* ultimo = Frente->Anterior; //En una lista circular doble, el "último" nodo SIEMPRE es el anterior del Frente
        nuevo->Siguiente = Frente; // El nuevo apunta al inicio
        nuevo->Anterior = ultimo;  // El nuevo apunta al que era el último

        ultimo->Siguiente = nuevo; // El viejo último ahora apunta al nuevo
        Frente->Anterior = nuevo;  // El Frente ahora reconoce al nuevo como el último
    }
    cout << "Insertado en la Li