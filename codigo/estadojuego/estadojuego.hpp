#ifndef ESTADOJUEGO_HPP
#define ESTADOJUEGO_HPP

#include <SDL2/SDL_events.h>
#include <string>

// Para este juego hay 3 estados:
// 1. El menu - En realidad solo una pantalla de bienvenida
// 2. El juego
// 3. Los bonus

class EstadoJuego
{
  public:

    virtual ~EstadoJuego()
    {
    }

    // Funcion que contiene el estado actual de "este estado" de la aplicacion
    virtual bool estaCorriendo() const = 0;

    // Funcion para controlar los eventos del usuario
    // @param evento - Puntero de tipo SDL_Event
    virtual void controlarEventos(SDL_Event *evento) = 0;

    // Funcion para actualizar la condicion de los objetos y variables
    // @param dt - Tiempo desde la ultima llamada a las funciones en milisegundos
    virtual void actualizar(Uint32 dt) = 0;

    // Dibuja el estado actual del juego
    virtual void dibujar() = 0;
    
    // Si estamos en el menu y le damos al boton "Jugar" esta funcion retorna
    // un objeto de la clase "Juego" y viceversa
    virtual EstadoJuego *siguienteEstado() = 0;

    virtual int retTiempo() = 0;
};

#endif /* ESTADOJUEGO_HPP */
