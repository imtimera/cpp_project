/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template 
 * 
 * in the editor.
 */

/* 
 * File:   JoueurRobot.h
 * Author: netbook
 *
 * Created on 22 novembre 2016, 18:47
 */

#ifndef JOUEURROBOT_H
#define JOUEURROBOT_H

#include "Joueur/Joueur.h"
class JoueurRobot:public Joueur {

    public:
    JoueurRobot();
    JoueurRobot(string n);
    JoueurRobot(const JoueurRobot& orig);
    void Jouer(Grille *g) override;
    int generePos() override;
    ~JoueurRobot();
   
};

#endif /* JOUEURROBOT_H */
