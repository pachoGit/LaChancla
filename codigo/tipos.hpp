#ifndef TIPOS_HPP
#define TIPOS_HPP

// Enumeracion que identifica los tipos de imagenes que tenemos en sistema de archivos
// esto es para darle a conocer a la funcion dibujarObjeto, de la clase renderizador,
// de que imagen dibujar la textura
enum TipoImagen
{
    IMG_CHANCLAS,
    IMG_PERSONAJES
    /*
    IMG_MENU
    */
};


enum TipoCuadro
{
    TC_CHANCLA1, // Nivel 1
    TC_CHANCLA2, // Nivel 2
    TC_CHANCLA3,  // Nivel 3
    // Lista de personajes
    TC_PERSONAJE1,
    TC_PERSONAJE2,
    TC_PERSONAJE3,
    TC_PERSONAJE4,
    TC_PERSONAJE5,
    // Jugador
    TC_ABUELA
};

enum Direccion
{
    DI_DERECHA,
    DI_IZQUIERDA
};

#endif /* TIPOS_HPP */
