#include "cpprouge/sala.h"
#include <cstdlib>

Sala::Sala(int x, int y, int ancho, int alto)
    : x(x), y(y), ancho(ancho), alto(alto) {}

Sala Sala::new_aleatoria(int mapa_ancho, int mapa_alto) {
    int ancho = 4 + rand() % (12 - 4);
    int alto = 4 + rand() % (12 - 4);
    int x = 1 + rand() % (mapa_ancho - ancho - 2);
    int y = 1 + rand() % (mapa_alto - alto - 2);
    return Sala(x, y, ancho, alto);
}

bool Sala::se_solapa(const Sala &otra) const {
    return x < otra.x + otra.ancho && x + ancho > otra.x &&
           y < otra.y + otra.alto && y + alto > otra.y;
}

std::pair<int, int> Sala::centro() const {
    return {x + ancho / 2, y + alto / 2};
}

int Sala::distacia(Sala *otra) const {

    auto [x1, y1] = this->centro();
    auto [x2, y2] = otra->centro();

    int dx = x1 - x2;
    int dy = y1 - y2;

    return dx * dx + dy * dy;

}

