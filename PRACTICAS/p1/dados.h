//Prototipo de las funciones de la clase dados

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>

using namespace std;

class Dados
{
	private:
		int d1_;
		int d2_;
		int l1_;
		int l2_;
		float n1_; 
		float n2_;
		vector <int> v1_;
		vector <int> v2_;
	public:
		Dados();
		inline int getDado1() const { return d1_;} 
		inline int getDado2() const { return d2_;}
		inline int getSuma() const { return d1_+d2_;}
		void lanzamiento();
		bool setDado1(int a);
		bool setDado2(int x);
		int getDiferencia();
		inline float getLanzamientos1() const { return n1_;}
		inline float getLanzamientos2() const { return n2_;}
		void getUltimos1(int v[]);
		void getUltimos2(int v[]);
		float getMedia1();
		float getMedia2();
};