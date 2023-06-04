<figure>
    <img src="Archivos/utb.jpg" alt="Imagen a la izquierda" style="width: 220px; height: 110px; float: left; margin-right: 10px;">
    <figcaption style="text-align: right; font-family: 'Carlito'">
        <p style="font-size: 26px">Facultad de Ingeniería</p>
        <p style="line-height: 1px; font-size: 16px;">Curso: Programación Orientada a Objetos</p>
        <p style="line-height: 1px; font-size: 16px;">Caso de estudio - Taller</p>
        <p style="line-height: 1px; font-size: 16px;">Diederik Antonio Montaño Burbano –T00068226</p>
        <p style="line-height: 1px; font-size: 16px;">Juan Diego Pérez Navarro –T00067699</p>
    </figcaption>
</figure>

## CASO EMPRESA

UTILIZANDO HERENCIA, CLASES, POLIMORFISMO, ARCHIVOS Y SOBRECARGA DE OPERADORES

Una empresa de transporte se encuentra en constante crecimiento, con el objetivo de adaptarse a las nuevas tecnologías y la competitividad del mercado, su jefe decide solicitarle un software capaz de organizar y verificar de forma eficaz los datos más básicos de la empresa.

Teniendo en cuenta su crecimiento, la empresa tiene nuevas y variadas utilidades, con variedad de maquinarias, operadores y equipos de mantenimiento a su disposición.

Cada empleado debe estar registrado con su nombre completo, ID empresarial y la última fecha en la que se reportó a su labor.

Los equipos de trabajo deben de contar con un nombre individual y estar formados por, como mínimo, tres empleados.

Los operadores son trabajadores especiales, que además de contar con los datos comunes, también están registrados junto a la máquina que se encargan de operar.

Las maquinarias son registradas con su placa, utilidad elegida, equipo de mantenimiento asignado y el ID del operador que se encuentra encargado de ella.

Si bien el software es un prototipo, la empresa desea que demuestre qué tan útil y flexible puede ser, por lo que debe ser capaz de editar todos los datos que se ingresen y la información debe ser persistente en el sistema (no perderse entre usos).

Hay información en específico a la que se debe poder acceder con gran facilidad: Listado de máquinas en mal estado, listado de operadores, listado de equipos de mantenimiento, listado de maquinarias y listado de maquinarias con mantenimientos atrasados.

---

### Clase base operario

Para la solución de este caso, se planteó como clase fundamental a “operario”, que contiene todos los elementos generales necesarios para el desarrollo del programa. Sus atributos son:

- **Nombre:** Nombre del empleado, almacenado en forma de string.
- **ID:** ID del empleado, almacenado en forma de string.
- **Ult_trabajo:** Objeto de la clase fecha, que contiene la última fecha de trabajo del empleado dentro de la empresa.
- **Maquina:** Placa de la maquinaria que se encuentra a cargo del operario, almacenada como string.

Los **métodos** de la clase operario son:

- **get_x() y set_x():** Como práctica de programación estándar, cada uno de los atributos de la clase operario cuenta con un método set asociado, que permite otorgarle un valor aún si no se cuenta con acceso a los elementos privados, y un método get, que permite recibir este valor.
- **void editaroperador():** Este método permite, por medio de un menú, editar uno de los atributos del objeto operador que lo invoca.

Esta clase también cuenta con dos funciones amigas:

```C++
friend ostream &operator << (ostream &, const operario &);
friend istream &operator >> (istream &, operario &);
```

Respectivamente, sobrecargas de los operadores de salida y entrada de datos, para facilitar la toma e impresión por consola de objetos de esta clase.

---

### Clase derivada equipo de mantenimiento

Los equipos de mantenimiento son un derivado de la **clase operador**, que hereda sus métodos y atributos, aunque no haga uso de estos últimos. Cuenta con nuevos atributos tales como:

- **Equipo:** Un vector contenedor de operarios, creado mediante la clase “vector” incluida mediante la librería homónima.
- **Nombre_equipo:** Una variable de tipo string que contiene el nombre del equipo de mantenimiento.
- **Integrantes:** Una variable de tipo int que contiene la cantidad de integrantes en el equipo.
  Además de los métodos heredados, Equipo de mantenimiento cuenta con los siguientes métodos propios:
- **get_x() y set_x():** Continuando con los métodos fundamentales para una buena programación, equipo de mantenimiento cuenta con métodos get y set para cada uno de sus atributos, que permiten acceder a los datos internos aún si no se cuenta con acceso al área privada del objeto.
- **void agregar_operario(const operario &):** Este método permite agregar un operario extra al final del vector “Equipo”.
- **void actualizar_operario():** Este método permite actualizar la información de un operario dentro del vector equipo.

A su vez, esta clase también cuenta con funciones amigas encargadas de sobrecargar los operadores de entrada y salida, que son:

