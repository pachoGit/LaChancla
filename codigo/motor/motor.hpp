#ifndef MOTOR_HPP
#define MOTOR_HPP

// Aqui hay algo interesante que deseo saber un poco mas como funciona, este codigo
// esta basado en un codigo que encontre de otro desarrollador.
// Pues veras, para dibujar algo en pantall simpre necesito el SDL_Renderer*, pero
// ¿como hago para obtener esto sin tener que enviarlo como paramentro en un una
// funcion?, pues es interesante, pero aqui esta el codigo

#include "renderizador.hpp"
#include "configcuadro.hpp"

class Motor
{
  private:
    Renderizador *renderizador;
    
    ConfigCuadro *config_cuadro;

  public:
    
    Motor();

    ~Motor();

    // Aqui la clave de la explicacion de arriba
    static Motor &retMotor();

    void iniciarModulos();

    void destruirModulos();

    Renderizador *retRenderizador() const;

    ConfigCuadro *retConfigCuadro() const;

};


#endif /* MOTOR_HPP */
