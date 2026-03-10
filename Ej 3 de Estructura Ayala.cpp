#include<iostream>
using namespace std;

int main(){

int tam;
cout << "¿Cuántos elementos quieres? ";
cin >> tam;
int* arreglo = new int[tam]; // Se crea el arreglo del tamaño exacto
// Siempre liberar al terminar
delete[] arreglo;


return 0;

}