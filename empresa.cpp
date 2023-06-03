#include "empresa.h"

empresa::empresa(int n_op, int n_equipos, int n_maquinas, int n_utilidades) {
    cant_operadores = (n_op > 2) ? n_op : 2;
    cant_equipos = (n_equipos > 1) ? n_equipos : 1;
    cant_maquinarias = (n_maquinas > 2) ? n_maquinas : 2;
    cant_utilidades = (n_utilidades > 1) ? n_utilidades : 1;

    // Cambiar el tamaño de los vectores al nuevo ingresado
    operadores.resize(n_op);
    equipos_de_mantenimiento.resize(n_equipos);
    maquinarias.resize(n_maquinas);
    utilidades.resize(n_utilidades);
}

empresa::empresa(const empresa &copia) {
    // Redifinir el tamaño de las vectores
    cant_operadores = copia.cant_operadores;
    cant_equipos = copia.cant_equipos;
    cant_maquinarias = copia.cant_maquinarias;
    cant_utilidades = copia.cant_utilidades;

    operadores.resize(cant_operadores);
    equipos_de_mantenimiento.resize(cant_equipos);
    maquinarias.resize(cant_maquinarias);
    utilidades.resize(cant_utilidades);

    // Copiar los elementos de los vectores del otro objeto
    copy(copia.operadores.begin(), copia.operadores.end(), operadores.begin());
    copy(copia.equipos_de_mantenimiento.begin(), copia.equipos_de_mantenimiento.end(), equipos_de_mantenimiento.begin());
    copy(copia.maquinarias.begin(), copia.maquinarias.end(), maquinarias.begin());
    copy(copia.utilidades.begin(), copia.utilidades.end(), utilidades.begin());
}

empresa::~empresa() {
    // En caso de no ser necesario, se puede quitar
    operadores.clear();
    equipos_de_mantenimiento.clear();
    maquinarias.clear();
    utilidades.clear();
}

const vector<operario> &empresa::get_operadores() const {
    return operadores;
}

const vector<equipo_mantenimiento> &empresa::get_equipos() const {
    return equipos_de_mantenimiento;
}

const vector<maquinaria> &empresa::get_maquinarias() const {
    return maquinarias;
}

int empresa::get_n_operadores() const {
    return cant_operadores;
}

int empresa::get_n_equipos() const {
    return cant_equipos;
}

int empresa::get_n_maquinarias() const {
    return cant_maquinarias;
}

void empresa::set_operadores(int a) {
    cant_operadores = a;
    operadores.resize(a);
    for(int i = 0; i < a; i++) {
        cout << " ----------- Ingrese los datos del operario N°" << i+1 << " -----------" << endl;
        cin >> operadores[i];
    }
}

void empresa::set_equipos(int a) {
    cant_equipos = a;
    equipos_de_mantenimiento.resize(a);

    for(int i = 0; i < a; i++) {
        cout<<" -----------" << "Por favor, ingrese la información del equipo N°" << i+1 <<" -----------"<< endl;
        cin >> equipos_de_mantenimiento[i];
    }
}

void empresa::set_maquinarias(int a) {
    cant_maquinarias = a;
    maquinarias.resize(a);

    for(int i = 0; i < a; i++) {
        cout<<" -----------" << "Por favor, ingrese la información de la maquinaria N°" << i+1 <<" -----------"<< endl;
        cin >> maquinarias[i];
    }
}

void empresa::set_utilidades(int a) {
    cant_utilidades = a;
    utilidades.resize(a);

    for(int i = 0; i < a; i++) {
        cout<<" -----------" << "Por favor, ingrese la utilidad N°" << i+1 <<" -----------"<< endl;
        cin >> utilidades[i];
    }
}

void empresa::imprimirnumerado_utilidades() {
    cout << "------------ Utilidades ------------" << endl;
    for (int i = 0; i < cant_utilidades; i++){
        cout << i+1 << " - " << utilidades[i] << endl;
    }
}

void empresa::imprimirnumerado_maquinarias_disponibles() {
    cout << "------------ Maquinarias disponibles ------------" << endl;
    for (int i = 0; i < cant_maquinarias; i++){
        if (maquinarias[i].get_idoperador() == "0000") // Si no hay operarios asignados
            cout << i+1 << "Placa: " <<maquinarias[i].get_placa() << " \t " << "Utilidad: " << maquinarias[i].get_utilidad() << endl;
    }
}

