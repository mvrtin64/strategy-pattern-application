#include <iostream>
#include <map>
using namespace std;

class Strategy {                              // interfaz strategy 
public:
    virtual void execute() = 0;
};

class Option1 : public Strategy {
public:
    void execute() override {
        cout << "option 1 selected." << endl;
    }
};

class Option2 : public Strategy {
public:
    void execute() override {
        cout << "option 2 selected." << endl;
    }
};

class Option3 : public Strategy {
public:
    void execute() override {
        cout << "option 3 selected." << endl;
    }
};

class Option4 : public Strategy { 
public:
    void execute() override {
        cout << "option 4 selected." << endl;
    }
};

class Option5 : public Strategy {                              // estrategias concretas (opciones con su implementación concreta)
public:
    void execute() override {
        cout << "option 5 selected." << endl;
    }
};

int main() {
    map<int, Strategy*> menuOptions;                      // mapa (diccionario o tabla de búsqueda) que asocia un entero (opción) a una instancia de la estrategia concreta correspondiente
    menuOptions[1] = new Option1;
    menuOptions[2] = new Option2;
    menuOptions[3] = new Option3;
    menuOptions[4] = new Option4;
    menuOptions[5] = new Option5;

    int choice;                            

    cout << "STRATEGY MENU:" << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "4. Option 4" << endl;
    cout << "5. Option 5" << endl;

    cout << "select a option: ";
    cin >> choice;                            // opción sobre la que se va a iterar para seleccionar una estrategia concreta

    auto it = menuOptions.find(choice);                     // creo un iterador que busca en el mapa la opción ingresada y la almacena
    if (it != menuOptions.end()) {                        // si se encuentra esa opción, devuelve un iterador que apunta a la posición de la clave encontrada en el mapa
        Strategy* selectedStrategy = it->second;                // la estrategia seleccionada (seleccionada por la elección previa) y accede a second (valor del par clave-valor del mapa), que es una instancia de una estrategia concreta
        selectedStrategy->execute();                           // ejecuta el método de la estrategia concreta seleccionada
    } else {
        cout << "INVALID OPTION." << endl;                // si no se encuentra la opción en el mapa, imprime un error
    }

    for (const auto& pair : menuOptions) {                 // itero sobre todos los pares clave del mapa y elimina las instancias creadas en memoria dinámica (second, que es el valor del par) para limpiar la memoria al finalizar
        delete pair.second;
    }

    return 0;
}
