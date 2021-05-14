#include "motor.hpp"

Motor::Motor()
{
    renderizador = nullptr;
    config_cuadro = nullptr;
}

Motor::~Motor()
{
    if (renderizador != nullptr)
        delete renderizador;
    if (config_cuadro != nullptr)
        delete config_cuadro;
}

// Esto es interesante
Motor &Motor::retMotor()
{
    static Motor motor;
    return motor;
}

void Motor::iniciarModulos()
{
    renderizador = new Renderizador;
    config_cuadro = new ConfigCuadro;
}

/* Esto por que?... si ya tenemos el destructor de arriba */
void Motor::destruirModulos()
{
    delete renderizador;
    renderizador = nullptr;
    delete config_cuadro;
    config_cuadro = nullptr;
}

Renderizador *Motor::retRenderizador() const
{
    return renderizador;
}

ConfigCuadro *Motor::retConfigCuadro() const
{
    return config_cuadro;
}
