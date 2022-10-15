#include "Controlador.h"
#include <unistd.h>

//Controlador::Controlador() {}//YO JONATHAN COMENTÉ ESTA LINEA
Controlador::~Controlador() {}

bool Controlador::Modo_Seleccion() {
	
	char vector[10];
	fgets(vector, 9, stdin);
	return vector[0] == 's' || vector[0] == 'S';
}

void Controlador::Menu_Principal() {
	char opc;
	do{
		try{
			system("cls");
			system("color 3");
			cout << " ----------------------------"<<"\n";
			cout << "| Bienvenido a Akinator Tico |"<<"\n";
			cout << "-----------------------------"<<"\n";
			cout << "1) Iniciar juego"<<"\n";
			cout << "2) Salir "<<"\n";
			cout << "Digite su eleccion: ";
			cin>>opc;
			
			if( opc != '1' && opc != '2' ){
				throw opc;
			}
			else{
				switch(opc){
				case '1':{
					system("cls");
					Menu_Auxiliar();
					system("pause");
					break;
				}
				}
			}
		}catch(char e){
			cerr<<endl;
			cerr<<"Opcion invalida :( \n";
			cerr<<"Elija una opcion valida.... \n";
			system("pause");
		}
	}while(opc != '2');
}


void Controlador::Menu_Auxiliar() {
	Arbol *archivo = new Arbol("Arbol.txt");
	string nom;
	cont = 0;
	NodoJuego *rq, *pr, *previo;
	bool resp, respPrev;
	char nuevo[256], preg[256];
	
	do
	{
		system("cls");
		system("color 6");				
		cout << " ----------------------------"<<"\n";
		cout << " | Reglas del juego          | \n";
		cout << " ----------------------------"<<"\n";
		cout<< "Para responder las preguntas presiona 's' para si y 'n' para hacer referencia a no \n";
		cout<< "No mientas o pongas datos que no estes 100% seguro que son los correctos \n";
		cout<< "Disfurta! \n";
		Modo_Seleccion();
		
		previo = NULL;
		pr = archivo->Raiz;
		
		do
		{
			rq = pr;
			if(pr->Acertar)
			{
				cout<<pr->palabra << "?" << endl;
			}
			
			else
			{
				system("color 2");
				cout << " -------------------------------------"<<endl;
				cout << "| Tu personaje es: " << pr->palabra <<"     |"<<endl;
				cout << " -------------------------------------"<<endl;
				
			}
			
			resp = Modo_Seleccion();
			
			if(pr->Acertar)
			{
				previo = pr;
				respPrev = resp;
				
				if(resp)
					pr = pr->Acertar;
				else
					pr = pr->Fallar;
			}
			
		}
		while(rq->Acertar);
		
		if(resp){
			cout <<"Yo gane!" << endl;
			
		}
		else
		{
			system("color 4");
			cout << "he perdido! no se quien estas pensando " << endl;
			cout << "Te voy a hacer ciertas preguntas para el futuro" << endl;
			do
			{
				cout << endl;
				cout << "Cual es la persona" << endl;
				cout << "                                 >";
				cin.getline(nuevo,sizeof(nuevo));
				cout << "Que lo diferencia "<< pr->palabra <<" de " << nuevo <<endl;
				cout << "                                 >";
				cin.getline(preg,sizeof(preg));
				cout << "La respuesta es un 's' de Si o una 'n' de No" << endl;
				cout << "                                 "<<preg << "?" << endl;
				resp = Modo_Seleccion();
				
				cout << "Muchas gracias dijite s\n";
			}
			while(!Modo_Seleccion());
			archivo->Crear_Arbol(previo, respPrev,preg, resp, nuevo);
			archivo->refresh();
		}
		cout << "Quieres ir al menu principal? s o n";
	}
	while(!Modo_Seleccion());
	archivo->~Arbol();
}

