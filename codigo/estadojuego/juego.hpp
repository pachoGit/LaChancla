#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "estadojuego.hpp"
#include "../util.hpp"
#include "../objetos/chancletazo.hpp"
#include "../objetos/jugador.hpp"

class Juego : public EstadoJuego 
{
  private:

    bool corriendo;
    
    Timer timer;

    Jugador *abuela;
    
  public:

    Juego();

    ~Juego();

    bool estaCorriendo() const;
    
    void controlarEventos(SDL_Event *evento);

    void actualizar(Uint32 dt);

    void dibujar();

    EstadoJuego *siguienteEstado();

    // Retorna el tiempo que se estuvo dentro del juego
    int retTiempo();

    // Chequear si la bala salio de la ventana de juego
    // @param chancla - Chancletazo que debe verificar
    void verColisionConLaVentana(Chancletazo *chancla);

};


#endif /* JUEGO_HPP */
