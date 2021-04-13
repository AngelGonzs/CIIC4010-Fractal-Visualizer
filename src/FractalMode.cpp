#include "FractalMode.h"

Fractal::Fractal(bool activate){
    this->activate = activate;
}

void Fractal::setActivate(bool k){ activate = k; }
bool Fractal::getActivate(){ return activate; }