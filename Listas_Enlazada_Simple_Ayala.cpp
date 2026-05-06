#include <iostream>

using namespace std;

// Estructura para una Lista Simple
struct Nodo {
    int dato;
    Nodo *Siguiente; // Solo tiene un puntero porque solo tiene un sentido
};

// Prototipo de la Función Insertar 
void Insertar_Lista_Simple (Nodo*& Frente, int valor);

int main () {
    
    Nodo* Lista_Simple = nullptr; // La lista empezara apuntando hacia la nada 
    int valor = 50;

    cout << "-Prueba de Ingreso-" << endl;
    
    Insertar_Lista_Simple (Lista_Simple, valor);

    cout << " Prueba realizada exitosamente " << endl;

    return 0;
}

void Insertar_Lista_Simple (Nodo*& Frente, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr}; // En la lista simple el nuevo nodo siempre apuntara a nullptr
    
    if (!Frente) {  // Si no hay frente, el nuevo nodo se convierte en el frente
        Frente = nuevo;
    } 
    else {
        Nodo* temp = Frente; // Usamos un auxiliar para no perder el inicio de la lista 
        while (temp->Siguiente) {
            temp = temp->Siguiente;
        }
        temp->Siguiente = nuevo; // El que era el último ahora apunta al nuevo nodo
    }
    cout << "Insertado en la Lista Simple: " << valor << endl;
}