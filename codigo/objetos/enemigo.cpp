#include "enemigo.hpp"

#define GRAVEDAD 9.8

Enemigo::Enemigo(double x, double y, TipoCuadro tc) : Objeto(x, y, tc)
{
    velocidad = 0.20;
    timer.iniciar();
    posy_inicial = y;
}

Enemigo::~Enemigo()
{
}

void Enemigo::actualizar(Uint32 dt)
{
    Objeto::actualizar(dt);
    double tiempo = timer.tiempoTrancurridoD();
    // Usando la formula: f(x) = y0 + v0*(t1 - t0) - 1/2*GRAVEDAD*(t1² - t0²)
    // El tiempo de inicio (t0) es 0. Ademas como el eje 'y' suma hacia abajo, la gravedad
    // debe ser positivo
    // Usando la formula: f(x) = y0 + v0*t1 + 1/2*GRAVEDAD(t1²)
    posy = posy_inicial + (velocidad * dt) * tiempo + ((1.0/2.0) * GRAVEDAD * tiempo * tiempo);
}

void Enemigo::dibujar()
{
    Objeto::dibujar();
}
