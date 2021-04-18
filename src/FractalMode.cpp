#include "FractalMode.h"

Fractal::Fractal(bool activate){
    this->activate = activate;
}

void Fractal::setActivate(){ activate = !activate; }
bool Fractal::getActivate(){ return activate; }