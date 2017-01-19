/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Case_Vide.h
 * Author: netbook
 *
 * Created on 30 novembre 2016, 11:17
 */

#ifndef CASE_VIDE_H
#define CASE_VIDE_H
#include "Case.h"

class Case_Vide: public Case{
public:
    Case_Vide();
    void put(ostream& out) override;
    ~Case_Vide();

private:

};

#endif /* CASE_VIDE_H */

