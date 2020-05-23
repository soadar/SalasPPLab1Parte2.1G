#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"
#include "salas.h"
#include "informes.h"

/** \brief imprime en pantalla el listado de tipos
 *
 * \param list array de estructura Tipo
 * \param tam tamaño del array
 *
 */

void listarTipos (Tipo* list, int tam)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*               Tipos de mascotas                *\n");
    printf("**************************************************\n\n");
    printf(" ID          Descripcion\n\n");
    for (int i=0; i < tam; i++)
    {
        printf(" %03d    %12s\n", list[i].id,list[i].descripcion);
    }
}

/** \brief imprime en pantalla el listado de colores
 *
 * \param list array de estructura Color
 * \param tam tamaño del array
 *
 */
void listarColores (Color* list, int tam)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*               Lista de colores                 *\n");
    printf("**************************************************\n\n");
    printf(" ID            Color\n\n");
    for (int i=0; i < tam; i++)
    {
        printf(" %03d    %12s\n", list[i].id,list[i].nombreColor);
    }
}

/** \brief imprime en pantalla el listado de servicios
 *
 * \param list array de estructura Servicio
 * \param tam tamaño del array
 *
 */
void listarServicios (Servicio* list, int tam)
{
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*             Listado de servicios               *\n");
    printf("**************************************************\n\n");
    printf(" ID         Descripcion       precio\n\n");
    for (int i=0; i < tam; i++)
    {
        printf(" %03d    %14s      %6.2f\n", list[i].id,list[i].descripcion, list[i].precio);
    }
}

/** \brief realiza el alta de una mascota
 *
 * \param idx ID a asignar
 * \param listM array de estructura Mascota
 * \param tamM tamaño del array listM
 * \param listColor array de estructura Color
 * \param listTipo array de estructura Tipo
 * \return retorna 0 si el alta fue exitosa, -1 en caso de error
 *
 */
int altaMascota(int idx, Mascota* listM, int tamM, Color* listColor, Tipo* listTipo)
{
    int index;
    index = buscarEmpty(listM, tamM);
    if (listM != NULL && listColor != NULL && listTipo != NULL )
    {


        if (index != -1)
        {

            Mascota auxMascota;
            system("cls");
            printf("\n\n**************************************************\n");
            printf("*                 Alta Mascota                   *\n");
            printf("**************************************************\n");
            auxMascota.id  = idx;
            getNombre(auxMascota.nombre, sizeof(auxMascota.nombre), "\nIngrese nombre: ", "\nError, ingrese solo letras\n", 3);
            listarTipos(listTipo, 5);
            utn_getNumero(&auxMascota.idTipo, "Ingrese un tipo: ", "Error, ingreso incorrecto, debe ingresar de 1001 a 1005\n", 1001, 1005, 3);
            listarColores(listColor, 5);
            utn_getNumero(&auxMascota.idColor, "Ingrese un color: ", "Error, ingreso incorrecto, debe ingresar de 5001 a 5005\n", 5001, 5005, 3);
            utn_getNumero(&auxMascota.edad, "Ingrese edad: ", "Error, la edad no puede ser un numero nevativo o mayor a 500\n", 0, 500, 3);
            printf("\n*** Carga Exitosa ***\n");
            system("pause>nul");
            auxMascota.isEmpty=0;

            listM[index] = auxMascota;
        }
        else
        {
            printf("\n\n**************************************************\n");
            printf("*          La base de datos esta llena           *\n");
            printf("**************************************************\n\n");
            return -1;
        }
        return 0;
    }
    return -1;
}

/** \brief harcodeo de mascotas para pruebas
 *
 * \param list array de estructura Mascota
 * \param tam tamaño del array list
 *
 */
void harcodeomascotas(Mascota* list, int tam)
{
    int id[10]= {100,101,102,103,104,105,106,107,108,109};
    char nombre[10][30]= {"Negra", "Rocco", "Lola", "Magui", "Michi", "Milo", "Homero", "Chispita", "piquenha", "rasta"};
    int tipo[10]= {1003,1002,1002,1004,1003,1002,1001,1005,1002,1004};
    int color[10]= {5001,5002,5003,5004,5005,5003,5002,5005,5002,5001};
    int edad[10]= {3,4,7,8,4,3,2,14,7,43};
    int cliente[10]= {30003,30002,30001,30006,30005,30004,30009,30008,300010,30007};

    for (int i=0; i<tam; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].nombre, nombre[i]);
        list[i].idTipo=tipo[i];
        list[i].idColor=color[i];
        list[i].edad=edad[i];
        list[i].isEmpty=0;
        list[i].idCliente=cliente[i];
    }
}

/**
 * \brief Busca la primera posicion vacia
 * \param list Array de estructura Mascota
 * \param tam tamaño del array list
 * \return retorna el indice de la posicion vacia si encuentra alguna o -1 si la base esta completa)
 *
 */
int buscarEmpty(Mascota* list, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 1)
        {
            return i;
            break;
        }
    }
    return -1;
}

/**
 * \brief carga los tipos en un puntero
 * \param desc puntero donde guardara la descripcion
 * \param list Array de estructura Tipo
 * \param tam tamaño del array list
 * \return retorna 0 luego de cargar la descrion o -1 si no logro cargarlo.
 *
 */
int cargarDescTipo(char* desc, int id, Tipo* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].descripcion);
            return 0;
        }
    }
    return -1;
}

int cargarDescColor(char* desc, int id, Color* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].nombreColor);
            return 0;
        }
    }
    return -1;
}

int cargarDescMascota(char* desc, int id, Mascota* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].nombre);
            return 0;
        }
    }
    return -1;
}

