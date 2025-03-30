#include <iostream>  
#include <stdlib.h>

using namespace std;

// Clase antigua con un metodo de suma
class LegacyAdder {
public:
    int add(int a, int b) {
        return a + b;
    }
};

// Interfaz  para la suma
class INewAdder {
public:
    virtual int sum(int a, int b) = 0; // Metodo puro virtual
    virtual INewAdder() {} // Destructor virtual
};

// Adaptador que conecta la clase antigua con la nueva interfaz
class Adapter : public INewAdder {
private:
    LegacyAdder legacyAdder;
public:
    int sum(int a, int b) override {
        return legacyAdder.add(a, b);
    }
};

// Funcion principal
int main() {
    int opcion;

    do {
        // Mostrar menu
        cout << "\n--- MENU ---" << endl;
        cout << "1. Sumar dos numeros" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Evaluar la opcion
        switch (opcion) {
            case 1: {
                int num1, num2;
                
                // Solicitar los numeros al usuario
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                
                cout << "Ingrese el segundo numero: ";
                cin >> num2;

                // Usar el Adapter para realizar la suma
                Adapter adder;
                int resultado = adder.sum(num1, num2);
                
                // mostrar el resultado
                cout << "La suma es: " << resultado << endl;
                break;
            }
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcion != 2); // Repetir hasta que el usuario elija salir

    return 0;
}
