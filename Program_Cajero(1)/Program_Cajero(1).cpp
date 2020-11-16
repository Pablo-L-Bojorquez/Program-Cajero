#include <iostream>
#include<string.h>
#include<stdlib.h>

char user[6] = "Pablo", nom[6]; 
char pass[5] = "1234", nip[5];
double saldo1 = 1000, slado2 = 955, saldo3 = 1500, retirar, saldoTtl;
short opcion, resp, resp1, intento = 3;
int main() 
{
	while (intento != 0){
	system("cls");	
	std::cout<<"ingrese el nombre: \n";
	std::cin>> nom;
	std::cout<<"ingrese su NIP: \n";
	std::cin>>nip;
	if(strcmp(nom, user)==0 && strcmp(nip, pass)==0)
	{
	do
	{
	system("cls");


		std::cout<<"Bienvenido/a \n";
		std::cout<<"Seleccione una Opcion: \n";
		std::cout<<"1 - Cambio de nip. \n";
		std::cout<<"2 - Consulta de saldo. \n";
		std::cout<<"3 - Retiro. \n";
		std::cout<<"4 - Deposito. \n";
		std::cout<<"5 - Transferencia. \n";
		std::cout<<"6.- Cerrar Sesion. \n";
		std::cin>> opcion;
	
		if (opcion == 1){
			system("cls");
			std::cout<<"Cambio de Nip. \n";
			std::cout<<"Ingrese su nuevo NIP: \n";
			std::cin>> pass;
			std::cout<<"Su Nuevo Nip es: " << pass <<'\n';
			}
		//
	
		if (opcion == 2){
			system("cls");
			std::cout<<"Consulta de Saldo. \n";
			std::cout<<"Su saldo es Actual es: " << saldo1 <<'\n';
			}
	
		if (opcion == 3){
			system("cls");
			std::cout<<"Retiro. \n";
			std::cout<<"Ingrese el Saldo a Retirar. ";
			std::cin>> retirar;
			
			if (retirar > saldo1){
				std::cout<<"No hay dinero suficiente para retirar \n";
				}
			else{
				saldoTtl = saldo1 - retirar;
				saldo1 = saldoTtl;
				std::cout<<"Usted ah Retirado: $"<< retirar << '\n';
				std::cout<<"Su saldo total es: $"<< saldoTtl<<'\n';
				} 
			}
		if (opcion == 4){
			system("cls");
			std::cout<<"Deposito. ";
			
		}
		if (opcion == 6){
			break;
		}
		system("pause>null");		
	}
	while (opcion != 6);
	

}
	else{	
	std::cout<<"Usuario Incorrecto Intentelo de Nuevo \n";
	intento --;
	}
}
	return 0;
}
