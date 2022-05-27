#include <iostream>
#include <fstream>
#include <sstream>
#include "peleador.h"
#include "objeto.h"
#include "arena.h"

#define NOMBRE_ARCHIVO "data tarea 3.csv"
using namespace std;

int main(int argc, char ** argv) {
  //para leer el archivo
  peleador *peleador1;
  peleador *peleador2;
  objeto *objeto1;
  objeto *objeto2;
  arena *arenaj;
  
  
  
  ifstream entrada (NOMBRE_ARCHIVO);
  string linea;
  char delimitador = ';';
  int cont_peleador = 0;
  int cont_obj = 0;
  int cont_arena = 0;
  
  while(getline(entrada, linea)) {
    stringstream stream(linea);
    string type,  name, tipo, salud, fuerza, vel, intel, resist, leyenda;
    getline(stream, type, delimitador);
    type.erase(0,1);

  //si es peleador
    if (type == "Peleador" || type == "peleador") {
      cont_peleador++;
      
      getline(stream, name, delimitador);
      getline(stream, salud, delimitador);
      int sal = stoi(salud);
      getline(stream, fuerza, delimitador);
      int fuer = stoi(fuerza);
      getline(stream, vel, delimitador);
      int velo = stoi(vel);
      getline(stream, intel, delimitador);
      int inte = stoi(intel);
      getline(stream, resist, delimitador);
      int res = stoi(resist);
      getline(stream, leyenda, delimitador);
      int len_ley = leyenda.length();
      leyenda.erase(0, 2);
      leyenda.erase((len_ley - 6), 6);


      if (cont_peleador == 1) {
        peleador1 = new peleador(name, sal, fuer, velo, inte, res, leyenda);
        
      }
      if (cont_peleador == 2) {
        peleador2 = new peleador(name, sal, fuer, velo, inte, res, leyenda);
      }
        
      
       
    }
    //para los objetos
    else if (type == "objeto" || type == "Objeto") {
      cont_obj++;
      getline(stream, name, delimitador);
      getline(stream, tipo, delimitador);
      getline(stream, salud, delimitador);
      getline(stream, fuerza, delimitador);
      getline(stream, vel, delimitador);
      getline(stream, intel, delimitador);
      getline(stream, resist, delimitador);
      getline(stream, leyenda, delimitador);
      int len_ley = leyenda.length();
      leyenda.erase(0, 2);
      leyenda.erase((len_ley - 6), 6);

      

      if (cont_obj == 1) {
        objeto1 = new objeto(name, tipo, salud, fuerza, vel, intel, resist, leyenda);
      }
      if (cont_obj == 2) {
        objeto2 = new objeto(name, tipo, salud, fuerza, vel, intel, resist, leyenda);
      }
      

    }

    //para la arena
    else if (type == "Arena" || type == "arena") {
      cont_arena++;
      getline(stream, name, delimitador);
      getline(stream, salud, delimitador);
      getline(stream, fuerza, delimitador);
      getline(stream, vel, delimitador);
      getline(stream, intel, delimitador);
      getline(stream, resist, delimitador);
      getline(stream, leyenda, delimitador);
      int len_ley = leyenda.length();
      leyenda.erase(0, 2);
      leyenda.erase((len_ley - 6), 6);


      arenaj = new arena(name, salud, fuerza, vel, intel, resist, leyenda);

      if (cont_arena != 1) {
        cout<<"Ya existe una arena para esta batalla"<<endl;
      }
    }
  }
  peleador1->show_peleador();
  peleador2->show_peleador();




  
  return 0;
  
}