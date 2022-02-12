/*
	Prototipos funciones clase ruleta
*/
#ifndef RULETA_H
#define RULETA_H
#include "persona.h"
#include "crupier.h"
#include "jugador.h"

class Ruleta
{
	private:
		int banca_; 
		int bola_; 
		list <Jugador> jugadores_; 
    	Crupier crupier_; 

	public:	
		Ruleta(Crupier c): crupier_(c)
		{
			bola_ = -1;
			banca_ = 1000000;
		};
		inline int getBanca(){return banca_;}
		inline int getBola(){ return bola_;}
		void setBanca(int valor);
		void setBola(int bola);
		inline Crupier getCrupier(){ return crupier_;}
		inline void setCrupier(Crupier cr){crupier_ = cr;}
		inline list <Jugador> getJugadores(){ return jugadores_;}
		bool addJugador(Jugador jugador);
		int deleteJugador(string DNI);
		inline int deleteJugador(Jugador jugador){return deleteJugador( jugador.getDNI() );}
		void escribeJugadores();
		void leeJugadores();
		void giraRuleta();
		void getPremios();
		void tratarApuestas(Jugador &j,Apuesta a);
};
 
#endif