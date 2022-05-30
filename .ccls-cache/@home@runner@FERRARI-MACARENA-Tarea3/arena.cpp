#include <stdlib.h>
#include <time.h>
#include "arena.h"

arena::arena(string name, string salud, string fuerza, string vel, string intel , string resist, string leyenda) {
  this->name = name;
  this->salud = salud;
  this->fuerza = fuerza;
  this->vel = vel;
  this->intel = intel;
  this->resist = resist;
  this->leyenda = leyenda;
  
}
int arena::habilidad_especial() {
  int hab;
    srand(time(NULL));
  hab = rand() % (3 - 0);
  return hab;
}