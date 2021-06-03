#ifndef RENDERIZADOR_HPP
#define RENDERIZADOR_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
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

    // El sonido de explosion de los enemigos
    Mix_Chunk *explosion;

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
    void dibujarTexto(SDL_Point comienzo, std::string texto, SDL_Color color);

    // Obtiene las dimensiones del texto a renderizar
    // @param texto - std::string de texto para obtener sus dimensiones
    // @param ancho - Puntero a un entero donde se guardara el ancho de la textura del texto
    // @param alto -  Puntero a un entero donde se guardara el alto de la textura del texto
    void retDimensionTexto(std::string texto, int *ancho, int *alto);

    // Inicia y carga los sonidos
    void iniciarCargarAudio();

    // Reproducir el audio
    void reproducir();

};


#endif /* RENDERIZADOR_HPP */
