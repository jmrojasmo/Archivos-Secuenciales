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
FILE *temporal;

void alta_secuencial();
void consultas_secuenciales();
void modificacion_secuencial();
void baja_logica_secuencial();
void baja_fisica_secuencial();
void listado_secuencial();



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
			case 3:
				modificacion_secuencial();
				break;
			case 4:
				baja_logica_secuencial();
				break;
			case 5:
				baja_fisica_secuencial();
				break;
			case 6:
				listado_secuencial();
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
		alias=fopen("PRODUCTO.SEC","rb+");
	}
	cout<<"INGRESA EL NUMERO DEL PRODUCTO:  "<<endl;
	cin>>num_producto;
		
	int count=0;
	//Busca si ya existe el numero de producto en el archivo
	while(!feof(alias)){
		if(Registro.num_producto==num_producto){
			cout<<"REGISTRO DUPLICADO"<<endl;
			fclose(alias);
			getch();
			return;
		}
		fread(&Registro,sizeof(Registro),1,alias);
	}
	//Como no existe el numero de producto, permite leer los demas datos para registrar el producto
	Registro.num_producto=num_producto;
	cout<<"INGRESA LA DESCRIPCION:"<<endl;
	cin>>(Registro.descripcion);
	cout<<"INGRESA LA CANTIDAD"<<endl;
	cin>>Registro.cantidad;
	cout<<"INGRESA EL PRECIO"<<endl;
	cin>>Registro.precio;
	do{
		cout<<"\nGARANTIA: "<<endl;
		Registro.garantia = toupper(getche());
	}while(Registro.garantia!='S' &&Registro.garantia !='N');
	
	fwrite(&Registro, sizeof(Registro),1,alias);
	fclose(alias);
    getch();
}

void consultas_secuenciales(){
  int num_producto; 
  system("cls");

  cout << "\n\tCONSULTA DE REGISTROS DE PRODUCTOS"<<endl;
  alias=fopen("PRODUCTO.SEC","rb"); 
  
  if(alias==NULL)
  {
    cout << "\n\n\rNO EXISTE EL ARCHIVO !!!"<<endl;
    cout << "\n\r****OPRIMA CUALQUIER TECLA PARA CONTINUAR****"<<endl;
    getch();
    return;
  }

  cout << "\n\n\rNUMERO DE PRODUCTO: "<<endl; 
  cin >> num_producto;

  fread(&Registro,sizeof(Registro),1,alias);
     
  while(!feof(alias)) 
  {
    if(Registro.num_producto==num_producto)
    {
      cout << "\nNo Prod                    Descripcion  Cantidad        Precio      Garantia"<<endl;
	  printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t\t%c?\r\r\n\n",Registro.num_producto,Registro.descripcion,Registro.cantidad,Registro.precio,Registro.garantia);
      fclose(alias);
      
      getch();
      return;
    }
    fread(&Registro,sizeof(Registro),1,alias);
  }
  cout << "\n\r NO SE ENCUENTRA EL REGISTRO !!!"<<endl;
  fclose(alias); 

  getch();
  return;
}


void modificacion_secuencial()
{
  int num_producto; 
  system("cls");

  cout << "\nMODIFICACION DE REGISTROS DE PRODUCTOS"<<endl;
  alias=fopen("PRODUCTO.SEC","rb+"); 
				     
  if(alias==NULL) 
  {
    cout << "\n\n\nNO EXISTE EL ARCHIVO !!!"<<endl;
    cout << "\n**** PRESIONE CUALQUIER TECLA PARA CONTINUAR ****"<<endl;
    getch();
    return;
  }

  cout << "\n\n\nNUMERO DE PRODUCTO: "<<endl; 
  cin >> num_producto;

  fread(&Registro,sizeof(Registro),1,alias);
     
  while(!feof(alias))
  {
    if(Registro.num_producto==num_producto)
    {
      cout << "\n\rNo Prod                    Descripcion  Cantidad        Precio  Garantia"<<endl;
      cout << "\n\r------------------------------------------------------------------------";
      printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.num_producto,Registro.descripcion,Registro.cantidad,Registro.precio,Registro.garantia);

      cout << "\n\n\nINGRESE LOS NUEVOS CAMBIOS ..."<<endl;
      cout << "\nDESCRIPCION: "<<endl; 
	  cin>>(Registro.descripcion);
      cout << "\nCANTIDAD   : "<<endl; 
	  cin >> Registro.cantidad;
      cout << "\nPRECIO     : "<<endl; 
	  cin >> Registro.precio;
      do
      {
	cout << "\nGARANTIA   : "<<endl; 
	Registro.garantia=toupper(getche());
      }while(Registro.garantia!='S' && Registro.garantia!='N');

      fseek(alias,ftell(alias)-sizeof(Registro),SEEK_SET);
      fwrite(&Registro,sizeof(Registro),1,alias);  
						   
      fclose(alias);   
      cout << "\n\n\nREGISTRO MODIFICADO !!!"<<endl;
      cout << "\n**** OPRIMA CUALQUIER TECLA PARA CONTINUAR ****"<<endl;
      getch();
      return;
    }
    fread(&Registro,sizeof(Registro),1,alias);
  }
  cout << "\n\rNO SE ENCUENTRA EL REGISTRO !!!";
  fclose(alias); 
  //cout << "\nOPRIMA CUALQUIER TECLA PARA CONTINUAR"<<endl;
  getch();
  return;
}