```C++
friend ostream &operator << (ostream &, const equipo_mantenimiento &);
friend istream &operator >> (istream &, equipo_mantenimiento &);
```

---

### Clase maquinaria

La clase maquinaria cuenta con los datos que deben almacenar todas las maquinarias, y es independiente al resto de clases, por lo que no hereda métodos ni atributos. Está formada por:

- **Placa:** Un atributo de tipo string en el que se almacena la placa de la maquinaria.
- **Utilidad:** Un atributo de tipo string que contiene la utilidad que tiene la maquinaria dentro de la empresa.
- **Estado:** Un atributo de tipo string que puede tener tres valores posibles: “Óptimo”, “Medio” y “Dañado”.
- **Ult_mantenimiento:** De tipo fecha, este atributo contiene la última en la que se realizó un mantenimiento.
- **Prox_mantenimiento:** Este atributo de tipo fecha contiene la próxima fecha estipulada para realizar un mantenimiento.
- **ID_operador:** Este atributo de tipo string contiene el ID del operador asignado a la maquinaria.
- **Nombre_equipo:** De tipo string, contiene el nombre del equipo de mantenimiento asignado a la maquinaria.

Esta clase cuenta con los siguientes **métodos**:

- **get_x() y set_x():** Como el resto de las clases, maquinarias también cuenta con métodos
  get y set asignados para cada uno de sus atributos.

Al igual que el resto de clases, cuenta con **funciones amigas** para sobrecargar los operadores de entrada y salida:

```C++
friend ostream &operator << (ostream &, const maquinaria &);
friend istream &operator >> (istream &, maquinaria &);
```

---

### Clase derivada empresa

La clase empresa es, a grandes rasgos, una clase contenedora para todas las clases creadas anteriormente. Hereda los **atributos** y **métodos** de las clases **maquinaria**, **operario** y **equipo de mantenimiento**, sin embargo, los atributos no son utilizados y la herencia se encuentra enfocada en los métodos.

La clase empresa cuenta con los siguientes atributos:

- **Operadores:** Un vector creado con la clase “vector”, que contiene a todos los operadores que trabajan en la empresa.
- **Cant_operadores:** Contiene el tamaño del vector operadores en formato entero.
- **Equipos de mantenimiento:** Un vector de la clase “vector”, que contiene objetos de la clase equipos de mantenimiento.
- **Cant_equipos:** Contiene el tamaño del vector equipos de mantenimiento en formato entero.
- **Maquinarias:** Un vector de la clase “vector” que contiene objetos de la clase maquinaria.
- **Cant_maquinarias:** Contiene el tamaño del vector maquinarias en formato entero.
- **Utilidades:** Un vector de la clase “vector” que contiene las utilidades disponibles en la empresa en forma de string.

Los **métodos** de la clase empresa son:

- **get_x() y set_x():** Como todas las otras clases, empresa cuenta con métodos get y set para acceder a cada uno de sus atributos aún cuando no se tiene acceso directo a la sección privada del objeto.
- **void imprimirnumerado_x():** “Imprimirnumerado” es el nombre de un conjunto de métodos que imprimen información numerada con el objetivo de permitirle al usuario relacionar números con datos e ingresarlos dentro de un menú. La implementación de estos métodos optimiza el desarrollo del código, evitando que deban realizarse secciones de código similares de forma continua al realizar impresiones.
- **void Imprimir_x():** A diferencia de los “Imprimirnumerado” los métodos imprimir imprimen toda la información de uno de los vectores de los atributos, aunque en algunos casos condicionados. El método “Imprimir_mantenimiento_atrasado(fecha)” por ejemplo, recibe la fecha actual como parámetro e imprime únicamente las maquinarias que tienen fechas de mantenimiento asignadas anteriores.
- **void Asignar_utilidades_equipos():** Debido a que los datos se conectan entre si de forma constante, no es posible ingresarlos todos al mismo tiempo dentro del programa. “Asignar utilidades y equipos” cubre esta falencia al asignar una utilidad y un equipo de mantenimiento a cada maquinaria.
- **void asignar_maquinarias():** Este método cumple la misma función que el anterior, pero relaciona las maquinarias con sus respectivos operadores.
- **void agregar_x():** Los métodos del grupo “Agregar” se encuentran encargados de incluir nuevos objetos al final de los vectores de la clase.
- **void editar_x():** Los métodos del grupo “editar” permiten acceder a un valor específico dentro de uno de los vectores de la clase y editar sus atributos.

A su vez, esta clase cuenta con dos **funciones amigas:**

```C++
friend void guardar_empresa(empresa &);
friend void leer_empresa(empresa &);
```

“Guardar empresa” se encarga de crear un archivo.csv que contiene toda la información de la empresa. Por otro lado “leer empresa” permite extraer la información de este archivo .csv y hacerla funcional dentro del programa
