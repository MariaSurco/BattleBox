#include "CBattleBox.h"
#include <math.h>
#include <string>
#include <iomanip>
#include <algorithm>

void CBattleBox::resizePlano(TipoEntero pAltura, TipoEntero pAncho){
     m_Plano.resize(pAltura);
    for (auto& item: m_Plano)
        item.resize(pAncho);
}
CBattleBox::CBattleBox() {
resizePlano(ALTURA,ANCHO);
}
CBattleBox::CBattleBox(TipoEntero pAltura, TipoEntero pAncho) {

resizePlano(pAltura,pAncho);
}
CBattleBox::~CBattleBox() {}

void CBattleBox:: agregarRobotLigero(CRobotLigero* pRobot){
      m_Robots.emplace_back(pRobot);

}
void CBattleBox:: agregarRobotPesado(CRobotPesado *pRobot){
        m_Robots.emplace_back(pRobot);

}


void CBattleBox::agregarRobotMediano(CRobotMediano *pRobot){
        m_Robots.emplace_back(pRobot);

}

void CBattleBox:: agregarobstaculoLigero(CObstaculoLigero* pObstaculo){
  m_obstaculo.emplace_back(pObstaculo);
}
void CBattleBox:: agregarobstaculoMediano(CObstaculoMediano* pObstaculo){  m_obstaculo.emplace_back(pObstaculo);}
void CBattleBox:: agregarobstaculoPesado(CObstaculoPesado* pObstaculo){  m_obstaculo.emplace_back(pObstaculo);}

void CBattleBox::imprimirRobots(ostream &os) {
    int i = 0;
    for (auto& item: m_Robots) {
        os << "* * * * * * [" << i << "] ";
        os << " Nombre = " << item->getNombre() << " "
             << " Color = "<<" " << item->getColor() <<" "<< "Vida = "<<item->getVida()<<" "<<"Energia = "<<item->getEnergia()<<endl;
        i++;
    }
} 

 
void CBattleBox::actualizarBattleBox() {
    for (auto &row: m_Plano)
        for (auto &cell: row)
            cell = COLOR;
    for (auto& item: m_obstaculo)
        m_Plano[item->getPosX()][item->getPosY()]
                = item->get_tipe();
                
    for (auto& item: m_Robots)
        m_Plano[item->getPosX()][item->getPosY()]
                = item->getColor();


}

void CBattleBox::dibujarBattleBox(ostream &os) {

    os << '\n';
    os << setw(3) << ' ';
    for (auto j = 0; j < getAncho(); ++j)
        os << setw(3) << j;
    os << '\n';

    for (auto i = 0; i < getAltura(); ++i) {
        os << setw(3) << i;
        for (auto j = 0; j < getAncho(); ++j) {
            os << setw(3) << m_Plano[i][j];
        }
        os << '\n';
    }
}

TipoEntero CBattleBox::getAltura() {
    return m_Plano.size();
}

TipoEntero CBattleBox::getAncho(){
    return m_Plano[0].size();
}


void CBattleBox:: set_x_y(TipoEntero Px, TipoEntero Py){
  
  resizePlano(Px+1, Py+1);
  
}

void CBattleBox::get_nombre_turno(TipoEntero i){
  cout<< "ES EL TURNO DE "<<m_Robots[i]->getNombre()<<endl;
}

