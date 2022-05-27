#include <string>
using namespace std;

class peleador {
private:
  string name;
  int salud;
  int fuerza;
  int vel;
  int intel;
  int resist;
  string leyenda;
public:
  peleador(string, int, int, int, int, int, string);
  double desgaste(int, int);
  void show_peleador();

};