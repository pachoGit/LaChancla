#include "../config.hpp"
#include "puntaje.hpp"
#include "../motor/motor.hpp"
#include "../motor/renderizador.hpp"

Puntaje::Puntaje(int t, int p)
{
    corriendo = true;
    tiempo = t;
    puntos = p;
    mfin = new ElementoMenu("FIN DEL JUEGO");
    mresultados = new ElementoMenu("RESULTADOS:");
    mtiempo = new ElementoMenu("Tiempo: " + std::to_string(tiempo));
    mpuntos = new ElementoMenu("Haraganes: " + std::to_string(puntos));

    // Obtener las dimensiones de los textos
    Motor::retMotor().retRenderizador()->retDimensionTexto(mfin->contenido, &mfin->rect.w, &mfin->rect.h);
    Motor::retMotor().retRenderizador()->retDimensionTexto(mresultados->contenido, &mresultados->rect.w, &mresultados->rect.h);
    Motor::retMotor().retRenderizador()->retDimensionTexto(mtiempo->contenido, &mtiempo->rect.w, &mtiempo->rect.h);
    Motor::retMotor().retRenderizador()->retDimensionTexto(mpuntos->contenido, &mpuntos->rect.w, &mpuntos->rect.h);

    // Calcular las posiciones de los textos
    mfin->rect.x = (Config::vancho - mfin->rect.w) / 2;
    mfin->rect.y = 50;
    mresultados->rect.x = (Config::vancho - mresultados->rect.w) / 2;
    mresultados->rect.y = 250;

    mtiempo->rect.x = (Config::vancho - mtiempo->rect.w) / 2; // En el centro
    // 10 pixeles mas abajo que el de arriba
    mtiempo->rect.y = mresultados->rect.y + mresultados->rect.h + 10;

    mpuntos->rect.x = (Config::vancho - mpuntos->rect.w) / 2; // En el centro
    // 10 pixeles mas abajo que el de arriba
    mpuntos->rect.y = mtiempo->rect.y + mtiempo->rect.h + 10;

}

Puntaje::~Puntaje()
{
    if (mfin)
        delete mfin;
    if (mresultados)
        delete mresultados;
    if (mtiempo)
        delete mtiempo;
    if (mpuntos)
        delete mpuntos;
}

bool Puntaje::estaCorriendo() const
{
    return corriendo;
}

void Puntaje::controlarEventos(SDL_Event *evento)
{
}

void Puntaje::actualizar(Uint32 dt)
{
    
}

void Puntaje::dibujar()
{
    Renderizador *render = Motor::retMotor().retRenderizador();
    SDL_Color c = {255, 255, 255, 255};

    render->dibujarTexto({mfin->rect.x, mfin->rect.y}, mfin->contenido, c);
    render->dibujarTexto({mresultados->rect.x, mresultados->rect.y}, mresultados->contenido, c);
    render->dibujarTexto({mtiempo->rect.x, mtiempo->rect.y}, mtiempo->contenido, c);
    render->dibujarTexto({mpuntos->rect.x, mpuntos->rect.y}, mpuntos->contenido, c);
    
}

EstadoJuego *Puntaje::siguienteEstado()
{
    return nullptr;
}
            
