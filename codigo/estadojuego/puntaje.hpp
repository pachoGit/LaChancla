#ifndef PUNTAJE_HPP
#define PUNTAJE_HPP

#include "estadojuego.hpp"
#include "../util.hpp"

class Puntaje : public EstadoJuego
{
  private:
    
    bool corriendo;

    // El mensaje central de final del juego
    ElementoMenu *mfin;

    // El mensaje central de final del juego
    ElementoMenu *mresultados;

    // El mensaje del tiempo que estuvo jugando
    ElementoMenu *mtiempo;

    // El mensaje de la cantidad de enemigos que elimino
    ElementoMenu *mpuntos;

    // El mensaje de presionar enter para jugar de nuevo
    ElementoMenu *menter;

    // El tiempo que ha durado la partida
    int tiempo;

    // El total de enemigos que ha vencido
    int puntos;

    bool otra_partida;

  public:

    Puntaje(int t, int p);
    
    ~Puntaje();

    bool estaCorriendo() const;
    
    void controlarEventos(SDL_Event *evento);

    void actualizar(Uint32 dt);

    void dibujar();

    EstadoJuego *siguienteEstado();
    
};

#endif /* PUNTAJE_HPP */
