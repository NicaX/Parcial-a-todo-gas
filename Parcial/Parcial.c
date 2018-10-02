#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parcial.h"

void abm_Inicializar(persona eEmpleado[],int cantidad)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        eEmpleado[iteracion].isEmpty = 1;
    }
}

void abm_Menu()
{
    printf("****AGENDA****\n\n");
    printf("1_Alta.\n");
    printf("2_Modificacion.\n");
    printf("3_Baja.\n");
    printf("4_Informar.\n");
    printf("5_Salir.\n");
}

int abm_Alta(persona eEmpleado[],int cantidad)//listo
{
    int retorno=0;
    char alta = 's';
    do{
        system("cls");
        if(abm_ingresaEmpleado(eEmpleado,abm_espacioVacio(eEmpleado,cantidad),cantidad) == -1)
        {
            retorno=-1;
            break;
        }
        printf("\n\nQuiere seguir ingresando?(s/n) ");
        fflush(stdin);
        scanf("%c",&alta);
    }while(alta == 's');
    return retorno;
}

int abm_ingresaEmpleado(persona eEmpleado[],int vacio,int cantidad)//listo
{
    int retorno = -1;
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s",eEmpleado[vacio].nombre);
    printf("\nApellido: ");
    fflush(stdin);
    scanf("%s",eEmpleado[vacio].apellido);
    eEmpleado[vacio].id = vacio + 1;
    printf("\nSalario: ");
    fflush(stdin);
    scanf("%f",&eEmpleado[vacio].salario);
    printf("\nSector: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[vacio].sector);
    eEmpleado[vacio].isEmpty = 0;
    retorno = 0;
    return retorno;
}

int abm_espacioVacio(persona eEmpleado[],int cantidad)
{
    int iteracion,retorno = -1;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 1)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

void abm_imprimirEmpleados(persona eEmpleado[],int cantidad)//listo
{
    int iteracion;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            printf("-------------------------------------------------------------------------------\n");
            printf("Id: %d\t",eEmpleado[iteracion].id);
            printf("Nombre: %s\t",eEmpleado[iteracion].nombre);
            printf("Apellido: %s\n",eEmpleado[iteracion].apellido);
            printf("ID: %d\t",eEmpleado[iteracion].id);
            printf("Salario: %f\t",eEmpleado[iteracion].salario);
            printf("Sector: %d\t",eEmpleado[iteracion].sector);
        }
    }
}

