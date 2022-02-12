/*
A partir de uno de los ejemplos de vector anteriores hacer un programa que
pida los elementos de un vector al usuario por teclado, los ordene y los
muestre ordenados en pantalla.
*/

#include <iostream>
#include <cstdlib>
#include <vector> // Necesario para el contenedor del vector
#include <algorithm> // necesario para short() y reverse()

using namespace std;

int main(void){

	int i;
	vector <int> v(4);

	for( i=0; i<v.size(); i++){

		cout<<" Valor: "<<endl;
		cin >> v[i];

	}

	cout<<" Ordenando el vector "<<endl;

	sort(v.begin(),v.end());

	for ( i=0 ; i<v.size() ; i++) cout << v[i] << " ";
	cout << endl;
	return 0;
}