int cargarDescServicios(char* desc, int id, Servicio* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].descripcion);
            return 0;
        }
    }
    return -1;
}

int cargarNombreCli(char* desc, int id, Cliente* list, int tam)
{
    for (int i=0; i < tam; i++ )
    {
        if (list[i].id == id)
        {
            strcpy ( desc, list[i].nombre);
            return 0;
        }
    }
    return -1;
}

int buscarMascota(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int check)
{
    int id;
    int resp;
    system("cls");
    if( listM != NULL)
    {
        if (check == 1)
        {
            mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, check);
            printf("\nIngrese ID de la mascota: ");
            scanf("%d",&id);
            for (int i=0; i < tamM; i++)
            {
                if (listM[i].id == id)
                {
                    system("CLS");
                    printf("\n\n**************************************************\n");
                    printf("*                Modificar mascota               *\n");
                    printf("**************************************************\n");
                    printf(" ID             Nombre       Tipo     color     edad\n");
                    mostrarMascota(listM[i], tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli);
                    printf("**************************************************\n");
                    printf("\nQue desea modificar?\n\n");
                    printf("1) Tipo\n");
                    printf("2) Edad\n");
                    utn_getNumero(&resp, "Ingrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 2\n", 1, 2, 3);
                    if (resp == 1)
                    {
                        listarTipos(listTipo, 5);
                        utn_getNumero(&listM[i].idTipo, "\nIngrese ID del nuevo tipo: ", "\nError, ingreso incorrecto, debe ingresar de 1001 a 1005\n", 1001, 1005, 3);
                        printf ("\nModificacion exitosa\n");
                        system("pause>nul");
                    }
                    else
                    {
                        utn_getNumero(&listM[i].edad, "\nIngrese nueva edad: ", "\nError, ingreso incorrecto, debe ingresar de 0 a 100\n", 0, 100, 3);
                        printf ("\nModificacion exitosa\n");
                        system("pause>nul");
                    }
                    return 0;
                }
            }
            printf("\nEl ID no coincide con ninguna mascota\n");
            system("pause");
        }
        else
        {
            printf("\n\n**************************************************\n");
            printf("*          La base de datos esta vacia           *\n");
            printf("**************************************************\n\n");
            system("pause");
        }
    }
    return -1;
}

void initMascotas(Mascota* list, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        list[i].isEmpty = 1;
    }
}

void mostrarMascota(Mascota list, int tam, Tipo* listTipo, int tamT, Color* listColor, int tamC, Cliente* listCli, int tamCli)
{
    char tipo[20];
    char color[20];
    char duenio[20];
    cargarDescTipo(tipo, list.idTipo, listTipo, tamT);
    cargarDescColor(color, list.idColor, listColor, tamC);
    cargarNombreCli(duenio, list.idCliente, listCli, tamCli);
//    printf("\n ID            Nombre       Tipo      color     edad\n\n");
    printf(" %03d  %15s     %6s     %6s      %2d      %10s\n", list.id, list.nombre, tipo, color, list.edad,duenio);
}

void mostrarMascotas(Mascota* listM, int tamM, Tipo* listTipo, int tamT, Color* listColor, int tamC, Cliente* listCli, int tamCli, int check)
{
    int flag = 0;
    system("cls");
    if (check == 1)
    {
        printf("\n\n**************************************************\n");
        printf("*              Listado de mascotas               *\n");
        printf("**************************************************\n\n");
        printf(" ID            Nombre       Tipo      color     edad         duenio\n\n");
        for (int i=0; i < tamM; i++ )
        {
            if (listM[i].isEmpty == 0)
            {
                mostrarMascota(listM[i], tamM, listTipo, tamT, listColor, tamC, listCli, tamCli);
                flag= 1;
            }
        }
        if (flag == 0)
        {
            printf("*** No hay empleados que listar ***");
        }
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*          La base de datos esta vacia           *\n");
        printf("**************************************************\n\n");
        system("pause");
    }
}

int bajaMascota(Mascota* listM, int tamM, Tipo* listTipo, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, int check)
{
    char resp;
    int id;
    system("cls");
    if( listM != NULL)
    {
        if (check == 1)
        {
            mostrarMascotas(listM, tamM, listTipo, tamT, listC, tamC, listCli, tamCli, check);
            printf("\nIngrese ID de la mascota: ");
            scanf("%d",&id);
            for (int i=0; i < tamM; i++)
            {
                if (listM[i].id == id)
                {
                    system("CLS");
                    printf("\n\n**************************************************\n");
                    printf("*                  Baja mascota                  *\n");
                    printf("**************************************************\n");
                    printf(" ID             Nombre       Tipo     color     edad\n");
                    mostrarMascota(listM[i], tamM, listTipo, tamT, listC, tamC, listCli, tamCli);
                    printf("**************************************************\n");
                    printf("\nDesea continuar con la baja (s/n)?: ");
                    fflush(stdin);
                    scanf("%c",&resp);
                    if (resp == 's')
                    {
                        listM[i].isEmpty=1;
                        printf ("\nBaja exitosa\n");
                        system("pause>nul");
                    }
                    else if (resp == 'n')
                    {
                        printf ("\nBaja Cancelada\n");
                        system("pause>nul");
                    }
                    else
                    {
                        printf ("\nIngreso invalido\n");
                        system("pause>nul");
                    }
                    return 0;
                }
            }
            printf("\nEl ID no coincide con ninguna mascota\n");
            system("pause>nul");
        }
        else
        {
            printf("\n\n**************************************************\n");
            printf("*          La base de datos esta vacia           *\n");
            printf("**************************************************\n\n");
            system("pause");
        }

    }
    return -1;
}
