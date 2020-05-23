#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"
#include "salas.h"
#include "informes.h"

/** \brief Menu de informes
 *
 */


int menuInformes()
{
    int resp;
    system("CLS");
    printf("\n\n**************************************************\n");
    printf("*                Menu de informes                *\n");
    printf("**************************************************\n\n");
    printf("\n1) Mascotas por color");
    printf("\n2) Mascotas por tipo");
    printf("\n3) Mascota mas joven");
    printf("\n4) Mascotas por tipo");
    printf("\n5) Cantidad por tipo y color");
    printf("\n6) El color mas usado");
    printf("\n7) Servicios por mascota");
    printf("\n8) Total costo por mascota");
    printf("\n9) Servicios por fecha");
    utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 9\n", 1, 9, 3);
    return resp;
}

/** \brief switch con la respuesta del menu de informes
 *
 * \param
 * \param
 * \return
 *
 */

int informes(Mascota* listM, int tamM, Servicio* listS, int tamS, Trabajo* listT, int tamT, Color* listColor, int tamC, Tipo* listTipo, int tamTipo, Cliente* listCli, int tamCli, int checkT)
{
    char seguir = 's';
    while (seguir == 's')
    {
        switch(menuInformes())
        {
        case 1://colores de un tipo
            informeXColor(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
            system("pause>nul");
            break;
        case 2://colores de un tipo
            informeXTipo(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
            system("pause>nul");
            break;
        case 3://colores de un tipo
            masJoven(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
            system("pause>nul");
            break;
        case 4://colores de un tipo
            separadosXColor(listM, tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
            system("pause>nul");
            break;
        case 5://colores de un tipo
            xTipoYColor(listM, tamM, listTipo, tamTipo, listColor, tamC);
            system("pause>nul");
            break;
        case 6://colores de un tipo
            informeMayorColor(listM, tamM, listTipo, tamTipo, listColor, tamC);
            system("pause>nul");
            break;
        case 7://colores de un tipo
            servicioXMascota(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamC, checkT);
            system("pause>nul");
            break;
        case 8://colores de un tipo
            TotalPrecioXMascota(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamC, checkT);
            system("pause>nul");
            break;
        case 9://colores de un tipo
            informeTrabajosXfecha(listT, tamT, listM, tamM, listS, tamS, listTipo, tamTipo, listColor, tamC, listCli, tamC, checkT);
            system("pause>nul");
            break;
        }
    }
    return 0;
}


void informeXColor (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli)
{
    int resp;
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*         Informes por tipo de mascota           *\n");
    printf("**************************************************\n");
    utn_getNumero(&resp, "1) Negro\n2) Blanco\n3) Gris\n4) Rojo\n5) Azul\n\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 5\n", 1, 5, 3);
    system("cls");
    switch(resp)
    {
    case 1:
        printf("\n\n**************************************************\n");
        printf("*               Listado de negros                *\n");
        printf("**************************************************\n");
        break;
    case 2:
        printf("\n\n**************************************************\n");
        printf("*               Listado de blancos               *\n");
        printf("**************************************************\n");
        break;
    case 3:
        printf("\n\n**************************************************\n");
        printf("*               Listado de grises                *\n");
        printf("**************************************************\n");
        break;
    case 4:
        printf("\n\n**************************************************\n");
        printf("*               Listado de rojos                 *\n");
        printf("**************************************************\n");
        break;
    case 5:
        printf("\n\n**************************************************\n");
        printf("*               Listado de azules                *\n");
        printf("**************************************************\n");
        break;
    }
    imprimirXColor(listM, tamM, listT, tamT, listC, tamC, listCli, tamCli, resp);
}

void imprimirXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp)
{
    printf("\n ID            Nombre       Tipo      color     edad\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idColor == resp+5000 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
    printf("\n\n");
}

void informeXTipo (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli)
{
    int resp;
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*         Informes por tipo de mascota           *\n");
    printf("**************************************************\n");
    utn_getNumero(&resp, "1) Aves\n2) Perros\n3) Gatos\n4) Roedores\n5) Peces\n\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 5\n", 1, 5, 3);
    system("cls");
    switch(resp)
    {
    case 1:
        printf("\n\n**************************************************\n");
        printf("*                listado de Aves                 *\n");
        printf("**************************************************\n");
        break;
    case 2:
        printf("\n\n**************************************************\n");
        printf("*               listado de perros                *\n");
        printf("**************************************************\n");
        break;
    case 3:
        printf("\n\n**************************************************\n");
        printf("*               listado de gatos                 *\n");
        printf("**************************************************\n");
        break;
    case 4:
        printf("\n\n**************************************************\n");
        printf("*              listado de roedores               *\n");
        printf("**************************************************\n");
        break;
    case 5:
        printf("\n\n**************************************************\n");
        printf("*               listado de peces                 *\n");
        printf("**************************************************\n");
        break;
    }
    imprimirXTipo(listM, tamM, listT, tamT, listC, tamC, listCli, tamCli, resp);
}

void imprimirXTipo(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp)
{
    printf("\n ID            Nombre       Tipo      color     edad\n\n");
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == resp+1000 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
    printf("\n\n");
}

void masJoven (Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli)
{
    int menor;
    int indexMenor;

    system("CLS");
    if (listM[0].isEmpty == 0)
    {
        menor=listM[0].edad;
    }
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].edad < menor && listM[i].isEmpty == 0)
        {
            menor = listM[i].edad;
            indexMenor=i;
        }
    }
    printf("\n\n");
    printf("\n**************************************************\n");
    printf("La mascota mas joven es :\n\n");
    printf(" ID            Nombre       Tipo      color     edad\n");
    mostrarMascota(listM[indexMenor],tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
    printf("\n**************************************************\n");
    printf("\n\n");
}

void separadosXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli)
{
    printf("\n\n**************************************************\n");
    printf("*                listado de aves                 *\n");
    printf("**************************************************");
    printf("\n ID            Nombre       Tipo      color     edad\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1001 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
    printf("\n");
    printf("\n*****************************************************\n");
    printf("*                listado de perros                  *\n");
    printf("*****************************************************");
    printf("\n ID            Nombre       Tipo      color     edad\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1002 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
    printf("\n*****************************************************\n");
    printf("*                listado de gatos                   *\n");
    printf("*****************************************************");
    printf("\n ID            Nombre       Tipo      color     edad\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1003 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
    printf("\n*****************************************************\n");
    printf("*                listado de roedores                *\n");
    printf("*****************************************************");
    printf("\n ID            Nombre       Tipo      color     edad\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1004 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
    printf("\n*****************************************************\n");
    printf("*                listado de peces                   *\n");
    printf("*****************************************************");
    printf("\n ID            Nombre       Tipo      color     edad\n");

    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idTipo == 1005 && listM[i].isEmpty == 0)
        {
            mostrarMascota(listM[i], tamM, listTipo, tamTipo, listColor, tamC, listCli, tamCli);
        }
    }
}

int xTipoYColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC)
{
    int tipo;
    int color;
    char descTipo[20]= "";
    char descColor[20]= "";
    char tipoElegido[20]= "";
    char colorElegido[20]= "";
    int suma=0;

    system("cls");
    printf("\n\n**************************************************\n");
    printf("*           Informe por tipo y color             *\n");
    printf("**************************************************\n");
    listarTipos(listTipo, 5);
    utn_getNumero(&tipo, "Ingrese un tipo: ", "Error, ingreso incorrecto, debe ingresar de 1001 a 1005\n", 1001, 1005, 3);
    listarColores(listColor, 5);
    utn_getNumero(&color, "Ingrese un color: ", "Error, ingreso incorrecto, debe ingresar de 5001 a 5005\n", 5001, 5005, 3);
    for (int i=0; i < tamM; i++ )
    {
        cargarDescTipo(descTipo, listM[i].idTipo, listTipo, tamTipo);
        cargarDescColor(descColor, listM[i].idColor, listColor, tamC);
        if (listM[i].idTipo == tipo && listM[i].idColor == color)
        {
            suma++;
            strcpy(tipoElegido,descTipo);
            strcpy(colorElegido,descColor);
        }
    }
    if (suma == 0 )
    {
        printf("\n\n**************************************************\n");
        printf("\nNo hay ninguna mascota con esa descripcion\n");
        printf("\n**************************************************\n");
        return -1;
    }
    else
    {
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("\nMascota elegida : %s \nColor elegido : %s\nCantidad en la base de datos: %d\n",tipoElegido, colorElegido, suma);
        printf("\n**************************************************\n");
    }
    return 0;
}

void informeMayorColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC)
{
    int negro=0;
    int blanco=0;
    int gris=0;
    int rojo=0;
    int azul=0;
    for (int i=0; i < tamM; i++ )
    {
        if (listM[i].idColor == 5001 && listM[i].isEmpty == 0)
        {
            negro++;
        }
        else if (listM[i].idColor == 5002 && listM[i].isEmpty == 0)
        {
            blanco++;
        }
        else if (listM[i].idColor == 5003 && listM[i].isEmpty == 0)
        {
            gris++;
        }
        else if (listM[i].idColor == 5004 && listM[i].isEmpty == 0)
        {
            rojo++;
        }
        else if (listM[i].idColor == 5005 && listM[i].isEmpty == 0)
        {
            azul++;
        }
    }
    if (negro > blanco && negro > gris && negro > rojo && negro > azul)
    {
        printf("\nHay mas cantidad de negro, con un total de %d", negro);
    }
    else if (blanco > negro && blanco > gris && blanco > rojo && blanco > azul)
    {
        printf("\nHay mas cantidad de blanco, con un total de %d", blanco);
    }
    else if (gris > negro && gris > blanco && gris > rojo && gris > azul)
    {
        printf("\nHay mas cantidad de gris, con un total de %d", gris);
    }
    else if (rojo > negro && rojo > gris && rojo > blanco && rojo > azul)
    {
        printf("\nHay mas cantidad de rojo, con un total de %d", rojo);
    }
    else if (azul > negro && azul > gris && azul > blanco && azul > rojo)
    {
        printf("\nHay mas cantidad de azul, con un total de %d", azul);
    }

    printf("\n\n");
}



void servicioXMascota (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT)
{
    system("CLS");
    if (checkT == 1)
    {
        int id;
        char descM[20];
        char descS[20];
        float descP;
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("*        Informe de trabajos por mascota         *\n");
        printf("**************************************************\n");
        mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, checkT);
        printf("\nIngrese ID de la mascota: ");
        scanf("%d",&id);
        system("CLS");
        printf("\n ID Trabajo          Mascota         Servicio        Fecha       precio\n\n");
        for (int i=0; i < tamT; i++)
        {
            if (listT[i].isEmpty == 0 && listT[i].idMascota == id)
            {
                cargarDescMascota(descM, listT[i].idMascota, listM, tamM);
                cargarDescServicios(descS, listT[i].idServicio, listS, tamS);
                cargarPrecios(&descP, listT[i].idServicio, listS, tamT);
                printf("   %03d    %15s   %15s      %02d/%02d/%04d    %6.2f\n", listT[i].id, descM, descS, listT[i].fecha.dia, listT[i].fecha.mes, listT[i].fecha.anio,descP);
            }
        }
        printf("\n");
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*            No hay trabajos cargados            *\n");
        printf("**************************************************\n\n");
    }
}

