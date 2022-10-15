#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include "NodoJuego.h"
#include <stdio.h>

using namespace std;


class Arbol {
public:
	Arbol(): Raiz() {}
	Arbol(char *);
	void Moztrar();
	void Crear_Arbol(NodoJuego *, bool, char *, bool, char *);
	NodoJuego *Raiz;
	void refresh();
	~Arbol();	
private:
	NodoJuego *Auto_Leer(FILE *);
	void Auto_guardar(FILE *, NodoJuego*);
	void eliminar(NodoJuego *);
	void Mostrar_Arbol(NodoJuego *);
	NodoJuego *temp;
	char Archivo[256];
	int cont;
	
	
	
	
};
#endif

