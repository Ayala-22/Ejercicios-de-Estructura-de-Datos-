#include <iostream>
#include <cmath> 

using namespace std;

struct Punto {
    float x;
    float y;
};

int main() {
    Punto p1, p2;

    cout << "Ingrese las coordenadas del Punto 1 (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Ingrese las coordenadas del Punto 2 (x y): ";
    cin >> p2.x >> p2.y;

    float distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    cout << "La distancia entre p1 y p2 es: " << distancia << endl;

    return 0;
}