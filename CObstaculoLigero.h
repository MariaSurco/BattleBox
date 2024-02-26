#ifndef AGREGACION_COBSTACULOLIGERO_H
#define AGREGACION_COBSTACULOLIGERO_H


#include <iostream>
#include "Tipos.h"
#include "CObstaculo.h"
using namespace std;

class CObstaculoLigero: public CObstaculo {
private:
TipoCaracter tipe='1';
TipoDouble ataca = 3;
TipoCaracter dano='3';
public:

    CObstaculoLigero(TipoEntero pPosX, TipoEntero pPosY);
    
   
    TipoCaracter get_tipe();
    TipoCaracter get_dano();
    TipoDouble get_ataca();
};
#endif //AGREGACION_COBSTACULOLIGERO_H