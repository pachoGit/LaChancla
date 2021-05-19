#ifndef UTIL_HPP
#define UTIL_HPP

#include <SDL2/SDL.h>

/* Clases utiles para el juego */

class Timer
{
  private:
    // Tiempo de inicio del timer en milisegundos
    int inicio;
    
  public:
    // Iniciar el cronometro y guardar en "inicio"
    void iniciar();

    // Calcula el tiempo que ha pasado desde que se inicio el timer 
    // @return - Tiempo transcurrido en segundos
    int tiempoTrancurrido();

    // Calcula el tiempo que ha pasado desde que se inicio el timer 
    // @return - Tiempo transcurrido en segundos en formato double
    double tiempoTrancurridoD();

};

#endif /* UTIL_HPP */
