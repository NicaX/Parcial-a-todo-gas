#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#define MAX_PELICULAS 3
typedef struct
{
    int idPelicula;
    char tituloPelicula[51];
    int anioPelicula;
    char nacionalidadPelicula[51];
    char directorPelicula[51];
    int estado;
}ePelicula;


/** \brief Da de alta empleados hasta que ocurra un error
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int  -1 en caso de error y 0 en caso de exito
 *
 */
int altaPeliculas(ePelicula arrayPelicula[],int cantidad);



/** \brief Toma los datos de un empleado para darlo de alta
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param vacio int Indice del primer espacio vacio del array
 * \param cantidad int  Cantidad de empleados del array
 * \return int  Devuelve -1 en caso de error y 0 si se logra completar
 *
 */
ePelicula cargarUnaPelicula();

/** \brief Busca el primer espacio vacio en el array
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int Devuelve el indice del espacio vacio
 *
 */
int buscarLibre(ePelicula arrayPelicula[],int cantidad);

ePelicula cargarPelicula();
#endif // PELICULAS_H_INCLUDED