void baja_logica_secuencial()
{
  int num_producto; 
  char op;
  system("cls");

  cout << "\n\rBAJAS LOGICAS DE REGISTROS DE PRODUCTOS";
  alias=fopen("PRODUCTO.SEC","rb+"); 
				    
  if(alias==NULL)  
  {
    cout << "\n\n\n NO EXISTE EL ARCHIVO !!!";
    cout << "\n\r\r<<< OPRIMA CUALQUIER TECLA PARA CONTINUAR >>>";
    getch();
    
  }

  cout << "\n\n\nNUMERO DE PRODUCTO: "<<endl; 
  cin >> num_producto;

  fread(&Registro,sizeof(Registro),1,alias);
     
  while(!feof(alias)) 
  {
    if(Registro.num_producto==num_producto)
    {
      cout << "\n\rNo Prod                    Descripcion  Cantidad        Precio  Garantia";
      cout << "\n\r------------------------------------------------------------------------";
      printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.num_producto,Registro.descripcion,Registro.cantidad,Registro.precio,Registro.garantia);

      Registro.num_producto=0;
      strcpy(Registro.descripcion,"");
      Registro.cantidad=0;
      Registro.precio=0.0;
      Registro.garantia=' ';

      do {
	  cout << "\n\nESTA SEGURO QUE DESEA ELIMINAR ESTE REGISTRO DE FORMA PERMANENTE? [S/N] ";
	  op=toupper(getche());
      }while(op!='S' && op!='N');

      if(op=='S')
      {
	 
	 fseek(alias,ftell(alias)-sizeof(Registro),SEEK_SET);
	 fwrite(&Registro,sizeof(Registro),1,alias);  
	 cout << "\n\n\nREGISTRO ELIMINADO !!!";
      }
      fclose(alias);   
      cout << "\n\n<<<OPRIMA CUALQUIER TECLA PARA CONTINUAR<<<";
      getch();
      return;
    }
    fread(&Registro,sizeof(Registro),1,alias);
  }
  cout << "\n\r\rNO SE ENCUENTRA ESE REGISTRO !!!";
  fclose(alias); 
  cout << "\n\n\r\r**** OPRIMA CUALQUIER TECLA PARA CONTINUAR ****";
  getch();
  return;
}

void baja_fisica_secuencial()
{
FILE *temporal; //Declaracion local de una variable para controlar el
		// archivo temporal
  system("cls");

  cout << "\n\rBAJAS FISICAS DE REGISTROS DE PRODUCTOS";
  alias=fopen("PRODUCTO.SEC","rb"); // Intenta abrir el archivo PRODUCTO.SEC
				     // en modo de solo lectura
  if(alias==NULL)  // Valida la existencia del archivo
  {
    cout << "\n\n\n\rNo existe el archivo !!!";
    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
    getch();
    return;
  }

  temporal=fopen("TEMPORAL.TMP","wb"); 

  fread(&Registro,sizeof(Registro),1,alias);
     
  while(!feof(alias)) 
  {
    if(Registro.num_producto!=0)
	 fwrite(&Registro,sizeof(Registro),1,temporal);
	 

    fread(&Registro,sizeof(Registro),1,alias);
  }
  fclose(alias); 
  remove("PRODUCTO.SEC"); 
  rename("TEMPORAL.TMP","PRODUCTO.SEC");
  

  cout << "\n\n\n\rArchivo compactado !!!";
  cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
  getch();
  return;
}

void listado_secuencial()
{
  system("cls");

  cout << "\n\rLISTADO DE REGISTROS DE PRODUCTOS";
  alias=fopen("PRODUCTO.SEC","rb"); 
				     
  if(alias==NULL)
  {
    cout << "\n\n\n\rNo existe el archivo !!!";
    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
    getch();
    return;
  }

  cout << "\n\rNo Prod                    Descripcion  Cantidad        Precio  Garantia"<<endl;
  cout << "\n\r------------------------------------------------------------------------";
  fread(&Registro,sizeof(Registro),1,alias);
     
  while(!feof(alias)) 
  {
    printf("\n\r%3d\t%30s\t%3d\t\t$%4.2f\t%c",Registro.num_producto,Registro.descripcion,Registro.cantidad,Registro.precio,Registro.garantia);
    fread(&Registro,sizeof(Registro),1,alias);
  }
  fclose(alias); 
  cout << "\n\r------------------------------------------------------------------------";
  cout << "\n\rFin del listado !!!"<<endl;
  cout << "\n\r<<< Oprima cualquier tecla para continuar >>>"<<endl;
  getch();
  return;
}


