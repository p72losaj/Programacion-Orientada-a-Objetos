/*
	Implementa en C++ un ejemplo usando la plantilla de clase de los apuntes de C++
	que se ha visto en clase de teoría y ampliando con algunas funciones miembro más a tu gusto y criterio. 
	La plantilla MiClase que realiza una división de sus datos privados sean int, float, etc.
*/

#include <iostream>

using namespace std;

template <class T> 

class MiClase{ 

	private:

		T x_, y_; 

	public:

		MiClase (T a, T b){ x_=a; y_=b;}; 
		T div(){return x_/y_;}; 

};

int main(void) { 

	MiClase <int> entero(10,3); 
	MiClase <double> real(3.3, 5.5);
	cout << "división entera = " << entero.div() << endl; 
	cout << "división real = " << real.div() << endl; 

	return 0;
}