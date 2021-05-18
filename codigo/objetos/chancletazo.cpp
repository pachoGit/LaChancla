#include "chancletazo.hpp"

Chancletazo::Chancletazo(double x, double y, TipoCuadro tc) : Objeto(x, y, tc)
{
    velocidad = 0.15;
    choque = false;
    cambiar = false;
    direccion = DI_DERECHA;
    
}

void Chancletazo::actualizar(Uint32 dt)
{
    if (!choque)
    {
        posx += velocidad * dt;
        posy = 3.20 * posx;

        /*
        switch (direccion)
        {
            case DI_DERECHA:
                posx += velocidad * dt;
                break;
            case DI_IZQUIERDA:
                posx -= velocidad * dt;
                break;
        }
        */
        Objeto::actualizar(dt);

    }
}

