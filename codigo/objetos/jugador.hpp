#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <vector>

#include "objeto.hpp"
#include "chancletazo.hpp"
#include "../tipos.hpp"

class Jugador : public Objeto
{
  private:

    // Velocidad del jugador
    double velocidad;

    // Contador de enemigos destruidos
    unsigned puntos;

    // Nos dice si el jugador se debe detener
    bool detener;

    // Nos dice si el jugador debe disparar, por lo tanto realizar la animacion de disparar
    bool debe_disparar;
    
    // Lista de disparos que ha realizado el jugador
    std::vector<Chancletazo *> chancletazos;

    // El tiempo que paso desde el ultimo disparo
    Uint32 tiempo_ultimo_disparo;
    
    Direccion direccion;

  public:

    // Constructor del jugador
    Jugador(double x, double y, TipoCuadro tc);
    
    ~Jugador();

    // Retorna la lista de balas
    std::vector<Chancletazo *> retChancletazos() const;

    // Actualiza la animacion del jugador y verifica el estado de las teclas presionadas
    void actualizar(Uint32 dt);

    void dibujar();

    // Chancletazo *disparar();
    void disparar(double x, double y, TipoCuadro tc);

};


#endif /* JUGADOR_HPP */
