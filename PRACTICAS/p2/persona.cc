#include "persona.h"

bool Persona::setEdad(int edad){
	edad_ = edad;
	if(edad_ >=0)
	{
		return true;
	}
	return false;
}

bool Persona::mayor(){
	if(edad_ > 17)
	{
		return true;
	}
	return false;
}
