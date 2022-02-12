/*
	Declaracion de funciones de la clase persona
*/

#ifndef PERSONA_H
#define PERSONA_H
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <list>
#include <iostream>

using namespace std;

class Persona
{
	private:
		string DNI_; 
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;
		int edad_;
	public:
		inline string getDNI(){return DNI_;}
		inline void setDNI(string DNI){DNI_ = DNI;}
		inline string getNombre(){return nombre_;}
		inline void setNombre(string nombre){nombre_ = nombre;}	
		inline string getApellidos(){return apellidos_;}
		inline void setApellidos(string apellidos){apellidos_=apellidos;}	
		inline string getDireccion(){return direccion_;}
		inline void setDireccion(string direccion){direccion_=direccion;}
		inline string getLocalidad(){return localidad_;}
		inline void setLocalidad(string localidad){localidad_=localidad;}
		inline string getProvincia(){return provincia_;}
		inline void setProvincia(string provincia){provincia_=provincia;}
		inline string getPais(){return pais_;}
		inline void setPais(string pais){pais_=pais;}
		inline int getEdad(){return edad_;}
		bool setEdad(int edad);
		inline string getApellidosyNombre(){return apellidos_+", "+nombre_;}	
		bool mayor();
		Persona(string DNI, string nombre="",string apellidos="",int edad=0, string direccion="",
			string localidad="",string provincia="",string pais="")
			{
				DNI_ = DNI;
				nombre_ = nombre;
				apellidos_ = apellidos;
				edad_ = edad;
				direccion_=direccion;
				localidad_=localidad;
				provincia_ = provincia;
				pais_ = pais;
			}		
};
#endif