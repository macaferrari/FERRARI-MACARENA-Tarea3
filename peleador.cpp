#include <stdlib.h>
#include <time.h>
#include "peleador.h"
#include <math.h>


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

double peleador::impacto(double mr, int c) {
  
  return c * ((vel * fuerza) / (vel + fuerza) + intel) * mr;
}


double peleador::ult_aliento() { 
  int prob;
  srand(time(NULL));
  prob = rand()%(12-1);

  if (prob == 7 || prob == 2 || prob == 4 || prob == 9) {
    return 1;
  }
  else {return 0;}
}
double peleador::rey_muertos() { 
  int prob;
  srand(time(NULL));
  prob = rand()%(12-1);

  if (prob == 7 || prob == 2 || prob == 4) {
    return 1;
  }
  else {return 0;}
}
  