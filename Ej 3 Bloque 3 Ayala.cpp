#include <iostream>
using namespace std;

struct Empleado {
    char nombre[50];
    float salario;
};

int main() {
    int n;
    cout << "Cantidad de empleados: "; cin >> n;
    Empleado e[n];

    for(int i = 0; i < n; i++) {
        cout << "Nombre " << i+1 << ": "; cin >> e[i].nombre;
        cout << "Salario " << i+1 << ": "; cin >> e[i].salario;
    }

    int mayor = 0, menor = 0;

    for(int i = 0; i < n; i++) {
        if(e[i].salario > e[mayor].salario) mayor = i;
        if(e[i].salario < e[menor].salario) menor = i;
    }

    cout << "\nMayor salario: " << e[mayor].nombre << " con " << e[mayor].salario;
    cout << "\nMenor salario: " << e[menor].nombre << " con " << e[menor].salario;

    return 0;
}







