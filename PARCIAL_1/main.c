#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "salas.h"
#include "trabajos.h"
#include "informes.h"

#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMSERVICIO 3
#define TAMCLIENTES 10

#define TAMMASCOTAS 100
#define TAMTRABAJO 10
#define IDSTART 100
#define IDSTARTTRABAJOS 10000
#define TAMHARDCODEO 10


Mascota listMascota[TAMMASCOTAS];
Trabajo listTrabajo[TAMTRABAJO];

int menu();

Servicio listServ[3]=
{
    {20001, "Corte", 250.00},
    {20002, "Desparasitado", 300.00},
    {20003, "Castrado", 400.00}
};

Color listColor[5]=
{
    {5001, "Negro"},
    {5002, "Blanco"},
    {5003, "Gris"},
    {5004, "Rojo"},
    {5005, "Azul"}
};

Tipo listTipo[5]=
{
    {1001, "Ave"},
    {1002, "Perro"},
    {1003, "Gato"},
    {1004, "Roedor"},
    {1005, "Pez"}
};

Cliente listCli[10]=
{
    {30000, "juan", 'm'},
    {30003, "maria", 'f'},
    {30002, "carlos", 'm'},
    {30008, "marta", 'f'},
    {30007, "lujan", 'f'},
    {30010, "dario", 'm'},
    {30001, "sofia", 'f'},
    {30004, "juana", 'f'},
    {30005, "roberto", 'm'},
    {30006, "pepe", 'm'}
};

int main()
{
    int salida=1;
    int idMascota=IDSTART;
    int idTrabajos=IDSTARTTRABAJOS;
    int check=1;
    int checkTrabajo=1;

    idMascota= idMascota+TAMHARDCODEO;
    initMascotas(listMascota, TAMMASCOTAS);
    initTrabajos(listTrabajo, TAMTRABAJO);
    harcodeomascotas(listMascota, TAMHARDCODEO);
    harcodeoTrabajos(listTrabajo, TAMTRABAJO);

    do
    {
        system("CLS");
        switch(menu())
        {
        case 1://Alta
            if (altaMascota(idMascota, listMascota, TAMMASCOTAS, listColor, listTipo) == 0)
            {
                idMascota++;
                check=1;
            }
            break;
        case 2://Modificar
            buscarMascota(listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listCli, TAMCLIENTES, check);
            break;
        case 3://Baja
            bajaMascota(listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listCli, TAMCLIENTES, check);
            break;
        case 4://lista
            mostrarMascotas(listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listCli, TAMCLIENTES, check);
            system("pause>nul");
            break;
        case 5://Listar tipos
            listarTipos(listTipo, TAMTIPO);
            system("pause>nul");
            break;
        case 6://Listar colores
            listarColores(listColor, TAMCOLOR);
            system("pause>nul");
            break;
        case 7://Listar servicios
            listarServicios(listServ, TAMSERVICIO);
            system("pause>nul");
            break;
        case 8://Alta trabajo
            if (altaTrabajo(idTrabajos, listTrabajo, TAMTRABAJO, listMascota, TAMMASCOTAS, listTipo, TAMTIPO, listColor, TAMCOLOR, listServ, TAMSERVICIO, listCli, TAMCLIENTES, check) == 0)
            {
                checkTrabajo=1;
                idTrabajos++;
            }
            break;
        case 9://Listar trabajos
            listarTrabajos(listTrabajo, TAMTRABAJO, listMascota, TAMMASCOTAS, listServ, TAMSERVICIO, checkTrabajo);
            system("pause>nul");
            break;
        case 10://Listar trabajos
            if (informes(listMascota, TAMMASCOTAS, listServ, TAMSERVICIO, listTrabajo, TAMTRABAJO, listColor, TAMCOLOR, listTipo, TAMTIPO, listCli, TAMCLIENTES, checkTrabajo)== -1)
            {
                salida=0;
            }
            break;
        case 11:
            system("cls");
            printf("\n\n**************************************************\n");
            printf("*          Saliendo de la aplicacion             *\n");
            printf("**************************************************\n\n");
            system("pause");
            salida=0;
            break;
        default:
            printf("\nSe ingreso un dato invalido\n");
            system("pause>nul");
            break;
        }
    }
    while (salida !=0);

    return 0;
}

int menu()
{
    int resp;
    printf("\n\n**************************************************\n");
    printf("*                Menu Veterinaria                *\n");
    printf("**************************************************\n\n");
    printf("1) Alta Mascota\n");
    printf("2) Modificar Mascota\n"); // MODIFICAR MASCOTA: Se ingresará el id, permitiendo en un submenú modificar: Tipo / Edad
    printf("3) Baja Mascota\n"); // Se ingresará el id de la mascota y se realizará una baja lógica.
    printf("4) Listar Mascotas\n"); //Hacer un único listado de todas las mascotas ordenadas por tipo y nombre.
    printf("5) Listar Tipos\n");
    printf("6) Listar Colores\n");
    printf("7) Listar Servicios\n");
    printf("8) Alta Trabajo\n"); //Se dará de alta cada ocurrencia de trabajo pidiéndole al usuario que elija una mascota y un Servicio
    printf("9) Listar Trabajos\n");
    printf("10) Menu de informes\n");
    printf("11) Exit\n");
    utn_getNumero(&resp, "\nIngrese una opcion: ", "\nError, ingreso incorrecto, debe ingresar de 0 a 11\n", 0, 11, 3);
    return resp;
}



