# Proyecto: Inventario
Mi proyecto se enfoca en crear un sistema funcione similar al inventario de un videojuego. Esto por medio de un archivo donde se escriba la ID del objeto que se contiene en un espacio y la cantidad de ese objeto. Por medio de un menú sería posible bucar la ubicación de un objeto, ordenar los objetos por ID, nombre o cantidad de objetos, modificar espacios específicos del inventario y al salir se genera un archivo con el inventario obtenido.

Los objetos que estoy utilizando vienen del juego "Terraria".

## Descripción del avance 1
En este avance cree las clases para los objetos y los espacios del inventario y cree un vector de cada uno de ellos, ambos vectores toman valores de archivos cvs para hace que sea posible modificar los archivos por medio de excel para facilitar crear los archivos. Además cree las funciones para organizar el inventario por ID, nombre y cantidad de objetos.

## Descripción del avance 2
En este avance agregué una lista doblemente ligada que funciona como una hotbar a la que se le pueden asignar los valores de uno de los espacios del inventario, al iniciarse el programa se toman los primeros 10 espacios del inventario y se guardan en la hotbar, además egregué un menú para que el usuario pueda modificar su inventario y hotbar.

### Cambios sobre el primer avance
1. Delimitar un tamaño de 50 para el vector Inventario: Al definir un tamaño fijo para el vector no me debo preocupar por cambiar el tamaño del vector en caso de que haya más o menos elementos y arriesgarme a no tener espacios de memoria contiguos suficientes para crear el vector.
2. Eliminar 3 archivos de salida: No es necesario y con el menú es posible acceder a los distintos tipos de organización
3. Sobrecargar el operador = en la clase espacio: Facilitar la implementación del constructor por copia.

## Descripción del avance 3
En este avance modifiqué las salidas para hacer más intuitivas las opciones del menú

### Cambios sobre el segundo avance
1. Cambiar la funcionalidad de "Mostrar inventario", "Mostrar hotbar" y "Mostrar todo" en el menú: Los cambié para que al seleccionar la opción muestre en la consola los objetos pertinentes en lugar de cargarlos al archivo.
2. Cambiar la cración de los archivos hacia el final del programa: Los archivos de salida ahora se generan solo una vez al final del programa ya que con el cambio anterior los datos del inventario y la hotbar en la consola no hay necesidad de generar varias veces los archivos, de esta manera los archivos sirve para guardar el inventario y la hotbar finales fuera de la ejecucuón del programa.
3. Eliminar "Muestra datos" en las clases Espacio e Item: No se estaban usando y eran redundantes con escribe datos.

## Instrucciones para compilar el avance de proyecto
Presionar el botón "Run"

## Instrucciones para ejecutar el avance de proyecto
Presionar el botón "Run"

## Descripción de las entradas del avance de proyecto
Se necesitan 2 archivos, ambos en formatos csv para el inicio del programa:

**Items:** Cada línea debe ser un objeto y con su nombre e ID (Agregar un espacio al último elemento ya que la última coma no se toma en cuenta)

ejemplo:
1,tierra,
2,roca,
3,metal ,

**Inventario:** Cada línea representa un espacio del inventario y debe contener la id del objeto y la cantidad del objeto.

ejemplo:
1,9,
2,23,
3,45,

Al llegar al menú se maneja al escribir el número de la opción que se quiera elegir y los valores subsecuentes que se pidan.

## Descripción de las salidas del avance de proyecto
Al seleccionar las opciones de "mostar inventario", "mostrar hotbar" o "mostrar todo" crea uno o 2 de los siguientes archivos:

- "Inventario.txt" muestra los contenidos del inventario
- "Hotbar.txt" muestra los contenidos de la hotbar

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
En el porgrama uso un shell sort, el cual utiliza 3 ciclos, un while que ya que se basa en el paso, que se va dividiendo a la mitad cada vuelta tiene una complejudad menor a O(n), por lo que se simplifica a O(log (n)) y 2 ciclos for que en el mejor de los casos pasan por el vector una sola vez para cambiar un solo dato (O(n)) y en el peor de los casos tienen que cambiar todos los elementos haciendo que recorra n veces todo el arreglo (O(n^2)), todo junto el shell sort tiene una complejudad de O((n log(n))^2) en el peor de los casos.

El resto de los ciclos que sacan los datos de los archivos cvs tienen una complejidad de O(n) ya que son solo 1 y el resto de las líneas son instrucciones que solo hacen una cosa como asignar valores, abrir y cerrar archivos, etc, por lo que son O(1).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

Todas las operaciones de inicialización son de complejidad O(n) ya que tengo que en el caso de los vectores inventario y objetos tengo que leer n líneas de los archivos para generar los objetos correspondientes y en la hotbar tengo que agregar todos los nodos que la conforman. La creación de los archivos también es de complejidad O(n) ya que tengo que obtener los datos de cada objeto del inventario y la hotbar.

