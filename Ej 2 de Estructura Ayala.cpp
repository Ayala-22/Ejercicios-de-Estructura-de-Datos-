#include<iostream>
using namespace std;

struct Estudiante {
	
	string Nombre;
	int Edad;
	float Promedio;
	};

int main(){
     
     Estudiante a1; // Creamos una variable de tipo Estudiante
    
    a1.Edad = 20;
    a1.Promedio = 18;
    a1.Nombre = "Juan Perez";

	cout << "Tengo " << a1.Edad << " años." << endl;
	cout << "Promedio " << a1.Promedio << "Puntos." << endl;
	cout << "Nombre " << a1.Nombre << "Identidad." << endl;

	
	return 0;

}