#pragma once
#include "Nodo.h"
#include "pila.h"
class pila_lista;
class cola
{
private:
    //atributos
    int tope, limite, *Vcola;

public:
    //metodos
    cola(int);
    void encolar(int); //set
    int desencolar(); //get
    void encularOrdenado(int, cola*);
    void ordenarCola();
    bool ColaLlena();
    bool ColaVacia();
    void llenarCola(cola*);
    void sumarPilaCola(pila_lista*,cola*);
    void intercalado(cola*, cola*);


    void invertirCola();
    void MostrarCola();

    int getLimite();
};