void empresa::imprimirnumerado_nombres_equipos() {
    cout << "------------ Equipos de mantenimiento ------------" << endl;
    for (int i = 0; i < cant_equipos; i++)
        cout << i+1<< " - " << equipos_de_mantenimiento[i].get_nombre() << endl;

}

void empresa::imprimirnumerado_operarios() {
    cout << "--------------------------------- Operarios ---------------------------------" << endl;
    cout << "    Nombre \t ID \t\t Máquina registrada" << endl;
    for (int i = 0; i < cant_operadores; i++){
        cout << i+1 <<" - " << operadores[i].get_nombre() << "\t" << operadores[i].get_id() <<"\t\t" <<operadores[i].get_maquina() << endl;
    }
}

void empresa::imprimirnumerado_maquinarias() {
    cout <<"------------------------- Maquinarias -------------------------" << endl;
    cout <<"    Placa \t utilidad \t estado \t ID Operario" << endl;
    for (int i = 0; i < cant_maquinarias; i++){
        cout << maquinarias[i].get_placa() << "\t" << maquinarias[i].get_utilidad() << "\t" << maquinarias[i].get_estado() << "\t" << maquinarias[i].get_idoperador() << endl;
    }
}

void empresa::imprimir_equipos() {
    cout <<"---------------------------- Equipos de mantenimiento ----------------------------" << endl;
    for (int i = 0; i < cant_equipos; i++){
        cout <<"Integrantes del equipo " << equipos_de_mantenimiento[i].get_nombre() << endl;
        cout << equipos_de_mantenimiento[i];
    }
}

void empresa::imprimir_operarios(){
    cout << "----------------------- Operarios -----------------------" << endl;
    for (int i = 0; i < cant_operadores; i++){
        cout << "------ Operario N°" << i+1 <<" ------" << endl;
        cout << operadores[i];
        cout << "-------------------------" << endl;
    }
}

void empresa::imprimir_mantenimiento_atrasado(fecha a) {
    cout << "------------------ Maquinarias con mantenimiento atrasado ------------------" << endl;
    cout << "Placa \t equipo encargado \t fecha esperada" << endl;
    for (int i = 0; i < cant_maquinarias; i++){
        if (maquinarias[i].get_prox_mantenimiento() < a){
            cout << maquinarias[i].get_placa() << "\t" << maquinarias[i].get_nombre_equipo() << "\t" << maquinarias[i].get_prox_mantenimiento() << endl;
        }
    }
}

void empresa::imprimir_maquinas_no_optimas() {
    cout << "------------------ Maquinarias en estado no óptimo ------------------" << endl;
    cout << "Placa \t Estado \t equipo encargado \t operador" << endl;
    for (int i=0; i<cant_maquinarias;i++){
        if (maquinarias[i].get_estado()!="Óptimo"){
            cout << maquinarias[i].get_placa() << "\t" << maquinarias[i].get_estado() << "\t" << maquinarias[i].get_nombre_equipo() << "\t" << maquinarias[i].get_idoperador() << endl;
        }
    }
}

void empresa::asignar_utilidades_equipos() {
    int aux = 0, vigia1 = 0;
    for (int i = 0; i < cant_maquinarias; i++){
        cout << "Por favor, ingrese los datos de la maquinaria con placa: " << maquinarias[i].get_placa() <<endl;
        //Ingreso del nombre del equipo de mantenimiento
        this -> imprimirnumerado_nombres_equipos();
        do {
            if (vigia1 == 1){
                cout << "El dato ingresado es inválido, recuerde que el número debe estar dentro de la lista." << endl;
            }
            cout << "Por favor, ingrese el número relacionado con el nombre del equipo de trabajo que desea asignar: " << endl;
            cin >> aux;
            vigia1 = 1;
        } while(aux <= 0 || aux > cant_equipos);

        maquinarias[i].set_nombre_equipo(equipos_de_mantenimiento[aux-1]);
        vigia1 = 0;
        //ingreso de la utilidad
        this -> imprimirnumerado_utilidades();
        do {
            if (vigia1 == 1){
                cout << "El dato ingresado es inválido, recuerde que el número debe estar dentro de la lista." << endl;
            }
            cout << "Por favor, ingrese el número relacionado con la utilidad que desea asignar: " << endl;
            cin >> aux;
            vigia1 = 1;
        } while(aux <= 0 || aux>cant_utilidades);
        vigia1 = 0;
        maquinarias[i].set_utilidad(utilidades[aux-1]);
    }
}

