#pragma once
#include <cstddef>
#include <utility>
#include "lugar.h"

class Sala {
  public:
    int ancho, alto/*, cortes*/;
	Lugar lugar;

    Sala(Lugar lugar, int ancho, int alto);
	
    static Sala new_aleatoria(int mapa_ancho, int mapa_alto);

    bool se_solapa(const Sala &otra) const;

    Lugar centro() const;

};