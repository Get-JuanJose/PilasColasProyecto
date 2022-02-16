#include "Cola.h"
#include "pila.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

cola::cola(int tam)
{
    limite = tam - 1;
    tope = -1;
    Vcola= new int[tam];
}

void cola::encolar(int d)
{
    tope++;
    Vcola[tope] = d;
}

int cola::desencolar()
{
    int r = Vcola[0], i = 1;
    while (i <= tope)
    {
        Vcola[i - 1] = Vcola[i];
        i++;
    }
    tope--;
    return r;
}

void cola::encularOrdenado(int d, cola* c)
{
    cola* aux = new cola(limite);
    int r = 0;
    if (ColaVacia())
        encolar(d);
    else
    {
        r = Vcola[0];
        if (d <= r)
        {
            aux->encolar(d);
            while (!ColaVacia())
                aux->encolar(desencolar());
            llenarCola(aux);
        }
        else
        {
            while (d > r && !ColaVacia())
            {
                aux->encolar(desencolar());
                r = Vcola[0];
            }
            aux->encolar(d);
            aux->llenarCola(c);
            llenarCola(aux);
        }
    }
    
}

void cola::ordenarCola()
{
    int r;
    cola* aux1 = new cola(limite);
    cola* aux2 = new cola(limite);

    if (tope > 0)
    {
        r = desencolar();
        while (!ColaVacia()) //encuentra al menor.
        {
            if (r < Vcola[0])
                aux1->encolar(desencolar());
            else
            {
                aux1->encolar(r);
                r = desencolar();
            }
        }
        encolar(r); //el menor se apila.
        r = aux1->desencolar();
        aux1->invertirCola();
        while (!aux1->ColaVacia())
        {
            if (r < aux1->Vcola[0])
            {
                aux2->encolar(r);
                r = aux1->desencolar();
            }
            else
            {
                aux2->encolar(aux1->desencolar());
            }
        }
        aux1->encolar(r);
        llenarCola(aux2);
        llenarCola(aux1);
        cout << "La Cola se ha ordenado correctamente." << endl;
    }
    else
    {
        cout << "La Cola solo tiene un dato" << endl;
    }
};

bool cola::ColaLlena()
{
    if (tope == limite)
        return true;
    else
        return false;
}

bool cola::ColaVacia()
{
    if (tope == -1)
        return true;
    else
        return false;
}

void cola::llenarCola(cola *a)
{
    while (a->ColaVacia() == false)
        encolar(a->desencolar());
}

void cola::sumarPilaCola(pila_lista* p1, cola* c1)
{
    cola* c2;
    int r = 0, s = 0, t = 0;
    if (p1->getLimite() > c1->getLimite())
    {
        c2 = new cola(p1->getLimite());
        while (!p1->pilaVacia())
        {
            if (!c1->ColaVacia() && !p1->pilaVacia())
            {
                r = c1->desencolar();
                s = p1->desapilar();
                t = r + s;
                c2->encolar(t);
            }
            else
            {
                s = p1->desapilar();
                c2->encolar(s);
            }
        }
    }
    else
    {
        c2 = new cola(c1->getLimite());
        while (!c1->ColaVacia())
        {
            if (!c1->ColaVacia() && !p1->pilaVacia())
            {
                r = c1->desencolar();
                s = p1->desapilar();
                t = r + s;
                c2->encolar(t);
            }
            else
            {
                r = c1->desencolar();
                c2->encolar(r);
            }
        }
    }
    c2->MostrarCola();
}

void cola::intercalado(cola* c1, cola* c2)
{
    pila_lista* p = new pila_lista(c1->getLimite());

    if(!p->pilaLlena())
    {
        while (!c1->ColaVacia() || !c2->ColaVacia())
        {
            if (!c1->ColaVacia() && !c2->ColaVacia())
            {
                p->apilar(c1->desencolar());
                p->apilar(c2->desencolar());
            }
            else
            {
                if (c1->ColaVacia())
                    p->apilar(c2->desencolar());
                else
                {
                    if (c2->ColaVacia())
                    {
                        p->apilar(c1->desencolar());
                    }
                }
            }
        }
        if (!p->pilaVacia())
        {
            p->mostrarPila();
        }
        else
        {
            cout << "No hay datos en la pila resultante." << endl;
            cin.get();
        }
    }
    else
    {
        cout << "La pila esta llena." << endl;
        cin.get();
    }
}

void cola::invertirCola()
{
    cola* aux1 = new cola(limite);
    cola* aux2 = new cola(limite);
    int r = 0;

    while (!ColaVacia())
    {
        r = desencolar();
        aux1->encolar(r);
    }
    aux2->llenarCola(aux1);
    llenarCola(aux2);
}
void cola::MostrarCola()
{
    int r = 0;
    cola* Ca = new cola(limite + 1);
    while (!ColaVacia())
    {
        r = desencolar();
        cout<<" | " << r <<" |";
        Ca->encolar(r);
    }
    llenarCola(Ca);
}
int cola::getLimite()
{
    return limite;
};