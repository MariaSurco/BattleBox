#ifndef AGREGACION_COBSTACULOMEDIANO_H
#define AGREGACION_COBSTACULOMEDIANO_H


#include <iostream>
#include "Tipos.h"
#include "CObstaculo.h"
using namespace std;

class CObstaculoMediano: public CObstaculo {
private:
TipoCaracter tipe='2';
TipoDouble ataca= 5;
TipoCaracter dano='5';
public:

    CObstaculoMediano(TipoEntero pPosX, TipoEntero pPosY);
        
    TipoCaracter get_tipe();
    TipoCaracter get_dano();
    TipoDouble get_ataca();
};
#endif //AGREGACION_COBSTACULOMEDIANO_H