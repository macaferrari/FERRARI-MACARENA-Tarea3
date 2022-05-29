#include <stdlib.h>
#include <time.h>
#include "peleador.h"
#include <bits/stdc++.h>

peleador::peleador(string name, int salud, int fuerza, int vel, int intel, int resist, string leyenda) {
  
  this->name = name;
  this->salud = salud;
  this->fuerza = fuerza;
  this->vel = vel;
  this->intel = intel;
  this->resist = resist;
  this->leyenda = leyenda;
  
}
double peleador::desgaste(int turno) {
  if (resist == 0) {
    return 0;
  }
  return (exp((-20*turno)/resist)) * (1 + ((20*turno)/resist));
}

double peleador::impacto(double mr) {
  int num, c;
    srand(time(NULL));
  c = rand() % (3 - 0);
  
  return c * ((vel * fuerza) / (vel + fuerza) + intel) * mr;
}


void peleador::show_peleador(){
  cout << name << ": "<< endl;
  cout << "Salud: " << salud << endl;
  cout << "Fuerza: " << fuerza << endl;
  cout << "Velocidad: " << vel << endl;
  cout << "Inteligencia: " << intel << endl;
  cout << "Resistencia: " << resist << endl;
  cout << "Leyenda: " << leyenda << endl;
  cout << ""<< endl;
  
}
  