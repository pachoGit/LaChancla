#include <iostream>

#include "juego.hpp"
#include "../config.hpp"

Juego::Juego()
{
    corriendo = true;
    timer.iniciar();
    abuela = new Jugador(((Config::vancho - 60) / 2), Config::valto - 60, TC_ABUELA);
    //abuela = new Jugador(80.0, 80.0, TC_ABUELA);
    //chancla = new Chancletazo(0.0, 0.0, TC_CHANCLA1);
}

Juego::~Juego()
{
    delete abuela;
}

bool Juego::estaCorriendo() const
{
    return corriendo;
}

void Juego::controlarEventos(SDL_Event *evento)
{
    // Si se presiona el buton izquierdo del mouse se debe disparar
    if (evento->type == SDL_MOUSEBUTTONDOWN && evento->button.button == SDL_BUTTON_LEFT)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (timer.tiempoTrancurrido() <= 30)
            abuela->disparar((double) x, (double) y, TC_CHANCLA1);
        else if (timer.tiempoTrancurrido() > 30 && timer.tiempoTrancurrido() <= 50)
            abuela->disparar((double) x, (double) y, TC_CHANCLA2);
        else
            abuela->disparar((double) x, (double) y, TC_CHANCLA3);
            
    }
}

void Juego::actualizar(Uint32 dt)
{
    abuela->actualizar(dt);
}

void Juego::dibujar()
{
    abuela->dibujar();
}

EstadoJuego *Juego::siguienteEstado()
{
    return nullptr;
}

int Juego::retTiempo()
{
    return timer.tiempoTrancurrido();
}
