#include <iostream>
#include <string>
#include <cstdio>
#include <string>
#include "CMenu.h"

using namespace std;

bool validacion=true;

enum class Opciones { Jugar=1, Configurar};


void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    char w;
    do {
         w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. JUGAR\n";
    cout << "2. CONFIGURAR BATTLEBOX\n";
    cout << "3. SALIR\n\n";
}



void Menu::imprimirmenu_configurar(){
  limpiar();
  cout<<"\n";
  cout<<"1. ANADIR OBSTACULO\n\n";
  cout<<"2. CONFIGURAR TAMANO DE TABLERO\n\n";
  cout<<"3. REGRESAR\n\n";

}

void Menu::imprimirobstaculos(){
  cout<<"\n";
  cout<<"1 . LIGERO , DANO: 3\n\n";
  cout<<"2 . MEDIANO, DANO: 5\n\n";
  cout<<"3 . PESADO , DANO: 8\n\n";

};

void Menu::imprimirrobots(){
  cout<<"\n";
  cout<<"1 . LIGERO , PESO : 3 , VIDA : 1 5 , MOVIMIENTO : 3 ,DANO: 1 , COSTO DE ACCION : 5\n\n";
  cout<<"2 . MEDIANO, PESO : 7 , VIDA : 2 0 , MOVIMIENTO : 2 ,DANO: 2 . 5 , COSTO DE ACCION : 7.5\n\n";
  cout<<"3 . PESADO , PESO : 1 2 , VIDA : 3 0 , MOVIMIENTO : 1 ,DANO: 4 , COSTO DE ACCION : 10\n\n";

};
void Menu:: imprimirmenu_jugar(){
  cout<<"\n";
  cout<<"1 .   MOVERSE\n\n";
  cout<<"2 .   EMPUJAR\n\n";
  cout<<"3 .   PEGAR\n\n";
};



void Menu::agregarObjeto() {

    imprimirobstaculos();
    auto opcio = input<TipoEntero>("ELIGE UN TIPO DE BATTLEBOT : ");

    

    auto x = input<TipoEntero>("Ingrese posicion X : ");


    while (x < 0 || x >= m_BattleBox.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << m_BattleBox.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");
    }

    TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
    while (y < 0 || y >= m_BattleBox.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0, "
              << m_BattleBox.getAltura() - 1 << "\n";
        y = input<TipoEntero>("Ingrese posicion Y : ");
    }
    if(opcio==1){
      m_BattleBox.agregarobstaculoLigero(new CObstaculoLigero(x,y));
    }

    else if(opcio==2){
      m_BattleBox.agregarobstaculoMediano(new CObstaculoMediano(x,y));
    }
    else if (opcio==3){
      m_BattleBox.agregarobstaculoPesado(new CObstaculoPesado(x,y));
    }

  m_BattleBox.actualizarBattleBox();
  
}


void Menu::agregarRobot() {

  auto    nombre = input<TipoString>("Ingrese Nombre : ");
   

  imprimirrobots();
  auto opcio = input<TipoEntero>("ELIGE UN TIPO DE BATTLEBOT : ");
    auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");

    auto x = input<TipoEntero>("Ingrese posicion X : ");


    while (x < 0 || x >= m_BattleBox.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << m_BattleBox.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");
    }

    TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
    while (y < 0 || y >= m_BattleBox.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0, "
              << m_BattleBox.getAltura() - 1 << "\n";
        y = input<TipoEntero>("Ingrese posicion Y : ");
    }
    if(opcio==1){
      m_BattleBox.agregarRobotLigero(new CRobotLigero(nombre, color,  x, y));
    }

    else if(opcio==2){
      m_BattleBox.agregarRobotMediano(new CRobotMediano(nombre, color, x, y));
    }
    else if (opcio==3){
      m_BattleBox.agregarRobotPesado(new CRobotPesado(nombre, color,  x, y));
    }

  m_BattleBox.actualizarBattleBox();
}


void Menu::dibujarMapa() {
    m_BattleBox.actualizarBattleBox();
    m_BattleBox.dibujarBattleBox(cout);
    cout << '\n';
    cout << '\n';
    m_BattleBox.imprimirRobots(cout);
    cout << '\n';
    cout << '\n';
}

void Menu::ejecutar() {
    do {
        imprimirMenu();
        cout<<"ELIGA UNA OPCION:";
        cin >> m_Opcion;
        seleccionarOpcion();
        if (validacion == false){
          break;
        }
        
    } while (m_Opcion != 3);
    cout << "Fin del programa...\n";
}

void Menu::ejecutar_configuracion() {

        do {
        imprimirmenu_configurar();
        cout<<"ELIGA UNA OPCION:";
        cin >> m_Opcion;
        if(m_Opcion==1){
          agregarObjeto();
        }
        if(m_Opcion==2){
          cambiar_tablero();
        }

    } while (m_Opcion != 3);
    ejecutar();

        
}


void Menu::cambiar_tablero(){
    auto x = input<TipoEntero>("INGRESE ANCHO DEL TABLERO : ");
    auto y = input<TipoEntero>("INGRESE LARGO DEL TABLERO : ");
    m_BattleBox.set_x_y(x,y);

}

void Menu::ejecutar_jugar(){
  TipoEntero i=0;
  agregarRobot();
  cout<<"\n";
  agregarRobot();
  while(m_BattleBox.get_vida_turno(1)!=0 &&m_BattleBox.get_vida_turno(0)!=0){
    limpiar();

    m_BattleBox.get_nombre_turno(i);
    dibujarMapa();
    imprimirmenu_jugar();
    TipoEntero opci;
    cout<<"ELIJA UNA OPCION: ";
    cin>>opci;

    switch(opci){
      case 1:
        m_BattleBox.moverse(i);
    
        break;
        
      case 3:
        m_BattleBox.pegar(i);
        break;
      case 2:
      m_BattleBox.empujar(i);

      break;
    }


    if(i==0){
      i=1;
    }
    else{
      i=0;
      m_BattleBox.recomponer_energia();
    }

    if(m_BattleBox.get_vida_turno(1)<=0 || m_BattleBox.get_vida_turno(0)<=0){

      if(m_BattleBox.get_vida_turno(1)!=0){
        cout<<"Gana el jugador "<< m_BattleBox.nombre(1)<<endl;
      }
      else{
        cout<<"Gana el jugador "<< m_BattleBox.nombre(0)<<endl;
      }
        validacion = false;
      
        break;
    }
    esperar();
    

  }
  
  }





void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(m_Opcion)) {
      case Opciones::Jugar:  
            ejecutar_jugar();
            break;
      case Opciones::Configurar: 
            ejecutar_configuracion();
            break;
    }
    }