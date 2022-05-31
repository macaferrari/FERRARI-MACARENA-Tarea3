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
  string archivo;
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      archivo += argv[i];
    }
  }
  cout << archivo;
  srand(time(NULL));
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
  vector <string> pel1;
  vector <string> pel2;
  vector <string> hab_esp;

  for (int v = 0; v < 3; v++) {
    if (v == 0) {
      hab_esp.push_back("Ninguno");
    }
    else if (v == 1) {
      hab_esp.push_back("Rey de los Muertos");
    }
    else if (v == 2) {
      hab_esp.push_back("Último aliento");
    }
  }

  
  
  
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
        if (objeto1->pel == peleador1->name) {
          pel1.push_back(objeto1->name);
        }
        else {pel2.push_back(objeto1->name);}
      }
      if (cont_obj == 2) {
        objeto2 = new objeto(p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
        if (objeto2->pel == peleador1->name) {
          pel1.push_back(objeto2->name);
        }
        else {pel2.push_back(objeto2->name);}
      
      }
      if (cont_obj == 3) {
        objeto3 = new objeto (p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
        if (objeto3->pel == peleador1->name) {
          pel1.push_back(objeto3->name);
        }
        else {pel2.push_back(objeto3->name);}
      }
      if (cont_obj == 4) {
        objeto4 = new objeto(p, name, tipo, salud, fuerza, vel, intel, resist, leyenda);
        if (objeto4->pel == peleador1->name) {
          pel1.push_back(objeto4->name);
        }
        else {pel2.push_back(objeto4->name);}
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


  //habilidad de los peleadores 
  
  int pel1_h = rand()%(3 - 0);
  int pel2_h = rand()%(3 - 0);
  
  

  string hab_1 = hab_esp[pel1_h];
  string hab_2 = hab_esp[pel2_h];
  
//prueba de ecuaciones del enunciado, funcionan
  /*
  int turno = 0;
  cout << peleador1->desgaste(turno)<< endl;
  cout << peleador2->desgaste(turno) << endl;
  double mr1 = peleador1->desgaste(turno);
  double mr2 = peleador2->desgaste(turno);
  cout << peleador1->impacto(mr1) << endl;
  cout << peleador2->impacto(mr2) << endl;*/

  

  
//escritura archivo OUTPUT.txt
  
  salida.open("OUTPUT.txt");

  if (pel1.size() == 1) {
    salida << peleador1->name << " equipado con los objetos " << objeto1->name << endl;
    salida << endl;
    salida << "Se enfrentará contra " << endl;
    salida << endl;
    if (pel2.size() == 1) {
    salida << peleador2->name << " equipado con los objetos " <<  objeto2->name <<endl;
    }
    else if (pel2.size() == 2) {
    salida << peleador2->name << " equipado con los objetos " <<  objeto2->name << " y " << objeto3->name << endl;
  }
  }
  else if (pel1.size() == 2) {
    salida << peleador1->name << " equipado con los objetos " <<  objeto1->name << " y " << objeto2->name << endl;
    salida << endl;
    salida << "Se enfrentará contra " << endl;
    salida << endl;
    
    if (pel2.size() == 1) {
    salida << peleador2->name << " equipado con los objetos " <<  objeto3->name <<endl;
    }
    else if (pel2.size() == 2) {
    salida << peleador2->name << " equipado con los objetos " <<  objeto3->name << " y " << objeto4->name << endl;
  }
  }
  salida <<endl;
  
  salida << "Se enfrentarán en el " << arenaj->leyenda << endl;
  salida << endl;
  
  salida << "Atributos finales: " << endl;
  salida << endl;
  
  salida << "----------------------------------------------------------------------------------------------------------------------------------------------------"<< endl;
  salida << endl;
  
  salida << peleador1->name << ": " << endl;
  salida << "-\tSalud: " << peleador1->salud << endl;
  salida << "-\tFuerza: " << peleador1->fuerza << endl;
  salida << "-\tVelocidad: " << peleador1->vel << endl;
  salida << "-\tInteligencia: " << peleador1->intel << endl;
  salida << "-\tResistencia: " << peleador1->resist << endl;
  salida << endl;
  
  salida << peleador2->name << ": " << endl;
  salida << "-\tSalud: " << peleador2->salud << endl;
  salida << "-\tFuerza: " << peleador2->fuerza << endl;
  salida << "-\tVelocidad: " << peleador2->vel << endl;
  salida << "-\tInteligencia: " << peleador2->intel << endl;
  salida << "-\tResistencia: " << peleador2->resist << endl;
  salida << endl;
  salida << "----------------------------------------------------------------------------------------------------------------------------------------------------"<< endl;
  salida << endl;

  if (hab_1 == "Rey de los Muertos") {
    salida << "La arena a conferido a " << peleador1->name << " la habilidad "<< hab_1 << endl;
    
  }
  else if (hab_1 == "Último aliento") {
    salida << "La arena a conferido a " << peleador1->name << " la habilidad "<< hab_1 << endl;
  }
  salida << endl;
  if (hab_2 == "Rey de los Muertos") {
    salida << "La arena a conferido a " << peleador2->name << " la habilidad "<< hab_2 << endl;
  }
  else if (hab_2 == "Último aliento") {
    salida << "La arena a conferido a " << peleador2->name << " la habilidad "<< hab_2 << endl;
  }
  salida << endl;
  salida << "--------------------------------------------------------------------------"<< endl;
  salida << endl;
  
  salida << "INICIO PELEA: " << endl;
  salida << endl;

  //hacer que juegue la weaita por la chucha juego de mierdadaaaaaaaa no entiendo niuna weaaaaaaaaaa pbn qliooooo te odioooooo aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  int turno = 0;
  string perdedor;
  int h_usada1 = 0;
  int h_usada2 = 0;
  string ganador;
  while (1) {
    if (peleador1->vel > peleador2->vel) {
      string pel1 = peleador1->name;
      string pel2 = peleador2->name;
      int vida_pel1 = peleador1->salud;
      int vida_pel2 = peleador2->salud;
      int n_vida1;
      int n_vida2;
      
      
      
      //turno del jugador 1
      double mr1;
      double mr2;
      int g1;
      int g2;
      //probabilidad
      int p1, p2;
      
      
      p1 = rand()%(3 - 0);
      p2 = rand()%(3 - 0);
      
      
      mr1 = peleador1->desgaste(turno);
      g1 = peleador1->impacto(mr1, p1);

      

      if (p1 == 0) {
        salida << peleador1->name << " pierde el ataque" << endl;
        salida << endl;
      }
      else if (p1 == 1) {
        //restarle vida al jugador
        int vida2 = peleador2->salud;
        n_vida2 = vida2 - g1;
        
        if (n_vida2 <= 0) {
          peleador2->salud = 0;
          n_vida2 = 0;
          
        }
        else {peleador2->salud = n_vida2;}
        
        salida << pel1 << " ataca a " << pel2 << " con un golpe de " << g1 << ", vida de " << pel2 << " queda en " << n_vida2 << endl;
        salida << endl;
        if (n_vida2 == 0) {
          salida << "-------------------- " << pel2 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel2;
          ganador = pel1;
          
        }
      }
      else if (p1 == 2) {
        //restarle vida al jugador
        int vida2 = peleador2->salud;
        n_vida2 = vida2 - g1;
        if (n_vida2 <= 0) {
          peleador2->salud = 0;
          n_vida2 = 0;
          
        }
        else {peleador2->salud = n_vida2;}
        
        salida << pel1 << " hace un critico, golpe de  " << g1 << ", " << pel2 << " pierde  " << g1 << " de vida. Vida de " << pel2 << " queda en " << n_vida2 << endl;
        salida << endl;
        if (n_vida2 == 0) {
          salida << "-------------------- " << pel2 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel2;
          ganador = pel1;
          
        }
        
      }
      if (n_vida2 == 0) {
        if (perdedor == peleador2->name) {
          cout << perdedor << endl;
          if (hab_2 == "Ninguno" ) {
          salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
          salida <<endl;
            break;
        }
          else if (hab_2 == "Rey de los Muertos") {
            
            
            double prob = peleador2->rey_muertos();
            cout << prob << endl;
            if (prob == 1) {
              if (h_usada2 == 0) {
                salida << "------- Habilidad especial Rey de los muerto activada -------------------" << endl;
                salida << endl;
                peleador2->salud = vida_pel2;
                int ptos = (peleador2->intel)/2; 
                int n_intel = peleador2->intel - ptos;
                salida << "-\t" << peleador2->name << " revive, inteligencia pierde " << ptos << " puntos." << endl;
                salida << endl;
                h_usada2++;
                }
              else {
                
                salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
                salida <<endl;
                break;}
                
            }
            
            if (prob == 0) {
              salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
              salida <<endl;
              break;
            }
          }
          else if (hab_2 == "Último aliento") {
            break;
          }
        }
        }
        //ultimo aliento
      else if (n_vida2 >= 1 && n_vida2 <= 10) {
        if (hab_2 == "Último aliento") {
          double ult_a = peleador2->ult_aliento();
          if (ult_a == 0) {
            peleador2->salud = 1;
            int f = (peleador2->fuerza)*0.5;
            int i = (peleador2->intel)*0.5;
            int r = (peleador2->resist)*0.5;
            int cambio = peleador2->fuerza + f;
            peleador2->fuerza = cambio;
            cambio = peleador2->intel + i;
            peleador2->intel = cambio;
            cambio = peleador2->resist + r;
            peleador2->resist = cambio;
            
          }
        }
      }
      //turno pel2
      
      
      mr2 = peleador2->desgaste(turno);
      g2 = peleador2->impacto(mr2, p2);

      if (p2 == 0) {
        salida << pel2 << " pierde el ataque" << endl;
        salida << endl;
      }
      else if (p2 == 1) {
        //restarle vida al jugador
        int vida1 = peleador1->salud;
        
        n_vida1 = vida1 - g2;
        
        if (n_vida1 <= 0) {
          peleador1->salud = 0;
          n_vida1 = 0;
        
        }
        else {peleador1->salud = n_vida1;}
        
        salida << pel2 << " ataca a " << pel1 << " con un golpe de " << g2 << ", vida de " << pel1 << " queda en " << n_vida1 << endl;
        salida << endl;
        if (n_vida1 == 0) {
          salida << "-------------------- " << pel1 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel1;
          ganador = pel2;
          
        }
      }
      else if (p2 == 2) {
        //restarle vida al jugador
        int vida1 = peleador1->salud;
        n_vida1 = vida1 - g2;
        peleador1->salud = n_vida1;
        if (n_vida1 <= 0) {
          peleador1->salud = 0;
          n_vida1 = 0;
          
        }
        else {peleador1->salud = n_vida1;}
        salida << pel2 << " ataca a " << pel1 << " con un golpe de " << g2 << ", vida de " << pel1 << " queda en " << n_vida1 << endl;
        salida << endl;
        if (n_vida1 == 0) {
          salida << "-------------------- " << pel1 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel1;
          ganador = pel2;
          
        }
      }
      if (n_vida1 == 0) {
        if (perdedor == peleador1->name) {
          if (hab_1 == "Ninguno" ) {
            salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
            salida <<endl;
            break;
        }
          else if (hab_1 == "Rey de los Muertos") {
            if (h_usada1 == 0) {
              double prob = peleador1->rey_muertos();
              if (prob == 1) {
                salida << "------- Habilidad especial Rey de los muerto activada -------------------" << endl;
                salida << endl;
                peleador2->salud = vida_pel1;
                int ptos = (peleador1->intel)/2; 
                int n_intel = peleador1->intel - ptos;
                salida << peleador1->name << " revive, inteligencia pierde " << ptos << " puntos." << endl;
                salida << endl;
                h_usada1++;
              }
              else {break;}
            }
            
          }
          else if (hab_1 == "Último aliento") {
            break;
          }
      }
        
      }
      else if (n_vida1 >= 1 && n_vida1 <= 10) {
        if (hab_1 == "Último aliento") {
          double ult_a = peleador1->ult_aliento();
          if (ult_a == 0) {
            peleador1->salud = 1;
            int f = (peleador1->fuerza)*0.5;
            int i = (peleador1->intel)*0.5;
            int r = (peleador1->resist)*0.5;
            int cambio = peleador1->fuerza + f;
            peleador1->fuerza = cambio;
            cambio = peleador1->intel + i;
            peleador1->intel = cambio;
            cambio = peleador1->resist + r;
            peleador1->resist = cambio;
            
          }
        }
      }
      int t = turno + 1;
      salida << "-------------------- Fin " << t << "° turno ---------------------------------------" << endl;
      salida << endl;

      turno++;
      
      
      
      
    }
    else if (peleador2->vel > peleador1->vel) {
      string pel1 = peleador2->name;
      string pel2 = peleador1->name;
      int vida_pel1 = peleador1->salud;
      int vida_pel2 = peleador2->salud;
      int n_vida1;
      int n_vida2;
      
      
      //turno del jugador 1
      double mr1;
      double mr2;
      int g1;
      int g2;
      //probabilidad
      int p1, p2;
      
      
      p1 = rand()%(3 - 0);
      p2 = rand()%(3 - 0);
      
      
      mr1 = peleador1->desgaste(turno);
      g1 = peleador1->impacto(mr1, p1);

      

      if (p1 == 0) {
        salida << peleador1->name << " pierde el ataque" << endl;
        salida << endl;
      }
      else if (p1 == 1) {
        //restarle vida al jugador
        int vida2 = peleador2->salud;
        n_vida2 = vida2 - g1;
        
        if (n_vida2 <= 0) {
          peleador2->salud = 0;
          n_vida2 = 0;
          
        }
        else {peleador2->salud = n_vida2;}
        
        salida << pel1 << " ataca a " << pel2 << " con un golpe de " << g1 << ", vida de " << pel2 << " queda en " << n_vida2 << endl;
        salida << endl;
        if (n_vida2 == 0) {
          salida << "-------------------- " << pel2 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel2;
          ganador = pel1;
          
        }
      }
      else if (p1 == 2) {
        //restarle vida al jugador
        int vida2 = peleador2->salud;
        n_vida2 = vida2 - g1;
        if (n_vida2 <= 0) {
          peleador2->salud = 0;
          n_vida2 = 0;
          
        }
        else {peleador2->salud = n_vida2;}
        
        salida << pel1 << " hace un critico, golpe de  " << g1 << ", " << pel2 << " pierde  " << g1 << " de vida. Vida de " << pel2 << " queda en " << n_vida2 << endl;
        salida << endl;
        if (n_vida2 == 0) {
          salida << "-------------------- " << pel2 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel2;
          ganador = pel1;
          
        }
        
      }
      if (n_vida2 == 0) {
        if (perdedor == peleador2->name) {
          cout << perdedor << endl;
          if (hab_2 == "Ninguno" ) {
          salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
          salida <<endl;
            break;
        }
          else if (hab_2 == "Rey de los Muertos") {
            
            
            double prob = peleador2->rey_muertos();
            cout << prob << endl;
            if (prob == 1) {
              if (h_usada2 == 0) {
                salida << "------- Habilidad especial Rey de los muerto activada -------------------" << endl;
                salida << endl;
                peleador2->salud = vida_pel2;
                int ptos = (peleador2->intel)/2; 
                int n_intel = peleador2->intel - ptos;
                salida << "-\t" << peleador2->name << " revive, inteligencia pierde " << ptos << " puntos." << endl;
                salida << endl;
                h_usada2++;
                }
              else {
                
                salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
                salida <<endl;
                break;}
                
            }
            
            if (prob == 0) {
              salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
              salida <<endl;
              break;
            }
          }
          else if (hab_2 == "Último aliento") {
            break;
          }
        }
        }
      //turno pel2
      
      
      mr2 = peleador2->desgaste(turno);
      g2 = peleador2->impacto(mr2, p2);

      if (p2 == 0) {
        salida << pel2 << " pierde el ataque" << endl;
        salida << endl;
      }
      else if (p2 == 1) {
        //restarle vida al jugador
        int vida1 = peleador1->salud;
        
        n_vida1 = vida1 - g2;
        
        if (n_vida1 <= 0) {
          peleador1->salud = 0;
          n_vida1 = 0;
        
        }
        else {peleador1->salud = n_vida1;}
        
        salida << pel2 << " ataca a " << pel1 << " con un golpe de " << g2 << ", vida de " << pel1 << " queda en " << n_vida1 << endl;
        salida << endl;
        if (n_vida1 == 0) {
          salida << "-------------------- " << pel1 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel1;
          ganador = pel2;
          
        }
      }
      else if (p2 == 2) {
        //restarle vida al jugador
        int vida1 = peleador1->salud;
        n_vida1 = vida1 - g2;
        peleador1->salud = n_vida1;
        if (n_vida1 <= 0) {
          peleador1->salud = 0;
          n_vida1 = 0;
          
        }
        else {peleador1->salud = n_vida1;}
        salida << pel2 << " ataca a " << pel1 << " con un golpe de " << g2 << ", vida de " << pel1 << " queda en " << n_vida1 << endl;
        salida << endl;
        if (n_vida1 == 0) {
          salida << "-------------------- " << pel1 << " muere -----------------------------------------" << endl;
          salida << endl;
          perdedor = pel1;
          ganador = pel2;
          
        }
      }
      if (n_vida1 == 0) {
        if (perdedor == peleador1->name) {
          if (hab_1 == "Ninguno" ) {
            salida << "----------------- Fin de la pelea ----------------------------------------" << endl;
            salida <<endl;
            break;
        }
          else if (hab_1 == "Rey de los Muertos") {
            if (h_usada1 == 0) {
              double prob = peleador1->rey_muertos();
              if (prob == 1) {
                salida << "------- Habilidad especial Rey de los muerto activada -------------------" << endl;
                salida << endl;
                peleador2->salud = vida_pel1;
                int ptos = (peleador1->intel)/2; 
                int n_intel = peleador1->intel - ptos;
                salida << peleador1->name << " revive, inteligencia pierde " << ptos << " puntos." << endl;
                salida << endl;
                h_usada1++;
              }
              else {break;}
            }
            
          }
          else if (hab_1 == "Último aliento") {
            break;
          }
      }   
        
      }
      int t = turno + 1;
      salida << "-------------------- Fin " << t << "° turno ---------------------------------------" << endl;
      salida << endl;

      turno++;
      
      
    }
    }

  if (ganador == peleador1->name) {
    salida <<" ------------------ Ganador: " << peleador1->name << " ----------------------------------------" << endl;
    salida << endl;
  }
  else if (ganador == peleador2->name) {
    salida <<" ------------------ Ganador: " << peleador2->name << " ----------------------------------------" << endl;
    salida << endl;
  
  }
  

  
  
  


  
  
  salida.close();
  delete(peleador1);
  delete(peleador2);
  delete(objeto1);
  delete(objeto2);
  if (cont_obj > 2) {
    delete(objeto3);
  }
  if (cont_obj > 3) {
    delete(objeto4);
  }
  delete(arenaj);
  
  return 0;
  
}