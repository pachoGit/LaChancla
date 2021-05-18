#include <iostream>

#include "renderizador.hpp"
#include "../config.hpp"

Renderizador::Renderizador()
{
    render = nullptr;
    texto_textura = nullptr;
    fuente_general = nullptr;
    fuente_fps = nullptr;
}

Renderizador::~Renderizador()
{
    if (render != nullptr)
        SDL_DestroyRenderer(render);
    if (!texturas.empty())
    {
        for (auto &[tipo, textura] : texturas)
            SDL_DestroyTexture(textura);
    }   
    if (texto_textura != nullptr)
        SDL_DestroyTexture(texto_textura);
    if (fuente_general != nullptr)
        TTF_CloseFont(fuente_general);
    if (fuente_fps != nullptr)
        TTF_CloseFont(fuente_fps);
}

void Renderizador::cargarTexturas(SDL_Window *ventana)
{
    SDL_Surface *chanclas = nullptr;
    SDL_Surface *personajes = nullptr;

    render = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    chanclas = IMG_Load(Config::chanclas_textura.c_str());
    personajes = IMG_Load(Config::personajes_textura.c_str());

    texturas[IMG_CHANCLAS] = SDL_CreateTextureFromSurface(render, chanclas);
    texturas[IMG_PERSONAJES] = SDL_CreateTextureFromSurface(render, personajes);

    if (!render)
        std::cout << "No se inicio el renderizador" << std::endl;

    for (auto &[tipo, textura] : texturas)
    {
        if (!textura)
            std::cout << "No se encontro la textura" << std::endl;
    }

    SDL_FreeSurface(chanclas);
    SDL_FreeSurface(personajes);
}

void Renderizador::limpiar()
{
    SDL_SetRenderDrawColor(render, 0x0F, 0x1C, 0x3B, 0x56);
    SDL_RenderClear(render);
}

void Renderizador::presentar()
{
    SDL_RenderPresent(render);
}

void Renderizador::dibujarObjeto(const SDL_Rect *rect_png, const SDL_Rect *rect_ventana, TipoImagen ti)
{
    SDL_RenderCopy(render, texturas.at(ti), rect_png, rect_ventana);
}
