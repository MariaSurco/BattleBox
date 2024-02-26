#include "CObstaculoPesado.h"


  CObstaculoPesado::CObstaculoPesado(TipoEntero pPosX, TipoEntero pPosY):CObstaculo(pPosX,pPosY){}
    
    TipoCaracter CObstaculoPesado:: get_tipe(){return tipe;}
    TipoCaracter CObstaculoPesado:: get_dano(){return dano;}
    TipoDouble CObstaculoPesado:: get_ataca(){return ataca;}