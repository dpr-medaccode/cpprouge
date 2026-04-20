#include "sala.h"
#include <cstdlib>

Sala::Sala(size_t x, size_t y, size_t ancho, size_t alto, size_t cortes)
    : x(x), y(y), ancho(ancho), alto(alto), cortes(cortes) {}

Sala Sala::new_aleatoria(size_t mapa_ancho, size_t mapa_alto) {
    size_t ancho  = 4 + rand() % (12 - 4);
    size_t alto   = 4 + rand() % (12 - 4);
    size_t x      = 1 + rand() % (mapa_ancho - ancho - 2);
    size_t y      = 1 + rand() % (mapa_alto  - alto  - 2);
    size_t cortes = rand() % 3;
    return Sala(x, y, ancho, alto, cortes);
}

bool Sala::se_solapa(const Sala& otra) const {
    return x < otra.x + otra.ancho
        && x + ancho > otra.x
        && y < otra.y + otra.alto
        && y + alto > otra.y;
}

std::pair<size_t, size_t> Sala::centro() const {
    return { x + ancho / 2, y + alto / 2 };
}