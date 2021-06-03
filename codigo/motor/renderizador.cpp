#include <iostream>

#include "renderizador.hpp"
#include "../config.hpp"

Renderizador::Renderizador()
{
    render = nullptr;
    texto_textura = nullptr;
    fuente_general = nullptr;
    fuente_fps = nullptr;
    explosion = nullptr;
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
    if (explosion != nullptr)
        Mix_FreeChunk(explosion);
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

void Renderizador::cargarFuentes()
{
    fuente_general = TTF_OpenFont(Config::path_fuente_general.c_str(), 28);
}


void Renderizador::limpiar()
{
    // SDL_SetRenderDrawColor(render, 0x0F, 0x1C, 0x3B, 0x56);
    SDL_SetRenderDrawColor(render, 0x2D, 0x77, 0xB8, 0x56);
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

void Renderizador::dibujarTexto(SDL_Point comienzo, std::string texto, SDL_Color color)
{
    if (!fuente_general)
        return;
    SDL_Surface *stexto = nullptr;
    SDL_Texture *ttexto = nullptr;

    stexto = TTF_RenderUTF8_Solid(fuente_general, texto.c_str(), color);
    ttexto = SDL_CreateTextureFromSurface(render, stexto);
    SDL_FreeSurface(stexto);
    if (!ttexto)
        return;
    SDL_Rect rect_final;
    rect_final.x = comienzo.x;
    rect_final.y = comienzo.y;
    SDL_QueryTexture(ttexto, nullptr, nullptr, &rect_final.w, &rect_final.h);

    SDL_RenderCopy(render, ttexto, nullptr, &rect_final);

    SDL_DestroyTexture(ttexto);
}

void Renderizador::retDimensionTexto(std::string texto, int *ancho, int *alto)
{
    TTF_SizeText(fuente_general, texto.c_str(), ancho, alto);
}

void Renderizador::iniciarCargarAudio()
{
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
        std::cout << "Error al abrir el audio..." << std::endl;
        std::cout << Mix_GetError() << std::endl;
        return;
    }

    explosion = Mix_LoadWAV(Config::audio_explosion.c_str());
    if (!explosion)
        std::cout << "No se ha cargado el audio para la explosion" << std::endl;
}

void Renderizador::reproducir()
{
    Mix_PlayChannel(1, explosion, 0);
}
