#include "empresa.h"

void solicitarpositivo(int &solicitado);
void menu_edicion_datos(empresa &a);
void menu_revision_datos(empresa &a);
void menu_principal(empresa &empresa1);


int main() {
    int opcion = 0, aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0, vigia1 = 0;
    string aux;
    cout << "¡Buen día! Bienvenido al software de gestión para empresas de maquinaria" << endl;
    do {
        if (opcion != 0){
            cout << "Ha ingresado un valor erróneo, por favor, inténtelo nuevamente" << endl;
        }
        cout << "¿Es usted administrador de una empresa nueva o registrada"<< endl;
        cout << "1 - Empresa registrada." << endl;
        cout << "2 - Empresa nueva." << endl;
        cout << "Por favor, ingrese el número relacionado a su respuesta ";
        cin >> opcion;
    } while (opcion != 1 && opcion != 2);

    if (opcion == 1){
        empresa empresa1;
        leer_empresa(empresa1);
        menu_principal(empresa1);
    }

    if (opcion == 2){
        cout << "Por favor, ingrese el nombre de su empresa: ";
        fflush(stdin);
        getline(cin, aux);
        fflush(stdin);
        cout << "Por favor, ingrese la cantidad de operadores que tiene su empresa: ";
        solicitarpositivo(aux1);
        cout << "Por favor, ingrese la cantidad de equipos de mantenimiento que tiene su empresa: ";
        solicitarpositivo(aux2);
        do {
            if (vigia1 == 1){
                cout << "La cantidad ingresada es incorrecta, el número de maquinarias debe ser igual o superior a la cantidad de operadores" << endl;
            }
            cout << "Por favor, ingrese la cantidad de maquinarias que tiene su empresa: ";
            solicitarpositivo(aux3);
            vigia1 = 1;
        }while (aux3 < aux1);
        vigia1 = 0;
        cout << "Por favor, ingrese la cantidad de utilidades que tiene su empresa: ";
        solicitarpositivo(aux4);
        empresa empresa1 (aux1, aux2, aux3, aux4);

        //ingreso de datos de los operadores
        cout << "Ingrese por favor los datos de cada uno de sus operadores." << endl;
        empresa1.set_operadores(aux1);
        //ingreso de datos de los equipos de mantenimiento
        cout << "Ingrese por favor los datos de cada equipo de mantenimiento." << endl;
        empresa1.set_equipos(aux2);
        //ingreso de datos de las maquinarias
        cout << "Ingrese por favor los datos de cada maquinaria." << endl;
        empresa1.set_maquinarias(aux3);
        //ingreso de datos de las utilidades
        cout << "Ingrese por favor cada una de las utilidades de la empresa" << endl;
        empresa1.set_utilidades(aux4);

        //estableciendo utilidades y equipos de mantenimiento para cada maquinaria
        cout << "A continuación se presentarán los nombres de los equipos de mantenimiento y las utilidades." << endl;
        cout << "Por favor, asígnele un equipo de mantenimiento y una utilidad a cada maquinaria de su empresa." << endl;
        empresa1.asignar_utilidades_equipos();
        cout << "Por favor, asígnele una maquinaria a cada uno de sus operadores" << endl;
        empresa1.asignar_maquinarias();
        menu_principal(empresa1);
    }

    return 0;
}

