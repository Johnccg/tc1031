
#include "Espacio.h"

class Hotbar;

class HotSpace : public Espacio
{
  private:
    HotSpace(Espacio &);

    HotSpace* next;
    HotSpace* previous;

    friend class Hotbar;
};

HotSpace::HotSpace(Espacio &x) :  Espacio(x)
{
  next = NULL;
  previous = NULL;
}

class Hotbar
{
  public:
    Hotbar();

    HotSpace* find(int);
    void add(Espacio);
    string escribeDatos();
    string escribeDatos(int);
    int length();
    void assign(Espacio, int);
    void deletes(int);

  private:
    HotSpace *head;
    HotSpace *tail;
    int size;
};

Hotbar::Hotbar()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

HotSpace* Hotbar::find(int indice)
{
  if (indice < 0 || indice >= size)
  {
    throw 'z';
  }else
  {
    HotSpace *actual;
  
    if (indice <= (size/2))
    {
      actual = head;
      for (int i = 0; i < indice; i++)
      {
        actual = actual->next;
      }
    }else
    {
      actual = tail;
      for (int i = size - 1; i > indice; i--)
      {
        actual = actual->previous;
      }
    }
    
    return  actual;
  }
  return NULL;
}

void Hotbar::add(Espacio val)
{
  if (size >= 10)
  {
    throw 'z';
  }
  
  HotSpace * nuevo = new HotSpace (val);

  if (nuevo == NULL)
  {
    throw 'm';
  }
  
  if (size == 0)
  {
    head = nuevo;
    tail = nuevo;
  }else
  {
    nuevo->previous = tail;
    tail->next = nuevo;
    tail = nuevo;
  }
  size ++;
}

string Hotbar::escribeDatos()
{
  string ans;
  HotSpace *actual = head;

  while(actual != NULL)
    {
      ans += actual->escribeDatos();
      actual = actual->next;
    }
  
  return ans;
}

string Hotbar::escribeDatos(int indice)
{
  if (find(indice) != NULL)
  {
    return find(indice)->escribeDatos();
  }
  return "";
}

int Hotbar::length()
{
  return size;
}

void Hotbar::assign(Espacio val, int indice)
{
  HotSpace *target = find(indice);
  
  if (target != NULL)
  {
    target->setID(val.getID());
    target->setNombre(val.getNombre());
    target->setCantidad(val.getCantidad());
  }
}

void Hotbar::deletes(int indice)
{
  if (size == 0)
  {
    cout << "No hay elementos en la lista";
  }else
  {
    HotSpace *victima = find(indice);
    if (indice == 0)
    {
      if (head == tail)
      {
        head = NULL;
        tail = NULL;
      }else
      {
        head = victima->next;
        head->previous = NULL;
        victima->next = NULL;
      }
    }else if (indice == size - 1)
    {
      tail = victima->previous;
      tail->next = NULL;
      victima->previous = NULL;
    }else
    {
      victima->next->previous = victima->previous;
      victima->previous->next = victima->next;
      victima->next = NULL;
      victima->previous = NULL;
    }
  
    delete victima;
    size --;
  }
}