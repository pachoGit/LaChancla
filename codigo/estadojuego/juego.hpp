#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "estadojuego.hpp"
#include "../util.hpp"
#include "../objetos/chancletazo.hpp"
#include "../objetos/jugador.hpp"
#include "../objetos/enemigo.hpp"

#include <vector>

class Juego : public EstadoJuego 
{
  private:

    bool corriendo;
    
    Timer timer;

    // Jugador principal
    Jugador *abuela;
    
    // Lista de enemigos presentes en la ventana
    std::vector<Enemigo *> enemigos;
    
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

    // Chequear si la bala choco contra un enemigo
    // @param chancla - Chancletazo
    // @param enemigo - Enemigo
    void verColisionChanclaConEnemigo(Chancletazo *chancla, Enemigo *enemigo);

    // Chequear si la bala salio de la ventana de juego
    // @param chancla - Chancletazo que debe verificar
    void verColisionConLaVentana(Chancletazo *chancla);

};


#endif /* JUEGO_HPP */
