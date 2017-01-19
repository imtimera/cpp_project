/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Case_Entier.h
 * Author: netbook
 *
 * Created on 22 novembre 2016, 22:44
 */

#ifndef CASE_ENTIER_H
#define CASE_ENTIER_H

#include "Case.h"
class Case_Entier:public Case {
private:
    int val;
public:
    Case_Entier();
    Case_Entier(int v);
    int getVal();
    void setVal(int i); 
    void put(ostream& out);
    int getElement() override;
    void setElement(int a) override;
    ~Case_Entier();
    
};

#endif /* CASE_ENTIER_H */

