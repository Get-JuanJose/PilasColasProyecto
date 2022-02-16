#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <wchar.h>
#include"pila.h"
#include"Cola.h"
//PIlas apiladas.

using namespace std;
void menuPilas();
void menuColas();
void menuPrincipal();
void colas();
int main()
{
	system("color A");
	int opt = 0, optP=0, optC=0, dato = 0, n = 0, m = 0, cantColas;
	setlocale(LC_ALL, "");
	cout << "Bienvenidos a la Apiladora Encolada." << endl<< endl<<endl;
	cout << "Ingrese el tamaño de la pila" << endl;
	cin >> n;
	cout << "Ingrese el tamaño de la cola" << endl;
	cin >> m;
	cin.get();
	//Instancia.

	pila_lista* p= new pila_lista(n);
	cola* c = new cola(m);
	cola* c1 =new cola(m);
	cola* c2=new cola(m);
	
	do
	{
		menuPrincipal();
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Usted ha escogido trabajar sobre pilas";
			cin.get();
			do
			{
				menuPilas();
				cin >> optP;
				switch (optP)
				{
				case 1:// Apilar.
					if (!p->pilaLlena())
					{
						cout << "Ingrese un dato: " << endl;
						cin >> dato;
						p->apilar(dato);
					}
					else
					{
						cout << "La pila esta llena." << endl;
						cin.get();
					}
					break;
				case 2://Desapilar.			
					if (!p->pilaVacia())
					{
						cout << "Se desapilo el ultimo dato: " << p->desapilar() << endl;
				
					}
					else
					{
						cout << "La pila esta vacia." << endl;
					}
					cin.get();
					break;
				case 3://Ordenar Pila.
					if (!p->pilaVacia())
					{
						p->ordenarPila();
						
						cin.get();
					}
					else
					{
						cout << "No hay ningun dato" << endl;
						cin.get();
					}
					break;
				case 4://Mostrar pila.
					if (!p->pilaVacia())
					{
						p->mostrarPila();
						cin.get();
					}
					else
					{
						cout << "No hay ningun dato" << endl;
						cin.get();
					}
					break;
				case 5://Apilar Ordenado
					if (!p->pilaLlena())
					{
						cout << "Ingrese el dato: " << endl;
						cin >> dato;
						p->apilarOrdenado(dato);
					}
					else
					{
						cout << "La pila esta llena." << endl;
						cin.get();
					}
					break;
				case 6://Salir
					cout << "Gracias por utilizar nuestro programa." << endl;
					break;
				default:
					cout << "Ha ingresado un dato incorrecto." << endl;
					cin.get();
					break;
				}
				cin.get();
				system("cls");
			} while (optP != 6);
			break;
		case 2:
			cout << "Usted ha escogido trabajar sobre colas"<<endl;
			cin.get();
			colas();
			cout << "Sobre que cola desea trabajar" << endl;
			cin >> cantColas;
			switch (cantColas)
			{
			case 1:
				c = c1;
				do
				{
					menuColas();
					cin >> optC;
					switch (optC)
					{
					case 1://Encolar.					
						if (!c->ColaLlena())
						{
							cout << "Ingrese un dato: " << endl;
							cin >> dato;
							c->encolar(dato);
							cout << "El dato se ha encolado correctamente." << endl;
							cin.get();
						}
						else
						{
							cout << "La cola esta llena." << endl;
							cin.get();
						}
						break;
					case 2://Desencolar.
						if (!c->ColaVacia())
						{
							cout << "El dato: " << c->desencolar() << " se ha desencolado correctamente." << endl;
							cin.get();
						}
						else
						{
							cout << "La cola esta vacia." << endl;
							cin.get();
						}
						break;
					case 3://Ordenar Cola
						if (!c->ColaVacia())
						{
							c->ordenarCola();
							cin.get();
						}
						else
						{
							cout << "No hay datos en la cola." << endl;
						}
						break;
					case 4://Mostrar cola.
						if (!c->ColaVacia())
						{
							c->MostrarCola();
							cin.get();
						}
						else
						{
							cout << "No hay ningun dato" << endl;
							cin.get();
						}
						break;
					case 5://Encolar ordenado.
						if (!c->ColaLlena())
						{
							cout << "Ingrese el dato: " << endl;
							cin >> dato;
							c->encularOrdenado(dato, c);

						}
						else
						{
							cout << "La cola esta llena." << endl;
							cin.get();
						}
						break;
					case 6:
						cout << "Gracias por utilizar nuestro programa." << endl;
						cin.get();
						break;
					default:
						cout << "Ha ingresado un dato incorrecto." << endl;
						cin.get();
						break;
					}
					cin.get();
					system("cls");
					c1 = c;
				} while (optC != 6);
				break;
			case 2:
				c = c2;
				do
				{
					menuColas();
					cin >> optC;
					switch (optC)
					{
					case 1://Encolar.					
						if (!c->ColaLlena())
						{
							cout << "Ingrese un dato: " << endl;
							cin >> dato;
							c->encolar(dato);
							cout << "El dato se ha encolado correctamente." << endl;
							cin.get();
						}
						else
						{
							cout << "La cola esta llena." << endl;
							cin.get();
						}
						break;
					case 2://Desencolar.
						if (!c->ColaVacia())
						{
							cout << "El dato: " << c->desencolar() << " se ha desencolado correctamente." << endl;
							cin.get();
						}
						else
						{
							cout << "La cola esta vacia." << endl;
							cin.get();
						}
						break;
					case 3://Ordenar Cola
						if (!c->ColaVacia())
						{
							c->ordenarCola();
							cin.get();
						}
						else
						{
							cout << "No hay datos en la cola." << endl;
						}
						break;
					case 4://Mostrar cola.
						if (!c->ColaVacia())
						{
							c->MostrarCola();
							cin.get();
						}
						else
						{
							cout << "No hay ningun dato" << endl;
							cin.get();
						}
						break;
					case 5://Encolar ordenado.
						if (!c->ColaLlena())
						{
							cout << "Ingrese el dato: " << endl;
							cin >> dato;
							c->encularOrdenado(dato, c);

						}
						else
						{
							cout << "La cola esta llena." << endl;
							cin.get();
						}
						break;
					case 6:
						cout << "Gracias por utilizar nuestro programa." << endl;
						cin.get();
						break;
					default:
						cout << "Ha ingresado un dato incorrecto." << endl;
						cin.get();
						break;
					}
					cin.get();
					system("cls");
					c2 = c;
				} while (optC != 6);
				break;
			default:
				cout << "Ha ingresado un dato incorrecto. " << endl;
				cin.get();
				break;
			}
			break;
		case 3://Sumar pila con cola.
			c->sumarPilaCola(p, c);
			cout << "La Suma ha sido realizada Correctamente." << endl;			
			break;
		case 4://Intercalar
			if (!c1->ColaVacia() || !c2->ColaVacia())
			{
				c->intercalado(c1, c2);
			}
			else
			{
				cout << "No hay datos para intercalar." << endl;
			}
			break;
		case 5://salir
			cout << "Gracias por utilizar nuestro programa." << endl;
			exit(1);
			break;
		default:
			cout << "Opcion incorrecta." << endl;
			cin.get();
			break;
		}
	} while (opt != 5);
}