void abm_Baja(persona eEmpleado[],int cantidad)//listo
{
    system("cls");
    int id,indice;
    abm_imprimirEmpleados(eEmpleado,cantidad);
    printf("\n\nIngrese el id del empleado a dar de baja: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarId(eEmpleado,cantidad,id);
    eEmpleado[indice].isEmpty = 1;
}

void abm_Modificar(persona eEmpleado[],int cantidad)
{
    system("cls");
    int indice,id,modificar;
    abm_imprimirEmpleados(eEmpleado,cantidad);
    printf("\n\nIngrese el id del empleado a modificar: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarId(eEmpleado,cantidad,id);
    printf("1_Nombre: %s\n",eEmpleado[indice].nombre);
    printf("2_Apellido: %s\n",eEmpleado[indice].apellido);
    printf("3_Salario: %f\n",eEmpleado[indice].salario);
    printf("4_Sector: %d\n",eEmpleado[indice].sector);
    fflush(stdin);
    scanf("%d",&modificar);
    system("cls");
    switch(modificar)
    {
        case 1:
            nombreMod(eEmpleado,indice);
            break;
        case 2:
            apellidoMod(eEmpleado,indice);
            break;
        case 3:
            salarioMod(eEmpleado,indice);
            break;
        case 4:
            sectorMod(eEmpleado,indice);
            break;
        default:
            system("cls");
            printf("Error: opcion no valida.");
            break;
    }
}

void nombreMod(persona eEmpleado[],int indice)//listo
{
    char auxiliar[31];
    printf("Nombre nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(eEmpleado[indice].nombre,auxiliar);
}

void apellidoMod(persona eEmpleado[],int indice)//listo
{
    char auxiliar[31];
    printf("Apelldio nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(eEmpleado[indice].apellido,auxiliar);
}

void idMod(persona eEmpleado[],int indice)//listo
{
    printf("ID nuevo: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[indice].id);
}

void sectorMod(persona eEmpleado[],int indice)//listo
{
    printf("Sector nuevo: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[indice].sector);
}

void salarioMod(persona eEmpleado[],int indice)//listo
{
    printf("Salario nuevo: ");
    fflush(stdin);
    scanf("%f",&eEmpleado[indice].salario);
}

int idUnico(persona eEmpleado[],int indice,int cantidad)
{
    int retorno = 0;
    int iteracion,comparacion;
    printf("\nID: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[indice].id);
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidad;comparacion++)
            {
                if((eEmpleado[comparacion].isEmpty == 0) && (eEmpleado[iteracion].id == eEmpleado[comparacion].id))
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

void abm_informarEmpleados(persona eEmpleado[],int cantidad)
{
    int iteracion,comparacion,contador=0;
    float totalSal,promedioSal;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidad;comparacion++)
            {
                if((eEmpleado[comparacion].isEmpty==0) && (strcmp(eEmpleado[iteracion].apellido,eEmpleado[comparacion].apellido)>0))
                {
                    intercambio(eEmpleado,iteracion,comparacion);
                }
                else if((eEmpleado[comparacion].isEmpty==0) && (eEmpleado[iteracion].sector<=eEmpleado[comparacion].sector))
                {
                    intercambio(eEmpleado,iteracion,comparacion);
                }
            }
        }
    }
    abm_imprimirEmpleados(eEmpleado,cantidad);
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty==0)
        {
            totalSal = totalSal + eEmpleado[iteracion].salario;
            contador++;
        }
    }
    printf("\nSalario total: %f\n",totalSal);
    promedioSal = totalSal / contador;
    printf("Promedio de salarios: %f\n",promedioSal);
    contador=0;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty==0 && eEmpleado[iteracion].salario>promedioSal)
        {
            contador++;
        }
    }
    printf("Cantidad de empleados que superan el salario promedio: %d",contador);
}

void intercambio(persona eEmpleado[],int indice1,int indice2)
{
    persona aux;
    aux = eEmpleado[indice1];
    eEmpleado[indice1] = eEmpleado[indice2];
    eEmpleado[indice2] = aux;
}

int buscarId(persona eEmpleado[],int cantidad,int id)
{
    int iteracion,retorno=-1;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0 && eEmpleado[iteracion].id == id)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

//--------------------------------------------------------------
/**
    utn_getInt:permite ingresar un numero entero y lo validar
    @param *pResultado: guarda el numero 1 ingresado luego de validarlo
    @return : 0 OK, -1 error
*/
/**
    utn_getFloat:permite ingresar un numero con coma y lo validar
    @param *pResultado: guarda el numero 1 ingresado luego de validarlo
    @return : 0 OK, -1 error
*/

static int getFloat(float* pResultado);
static int getInt(int* pResultado);
static int isFloat(char* pBuffer);
static int isInt(char* pBuffer);
static int isLetra(char* pBuffer);
static int getString(char* pBufferString,int limite);


int utn_menu(float numero1,float numero2)
{
    int opcion;

    printf("1. Ingresar primer numero (A: %.2f)\n",numero1);
    printf("2. Ingresar segundo numero (B: %.2f)\n",numero2);
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    fflush(stdin);
    utn_getEntero(&opcion,10,"Seleccione una opcion: ","Esa opcion no es valida \n",6,0);


    return opcion;
}
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {

        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 &&
                buffer <= maximo && buffer >= minimo )
            {
                    *pNum = buffer;
                    retorno = 0;
                    break;

            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }


        }while(reint >= 0);

    }

    return retorno;
}
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;

            }else
            {
                printf(msgError);
            }


        }else
        {
            printf(msgError);
        }
    }


    return retorno;
}

/*int utn_getCaracter(char* pOpcion,char* msg, char* msgError,int reint)
{
    char opcion;
    int retorno=-1;


    for(;reint > 0;reint--)
    {
        printf(msg);
        scanf("%s",&opcion);
        if(opcion=='a' || opcion=='b'||opcion=='c'|| opcion=='d' || opcion=='e')
        {
            *pOpcion = opcion;
            retorno = 0;
            break;
        }else
        {
            printf(msgError);
        }
    }
    return retorno;
}*/

int utn_suma(float *pResultado,float numero1,float numero2)
{

    *pResultado=numero1+numero2;

    return 0;
}

int utn_resta(float *pResultado,float numero1, float numero2)
{

    *pResultado=numero1-numero2;

    return 0;
}

int utn_multiplicacion(float *pResultado,float numero1, float numero2)
{

    *pResultado=numero1*numero2;
    return 0;
}

