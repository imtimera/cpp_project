/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_2048_VarT.h
 * Author: netbook
 *
 * Created on 21 décembre 2016, 22:28
 */

#ifndef CASE_2048_VART_H
#define CASE_2048_VART_H
#include "Grille_2048.h"

class Grille_2048_VarT: public Grille_2048 {
public:
    Grille_2048_VarT(Joueur & j);
    Grille_2048_VarT(int n, Joueur& j);
    virtual ~Grille_2048_VarT();

    
private:
    void GenereAlea() override;

};

#endif /* CASE_2048_VART_H */

