/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Case.h"
#include "Case_Vide.h"
#include "Case_Entier.h"


Case::Case(){

}
void Case::put(ostream& out){
    out <<"X";
}

int Case::getElement() {
    return 0;
}

void Case::setElement(int a){
    
}

ostream& operator <<(ostream& out, Case& c){
    c.put(out);
    return out;
}
Case::~Case(){
    
}

    
