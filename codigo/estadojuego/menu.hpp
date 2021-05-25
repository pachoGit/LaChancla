#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <SDL2/SDL.h>

#include "estadojuego.hpp"
#include "../util.hpp"

struct ElementoMenu
{
    std::string contenido;
    SDL_Rect rect;

    ElementoMenu(std::string c) : contenido(c)
    {
        rect.x = 0;
        rect.y = 0;
        rect.w = 0;
        rect.h = 0;
    }
    
};

class Menu : public EstadoJuego
{
  private:
    
    // Determina si este estado de juego sigue ejecutandose
    bool corriendo;
    
    // Para lograr un efecto de parpadeo
    Timer timer;

    // El titulo del juego
    ElementoMenu *titulo;

    // Cuerpo del mensaje
    ElementoMenu *cuerpo;
    
    // El mensaje que dice: Presione una tecla para comenzar :D
    ElementoMenu *comenzar;

  public:
    
    Menu();
    
    ~Menu();

    bool estaCorriendo() const;
    
    void controlarEventos(SDL_Event *evento);

    void actualizar(Uint32 dt);

    void dibujar();

    EstadoJuego *siguienteEstado();
    
    int retTiempo();
};

#endif /* MENU_HPP */
