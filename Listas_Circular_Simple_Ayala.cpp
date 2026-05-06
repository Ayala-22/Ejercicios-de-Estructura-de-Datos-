#include <iostream>

using namespace std;

// Estructura para una Lista Circular Simple
struct Nodo {
    int dato;
    Nodo *Siguiente; // Un solo sentido, pero esta vez el último termino apunta al primero
};

void Insertar_Lista_Circular_Simple (Nodo*& Frente, int valor);

int main () {
    
    Nodo* Lista_Circular_Simple = nullptr;
    int valor = 50;

    cout << "-Prueba de Ingreso-" << endl;
    
    Insertar_Lista_Circular_Simple(Lista_Circular_Simple, valor);

    cout << " Prueba realizada Exitosamente " << endl;

    return 0;
}

void Insertar_Lista_Circular_Simple (Nodo*& Frente, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr}; // A diferencia de las lineales, aquí nunca terminará en nullptr.
    
    if (!Frente) {
        Frente = nuevo;
        nuevo->Siguiente = Frente; // El primer nodo se apunta a sí mismo para formar el círculo inicial.
    } else {
        Nodo* temp = Frente;
        
        //En las listas lineales buscábamos 'nullptr'. Aquí, el último nodo es aquel cuyo 'Siguiente' es el 'Frente'
        while (temp->Siguiente != Frente) {
            temp = temp->Siguiente;
        }
        
        temp->Siguiente = nuevo; // El antiguo último ahora apunta al nuevo integrante
    
        nuevo->Siguiente = Frente; // El nuevo nodo ahora debe apuntar al 'Frente' para mantener la circularidad
    }
    cout << "Insertado en la Lista Circular Simple: " << valor << endl;
}