#include "ruleta.h"
#include <cstring>

void Ruleta::setBanca(int valor)
{
	if(valor >= 0)
	{
		banca_ = valor;
	}
}

void Ruleta::setBola(int bola)
{
	if(bola>=0 && bola<=36)
	{
		bola_ = bola;
	}
}

bool Ruleta::addJugador(Jugador jugador)
{
	list<Jugador>:: iterator i;
	for(i=jugadores_.begin();i!=jugadores_.end();i++)
	{
		if(i->getDNI()==jugador.getDNI()){
			return false;
		}
	}
	jugadores_.push_back(jugador);
	string nomfich=(jugador.getDNI() + ".txt");
	ifstream fich(nomfich.c_str());
		if(!fich){
			ofstream fich(nomfich.c_str());
		}
	fich.close();
	return true;
}

int Ruleta::deleteJugador(string DNI)
{
	list<Jugador>:: iterator i;
	if(jugadores_.empty()==true)
	{
		return -1;
	}
	for(i=jugadores_.begin();i!=jugadores_.end();i++)
	{
		if(i->getDNI()== DNI)
		{
			jugadores_.erase(i);
			return 1;
		}
	}
return -2;
}

void Ruleta::escribeJugadores()
{
	list<Jugador>:: iterator i;
	string nomfich("jugadores.txt");
	ofstream fich(nomfich.c_str());
	if(fich.is_open())
	{
		for(i=jugadores_.begin();i!=jugadores_.end();i++){
			fich<<i->getDNI()+",";
			fich<<i->getCodigo()+",";
			fich<<i->getNombre()+",";
			fich<<i->getApellidos()+",";
			fich<<i->getEdad()+",";
			fich<<i->getDireccion()+",";
			fich<<i->getLocalidad()+",";
			fich<<i->getProvincia()+",";
			fich<<i->getPais()+",";
			fich<<i->getDinero()<<endl;
		}
	fich.close();
	}		
}

void Ruleta::leeJugadores()
{
	ifstream fichero;
	fichero.open("jugadores.txt");
	string cadaux;
	Jugador aux("dni","cod");
	jugadores_.clear();
	while(getline(fichero,cadaux,',') && !fichero.eof()){
		aux.setDNI(cadaux);
		getline(fichero, cadaux, ',');
		aux.setCodigo(cadaux);
		getline(fichero, cadaux, ',');
		aux.setNombre(cadaux);
		getline(fichero, cadaux, ',');
		aux.setApellidos(cadaux);
		getline(fichero, cadaux, ',');
		aux.setEdad( atoi( cadaux.c_str() ) );
		getline(fichero, cadaux, ',');
		aux.setDireccion(cadaux);
		getline(fichero, cadaux, ',');
		aux.setLocalidad(cadaux);
		getline(fichero, cadaux, ',');
		aux.setProvincia(cadaux);
		getline(fichero, cadaux, ',');
		aux.setPais(cadaux);
		getline(fichero, cadaux, '\n');
		aux.setDinero(atoi(cadaux.c_str()));
		jugadores_.push_back(aux);
	}
	fichero.close();	
}

void Ruleta::giraRuleta()
{
	int auxbola;
	auxbola=rand()%37;
	setBola(auxbola);
}

void Ruleta::getPremios(){
	list <Apuesta>::iterator iap;
	list <Jugador>::iterator ijug;
	list <Apuesta> aux;
	for(ijug=jugadores_.begin(); ijug!=jugadores_.end(); ijug++){
		ijug->setApuestas();
		aux=ijug->getApuestas();
		for(iap=aux.begin(); iap!=aux.end();iap++){			
			tratarApuestas(*ijug,*iap);	
		}
	}
}

void Ruleta::tratarApuestas(Jugador &j,Apuesta a){
	int opcion=a.tipo;
	switch (opcion){
		case 1:
			if(atoi(a.valor.c_str() )==getBola() ){
				j.setDinero( (j.getDinero()+ (35*a.cantidad) ) );
				setBanca((getBanca()-35*a.cantidad));
			}	
			else{ 		
				j.setDinero((j.getDinero()-a.cantidad));
				setBanca((getBanca()+a.cantidad));
			}
		break;

		case 2:	
			if(getBola()==0){ 
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
			}
			else
			{ 
				if( (a.valor=="negro" && ( (getBola()%2 + ( (getBola()/10)%2) )%2)==1 )
				||(a.valor=="rojo"  && ( (getBola()%2 + ( (getBola()/10)%2) )%2)==0) )
				{
					j.setDinero(j.getDinero()+a.cantidad);
					setBanca(getBanca()-a.cantidad);
				}
				else
				{ 
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
				}	
			}
		break;

		case 3:	
			if(getBola()==0)
			{
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
			}
			else if( (a.valor=="par" && getBola()%2==0) 
					 || (a.valor =="impar" && getBola()%2==1) )
			{
					j.setDinero(j.getDinero()+a.cantidad);
					setBanca(getBanca()-a.cantidad);	
			}
			else{
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
			}
		break;

		case 4: 
			if(getBola()==0)
			{
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
			}
			else if( (a.valor=="bajo" && (getBola()>=1 && getBola()<=18) ) 
					  || ( (a.valor=="alto" && (getBola()>=19 && getBola()<=36) ) ) )
			{
				j.setDinero(j.getDinero()+a.cantidad);
				setBanca(getBanca()-a.cantidad);
			}
			else
			{
				j.setDinero(j.getDinero()-a.cantidad);
				setBanca(getBanca()+a.cantidad);
			}
		break;
		default: cout<< "Error en la apuesta";
		exit(-1);
	}
}
