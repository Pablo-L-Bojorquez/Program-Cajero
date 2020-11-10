#include <iostream>
#include<string.h>
#include<stdlib.h>

char user[6] = "Pablo", nom[6]; 
char pass[5] = "1234", nip[5];
short opcion;
int main() 
{
	
	std::cout<<"ingrese el nombre: \n";
	std::cin>> nom;
	std::cout<<"ingrese su NIP: \n";
	std::cin>>nip;

	if(strcmp(nom, user)==0 && strcmp(nip, pass)==0)
	{
	std::cout<<"Bienvenido/a \n";
	std::cout<<	"Seleccione una Opcion: \n";
	std::cout<<"1 - Cambio de nip. \n";
	std::cout<<"2 - Consulta de saldo. \n";
	std::cout<<"3 - Retiro. \n";
	std::cout<<"4 - Deposito. \n";
	std::cout<<"5 - Transferencia. \n";
	std::cin>> opcion;
	
	if (opcion == 1){
	system("cls");
	std::cout<<"Ingrese su nuevo NIP: \n";
	std::cin>> pass;
	std::cout<<"Su Nuevo Nip es: " << pass <<'\n';
	}
	
	
	}
	else std::cout<<"Usuario Incorrecto Intentelo de Nuevo";
	
	return 0;
}
