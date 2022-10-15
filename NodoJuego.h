#ifndef NODOJUEGO_H
#define NODOJUEGO_H
#include <string.h>

class NodoJuego
{
public:
public:
	NodoJuego();
	NodoJuego(char *);
	char *palabra;
	NodoJuego *Acertar;
	NodoJuego *Fallar;
	~NodoJuego();
};

#endif

