#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

typedef struct{
int id;
char nombre[51];
char apellido[51];
float salario;
int sector;
int isEmpty;
}persona;

/** \brief Inicializa el array de empleados poniendolos como vacios
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Inicializar(persona eEmpleado[],int cantidad);

/** \brief Imprime el menu de opciones principales
 *
 * \return void
 *
 */
void abm_Menu();

/** \brief Da de alta empleados hasta que ocurra un error
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int  -1 en caso de error y 0 en caso de exito
 *
 */
int abm_Alta(persona eEmpleado[],int cantidad);

/** \brief Toma los datos de un empleado para darlo de alta
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param vacio int Indice del primer espacio vacio del array
 * \param cantidad int  Cantidad de empleados del array
 * \return int  Devuelve -1 en caso de error y 0 si se logra completar
 *
 */
int abm_ingresaEmpleado(persona eEmpleado[],int vacio,int cantidad);

/** \brief Busca el primer espacio vacio en el array
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int Devuelve el indice del espacio vacio
 *
 */
int abm_espacioVacio(persona eEmpleado[],int cantidad);

/** \brief  Toma el array de empleados y lo imprime por pantalla
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_imprimirEmpleados(persona eEmpleado[],int cantidad);

/** \brief  Muestra la lista de empleados y da de baja uno mediante su id
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Baja(persona eEmpleado[],int cantidad);

/** \brief  Muestra la lista de empleados y da opcion a modificar todos los parametros excepto el indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Modificar(persona eEmpleado[],int cantidad);

/** \brief  Modifica el nombre del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void nombreMod(persona eEmpleado[],int indice);

/** \brief  Modifica el apellido del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void apellidoMod(persona eEmpleado[],int indice);

/** \brief  Modifica el sector del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void sectorMod(persona eEmpleado[],int indice);

/** \brief  Modifica el salario del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void salarioMod(persona eEmpleado[],int indice);

/** \brief  Modifica el id del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void idMod(persona eEmpleado[],int indice);

/** \brief  Da de alta la id del empleado con la condicion de que no se repita
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param indice int    Indice del empleado a dar de alta
 * \param cantidad int  Cantidad de empleados del array
 * \return int Retorna 0 si no hay problemas y -1 si la id ya se encuentra en uso
 *
 */
int idUnico(persona eEmpleado[],int indice,int cantidad);

/** \brief  Intercambia el indice de dos empleados dentro del array
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param indice1 int   Indice del primer empleado
 * \param indice2 int   Indice del Segundo empleado
 * \return void
 *
 */
void intercambio(persona eEmpleado[],int indice1,int indice2);

/** \brief Imprime una lista ordenada por apellido y sector, y un breve informe sobre los salarios
 *
 * \param eEmpleado persona Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_informarEmpleados(persona eEmpleado[],int cantidad);

/** \brief  Busca el indice de un empleado mediante su id
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantiadad de empleados del array
 * \param id int    Id del empleado a buscar
 * \return int  Retorna -1 en caso de error y el indice correspondiente al id en caso exitoso
 *
 */
int buscarId(persona eEmpleado[],int cantidad,int id);

