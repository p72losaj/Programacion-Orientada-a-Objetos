#include <fstream>
#include <list>
#include "jugador.h"
#include "ruleta.h"

using namespace std;

int main(){

  Crupier c("33XX","crupier1");
  Ruleta r(c);

  list <Jugador> jugadores_;
  Jugador j1("44XX", "jugador1");
  Jugador j2("55XX", "jugador2");
  
  int opcion, nj, sj, db, lb, dm;
  // Numero de jugadores
  nj = 0;
  // Dinero mesa
  dm = 0; 
  // Suma dinero jugadores
  sj = 0;
  // Dinero banca
  db = 0;
  // Lanzaminetos de la bola
  lb = 0;
  string dni;

  do{

    cout<<"MENU\n"<<endl;
    cout<<"1. Cargar los jugadores del fichero jugadores.txt en la lista\n"<<endl;
    cout<<"2. Guardar los ficheros de los jugadores en jugadores.txt\n"<<endl;
    cout<<"3. Estado_ruleta, dinero_banca y dinero_jugadores.\n"<<endl;
    cout<<"4. Número_ruleta, premios_jugador y gana/pierde_banca\n"<<endl;
    cout<<"5. Eliminar un jugador de la mesa\n"<<endl;
    cout<<"6. Añadir un jugador a la mesa\n"<<endl;
    cout<<"7. Salir del programa\n"<<endl;

    cout<<"Introduce una opcion: "<<endl;
    cin>>opcion;
    
    switch(opcion){

      case 1:
        
        r.leeJugadores();
        nj = r.getJugadores().size();
        db = r.getBanca();
        
  
      break;

      case 2:

        r.escribeJugadores();        

      break;


      case 3:

          if(nj==0){
            cout<<" Lista vacia\n";
          }

          if(nj == 2){
            cout<<" Dinero jugador  "<<r.getJugadores().begin()->getDNI()<<" = "<<r.getJugadores().begin()->getDinero()<<endl;      
            cout<<" Dinero jugador  "<<(++r.getJugadores().begin() )->getDNI()<<" = "<<(++r.getJugadores().begin() )->getDinero()<<endl; 
            sj = r.getJugadores().begin()->getDinero() + (++r.getJugadores().begin())->getDinero();
          }

          else{
            cout<<" Dinero jugador "<<r.getJugadores().begin()->getDNI()<<" = "<<r.getJugadores().begin()->getDinero()<<endl;
            sj = r.getJugadores().begin()->getDinero();
          }


          cout<<" Dinero jugadores: "<<sj<<endl;

          dm = db+sj;

          r.getEstadoRuleta(&nj,&dm,&lb, &db);

      break;

      case 4:

      if(nj == 0){
        cout<<" Lista vacia\n";
      }

      else{

        r.giraRuleta();
        cout<<" Valor de la bola: "<<r.getBola()<<endl;
        lb++;
        r.getPremios();
        if(nj==1){
          cout<<" Jugador: "<<r.getJugadores().begin()->getDNI()<<endl;
          cout<<" Dinero jugador: "<<r.getJugadores().begin()->getDinero()<<endl;
        }
        else{
          cout<<" Jugador: "<<r.getJugadores().begin()->getDNI()<<endl;
          cout<<" Dinero jugador: "<<r.getJugadores().begin()->getDinero()<<endl;
          cout<<" DNI: "<<(++r.getJugadores().begin() )->getDNI()<<endl;
          cout<<" Dinero jugador: "<<(++r.getJugadores().begin())->getDinero()<<endl;
        }
      cout<<" Dinero banca: "<<r.getBanca()<<endl;
      }


      break;

      case 5:
        
        cout<<"Dni del jugador a eliminar: "<<endl;
        cin>>dni;
        r.deleteJugador(dni);
        nj = r.getJugadores().size();
        dm = sj+r.getBanca();
  
      break;

      case 6:
      
        r.addJugador(j1);
        r.addJugador(j2);
        dm = sj+r.getBanca();

      break;
      
    }

  } while(opcion!=7);
  
  return 0;

}


