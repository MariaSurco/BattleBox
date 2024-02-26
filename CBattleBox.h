#ifndef AGREGACION_CBATTLEBOX_H
#define AGREGACION_CBATTLEBOX_H
#include <iostream>
#include <vector>
#include "Tipos.h"
#include "CRobot.h"
#include "CRobotMedianoyPesado.h"
#include "CRobotLigero.h"
#include "CObstaculo.h"
#include "CObstaculoLigero.h"
#include "CObstaculoMediano.h"
#include "CObstaculoPesado.h"
#include <stdbool.h>


using namespace std;
const TipoEntero ALTURA = 11;
const TipoEntero ANCHO  = 11;
const TipoCaracter COLOR ='.';

class CBattleBox {
private:
    vector<vector<TipoCaracter>> m_Plano;
    vector<CRobot*> m_Robots;
    vector<CObstaculo*> m_obstaculo;
    void resizePlano(TipoEntero pAltura, TipoEntero pAncho);

public:
    CBattleBox();
    CBattleBox(TipoEntero pAltura, TipoEntero pAncho);
    virtual ~CBattleBox();
    void agregarRobotLigero(CRobotLigero* pRobot);
    void agregarRobotPesado(CRobotPesado* pRobot);
    void dibujarBattleBox(ostream &os);
    void actualizarBattleBox();
    TipoEntero getAltura();
    TipoEntero getAncho();
    void set_x_y(TipoEntero Px,TipoEntero Py);
    void agregarRobotMediano(CRobotMediano* pRobot);
    void agregarobstaculoLigero(CObstaculoLigero* pObstaculo);
   void agregarobstaculoMediano(CObstaculoMediano* pObstaculo);
   void agregarobstaculoPesado(CObstaculoPesado* pObstaculo);
    void imprimirRobots(ostream &os);
    void get_nombre_turno(TipoEntero i);
    TipoEntero get_vida_turno(TipoEntero i);
    void moverse(TipoEntero i);
    void recomponer_energia();
    void pegar(TipoEntero i);
    void empujar(TipoEntero i);
    TipoString nombre(TipoEntero i);


    
    
    
    
    
    };
    #endif //AGREGACION_BATTLEBOX_H