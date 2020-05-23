#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    int id; //1000
    char descripcion[20];
} Tipo;

typedef struct
{
    int id; //5000
    char nombreColor[20];
} Color;

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;//Validar
    int idColor;//Validar
    int edad;
    int isEmpty;
    int idCliente;
} Mascota;

typedef struct
{
    int id; //20000
    char descripcion[25];
    float precio;
} Servicio;


typedef struct
{
    int id; //autoincremental
    int idMascota;//Validar
    int idServicio;//Validar
    Fecha fecha; // validar dia mes año
    int isEmpty;
} Trabajo;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
} Cliente;

#endif // MASCOTAS_H_INCLUDED

void initMascotas(Mascota* list, int tam);
void initTrabajos(Trabajo* list, int tam);
void harcodeomascotas(Mascota* list, int tam);
void harcodeoTrabajos(Trabajo* list, int tam);

int buscarEmpty(Mascota* list, int tam);
int buscarMascota(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int check);

void listarTipos (Tipo* list, int tam);
void listarColores (Color* list, int tam);
void listarServicios (Servicio* list, int tam);
void listarMascotas (Mascota* list, int tam, Tipo* listTipo, int tamT, Color* listColor, int tamC);

int cargarDescTipo(char* desc, int id, Tipo* list, int tam);
int cargarDescColor(char* desc, int id, Color* list, int tam);
int cargarDescMascota(char* desc, int id, Mascota* list, int tam);
int cargarDescServicios(char* desc, int id, Servicio* list, int tam);
int cargarPrecios(float* desc, int id, Servicio* list, int tam);
int cargarNombreCli(char* desc, int id, Cliente* list, int tam);

void mostrarMascota(Mascota list, int tam, Tipo* listTipo, int tamT, Color* listColor, int tamC, Cliente* listCli, int tamCli);
void mostrarMascotas(Mascota* listM, int tamM, Tipo* listTipo, int tamT, Color* listColor, int tamC, Cliente* listCli, int tamCli, int check);
int bajaMascota(Mascota* listM, int tamM, Tipo* listTipo, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli, int check);
int altaMascota(int idx, Mascota* listM, int tamM, Color* listColor, Tipo* listTipo);

int sortMascotas(Mascota* list, int tam);


