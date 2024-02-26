#include "CObstaculo.h"


CObstaculo::CObstaculo(TipoEntero pPosX, TipoEntero pPosY){
  m_PosX=pPosX;
  m_PosY=pPosY;
}
TipoEntero CObstaculo:: getPosX(){return m_PosX;};
TipoEntero CObstaculo:: getPosY(){return m_PosY;};