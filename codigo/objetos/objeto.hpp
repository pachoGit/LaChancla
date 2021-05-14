#ifndef OBJETO_HPP
#define OBJETO_HPP

#include "../motor/motor.hpp"

class Objeto
{
  public:

    // Bandera que dice si el objeto debe ser eliminado
    bool borrar;

    // Posicion x del objeto
    double posx;

    // Posicion y del objeto
    double posy;

    // Tipo de sprite del objeto
    TipoCuadro tipo;

    // Informacion del sprite del objeto
    const InfoCuadro *info_cuadro;

    // Tiempo que se debe mostrar el cuadro actual
    Uint32 tiempo_cuadro;

    // Cuadro actual del objeto
    int cuadro_actual;

    // Posicion y dimensiones del objeto en la textura
    SDL_Rect rect_png;

    // Posicion y dimensiones del objeto que tendra en la ventana de renderizado
    SDL_Rect rect_ventana;

    // Rectangulo de colision para el objeto
    SDL_Rect rect_colision;

    // Contructor por defecto (0, 0)
    Objeto();

    /*
     * Constructor
     * @param x    - Posicion x del objeto
     * @param y    - Posicion y del objeto
     * @param t    - Tipo de sprite
     */
    Objeto(double x, double y, TipoCuadro t);

    virtual ~Objeto();

    // Actualizar el rectangulo de destino (rect_ventana)
    virtual void actualizar(Uint32 dt);

    // Esta funcion dibuja el objeto (SDL_RenderCopy)
    virtual void dibujar();

    SDL_Rect moverRect(const SDL_Rect &rect, int x, int y);
    
};

#endif /* OBJETO_HPP */
