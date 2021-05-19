#include "enemigo.hpp"

#define GRAVEDAD 9.8

Enemigo::Enemigo(double x, double y, TipoCuadro tc) : Objeto(x, y, tc)
{
    velocidad = 0.20;
    timer.iniciar();
}

Enemigo::~Enemigo()
{
}

void Enemigo::actualizar(Uint32 dt)
{
    Objeto::actualizar(dt);
    double tiempo = timer.tiempoTrancurridoD();
    posy = 0 + (velocidad * dt) * tiempo + ((1.0/2.0) * GRAVEDAD * tiempo * tiempo);
}

void Enemigo::dibujar()
{
    Objeto::dibujar();
}
