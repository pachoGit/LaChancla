#include <iostream>
#include <algorithm>

#include "juego.hpp"
#include "../config.hpp"

Juego::Juego()
{
    corriendo = true;
    timer.iniciar();
    abuela = new Jugador(((Config::vancho - 60) / 2), Config::valto - 60, TC_ABUELA);

    enemigos.push_back(new Enemigo(0.0, 0.0, TC_PERSONAJE1));
    enemigos.push_back(new Enemigo(70.0, 0.0, TC_PERSONAJE2));
}

Juego::~Juego()
{
    delete abuela;
    if (!enemigos.empty())
    {
        for (auto &enemigo : enemigos)
            delete enemigo;
        enemigos.clear();
    }
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
    for (auto &chancla : abuela->retChancletazos())
        for (auto &enemigo : enemigos)
            verColisionChanclaConEnemigo(chancla, enemigo);

    for (auto &chancla : abuela->retChancletazos())
        verColisionConLaVentana(chancla);

    // Actualizar los objetos
    abuela->actualizar(dt);

    for (auto &enemigo : enemigos)
        enemigo->actualizar(dt);

    // Verficamos si hay alguien
    enemigos.erase(std::remove_if(enemigos.begin(), enemigos.end(), [](Enemigo *e)
                                                                    {
                                                                        if (e->borrar)
                                                                        {
                                                                            delete e;
                                                                            return true;
                                                                        }
                                                                        return false;
                                                                    }), enemigos.end());
}

void Juego::dibujar()
{
    abuela->dibujar();
    for (auto &enemigo : enemigos)
        enemigo->dibujar();
}

EstadoJuego *Juego::siguienteEstado()
{
    return nullptr;
}

int Juego::retTiempo()
{
    return timer.tiempoTrancurrido();
}

void Juego::verColisionChanclaConEnemigo(Chancletazo *chancla, Enemigo *enemigo)
{
    if ((chancla->rect_ventana.x >= enemigo->rect_ventana.x &&
         chancla->rect_ventana.x <= enemigo->rect_ventana.x + enemigo->rect_ventana.w) &&
        (chancla->rect_ventana.y >= enemigo->rect_ventana.y &&
         chancla->rect_ventana.y <= enemigo->rect_ventana.y + enemigo->rect_ventana.h))
    {
        chancla->borrar = true;
        enemigo->borrar = true;
    }
}


void Juego::verColisionConLaVentana(Chancletazo *chancla)
{
    if ((chancla->rect_ventana.x > Config::vancho ||
         (chancla->rect_ventana.x + 60) < 0) ||
        (chancla->rect_ventana.y > Config::valto ||
         ((chancla->rect_ventana.y + 60) < 0)))
        chancla->borrar = true;
}
