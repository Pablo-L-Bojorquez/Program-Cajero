#include <iostream>
//libreria para cadenas char
#include <string.h>
//se carga la libreria para usar el system "cls"(borra la pantalla) y pause>null(Pausa el programa en la instruccion donde es invocado)
#include <stdlib.h>

char user[6] = "Pablo", nom[6]; 
char pass[5] = "1234", nip[5];
double saldo1 = 1000, saldo2 = 955, saldo3 = 1500, retirar, saldoTtl;
short opcion, resp, resp1, intento = 0;
int main() 
{
	//mientras que intento sea diferente de 3 el programa se ejecuta cuando no sea diferente el programa se cierra.
	while (intento != 3)
	{
	system("cls");
	std::cout<<"ingrese el nombre: \n";
	std::cin>> nom;
	std::cout<<"ingrese su NIP: \n";
	std::cin>>nip;
	//se comparan la cadena char 1 con la cadena char2.
	if(strcmp(nom, user)==0 && strcmp(nip, pass)==0)
	{
	do
	{
	system("cls");
		//si la comparacion de las cadenas 1 y 2 es correcta se accede al menu de opciones.
		std::cout<<"Bienvenido/a \n";
		std::cout<<"Seleccione una Opcion: \n";
		std::cout<<"1 - Cambio de nip. \n";
		std::cout<<"2 - Consulta de saldo. \n";
		std::cout<<"3 - Retiro. \n";
		std::cout<<"4 - Deposito. \n";
		std::cout<<"5 - Transferencia. \n";
		std::cout<<"6.- Cerrar Sesion. \n";
		std::cin>> opcion;
		//cambio de nip, el usuario ingresa un nuevo nip que sustituye al actual.
		if (opcion == 1){
			system("cls");
			std::cout<<"Cambio de Nip. \n";
			std::cout<<"Ingrese su nuevo NIP: \n";
			std::cin>> pass;
			std::cout<<"Su Nuevo Nip es: " << pass <<'\n';
			}
		//consulta de saldo, muestra al usuario su saldo actual.
		if (opcion == 2){
			system("cls");
			std::cout<<"Consulta de Saldo. \n";
			std::cout<<"Su saldo es Actual es: " << saldo1 <<'\n';
			}
		//retiro de dinero de la cuenta propia del usuario.
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
		//se deposita dinero externo a la cuenta del usuario o a otra cuenta.
		if (opcion == 4){
			system("cls");
			std::cout<<"Deposito. \n";
			std::cout<<"Seleccione la Cuenta. \n";
			std::cout<<"1.- saldo1 \n";
			std::cout<<"2.- saldo2 \n";
			std::cout<<"3.- saldo3 \n";
			int cuenta;
			std::cin>> cuenta;
			//switch case para determinar al usuario al que se desea depositar.
			switch (cuenta){
				case 1:{
					std::cout<<"Ingrese el Dinero a Depositar. \n";
					int depositar = 0;
					std::cin>> depositar;
					saldo1 = saldo1 + depositar;
					std::cout<<"Usted a Depositado: $"<< depositar <<" A saldo1";
					break;
				}
				case 2:{
					std::cout<<"Ingrese el Dinero a Depositar. \n";
					int depositar = 0;
					std::cin>> depositar;
					saldo2 = saldo2 + depositar;
					std::cout<<"Usted a Depositado: $"<< depositar <<" A saldo2";
					break;
				}
				case 3:{
					std::cout<<"Ingrese el Dinero a Depositar. \n";
					int depositar = 0;
					std::cin>> depositar;
					saldo3 = saldo3 + depositar;
					std::cout<<"Usted a Depositado: $"<< depositar <<" A saldo3";
					break;
				}
			}
		}
		//transferencia de cuenta a cuenta, el dinero transferido se retira de la cuenta del 
		//usuario en sesion y se envia a los otros usuarios pre-cargados.
		if (opcion == 5){
			std::cout<<"Tranferencia. \n";
			std::cout<<"Seleccione la Cuenta. \n";
			std::cout<<"1.- saldo2 \n";
			std::cout<<"2.- saldo3 \n";
			int cuenta;
			std::cin>> cuenta;
			switch (cuenta){
				case 1:{
					std::cout<<"Ingrese el Dinero a Transferir. \n";
					int transferir = 0;
					std::cin>> transferir;
					if (transferir > saldo1) std::cout<<"No hay dinero suficiente en la cuenta. \n";
					else{
					saldo1 = saldo1 - transferir;
					saldo2 = transferir;
					std::cout<<"Usted a Transferido: $"<< transferir << " A saldo2 \n";
					std::cout<<"Su Saldo Total es: $"<< saldo1 <<'\n';
					}
					break;
				}
				case 2:{
					std::cout<<"Ingrese el Dinero a Depositar. \n";
					int transferir = 0;
					std::cin>> transferir;
					if (transferir > saldo1) std::cout<<"No hay dinero suficiente en la cuenta.";
					else{
					saldo1 = saldo1 - transferir;
					saldo3 = transferir;
					std::cout<<"Usted a Transferido: $"<< transferir << " A saldo3 \n";
					std::cout<<"Su Saldo Total es: $"<< saldo1 <<'\n';
					}
					break;
				}
			}
		}
		//detiene las instrucciones del programa para poder visualizar las acciones que se desen realizar.
		system("pause>null");		
	}
	//mientras que opcion sea diferente de 6 sigue trabajando sobre la cuenta, cuando no sea diferente de 6 cierra la sesion.
	while (opcion != 6);

	}
	else{
	system("cls");
	//incremente en 1 la variable intento.
	intento ++;
	//se indica al usuario la cantidad de intentos restantes.
	if (intento == 3) std::cout<<"Ha Excedido el Numero de Intentos. "<< intento<< "/3";
		else{
			std::cout<<"Usuario Incorrecto Intentelo de Nuevo. Intento "<<intento <<"/3";
			system("pause>null");
			}	
		}
	}
	return 0;
}
