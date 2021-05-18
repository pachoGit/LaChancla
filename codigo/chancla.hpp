#ifndef CHANCLA_HPP
#define CHANCLA_HPP

#include <SDL2/SDL.h>
#include "objetos/objeto.hpp"
#include "estadojuego/estadojuego.hpp"

class Chancla
{
  private:
    
    // El programa esta corriendo?
    bool corriendo;

    // La ventana donde se presenta el juego
    SDL_Window *ventana;

    // El estado de juego
    EstadoJuego *estado_juego;

  public:

    Chancla();

    ~Chancla();

    // Esta es la funcion que contiene el loop principal
    void correr();

    // Funcion mas externa del controlador de eventos, de aca se dezplaza hacia los
    // demas puntos del programa
    void controlarEventos();
};


#endif /* CHANCLA_HPP */
