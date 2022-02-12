#ifndef CONTADOR_H
#define CONTADOR_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Contador{

private:

    int Min_;
    int Max_;
    int Num_;
    int it_;
    list <int> Nit_;

public:

  inline  void SetMin(int Min){Min_=Min;};
  inline  int GetMin(){return Min_;};

  inline void SetMax(int Max){Max_=Max;};
  inline int GetMax(){return Max_;};

  inline void SetNum(int Num){Num_=Num;};
  inline int get(){return Num_;};

  inline int getIt(){return it_;};

  Contador(int Num=0, int Min=0, int Max=1000);

  Contador operator =(Contador c);

  Contador operator =(const int &Num);

  Contador operator ++(void);

  Contador operator ++(int);

  Contador operator --(void);

  Contador operator --(int);

  Contador operator +(int a);

  friend Contador operator +(int a, Contador c);

  Contador operator -(int a);

  friend Contador operator -(int a, Contador c);

  bool undo(int n=1);

};

#endif
