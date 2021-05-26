#include <iostream>

#include "chancla.hpp"
#include "config.hpp"
#include "motor/motor.hpp"
#include "objetos/objeto.hpp"

#include "estadojuego/juego.hpp"
#include "estadojuego/menu.hpp"

#define VERSION "1.0.0"

Chancla::Chancla()
{
    ventana = nullptr;
    estado_juego = nullptr;
}

Chancla::~Chancla()
{
    if (ventana != nullptr)
        SDL_DestroyWindow(ventana);
    if (estado_juego)
        delete estado_juego;
}

void Chancla::correr()
{
    corriendo = true;
    
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER) != 0)
        return;
    ventana = SDL_CreateWindow("Chancla", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                               Config::vancho, Config::valto, SDL_WINDOW_SHOWN);

    if (!ventana)
        return;
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        return;
    if(TTF_Init() == -1)
        return;

    Motor &motor = Motor::retMotor();
    motor.iniciarModulos();
    motor.retRenderizador()->cargarTexturas(ventana);
    motor.retRenderizador()->cargarFuentes();

    estado_juego = new Menu;

    Uint32 tultimo = SDL_GetTicks();
    Uint32 tactual;
    Uint32 dt;
    while (corriendo)
    {
        tactual = SDL_GetTicks();
        dt = tactual - tultimo;

        // Esto seria mejor dentro de cada estado, pero como es el mismo fondo, da igual
        motor.retRenderizador()->limpiar(); 
        
        if (!estado_juego->estaCorriendo())
        {
            EstadoJuego *nuevo_estado = estado_juego->siguienteEstado();
            delete estado_juego;
            estado_juego = nuevo_estado;
        }
        if (estado_juego == nullptr)
            break;

        controlarEventos();
        estado_juego->actualizar(dt);
        estado_juego->dibujar();

        tultimo = tactual;

        // Esto seria mejor dentro de cada estado
        motor.retRenderizador()->presentar();
    }

    motor.destruirModulos();
    SDL_DestroyWindow(ventana);
    ventana = nullptr;
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}


void Chancla::controlarEventos()
{
    SDL_Event evento;
    while (SDL_PollEvent(&evento))
    {
        if (evento.type == SDL_QUIT)
            corriendo = false;
        estado_juego->controlarEventos(&evento);
    }
    
}
