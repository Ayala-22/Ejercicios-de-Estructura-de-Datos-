#include <iostream>
using namespace std;
int main() {
int notas[] = {15, 18, 20, 12};
int *p = notas; // 'p' apunta al inicio (al 15)
cout << "Recorriendo la calle de las notas:" << endl;
for (int i = 0; i < 4; i++) {
// *(p + i) significa: "Ve a la casa i y dime qué hay dentro"
cout << "Nota " << i << ": " << *(p + i) << " (Direccion: " <<
(p + i) << ")" << endl;
}
return 0;
}