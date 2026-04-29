#pragma once
#include <cstddef>
#include <utility>

class Sala {
  public:
    int x, y, ancho, alto/*, cortes*/;

    Sala(int x, int y, int ancho, int alto);
	
    static Sala new_aleatoria(int mapa_ancho, int mapa_alto);

    bool se_solapa(const Sala &otra) const;

    std::pair<int, int> centro() const;

    int distacia(Sala *otra) const;

};