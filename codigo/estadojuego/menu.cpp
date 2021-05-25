#include "../config.hpp"
#include "menu.hpp"
#include "../motor/motor.hpp"
#include "../motor/renderizador.hpp"
#include "juego.hpp"

Menu::Menu()
{
    corriendo = true;
    timer.iniciar();
    titulo = new ElementoMenu("LA CHANCLA");
    cuerpo = new ElementoMenu("Encargate de quitar la pereza a todos :D");
    comenzar = new ElementoMenu("Presiona cualquier tecla para comenzar");
    
    // Obtener las dimensiones de los textos
    Motor::retMotor().retRenderizador()->retDimensionTexto(titulo->contenido, &titulo->rect.w, &titulo->rect.h);
    Motor::retMotor().retRenderizador()->retDimensionTexto(cuerpo->contenido, &cuerpo->rect.w, &cuerpo->rect.h);
    Motor::retMotor().retRenderizador()->retDimensionTexto(comenzar->contenido, &comenzar->rect.w, &comenzar->rect.h);

    // Calcular las posiciones de los textos

    titulo->rect.x = (Config::vancho - titulo->rect.w) / 2;
    titulo->rect.y = 50;
    cuerpo->rect.x = (Config::vancho - cuerpo->rect.w) / 2;
    cuerpo->rect.y = 250;
    comenzar->rect.x = (Config::vancho - comenzar->rect.w) / 2;
    comenzar->rect.y = 450;

}

Menu::~Menu()
{
    if (titulo)
        delete titulo;
    if (cuerpo)
        delete cuerpo;
    if (comenzar)
        delete comenzar;
}

bool Menu::estaCorriendo() const
{
    return corriendo;
}

void Menu::controlarEventos(SDL_Event *evento)
{
    if (evento->type == SDL_KEYDOWN)
        corriendo = false;
}

void Menu::actualizar(Uint32 dt)
{
}

void Menu::dibujar()
{
    Renderizador *render = Motor::retMotor().retRenderizador();
    SDL_Color c = {255, 255, 255, 255};
    SDL_Point p1 = {titulo->rect.x, titulo->rect.y};
    SDL_Point p2 = {cuerpo->rect.x, cuerpo->rect.y};
    SDL_Point p3 = {comenzar->rect.x, comenzar->rect.y};

    render->dibujarTexto(p1, titulo->contenido, c);
    render->dibujarTexto(p2, cuerpo->contenido, c);
    if (timer.tiempoTrancurridoMili() >= 1000)
    {
        render->dibujarTexto(p3, comenzar->contenido, c);
        // Esperar un momento antes de ocultar el texto
        if (timer.tiempoTrancurridoMili() >= 1500)
            timer.reiniciar();
    }
}

EstadoJuego *Menu::siguienteEstado()
{
    return new Juego;
}

int Menu::retTiempo()
{
    return 10;
}
