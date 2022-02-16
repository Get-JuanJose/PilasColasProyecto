#pragma once
class Nodo
{
	//Atributos.
private:
	int dato;
	Nodo* liga;
	//Metodos
public:
	Nodo();
	int getDato();
	void setDato(int);
	Nodo* getliga();
	void setLiga(Nodo*);
};

