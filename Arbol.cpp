#include "Arbol.h"

Arbol::Arbol(char *name) {
	
	FILE *file;
	
	strcpy(Archivo, name);
	
	file = fopen(Archivo, "r");
	
	if(!file)
		Raiz = new NodoJuego("");
	else
	{
		Raiz = Auto_Leer(file);
		fclose(file);
	}
}



NodoJuego *Arbol::Auto_Leer(FILE *file) {
	
	char oracion[258];
	NodoJuego *N;
	
	fgets(oracion, 257, file);
	
	while(oracion[strlen(oracion) - 1] < ' ' && oracion[strlen(oracion) - 1] > 0)
		oracion[strlen(oracion) - 1] = 0;
	
	N = new NodoJuego(&oracion[1]);
	
	if(oracion[0] == '-')
	{
		N->Acertar = Auto_Leer(file);
		N->Fallar = Auto_Leer(file);
	}
	return N;
}

void Arbol::Auto_guardar(FILE *file, NodoJuego *N) {
	
	if(N->Acertar)
	{
		
		fprintf(file, "-%s\n", N->palabra);
		Auto_guardar(file, N->Acertar);
		Auto_guardar(file, N->Fallar);
	}
	else
	   
	   fprintf(file, ".%s\n", N->palabra);
}


void Arbol::eliminar(NodoJuego *n) {
	
	if(n->Acertar) eliminar(n->Acertar);
	if(n->Fallar) eliminar(n->Fallar);
	delete n;
}

void Arbol::Moztrar() {
	
	cont = 0;
	Mostrar_Arbol(Raiz);
}

void Arbol::Mostrar_Arbol(NodoJuego *N) {
	
	int i;
	
	for(i = 0; i < cont; i++) putchar(' ');
	cont += 3;
	cout << ">" << N->palabra << endl;
	if(N->Acertar)
	{
		cout << "S ";
		Mostrar_Arbol(N->Acertar);
	}
	if(N->Fallar)
	{
		printf("N ");
		Mostrar_Arbol(N->Fallar);
	}
	cont -= 3;
}

void Arbol::Crear_Arbol(NodoJuego *previo, bool respPrev,char *preg, bool resp, char *nuevo) {
	
	NodoJuego *pr, *rq;
	
	if(respPrev)
		pr = previo->Acertar;
	else
		pr = previo->Fallar;
	
	rq = new NodoJuego(preg);
	
	if(respPrev)
		previo->Acertar = rq;
	else
		previo->Fallar = rq;
	
	if(resp)
		rq->Fallar = pr;
	else
		rq->Acertar = pr;
	
	pr = new NodoJuego(nuevo);
	
	if(resp)
		rq->Acertar = pr;
	else
		rq->Fallar = pr;
}
void Arbol::refresh(){
	
	FILE *file;
	
	file = fopen(Archivo, "w");
	
	Auto_guardar(file, Raiz);
	fclose(file);
}
Arbol::~Arbol() {
	
	FILE *file;
	
	file = fopen(Archivo, "w");
	
	Auto_guardar(file, Raiz);
	fclose(file);
	
	eliminar(Raiz);
}
