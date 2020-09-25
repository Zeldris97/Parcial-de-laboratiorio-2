#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include "rlutil.h"
using namespace std;
#include "interfaz.h"
using namespace rlutil;
#include "usuario.h"
#include "fecha.h"
#include "entrenamiento.h"
#include "Reportes.h"







void reporte_a(){

    float Va[3]={}, Vp[3]={}, pro;
    int Vc[3]={} , i;

    cout << "    PERFILES QUE SUPERAN EL PESO PROMEDIO" << endl << endl;
	Usuario reg;
	FILE* f;
	f = fopen("usuarios.dat", "rb");
	if (f == NULL) {
		cout << "No se puede leer el archivo."<<endl;
		return;
	}

	while (fread(&reg, sizeof(Usuario), 1, f)) {

           switch (reg.perfil){
	case 'a':
	case 'A':
	Va[0]+= reg.peso;
	Vc[0]++;
		break;
	case 'b':
	case 'B':
	    Va[1]+= reg.peso;
	    Vc[1]++;
		break;
	case 'c':
	case 'C':

    Va[2]+= reg.peso;
	Vc[2]++;
		break;
           }
        }

        for(i=0; i<3; i++){
        Vp[i]=Va[i]/Vc[i];

        }

cout << "PROMEDIO DE PERFILES: "<<endl;


    cout << left;
    for (i=0; i<3; i++){

    cout<<Vp[i]<<endl;

	};
  anykey();

  return;


}


void reporte_b(){
    float calorias_usuario;
    int codigo;
	Usuario reg;
	FILE* f;
	f = fopen("usuarios.dat", "rb");
	if (f == NULL) {
		cout << "No se puede leer el archivo.";
		return;
	}


	cout << "   |Apellidos" << "      |Nombres"<<"    Calorias quemadas";
    cout << endl <<"    ------------------------------------------------------------------------------------------------";
    cout<<endl;
	while (fread(&reg, sizeof(Usuario), 1, f)) {

    cout << left;
    cout << "    " <<setw(6)<< reg.nombres<<endl;
    cout << setw(16) << reg.apellidos;
    codigo=reg.ID;
    calorias_usuario=calcular_calorias(codigo);
    cout << setw(11)<<calorias_usuario;


	}
    cout<<endl;
	fclose(f);

   anykey();
   return;

}

 float calcular_calorias(int cod){
   int calorias;

   Entrenamiento reg;
	FILE* f;
	f = fopen("entrenamientos.dat", "rb");
	if (f == NULL) {
		cout << "No se puede leer el archivo.";
		return 0;
	}

	while (fread(&reg, sizeof(Entrenamiento), 1, f)) {

            if(reg.IDusuario==cod){
                calorias+=reg.calorias;

            }}
            return calorias;

            }














