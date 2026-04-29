#include "cpprouge/mapa.h"
#include <algorithm>
#include <iostream>

Mapa::Mapa(int alto, int ancho) : alto(alto), ancho(ancho) {}

Mapa Mapa::new_vacio(int alto, int ancho) {
    Mapa mapa(alto, ancho);

    for (int i = 0; i < alto; ++i) {
        std::vector<TipoCelda> fila(ancho, TipoCelda::Muro);
        mapa.celdas.push_back(fila);
    }

    return mapa;
}

Mapa Mapa::nuevo(int alto, int ancho, int cantidad_salas) {
    Mapa mapa = Mapa::new_vacio(alto, ancho);
    mapa.salas = Mapa::annadir_salas_aleatorias(mapa, cantidad_salas);
    mapa.grabar_salas();
    mapa.grabar_pasillos();
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
        for (int i = sala.y; i < sala.y + sala.alto; ++i)
            for (int j = sala.x; j < sala.x + sala.ancho; ++j)
                celdas[i][j] = TipoCelda::Suelo;
    }
}

void Mapa::grabar_pasillos() {

    //std::vector<Sala*> visitadas;

    // prioriza la mas cercna sin visitar  y si no hay la mas cercana visitada

    for (Sala &a : salas) {

        Sala *mas_cercana = nullptr;
        int mejor_dist = 999999;

        for (Sala &b : salas) {

            if (&a == &b) {
                mejor_dist = 999999; // chapuza del siglo
                continue;
            }

            if (&a == mas_cercana || &b == mas_cercana) continue;
            

            int d = a.distacia(&b);

            if (d < mejor_dist) {
                mejor_dist = d;
                mas_cercana = &b;
            }

        }

        conectar(a.centro(), mas_cercana->centro());

        //visitadas.push_back(&a);
        //visitadas.push_back(mas_cercana);
    }

	conectar(salas.front().centro(), salas.back().centro());

}

void Mapa::conectar(std::pair<int, int> a, std::pair<int, int> b) {

    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;

    for (int x = std::min(x1, x2); x <= std::max(x1, x2); ++x) {
        celdas[y1][x] = TipoCelda::Suelo;
    }

    for (int y = std::min(y1, y2); y <= std::max(y1, y2); ++y) {
        celdas[y][x2] = TipoCelda::Suelo;
    }
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