void empresa::asignar_maquinarias() {
    int aux = 0, vigia = 0;
    for (int i = 0; i < cant_operadores; i++){
        vigia = 0;
        do {
            if (vigia == 1) {
                cout << "Dato inválido, recuerde que el número ingresado debe coincidir con una máquina disponible." << endl;
            }
            cout<< "Por favor, introduzca el número relacionado con la máquina que operará el trabajador " << endl;
            cout << operadores[i].get_nombre() << ", que tiene el ID: " <<operadores[i].get_id() << endl;

            this -> imprimirnumerado_maquinarias_disponibles();
            cin >> aux;
            vigia = 1;
        } while (aux <= 0 || maquinarias[aux-1].get_idoperador() != "0000" || aux > cant_maquinarias);

        operadores[i].set_maquina(maquinarias[aux-1].get_placa());
        maquinarias[aux-1].set_idoperador(operadores[i]);
    }
}

void empresa::editar_operador(int a) {
    operadores[a].editaroperador();
}

void empresa::editar_maquinaria(int a) {
    int aux = 0, vigia1 = 0;
    string aux1 = "0";
    fecha aux2;
    do {
        cout << "1 - Placa. " << endl;
        cout << "2 - Utilidad." << endl;
        cout << "3 - Último mantenimiento. " << endl;
        cout << "4 - Próximo mantenimiento. " << endl;
        cout << "5 - Estado. " << endl;
        cout << "6 - Equipo de mantenimiento asignado. " << endl;
        cout << "Por favor, ingrese el número relacionado con la característica que desea modificar: " << endl;
        cin >> aux;
        switch (aux){
            case 1:
                cout << "Por favor, ingrese la nueva placa de la maquinaria " << endl;
                cin >> aux1;
                for (int i = 0; i < cant_operadores; i++) { // Cambiar placa al operario que se encargue de ella
                    if (operadores[i].get_maquina() == maquinarias[a].get_placa())
                        operadores[i].set_maquina(aux1);
                }
                maquinarias[a].set_placa(aux1);
                aux = 1;
                break;

            case 2:
                this -> imprimirnumerado_utilidades();
                do {
                    if (vigia1==1){
                        cout << "El dato ingresado es inválido, recuerde que el número debe estar dentro de la lista." << endl;
                    }
                    cout << "Por favor, ingrese el número relacionado con la utilidad que desea asignar: " << endl;
                    cin >> aux;
                    vigia1=1;
                } while(aux <= 0 || aux>cant_utilidades);
                vigia1 = 0;
                maquinarias[a].set_utilidad(utilidades[aux-1]);
                aux = 1;
                break;

            case 3:
                do {
                    cout << "Por favor, ingrese la fecha del último mantenimiento realizado" << endl;
                    cin >> aux2;
                    if (aux2 > maquinarias[a].get_prox_mantenimiento()){
                        cout << "El último mantenimiento realizado no puede ser posterior al próximo mantenimiento estipulado." << endl;
                        cout << "Por favor, inténtelo nuevamente" << endl;
                    }
                } while (aux2 > maquinarias[a].get_prox_mantenimiento());
                maquinarias[a].set_prox_mantenimiento(aux2);
                aux = 1;
                break;

            case 4:
                do {
                    cout << "Por favor, ingrese la fecha del próximo mantenimiento agendado" << endl;
                    cin >> aux2;
                    if (aux2 < maquinarias[a].get_ult_mantenimiento()){
                        cout << "El próximo mantenimiento agendado no puede ser anterior al último mantenimiento realizado" << endl;
                        cout << "Por favor, inténtelo nuevamente" << endl;
                    }
                } while (aux2 < maquinarias[a].get_ult_mantenimiento());
                maquinarias[a].set_ult_mantenimiento(aux2);
                aux = 1;
                break;

            case 5:
                maquinarias[a].set_estado();
                aux = 1;
                break;

            case 6:
                this -> imprimirnumerado_nombres_equipos();
                do {
                    cout<< "Por favor, ingrese el número relacionado con el equipo de mantenimiento que desea asignar: "<< endl;
                    cin >> aux;
                    if (aux <= 0 || aux > cant_equipos){
                        cout << "La cantidad ingresada no corresponde a ninguno de los equipos existentes, por favor inténtelo de nuevo" << endl;
                    }
                } while (aux <= 0 || aux > cant_equipos);
                maquinarias[a].set_nombre_equipo(equipos_de_mantenimiento[aux-1]);
                aux = 1;
                break;

            default:
                cout << "El número ingresado no corresponde a ninguno de los cambios posibles, por favor inténtelo nuevamente" << endl;
                aux = 0;
                break;
        }
    } while (aux == 0);
}

