#include "CRobotMedianoyPesado.h"

CRobotMediano::CRobotMediano(TipoString pNombre, TipoCaracter pColor,  TipoEntero pPosX, TipoEntero pPosY):CRobot(pNombre,pColor,pPosX,pPosY){}


    TipoDouble CRobotMediano::getPeso(){return Peso;};
    TipoDouble CRobotMediano:: getVida(){return Vida;};
    TipoEntero CRobotMediano:: getMovimiento(){return Movimiento;};
    TipoDouble CRobotMediano:: getDano(){return Dano;};
    TipoDouble CRobotMediano:: getCosto(){return Costo_ac;};
     void CRobotMediano:: set_vida(TipoDouble u){
      Vida-=u;
      
    };


CRobotPesado::CRobotPesado(TipoString pNombre, TipoCaracter pColor,   TipoEntero pPosX, TipoEntero pPosY):CRobot(pNombre,pColor,pPosX,pPosY){}


    TipoDouble CRobotPesado::getPeso(){return Peso;};
    TipoDouble CRobotPesado:: getVida(){return Vida;};
    TipoEntero CRobotPesado:: getMovimiento(){return Movimiento;};
    TipoDouble CRobotPesado:: getDano(){return Dano;};
    TipoDouble CRobotPesado:: getCosto(){return Costo_ac;};
     void CRobotPesado:: set_vida(TipoDouble u){
      Vida-=u;
      
    };