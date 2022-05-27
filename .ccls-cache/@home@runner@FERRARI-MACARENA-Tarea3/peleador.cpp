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
double peleador::desgaste(int resist, int turno) {
  return (exp((-20*turno)/resist)) * (1 + ((20*turno)/resist));
}

void peleador::show_peleador(){
  cout << "\nNombre: " << name << endl;
  cout << "Salud: " << salud << endl;
  cout << "Fuerza: " << fuerza << endl;
  cout << "Velocidad: " << vel << endl;
  cout << "Inteligencia: " << intel << endl;
  cout << "Resistencia: " << resist << endl;
  cout << "Leyenda: " << leyenda << endl;
  

}
  