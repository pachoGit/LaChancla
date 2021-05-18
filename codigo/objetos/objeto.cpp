#include "objeto.hpp"

Objeto::Objeto()
{
    borrar = false;
    posx = 0.0;
    posy = 0.0;
    info_cuadro = nullptr;
    tiempo_cuadro = 0;
    cuadro_actual = 0;
}

Objeto::Objeto(double x, double y, TipoCuadro t)
{
    borrar = false;
    posx = x;
    posy = y;
    tipo = t;
    info_cuadro = Motor::retMotor().retConfigCuadro()->retInfoCuadro(tipo);
    tiempo_cuadro = 0;
    cuadro_actual = 0;

    rect_png.x = info_cuadro->rect_png.x;
    rect_png.y = info_cuadro->rect_png.y;
    rect_png.w = info_cuadro->rect_png.w;
    rect_png.h = info_cuadro->rect_png.h;

    rect_ventana.x = posx;
    rect_ventana.y = posy;
    rect_ventana.w = info_cuadro->rect_png.w;
    rect_ventana.h = info_cuadro->rect_png.h;

    rect_colision.x = posx;
    rect_colision.y = posy;
    rect_colision.w = info_cuadro->rect_png.w;
    rect_colision.h = info_cuadro->rect_png.h;

}

Objeto::~Objeto()
{
}

void Objeto::actualizar(Uint32 dt)
{
    if (borrar)
        return;

    rect_ventana.x = posx;
    rect_ventana.y = posy;
    rect_ventana.w = info_cuadro->rect_png.w;
    rect_ventana.h = info_cuadro->rect_png.h;
    
    rect_colision.x = posx;
    rect_colision.y = posy;
    rect_colision.w = info_cuadro->rect_png.w;
    rect_colision.h = info_cuadro->rect_png.h;
    
    // Realizar la animacion...si tiene :D
    if (info_cuadro->numero_cuadros > 1)
    {
        tiempo_cuadro += dt;
        if (tiempo_cuadro > info_cuadro->duracion_cuadro)
        {
            tiempo_cuadro = 0;
            cuadro_actual++;
            if (cuadro_actual >= info_cuadro->numero_cuadros)
            {
                if (info_cuadro->ciclo)
                    cuadro_actual = 0;
                else
                    cuadro_actual = info_cuadro->numero_cuadros - 1;
            }
            rect_png = moverRect(info_cuadro->rect_png, cuadro_actual, 0);
        }
    }
}

void Objeto::dibujar()
{
    if (!info_cuadro || borrar)
        return;
    Motor::retMotor().retRenderizador()->dibujarObjeto(&rect_png, &rect_ventana, info_cuadro->tipo_imagen);
}

SDL_Rect Objeto::moverRect(const SDL_Rect &rect, int x, int y)
{
    SDL_Rect r;
    r.x = rect.x + x * rect.w;
    r.y = rect.y + y * rect.h;
    r.w = rect.w;
    r.h = rect.h;

    return r;
}




