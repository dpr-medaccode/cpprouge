#include "cpprouge/lugar.h"

Lugar::Lugar(int x, int y) : x(x), y(y) {}

int Lugar::distacia(Lugar *otro) {

    int dx = x - otro->x;
    int dy = y - otro->y;

    return dx * dx + dy * dy;
	
}
