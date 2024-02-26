#ifndef AGREGACION_COBSTACULOPESADO_H
#define AGREGACION_COBSTACULOPESADO_H


#include <iostream>
#include "Tipos.h"
#include "CObstaculo.h"
using namespace std;

class CObstaculoPesado: public CObstaculo {
private:
TipoCaracter tipe='3';
TipoDouble ataca=8;
TipoCaracter dano= '8';
public:

    CObstaculoPesado(TipoEntero pPosX, TipoEntero pPosY);
    
    TipoCaracter get_tipe();
    TipoCaracter get_dano();
    TipoDouble get_ataca();    
};
#endif //AGREGACION_COBSTACULOPESADO_H