#include <iostream>
//libreria para cadenas char
#include <string.h>
//se carga la libreria para usar el system "cls"(borra la pantalla) y pause>null(Pausa el programa en la instruccion donde es invocado)
#include <stdlib.h>

char user[6] = "Pablo", user2[7] = "Carlos", user3[6] = "Kenia", nom[7]; 
char pass[5] = "1234", pass2[5] = "1235", pass3[5] = "1236", nip[5];
char numCuenta[11] = "1234567890", numCuenta2[11] = "1234567891", numCuenta3[11] = "1234567892", userCuenta[11];
double saldo1 = 1000, saldo2 = 955, saldo3 = 1500, retirar, saldoTtl;
short opcion, intento = 0;
int main()
{
	//mientras que intento sea diferente de 3 el programa se ejecuta cuando no sea diferente el programa se cierra.
	while (intento != 3)
	{
	system("cls");
	std::cout<<"Ingrese la Informacion Siguiente. . . \n";
	std::cout<<"Nombre: ";
	std::cin>> nom;
	std::cout<<"Ingrese su NIP: ";
	std::cin>>nip;
	std::cout<<"Ingrese su Num. de Cuenta: ";
	std::cin>> userCuenta;
	//se comparan la cadena char 1 con la cadena char2.
	if(strcmp(nom, user)==0 && strcmp(nip, pass)==0 && strcmp(userCuenta, numCuenta)==0)
	{
	do
	{
	intento = 0;
	system("cls");
		//si la comparacion de las cadenas 1 y 2 es correcta se accede al menu de opciones.
		std::cout<<"Bienvenido/a al Cajero: " << nom << '\n';
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
			std::cout<<"Ingrese su NIP: ";
			char confirmNip[5];
			std::cin>>confirmNip;
			if (strcmp(confirmNip, pass)==0){
			
			std::cout<<"Ingrese la Cuenta. \n";
			char cuenta[11];
			std::cin>> cuenta;
			std::cout<<"Ingrese el Dinero a Depositar. \n";
			double depositar = 0;
			std::cin>> depositar;
			//if anidados para determinar al usuario al que se desea depositar.
			if (strcmp(cuenta, numCuenta)==0){
				saldo1 += depositar;
				std::cout<<"Usted a Depositado: $"<< depositar <<" a la Cuenta #.1234567890";
			}
			else if(strcmp(cuenta, numCuenta2)==0){
				saldo2 += depositar;
				std::cout<<"Usted a Depositado: $"<< depositar <<" a la Cuenta #.1234567891";
			}
			else if(strcmp(cuenta, numCuenta3)==0){
				saldo3 += depositar;
				std::cout<<"Usted a Depositado: $"<< depositar <<" a la Cuenta #.1234567892";
			}
			else std::cout<<"El Num. Cuenta ingresado es invalido..";
			}
			else std::cout<<"El NIP ingresado es Incorrecto. . Pruebe intentando de nuevo.";
		}
		//transferencia de cuenta a cuenta, el dinero transferido se retira de la cuenta del 
		//usuario en sesion y se envia a los otros usuarios pre-cargados.
		if (opcion == 5){
			system("cls");
			std::cout<<"Tranferencia. \n";
			std::cout<<"Ingrese su NIP: ";
			char confirmNip[5];
			std::cin>>confirmNip;
			if (strcmp(confirmNip, pass)==0){
			
			std::cout<<"Ingrese la Cuenta a Transferir. \n";
			char cuenta[11];
			std::cin>> cuenta;
			std::cout<<"Ingrese el Monto a Transferir. \n";
			double transferir = 0;
			std::cin>> transferir;
			
			if (strcmp(cuenta, numCuenta2)==0){
				if (transferir > saldo1) std::cout<<"No hay dinero suficiente en la cuenta. \n";
				else{
					saldo1 = saldo1 - transferir;
					saldo2 = transferir;
					std::cout<<"Usted a Transferido: $"<< transferir << " a la Cuenta #.1234567891 \n";
					std::cout<<"Su Saldo Total es: $"<< saldo1 <<'\n';
				}
			}
			else if (strcmp(cuenta, numCuenta3)==0){
				if (transferir > saldo1) std::cout<<"No hay dinero suficiente en la cuenta.";
				else{
					saldo1 = saldo1 - transferir;
					saldo3 = transferir;
					std::cout<<"Usted a Transferido: $"<< transferir << " a la Cuenta #.1234567892 \n";
					std::cout<<"Su Saldo Total es: $"<< saldo1 <<'\n';
				}
			}
		}
	}
		//detiene las instrucciones del programa para poder visualizar las acciones que se desen realizar.
		system("pause>null");		
	}
	//mientras que opcion sea diferente de 6 sigue trabajando sobre la cuenta, cuando no sea diferente de 6 cierra la sesion.
	while (opcion != 6);
	}
	//segundo usuario..
	else if(strcmp(nom, user2)==0 && strcmp(nip, pass2)==0 && strcmp(userCuenta, numCuenta2)==0){
	do
	{
	intento = 0;
	system("cls");
		//si la comparacion de las cadenas 1 y 2 es correcta se accede al menu de opciones.
		std::cout<<"Bienvenido/a al Cajero: " << nom << '\n';
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
			std::cout<<"Cambio de NIP. \n";
			std::cout<<"Confirme su NIP Actual: ";
			char confirmNip[5];
			std::cin>>confirmNip;
			if (strcmp(confirmNip, pass2)==0){
			std::cout<<"Ingrese su nuevo NIP: \n";
			std::cin>> pass2;
			std::cout<<"Su Nuevo Nip es: " << pass2 <<'\n';
			}
			else std::cout<<"El NIP ingresado es Incorrecto. . Pruebe intentando de nuevo.";
		}
		//consulta de saldo, muestra al usuario su saldo actual.
		if (opcion == 2){
			system("cls");
			std::cout<<"Consulta de Saldo. \n";
			std::cout<<"Su saldo es Actual es: " << saldo2 <<'\n';
			}
		//retiro de dinero de la cuenta propia del usuario.
		if (opcion == 3){
			system("cls");
			std::cout<<"Retiro. \n";
			std::cout<<"Ingrese su NIP: ";
			char confirmNip[5];
			std::cin>>confirmNip;
			if (strcmp(confirmNip, pass2)==0){
			std::cout<<"Ingrese el Saldo a Retirar. ";
			std::cin>> retirar;
			
			if (retirar > saldo2) std::cout<<"No hay dinero suficiente para retirar \n";
			else{
				saldoTtl = saldo2 - retirar;
				saldo2 = saldoTtl;
				std::cout<<"Usted ah Retirado: $"<< retirar << '\n';
				std::cout<<"Su saldo total es: $"<< saldoTtl<<'\n';
				} 
			}
		}
		//se deposita dinero externo a la cuenta del usuario o a otra cuenta.
		if (opcion == 4){
			system("cls");
			std::cout<<"Deposito. \n";
			std::cout<<"Ingrese su NIP: ";
			char confirmNip[5];
			std::cin>>confirmNip;
			if (strcmp(confirmNip, pass2)==0){
			
			std::cout<<"Ingrese la Cuenta. \n";
			char cuenta[11];
			std::cin>> cuenta;
			std::cout<<"Ingrese el Dinero a Depositar. \n";
			double depositar = 0;
			std::cin>> depositar;
			//if anidados para determinar al usuario al que se desea depositar.
			if (strcmp(cuenta, numCuenta)==0){
				saldo1 += depositar;
				std::cout<<"Usted a Depositado: $"<< depositar <<" a la Cuenta #.1234567890";
			}
			else if(strcmp(cuenta, numCuenta2)==0){
				saldo2 += depositar;
				std::cout<<"Usted a Depositado: $"<< depositar <<" a la Cuenta #.1234567891";
			}
			else if(strcmp(cuenta, numCuenta3)==0){
				saldo3 += depositar;
				std::cout<<"Usted a Depositado: $"<< depositar <<" a la Cuenta #.1234567892";
			}
			else std::cout<<"El Num. Cuenta ingresado es invalido..";
			}
			else std::cout<<"El NIP ingresado es Incorrecto. . Pruebe intentando de nuevo.";
		}
		//transferencia de cuenta a cuenta, el dinero transferido se retira de la cuenta del 
		//usuario en sesion y se envia a los otros usuarios pre-cargados.
		if (opcion == 5){
			system("cls");
			std::cout<<"Tranferencia. \n";
			std::cout<<"Ingrese su NIP: ";
			char confirmNip[5];
			std::cin>>confirmNip;
			if (strcmp(confirmNip, pass2)==0){
			
			std::cout<<"Ingrese la Cuenta a Transferir. \n";
			char cuenta[11];
			std::cin>> cuenta;
			std::cout<<"Ingrese el Monto a Transferir. \n";
			double transferir = 0;
			std::cin>> transferir;
			
			if (strcmp(cuenta, numCuenta)==0){
				if (transferir > saldo2) std::cout<<"No hay dinero suficiente en la cuenta. \n";
				else{
					saldo2 = saldo2 - transferir;
					saldo1 = transferir;
					std::cout<<"Usted a Transferido: $"<< transferir << " a la Cuenta #.1234567890 \n";
					std::cout<<"Su Saldo Total es: $"<< saldo2 <<'\n';
				}
			}
			else if (strcmp(cuenta, numCuenta3)==0){
				if (transferir > saldo2) std::cout<<"No hay dinero suficiente en la cuenta.";
				else{
					saldo2 = saldo2 - transferir;
					saldo3 = transferir;
					std::cout<<"Usted a Transferido: $"<< transferir << " a la Cuenta #.1234567892 \n";
					std::cout<<"Su Saldo Total es: $"<< saldo2 <<'\n';
				}
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
