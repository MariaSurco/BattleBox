
#include "CRobot.h"

CRobot::CRobot(): m_Color{}, m_PosX{}, m_PosY{}  {}

CRobot::CRobot(TipoString pNombre, TipoCaracter pColor,  TipoEntero pPosX, TipoEntero pPosY):
                                                 m_Nombre{pNombre}, m_Color{pColor},
              
                                                 m_PosX{pPosX}, m_PosY{pPosY}
                                                 {}
                                                 

CRobot::~CRobot() {}
void CRobot:: set_Px(TipoEntero ppx){
  m_PosX=ppx;
};
void CRobot:: set_Py(TipoEntero ppy){
    m_PosY=ppy;

};

TipoString   CRobot::getNombre() { return m_Nombre; }
TipoEntero   CRobot::getPosX()   { return m_PosX; }
TipoEntero   CRobot::getPosY()   { return m_PosY; }
TipoCaracter CRobot::getColor()  { return m_Color; }
TipoDouble CRobot:: getEnergia(){return m_energia;};
void CRobot:: set_Energia(TipoDouble energy){m_energia-=energy;};
void CRobot:: recomponer_energia(){
  m_energia+=10;
};


