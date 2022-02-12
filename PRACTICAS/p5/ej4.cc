/*
Programa que ordena un vector en orden ascendente o descendente segun
la eleccion del usuario
*/

#include <iostream>
#include <cstdlib>
#include <vector> // Necesario para el contenedor del vector
#include <algorithm> // necesario para short() y reverse()

using namespace std;

bool descendente(int i, int j){ return i>j; }
bool ascendente(int i, int j){ return i<j; }
int main(void){

	int i, opcion;
	vector <int> v(4);

	for( i=0; i<v.size(); i++){

		cout<<" Valor: "<<endl;
		cin >> v[i];

	}

	cout<<" Introduce una opcion: 1.ascendente; 2. descendente\n"<<endl;
	cin>> opcion;
	if(opcion == 2){
		cout<<" Ordenando el vector en orden descendente"<<endl;
		sort(v.begin(),v.end(), descendente);
	}
	else{
		cout<<" Ordenando el vector en orden ascendente"<<endl;
		sort(v.begin(), v.end(), ascendente);
	}
	for ( i=0 ; i<v.size() ; i++) cout << v[i] << " "<<endl;
	
	return 0;
}