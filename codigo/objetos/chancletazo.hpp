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

    // La pendiente para el movimiento de la chacla
    double pendiente;

    // Posicion x0, y0 para la formula de la recta
    SDL_Point referencia;
    
    // El comportamiento de la chancla va a depender si disparamos hacia lado derecho
    // o al lado izquierdo del jugador
    // true - lado derecho
    // false - lado izquierdo
    bool lado_disparo;

    // Para saber si la chancla choco con algo
    bool choque;

    // Para saber si es hora de cambiar de tipo de chancla
    bool cambiar;

    // Constructor
    // @param x - Posicion x
    // @param y - Posicion y
    // @param tc - Tipo de chancleta a utilizar
    Chancletazo(double x, double y, TipoCuadro tc);

    ~Chancletazo();

    // Modifica las posiciones y dimensiones de la animacion
    void actualizar(Uint32 dt);

    // 
    void destruir();

};

#endif /* CHANCLETAZO_HPP */
