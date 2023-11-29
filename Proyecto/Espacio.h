/*
  Created on: 20/09/2023
  Author: Juan Carlos Calderón García
*/

#include "Item.h"

using namespace std;

class Espacio
{
  public:
    Espacio();
    Espacio(const Espacio&);
    Espacio(Item, int);

    void setID(int);
    int getID();
    void setNombre(string);
    string getNombre();
    void setItem(Item&);
    Item getItem();
    void setCantidad(int);
    int getCantidad();
    string escribeDatos();

    void operator=(const Espacio&);

  private:
    Item objeto;
    int cantidad;
};

Espacio::Espacio()
{
  objeto = Item();
  cantidad = 0;
}

Espacio::Espacio(const Espacio &x)
{
  objeto = x.objeto;
  cantidad = x.cantidad;
}

Espacio::Espacio(Item obj, int x)
{
  objeto.setID(obj.getID());
  objeto.setNombre(obj.getNombre());
  cantidad = x;
}

void Espacio::setID(int x)
{
  objeto.setID(x);
}

int Espacio::getID()
{
  return objeto.getID();
}

void Espacio::setNombre(string x)
{
  objeto.setNombre(x);
}

string Espacio::getNombre()
{
  return objeto.getNombre();
}

void Espacio::setItem(Item &x)
{
  objeto.setID(x.getID());
  objeto.setNombre(x.getNombre());
}

Item Espacio::getItem()
{
  return objeto;
}

void Espacio::setCantidad(int x)
{
  cantidad = x;
}

int Espacio::getCantidad()
{
  return cantidad;
}

string Espacio::escribeDatos()
{
  return objeto.escribeDatos() + "Cantidad: " + to_string(cantidad) + "\n\n";
}

void Espacio::operator=(const Espacio &source)
{
  objeto = source.objeto;
  cantidad = source.cantidad;
}