#include "CObstaculoMediano.h"


  CObstaculoMediano::CObstaculoMediano(TipoEntero pPosX, TipoEntero pPosY):CObstaculo(pPosX,pPosY){}
    
    TipoCaracter CObstaculoMediano:: get_tipe(){return tipe;}
    TipoCaracter CObstaculoMediano:: get_dano(){return dano;}
    TipoDouble CObstaculoMediano:: get_ataca(){return ataca;}