/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Case_2048.h
 * Author: netbook
 *
 * Created on 22 novembre 2016, 22:42
 */

#ifndef CASE_2048_H
#define CASE_2048_H

#include "Case_Entier.h"
class Case_2048:public Case_Entier{
    public :
    Case_2048();
    Case_2048(int v);
    Case_2048(const Case_2048& orig);
    //bool deplacer(int dir);
   // ~Case_2048();
};

#endif /* CASE_2048_H *///ostream& operator<<(ostream& out,const Case& c);