void menuPilas()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu trabajo\n\n";
	cout << "1. Apilar. " << endl;
	cout << "2. Desapilar. " << endl;
	cout << "3. Ordenar Pila" << endl;
	cout << "4. Mostrar pila. " << endl;
	cout << "5. Apilar Ordenado" << endl;
	cout << "6. salir" << endl;

	cout << "\tIngresar opcion.\n";
}
void menuColas()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu trabajo\n\n";
	cout << "1. Encolar " << endl;
	cout << "2. Desencolar. " << endl;
	cout << "3. Ordenar Cola" << endl;
	cout << "4. Mostrar Cola." << endl;
	cout << "5. Encolar Ordenado" << endl;
	cout << "6. salir" << endl;

	cout << "\tIngresar opcion.\n";
}

void menuPrincipal()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu Principal.\n\n";
	cout << "1. Trabajar Pilas. " << endl;
	cout << "2. Trabajar Colas" << endl;
	cout << "3. Sumar Pilas y colas." << endl;
	cout << "4. Intercalar." << endl;
	cout << "5. Salir." << endl;
	cout << "\n \t\t\t\t\t\t\t By : Brian Torres (GOD) juan jose GODzalez\n\n";
}
void colas()
{
	cout << "1. cola 1. " << endl;
	cout << "2. Cola 2" << endl;
}