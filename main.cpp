#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

using namespace std;

struct tipo_registro
{
	int num_producto;
	char descripcion[30];
	int cantidad;
	float precio;
	char garantia;
};

struct tipo_registro Registro;
FILE *alias;

void alta_secuencial();
void consultas_secuenciales();



int main()
{

	int op=0;

	
	do{
		system("cls");
		cout<<"-------------------------------"<<endl;
		cout<<"\t\tMENU DE OPCIONES"<<endl;
		cout<<"1 ALTAS SECUENCIALES"<<endl;
		cout<<"2 CONSULTAS SECUENCIALES"<<endl;
		cout<<"3 MODIFICACIONES SECUENCIALES"<<endl;
		cout<<"4 BAJAS LOGICAS SECUENCIALES"<<endl;
		cout<<"5 BAJAS FISICAS SECUENCIALES"<<endl;
		cout<<"6 LISTADO SECUENCIAL"<<endl;
		cout<<"7 Salir"<<endl; 
		cout<<"-------------------------------"<<endl;
		cin>>op;
		
		switch(op)
		{
			case 1:
				alta_secuencial();
				break;
			case 2:
				consultas_secuenciales();
				break;
		}
		system("pause");		
		
	}while(op !=7);
}

void alta_secuencial(){
	int num_producto;
	
	system("cls");
	cout<<"ALTAS DE PRODUCTOS"<<endl;
	alias = fopen("PRODUCTO.SEC","rb+");
	
	if(alias==NULL){
		alias=fopen("PRODUCTO.SEC","wb");
		cout<<"INGRESA EL NUMERO DEL PRODUCTO:  "<<endl;
		cin>>num_producto;
		fread(&Registro, sizeof(Registro),1,alias);
	}
	while(!feof(alias)){
		if(Registro.num_producto==num_producto){
			cout<<"REGISTRO DUPLICADO"<<endl;
			fclose(alias);
			getch();
			return;
		}
		fread(&Registro, sizeof(Registro),1,alias);
		cout<<"INGRESA LA DESCRIPCION:"<<endl;
		cin>>(Registro.descripcion);
		cout<<"INGRESA LA CANTIDAD"<<endl;
		cin>>Registro.cantidad;
		cout<<"INGRESA EL PRECIO"<<endl;
		cin>>Registro.precio;
		
		do{
			cout<<"GARANTIA: "<<endl;
			Registro.garantia = toupper(getche());	
		}while(Registro.garantia!='S' &&Registro.garantia !='N');
		Registro.num_producto = num_producto;
		
		fwrite(&Registro, sizeof(Registro),1,alias);
		fclose(alias);
		cout<<"PRODUCTO REGISTRADO"<<endl;
		getch();
		return;
		
	
		
	}
	
}


void consultas_secuenciales(){
  int num_producto; 
  system("cls");

  cout << "\n\tCONSULTA DE REGISTROS DE PRODUCTOS"<<endl;
  alias=fopen("PRODUCTO.SEC","rb"); 
  
  if(alias==NULL)
  {
    cout << "\n\n\n\rNo existe el archivo !!!"<<endl;
    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>"<<endl;
    getch();
    return;
  }

  cout << "\n\n\n\rNumero de producto: "<<endl; 
  cin >> num_producto;

  fread(&Registro,sizeof(Registro),1,alias);
     // Lee el "Registro", de tamano=sizeof(Registro) del archivo "alias"
  while(!feof(alias)) // Ciclo mientras no se encuentre el final del archivo
  {
    if(Registro.num_producto==num_producto)
    {
      cout << "\n\rNo Prod                    Descripcion  Cantidad        Precio  Garantia"<<endl;
	  printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.num_producto,Registro.descripcion,Registro.cantidad,Registro.precio,Registro.garantia);
      fclose(alias);
      
      getch();
      return;
    }
    fread(&Registro,sizeof(Registro),1,alias);
  }
  cout << "\n\rNo se encuentra ese registro !!!"<<endl;
  fclose(alias); // Cierra el archivo

  getch();
  return;
}
	
	
	
	
	
