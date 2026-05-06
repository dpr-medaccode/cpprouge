#include "cpprouge/sala.h"
#include "cpprouge/lugar.h"
#include <cstdlib>

Sala::Sala(Lugar lugar, int ancho, int alto)
    : lugar(lugar), ancho(ancho), alto(alto) {}

Sala Sala::new_aleatoria(int mapa_ancho, int mapa_alto) {
    int ancho = 4 + rand() % (12 - 4);
    int alto = 4 + rand() % (12 - 4);
    int x = 1 + rand() % (mapa_ancho - ancho - 2);
    int y = 1 + rand() % (mapa_alto - alto - 2);
    return Sala(Lugar(x, y), ancho, alto);
}

bool Sala::se_solapa(const Sala &otra) const {
    return lugar.x < otra.lugar.x + otra.ancho && lugar.x + ancho > otra.lugar.x &&
           lugar.y < otra.lugar.y + otra.alto && lugar.y + alto > otra.lugar.y;
}

Lugar Sala::centro() const {
    return {lugar.x + ancho / 2, lugar.y + alto / 2};
}


