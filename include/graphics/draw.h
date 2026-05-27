#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>

#include "graphics/texture.h"

void Draw_CircleOnTexture
    (
    Texture * texture,
    Coord2D pos,
    uint32_t color_rgba,
    uint32_t radius
    );

#endif