void solicitarpositivo(int &solicitado){
    int vigia1=0;
    do{
        if (vigia1==1){
            cout << "La cantidad ingresada es inválida, el valor debe ser superior a 0"<< endl;
        }
        cin >> solicitado;
        vigia1=1;
    } while (solicitado <= 0);
}
void menu_edicion_datos(empresa &a){
    int opcion=0;
    do{
        cout << "Bienvenido al menú de edición, desde aquí será capaz de editar los datos de su empresa" << endl;
        cout << "---------- opciones de edición ----------" << endl;
        cout << "1 - editar datos de operadores."<< endl;
        cout << "2 - editar datos de maquinaria. " << endl;
        cout << "3 - editar datos de equipos de trabajo." << endl;
        cout << "4 - Agregar utilidad." << endl;
        cout << "5 - Volver al menú principal. " << endl;
        cout << "Por favor, ingrese el número relacionado con la opción que desea ejecutar " << endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                do{
                    cout << "-------- Opciones de edición de operarios ------" << endl;
                    cout << "1 - editar datos de un operario existente. " << endl;
                    cout << "2 - añadir un operario" << endl;
                    cin>> opcion;
                } while (opcion != 1 && opcion != 2);
                if (opcion == 1){
                    a.imprimirnumerado_operarios();
                    do{
                        cout << "Por favor, ingrese el número relacionado con el operario que desea modificar";
                        cin >> opcion;
                    } while (opcion <= 0 || opcion > a.get_n_operadores());
                    a.editar_operador(opcion-1);
                    opcion=0;
                }
                if (opcion == 2){
                    a.agregar_operario();
                }
                opcion = 0;
                break;
            case 2:
                do{
                    cout << "-------- Opciones de edición maquinarias ------" << endl;
                    cout << "1 - editar datos de una maquinaria existente. " << endl;
                    cout << "2 - añadir una máquina" << endl;
                    cin >> opcion;
                }while (opcion != 1 && opcion != 2);
                if (opcion == 1){
                    a.imprimirnumerado_maquinarias();
                    do{
                        cout << "Por favor, ingrese el número relacionado con la máquina que desea modificar ";
                        cin >> opcion;
                    } while (opcion <= 0 || opcion > a.get_n_maquinarias());
                    a.editar_maquinaria(opcion-1);
                    opcion = 0;
                }
                if (opcion == 2){
                    a.agregar_maquinaria();
                    opcion = 0;
                }
                opcion = 0;
                break;
            case 3:
                do{
                    cout << "-------- Opciones de edición para Equipos de Mantenimiento ------" << endl;
                    cout << "1 - editar datos de un equipo existente. " << endl;
                    cout << "2 - añadir un equipo" << endl;
                    cin >> opcion;
                }while (opcion != 1 && opcion != 2);
                if (opcion == 1){
                    a.imprimirnumerado_nombres_equipos();
                    do{
                        cout << "Por favor, ingrese el número relacionado con el equipo que desea editar" << endl;
                        cin>>opcion;
                    } while (opcion <= 0 || opcion > a.get_n_equipos());
                    a.editar_equipo(opcion-1);
                    opcion = 0;
                }
                if (opcion == 2){
                    a.agregar_equipo();
                }
                opcion = 0;
                break;
            case 4:
                a.agregar_utilidad();
                opcion = 0;
                break;
            case 5:
                opcion = 1;
                break;
            default:
                cout << "El número ingresado no coincide con ninguna de las opciones posibles, por favor inténtelo nuevamente" << endl;
                opcion = 0;
                break;

        }
    } while(opcion == 0);
}

void menu_revision_datos(empresa &a){
    int opcion = 0;
    fecha aux;
    do{
        cout << "Bienvenido al menú de revisión, desde aquí será capaz de observar todos los datos de su empresa" << endl;
        cout << "---------- opciones de revision ----------" << endl;
        cout << "1 - Imprimir todas las maquinarias" << endl;
        cout << "2 - Imprimir todos los equipos de mantenimiento" << endl;
        cout << "3 - Imprimir todos los operadores " << endl;
        cout << "4 - Imprimir máquinas con mantenimiento atrasado" << endl;
        cout << "5 - Imprimir máquinas es estado no óptimo" << endl;
        cout << "6 - Volver al menú principal" << endl;
        cout << "Por favor, ingrese el numero relacionado con la opción que desea ejecutar " << endl;
        cin >> opcion;
        switch(opcion){
            case 1:
                a.imprimirnumerado_maquinarias();
                opcion = 0;
                break;
            case 2:
                a.imprimir_equipos();
                opcion = 0;
                break;
            case 3:
                a.imprimir_operarios();
                opcion = 0;
                break;
            case 4:
                cout << "Por favor, ingrese la fecha actual: " << endl;
                cin >> aux;
                a.imprimir_mantenimiento_atrasado(aux);
                opcion = 0;
                break;
            case 5:
                a.imprimir_maquinas_no_optimas();
                opcion = 0;
                break;
            case 6:
                opcion = 1;
                break;
            default:
                cout << "El número ingresado no corresponde a ninguna de las opciones posibles,por favor inténtelo nuevamente." << endl;
                opcion = 0;
                break;
        }
    } while(opcion == 0);
}

void menu_principal(empresa &empresa1){
    int opcion = 0;
    do{
        cout << "-------------- Menú Principal --------------" << endl;
        cout << "1 - Edición de datos." << endl;
        cout << "2 - Revisión de datos. " << endl;
        cout << "3 - Guardar datos y salir. " << endl;
        cout << "Ingrese el número relacinoado con la acción que desea realizar:" << endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                menu_edicion_datos(empresa1);
                opcion = 0;
                break;
            case 2:
                menu_revision_datos(empresa1);
                opcion = 0;
                break;
            case 3:
                cout << "Muchas gracias por utilizar el programa, ten un buen día! " << endl;
                guardar_empresa(empresa1);
                opcion = 1;
                break;
            default:
                cout << "El número ingresado no coincide con ninguna de las acciones posibles, por favor inténtelo de nuevo" << endl;
                opcion = 0;
                break;
        }
    } while(opcion == 0);
}