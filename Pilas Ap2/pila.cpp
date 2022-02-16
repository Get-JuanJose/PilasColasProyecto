#include "pila.h"
#include<iostream>
#include"Nodo.h"
#include"Cola.h"
using namespace std;

pila_lista::pila_lista(int tam)
{
	limite = tam;
	tope = 0;
	punta = nullptr;
};

void pila_lista::apilar(int d)//Similar al Set.
{
	tope++;
	insertarInicio(d);
}


void pila_lista::apilarOrdenado(int d)//malo
{
	int r;
	pila_lista* aux = new pila_lista(limite);

	if (pilaVacia())
		apilar(d);
	else
	{
		
		if (d <= punta->getDato())
		{
			while (!pilaVacia() && d <= punta->getDato())
			{
				r = desapilar();
				aux->apilar(r);
			}
			apilar(d);
			llenarPila(aux);
		}
		else
		{
			apilar(d);
		}
	}
}

void pila_lista::ordenarPila()
{
	int r;
	pila_lista* aux1 = new pila_lista(limite);
	pila_lista* aux2 = new pila_lista(limite);
	if (tope > 1)
	{
		r = desapilar();
		while (!pilaVacia()) //encuentra al menor.
		{
			if (r < punta->getDato())
				aux1->apilar(desapilar());
			else
			{
				aux1->apilar(r);
				r = desapilar();
			}
		}
		apilar(r); //el menor se apila.
		r = aux1->desapilar();
		while (!aux1->pilaVacia())
		{
			if (r < aux1->punta->getDato())
			{
				aux2->apilar(r);
				r = aux1->desapilar();
			}
			else
				aux2->apilar(aux1->desapilar());
		}
		aux1->apilar(r);
		aux1->llenarPila(aux2);
		llenarPila(aux1);
		cout << "La pila se ha ordenado correctamente." << endl;
	}
	else
	{
		cout << "La pila solo tiene un dato" << endl;
	}
}

int pila_lista::desapilar()//Similar al Get.
{
	Nodo* p = punta;
	int r = p->getDato();
	punta = punta->getliga();
	tope--;
	delete(p);
	return r;
}

bool pila_lista::pilaVacia()//Validacion vacia.
{
	bool r= false;
	if (tope == 0)
	{
		r = true;
	}
	return r;
}

bool pila_lista::pilaLlena()//Validacion llena(true = llena).
{
	if (tope == limite) 
		return true;
	else
		return false;
}

void pila_lista::llenarPila(pila_lista* a)
{
	while (a->pilaVacia() == false)
	{
		apilar(a->desapilar());
	}
}

void pila_lista::insertarInicio(int d)
{
	Nodo* x = new Nodo();

	x->setDato(d);

	if (punta == nullptr)
	{
		punta = x;
	}
	else
	{
		x->setLiga(punta);
		punta = x;
	}
}

void pila_lista::invertirPila()
{
	pila_lista* aux1 = new pila_lista(limite);
	pila_lista* aux2 = new pila_lista(limite);
	int r= 0;

	while (!pilaVacia())
	{
		r = desapilar();
		aux1->apilar(r);
	}
	aux2->llenarPila(aux1);
	llenarPila(aux2);
}

void pila_lista::mostrarPila()
{
	pila_lista * aux= new pila_lista(limite);
	int r = 0;
	while (pilaVacia() == false)
	{
		r = desapilar(); //Se vacia la pila principal.
		cout << "|"<< r<< "|"<< endl;
		aux->apilar(r);
	}
	llenarPila(aux); //Se llena la pila auxiliar.
}

int pila_lista::getLimite()
{
	return limite;
}