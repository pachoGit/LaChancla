#ifndef UTIL_HPP
#define UTIL_HPP

#include <SDL2/SDL.h>
#include <string>

/* Clases utiles para el juego */

class Timer
{
  private:
    // Tiempo de inicio del timer en milisegundos
    int inicio;
    
  public:
    // Iniciar el cronometro y guardar en "inicio"
    void iniciar();

    // Coloca el 'inicio' en 0
    void reiniciar();

    // Calcula el tiempo que ha pasado desde que se inicio el timer 
    // @return - Tiempo transcurrido en segundos
    int tiempoTrancurrido();

    // Calcula el tiempo que ha pasado desde que se inicio el timer 
    // @return - Tiempo transcurrido en segundos en formato double
    double tiempoTrancurridoD();

    // Calcula el tiempo que ha pasado desde que se inicio el timer 
    // @return - Tiempo transcurrido en segundos en milisegundos
    int tiempoTrancurridoMili();
};

// Esto sirve para dibujar texto
class ElementoMenu
{
  public:

    std::string contenido;
    SDL_Rect rect;

    ElementoMenu(std::string c);
};

#endif /* UTIL_HPP */
