#include "Nodo.h"
#include"pila.h"
#include"Cola.h"

Nodo::Nodo()
{
    dato = 0;
    liga = nullptr;
}

int Nodo::getDato()
{
    return dato;
}

void Nodo::setDato(int d)
{
    dato = d;
}

Nodo* Nodo::getliga()
{
    return liga;
}

void Nodo::setLiga(Nodo* l)
{
    liga = l;
}
