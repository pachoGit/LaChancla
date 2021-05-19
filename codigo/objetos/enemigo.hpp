#ifndef ENEMIGO_HPP
#define ENEMIGO_HPP

#include "objeto.hpp"
#include "../util.hpp"

class Enemigo : public Objeto
{
  private:

    double velocidad;

    Timer timer;
    
  public:
    
    // Constructor del jugador
    // @param x - Posicion x
    // @param y - Posicion y
    // @param tc - Cuadro de animacion del enemigo
    Enemigo(double x, double y, TipoCuadro tc);

    ~Enemigo();

    // Modifica las posiciones y dimensiones de la animacion
    void actualizar(Uint32 dt);

    void dibujar();
    

};

#endif /* ENEMIGO_HPP */
