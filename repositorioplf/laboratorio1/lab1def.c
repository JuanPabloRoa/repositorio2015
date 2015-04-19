#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_BUFFER 512 //valor para leer lineas de carcacteres con un maximo de 512 caracteres

int Identificar(char **palabra){

if(strcmp(*palabra,"I")==0){
*palabra="I Tarapacá ";

}
if(strcmp(*palabra,"II")==0){
*palabra="II Antofagasta ";

}
if(strcmp(*palabra,"III")==0){
*palabra="III Atacama ";

}
if(strcmp(*palabra,"IV")==0){
*palabra="IV Coquimbo ";

}
if(strcmp(*palabra,"V")==0){
*palabra="V Valparaíso ";
}
if(strcmp(*palabra,"VI")==0){
*palabra="VI Libertador Bernardo O'Higgins ";
}
if(strcmp(*palabra,"VII")==0){
*palabra="VII Maule ";
}
if(strcmp(*palabra,"VIII")==0){
*palabra="VIII Biobío ";

}
if(strcmp(*palabra,"IX")==0){
*palabra="IX Araucanía ";

}
if(strcmp(*palabra,"X")==0){
*palabra="X Los Lagos ";

}
if(strcmp(*palabra,"XI")==0){
*palabra="XI Aysén del General Carlos Ibáñez del Campo ";

}
if(strcmp(*palabra,"XII")==0){
*palabra="XII Magallanes y la Antártica Chilena ";

}
if(strcmp(*palabra,"XIII")==0){
*palabra="XIII Metropolitana de Santiago ";

}
if(strcmp(*palabra,"XIV")==0){
*palabra="XIV Los Ríos ";

}
if(strcmp(*palabra,"XV")==0){
*palabra="XV Arica y Parinacota ";

}

}

int Error(int *cantidadArgumento){//funcion que devuelve 1 si existe un error o en caso contrario 0

if(*cantidadArgumento!=3){//existe error por cantidad de argumentos
if(*cantidadArgumento==1){
printf("Error: Faltan parámetros en la línea de comandos.\nUso:region.exe archivo_entrada archivo_salida\n");
}
if(*cantidadArgumento==2){
printf("Error: Faltan parámetros en la línea de comandos.\nUso:region.exe archivo_entrada archivo_salida\n");
}
if(*cantidadArgumento>3){
printf("Error: Demasiados parámetros en la línea de comandos.\nUso:region.exe archivo_entrada archivo_salida\n");
}
return 1;
}

else{
return 0;
}
}

void Transcribir(char **entrada,char **salida){

char delimitadores[3]=" 	\n";
FILE *leer=fopen(*entrada,"r");
FILE *escribir=fopen(*salida,"a");
	char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
	char*temp=(char*)malloc (sizeof(char));
	
	while(fgets(texto,SIZE_BUFFER,leer)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
	temp=strtok(texto,delimitadores);//divido las lineas segun aparecen delimitadores
	
    while(temp != NULL ){  //mientras la linea no termine avanzare por las palabras
		
		
		Identificar(&temp);
		fprintf(escribir,"%s ",temp);
		temp=strtok(NULL,delimitadores);
		

	}
	fprintf(escribir,"\n");
	}fclose(leer);
	fclose(escribir);
}

void VaciarSalida(char**salida){

FILE *vaciar=fopen(*salida,"w");
fprintf(vaciar,"");
fclose(vaciar);
}


int main(int argc, char **argv){
//argc es un entero que representa la cantidad de parametros entregado por linea de comando incluyendo el nombre del ejecutable
//argv es una arreglo que guarda los parametros ingresados
    
if (Error(&argc)==1){//si existe un error en la cantidad de parametros se termina la ejecucion
return 0;
}else{//ahora verifico errores de existencia de archivos
FILE *lectorEntrada= fopen(argv[1],"r");
FILE *lectorSalida=fopen(argv[2],"r");
if(lectorEntrada==NULL){
printf("Error: El archivo de entrada no existe");
fclose(lectorEntrada);
fclose(lectorSalida);
return 0;
}
if(lectorSalida==NULL){
printf("Error: El archivo de salida no existe");
fclose(lectorEntrada);
fclose(lectorSalida);
return 0;
}

VaciarSalida(&argv[2]);//vacio el archivo de salida en caso que contenga datos de pruebas anteriores


Transcribir(&argv[1],&argv[2]);


}
return 0;
}






