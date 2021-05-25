#include "enemigo.hpp"

Enemigo::Enemigo(double x, double y, TipoCuadro tc) : Objeto(x, y, tc)
{
    velocidad = 0.20;
    timer.iniciar();
    posy_inicial = y;
    gravedad = 9.8;
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
    // debe ser positivo por lo que al final quedaria:
    // Usando la formula: f(x) = y0 + v0*t1 + 1/2*GRAVEDAD(t1²)
    posy = posy_inicial + velocidad * tiempo + (0.5 * gravedad * tiempo * tiempo);
}

void Enemigo::dibujar()
{
    Objeto::dibujar();
}
