
#ifndef AGREGACION_CROBOT_H
#define AGREGACION_CROBOT_H


#include <iostream>
#include "Tipos.h"

using namespace std;

class CRobot {
private:
  TipoString    m_Nombre;
  TipoCaracter  m_Color;
  TipoDouble    m_energia=100;
public:
    CRobot();
    CRobot(TipoString pNombre, TipoCaracter pColor,            TipoEntero pPosX, TipoEntero pPosY);
    virtual ~CRobot();
    TipoEntero    m_PosX;
    TipoEntero    m_PosY;
    TipoString getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    TipoCaracter getColor();  
    virtual   TipoDouble getPeso()=0;
    virtual TipoDouble getVida()=0;
    virtual TipoEntero getMovimiento()=0;
    virtual TipoDouble getDano()=0;
    virtual TipoDouble getCosto()=0;
    TipoDouble getEnergia();
    void set_Px(TipoEntero ppx);
    void set_Py(TipoEntero ppy);
    void set_Energia(TipoDouble energy);
    virtual void set_vida(TipoDouble u)=0;
    void recomponer_energia();

};

#endif //AGREGACION_CROBOT_H