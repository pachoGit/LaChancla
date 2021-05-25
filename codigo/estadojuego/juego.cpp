#include <iostream>
#include <algorithm>
#include <random> // Para default_random_engine y uniform_int_distribution
#include <typeinfo> // Para typeid
#include <string>

#include "../config.hpp"
#include "juego.hpp"
#include "puntaje.hpp"

#define TIEMPO_NIVEL1 120 // El primer nivel sera hasta los primeros 2 minutos
#define TIEMPO_NIVEL2 360 // El primer nivel sera desde el minutos 2 hasta el minuto 6, y el 3 nivel es el resto

#define MAX_FALLOS 5 // Cantidad maxima de enemigos que debemos dejar :D

std::default_random_engine generador;
// Generar numeros aleatorios desde  0 hasta el ancho de la ventana, menos el ancho de las
// texturas enemigas - 60 px
std::uniform_int_distribution<int> distribucionPosEnemigo(0, (Config::vancho - 60));

// Para escoger un tipo de enemigo aleatorio
std::uniform_int_distribution<int> distribucionTipoEnemigo(0, 4);

Juego::Juego()
{
    corriendo = true;
    timer.iniciar();
    abuela = new Jugador(((Config::vancho - 60) / 2), Config::valto - 60, TC_ABUELA);
    timerEnemigo.iniciar();
    fallos = 0;
    enemigosEliminados = 0;
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
        if (timer.tiempoTrancurrido() <= TIEMPO_NIVEL1)
            abuela->disparar((double) x, (double) y, TC_CHANCLA1);
        else if (timer.tiempoTrancurrido() > TIEMPO_NIVEL1 && timer.tiempoTrancurrido() <= TIEMPO_NIVEL2)
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

    for (auto &enemigo : enemigos)
        verColisionConLaVentana(enemigo);

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

    // Generamos un enemigo cada 2 segundos
    generarEnemigo();
}

void Juego::dibujar()
{
    abuela->dibujar();
    for (auto &enemigo : enemigos)
        enemigo->dibujar();
}

EstadoJuego *Juego::siguienteEstado()
{
    return new Puntaje(timer.tiempoTrancurrido(), enemigosEliminados);
}

void Juego::verColisionChanclaConEnemigo(Chancletazo *chancla, Enemigo *enemigo)
{
    SDL_Rect interseccion;

    // Los objetos estan chocandose cuando se forma un rectangulo dentro de ellos
    interseccion.x = std::max(chancla->rect_ventana.x, enemigo->rect_ventana.x);
    interseccion.y = std::max(chancla->rect_ventana.y, enemigo->rect_ventana.y);
    interseccion.w = std::min(chancla->rect_ventana.x + chancla->rect_ventana.w, enemigo->rect_ventana.x + enemigo->rect_ventana.w) - interseccion.x;
    interseccion.h = std::min(chancla->rect_ventana.y + chancla->rect_ventana.h, enemigo->rect_ventana.y + enemigo->rect_ventana.h) - interseccion.y;

    if (interseccion.w >= 0 && interseccion.h >= 0)
    {
        chancla->borrar = true;
        enemigo->borrar = true;
        enemigosEliminados++;
    }
}

/*
void Juego::verColisionConLaVentana(Chancletazo *chancla)
{
    if ((chancla->rect_ventana.x > Config::vancho ||
         (chancla->rect_ventana.x + chancla->rect_ventana.w) < 0) ||
        (chancla->rect_ventana.y > Config::valto ||
         ((chancla->rect_ventana.y + chancla->rect_ventana.h) < 0)))
        chancla->borrar = true;
}
*/

void Juego::verColisionConLaVentana(Objeto *objeto)
{
    if ((objeto->rect_ventana.x > Config::vancho ||
         (objeto->rect_ventana.x + objeto->rect_ventana.w) < 0) ||
        (objeto->rect_ventana.y > Config::valto ||
         ((objeto->rect_ventana.y + objeto->rect_ventana.h) < 0)))
    {
        objeto->borrar = true;
        // Pienso que esta funcion no se debe usar pero por ahora me sirve.
        // No se si sera de buena practica usarlo ya que supongo que debe de haber una
        // manera de evitarlo, ya que no estamos usando un lenguaje en el que no sabemos
        // que tipo de dato estemos usando :D, pero bueno, eso me evita hacer una funcion
        // para las chanclas y otras para los enemigos que al final ambas hagan los mismo
        // la unica diferencia es que en una debemos hacer una cosa mas :D
        if (typeid(*objeto) == typeid(Enemigo))
            fallos++;
        // Aqui el fin del juego
        if (fallos >= MAX_FALLOS)
            corriendo = false;
    }
}

void Juego::generarEnemigo()
{
    if (timerEnemigo.tiempoTrancurridoMili() > 1000)
    {
        TipoCuadro tc;
        int x = distribucionPosEnemigo(generador);
        int te = distribucionTipoEnemigo(generador);
        switch (te)
        {
            case 0:
                tc = TC_PERSONAJE1;
                break;
            case 1:
                tc = TC_PERSONAJE2;
                break;
            case 2:
                tc = TC_PERSONAJE3;
                break;
            case 3:
                tc = TC_PERSONAJE4;
                break;
            case 4:
                tc = TC_PERSONAJE5;
                break;
        }
        Enemigo *nuevo = new Enemigo((double) x , -60.0, tc);
        // Cambiar las habilidades de nuevo
        enemigos.push_back(nuevo);
        timerEnemigo.reiniciar();
    }
}
