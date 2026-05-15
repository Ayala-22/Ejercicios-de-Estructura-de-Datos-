#include <iostream>
#include <string>

using namespace std;

// Comenzamos definiendo nuestro Nodo (Tarea)
struct Tarea {
    int id;
    string Documento;
    int Prioridad;
    Tarea* Siguiente;
}; 

// Prototipo de Funciones 
void InsertarTarea(Tarea*& lista, int id, string nombre, int prio); // Funcion para insertar los elementos a la lista (Incluyendo la de insertar con Prioridad a la mmisma)
void MostrarLista(Tarea* lista); // Funcion de mostrar los elementos con todos sus caracteristicas recopiladas
void EliminarTarea(Tarea*& lista, int id); // Funcion de eliminar cualquier elemento de la lista
void ProcesarSiguiente(Tarea*& lista); // Funcion para atender al primer elemento o al de mayor prioridad de la lista para despues sacarlo de la misma
bool BuscarTarea(Tarea* lista, int id); // Funcion para ubicar cualquier elemento dentro de la lista

// Programa Principal 
int main () {
    // Declaracion de las variables locales 
    Tarea* spooler = nullptr;
    int opcion, id, prio;
    string nombre;

    // Menu de opciones a ejecutar en el Programa 

    do {
        cout << "\n--- Gestor de Procesos ---";
        cout << "\n1. Insertar nueva tarea";
        cout << "\n2. Mostrar Lista Completa";
        cout << "\n3. Buscar tarea por ID";
        cout << "\n4. Eliminar tarea especifica";
        cout << "\n5. Procesar siguiente tarea";
        cout << "\n6. Finalizar Programa";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
    
     // Llamado de las Funciones al programa principal (Con el objetivo de que pueda funcionar sin ningun problema)
        switch (opcion) {
            case 1:
                cout << "ID de la tarea: "; cin >> id;
                cout << "Nombre del documento: "; cin.ignore(); getline(cin, nombre);
                cout << "Prioridad (1: Alta, 2: Baja): "; cin >> prio;
                InsertarTarea(spooler, id, nombre, prio);
                break;
            case 2:
                MostrarLista(spooler);
                break;
            case 3:
                cout << "Ingrese ID a buscar: "; cin >> id;
                if (BuscarTarea(spooler, id)) cout << "\n La tarea existe en la lista \n";
                else cout << "\n Lo sentimos, no se encontro nada \n";
                break;
            case 4:
                cout << "Ingrese ID de la tarea a eliminar: "; cin >> id;
                EliminarTarea(spooler, id);
                break;
            case 5:
                ProcesarSiguiente(spooler);
                break;
            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}

// Estructura de las Funciones a Ejecutar en el Porgrama 
bool BuscarTarea(Tarea* lista, int id) { //Comenzamos con la funcion de buscar por que al depender de verdadero o falso se necesitara para las siguientes funciones a declarar 
    Tarea* aux = lista;
    while (aux != nullptr) {
        if (aux->id == id) return true;
        aux = aux->Siguiente;
    }
    return false;
}

void InsertarTarea(Tarea*& lista, int id, string nombre, int prio) { // Se encarga de añadir los elementos a la lista, priorizaando elementos de ingreso (En este caso si es de valor Alto o Bajo)
    if (BuscarTarea(lista, id)) {
        cout << "\n Error: El ID " << id << " ya existe en la lista.\n";
        return;
    }

    Tarea* nuevaTarea = new Tarea();
    nuevaTarea->id = id;
    nuevaTarea->Documento = nombre;
    nuevaTarea->Prioridad = prio;
    nuevaTarea->Siguiente = nullptr;

    // Prioridad 1: Insertar al inicio | Prioridad 2: Insertar al final
    if (prio == 1 || lista == nullptr) {
        nuevaTarea->Siguiente = lista;
        lista = nuevaTarea;
    } else {
        Tarea* aux = lista;
        while (aux->Siguiente != nullptr) {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevaTarea;
    }
    cout << "\n Tarea implementada exitosamente.\n";
}

void MostrarLista(Tarea* lista) { // Usamos estructuras de desicion y bucles para lograr mostrar todos los elementos en la pantalla
    if (lista == nullptr) {
        cout << "\n La cola de impresion esta vacia.\n";
        return;
    }
    cout << "\n--- Cola de Impresion ---\n";
    Tarea* aux = lista;
    while (aux != nullptr) {
        cout << "ID: " << aux->id << " | Doc: " << aux->Documento 
             << " | P: " << (aux->Prioridad == 1 ? "ALTA" : "BAJA") << "\n";
        aux = aux->Siguiente;
    }
    cout << "------------------------\n";
}

void EliminarTarea(Tarea*& lista, int id) { // Procedimietno similar al caso de mostra, solamente que aqui usaremos mas punteros apuntando a nullptr para asegurarnos de vaciar los puntos solicitados por el usuario
    if (lista == nullptr) return;

    Tarea *aux_borrar = lista;
    Tarea *anterior = nullptr;

    while (aux_borrar != nullptr && aux_borrar->id != id) {
        anterior = aux_borrar;
        aux_borrar = aux_borrar->Siguiente;
    }

    if (aux_borrar == nullptr) {
        cout << "\n No se encontro la tarea con ID: " << id << endl;
    } else {
        if (anterior == nullptr) { // Es el primero
            lista = lista->Siguiente;
        } else { // Es intermedio o final
            anterior->Siguiente = aux_borrar->Siguiente;
        }
        delete aux_borrar;
        cout << "\n Tarea " << id << " eliminada \n";
    }
}

void ProcesarSiguiente(Tarea*& lista) { // Simplemente se encarga de imprimir y pasar los elementos que se encuentren en la primera posicion (O los de Prioridad) de la lista
    if (lista == nullptr) {
        cout << "\n No hay tareas pendientes para procesar \n";
        return;
    }
    Tarea* aux = lista;
    cout << "\n Imprimiendo: " << aux->Documento << " (ID: " << aux->id << ")...";
    lista = lista->Siguiente;
    delete aux;
    cout << " (Completado)\n";
}