El resto de las operaciones con vectores so O(1) ya acceder al valor de un vector tiene una complejidad O(1) ya que solo requiero indicar la posición a la que quiero acceder y en esa misma línea en la que accedo a una localidad de memoria puedo modificarla. Así que cuando quiero modificar, agregar o borrar un valor en el inventario solo llamo la isntrucción para acceder a esa localidad y si necesito un item como todos los objetos están en un vector no añade a la complejidad.

En cambio en la lista modificar los elementos tiene una complejudad de O(log(n)) ya que aunque las asignaciones de valores también tienen una complejidad de O(1), el acceder al elemento correcto de la lista requiere que la recorra para encontrarlo. Ya que es una lista dóblemente ligada puedo comprobar si el índice está del lado izquierdo o derecho de la lista y empezar a recorrer la lista desde el inicio o el final lo que hace que en el peor de los casos solo tenga que recorrer la mitad de la lista, lo que simplifica a O(log(n)).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Varias de las funciones del menú como los if para comprobar que los índices están dentro del rango de la estructura de datos y que hay valores en el indice al que se quiere acceder son de complejidad O(1), pero al ser solo parte de una función más grande la complejidad cambia, por ejemplo todas las operaciones que involucran eliminar, modificar o agregar valores a un vector se mantienen de complejidad O(1), pero las mimsas funciones en la lista aumentan a O(log(n)) ya que esa es la complejidad de acceder a un elemento de una lista

El menú es el único elemento que no depende de una estructura de datos, este menú es de complejidad O(1) ya que como utiliza un switch case va directo al caso que corresponde a la opción, en lugar de comparar cada caso individualmente.

El algoritmo de ordenamiento es el elemento más complejo del programa ya que en el mejor de los casos tiene una complejidad de O(n log(n)) y en el peor de los casos es de O((n log(n))^2), esto hace que mi programa tenga una complejidad de O((n log(n))^2).

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Seleccioné un shell sort ya que como el programa simula un inventario en un videojuego considero que reducir la cantidad de memoria utilizada sería lo mejor para reducir la cantidad de recusos que se necesitan para el juego, debido a esto eliminé el merge sort como opción, de los algoritmos que tienen una ocmpeljidad de memoria de O(1) me decidí por el shell sort ya que es mucho más rápido que selection y bubble sort, reduciendo el tiempo que tiene que esperar el jugador para ordenar su inventario.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Decidí utilizar un vector para almacenar los items ya que son un grupo muy grande de elementos y voy a estar accediendo constantemente a los items para generar los espacios del inventario y la hotbar, por lo que la complejidad O(n) del vector ayuda a eso y como todo el vector se genera desde el principio y no se modifica su tamaño es poco probable que me encuentre con problemas de que no haya suficientes espacios de memoria consecutivos para tener todos los datos, este mismo razonaliento se aplica al inventario ya que es el espacio de almacenamiento más grande al que el usuario tiene acceso durante la ejecución y se está accediendo constantemente a el para hacer cambios a los elementos dentro, pero no al arreglo en si y pasar datos a la hotbar.

Me decidí por una lista ligada para la hotbar ya que es un elemento más pequeño por lo que un acceso un poco más complejo no afecta mucho, pero a diferencia del inventario o los items, la hotbar cambia de tamaño dependiendo de los elementos que se le añadan y eliminen, por lo que utilizar una estructura de datos más flexible respecto a espacios de memoria permite tener estos cambios constantes de tamaño sin mucha perocupación.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.

Para la consulta de información en los vectores de Items e Inventario utilizo .at() para acceder al valor en el índice indicado, esto es ya que al utilizar corchetes incluso si excedo el límite del vector añade datos y extiende el arreglo, utilizando .at() evito posibles cambiar el tamaño de los vectores y añadir datos innecesarios.

Para acceder a los elementos de la hotbar ya que es una lista ligada tengo que ir recorriendo los elementos de la lista hasta llegar al que quiero, para esto creé la fnción find() que recorre la lista hasta llegar al índice indicado y regresa el apuntador hacia el objeto en la posición deseada.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

El archivo "Items.csv" es necesario para que el programa pueda funcionar, e incluso si "Inventario.csv" no es esctictamente necesario ayuda a que cargar información de un inventariuo preexistente sea posible y sencillo ya que se puede armar en excel.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

Los  archivos "Inventario.txt" y "Hotbar.txt" son una de las salidas del programa, esto permite que el usuario pueda tener un registro de cómo terminó su inventario tras la ejecución del programa y que la información no se pierda cuando la ejecución termine.