#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipos de Funciones
void AgregarCola (Nodo *&, Nodo *&, int);
void EliminarCola (Nodo *&, Nodo *&, int &);
bool cola_vacia (Nodo *);

// Programa Principal
int main (){
    Nodo *Frente = nullptr;
    Nodo *Fin = nullptr;

    int dato;

    cout << "Ingrese su Numero: ";
    cin >> dato;
    AgregarCola (Frente, Fin, dato);

    cout << "Ingrese su Numero: ";
    cin >> dato;
    AgregarCola (Frente, Fin, dato);

    cout << "Ingrese su Numero: ";
    cin >> dato;
    AgregarCola (Frente, Fin, dato);

    cout << "\nEliminando los elementos de la Cola: ";
    while (Frente != nullptr){
        EliminarCola (Frente, Fin, dato);

        if (Frente != nullptr){
            cout << dato <<",";
        } else {
            cout << dato << ".";
        }
    }

    getch();
    return 0;
}

//Función para insertar elementos en una cola
void AgregarCola (Nodo *&Frente, Nodo *&Fin, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = nullptr;

    if (cola_vacia (Frente)) {
         Frente = nuevo_nodo;
    } else {
        Fin -> siguiente = nuevo_nodo;
    }
    Fin = nuevo_nodo;
    cout << " Elemento " << n << " Agregado con exito a la Cola\n "; 
}

// Función para eliminar elementos de la Cola
void EliminarCola (Nodo *&Frente, Nodo *&Fin, int &n){
    n = Frente->dato;
    Nodo *aux = Frente;

    if (Frente == Fin){
        Frente = nullptr;
        Fin = nullptr;
    }
    else {
        Frente = Frente -> siguiente;
    }
    delete aux;
}

//Función para saber si la Cola se encuentra Vacia o no
bool cola_vacia (Nodo *Frente) {
    return (Frente == nullptr) ? true : false;
}