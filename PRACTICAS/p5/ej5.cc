/*
	Programa que ordene un vector de Jugadores por el DNI y los mueste en pantalla ordenados. 
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){

	vector <string> v(4);
	string cad;
	int i;
	//Creando el vector de jugadores
	while(i<4){
		cout<<" DNI del jugador"<<endl;
		cin>> v[i];
		i++;
	}
	// Ordenamos el vector de DNI
	sort(v.begin(), v.end());
	// Imprimimos el vector
	for(i=0; i<v.size(); i++) cout<< v[i] <<endl;
return 0;
}