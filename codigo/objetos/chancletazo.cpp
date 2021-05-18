#include "chancletazo.hpp"
#include "../config.hpp"

Chancletazo::Chancletazo(double x, double y, TipoCuadro tc) : Objeto(x, y, tc)
{
    velocidad = Config::velocidad_chancla1;
    pendiente = 0.0;
    referencia.x = 0;
    referencia.y = 0;
    choque = false;
    cambiar = false;
    lado_disparo = true;
}

void Chancletazo::actualizar(Uint32 dt)
{
    if (!choque)
    {
        // Cuando la pendiente no es tan cerrada se toma como "x" para calcular "y"
        if (pendiente < 2.5 && pendiente > -2.5)
        {
            if (lado_disparo)
                posx += velocidad * dt;
            else
                posx -= velocidad * dt;
            posy = pendiente * (posx - referencia.x) + referencia.y;
        }
        // Pero cuando la pendiente es cerrada, se toma a "y" para calcular "x"
        else 
        {
            // Aumentamos un poquito la velocidad :D
            posy -= (velocidad + 0.1) * dt;
            posx = ((posy - referencia.y) / pendiente) + referencia.x;
        }
        
        Objeto::actualizar(dt);
    }
}

