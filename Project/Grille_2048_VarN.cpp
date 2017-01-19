/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_2048_VarN.cpp
 * Author: netbook
 * 
 * Created on 20 décembre 2016, 16:31
 */

#include "Grille_2048_VarN.h"

Grille_2048_VarN::Grille_2048_VarN(Joueur &j):Grille_2048(3,j) {
    
}

Grille_2048_VarN::Grille_2048_VarN(int n,Joueur &j):Grille_2048(n,j) {
    
}

/**
 * On redefinie la fusion qui est maintenant pour entre deux cases 
 * egales en valeur absolue et de signe contraires
 * @param i
 * @param j
 */
void Grille_2048_VarN::fusion(int i, int j){
  Case* c;
  /*if (i>j){
      int tmp=i;
      i=j;
      j=tmp;
  }*/
    if (getContenu(i)->getElement()==getContenu(j)->getElement()){
         c=new Case_Entier(2*getContenu(j)->getElement());
         setBoard(j,c);
         Cdeplacable[j]=false;
        setScore(getScore()+abs(c->getElement()));
    }
  else if(getContenu(i)->getElement()+getContenu(j)->getElement()==0){
            setScore(getScore()+abs(2*getContenu(i)->getElement()));
            c=new Case_Vide();
            setBoard(j,new Case_Vide);
            Cdeplacable[j]=true;
  }
    if (c->getElement()>getVal())
        setVal(c->getElement());
    setBoard(i,new Case_Vide);
    
}

void Grille_2048_VarN::GenereAlea(){
    int alea1=abs(rand()%getN());
    int alea2=abs(rand()%12);
    while(getContenu(alea1)->getElement()!=0)
        alea1=abs(rand()%getN());
    if (alea2<=4)
        setBoard(alea1,new Case_Entier(2));
    else if (alea2<=7)
        setBoard(alea1,new Case_Entier(-2));
    else if (alea2<=10) 
        setBoard(alea1,new Case_Entier(4));
    else 
        setBoard(alea1,new Case_Entier(-4));
}

Grille_2048_VarN::~Grille_2048_VarN() {
}

