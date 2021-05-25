#ifndef RENDERIZADOR_HPP
#define RENDERIZADOR_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>

#include "../tipos.hpp"

class Renderizador
{
  private:

    // Renderizador de SDL2
    SDL_Renderer *render;

    // Lista de texturas
    std::map<TipoImagen, SDL_Texture *> texturas;

    // Textura para el texto
    SDL_Texture *texto_textura;

    // Fuente de texto general
    TTF_Font *fuente_general;

    // Fuente para el texto para mostrar los FPS
    TTF_Font *fuente_fps;

  public:

    Renderizador();

    ~Renderizador();

    // Cargar las texturas desde el sistema de archivos
    void cargarTexturas(SDL_Window *ventana);

    // Cargar las fuentes de texto
    void cargarFuentes();

    // Limpia la pantalla antes de prensetar las texturas
    void limpiar();

    // Presenta las texturas
    void presentar();

    // Dibujar un la textura de un objeto
    // @param rect_png     - Posicion y dimensiones del textura en la imagen
    // @param rect_ventana - Posicion y dimensiones del textura en la ventana de renderizado
    // @param ti           - Es la imagen donde se buscara la textura
    void dibujarObjeto(const SDL_Rect *rect_png, const SDL_Rect *rect_ventana, TipoImagen ti);

    // Dibujar texto en la pantalla
    // comienzo - Punto de inicio para el texto
    // texto - Contenido para mostrar
    // color - Color del texto
    // tam - Tamanio del texto
    // void dibujarTexto(SDL_Point *comienzo, std::string texto, SDL_Color color, int tam);
    void dibujarTexto(SDL_Point *comienzo, std::string texto, SDL_Color color);

    TTF_Font *retFuenteGeneral() const;

};


#endif /* RENDERIZADOR_HPP */
