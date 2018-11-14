#include<stdio.h>

typedef struct t_r_persona{
	int edad;
	int dni;
	char sexo;
}t_r_persona;
void cargarDatos();
void mostrarDatos(FILE *,int);
void generaHM(FILE *,FILE *,FILE *);

int main()
{
	FILE * APersona;
	FILE * AHombres;
	FILE * AMujeres;
	
	cargarDatos(&APersona);
 	
 	generaHM(APersona,AHombres,AMujeres);
 	printf("datos de mujeres mauyoress\n");
 	mostrarDatos(AMujeres,3);
 	printf("datos de hombres mauyoress\n");
 	mostrarDatos(AHombres,2);
 
	return 0;
}
void cargarDatos(FILE * a)
{
 	 a=fopen("archivo.dat","ab");
 	  t_r_persona datos_a_cargar;
 	 char seso;
 	 printf("Sale con dni =0 \n");
	 printf("Ingrese dni: ");
  	 scanf("%d",&datos_a_cargar.dni); 
	   while((datos_a_cargar.dni!=0))
 	  {
	   	printf("Ingrese edad: ");
	   	scanf("%d",&datos_a_cargar.edad);
	   	
	   	printf("Ingrese sexo: ");
	   	fflush(stdin);
	   	scanf("%c",&seso);
	   	datos_a_cargar.sexo=seso;
		   
		fwrite(&datos_a_cargar,sizeof(t_r_persona),1,a); 	
	   	
	   	printf("Ingrese dni: ");
	   	fflush(stdin);
	   	scanf("%d",&datos_a_cargar.dni);
       }
       fclose(a);
}
void mostrarDatos(FILE * a,int e)
{
	if(e==1){a=fopen("archivo.dat","rb");}
	else if(e==2){a=fopen("hombresM.dat","rb");}
	else if(e==3){a=fopen("mujeresM.dat","rb");}
	
 	  t_r_persona dL;
 	  
 	  fread(&dL,sizeof(t_r_persona),1,a);
 	  while(!feof(a))
 	  {
 	  	printf("\nDatos\n");
 	  	printf("Dni : %d\n",dL.dni);
 	  	printf("Edad: %d\n",dL.edad);
 	  	printf("Sexo:%c\n",dL.sexo);
 	  	
 	  	fread(&dL,sizeof(t_r_persona),1,a);
	   }
	  fclose(a); 
}
void generaHM(FILE *a,FILE *h,FILE *m)
{
	printf("aqui se genera el archivo\n");
	a=fopen("archivo.dat","r");
	h=fopen("hombresM.dat","wb");
 	m=fopen("mujeresM.dat","wb");
  	t_r_persona dL;
  	
  	fread(&dL,sizeof(t_r_persona),1,a);
 	  while(!feof(a))
 	  {
	  	if(((dL.edad)>18))
	  	{
	  		if((dL.sexo)=='m')
	  		{
	  			fwrite(&dL,sizeof(t_r_persona),1,h);
			  }
		    else 
		    {
	  			fwrite(&dL,sizeof(t_r_persona),1,m);
			  }
		  }
 	  	
 	  	fread(&dL,sizeof(t_r_persona),1,a);
	   }
	  fclose(a); 
	  fclose(h);
	  fclose(m);
}
