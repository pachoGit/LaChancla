#include "util.hpp"

void Timer::iniciar()
{
    inicio = (int) SDL_GetTicks();
}

void Timer::reiniciar()
{
    inicio = 0;
    inicio = (int) SDL_GetTicks();
}

int Timer::tiempoTrancurrido()
{
    int tiempo = (int) SDL_GetTicks() - inicio;
    return tiempo / 1000; // Convertimos a segundos
}

double Timer::tiempoTrancurridoD()
{
    double tiempo = (double) SDL_GetTicks() - inicio;
    return tiempo / 1000.0; // Convertimos a segundos
}

int Timer::tiempoTrancurridoMili()
{
    return ((int) SDL_GetTicks() - inicio);
}

ElementoMenu::ElementoMenu(std::string c) : contenido(c)
{
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
}

ElementoMenu::~ElementoMenu()
{
}
