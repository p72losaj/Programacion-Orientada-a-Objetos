//juego.cc
// Programa principal prueba funcionamiento de la clase Dados 


#include "dados.h"

int main(void)
{
	Dados d; //Valor de tipo dados
	int v1[5], v2[5];
	int opcion, x, opcion2;
	int n1 = 0;
	int n2 = 0;
	int suma1 = 0;
	int suma2 = 0;
	int x1, x2;
	do{
		std:: cout<<"Introduce una opcion.\n ";
		std:: cout<<"0.Exit\n";
		std:: cout<<"1. Lanzar los dados\n";
		std:: cout<<"2. Ver valor de los dados\n";
		std:: cout<<"3. Suma de los dados\n";
		std:: cout<<"4. Asignar un nuevo valor al dado\n";
		std:: cout<<"5. Distancia entre el menor y el mayor valor almacenados en los dados\n";
		std:: cout<<"6. Número de veces que se han lanzado los dados.\n";
		std:: cout<<"7. Media de los lanzamientos de los dados.\n";
		std:: cout<<"8. Ver los últimos 5 valores de los dados\n";
		std:: cin>>opcion;
		switch(opcion){
			case 1:
			d.lanzamiento();
			n1++;
			n2++;
			suma1 = suma1+d.getDado1();
			suma2 = suma2+d.getDado2();
			
			std:: cout<<"\n\n";
			break;
			case 2:
			std:: cout<<"Valor del dado 1: "<<d.getDado1()<<"\n";
			std:: cout<<"Valor del dado 2: "<<d.getDado2()<<"\n\n";
			break;
			case 3:
			std:: cout<<"Valor de la suma de los 2 dados: "<<d.getSuma()<<"\n";
			break;
			case 4:
			std:: cout<<"Introduce una opcion. 1)Dado 1; 2)Dado 2\n";
			std:: cin>>opcion2;
			if(opcion2==1){
			std:: cout<<"Introduce un valor para el dado: ";
			std:: cin>>x;
			d.setDado1(x);
			suma1 = suma1+d.getDado1();
			n1++;
			}
			else{
				std:: cout<<"Introduce un valor para el dado: ";
				std:: cin>>x;
				d.setDado2(x);
				suma2 = suma2+d.getDado2();
				n2++;
			}
			break;
			case 5:
			std:: cout<<"Diferencia entre los dados: "<<d.getDiferencia()<<"\n\n";
			break;
			case 6:
			std:: cout<<"Número de lanzamientos del dado 1: "<<d.getLanzamientos1(n1)<<"\n";
			std:: cout<<"Número de lanzamientos del dado 2: "<<d.getLanzamientos2(n2)<<"\n\n";
			break;
			case 7:
			std:: cout<<"Media del dado 1: "<<d.getMedia1(d.getLanzamientos1(n1),d.getSuma1(suma1))<<"\n";
			std:: cout<<"Media del dado 2: "<<d.getMedia2(d.getLanzamientos2(n2),d.getSuma2(suma2))<<"\n\n";
			break;
			case 8:
			d.getUltimos1(v1);
			std:: cout<<"\n";
			d.getUltimos2(v2);
			std:: cout<<"\n\n";
			break;
		}
	}while(opcion!=0);
return 0;
}