int utn_division(float *pResultado,float numero1, float numero2)
{
    int retorno = 0;
    if(numero2==0)
    {
        retorno = -1;
    }else
    {
        *pResultado=numero1/numero2;
    }
    return retorno;
}

int utn_factoreo(float numero)
{
    float i;
    float respuesta=1;

    if(numero==1 || numero ==0)
    {
        respuesta = 1;
    }else if(numero < 0)
    {
        respuesta = -1;
    }else
    {
         for (i = 1; i <= (int)numero; i++)
         {
            respuesta =respuesta * i;
         }

    }
    return respuesta;
}

void utn_texto(float resultado, char* msg)
{
    printf(msg,resultado);
}

int static getString(char* pBufferString,int limite)
{
    fflush(stdin);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}

int utn_getNombre(char* pNombre,char* msg,char* msgError)
{
    int retorno=-1;
    int max=50;
    char buffer[max];
    if(pNombre != NULL && msg != NULL && msgError!=NULL)
    {
        printf("%s",msg);
        if(getString(buffer,max)==0 && isLetra(buffer)==0)
        {
            retorno=0;
            strncpy(pNombre,buffer,max);
        }else
        {
            printf("%s",msgError);
            system("pause");
        }
    }
    return retorno;
}

static int isLetra(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if((pBuffer[i] < 'A' || pBuffer[i] > 'Z') && (pBuffer[i] < 'a' || pBuffer[i] > 'z') && (pBuffer[i] != ' '))
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
if(pResultado != NULL)
{
  if(getString(bufferString,4096) == 0 && isFloat(bufferString)==0)
    {

        *pResultado=atof(bufferString);
        retorno=0;

    }
}

    return retorno;
}

static int getInt(int* pResultado)
{
        int retorno=-1;
        char bufferString[4096];
    if(pResultado != NULL)
    {
      if(getString(bufferString,4096) == 0 && isInt(bufferString)==0)
        {

            *pResultado=atoi(bufferString);
            retorno=0;

        }
    }
    return retorno;
}

