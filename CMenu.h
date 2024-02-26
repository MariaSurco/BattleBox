
#ifndef AGREGACION_MENU_H
#define AGREGACION_MENU_H
#include "CBattleBox.h"
#include "Tipos.h"

template <typename T>
T input(string label) {
  T value;
  cout << label;
  cin >> value;
  cin.clear();
  return value;
}



class Menu {

  
    
    TipoEntero m_Opcion;
    CBattleBox m_BattleBox;
    void imprimirMenu();
    void seleccionarOpcion();
    void agregarObjeto();
    void agregarRobot();
    void dibujarMapa();
    void cambiar_tablero();
    void imprimirmenu_configurar();
    void imprimirmenu_jugar();
    void imprimirobstaculos();
    void imprimirrobots();
    void ejecutar_configuracion();
    void ejecutar_jugar();
    void pegar(TipoEntero i);

public:
    Menu(): m_Opcion{} {}
    void ejecutar();
};

#endif //AGREGACION_MENU_H