TipoEntero CBattleBox:: get_vida_turno(TipoEntero i){
  return m_Robots[i]->getVida();
};
void CBattleBox::moverse(TipoEntero i) {
    TipoEntero Espacios;
  TipoString Direccion;

  cout<<"CUANTOS  ESPACIOS  SE  QUIERE  MOVER?: ";
  cin>> Espacios;
 while (Espacios <= 0 || Espacios > m_Robots[i]->getPeso()) {
        cout << "Cantidad incorrecta, los limites son: 1, "<<m_Robots[i]->getPeso()<<" : ";
        cin>>Espacios;
    }
  
  cout<<"EN  QUE  DIRECCION  SE  QUIERE  MOVER?: ";
  cin>> Direccion;

  TipoEntero x= m_Robots[i]->getPosX();
  TipoEntero y= m_Robots[i]->getPosY();

  if(Direccion=="ARRIBA" ){
            if(m_Plano[x-Espacios][y]!='.'){
      if(m_Plano[x-Espacios][y]=='1'||m_Plano[x-Espacios][y]=='2'||m_Plano[x-Espacios][y]=='3'){
        if(m_Plano[x-Espacios][y]=='1'){
          m_Robots[i]->set_vida(3);

        }
        else if(m_Plano[x-Espacios][y]=='2'){
          m_Robots[i]->set_vida(5);
          
        }
        else  if(m_Plano[x-Espacios][y]=='3'){        
          m_Robots[i]->set_vida(8);
}
       
      }
      
      else{
          Espacios+=1;
        }
    }
    m_Robots[i]->set_Px(x-Espacios);


}
  else if(Direccion=="ABAJO" ){

    if(m_Plano[x+Espacios][y]!='.'){
      if(m_Plano[x+Espacios][y]=='1'||m_Plano[x+Espacios][y]=='2'||m_Plano[x+Espacios][y]=='3'){
        if(m_Plano[x+Espacios][y]=='1'){
          m_Robots[i]->set_vida(3);

        }
        else if(m_Plano[x+Espacios][y]=='2'){
          m_Robots[i]->set_vida(5);
          
        }
        else  if(m_Plano[x+Espacios][y]=='3'){        
          m_Robots[i]->set_vida(8);
}
        
      }
      
      else{
          Espacios+=1;
        }
    }
    m_Robots[i]->set_Px(x+Espacios);
  }
  if(Direccion=="DERECHA" ){


      if(m_Plano[x][y+Espacios]!='.'){
      if(m_Plano[x][y+Espacios]=='1'||m_Plano[x][y+Espacios]=='2'||m_Plano[x][y+Espacios]=='3'){
        if(m_Plano[x][y+Espacios]=='1'){
          m_Robots[i]->set_vida(3);

        }
        else if(m_Plano[x][y+Espacios]=='2'){
          m_Robots[i]->set_vida(5);
          
        }
        else  if(m_Plano[x][y+Espacios]=='3'){        
          m_Robots[i]->set_vida(8);
}
      else{
          Espacios+=1;
        }
      }
      
      else{
          Espacios+=1;
        }
    }
    m_Robots[i]->set_Py(y+Espacios);


  }
  if(Direccion=="IZQUIERDA" ){


    if(m_Plano[x][y-Espacios]!='.'){
      if(m_Plano[x][y-Espacios]=='1'||m_Plano[x][y-Espacios]=='2'||m_Plano[x][y-Espacios]=='3'){
        if(m_Plano[x][y-Espacios]=='1'){
          m_Robots[i]->set_vida(3);

        }
        else if(m_Plano[x][y-Espacios]=='2'){
          m_Robots[i]->set_vida(5);
          
        }
        else  if(m_Plano[x][y-Espacios]=='3'){        
          m_Robots[i]->set_vida(8);
}

      }
      else{
          Espacios+=1;
        }
    }
    m_Robots[i]->set_Py(y-Espacios);

  

  }

  m_Robots[i]->set_Energia(m_Robots[i]->getCosto());
  
}
void CBattleBox:: recomponer_energia(){
  for(auto i:m_Robots){
  i->recomponer_energia();
}
};

void CBattleBox:: pegar(TipoEntero i){
  TipoEntero x= m_Robots[i]->getPosX();
  TipoEntero y= m_Robots[i]->getPosY();

  if(m_Plano[x][y-1]!='.'||m_Plano[x][y+1]!='.'||m_Plano[x-1][y]!='.'||m_Plano[x+1][y]!='.'){
    if(i==0){
      m_Robots[1]->set_vida(m_Robots[0]->getPeso());
    }
    else{
          m_Robots[0]->set_vida(m_Robots[1]->getPeso());
    
    }
    cout<<"GOLPEASTE  AL  ENEMIGO  POR  "<<m_Robots[i]->getPeso() <<" DE  DANO!"<<endl;
  }
  else{
    cout<<"FALLASTE"<<endl;
  }
  m_Robots[i]->set_Energia(m_Robots[i]->getCosto()*3);
  };

