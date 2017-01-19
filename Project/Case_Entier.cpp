/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Case_Entier.cpp
 * Author: netbook
 * 
 * Created on 22 novembre 2016, 22:44
 */
#include "Case_Entier.h"

Case_Entier::Case_Entier(){
}
Case_Entier::Case_Entier(int v):val(v) {
}

int Case_Entier::getVal(){
    return val;
}
void Case_Entier::setVal(int i){
     val=i;
}
void Case_Entier::setElement(int a){
    setVal(a);
}
/**
 * La methode d'affichage d'un element
 * Pourquoi autant de espace??? Pour une bonne presentation
 * et une bonne visibilité du prog dans le terminal
 * @param out
 */
void Case_Entier::put(ostream& out){
    int val=getVal();
     if (val<10 && val>=0)
        out << "__" <<val <<"_";
    else if (val >=10 && val<100)
        out <<"_"<< val <<"_";
    else if (val<1000 && val >=100) 
        out  <<val<<"_";
    else if (val<0 && val >-10 )
        out << "_" <<val <<"_";
    else if (val <= -10 && val >-100 )
        out <<val <<"_";
    else if (val <= -100 && val >-1000)
        out  <<val<"_" ;
    
    else 
        out << val;
}

int Case_Entier::getElement(){
    return getVal();
}

Case_Entier::~Case_Entier() {
    delete &val;
}

