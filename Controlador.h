#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include <iostream>
#include "Arbol.h"
#include "NodoJuego.h"
#include "windows.h"

class Controlador {
public:
//	Controlador()// YO JONATHAN COMENTÉ ESTA LINEA
	bool Modo_Seleccion();
	void Menu_Principal();
	void Menu_Auxiliar();
	virtual ~Controlador();
	int cont;
	
};

#endif

