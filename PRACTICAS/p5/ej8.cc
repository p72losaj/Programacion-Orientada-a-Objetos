#include "dados.h"

// Funcion insertador

ostream& operator<<(ostream &os, Dados& d) {
   os << "Valor dado 1: "<< d.getDado1() << endl;
   os << "Valor dado 2: "<< d.getDado2() << endl;
   return os;
}

// Funcion extractor

istream& operator>>(istream &is, Dados& d)
{

	int valor;
	do{
		cout<<" Valor dado 1: ";
		is >> valor;
		if( d.setDado1( valor) == false) cout << "Valor no correcto" << endl;
	} while( d.setDado1(valor) == false);

	do{
		cout<<" Valor dado 2: ";
		is >> valor;
		if( d.setDado2(valor) == false) cout << "Valor no correcto" << endl;
		else cout << "Valor correcto" << endl;
	} while( d.setDado2(valor) == false);
	return is;
}

int main(void)
{
	Dados d;
	cout << "Realizando funcion del extractor" << endl;
	cin >> d;
	cout << "Realizando funcion del insertador" << endl;
	cout << d << endl;
	return 0;
}