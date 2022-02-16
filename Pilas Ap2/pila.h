#pragma once
#include "Nodo.h"
#include "Cola.h"
class pila_lista	
{
private:
	//Atributos.
	Nodo* punta;
	int limite, tope;

	//Metodos.
public:
	pila_lista(int);//Constructor.
	void apilar(int);//Set.
	int desapilar(); //Get.
	void apilarOrdenado(int);
	void ordenarPila();

	bool pilaVacia();
	bool pilaLlena();
	void llenarPila(pila_lista*);//Pasar datos, de pila llena a pila vacia.
	void invertirPila();
	void mostrarPila();
	int getLimite();

	void insertarInicio(int);
};

