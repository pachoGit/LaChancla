#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

using namespace std;

class Config
{
  public:
    
    // Ruta hacia la imagen de las chanclas
    static string chanclas_textura;

    // Ruta hacia la imagen de los personajes
    static string personajes_textura;

    // Ancho de la ventana
    static int vancho;

    // Alto de la ventana
    static int valto;

    // Velocidad por defecto del jugador (abuela)
    static double velocidad_defecto_jugador;

    /** Velocidades para las distintos niveles de chanclas **/
    static double velocidad_chancla1;

    static double velocidad_chancla2;

    static double velocidad_chancla3;
};


#endif /* CONFIG_HPP */
