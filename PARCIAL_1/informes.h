#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int informes(Mascota* listM, int tamM, Servicio* listS, int tamS, Trabajo* listT, int tamT, Color* listColor, int tamC, Tipo* listTipo, int tamTipo, Cliente* listCli, int tamCli, int checkT);
int menuInformes();
void informeXColor (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli);
void imprimirXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp);
void informeXTipo (Mascota* listM, int tamM, Tipo* listT, int tamT, Color* listC, int tamC, Cliente* listCli, int tamCli);

void imprimirXTipo(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli, int resp);
void masJoven (Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli);
void separadosXColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC, Cliente* listCli, int tamCli);
int xTipoYColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC);
void informeMayorColor(Mascota* listM, int tamM, Tipo* listTipo, int tamTipo, Color* listColor, int tamC);
void servicioXMascota (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT);
void TotalPrecioXMascota(Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT);
void informeTrabajosXfecha (Trabajo* listT, int tamT, Mascota* listM, int tamM, Servicio* listS, int tamS, Tipo* listTipo, int tamTipo, Color* listC, int tamC, Cliente* listCli, int tamCli, int checkT);