static int isFloat(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

static int isInt(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}



//--------------------------------------------------------------

static int generarID(void);

int emp_cargarForzadaIndice(Empleado* pEmpleado,int limite,char* nombre, char* apellido,int sector, float sueldo)
{
    int retorno=-1;
    int indice;
    emp_getEmptyIndex(pEmpleado,limite,&indice);

    if(pEmpleado != NULL && limite >0)
    {
          if(indice >= 0)
          {
            strncpy(pEmpleado[indice].nombre,nombre,50);
            strncpy(pEmpleado[indice].apellido,apellido,50);
            pEmpleado[indice].sector=sector;
            pEmpleado[indice].sueldo=sueldo;
            pEmpleado[indice].ID=generarID();
            pEmpleado[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

int emp_cargarDatosVacio(Empleado* pEmpleado, int limite)
{
    int retorno=-1;
    int i;
    if(pEmpleado != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pEmpleado[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}
int emp_cargarIndice(Empleado* pEmpleado,int indice,int limite)
{
    int retorno=-1;
    char auxnombre[50];
    char auxapellido[50];
    int auxSector;
    float auxsueldo;

    if(pEmpleado != NULL && limite >0)
    {
        if(utn_getNombre(auxnombre,"Ingrese nombre del empleado: ","Ese no es un nombre valido\n")==0)
        {
            strncpy(pEmpleado[indice].nombre,auxnombre,50);
            if(utn_getNombre(auxapellido,"Ingrese apellido del empleado: ","Ese no es un apellido valido \n")==0)
            {
                strncpy(pEmpleado[indice].apellido,auxapellido,50);
                if(utn_getEntero(&auxSector,2,"Ingrese el sector del empleado(1-Fabrica,2-Administracion,3-Tesoreria): ","Ese sector no existe\n",4,0)==0)
                {
                    pEmpleado[indice].sector=auxSector;

                    if(utn_getNumeroDecimal(&auxsueldo,10,"Ingrese el salario del empleado: ","Ese no es un salario valido\n",1000000,0)==0)
                    {
                        pEmpleado[indice].sueldo=auxsueldo;
                        pEmpleado[indice].ID=generarID();
                        pEmpleado[indice].isEmpty=0;
                        retorno =0;

                    }

                }

            }

        }
    }


    return retorno;
}

int emp_modificarIndice(Empleado* pEmpleado,int id, int limite)
{
    int retorno=-1;
    char auxnombre[50];
    char auxapellido[50];
    int auxSector;
    float auxsueldo;
    int indice;
    int opcion;
    int salir;
    indice=emp_buscarEmpleadoPorId(pEmpleado,limite,id);
    if(indice >= 0)
    {
        if(pEmpleado != NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                if(utn_getEntero(&opcion,10,MENU_MODIFICAR,"Esa no es una opcion valida\n",6,0)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            system("cls");
                            if(utn_getNombre(auxnombre,"Ingrese el nuevo nombre del empleado: ","Ese no es un nombre valido\n")==0)
                            {
                                strncpy(pEmpleado[indice].nombre,auxnombre,50);
                            }
                            fflush(stdin);
                            break;
                        case 2:
                            system("cls");
                            if(utn_getNombre(auxapellido,"Ingrese el nuevo apellido del empleado: ","Ese no es un apellido valido\n")==0)
                            {
                                    strncpy(pEmpleado[indice].apellido,auxapellido,50);
                            }
                            fflush(stdin);
                            break;
                        case 3:
                            system("cls");
                            if(utn_getEntero(&auxSector,2,"Ingrese el nuevo sector del empleado(1-Fabrica,2-Administracion,3-Tesoreria): ","Ese sector no existe\n",4,0)==0)
                            {
                                pEmpleado[indice].sector=auxSector;
                            }
                            fflush(stdin);
                            break;
                        case 4:
                            system("cls");
                            if(utn_getNumeroDecimal(&auxsueldo,10,"Ingrese el nuevo salario del empleado: ","Ese no es un salario valido",1000000,0)==0)
                            {
                                pEmpleado[indice].sueldo=auxsueldo;
                            }
                            fflush(stdin);
                            break;
                        case 5:
                            salir=1;
                    }

                 }
            }while(salir==0);
            retorno=0;

        }

    }else
    {
        printf("El ID no existe\n");
        system("pause");
    }
    return retorno;
    return 0;
}

int emp_buscarEmpleadoPorId(Empleado* pEmpleado,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            if(pEmpleado[i].ID==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int emp_borrarEmpleado(Empleado* pEmpleado,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            if(pEmpleado[i].ID==id)
            {
                pEmpleado[i].isEmpty=-1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int emp_mostrarIndice(Empleado* pEmpleado,int limite)
{
    int retorno=-1;
    int i;
    if(pEmpleado != NULL && limite > 0)
    {
        if(emp_ordenarIndice(pEmpleado,limite)==0)
        {
            for(i=0;i<limite;i++)
            {
                if(pEmpleado[i].isEmpty==0)
                {
                    printf("\nEl ID del empleado es: %d", pEmpleado[i].ID);
                    printf("\nEl nombre del empleado es: %s",pEmpleado[i].nombre);
                    printf("\nEl apellido del empleado es: %s",pEmpleado[i].apellido);
                    printf("\nEl sector del empleado es: %d",pEmpleado[i].sector);
                    printf("\nEl salario del empleado es: %.2f\n",pEmpleado[i].sueldo);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int emp_ordenarIndice(Empleado* pEmpleado, int limite)
{
  int retorno=-1;
  int i;
  int j;
  int tempID;
  int tempSector;
  float tempsueldo;
  char tempnombre[50];
  char tempapellido[50];
  if(pEmpleado != NULL && limite > 0)
  {
    for(i=1;i<limite;i++)
    {
        if(pEmpleado[i].isEmpty==0)
        {
            tempID=pEmpleado[i].ID;
            tempSector=pEmpleado[i].sector;
            tempsueldo=pEmpleado[i].sueldo;
            strcpy(tempnombre,pEmpleado[i].nombre);
            strcpy(tempapellido,pEmpleado[i].apellido);
            j=i-1;
            while(j>=0 && tempSector<pEmpleado[j].sector /*strcmp(tempapellido,pEmpleado[j].apellido)<0*/)
            {
                pEmpleado[j+1]=pEmpleado[j];
                j--;
            }
            pEmpleado[j+1].ID=tempID;
            pEmpleado[j+1].sector=tempSector;
            pEmpleado[j+1].sueldo=tempsueldo;
            strcpy(pEmpleado[j+1].nombre,tempnombre);
            strcpy(pEmpleado[j+1].apellido,tempapellido);

        }
    }
    retorno=0;
  }
  return retorno;
}
int emp_getEmptyIndex(Empleado* pEmpleado,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pEmpleado != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmpleado[i].isEmpty==-1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int emp_checkEmptyIndex(Empleado* pEmpleado,int limite)
{
    int i=0;
    int retorno = 0;
    if(pEmpleado != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmpleado[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int emp_calcularSalario(Empleado* pEmpleado,int limite)
{
    int retorno=-1;
    int i;
    float total=0;
    float cantSalarios=0;
    int cantMayorPromedio=0;
    float promedio;
    int flag=0;

    if(pEmpleado != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pEmpleado[i].isEmpty==0)
            {
                total=total + pEmpleado[i].sueldo;
                cantSalarios++;
            }
        }

        promedio=total/cantSalarios;

        for(i=0;i<limite;i++)
        {
            if(pEmpleado[i].isEmpty==0)
            {
                if(pEmpleado[i].sueldo>promedio)
                {
                    cantMayorPromedio++;
                    flag=1;
                }
            }
        }

    }

    if(cantSalarios > 0)
    {
        printf("El total de los salarios es: %.2f",total);
        printf(" y el promedio es: %.2f\n",promedio);
    }else
    {
        printf("No hay salarios cargados\n");
        system("pause");
    }
    if(flag==1)
    {
        printf("La cantidad de salarios que superan el promedio es de: %d\n",cantMayorPromedio);
        system("pause");
    }else
    {
        printf("Ningun salario supera el promedio");
        system("pause");
    }
    return retorno;
}

static int generarID(void)
{
        static int cont = -1; //es privada de la funcion, además no muere
        return ++cont;
}
//--------------------------------------------------------------------
//gerflix
void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{
    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};
    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }

}
void mostrarListaUsuarios(eUsuario usuarios[], int tam)
{
    int i;
    printf("Nombre -- ID -- ID serie\n");
    printf("\n");
    for(i=0; i<tam; i++)
    {
        if(usuarios[i].estado==1)
        {
          printf("%s -- %d -- %d\n", usuarios[i].nombre, usuarios[i].idUsuario, usuarios[i].idSerie);
        }
    }
}




void inicializarSeriesEstado(eSerie series[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        series[i].estado = 0;
    }
}


void inicializarSeriesHardCode(eSerie series[])
{
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    int i;

    for(i=0; i<5; i++)
    {
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}
void mostrarListaSeries(eSerie series[], int tam)
{
    int i;
    printf("Nombre -- Genero -- Temporadas -- serie\n");
    printf("\n");
    for(i=0; i<tam; i++)
    {
        if(series[i].estado==1)
        {
          printf("%s -- %s -- %d -- %d\n", series[i].nombre, series[i].genero, series[i].cantidadTemporadas, series[i].idSerie);
        }
    }
}



void mostrarSeriesConSuUsuario(eSerie series[], int TAMSERIE, eUsuario usuarios[], int TAMUSUARIO)
{

    int i, j;
    for(i=0; i<TAMUSUARIO;i++)
                {
                    if(series[i].estado==1 && usuarios[i].estado==1)
                    {
                        printf("%s -- %s -- %d -- %d --", series[i].nombre, series[i].genero, series[i].cantidadTemporadas, series[i].idSerie);

                        for(j=0;j<TAMSERIE;j++)
                        {
                            if(series[i].idSerie==usuarios[j].idSerie)
                            {
                                printf("%s ", usuarios[j].nombre);

                            }
                        }
                    printf("\n");
                    }
                }
}

void mostrarUsuarioConSuSerie(eUsuario usuarios[], int TAMUSUARIO, eSerie series[], int TAMSERIE)
{
    int i, j;
    for(i=0; i<TAMUSUARIO;i++)
                {
                    if(usuarios[i].estado==1)
                    {
                        printf("%s -- %d -- ", usuarios[i].nombre, usuarios[i].idUsuario, usuarios[i].idSerie);

                        for(j=0;j<TAMSERIE;j++)
                        {
                            if(usuarios[i].idSerie==series[j].idSerie)
                            {
                                printf("%s", series[j].nombre);
                                break;
                            }
                        }
                    printf("\n");
                    }
                }
}
int buscarEspacioSE(eSerie listado[], int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam;i++)
    {
        if(listado[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int buscarEspacioUS(eUsuario listado[], int tam)
{
    int indice=-1;
    int i;

    for(i=0; i<tam;i++)
    {
        if(listado[i].estado==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int cargarSerie(eSerie series[], int tam)
{
    int indice;
    int encontro=0;

    indice=buscarEspacioSE(series,tam);

    if(indice!=1)
    {
        series[indice]=cargarSeries();
        encontro=1;
    }

   return encontro;

}
eSerie cargarSeries()
{
    eSerie nuevaSerie;

    printf("Ingrese id: ");  //poner pedirentero("Ingrese legajo",&mialumno.legajo)
    scanf("%d", &nuevaSerie.idSerie);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nuevaSerie.nombre);

    printf("Ingrese genero: ");
    fflush(stdin);
    gets(nuevaSerie.genero);

     printf("Ingrese cantidad de temporadas: ");
     scanf("%d", &nuevaSerie.cantidadTemporadas);

    nuevaSerie.estado=1;

    return nuevaSerie;
}
int borrarSerie(eSerie series[], int tam)
{
    int id;
    int i;
    int aux;
    char resp;
    int encontro=0;
    printf("Seleccione la id de las siguientes series que desea borrar: \n");
    mostrarListaSeries(series,tam);
    //printf("Ingrese ID a buscar ");
    scanf("%d", &id);

    for(i=0; i<tam;i++)
    {
        if(id==series[i].idSerie && series[i].estado==1)
        {
            printf("Esta seguro en borrar la serie? s/n \n");
            fflush(stdin);
            scanf("%c", &resp);
            if(resp=='s')
            {
              series[i].estado=0;
               encontro=1;
                break;
            }
           //preguntar si esta seguro dar de baja
        }
    }
    return encontro;
}
int modificareSerie(eSerie series[], int tam)
{
    int id;
    int i;
    int encontro=0;

    printf("Seleccione la id de las siguientes series que desea modificar: \n");
    mostrarListaSeries(series,tam);
    scanf("%d", &id);

    for(i=0; i<tam;i++)
    {
        if(id==series[i].idSerie && series[i].estado==1)
        {
           series[i]=modfserie();
            encontro=1;

            break;          //preguntar si esta seguro dar de baja
                            //muestro el dato, pregunto q modificar
        }
    }
    return encontro;
}
eSerie modfserie()
{
    eSerie nuevaSerie;
    int opcion;

    printf("1. modificar nombre\n");
    printf("2. modificar genero\n");
    printf("3. modificar cantidad de temporadas\n");
    printf("4. salir \n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaSerie.nombre);
        break;

        case 2:
             printf("Ingrese genero: ");
             fflush(stdin);
             gets(nuevaSerie.genero);
            break;

        case 3:
               printf("Ingrese cantidad de temporadas: ");
                scanf("%d", &nuevaSerie.cantidadTemporadas);
            break;

    }while(opcion==4);


    nuevaSerie.estado=1;

    return nuevaSerie;
}

///****  USUARIOS ****////
int cargarUsuarioEnListado(eUsuario usuarios[], int tam)
{
    int indice;
    int encontro=0;

    indice=buscarEspacioUS(usuarios,tam);

    if(indice!=1)
    {
        usuarios[indice]=cargarUsuario();
        encontro=1;
    }

   return encontro;
}
eUsuario cargarUsuario()
{
    eUsuario nuevoUsuario;

    printf("Ingrese id: ");  //poner pedirentero("Ingrese legajo",&mialumno.legajo)
    scanf("%d", &nuevoUsuario.idUsuario);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nuevoUsuario.nombre);

    nuevoUsuario.estado=1;

    printf("Ingrese id de serie que mira: ");
    scanf("%d", &nuevoUsuario.idSerie);

    return nuevoUsuario;
}
int borrarUsuario(eUsuario usuarios[], int tam)
{
    int id;
    int i;
    int encontro=0;
    printf("Ingrese ID a buscar ");
    scanf("%d", &id);

    for(i=0; i<tam;i++)
    {
        if(id==usuarios[i].idUsuario && usuarios[i].estado==1)
        {
            usuarios[i].estado=0;
            encontro=1;
            break; //preguntar si esta seguro dar de baja
        }
    }
    return encontro;
}
int modificarUsuario(eUsuario usuarios[], int tam)
{
    int legajo;
    int i;
    int encontro=0;
    printf("Ingrese legajo a buscar ");
    scanf("%d", &legajo);

    for(i=0; i<tam;i++)
    {
        if(legajo==usuarios[i].idUsuario && usuarios[i].estado==1)
        {
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(usuarios[i].nombre);
            encontro=1;
            break;          //preguntar si esta seguro dar de baja
                            //muestro el dato, pregunto q modificar
        }
    }
    return encontro;
}
