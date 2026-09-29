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

Nodo* inicio = nullptr;

void InsertarInicio(Producto nuevo_producto);

int main()
{

    return 0;
}

void InsertarInicio (Producto nuevo_producto){
    Nodo* nuevo = new Nodo();
    nuevo->dato = nuevo_producto;
    nuevo->anterior = nullptr;
    nuevo->siguiente = inicio;

    if (inicio != nullptr)
    {
        inicio->anterior = nuevo;
    }

    inicio = nuevo;

    std::cout << "Producto \"" << nuevo->dato.nombre << "\" agregado al inicio.\n";
}