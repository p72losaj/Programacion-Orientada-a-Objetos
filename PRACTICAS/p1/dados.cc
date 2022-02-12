//dados.cc
//Cuerpo de los métodos de la clase Dados
#include "dados.h"
Dados::Dados(){
	srand(time(NULL)); 
	d1_=1; 
	d2_=1; 
	n1_=0.0; 
	n2_ = 0.0; 
	l1_ = 0; 
	l2_ = 0; 
	v1_.resize(5,0); 
	v2_.resize(5,0);
}

void Dados::lanzamiento(){
	d1_=(rand()%6)+1;
	n1_++;
	l1_ = l1_ + d1_;
	d2_ = (rand()%6)+1;
	l2_ = l2_ + d2_;
	n2_++;
}

bool Dados::setDado1(int a){
	if( (a>0) && (a<7) ){
		d1_ = a;
		for(int i=4; i>0; i--){
			v1_[i] = v1_[i-1];
		}
		v1_[0] = d1_;
		n1_++;
		l1_ = l1_ + a;
		return true;
	}
	else{
		return false;
	}
}

bool Dados::setDado2(int a){
	if( (a>0) && (a<7) ){
		d2_ = a;
		for(int i=4; i>0; i--){
			v2_[i] = v2_[i-1];
		}
		v2_[0] = d2_;
		n2_++;
		l2_= l2_+a;
		return true;
	}
	else{
		return false;
	}
}

int Dados::getDiferencia(){
	if(d1_ > d2_){
		return d1_-d2_;
	}
	else{
		return d2_-d1_;
	}
}

void Dados::getUltimos1(int v[]){
	for(int i=0; i<5; i++){
		v[i] = v1_[i];
	}
}

void Dados::getUltimos2(int v[]){
	for(int i=0; i<5; i++){
		v[i] = v2_[i];
	}
}

float Dados::getMedia1(){
	if(n1_ == 0){
		return 0;
	}
	return (l1_ / float (n1_) );
}

float Dados::getMedia2(){ 
	if(n2_ == 0){
		return 0;
	}
	return l2_ / float(n2_);
}