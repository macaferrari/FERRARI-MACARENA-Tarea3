#include <string>
using namespace std;

class peleador {
public:
  string name;
  int salud;
  int fuerza;
  int vel;
  int intel;
  int resist;
  string leyenda;

  peleador(string, int, int, int, int, int, string);
  double desgaste(int);
  double impacto(double, int);

  double rey_muertos();
  double ult_aliento();

};