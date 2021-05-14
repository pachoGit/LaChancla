#ifndef CUADRO_HPP
#define CUADRO_HPP

#include <SDL2/SDL.h>
#include <map>

#include "../tipos.hpp"

/* Esta estructura guarda la informacion del comienzo de la serie de cuadros
 * de animacion
 */
struct InfoCuadro
{
    InfoCuadro()
    {
        rect_png.x = 0;
        rect_png.y = 0;
        rect_png.w = 0;
        rect_png.h = 0;
        numero_cuadros = 0;
        duracion_cuadro = 0;
        ciclo = false;
        tipo_imagen = IMG_CHANCLAS;
    }

    InfoCuadro(int x, int y, int ancho, int alto, int nc, int dc, bool c, TipoImagen ti)
    {
        rect_png.x = x;
        rect_png.y = y;
        rect_png.w = ancho;
        rect_png.h = alto;
        numero_cuadros = nc;
        duracion_cuadro = dc;
        ciclo = c;
        tipo_imagen = ti;
    }
    
    // Posicion y dimensiones del primer cuadro de animacion en la imagen de texturas
    SDL_Rect rect_png;

    // Cantidad de cuadros que tiene esta animacion
    int numero_cuadros;

    // Duracion de cada cuadro en la pantalla
    unsigned duracion_cuadro;

    // Variable que determina si la animacion esta en bucle
    bool ciclo;
    
    // Determina en que imagen se encuentra este cuador
    TipoImagen tipo_imagen;
};

/* Esta clase almacena la informacion de todas las animaciones del juego */
class ConfigCuadro
{
  private:
    
    // Lista de los "primeros" cuadros que forman las animaciones
    std::map<TipoCuadro, InfoCuadro> cuadros;

  public:
    
    /* Constructor por defecto */
    ConfigCuadro();

    /* Obtiene la informacion de un determinado cuadro de animacion
     * @param tc - Tipo de cuadro del cual se desea obtener su informacion
     * @return La informacion del cuadro de animacion
     */
    const InfoCuadro *retInfoCuadro(TipoCuadro tc) const;

  private:
    
    /* Ingresar la informacion de un determinado cuadro de animacion
     * @param tc     - Es el tipo de cuadro
     * @param x      - Posicion x del cuadro en la imagen de textura
     * @param y      - Posicion y del cuadro en la imagen de textura
     * @param ancho  - Ancho del cuadro en la imagen de textura
     * @param alto   - Alto del cuadro en la imagen de textura
     * @param nc     - Numero de cuadros que le siguen para formar la animacion
     * @param dc     - Duracion de cada cuadro para formar la animacion
     * @param c      - Determina si el cuadro esta en un bucle
     * @param ti     - Determina la en que imagen se encuentra este cuadro de animacion
     */
    void insertar(TipoCuadro tc, int x, int y, int ancho, int alto, int nc, int dc, bool c, TipoImagen ti);

};


#endif /* CUADRO_HPP */
