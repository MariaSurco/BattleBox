#ifndef AGREGACION_COBSTACULO_H
#define AGREGACION_COBSTACULO_H


#include <iostream>
#include "Tipos.h"

using namespace std;


class CObstaculo {
private:
public:

    CObstaculo(TipoEntero pPosX, TipoEntero pPosY);
    TipoEntero    m_PosX;
    TipoEntero    m_PosY;
    TipoEntero getPosX();
    TipoEntero getPosY();
    virtual    TipoCaracter get_tipe()=0;
    virtual    TipoCaracter get_dano()=0;
    virtual    TipoDouble get_ataca()=0;
};
#endif //AGREGACION_COBSTACULO_H