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
  
  ifstream entrada (NOMBRE_ARCHIVO);
  string linea;
  char delimitador = ';';
  int cont_peleador = 0;
  int cont_obj = 0;
  int cont_arena = 0;
  while(getline(entrada, linea)) {
    stringstream stream(linea);
    string type, t,  name, tipo, salud, fuerza, vel, intel, resist, leyenda;
    getline(stream, type, delimitador);
    type.erase(0,1);
    cout<<type<<endl;
    

    
    
    if (type == "Peleador" || type == "peleador") {
      cont_peleador++;
      cout<<"es un peleador\n";
      getline(stream, name, delimitador);
      getline(stream, salud, delimitador);
      int sal = stoi(salud);
      cout<<salud<<endl;
      getline(stream, fuerza, delimitador);
      int fuer = stoi(fuerza);
      getline(stream, vel, delimitador);
      int velo = stoi(vel);
      getline(stream, intel, delimitador);
      int inte = stoi(intel);
      getline(stream, resist, delimitador);
      int res = stoi(resist);
      getline(stream, leyenda, delimitador);

      switch(cont_peleador) {
        case 0:
          peleador peleador1(name, sal, fuer, velo, inte, res, leyenda);
          break;

        case 1:
          peleador peleador2(name, sal, fuer, velo, inte, res, leyenda);
          break;
      }
      
      
    }
  }
  

  



  
  return 0;
  
}