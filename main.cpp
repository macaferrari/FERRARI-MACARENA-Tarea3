#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
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
  objeto *objeto3;
  objeto *objeto4;
  arena *arenaj;
  
  vector <string> peleadores;
  vector <string> objetos;
  
  
  
  ifstream entrada (NOMBRE_ARCHIVO);
  ofstream salida;
  
  string linea;
  char delimitador = ';';
  int cont_peleador = 0;
  int cont_obj = 0;
  int cont_arena = 0;
  int o_p_p = 0;
  string p;
  //este codigo lo saque 
  while(getline(entrada, linea)) {
    stringstream stream(linea);
    string type,  name, tipo, salud, fuerza, vel, intel, resist, leyenda;
    getline(stream, type, delimitador);
    type.erase(0,1);

  //si es peleador
    if (type == "Peleador" || type == "peleador") {
      cont_peleador++;
      
      getline(stream, name, delimitador);
      p = name;
      peleadores.push_back(p);
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
      string o = name;
      objetos.push_back(o);
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
        objeto1 = new objeto(p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
      }
      if (cont_obj == 2) {
        objeto2 = new objeto(p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
      }
      if (cont_obj == 3) {
        objeto3 = new objeto (p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
      }
      if (cont_obj == 4) {
        objeto4 = new objeto(p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
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
  
//Agregar o restar a los atributos de los peleadores
  //primero al peleador1

  string pel = peleador1->name;
  if (pel == objeto1->pel) {
    int cambio = stoi(objeto1->salud) + peleador1->salud;
    peleador1->salud = cambio;
    cambio = stoi(objeto1->fuerza) + peleador1->fuerza;
    peleador1->fuerza = cambio;
    cambio = stoi(objeto1->intel) + peleador1->intel;
    peleador1->intel = cambio;
    cambio = stoi(objeto1->vel) + peleador1->vel;
    peleador1->vel = cambio;
    cambio = stoi(objeto1->resist) + peleador1->resist;
    peleador1->resist = cambio;
  }
  
  if (pel == objeto2->pel) {
    int cambio = stoi(objeto2->salud) + peleador1->salud;
    if (cambio < 0) {cambio = 0;}
    peleador1->salud = cambio;
    cambio = stoi(objeto2->fuerza) + peleador1->fuerza;
    if (cambio < 0) {cambio = 0;}
    peleador1->fuerza = cambio;
    cambio = stoi(objeto2->intel) + peleador1->intel;
    if (cambio < 0) {cambio = 0;}
    peleador1->intel = cambio;
    cambio = stoi(objeto2->vel) + peleador1->vel;
    if (cambio < 0) {cambio = 0;}
    peleador1->vel = cambio;
    cambio = stoi(objeto2->resist) + peleador1->resist;
    if (cambio < 0) {cambio = 0;}
    peleador1->resist = cambio;
  }

  //peleador2

  pel = peleador2->name;
  if (cont_obj > 1) {
    if (pel == objeto2->pel) {
    int cambio = stoi(objeto2->salud) + peleador2->salud;
    if (cambio < 0) {cambio = 0;}
    peleador2->salud = cambio;
    cambio = stoi(objeto2->fuerza) + peleador2->fuerza;
    if (cambio < 0) {cambio = 0;}
    peleador2->fuerza = cambio;
    cambio = stoi(objeto2->intel) + peleador2->intel;
    if (cambio < 0) {cambio = 0;}
    peleador2->intel = cambio;
    cambio = stoi(objeto2->vel) + peleador2->vel;
    if (cambio < 0) {cambio = 0;}
    peleador2->vel = cambio;
    cambio = stoi(objeto2->resist) + peleador2->resist;
    if (cambio < 0) {cambio = 0;}
    peleador2->resist = cambio;
  }
  }
  if (cont_obj > 2) {
    if (pel == objeto3->pel) {
    int cambio = stoi(objeto3->salud) + peleador2->salud;
    if (cambio < 0) {cambio = 0;}
    peleador2->salud = cambio;
    cambio = stoi(objeto3->fuerza) + peleador2->fuerza;
    if (cambio < 0) {cambio = 0;}
    peleador2->fuerza = cambio;
    cambio = stoi(objeto3->intel) + peleador2->intel;
    if (cambio < 0) {cambio = 0;}
    peleador2->intel = cambio;
    cambio = stoi(objeto3->vel) + peleador2->vel;
    if (cambio < 0) {cambio = 0;}
    peleador2->vel = cambio;
    cambio = stoi(objeto3->resist) + peleador2->resist;
    if (cambio < 0) {cambio = 0;}
    peleador2->resist = cambio;
  }
  }
  
  
  if (cont_obj > 3) {
    if (pel == objeto4->pel) {
    int cambio = stoi(objeto4->salud) + peleador2->salud;
    if (cambio < 0) {cambio = 0;}
    peleador2->salud = cambio;
    cambio = stoi(objeto4->fuerza) + peleador2->fuerza;
    if (cambio < 0) {cambio = 0;}
    peleador2->fuerza = cambio;
    cambio = stoi(objeto4->intel) + peleador2->intel;
    if (cambio < 0) {cambio = 0;}
    peleador2->intel = cambio;
    cambio = stoi(objeto4->vel) + peleador2->vel;
    if (cambio < 0) {cambio = 0;}
    peleador2->vel = cambio;
    cambio = stoi(objeto4->resist) + peleador2->resist;
    if (cambio < 0) {cambio = 0;}
    peleador2->resist = cambio;
  }
  }
  


  //suma arena
  //salud
  string por = arenaj->salud;
  por.erase(2,1);
  
  float pc = stoi(por);
  double per = pc/100;
  int final = peleador1->salud + (peleador1->salud)*per;
  peleador1->salud = final;
  final = peleador2->salud + (peleador2->salud)*per;
  peleador2->salud = final;
  //fuerza
  por = arenaj->fuerza;
  por.erase(2,1);
  pc = stoi(por);
  per = pc/100;
  final = peleador1->fuerza + (peleador1->fuerza)*per;
  peleador1->fuerza = final;
  final = peleador2->fuerza + (peleador2->fuerza)*per;
  peleador2->fuerza = final;
  //vel
  por = arenaj->vel;
  por.erase(2,1);
  pc = stoi(por);
  per = pc/100;
  final = peleador1->vel + (peleador1->vel)*per;
  peleador1->vel = final;
  final = peleador2->vel + (peleador2->vel)*per;
  peleador2->vel = final;
  //intel
  por = arenaj->intel;
  por.erase(2,1);
  pc = stoi(por);
  per = pc/100;
  final = peleador1->intel + (peleador1->intel)*per;
  peleador1->intel = final;
  final = peleador2->intel + (peleador2->intel)*per;
  peleador2->intel = final;
  //resist
  por = arenaj->resist;
  por.erase(2,1);
  pc = stoi(por);
  per = pc/100;
  final = peleador1->resist + (peleador1->resist)*per;
  peleador1->resist = final;
  final = peleador2->resist + (peleador2->resist)*per;
  peleador2->resist = final;



//escritura archivo OUTPUT.txt
  vector <string> pel1;
  vector <string> pel2;
  int turno = 0;
  salida.open("OUTPUT.txt");


  salida << peleador1->name << " equipado con los objetos " <<  objeto1->name << " y " << objeto2->name << endl;
  salida << endl;
  salida << "Se enfrentará contra " << endl;
  salida << endl;
  salida << peleador2->name << " equipado con los objetos " << objeto3->name << endl;
  salida <<endl;
  salida << "Se enfrentarán en el " << arenaj->leyenda << endl;
  salida << endl;
  salida << "Atributos finales: " << endl;
  salida << endl;
  salida << "==============================================================="<< endl;
  salida << endl;
  salida << peleador1->name << ": " << endl;
  salida << "Salud: " << peleador1->salud << endl;
  salida << "Fuerza: " << peleador1->fuerza << endl;
  salida << "Velocidad: " << peleador1->vel << endl;
  salida << "Inteligencia: " << peleador1->intel << endl;
  salida << "Resistencia: " << peleador1->resist << endl;
  salida << ""<< endl;
  
  salida << peleador2->name << ": " << endl;
  salida << "Salud: " << peleador2->salud << endl;
  salida << "Fuerza: " << peleador2->fuerza << endl;
  salida << "Velocidad: " << peleador2->vel << endl;
  salida << "Inteligencia: " << peleador2->intel << endl;
  salida << "Resistencia: " << peleador2->resist << endl;
  salida << ""<< endl;



  
  
  salida.close();
  return 0;
  
}