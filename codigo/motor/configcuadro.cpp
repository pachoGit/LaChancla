#include "configcuadro.hpp"

ConfigCuadro::ConfigCuadro()
{
    insertar(TC_CHANCLA1, 0, 0, 40, 40, 8, 100, true, IMG_CHANCLAS);
    insertar(TC_CHANCLA2, 0, 40, 40, 40, 8, 100, true, IMG_CHANCLAS);
    insertar(TC_CHANCLA3, 0, 80, 40, 40, 8, 100, true, IMG_CHANCLAS);
}

const InfoCuadro *ConfigCuadro::retInfoCuadro(TipoCuadro tc) const
{
    return &cuadros.at(tc);
}

void ConfigCuadro::insertar(TipoCuadro tc, int x, int y, int ancho, int alto, int nc, int dc, bool c, TipoImagen ti)
{
    cuadros[tc] = InfoCuadro(x, y, ancho, alto, nc, dc, c, ti);
}