void CBattleBox:: empujar(TipoEntero i){
  TipoEntero x= m_Robots[i]->getPosX();
  TipoEntero y= m_Robots[i]->getPosY();

  TipoEntero Espacios=fabs((m_Robots[0]->getPeso()*m_Robots[0]->getMovimiento())-(m_Robots[1]->getPeso()*m_Robots[1]->getMovimiento()));
        
if(Espacios==0){
  Espacios=1;
}

  if(m_Plano[x][y-1]!='.'||m_Plano[x][y+1]!='.'||m_Plano[x-1][y]!='.'||m_Plano[x+1][y]!='.'){
      if(i==0){
            
      TipoEntero px= m_Robots[1]->getPosX();
      TipoEntero py= m_Robots[1]->getPosY();
      if(m_Plano[x][y-1]==m_Plano[px][py]){
          if(m_Plano[px][py-Espacios]=='1'){
            m_Robots[1]->set_vida(3);
          }
          if(m_Plano[px][py-Espacios]=='2'){
            m_Robots[1]->set_vida(5);
          }
          if(m_Plano[px][py-Espacios]=='3'){
            m_Robots[1]->set_vida(8);
          }
          m_Robots[1]->set_Py(py-Espacios);
        }

      
      if(m_Plano[x][y+1]==m_Plano[px][py]){
          if(m_Plano[px][py+Espacios]=='1'){
            m_Robots[1]->set_vida(3);
          }
          if(m_Plano[px][py+Espacios]=='2'){
            m_Robots[1]->set_vida(5);
          }
          if(m_Plano[px][py+Espacios]=='3'){
            m_Robots[1]->set_vida(8);
          }
          m_Robots[1]->set_Py(py+Espacios);
        }

      
      if(m_Plano[x+1][y]==m_Plano[px][py]){
         if(m_Plano[px+Espacios][py]=='1'){
            m_Robots[1]->set_vida(3);
          }
          if(m_Plano[px+Espacios][py]=='2'){
            m_Robots[1]->set_vida(5);
          }
          if(m_Plano[px+Espacios][py]=='3'){
            m_Robots[1]->set_vida(8);
          }
          m_Robots[1]->set_Px(px+Espacios);
        }

      
      if(m_Plano[x-1][y]==m_Plano[px][py]){
          if(m_Plano[px-Espacios][py]=='1'){
            m_Robots[1]->set_vida(3);
          }
          if(m_Plano[px-Espacios][py]=='2'){
            m_Robots[1]->set_vida(5);
          }
          if(m_Plano[px-Espacios][py]=='3'){
            m_Robots[1]->set_vida(8);
          }
          m_Robots[1]->set_Px(px-Espacios);
        }



      

            }  
      else if(i==1){
            
      TipoEntero px= m_Robots[0]->getPosX();
      TipoEntero py= m_Robots[0]->getPosY();
      if(m_Plano[x][y-1]==m_Plano[px][py]){
          if(m_Plano[px][py-Espacios]=='1'){
            m_Robots[0]->set_vida(3);
          }
          if(m_Plano[px][py-Espacios]=='2'){
            m_Robots[0]->set_vida(5);
          }
          if(m_Plano[px][py-Espacios]=='3'){
            m_Robots[0]->set_vida(8);
          }
          m_Robots[0]->set_Py(py-Espacios);
        }

      
      if(m_Plano[x][y+1]==m_Plano[px][py]){
          if(m_Plano[px][py+Espacios]=='1'){
            m_Robots[0]->set_vida(3);
          }
          if(m_Plano[px][py+Espacios]=='2'){
            m_Robots[0]->set_vida(5);
          }
          if(m_Plano[px][py+Espacios]=='3'){
            m_Robots[0]->set_vida(8);
          }
          m_Robots[0]->set_Py(py+Espacios);
        }

      
      if(m_Plano[x+1][y]==m_Plano[px][py]){
          if(m_Plano[px+Espacios][py]=='1'){
            m_Robots[0]->set_vida(3);
          }
          if(m_Plano[px+Espacios][py]=='2'){
            m_Robots[0]->set_vida(5);
          }
          if(m_Plano[px+Espacios][py]=='3'){
            m_Robots[0]->set_vida(8);
          }
          m_Robots[0]->set_Px(px+Espacios);
        }

      
      if(m_Plano[x-1][y]==m_Plano[px][py]){
          if(m_Plano[px-Espacios][py]=='1'){
            m_Robots[0]->set_vida(3);
          }
          if(m_Plano[px-Espacios][py]=='2'){
            m_Robots[0]->set_vida(5);
          }
          if(m_Plano[px-Espacios][py]=='3'){
            m_Robots[0]->set_vida(8);
          }
          m_Robots[0]->set_Px(px-Espacios);
        }
      }

      



  }
  else{
        cout<<"FALLASTE\n";
      }
    m_Robots[i]->set_Energia(m_Robots[i]->getCosto()*2);

      };



    TipoString CBattleBox:: nombre(TipoEntero i){
      return m_Robots[i]->getNombre();
    };
