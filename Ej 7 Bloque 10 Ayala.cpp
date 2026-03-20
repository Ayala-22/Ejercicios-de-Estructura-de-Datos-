#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char nombre[100];
    int contador = 0;

    cout << "Nombre: ";
    cin.getline(nombre, 100);

    for (char *p = nombre; *p != '\0'; p++) {
        if (strchr("aeiouAEIOU", *p)) {
            contador++;
        }
    }

    cout << "Vocales: " << contador << endl;

    return 0;
}