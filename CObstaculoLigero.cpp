#include "CObstaculoLigero.h"


  CObstaculoLigero::CObstaculoLigero(TipoEntero pPosX, TipoEntero pPosY):CObstaculo(pPosX,pPosY){}
    
    TipoCaracter CObstaculoLigero:: get_tipe(){return tipe;}
    TipoCaracter CObstaculoLigero:: get_dano(){return dano;}
    TipoDouble CObstaculoLigero:: get_ataca(){return ataca;}