#ifndef CHANCLETAZO_HPP
#define CHANCLETAZO_HPP

#include <SDL2/SDL.h>

#include "objeto.hpp"
#include "../tipos.hpp"

class Chancletazo : public Objeto
{
  public:

    // Velocidad de la chancleta
    double velocidad;

    // Posicion x, y desde hacia donde se desea enviar la chancla
    SDL_Point referencia;
    
    // Para saber si la chancla choco con algo
    bool choque;

    // Para saber si es hora de cambiar de tipo de chancla
    bool cambiar;

    Direccion direccion;

    // Constructor
    // @param x - Posicion x
    // @param y - Posicion y
    // @param tc - Tipo de chancleta a utilizar
    Chancletazo(double x, double y, TipoCuadro tc);

    void actualizar(Uint32 dt);

    void destruir();

};

#endif /* CHANCLETAZO_HPP */
