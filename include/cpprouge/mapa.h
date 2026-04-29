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
    int alto, ancho;

    static Mapa new_vacio(int alto, int ancho);
    static Mapa nuevo(int alto, int ancho, int cantidad_salas);

    static std::vector<Sala> annadir_salas_aleatorias(const Mapa &mapa,
                                                      int cantidad);

    friend std::ostream &operator<<(std::ostream &os, const Mapa &mapa);

  private:

    Mapa(int alto, int ancho);
    void grabar_salas();
    void grabar_pasillos();
    void conectar(std::pair<int,int> a, std::pair<int,int> b);
};