#include "util.hpp"

void Timer::iniciar()
{
    inicio = (int) SDL_GetTicks();
}

int Timer::tiempoTrancurrido()
{
    int tiempo = (int) SDL_GetTicks() - inicio;
    return tiempo / 1000; // Convertimos a segundos
}
