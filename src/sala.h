#pragma once
#include <cstddef>
#include <utility>

class Sala {
  public:
    size_t x, y, ancho, alto, cortes;

    Sala(size_t x, size_t y, size_t ancho, size_t alto, size_t cortes);
    static Sala new_aleatoria(size_t mapa_ancho, size_t mapa_alto);

    bool se_solapa(const Sala &otra) const;
    std::pair<size_t, size_t> centro() const;
};