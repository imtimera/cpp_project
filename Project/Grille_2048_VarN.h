/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grille_2048_VarN.h
 * Author: netbook
 *
 * Created on 20 décembre 2016, 16:31
 */

#ifndef GRILLE_2048_VARN_H
#define GRILLE_2048_VARN_H

#include "Grille_2048.h"


class Grille_2048_VarN : public Grille_2048 {
public:
    Grille_2048_VarN(Joueur & j);
    Grille_2048_VarN(int n, Joueur & j);
    virtual ~Grille_2048_VarN();
private:
    void fusion(int i, int j) override;
    void GenereAlea() override;
    
};

#endif /* GRILLE_2048_VARN_H */

