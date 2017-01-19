/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_2048_VarT.cpp
 * Author: netbook
 * 
 * Created on 21 décembre 2016, 22:28
 */

#include "Grille_2048_VarT.h"

Grille_2048_VarT::Grille_2048_VarT(Joueur &j):Grille_2048(3,j) {

}


Grille_2048_VarT::Grille_2048_VarT(int n,Joueur &j):Grille_2048(n,j) {

}


/**
 * Generer aleatoirement des 2 3 4 ou 5
 */
void Grille_2048_VarT::GenereAlea(){
    int alea1=abs(rand()%getN());
    int alea2=abs(rand()%5);
    while(getContenu(alea1)->getElement()!=0)
        alea1=abs(rand()%getN());
    if (alea2<=1)
        setBoard(alea1,new Case_Entier(2));
    else if (alea1==2)
        setBoard(alea1,new Case_Entier(4));
    else if (alea2==3) 
        setBoard(alea1,new Case_Entier(3));
    else 
       setBoard(alea1,new Case_Entier(5));
}


Grille_2048_VarT::~Grille_2048_VarT(){
    
}

