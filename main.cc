#include <iostream>

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
void Imprimir();

Nodo *head = nullptr;


int main()
{

    return 0;
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