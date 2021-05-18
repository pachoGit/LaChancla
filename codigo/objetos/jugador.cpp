#include <iostream> 
#include <stdio.h>

#include "jugador.hpp"
#include "../config.hpp"

Jugador::Jugador(double x, double y, TipoCuadro tc) : Objeto(x, y, tc)
{
    velocidad = Config::velocidad_defecto_jugador;
    puntos = 0;
    detener = true;
    debe_disparar = false;
    tiempo_ultimo_disparo = 0;
    direccion = DI_DERECHA;
}

Jugador::~Jugador()
{
    if (!chancletazos.empty())
        for (auto &chancla : chancletazos)
            delete chancla;
}

void Jugador::actualizar(Uint32 dt)
{
    // Actualizamos la posicion
    rect_ventana.x = posx;
    rect_ventana.y = posy;
    rect_ventana.w = info_cuadro->rect_png.w;
    rect_ventana.h = info_cuadro->rect_png.h;
    
    rect_colision.x = posx;
    rect_colision.y = posy;
    rect_colision.w = info_cuadro->rect_png.w;
    rect_colision.h = info_cuadro->rect_png.h;

    // Realizar la animacion de disparar
    if (debe_disparar) // Tambien se puede agregar un tiempo de espera entre disparos
    {
        tiempo_cuadro += dt;
        if (tiempo_cuadro > info_cuadro->duracion_cuadro)
        {
            tiempo_cuadro = 0;
            cuadro_actual++;
            if (cuadro_actual >= info_cuadro->numero_cuadros)
            {
                cuadro_actual = 0;
                debe_disparar = false;
            }
            rect_png = moverRect(info_cuadro->rect_png, cuadro_actual, 0);
        }
    }

    // Escuchamos el evento del teclado por medio de Scancode
    const Uint8 *estado_tecla = SDL_GetKeyboardState(NULL);

    if (estado_tecla)
    {
        if (estado_tecla[SDL_SCANCODE_D] || estado_tecla[SDL_SCANCODE_RIGHT])
        {
            direccion = DI_DERECHA;
            detener = false;
        }
        else if (estado_tecla[SDL_SCANCODE_A] || estado_tecla[SDL_SCANCODE_LEFT])
        {
            direccion = DI_IZQUIERDA;
            detener = false;
        }
        else
            detener = true;
    }

    // Si se presiono una tecla, actualizamos la posicion
    if (!detener)
    {
        switch (direccion)
        {
            case DI_DERECHA:
                posx += velocidad * dt;
                break;
            case DI_IZQUIERDA:
                posx -= velocidad * dt;
                break;
        }
    }

    // Actualizamos las balas (chancletazos que posee)
    if (chancletazos.empty())
        return;
    for (auto &chancla : chancletazos)
        chancla->actualizar(dt);
}

void Jugador::dibujar()
{
    Objeto::dibujar();
    if (chancletazos.empty())
        return;
    for (auto &chancla : chancletazos)
        chancla->dibujar();
}

void Jugador::disparar(double x, double y, TipoCuadro tc)
{
    debe_disparar = true;
    Chancletazo *nuevo;
    if (tc == TC_CHANCLA1)
        nuevo = new Chancletazo(posx + 30, posy, tc);
    if (tc == TC_CHANCLA2)
    {
        nuevo = new Chancletazo(posx + 30, posy, tc);
        nuevo->velocidad = Config::velocidad_chancla2;
    }
    if (tc == TC_CHANCLA3)
    {
        nuevo = new Chancletazo(posx + 30, posy, tc);
        nuevo->velocidad = Config::velocidad_chancla3;
    }

    // Calculamos la funcion del recta que determina el movimiento de la chancla (bala)
    // La formula de la recta es la siguiente:
    // f(x) = ((y1 - y0) / (x1 - x0)) * (x - x0) + y0
    double pendiente =  (y - posy) / (x - posx);
    nuevo->pendiente = pendiente; // Asignamos la pendiente para la chancla
    // Estos valores son x0 y y0 para realizar los calculos del movimiento de la chancla
    nuevo->referencia.x = posx;
    nuevo->referencia.y = posy;
    if (x < posx)
        nuevo->lado_disparo = false;
    chancletazos.push_back(nuevo);
}
