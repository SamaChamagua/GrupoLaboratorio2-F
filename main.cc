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

void InsertarInicio(Producto nuevo_producto);
void Imprimir();

Nodo *head = nullptr;


int main()
{
    
    return 0;
}

void InsertarInicio(int codigo, std::string nombre, double precio)
{
    struct nodo *nuevo_nodo = new nodo;
    nuevo_nodo->producto.codigo = codigo;
    nuevo_nodo->producto.nombre = nombre;
    nuevo_nodo->producto.precio = precio;

    nuevo_nodo->siguiente = Lista;
    Lista = nuevo_nodo;

    return 0;
}

void InsertarInicio (Producto nuevo_producto){
    Nodo* nuevo = new Nodo();
    nuevo->dato = nuevo_producto;
    nuevo->anterior = nullptr;
    nuevo->siguiente = head;

    if (head != nullptr)
    {
        head->anterior = nuevo;
    }

    head = nuevo;

    std::cout << "Producto \"" << nuevo->dato.nombre << "\" agregado al inicio.\n";
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
    }
    
    
}