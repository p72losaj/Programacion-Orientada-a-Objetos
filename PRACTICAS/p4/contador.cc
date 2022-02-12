//contador.cc
//definicion de metodos de la clase contador
#include "contador.h"


using namespace std;

Contador:: Contador(int Num, int Min, int Max){

	it_=0;

	if(Num>Max || Num<Min){

 		SetMax(1000);
  		SetMin(0);
  		SetNum(0);
  		it_++;
  		Nit_.push_back(Num_);
	}

	else if(Max<=Min){

  		SetMax(1000);
  		SetMin(0);
  		SetNum(0);
  		it_++;
		Nit_.push_back(Num_);
	}

	else{

  		SetMax(Max);
  		SetMin(Min);
  		SetNum(Num);
  		it_++;
		Nit_.push_back(Num_);
	}

}

Contador Contador::operator =(Contador c){

	SetNum( c.get() );
	SetMin( c.GetMin() );
	SetMax( c.GetMax() );
	it_++;
	Nit_.push_back(Num_);
	
	return *this;
}

Contador Contador::operator =(const int &Num){

	if( Num < Min_ ){
	
		SetNum( Min_ );
		it_++;
		Nit_.push_back(Num_);

	}
	
	else if ( Num > GetMax() ){
		
		SetNum( Max_ );
		it_++;
		Nit_.push_back(Num_);

	}
	
	else{
	
		SetNum( Num );
		it_++;
		Nit_.push_back( Num_ );
	}

	return *this;
}

Contador Contador::operator ++(void){//++ prefijo

	if(Num_ < Max_){

		Num_++;
		it_++;

	}

	return *this;
}

Contador Contador::operator ++(int){//++ sufijo

	Contador temp=*this;

	if(Num_ < Max_){

		Num_++;
		it_++;
	}

	Nit_.push_back(Num_);

	return temp;
}

Contador Contador::operator --(void){//-- prefijo
	
	if(Num_ > Min_){

		Num_--;
		it_++;

	}

	return *this;
}

Contador Contador::operator --(int){//-- sufijo

	Contador temp=*this;
	if(Num_ > Min_){

		Num_--;
		it_++;
	}

	Nit_.push_back(Num_);

	return temp;
}

Contador Contador::operator +(int a){//c+a

	if( (Num_ + a) < Max_ ){
	
		Num_ = Num_ + a;
	}

	else{

		Num_ = Max_;
	}

	it_++;

	Nit_.push_back(Num_);

	return *this;
}



Contador operator +(int a,Contador c){//a+c

	Contador aux(c);
	
	if( (aux.get() + a) < aux.GetMax()){

		aux.SetNum(aux.get() + a);

	}
	
	else{

		aux.SetNum( aux.GetMax() );
	}
	
	aux.it_++;

	aux.Nit_.push_back(aux.Num_);

	return aux;
}

Contador Contador::operator -(int a){//c-a

	if( (Num_ - a) > Min_){

		Num_ = Num_ - a;
	}
	
	else{

		Num_ = Min_;

	}

	it_++;

	Nit_.push_back(Num_);
	
	return *this;

}

Contador operator -(int a,Contador c){//a-c

	Contador aux(c);
	
	if( (a - aux.get() ) > aux.GetMin() ){

		aux.SetNum(a - aux.get() );

	}
	
	else{

		aux.SetNum( aux.GetMin() );

	}
	
	aux.it_++;

	aux.Nit_.push_back(aux.Num_);

	return aux;

}

bool Contador::undo(int n){

	int i;

	if( n> ( it_ - 1 ) || n<1 ) return false;
	
	else{

		for( i=0; i<it_ -1; i++ ){
		
			Nit_.pop_back(); 

			Num_ = Nit_.back();

		}
		
		return true;

	}


}

