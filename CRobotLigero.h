
#ifndef AGREGACION_ROBOTLIGERO_H
#define AGREGACION_ROBOTLIGERO_H
#include "Tipos.h"
#include "CRobot.h"
class CRobotLigero: public CRobot{
private:

  TipoDouble Peso =3;
  TipoDouble Vida = 15;
  TipoEntero Movimiento = 3;
  TipoDouble Dano = 1;
  TipoDouble Costo_ac = 5;
public:
CRobotLigero();
CRobotLigero(TipoString pNombre, TipoCaracter pColor, TipoEntero pPosX, TipoEntero pPosY);

    TipoDouble getPeso();
    TipoDouble getVida();
    TipoEntero getMovimiento();
    TipoDouble getDano();
    TipoDouble getCosto();
    void set_vida(TipoDouble u);

};


#endif //AGREGACION_ROBOTLIGERO_H