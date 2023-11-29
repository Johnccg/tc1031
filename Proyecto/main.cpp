/*
  Created on: 20/09/2023
  Author: Juan Carlos Calderón García
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Hotbar.h"


using namespace std;

//Función para crear los items a partir de la línea de texto y almacenarlos en un vector
void crearItem(string &str, vector<Item> &almacen)
{
  Item test;
  
  int cut = str.find(",");
  int ID = stoi(str.substr(0, cut));
  //Se le suma 1 a cut para saltarse la coma
  //A al langitud del archivo se le resta la ubicación de la coma, -2 para evitar la coma del inicio y el final y -1 por que la ubicación contempla el 0
  string name = str.substr(cut + 1, str.length() - cut - 3);

  if (ID <= 0)
  {
   test = Item();
  }else
  {
    test = Item(ID,name); 
  }

  almacen.push_back(test);
}


//Función para crear los espacios a partir de la línea de texto y almacenarlos en un vector
void crearInventario(string &str, vector<Espacio> &almacen, vector<Item> &base, int cont)
{
  int cut = str.find(",");
  int inicio = stoi(str.substr(0, cut));
  int fin = stoi(str.substr(cut + 1, str.length() - cut - 3));
  //Resto 1 para que coincida con el índice
  Espacio test(base[inicio - 1],fin);

  if (cont >= 50)
  {
    cout << "Elemento excede el límite de inventario" << endl << endl;
  }else
  {
    almacen.at(cont) = test;
  }
}

void crearArchivo(vector<Espacio> &vec)
{
  ofstream Inv("Inventario.txt");
  for (int i = 0; i < vec.size(); i++)
    {
      Inv << vec.at(i).escribeDatos();
    }
  Inv.close();
}

void crearArchivo(Hotbar &hot)
{
  ofstream Inv("Hotbar.txt");
  Inv << hot.escribeDatos();
  Inv.close();
}

//Un shell sort para organizar el inventario por ID
void organizarID(vector<Espacio> &vec)
{
  int paso = vec.size()/2;
  Espacio temp;

  while (paso > 0)
    {
      for (int i = paso; i < vec.size(); i++)
        {
          for (int j = i; j >= paso; j -= paso)
            {
              if (vec[j].getID() < vec[j - paso].getID())
              {
                temp = vec[j];
                vec[j] = vec[j - paso];
                vec[j - paso] = temp;
              }
            }
        }
      paso /= 2;
    }
}


//Un shell sort para organizar el inventario alfabéticamente
void organizarAlfa(vector<Espacio> &vec)
{
  int paso = vec.size()/2;
  Espacio temp;

  while (paso > 0)
    {
      for (int i = paso; i < vec.size(); i++)
        {
          for (int j = i; j >= paso; j -= paso)
            {
              if (vec[j].getNombre() < vec[j - paso].getNombre())
              {
                temp = vec[j];
                vec[j] = vec[j - paso];
                vec[j - paso] = temp;
              }
            }
        }
      paso /= 2;
    }
}


//Un shell sort para organizar el inventario por cantidad
void organizarCant(vector<Espacio> &vec)
{
  int paso = vec.size()/2;
  Espacio temp;

  while (paso > 0)
    {
      for (int i = paso; i < vec.size(); i++)
        {
          for (int j = i; j >= paso; j -= paso)
            {
              if (vec[j].getCantidad() < vec[j - paso].getCantidad())
              {
                temp = vec[j];
                vec[j] = vec[j - paso];
                vec[j - paso] = temp;
              }
            }
        }
      paso /= 2;
    }
}


int main()
{
  string linea;
  int cont = 0;
  vector<Item> objetos; 
  vector<Espacio> inventario(50);
  Hotbar hotbar;
  int opc = 10;
  int index = 0;
  int temp = 0;
  
  //Pasar por todas las líneas del archivo con items
  ifstream loadItems("Items.csv");
  while (getline(loadItems,linea))
    {
      crearItem(linea,objetos);
    }
  loadItems.close();

  
  //Pasar por todas las líneas del archivo con el inventario
  ifstream loadInventario("Inventario.csv");
  while (getline(loadInventario,linea))
    {
      crearInventario(linea, inventario, objetos, cont);
      cont++;
    }
  loadInventario.close();

  //Crea la lista para la hotbar a partir de los primeros 10 elementos del inventario
  try
    {
      for (int i = 0; i < 10; i++)
      {
        hotbar.add(inventario.at(i));
      }
    }
  catch(char e)
    {
      if (e == 'z')
      {
        cout << "Elemento excede el límite de 10 en la hotbar" << endl << endl;
      }else if (e == 'm')
      {
        cerr << "No hay memoria para alocar al elemento" << endl << endl;
      }else
      {
        cerr << "Hubo un error" << endl << endl;
      }

    }

//menú para que el usuario pueda manipular el inventario y la hotbar
  while (opc != 0)
    {
      cout << endl << endl << "1.- Modificar elementos del inventario\n2.- Borrar elementos del inventario\n3.- Añadir elementos al inventario\n4.- Organizar el inventario\n5.- Mostrar el inventario\n6.- Modificar elementos de la hotbar\n7.- Borrar elementos de la hotbar\n8.- Añadir elementos a la hotbar\n9.- Mostrar la hotbar\n10.- Mostrar todo\n¿Qué quieres hacer? (Para salir escribe 0)  ";
      
      try
        {
          cin >> opc;
          
          switch(opc)
            {
              case 0:
                //salir
                break;
              
              case 1:
                //modificar elemento del inventario
                cout << "¿Qué espacio quieres modificar? (índice)";
                cin >> index;

                if (index >= 50 || index < 0)
                {
                  throw 's';
                  break;
                } else if (index >= cont)
                {
                  throw 'c';
                  break;
                }
                
                cout << "¿Cuál es el ID del item por el que quieres reemplazarlo?";
                cin >> temp;

                if (temp >= objetos.size() || index < 0)
                {
                  throw 'i';
                  break;
                }
                
                inventario.at(index).setItem(objetos.at(temp - 1));
    
                cout << "¿Cuántos objetos hay?  ";
                cin >> temp;
                inventario.at(index).setCantidad(temp);

                break;
              
              case 2:
                //borrar elemento del inventario
                cout << "¿Qué espacio quieres borrar? (ínidce)  ";
                cin >> index;
  
                if (index >= 50 || index < 0)
                {
                  throw 's';
                  break;
                } else if (index >= cont)
                {
                  throw 'c';
                  break;
                }
  
                inventario.erase(inventario.begin() + index);
                cont --;
                break;
              
              case 3:
                //añadir elemento al inventario
                if (cont >= 50 || index < 0)
                {
                  throw 's';
                  break;
                }

                inventario.push_back(Espacio());
                
                cout << "¿Cuál es el ID del nuevo item?  ";
                cin >> temp;

                if (temp >= objetos.size() || index < 0)
                {
                  throw 'i';
                  break;
                }

                inventario.at(cont).setItem(objetos.at(temp - 1));

                cout << "¿Cuántos objetos hay?  ";
                cin >> temp;
                inventario.at(cont).setCantidad(temp);

                cont ++;
                break;
              
              case 4:
                //ordena el inventario
                cout << "1.- Alfabéticamente\n2.- Por ID\n3.- Por cantidad\n¿Cómo los quieres ordenar?  ";
                cin >> temp;

                if (temp == 1)
                {
                  organizarAlfa(inventario);
                }else if (temp == 2)
                {
                  organizarID(inventario);
                }else if (temp == 3)
                {
                  organizarCant(inventario);
                }else
                {
                  cout << "Respuesta inválida, no está en las opciones";
                }
                break;
              
              case 5:
                //Muestra en la consola todos los espacios del inventario
                cout << endl << endl;
                for (int i = 0; i < inventario.size(); i++)
                {
                  cout << inventario.at(i).escribeDatos();
                }
                break;
              
              case 6:
                //modificar elemento de la hotbar
                cout << "¿Qué espacio del inventario quieres asignar a la hotbar?";
                cin >> temp;
                
                if (temp >= 50 || index < 0)
                {
                  throw 's';
                  break;
                } else if (temp >= cont)
                {
                  throw 'c';
                  break;
                }
                
                cout << "¿Qué espacio de la hotbar quieres modificar?";
                cin >> index;
                
                hotbar.assign(inventario.at(temp), index);
                break;
              
              case 7:
                //borrar elemento de la hotbar
                cout << "¿Qué espacio quieres borrar?";
                cin >> index;

                hotbar.deletes(index);
                break;
              
              case 8:
                //añadir elemento a la hotbar
                cout << "¿Qué espacio del inventario quieres agregar a la hotbar?";
                cin >> index;

                if (index >= 50 || index < 0)
                {
                  throw 's';
                  break;
                } else if (index >= cont)
                {
                  throw 'c';
                  break;
                }

                hotbar.add(inventario.at(index));
                break;
              
              case 9:
                //crear el archivo de la hotbar
                cout << endl << endl << hotbar.escribeDatos();
                break;
              case 10:
                //crear el archivo del inventario y la hotbar
                cout << "\n\nInventario: \n\n";
                for (int i = 0; i < inventario.size(); i++)
                {
                  cout << inventario.at(i).escribeDatos();
                }
                cout << "\n\nHotbar: \n\n" << hotbar.escribeDatos();
              break;
              default:
                cout << "Respuesta inválida, no está en las opciones";
            }
        }
      catch (char e)
        {
          if (e == 'i')
          {
            cout << "El índice no corresponde a ninguna ID";
          }else if (e == 's')
          {
            cout << "Elemento está fuera de los límites del inventario";
          }else if (e == 'c')
          {
            cout << "El elemento no existe";
          }else if (e == 'z')
          {
            cout << "El elemento está fuera de los límites de la hotbar";
          }else if (e == 'm')
          {
            cout << "No hay memoria disponible para el elemento";
          }
        }
    }
  //crear el archivo inventario.txt
  crearArchivo(inventario);

  //crear el archivo de la hotbar
  crearArchivo(hotbar);
  
  cout << endl << "fin";
}