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

    if (debe_disparar) // Realizar la animacion de disparar
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

    // Si se presiono una tecla, actulizamos la posicion
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

/*
Chancletazo *Jugador::disparar()
{
    debe_disparar = true;
    return nullptr;
}
*/

void Jugador::disparar()
{
    debe_disparar = true;
    //chancletazos.push_back(new Chancletazo(rect_ventana.x, rect_ventana.y, TC_CHANCLA1));
    chancletazos.push_back(new Chancletazo(0.0, 0.0, TC_CHANCLA1));
}
