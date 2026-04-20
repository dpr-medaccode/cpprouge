#include "mapa.h"
#include <algorithm>
#include <iostream>

Mapa::Mapa(size_t alto, size_t ancho) : alto(alto), ancho(ancho) {}

Mapa Mapa::new_vacio(size_t alto, size_t ancho) {
    Mapa mapa(alto, ancho);

    for (size_t i = 0; i < alto; ++i) {
        std::vector<TipoCelda> fila(ancho, TipoCelda::Muro);
        mapa.celdas.push_back(fila);
    }

    return mapa;
}

Mapa Mapa::nuevo(size_t alto, size_t ancho, int cantidad_salas) {
    Mapa mapa = Mapa::new_vacio(alto, ancho);
    mapa.salas = Mapa::annadir_salas_aleatorias(mapa, cantidad_salas);
    mapa.grabar_salas();
    return mapa;
}

std::vector<Sala> Mapa::annadir_salas_aleatorias(const Mapa &mapa,
                                                 int cantidad) {
    std::vector<Sala> salas;

    for (int n = 0; n < cantidad; ++n) {
        bool colocada = false;
        int intentos = 0;

        while (!colocada) {
            Sala sala = Sala::new_aleatoria(mapa.ancho, mapa.alto);

            bool solapa =
                std::any_of(salas.begin(), salas.end(),
                            [&](const Sala &s) { return s.se_solapa(sala); });

            if (!solapa) {
                salas.push_back(sala);
                colocada = true;
            }

            ++intentos;
            if (intentos > 10)
                colocada = true;
        }
    }

    return salas;
}

void Mapa::grabar_salas() {
    for (const Sala &sala : salas) {
        for (size_t i = sala.y; i < sala.y + sala.alto; ++i)
            for (size_t j = sala.x; j < sala.x + sala.ancho; ++j)
                celdas[i][j] = TipoCelda::Suelo;
    }
}

void Mapa::grabar_pasillos(int conexiones) {
    // TODO
}

std::ostream &operator<<(std::ostream &os, const Mapa &mapa) {
    os << "Mapa " << mapa.alto << "x" << mapa.ancho << ":\n";

    for (const auto &fila : mapa.celdas) {
        for (const auto &celda : fila) {
            os << (celda == TipoCelda::Suelo ? ' ' : '#');
        }
        os << '\n';
    }

    return os;
}