void TotalPrecioXMascota (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT)
{
    system("CLS");
    if (checkT == 1)
    {
        int id;
        char descM[20];
        char descS[20];
        float descP;
        float suma;
        system("CLS");
        printf("\n\n**************************************************\n");
        printf("*        Informe de trabajos por mascota         *\n");
        printf("**************************************************\n");
        mostrarMascotas(listM, tamM, listTipo, tamTipo, listC, tamC, listCli, tamCli, checkT);
        printf("\nIngrese ID de la mascota: ");
        scanf("%d",&id);
        system("CLS");
        for (int i=0; i < tamT; i++)
        {
            if (listT[i].isEmpty == 0 && listT[i].idMascota == id)
            {
                cargarDescMascota(descM, listT[i].idMascota, listM, tamM);
                cargarDescServicios(descS, listT[i].idServicio, listS, tamS);
                cargarPrecios(&descP, listT[i].idServicio, listS, tamT);
                suma+=listS[i].precio;
            }
        }
        printf("\nEl costo total es %6.2f\n", suma);
        printf("\n");
    }
    else
    {
        printf("\n\n**************************************************\n");
        printf("*            No hay trabajos cargados            *\n");
        printf("**************************************************\n\n");
    }
}

void informeTrabajosXfecha (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT)
{
    int mes;
    int dia;
    int anio;
    int flag=0;
    system("cls");
    printf("\n\n**************************************************\n");
    printf("*                Trabajos por mes                *\n");
    printf("**************************************************\n\n");
    utn_getNumero(&dia, "\nIngrese dia: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 31\n", 1, 31, 3);
    utn_getNumero(&mes, "\nIngrese mes: ", "\nError, ingreso incorrecto, debe ingresar de 1 a 12\n", 1, 12, 3);
    utn_getNumero(&anio, "\nIngrese anio: ", "\nError, ingreso incorrecto, debe ingresar de 2020 a 2030\n", 2020, 2030, 3);
    printf("\n");
    printf("\n ID            Nombre       Tipo      color     edad \n\n");
    for (int i=0; i < tamT; i++ )
    {
        if (listT[i].isEmpty == 0 && listT[i].fecha.dia == dia && listT[i].fecha.mes == mes && listT[i].fecha.anio == anio)
        {
            //cargarDescMascota(descM, listT[i].idMascota, listM, tamM);
            //cargarDescServicios(descS, listT[i].idServicio, listS, tamS);
            //cargarPrecios(&descP, listT[i].idServicio, listS, tamT);
            mostrarMascota(listM[i], tamM, listTipo, tamT, listC, tamC, listCli, tamCli);
            flag = 1;
        }
    }
    printf("\n\n");

    if (flag == 0)
    {
        printf("\n*** No hay trabajos que ingresaron ese mes ***\n");
    }
}
