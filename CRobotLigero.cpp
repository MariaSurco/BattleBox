#include "CRobotLigero.h"

CRobotLigero::CRobotLigero(TipoString pNombre, TipoCaracter pColor,   TipoEntero pPosX, TipoEntero pPosY):CRobot(pNombre,pColor,pPosX,pPosY){}


    TipoDouble CRobotLigero::getPeso(){return Peso;};
    TipoDouble CRobotLigero:: getVida(){return Vida;};
    TipoEntero CRobotLigero:: getMovimiento(){return Movimiento;};
    TipoDouble CRobotLigero:: getDano(){return Dano;};
    TipoDouble CRobotLigero:: getCosto(){return Costo_ac;};
    void CRobotLigero:: set_vida(TipoDouble u){
      Vida-=u;
      
    };