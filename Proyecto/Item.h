/*
  Created on: 20/09/2023
  Author: Juan Carlos Calderón García
*/

#include <string>
#include <iostream>

using namespace std;

class Item 
{
  public:
    Item();
    Item(int,string);
    Item(const Item&);
    
    void setID(int);
    int getID();
    void setNombre(string);
    string getNombre();
    string escribeDatos();

  private:
    int ID;
    string nombre;

};

Item::Item()
{
  ID = 0;
  nombre = "no name";
}

Item::Item(int I,string n)
{
  ID = I;
  nombre = n;
}

Item::Item(const Item &x)
{
  ID = x.ID;
  nombre = x.nombre;
}
    
void Item::setID(int x)
{
  ID = x;
}

int Item::getID()
{
  return ID;
}

void Item::setNombre(string x)
{
  nombre = x;
}

string Item::getNombre()
{
  return nombre;
}

string Item::escribeDatos()
{
  return  "ID: " + to_string(ID) + "\n" + "Nombre: " + nombre + "\n";
}