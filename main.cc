#include <iostream>
#include <string>

struct Producto
{
    int codigo;
    std::string nombre;
    double precio;
};

struct Nodo
{
    Producto dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void InsertarFinal(Producto nuevo_producto);
void InsertarInicio(int codigo, std::string nombre, double precio);
void Imprimir();

Nodo *head = nullptr;


int main()
{
    int opcion;
    do
    {
        std::cout << "\n===== MENÚ DE INVENTARIO =====\n";
        std::cout << "1. Insertar producto al inicio\n";
        std::cout << "2. Insertar producto al final\n";
        std::cout << "3. Imprimir inventario\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int codigo;
            std::string nombre;
            double precio;

            std::cout << "Ingrese código: ";
            std::cin >> codigo;
            std::cout << "Ingrese nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese precio: ";
            std::cin >> precio;

            InsertarInicio(codigo, nombre, precio);
            break;
        }
        case 2:
        {
            Producto nuevo;
            std::cout << "Ingrese código: ";
            std::cin >> nuevo.codigo;
            std::cout << "Ingrese nombre: ";
            std::cin >> nuevo.nombre;
            std::cout << "Ingrese precio: ";
            std::cin >> nuevo.precio;

            InsertarFinal(nuevo);
            break;
        }
        case 3:
            Imprimir();
            break;
        case 4:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
    
    return 0;
}

void InsertarInicio(int codigo, std::string nombre, double precio)
{
    Nodo* actual = head;
    Nodo* nuevo_nodo = new Nodo;
    nuevo_nodo->dato.codigo = codigo;
    nuevo_nodo->dato.nombre = nombre;
    nuevo_nodo->dato.precio = precio;
    nuevo_nodo->anterior = nullptr;

    nuevo_nodo->siguiente = head;
    head = nuevo_nodo;
    if (head->siguiente != nullptr)
    {
        head->siguiente->anterior = head;
    }
    
    if (head == nullptr)
    {
        std::cout << "Codigo: "<<actual->dato.codigo<<std::endl;
        std::cout << "Nombre: "<<actual->dato.nombre<<std::endl;
        std::cout << "Precio: "<<actual->dato.precio<<std::endl;

        actual = actual->siguiente;
    };
      
}

void InsertarFinal(Producto nuevo_producto)
{
    Nodo* nuevo = new Nodo();
    nuevo->dato = nuevo_producto;
    nuevo->siguiente = nullptr;

    if (head == nullptr)
    {
        nuevo->anterior = nullptr;
        head = nuevo;
    }
    else
    {
        std::cout << "Producto insertado al inicio: " << head->dato.nombre << std::endl;
    }
}

void Imprimir()
{
    if (head == nullptr)
    {
        std::cout << "Lista Vacia. No hay productos para mostrar"<<std::endl;
    }

    Nodo *actual = head;

    std::cout << "-------------INVENTARIO-----------"<<std::endl;
    while (actual != nullptr)
    {
        std::cout << "Codigo: "<<actual->dato.codigo<<std::endl;
        std::cout << "Nombre: "<<actual->dato.nombre<<std::endl;
        std::cout << "Precio: "<<actual->dato.precio<<std::endl;

        actual = actual->siguiente;
    };
      
}

void InsertarFinal(Producto nuevo_producto)
{
    Nodo* nuevo = new Nodo();
    nuevo->dato = nuevo_producto;
    nuevo->siguiente = nullptr;

    if (head == nullptr)
    {
        nuevo->anterior = nullptr;
        head = nuevo;
    }
    else
    {
        Nodo* actual = head;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }

    std::cout << "Producto \"" << nuevo->dato.nombre << "\" agregado al final.\n";
}