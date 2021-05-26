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
    
    // Timer general del juego, mide cuanto tiempo estamos jugando
    Timer timer;

    // Timer que mide que tiempo paso desde el ultimo disparo
    Timer timer_ult_disparo;

    // Este el timer para la generacion de enemigos
    Timer timerEnemigo;

    // Jugador principal
    Jugador *abuela;
    
    // Lista de enemigos presentes en la ventana
    std::vector<Enemigo *> enemigos;

    // Cantidad de fallos hasta el momento
    int fallos;

    // Cantidad de enemigos eliminados
    int enemigosEliminados;

  public:

    Juego();

    ~Juego();

    bool estaCorriendo() const;
    
    void controlarEventos(SDL_Event *evento);

    void actualizar(Uint32 dt);

    void dibujar();

    EstadoJuego *siguienteEstado();

    // Chequear si la bala choco contra un enemigo
    // @param chancla - Chancletazo
    // @param enemigo - Enemigo
    void verColisionChanclaConEnemigo(Chancletazo *chancla, Enemigo *enemigo);

    // Chequear si la bala salio de la ventana de juego
    // @param chancla - Chancletazo que debe verificar
    //void verColisionConLaVentana(Chancletazo *chancla);
    void verColisionConLaVentana(Objeto *objeto);

    // Generar un nuevo enemigo
    void generarEnemigo();
};


#endif /* JUEGO_HPP */
