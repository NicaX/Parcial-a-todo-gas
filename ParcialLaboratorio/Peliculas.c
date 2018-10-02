#include <stdio.h>
#include <stdlib.h>
#include "Peliculas.h"

/*int altaPelicula(ePelicula arrayPelicula[],int cantidad)//listo
{
    int retorno=0;
    char alta = 's';
    do{
        system("cls");
        if(altaUnaPelicula(ePelicula,buscarLibre(ePelicula arrayPelicula[],cantidad),cantidad) == -1)
        {
            retorno=-1;
            break;
        }
        printf("\n\nQuiere seguir ingresando?(s/n) ");
        fflush(stdin);
        scanf("%c",&alta);
    }while(alta == 's');
    return retorno;
}*/

int altaPeliculas(ePelicula arrayPelicula[],int cantidad)
{
    int index;
    int retorno=0;

    index=buscarLibre(arrayPelicula,cantidad);

    if(index!=1)
    {

        arrayPelicula[index]=cargarUnaPelicula();

    }
    else
    {
        system("cls");
        printf("No hay mas lugar disponible. Borre un contacto\n");
        system("pause");
    }
    return retorno;
}

int buscarLibre(ePelicula arrayPelicula[],int cantidad)
{
    int i;
    int indice = -1;
    for(i=0;i<cantidad;i++)
    {
        if(arrayPelicula[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

ePelicula cargarPelicula()
{
    ePelicula nuevaPelicula;

    printf("Ingrese id: ");
    scanf("%d", &nuevaPelicula.idPelicula);

    printf("Ingrese titulo de pelicula: ");
    fflush(stdin);
    gets(nuevaPelicula.tituloPelicula);

    printf("Ingrese año de la pelicula: ");
    scanf("%d", &nuevaPelicula.anioPelicula);

    printf("Ingrese nacionalidadPelicula: ");
    fflush(stdin);
    gets(nuevaPelicula.nacionalidadPelicula);

    printf("Ingrese directorPelicula: ");
    fflush(stdin);
    gets(nuevaPelicula.directorPelicula);



    nuevaPelicula.estado=1;

    return nuevaPelicula;
}