void empresa::editar_equipo(int a) {
    int aux = 0;
    string aux1, aux2;
    operario aux3;
    do{
        cout << "1 - Editar integrantes" << endl;
        cout << "2 - Editar nombre del equipo." << endl;
        cout << "3 - Agregar integrante" << endl;
        cout << "Por favor ingrese el número relacionado con la característica que desea editar" << endl;
        cin >> aux;
        switch (aux){
            case 1:
                equipos_de_mantenimiento[a].actualizar_operario();
                aux = 1;
                break;

            case 2:
                cout << "Por favor, ingrese el nuevo nombre del equipo" << endl;
                cin >> aux1;
                aux2 = equipos_de_mantenimiento[a].get_nombre();
                equipos_de_mantenimiento[a].set_nombre(aux1);
                for(int i = 0; i < cant_maquinarias; i++){
                    if (maquinarias[i].get_nombre_equipo() == aux2)
                        maquinarias[i].set_nombre_equipo(equipos_de_mantenimiento[a]);
                }
                aux = 1;
                break;

            case 3:
                cout << "Por favor, ingrese los datos del nuevo integrante del equipo" << endl;
                cin >> aux3;
                equipos_de_mantenimiento[a].agregar_operario(aux3);
                aux = 1;
                break;

            default:
                cout << "El dato ingresado no corresponde a ninguno de los datos posibles, por favor inténtelo nuevamente" << endl;
                aux = 0;
                break;
        }
    } while(aux == 0);

}

void empresa::agregar_operario() {
    int vigia=0, aux=0;
    if(cant_operadores < cant_maquinarias){
        operario operador_temp;
        cin >> operador_temp;
        do {
            if (vigia == 1){
                cout << "Dato inválido, recuerde que el número ingresado debe coincidir con una máquina disponible." << endl;
            }

            cout << "Por favor, introduzca el número relacionado con la máquina que operará el trabajador " << endl;
            cout << operador_temp.get_nombre() << ", que tiene el ID: " <<operador_temp.get_id() << endl;
            this -> imprimirnumerado_maquinarias_disponibles();
            cin >> aux;
            vigia = 1;
        } while (aux <= 0 || maquinarias[aux].get_idoperador() != "0000" || aux > cant_maquinarias);

        operador_temp.set_maquina(maquinarias[aux-1].get_placa());
        maquinarias[aux-1].set_idoperador(operador_temp);
        operadores.push_back(operador_temp);
        cant_operadores++;
    }
    else
        cout << "La cantidad de operarios no puede ser superior a la cantidad de maquinarias disponibles, por lo que no es posible ingresar un nuevo operario " << endl;

}

void empresa::agregar_equipo() {
    equipo_mantenimiento equipo_temp;
    cout << "Por favor, ingrese los datos del nuevo equipo " << endl;
    cin >> equipo_temp;

    equipos_de_mantenimiento.push_back(equipo_temp);
    cant_equipos++;
}

void empresa::agregar_maquinaria() {
    maquinaria maquinaria_temp;

    cin >> maquinaria_temp;

    maquinarias.push_back(maquinaria_temp);
    cant_maquinarias++;
}

void empresa::agregar_utilidad() {
    string aux;
    cout << "Por favor, ingrese la nueva utilidad de su empresa: " << endl;
    fflush(stdin);
    getline(cin,aux);
    fflush(stdin);

    utilidades.push_back(aux);
    cant_utilidades++;
}

