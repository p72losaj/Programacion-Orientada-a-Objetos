/*
	Ejemplo usando la plantilla de función de los apuntes de C++ que se ha visto en clase de teoría. 
	La función debe recibir un vector y su tamaño, y escribir su contenido en pantalla sea el vector
	de int, float o char. 
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> 
void print_vector(T *v, const int n) 
{ 
	for(int i=0;i<n;i++) cout << v[i] << " , ";
}

int main(void) 
{ 
	int a[5]={1,3,5,7,9}; 
	float b[4]={5.6, 7.8, 3.9, 1.2}; 
	char c[5]="hola";
	cout << "vector de enteros"<<endl;
	print_vector(a,5); 
	cout << "\nvector de floats"<<endl; 
	print_vector(b,4); 
	cout << "\nvector de char"<<endl; 
	print_vector(c,4);
	cout<<" "<<endl;
	return 0;
}