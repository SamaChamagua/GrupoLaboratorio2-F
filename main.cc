#include <iostream>
#include <string>

struct Producto
{
    int codigo;
    std::string nombre;
    double precio;
};

struct nodo
{
    Producto producto;
    struct nodo *siguiente;
};

struct nodo *Lista = nullptr;
void InsertarInicio(int codigo, std::string nombre, double precio);

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

    if (Lista == nullptr)
    {
        std::cout << "La lista esta vacia." << std::endl;
    }
    else
    {
        std::cout << "Producto insertado al inicio: " << Lista->producto.nombre << std::endl;
    }
}