void guardar_empresa(empresa &a){
    ofstream empresa("empresa.csv");
    if(!empresa){
        cout << "No se ha podido guardar los datos" << endl;
        return;
    }
    //Orden de guardado: Cantidad de operadores, cantidad de equipos, cantidad de maquinarias, cantidad de utilidades;
    empresa << a.get_n_operadores() << ";" << a.get_n_equipos() << ";" << a.get_n_maquinarias() << ";" << a.cant_utilidades << endl;
    empresa.close();

    //Guardado de operadores
    ofstream operadores("operadores.csv");
    if(!operadores){
        cout << "No ha sido posible guardar los operadores" << endl;
        return;
    }
    operadores <<"Nombre;ID;Maquina;Último Trabajo" <<endl;
    for(int i = 0; i < a.cant_operadores; i++){
        fecha ult_trab = a.operadores[i].get_ult_trabajo();
        string ult_trab_str = to_string(ult_trab.get_dia()) + "/" + to_string(ult_trab.get_mes()) + "/" + to_string(ult_trab.get_anio());

        operadores << a.operadores[i].get_nombre() << ";" << a.operadores[i].get_id() << ";" << a.operadores[i].get_maquina() << ";" << ult_trab_str << endl;
    }
    operadores.close();

    //Guardado de maquinarias
    ofstream  maquinarias("maquinarias.csv");
    if (!maquinarias){
        cout << "No ha sido posible guardar las maquinarias" << endl;
        return;
    }
    maquinarias << "Placa;ID Operador;Próximo mantenimiento;Estado;Nombre equipo de mantenimiento; Utilidad;Último mantenimiento "<<endl;
    for(int i = 0; i < a.cant_maquinarias; i++){
        fecha prox_mant = a.maquinarias[i].get_prox_mantenimiento(), ult_mant = a.maquinarias[i].get_ult_mantenimiento();

        string prox_mant_str = to_string(prox_mant.get_dia()) + "/" + to_string(prox_mant.get_mes()) + "/" + to_string(prox_mant.get_anio()),
                ult_mant_str = to_string(ult_mant.get_dia()) + "/" + to_string(ult_mant.get_mes()) + "/" + to_string(ult_mant.get_anio());

        maquinarias << a.maquinarias[i].get_placa()<< ";" << a.maquinarias[i].get_idoperador() << ";" << prox_mant_str << ";" << a.maquinarias[i].get_estado() << ";" << a.maquinarias[i].get_nombre_equipo() << ";" << a.maquinarias[i].get_utilidad() << ";" <<ult_mant_str<<endl;
    }
    maquinarias.close();

    ofstream equipos("equipos.csv");
    if (!equipos){
        cout << "No ha sido posible guardar los equipos de mantenimiento" << endl;
        return;
    }
    for(int i = 0; i < a.cant_equipos; i++){
        equipos << a.equipos_de_mantenimiento[i].get_integrantes() << ";" << a.equipos_de_mantenimiento[i].get_nombre() << endl;
        for (int j = 0; j < a.equipos_de_mantenimiento[i].get_integrantes(); j++){
            fecha ult_trab = a.equipos_de_mantenimiento[i].equipo[j].get_ult_trabajo();
            string ult_trab_str = to_string(ult_trab.get_dia()) + "/" + to_string(ult_trab.get_mes()) + "/" + to_string(ult_trab.get_anio());

            equipos << a.equipos_de_mantenimiento[i].equipo[j].get_nombre() << ";" << a.equipos_de_mantenimiento[i].equipo[j].get_id() << ";" << ult_trab_str << endl;
        }
    }
    equipos.close();

    ofstream utilidades("utilidades.csv");
    if(!utilidades){
        cout << "No ha sido posible guardar las utilidades " << endl;
        return;
    }
    for(int i = 0;i < a.cant_utilidades; i++){
        if(i == (a.cant_utilidades-1))
            utilidades<<a.utilidades[i] << endl;
        else
            utilidades<<a.utilidades[i]<<";";
    }
    utilidades.close();
}

