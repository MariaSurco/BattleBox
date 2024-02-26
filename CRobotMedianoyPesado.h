#ifndef AGREGACION_ROBOTMEDIANO_H
#define AGREGACION_ROBOTMEDIANO_H
#include "Tipos.h"
#include "CRobot.h"
class CRobotMediano: public CRobot{
private:

  TipoDouble Peso=7;
  TipoDouble Vida = 20;
  TipoEntero Movimiento =2;
  TipoDouble Dano = 2.5;
  TipoDouble Costo_ac=7.5;
public:
CRobotMediano(TipoString pNombre, TipoCaracter pColor, TipoEntero pPosX, TipoEntero pPosY);

    TipoDouble getPeso();
    TipoDouble getVida();
    TipoEntero getMovimiento();
    TipoDouble getDano();
    TipoDouble getCosto();
    void set_vida(TipoDouble u);
};
class CRobotPesado: public CRobot{
private:

  TipoDouble Peso=12;
  TipoDouble Vida=30;
  TipoEntero Movimiento=1;
  TipoDouble Dano=4;
  TipoDouble Costo_ac=10;
public:
CRobotPesado(TipoString pNombre, TipoCaracter pColor,  TipoEntero pPosX, TipoEntero pPosY);

    TipoDouble getPeso();
    TipoDouble getVida();
    TipoEntero getMovimiento();
    TipoDouble getDano();
    TipoDouble getCosto();
    void set_vida(TipoDouble u);
};

#endif //AGREGACION_ROBOTMEDIANO_H