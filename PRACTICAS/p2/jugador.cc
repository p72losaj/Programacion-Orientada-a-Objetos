#include "jugador.h"

void Jugador::setApuestas(){
	char tipo[10], valor[10], cantidad[10];
	Apuesta a;
	apuestas_.clear();
	string nf = getDNI() + ".txt";
	ifstream fichero(nf.c_str());
	if(fichero.is_open()){
		while(fichero.getline(tipo,256,',')){
			fichero.getline(valor,256,',');
			fichero.getline(cantidad,256,'\n');
			a.tipo = atoi(tipo);
			a.valor = valor;
			a.cantidad = atoi(cantidad);
			apuestas_.push_back(a);
		}
		fichero.close();
	}
	else{
		exit(-1);
	}
}