#pragma once
#include "sala.h"
#include <ostream>
#include <vector>

enum class TipoCelda {
    Suelo,
    Muro,
};

class Mapa {

  public:
  
    std::vector<std::vector<TipoCelda>> celdas;
    std::vector<Sala> salas;
    size_t alto, ancho;

    static Mapa new_vacio(size_t alto, size_t ancho);
    static Mapa nuevo(size_t alto, size_t ancho, int cantidad_salas);

    static std::vector<Sala> annadir_salas_aleatorias(const Mapa &mapa,
                                                      int cantidad);

    friend std::ostream &operator<<(std::ostream &os, const Mapa &mapa);

  private:
    Mapa(size_t alto, size_t ancho);
    void grabar_salas();
    void grabar_pasillos(int conexiones);
};