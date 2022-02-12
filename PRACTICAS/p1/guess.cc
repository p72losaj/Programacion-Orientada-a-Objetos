
//guess.cc
//Programa que adivina un numero entre 1 y 10

#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void)
{
	srand(time(NULL));
	int n = 1+rand()%(11-1);
	int i;
	std:: cout << "Introduce un numero: ";
	std:: cin >>i;
	while(i != n)
	{
		if(i<n)
		{
			std:: cout<<"Valor introducido menor al engendrado\n";
		}
		if(i>n)
		{
			std:: cout <<"Valor introducido mayor al engendrado\n";
		}
	std:: cout << "Introduce un numero: \n";
	std:: cin >>i;
	}
	std:: cout <<"Valor engendrado: " <<n<<"\n";
	return 0;
}