//-----------------------------------------------------------------
/**
    utn_menu: Muestra un menu de opciones y utiliza el getEntero para seleccionar una
    @param numero1: guarda el numero 1 ingresado
    @param numero2: guarda el numero 2 ingresado
    @return : retorna la opcion del menu que seleccionada
*/
int utn_menu(float numero1,float numero2);
/**
    utn_getNumeroDecimal: pide un numero con coma y utiliza a getFloat para validarlo
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos al fallar
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @return return 0 OK, -1 error.
*/
int utn_getNumeroDecimal(float* pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
/**
    utn_getEntero: pide un numero entero y utiliza getInt para validarlo
    @param pNum: puntero a numero
    @param reint: cantidad de reintentos
    @param msg: mensaje a mostrar
    @param msgError: mensaje de error
    @param maximo: el numero maximo
    @param minimo: el numero minimo
    @return return 0 OK, -1 error.
*/
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
/**
    utn_suma: realiza una suma entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la suma del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_suma(float *pResultado,float numero1, float numero2);
/**
    utn_resta: realiza una resta entre 2 numeros flotantes
    @param numero1: guarda el numero 1 ingresado
    @param numero2: guarda el numero 2 ingresado
    @param *pResultado: guarda la resta del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_resta(float *pResultado,float numero1, float numero2);
/**
    utn_multiplicacion: realiza una multiplicacion entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la multiplicacion del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_multiplicacion(float *pResultado,float numero1, float numero2);
/**
    utn_division: realiza una division entre 2 numeros flotantes
    @param numero1: guarda el numero 1 recibido
    @param numero2: guarda el numero 2 recibido
    @param *pResultado: guarda la division del numero 1 y 2
    @return return 0 OK, -1 error.
*/
int utn_division(float *pResultado,float numero1, float numero2);
/**
    utn_factoreo: realiza el factoreo de un numero utilizando un for para ir multiplicandolo
    @param numero: guarda el numero recibido
    @return return devuelve la respuesta del numero factoreado
*/
int utn_factoreo(float  numero);
/**
    utn_texto: recibe una variable para mostrar y un mensaje
    @param resultado: numero con coma
    @param mensaje: que se debe mostrar con printf
*/
void utn_texto(float resultado, char* msg);
/**
    utn_getNombre:recibe una cadera de caracteres con un mensaje y un mensaje de error para pedirle al usuario que ingrese un nombre
    @param *pNombre: guarda el Array o cadena de caracteres recibida
    @param msg: mensaje a mostrar antes de ingresar el nombre
    @param msgError: mensaje a mostrar si se ingresa un dato no deseado
*/
int utn_getNombre(char* pNombre,char* msg,char* msgError);


//----------------------------------------------------------------------------------
/**
    emp_cargarForzadaIndice: realizar una carga de datos de manera automatica al iniciar el programa
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param nombre: guarda una cadena de caracteres recibida
    @param apellido: guarda una cadena de caracteres recibida
    @param sector: guarda un int recibido
    @param sector: guarda un float recibido
    @return return 0 OK, -1 error.
*/
int emp_cargarForzadaIndice(Empleado* pEmpleado,int limite,char* nombre, char* apellido,int sector, float sueldo);
/**
    emp_cargarDatosVacio: carga un valor en el mismo campo de todas las posiciones del array recibido
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_cargarDatosVacio(Empleado* pEmpleado,int limite);
/**
    emp_cargarDatosVacio: carga valores en la posicion del array recibida
    @param pEmpleado: guarda el array recibido
    @param indice: guarda el int de la posicion del array
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_cargarIndice(Empleado* pEmpleado,int indice,int limite);
/**
    emp_mostrarIndice: muestra los datos de todas las posiciones del array
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_mostrarIndice(Empleado* pEmpleado,int limite);
/**
    emp_getEmptyIndex:busca dentro del array hasta encontrar un indice vacio donde cargar datos
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indiceVacio: guarda el indice de la posicion vacia del array
    @return return 0 OK, -1 error.
*/
int emp_getEmptyIndex(Empleado* pEmpleado,int limite,int* indiceVacio);
/**
    emp_modificarIndice: recibe un ID para modificar una posicion del array
    @param pEmpleado: guarda el array recibido
    @param id:guarda el int recibido del ID a modificar
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_modificarIndice(Empleado* pEmpleado,int id, int limite);
/**
    emp_buscarEmpleadoPorID: recibe un ID para buscar un empleado
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a buscar
    @return return el indice del array donde esta el empleado
*/
int emp_buscarEmpleadoPorId(Empleado* pEmpleado,int limite,int id);
/**
    emp_borrarEmpleado: recibe un ID para borrar un empleado
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a borrar
    @return return 0 OK, -1 error.
*/
int emp_borrarEmpleado(Empleado* pEmpleado,int limite,int id);
/**
    emp_calcularSalario: recibe el array de empleados y realizar operaciones con el salario
    (total, promedio y salarios mayores al promedio)
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_calcularSalario(Empleado* pEmpleado,int limite);
/**
    emp_checkEmptyIndex:recibe el array para checkear si esta cargado o no
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_checkEmptyIndex(Empleado* pEmpleado,int limite);
/**
    emp_ordenarIndice:recibe el array para ordenarlo con Insertion
    @param pEmpleado: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int emp_ordenarIndice(Empleado* pEmpleado, int limite);




//--------------------------------------------------------------------
//gerflix

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarListaUsuarios(eUsuario[], int);

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);
void mostrarListaSeries(eSerie[], int);



void mostrarUsuarioConSuSerie(eUsuario[], int, eSerie[], int);
void mostrarSeriesConSuUsuario(eSerie[], int, eUsuario[], int);

int cargarUsuarioEnListado(eUsuario[], int);
eUsuario cargarUsuario();
int buscarEspacioUS(eUsuario[], int);
int borrarUsuario(eUsuario[], int);
int modificarUsuario(eUsuario[], int);

int buscarEspacioSE(eSerie[], int);
int cargarSerie(eSerie[], int);
eSerie cargarSeries();
int borrarSerie(eSerie[], int);
int modificareSerie(eSerie[], int);
eSerie modfserie();

#endif // PARCIAL_H_INCLUDED
