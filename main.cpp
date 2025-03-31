#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MiembroClub {
private:
    string nombre;
    int edad;
    string correo;

public:
    // Constructor
    MiembroClub(string n = "", int e = 0, string c = "") {
        nombre = n;
        edad = e;
        correo = c;
    }

    // Método para guardar datos en el archivo
    void guardarEnArchivo() {
        ofstream archivo("club.txt", ios::app); // modo append
        if (archivo.is_open()) {
            archivo << nombre << "," << edad << "," << correo << endl;
            archivo.close();
            cout << "Miembro guardado con exito.\n";
        }
        else {
            cout << "Error al abrir el archivo.\n";
        }
    }

    // Método estático para leer los datos desde el archivo
    static void leerDesdeArchivo() {
        ifstream archivo("club.txt");
        string linea;
        if (archivo.is_open()) {
            cout << "Miembros registrados:\n";
            while (getline(archivo, linea)) {
                cout << linea << endl;
            }
            archivo.close();
        }
        else {
            cout << "No se pudo abrir el archivo.\n";
        }
    }

    // Método estático para actualizar un miembro por nombre
    static void actualizarMiembro(string nombreBuscar, string nuevoCorreo) {
        ifstream archivo("club.txt");
        ofstream temp("temp.txt");
        string linea, nombre, correo;
        int edad;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            size_t p1 = linea.find(',');
            size_t p2 = linea.rfind(',');

            nombre = linea.substr(0, p1);
            edad = stoi(linea.substr(p1 + 1, p2 - p1 - 1));
            correo = linea.substr(p2 + 1);

            if (nombre == nombreBuscar) {
                temp << nombre << "," << edad << "," << nuevoCorreo << endl;
                encontrado = true;
            }
            else {
                temp << linea << endl;
            }
        }

        archivo.close();
        temp.close();
        remove("club.txt");
        rename("temp.txt", "club.txt");

        if (encontrado)
            cout << "Miembro actualizado.\n";
        else
            cout << "Miembro no encontrado.\n";
    }

    // Método estático para eliminar un miembro por nombre
    static void eliminarMiembro(string nombreEliminar) {
        ifstream archivo("club.txt");
        ofstream temp("temp.txt");
        string linea, nombre;
        bool eliminado = false;

        while (getline(archivo, linea)) {
            size_t p1 = linea.find(',');
            nombre = linea.substr(0, p1);

            if (nombre != nombreEliminar) {
                temp << linea << endl;
            }
            else {
                eliminado = true;
            }
        }

        archivo.close();
        temp.close();
        remove("club.txt");
        rename("temp.txt", "club.txt");

        if (eliminado)
            cout << "Miembro eliminado.\n";
        else
            cout << "Miembro no encontrado.\n";
    }
};

// Menú principal
int main() {
    int opcion;
    string nombre, correo;
    int edad;

    do {
        cout << "\n---- Menú del Club ----\n";
        cout << "1. Agregar miembro\n";
        cout << "2. Mostrar miembros\n";
        cout << "3. Actualizar miembro\n";
        cout << "4. Eliminar miembro\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: "; cin >> edad; cin.ignore();
            cout << "Correo: "; getline(cin, correo);
            {
                MiembroClub nuevo(nombre, edad, correo);
                nuevo.guardarEnArchivo();
            }
            break;
        case 2:
            MiembroClub::leerDesdeArchivo();
            break;
        case 3:
            cout << "Nombre del miembro a actualizar: ";
            getline(cin, nombre);
            cout << "Nuevo correo: ";
            getline(cin, correo);
            MiembroClub::actualizarMiembro(nombre, correo);
            break;
        case 4:
            cout << "Nombre del miembro a eliminar: ";
            getline(cin, nombre);
            MiembroClub::eliminarMiembro(nombre);
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}
