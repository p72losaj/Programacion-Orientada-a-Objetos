/*
	Prototipo funciones clase jugador
	Hereda la clase Persona
*/

#ifndef JUGADOR_H
#define JUGADOR_H
#include "persona.h"

typedef struct Apuesta
{
	int tipo;
	string valor;
	int cantidad;
} Apuesta;

class Jugador: public Persona
{
	private: 
		int dinero_;
		string codigo_;
		list <Apuesta> apuestas_;
	public:
		Jugador(string DNI, string codigo, string nombre="",string apellidos="",int edad=0, string direccion="",
			string localidad="",string provincia="",string pais=""):
			Persona(DNI,nombre,apellidos,edad,direccion,localidad,provincia,pais)
			{
				dinero_ = 1000;
				codigo_ = codigo;
			};
		inline string getCodigo(){ return codigo_;};
		inline void setCodigo(string codigo){ codigo_=codigo;};
		inline int getDinero(){ return dinero_;}
		inline void setDinero(int dinero){dinero_ = dinero;}
		inline list <Apuesta> getApuestas(){return apuestas_;}
		void setApuestas();
};
#endif