void leer_empresa(empresa &a){
    ifstream empresa("empresa.csv", ios::in);
    if(!empresa){
        cout << "No ha sido posible leer los datos de la empresa" << endl;
        return;
    }
    int i = 0;
    string dato, n_ops, n_equi, n_maqui, n_utili;
    getline(empresa, dato);

    // Leer los datos numericos como cadena y luego pasarlos a enteros para guardarlos
    stringstream token(dato);
    getline(token, n_ops, ';');
    getline(token, n_equi, ';');
    getline(token, n_maqui, ';');
    getline(token, n_utili, ';');

    a.cant_operadores = atoi(n_ops.c_str());
    a.operadores.resize(a.cant_operadores);

    a.cant_equipos = atoi(n_equi.c_str());
    a.equipos_de_mantenimiento.resize(a.cant_equipos);

    a.cant_maquinarias = atoi(n_maqui.c_str());
    a.maquinarias.resize(a.cant_maquinarias);

    a.cant_utilidades = atoi(n_utili.c_str());
    a.utilidades.resize(a.cant_utilidades);

    empresa.close();

    ifstream operadores("operadores.csv");
    string nombre_op, id, maquina, ult_trabajo;
    if(!operadores){
        cout << "No ha sido posible leer los datos de los operadores" << endl;
        return;
    }

    getline(operadores, dato); // Quitar cabecera del archivo
    while(getline(operadores, dato)) {
        stringstream temp(dato);

        getline(temp, nombre_op, ';');
        a.operadores[i].set_nombre(nombre_op);

        getline(temp, id, ';');
        a.operadores[i].set_id(id);

        getline(temp, maquina, ';');
        a.operadores[i].set_maquina(maquina);

        getline(temp, ult_trabajo, ';');
        a.operadores[i].set_ult_trabajo(to_fecha(ult_trabajo));

        i++;
    }
    operadores.close();
    i = 0; // Reiniciar las posiciones en 0

    ifstream maquinarias("maquinarias.csv");
    if (!maquinarias) {
        cout << "No ha sido posible leer los datos de las maquinarias" << endl;
        return;
    }
    string placa, prox_mant, estado, nombre_equi, utilidad, ult_mant;

    getline(maquinarias, dato); // Quitar cabecera
    while(getline(maquinarias, dato)) {
        stringstream temp(dato);

        getline(temp, placa, ';');
        a.maquinarias[i].set_placa(placa);

        getline(temp, id, ';');
        a.maquinarias[i].set_idoperador(id);

        getline(temp, prox_mant, ';');
        a.maquinarias[i].set_prox_mantenimiento(to_fecha(prox_mant));

        getline(temp, estado, ';');
        a.maquinarias[i].set_estado(estado);

        getline(temp, nombre_equi, ';');
        a.maquinarias[i].set_nombre_equipo(nombre_equi);

        getline(temp, utilidad, ';');
        a.maquinarias[i].set_utilidad(utilidad);

        getline(temp, ult_trabajo, ';');
        a.maquinarias[i].set_ult_mantenimiento(to_fecha(ult_trabajo));

        i++;
    }
    maquinarias.close();
    i = 0;

    ifstream equipos("equipos.csv");
    if (!equipos) {
        cout << "No ha sido posible leer los datos de los equipos" << endl;
        return;
    }

    string n_integrantes;
    int n;
    while(getline(equipos, dato)) {
        stringstream temp(dato);

        getline(temp, n_integrantes, ';');
        n = atoi(n_integrantes.c_str());
        a.equipos_de_mantenimiento[i].set_integrantes(n);

        getline(temp, nombre_equi, ';');
        a.equipos_de_mantenimiento[i].set_nombre_equipo(nombre_equi);

        for(int j = 0; j < n; j++) {
            getline(equipos, dato);
            stringstream temp2(dato);

            getline(temp2, nombre_op, ';');
            a.equipos_de_mantenimiento[i].equipo[j].set_nombre(nombre_op);

            getline(temp2, id, ';');
            a.equipos_de_mantenimiento[i].equipo[j].set_id(id);

            getline(temp2, ult_trabajo, ';');
            a.equipos_de_mantenimiento[i].equipo[j].set_ult_trabajo(to_fecha(ult_trabajo));
        }
    }

    equipos.close();
    i = 0;

    ifstream utilidades("utilidades.csv");
    if(!utilidades) {
        cout << "No ha sido posible leer los datos de las utilidades" << endl;
        return;
    }

    getline(utilidades, dato);
    stringstream temp(dato);

    for (int j = 0; j < a.cant_utilidades; j++) {
        getline(temp, utilidad, ';');
        a.utilidades[i] = utilidad;
    }
    utilidades.close();
}