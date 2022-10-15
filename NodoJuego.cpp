#include "NodoJuego.h"

NodoJuego::NodoJuego(): Acertar(0), Fallar(0), palabra(0) {}
NodoJuego::NodoJuego(char *pal) {
	palabra = new char[strlen(pal)+1];
	strcpy(palabra, pal);
	Acertar = 0;
	Fallar = 0;
}

NodoJuego::~NodoJuego() {if(palabra) delete[] palabra;}

